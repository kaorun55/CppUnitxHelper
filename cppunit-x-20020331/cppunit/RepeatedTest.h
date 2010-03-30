/*
 * RepeatedTest.h
 */

#ifndef cppunit_RepeatedTest_h
#define cppunit_RepeatedTest_h

#include "cuconfig.h"
#include "TestDecorator.h"

cu_NAMESPACE_BEGIN(cppunit)

/**
 * �����e�X�g���J��Ԃ����s����f�R���[�^�B<br>
 * Decorator that runs a test repeatedly.
 *
 * �ۗL���� Test �̃��C�t�T�C�N�����Ǘ�����B
 */
class RepeatedTest : public TestDecorator
{
  public:
	/**
	 * �R���X�g���N�^�B
	 * @param test   ���s����e�X�g�B
	 * @param repeat �J��Ԃ��񐔁B
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
