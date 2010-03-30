/*
 * TestRunner.cpp
 */

#include "cuconfig.h"
#include "cudebug.h"
#include "TestRunner.h"
#include "Test.h"
#include "TestListener.h"
#include "TestResult.h"
#include "TestFailure.h"
#include "TestUtility.h"
#include <stdio.h>
#include <string.h>

#ifndef cu_NO_TIME_H
#  include <time.h>
#endif

#ifdef cu_NO_FILE_OPERATIONS
#  include "custdio.h"
#endif

cu_NAMESPACE_BEGIN(cppunit)

// ---- class Utility ----

/**
 * TestRunner のユーティリティクラス。
 */
class TestRunner::Utility
{
  public:
	friend class Logger;	// for MSVC++
	static void printFailureDetail(FILE* fp, const TestFailure& failure);
	static void printErrorDetail(FILE* fp, const TestFailure& error)
		{ printFailureDetail(fp, error); }
	static void printResult(FILE* fp, const TestResult& result);
};

void TestRunner::Utility::printFailureDetail(
		FILE* fp, const TestFailure& failure)
{
	fprintf(fp, " (%s:%ld)\n",
			TestUtility::trimFileName(failure.file()), failure.line());
	const char* what = failure.what();
	if (what != 0 && *what != 0) {
		fprintf(fp, "%s\n", what);
	}
}

void TestRunner::Utility::printResult(FILE* fp, const TestResult& result)
{
	if (result.wasSuccessful()) {
		fprintf(fp, "\nOK (%d tests)\n", result.runCount());
		return;
	}
	fprintf(fp, "\n!!!FAILURES!!!\nTest Results:\n"
			"Run: %d, Failures: %d, Errors: %d\n",
			result.runCount(), result.failureCount(), result.errorCount());
}

// ---- class SimpleListener ----

/**
 * 簡易表示を行うリスナ。
 */
class TestRunner::SimpleListener : public TestListener
{
  public:
	SimpleListener() {}
	virtual ~SimpleListener() {}
	virtual void startTest(Test* test) { fputc('.', stderr); }
	virtual void endTest(Test* test) {}
	virtual void addFailure(const TestFailure* failure)
		{ fputs("F\n", stderr); }
	virtual void addError(const TestFailure* error)
		{ fputs("E\n", stderr); }
};

// ---- class Logger ----

/**
 * ログ出力用リスナ。
 */
class TestRunner::Logger : public TestListener
{
  public:
	explicit Logger(FILE* fp) : m_filePtr(fp), m_hasError(false) {}
	virtual ~Logger() { close(); }
	virtual void startTest(Test* test) { m_hasError = false; }
	virtual void endTest(Test* test);
	virtual void addFailure(const TestFailure* failure);
	virtual void addError(const TestFailure* error);
	void printHeader() const;
	void printResult(const TestResult& result) const
		{ Utility::printResult(m_filePtr, result); }

	static Logger* openFile(const char* fileName, const char* mode = "a");

  protected:
	void printTestResult(Test* test, bool ok) const;
	void close();

  private:
	FILE* m_filePtr;
	bool  m_hasError;
};

void TestRunner::Logger::endTest(Test* test)
{
	if (!m_hasError) printTestResult(test, true);
}

void TestRunner::Logger::addFailure(const TestFailure* failure)
{
	if (!m_hasError) {
		m_hasError = true;
		printTestResult(failure->failedTest(), false);
	}
	fputs("Failure!!", m_filePtr);
	Utility::printFailureDetail(m_filePtr, *failure);
}

void TestRunner::Logger::addError(const TestFailure* error)
{
	if (!m_hasError) {
		m_hasError = true;
		printTestResult(error->failedTest(), false);
	}
	fputs("Error!!", m_filePtr);
	Utility::printErrorDetail(m_filePtr, *error);
}

void TestRunner::Logger::printTestResult(Test* test, bool ok) const
{
	fprintf(m_filePtr, "[%s] %s\n", (ok ? "OK" : "NG"), test->getName());
}

void TestRunner::Logger::printHeader() const
{
	fprintf(m_filePtr, "--------------------\n");
#ifndef cu_NO_TIME_H
	time_t current = time(0);
	struct tm* data = localtime(&current);
	char buf[80];
	strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", data);
	fprintf(m_filePtr, "%s\n\n", buf);
#endif
}

TestRunner::Logger*
TestRunner::Logger::openFile(const char* fileName, const char* mode)
{
#ifndef cu_NO_FILE_OPERATIONS
	FILE* fp = fopen(fileName, mode);
	return (fp ? new Logger(fp) : 0);
#else
	return 0;
#endif
}

void TestRunner::Logger::close()
{
#ifndef cu_NO_FILE_OPERATIONS
	if (m_filePtr != 0 && m_filePtr != stdout && m_filePtr != stderr) {
		fclose(m_filePtr);
	}
#endif
}

// ---- class TestRunner ----

TestRunner::TestRunner()
	: m_help(false), m_wait(false), m_verbose(false), m_logfile(0)
{
}

void TestRunner::addTest(Test* test)
{
	m_registry.addTest(test->getName(), test);
}

void TestRunner::addTest(const char* name, Test* test)
{
	m_registry.addTest(name, test);
}

int TestRunner::run(int argc, char* argv[])
{
	int result = parseArgs(argc, argv);
	if (result != 0 || m_help) {
		printUsage(argv[0]);
		return result;
	}
	result = runTests();
	if (result < 0) {
		printUsage(argv[0]);
		return result;
	}
	if (m_wait) wait();
	return result;
}

int TestRunner::parseArgs(int argc, char* argv[])
{
	m_help = false;
	m_wait = false;
	m_verbose = false;
	m_logfile = 0;
	m_registry.setAllAvailable(false);

	for (int i = 1; i < argc; i++) {
		const char* arg = argv[i];
		if (strlen(arg) == 0) continue;
		if (*arg == '-') {
			if (strcmp(arg, "-help") == 0) {
				m_help = true; return 0;
			}
			if (strcmp(arg, "-wait") == 0) {
				m_wait = true; continue;
			}
			if (strcmp(arg, "-verbose") == 0) {
				m_verbose = true; continue;
			}
#ifndef cu_NO_FILE_OPERATIONS
			if (strcmp(arg, "-log") == 0) {
				if (++i >= argc) return -1;
				m_logfile = argv[i]; continue;
			}
#endif
			fprintf(stderr, "ERROR!! illegal option: %s\n", arg);
			return -1;
		}
		bool found = m_registry.setAvailable(arg);
		if (!found) {
			fprintf(stderr, "ERROR!! test %s not found.\n", arg);
			return -1;
		}
	}
	if (!m_registry.hasAvailables()) {
		m_registry.setAllAvailable();
	}
	return 0;
}

int TestRunner::runTests()
{
	// 指定した全てのテストを 1 つの TestResult で扱うように変更した。

#ifdef cu_HAS_INNER_CLASS_BUG
	typedef TestRunner::SimpleListener SimpleListener;
	typedef TestRunner::Logger Logger;
#endif
	cu_AUTO_PTR(TestListener) listener(m_verbose
			? (TestListener*)new Logger(stdout)
			: (TestListener*)new SimpleListener());
	cu_AUTO_PTR(Logger) logger;
	if (m_logfile != 0) {
		logger.reset(Logger::openFile(m_logfile));
		if (logger.get() == 0) {
			fprintf(stderr, "ERROR!! cannot open file: %s\n", m_logfile);
			return -1;
		}
	}

	TestResult result;
	result.addListener(listener.get());
	if (logger.get() != 0) {
		result.addListener(logger.get());
		logger->printHeader();
	}

	m_registry.runTests(&result);
	if (!m_verbose) {
		fputc('\n', stderr);
		fflush(stderr);
	}
	printResult(result);
	if (logger.get() != 0) {
		logger->printResult(result);
	}

	if (result.errorCount()   > 0) return 2;
	if (result.failureCount() > 0) return 1;
	return 0;
}

void TestRunner::wait()
{
	fprintf(stderr, "\n<Enter> to continue");
	getchar();
}

void TestRunner::printUsage(const char* command) const
{
	fprintf(stderr, "Usage: %s [-help] [-wait] [-verbose]"
#ifndef cu_NO_FILE_OPERATIONS
			" [-log file]"
#endif
			" [tests...]\n", TestUtility::trimFileName(command));
}

void TestRunner::printResult(const TestResult& result) const
{
	printHeader(result);
	if (m_verbose) return;
	printFailures(result.failures());
	printErrors(result.errors());
}

void TestRunner::printHeader(const TestResult& result) const
{
	Utility::printResult(stdout, result);
}

void TestRunner::printFailures(const cu_List& failures) const
{
	int count = failures.size();
	if (count == 0) return;
	if (count == 1) {
		printf("There was 1 failure:\n");
	} else {
		printf("There were %d failures:\n", count);
	}
	int index = 0;
	for (cu_List::const_iterator p = failures.begin();
			p != failures.end(); ++p) {
		TestFailure* failure = (TestFailure*)*p;
		printf("%d) %s", ++index, failure->failedTest()->getName());
		Utility::printFailureDetail(stdout, *failure);
	}
}

void TestRunner::printErrors(const cu_List& errors) const
{
	int count = errors.size();
	if (count == 0) return;
	if (count == 1) {
		printf("There was 1 error:\n");
	} else {
		printf("There were %d errors:\n", count);
	}
	int index = 0;
	for (cu_List::const_iterator p = errors.begin(); p != errors.end(); ++p) {
		TestFailure* error = (TestFailure*)*p;
		printf("%d) %s", ++index, error->failedTest()->getName());
		Utility::printErrorDetail(stdout, *error);
	}
}

cu_NAMESPACE_END
