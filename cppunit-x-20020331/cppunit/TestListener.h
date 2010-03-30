/*
 * TestListener.h
 */

#ifndef cppunit_TestListener_h
#define cppunit_TestListener_h

#include "cuconfig.h"

cu_NAMESPACE_BEGIN(cppunit)

class Test;
class TestFailure;

/**
 * テストのリスナ。<br>
 * A Listener for test progress.
 *
 * @see TestResult
 */
class TestListener
{
  public:
	/** デストラクタ。 */
	virtual ~TestListener() {}

	/**
	 * テストが開始した。
	 * @param test テスト。
	 */
	virtual void startTest(Test* test) = 0;

	/**
	 * テストが終了した。
	 * @param test テスト。
	 */
	virtual void endTest(Test* test) = 0;

	/**
	 * テストの失敗が追加された。
	 * @param failure 失敗したテストの情報。
	 */
	virtual void addFailure(const TestFailure* failure) = 0;

	/**
	 * エラーが追加された。
	 * @param error エラー情報。
	 */
	virtual void addError(const TestFailure* error) = 0;
};

cu_NAMESPACE_END

#endif /* !cppunit_TestListener_h */
