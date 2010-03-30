/*
 * SampleTest.cpp
 *
 * Test Framework のサンプルプログラム。
 */

// for Leak Check
#include <cppunit/cudebug.h>

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestRunner.h>
#include <string.h>

USING_NAMESPACE_CPPUNIT

/**
 * runTest() を上書きする例。
 */
class SampleTest1 : public TestCase
{
  public:
	/// お決まりのコンストラクタ。
	explicit SampleTest1(const char* name) : TestCase(name) {}

	/// テスト本体を実行する。
	virtual void runTest() {
		// ここにテストを書く。
		short num = 12;
		TEST_ASSERT_EQUALS(12, num);
		const char* str = "abc";
		TEST_ASSERT_EQUALS("ABC", str);
	}
};

/**
 * TEST_CASE マクロを使用する例。
 * 実行するテストを属性として持っている。
 *
 * @see TEST_CASE() (in TestCase.h)
 */
class SampleTest2 : public TestCase
{
	// コンストラクタ、runTest() 等の定義。
	TEST_CASE_COMMON(SampleTest2)

  public:
	/// テストを初期化する。
	virtual void setUp() {
		m_num = new int(12);
		strcpy(m_str, "abc");
	}

	/// テストの後片付けをする。
	virtual void tearDown() {
		delete m_num;
	}

	/// 数値の比較テスト。
	void testNumberEquals() {
		TEST_ASSERT_EQUALS(13, *m_num);
	}

	/// 文字列の比較テスト。
	void testStringEquals() {
		TEST_ASSERT_EQUALS("abc", m_str);
	}

	/// 全てのテストの集合を返す。定義しておくと便利。
	static Test* suite() {
		TestSuite* suite = new TestSuite("SampleTest2");
		// TEST_CASE マクロを使用してテストオブジェクトを生成。
		suite->addTest(new TEST_CASE(SampleTest2, testNumberEquals));
		suite->addTest(new TEST_CASE(SampleTest2, testStringEquals));
		return suite;
	}

  private:
	int* m_num;
	char m_str[80];
};

/**
 * TestCaller を使用する例。
 *
 * @see TestCaller
 */
class SampleTest3 : public TestCase
{
  public:
	/// お決まりのコンストラクタ。
	explicit SampleTest3(const char* name) : TestCase(name) {}

	/// テストを初期化する。
	virtual void setUp() {
		m_num = new int(12);
		strcpy(m_str, "abc");
	}

	/// テストの後片付けをする。
	virtual void tearDown() {
		delete m_num;
	}

	/// 数値の比較テスト。
	void testNumberEquals() {
		TEST_ASSERT_EQUALS(13, *m_num);
	}

	/// 文字列の比較テスト。
	void testStringEquals() {
		TEST_ASSERT_EQUALS("abc", m_str);
	}

	/// 未実装のテスト。
	void testNotImplemented() {
		TEST_ERROR("not implemented yet");
	}

	/// 全てのテストの集合を返す。定義しておくと便利。
	static Test* suite();

  private:
	int* m_num;
	char m_str[80];
};

// template が使用できない環境ではこれを追加。
DECLARE_TEST_CALLER(SampleTest3)

/**
 * 全てのテストの集合を返す。
 */
Test* SampleTest3::suite()
{
	TestSuite* suite = new TestSuite("SampleTest3");
	// TestCaller の記述はマクロを使用すると簡単になる。
	suite->addTest(new TEST_CALLER(SampleTest3, testNumberEquals));
	suite->addTest(new TEST_CALLER(SampleTest3, testStringEquals));
	suite->addTest(new TEST_CALLER(SampleTest3, testNotImplemented));
	return suite;
}

/**
 * サンプルのメイン関数。
 */
int main(int argc, char* argv[])
{
#if defined(ENABLE_LEAK_CHECKER) && !defined(_MSC_VER)
	LeakChecker checker;
#endif

	// TestRunner にテストを追加して実行する。
	TestRunner runner;
	runner.addTest("SampleTest1", new SampleTest1("SampleTest1"));
	runner.addTest("SampleTest2", SampleTest2::suite());
	runner.addTest("SampleTest3", SampleTest3::suite());
	return runner.run(argc, argv);
}

// 以下の記述はデバッグ用なので無視してください。
#ifdef USE_DEBUGTOOLS
#  include <debug/debugtools.cpp>
#endif

#if defined(ENABLE_LEAK_CHECKER) && defined(_MSC_VER)
#  pragma warning(disable:4073)
#  pragma init_seg(lib)
LeakChecker g_leakChecker;
#endif
