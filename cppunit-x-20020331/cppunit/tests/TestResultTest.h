/*
 * TestResultTest.h
 */

#ifndef cppunit_tests_TestResultTest_h
#define cppunit_tests_TestResultTest_h

#include <cppunit/TestCase.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestListener.h>

USING_NAMESPACE_CPPUNIT

class TestResultTest : public TestCase
{
  public:
	explicit TestResultTest(const char* name)
		: TestCase(name), m_mutex(0), m_result(0) {}
	virtual void setUp();
	virtual void tearDown();
	void testStartTest();
	void testEndTest();
	void testAddFailure();
	void testAddError();
	void testStop();
	static Test* suite();

  private:
	class TestMutex : public TestResult::Mutex {
	  public:
		TestMutex() : locked(0), unlocked(0) {}
		virtual void lock()   { ++locked;   }
		virtual void unlock() { ++unlocked; }
		int locked, unlocked;
	};

	class TestTestListener : public TestListener {
	  public:
		TestTestListener() : started(0), ended(0), failures(0), errors(0) {}
		virtual void startTest(Test* test) { ++started; }
		virtual void endTest(Test* test)   { ++ended;   }
		virtual void addFailure(const TestFailure* failure) { ++failures; }
		virtual void addError(const TestFailure* failure)   { ++errors;   }
		int started, ended, failures, errors;
	};

	class EmptyTest : public Test {
	  public:
		explicit EmptyTest(const char* name) : name(name) {}
		virtual void run(TestResult* result) {}
		virtual int countTestCases() const { return 0; }
		virtual const char* getName() const { return name; }
		virtual cu_String toString() const { return name; }
		const char* name;
	};

  private:
	TestMutex*  m_mutex;
	TestResult* m_result;
};

#endif /* !cppunit_tests_TestResultTest_h */
