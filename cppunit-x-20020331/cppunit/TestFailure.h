/*
 * TestFailure.h
 */

#ifndef cppunit_TestFailure_h
#define cppunit_TestFailure_h

#include "cuconfig.h"

cu_NAMESPACE_BEGIN(cppunit)

class Test;

/**
 * ���s�����e�X�g�̏��B<br>
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
	 * �R���X�g���N�^�B
	 * @param test ���s�����e�X�g�B
	 * @param msg  ���b�Z�[�W�B
	 * @param file ��肪���������t�@�C�����B
	 * @param line ��肪���������s�ԍ��B
	 */
	TestFailure(Test* test, const cu_String& msg, const char* file, long line);

	/** �f�X�g���N�^�B */
	~TestFailure() {}

	/** ���s�����e�X�g��Ԃ��B */
	Test* failedTest() const { return m_failedTest; }

	/** ���s�����e�X�g�̏���Ԃ��B */
	const char* what() const { return m_message.c_str(); }

	/** ��肪���������t�@�C������Ԃ��B */
	const char* file() const { return m_file; }

	/** ��肪���������s�ԍ���Ԃ��B */
	long line() const { return m_line; }

	/** ������ɕϊ�����B */
	cu_String toString() const;

  private:
	Test* m_failedTest;
	cu_String   m_message;
	const char* m_file;
	long        m_line;
};

cu_NAMESPACE_END

#endif /* !cppunit_TestFailure_h */
