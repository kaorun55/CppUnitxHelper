/*
 * TestDecorator.h
 */

#ifndef cppunit_TestDecorator_h
#define cppunit_TestDecorator_h

#include "cuconfig.h"
#include "Test.h"

cu_NAMESPACE_BEGIN(cppunit)

/**
 * テストデコレータ。<br>
 * Decorator for Tests.
 *
 * TestDecorator provides an alternate means to extend functionality<br>
 * of a test class without subclassing the test.<br>
 * Instead, one can subclass the decorater and use it to wrap the test class.
 *
 * 保有する Test のライフサイクルを管理する。
 */ 
class TestDecorator : public Test
{
  public:
	/**
	 * コンストラクタ。
	 * @param test 元になるテスト。
	 */
	explicit TestDecorator(Test* test);

	/** デストラクタ。 */
	virtual ~TestDecorator();

	virtual void run(TestResult* result);
	virtual int countTestCases() const;
	virtual const char* getName() const;
	virtual cu_String toString() const;

  protected:
	Test* m_test;

  private:
	TestDecorator(const TestDecorator& rhs);
	TestDecorator& operator=(const TestDecorator& rhs);
};

cu_NAMESPACE_END

#endif /* !cppunit_TestDecorator_h */
