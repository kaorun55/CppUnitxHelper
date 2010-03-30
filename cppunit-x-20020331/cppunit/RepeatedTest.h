/*
 * RepeatedTest.h
 */

#ifndef cppunit_RepeatedTest_h
#define cppunit_RepeatedTest_h

#include "cuconfig.h"
#include "TestDecorator.h"

cu_NAMESPACE_BEGIN(cppunit)

/**
 * 同じテストを繰り返し実行するデコレータ。<br>
 * Decorator that runs a test repeatedly.
 *
 * 保有する Test のライフサイクルを管理する。
 */
class RepeatedTest : public TestDecorator
{
  public:
	/**
	 * コンストラクタ。
	 * @param test   実行するテスト。
	 * @param repeat 繰り返し回数。
	 */
	RepeatedTest(Test* test, int repeat);

	virtual void run(TestResult* result);
	virtual int countTestCases() const;
	virtual cu_String toString() const;

  private:
	RepeatedTest(const RepeatedTest& rhs);
	RepeatedTest& operator=(const RepeatedTest& rhs);

  private:
	const int m_timesRepeat;
};

cu_NAMESPACE_END

#endif /* !cppunit_RepeatedTest_h */
