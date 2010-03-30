/*
 * TestFailure.h
 */

#ifndef cppunit_TestFailure_h
#define cppunit_TestFailure_h

#include "cuconfig.h"

cu_NAMESPACE_BEGIN(cppunit)

class Test;

/**
 * 失敗したテストの情報。<br>
 * Record of a failed test execution.
 *
 * A TestFailure collects a failed test.
 *
 * @see TestResult
 */
class TestFailure
{
  public:
	/**
	 * コンストラクタ。
	 * @param test 失敗したテスト。
	 * @param msg  メッセージ。
	 * @param file 問題が発生したファイル名。
	 * @param line 問題が発生した行番号。
	 */
	TestFailure(Test* test, const cu_String& msg, const char* file, long line);

	/** デストラクタ。 */
	~TestFailure() {}

	/** 失敗したテストを返す。 */
	Test* failedTest() const { return m_failedTest; }

	/** 失敗したテストの情報を返す。 */
	const char* what() const { return m_message.c_str(); }

	/** 問題が発生したファイル名を返す。 */
	const char* file() const { return m_file; }

	/** 問題が発生した行番号を返す。 */
	long line() const { return m_line; }

	/** 文字列に変換する。 */
	cu_String toString() const;

  private:
	Test* m_failedTest;
	cu_String   m_message;
	const char* m_file;
	long        m_line;
};

cu_NAMESPACE_END

#endif /* !cppunit_TestFailure_h */
