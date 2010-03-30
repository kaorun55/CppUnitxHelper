/*
 * TestRunner.h
 */

#ifndef cppunit_TestRunner_h
#define cppunit_TestRunner_h

#include "cuconfig.h"
#include "TestRegistry.h"

cu_NAMESPACE_BEGIN(cppunit)

class Test;
class TestResult;

/**
 * テキスト版テストランナ<br>
 * A text mode test runner.
 *
 * The test runner manage the life cycle of the added tests.
 *
 * TestRunner prints out a trace as the tests are executed followed by
 * a summary at the end.
 *
 * Here is an example:
 * <pre>
 * class ATestCase : public TestCase { ... };
 *
 * int main(int argc, char* argv[]) {
 *     TestRunner runner;
 *     runner.addTest("ATestCase", new ATestCase("ATestCase"));
 *     return runner.run(argc, argv);
 * }
 * </pre>
 */
class TestRunner
{
  public:
	/** コンストラクタ。 */
	TestRunner();

	/** デストラクタ。 */
	~TestRunner() {}

	/**
	 * テストを追加する。
	 * @param test 追加するテスト。
	 */
	void addTest(Test* test);

	/**
	 * テストを追加する。
	 * @param name テスト名。
	 * @param test 追加するテスト。
	 */
	void addTest(const char* name, Test* test);

	/**
	 * テストを実行する。
	 * @param argc コマンドライン引数の個数。
	 * @param argv コマンドライン引数の配列。
	 * @return 実行結果。0: SUCCESS, 1: FAILURE, etc.
	 */
	int run(int argc, char* argv[]);

  protected:
	/**
	 * コマンドライン引数を解析する。
	 * @param argc コマンドライン引数の個数。
	 * @param argv コマンドライン引数の配列。
	 */
	int parseArgs(int argc, char* argv[]);

	/** テストを実行する。 */
	int runTests();

	/** キーボードからの入力を待つ。 */
	void wait();

	/**
	 * 使用法を表示する。
	 * @param command コマンド名。
	 */
	void printUsage(const char* command) const;

	/**
	 * テスト結果を表示する。
	 * @param result テスト結果。
	 */
	void printResult(const TestResult& result) const;

	/**
	 * テスト結果のヘッダを表示する。
	 * @param result テスト結果。
	 */
	void printHeader(const TestResult& result) const;

	/**
	 * 失敗したテストのリストを表示する。
	 * @param failures 失敗したテストのリスト。
	 */
	void printFailures(const cu_List& failures) const;

	/**
	 * エラーのリストを表示する。
	 * @param errors エラーのリスト。
	 */
	void printErrors(const cu_List& errors) const;

  private:
	TestRunner(const TestRunner& rhs);
	TestRunner& operator=(const TestRunner& rhs);

  private:
	bool m_help;
	bool m_wait;
	bool m_verbose;
	const char*  m_logfile;
	TestRegistry m_registry;

  private:
	class Utility;
	class SimpleListener;
	class Logger;
};

cu_NAMESPACE_END

#endif /* !cppunit_TestRunner_h */
