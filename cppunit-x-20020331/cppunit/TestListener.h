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
 * �e�X�g�̃��X�i�B<br>
 * A Listener for test progress.
 *
 * @see TestResult
 */
class TestListener
{
  public:
	/** �f�X�g���N�^�B */
	virtual ~TestListener() {}

	/**
	 * �e�X�g���J�n�����B
	 * @param test �e�X�g�B
	 */
	virtual void startTest(Test* test) = 0;

	/**
	 * �e�X�g���I�������B
	 * @param test �e�X�g�B
	 */
	virtual void endTest(Test* test) = 0;

	/**
	 * �e�X�g�̎��s���ǉ����ꂽ�B
	 * @param failure ���s�����e�X�g�̏��B
	 */
	virtual void addFailure(const TestFailure* failure) = 0;

	/**
	 * �G���[���ǉ����ꂽ�B
	 * @param error �G���[���B
	 */
	virtual void addError(const TestFailure* error) = 0;
};

cu_NAMESPACE_END

#endif /* !cppunit_TestListener_h */
