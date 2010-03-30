/*
 * TestDecorator.h
 */

#ifndef cppunit_TestDecorator_h
#define cppunit_TestDecorator_h

#include "cuconfig.h"
#include "Test.h"

cu_NAMESPACE_BEGIN(cppunit)

/**
 * �e�X�g�f�R���[�^�B<br>
 * Decorator for Tests.
 *
 * TestDecorator provides an alternate means to extend functionality<br>
 * of a test class without subclassing the test.<br>
 * Instead, one can subclass the decorater and use it to wrap the test class.
 *
 * �ۗL���� Test �̃��C�t�T�C�N�����Ǘ�����B
 */ 
class TestDecorator : public Test
{
  public:
	/**
	 * �R���X�g���N�^�B
	 * @param test ���ɂȂ�e�X�g�B
	 */
	explicit TestDecorator(Test* test);

	/** �f�X�g���N�^�B */
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
