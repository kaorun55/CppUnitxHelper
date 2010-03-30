/*
 * TestSetup.h
 */

#ifndef cppunit_TestSetup_h
#define cppunit_TestSetup_h

#include "cuconfig.h"
#include "TestCase.h"
#include "TestDecorator.h"

cu_NAMESPACE_BEGIN(cppunit)

/**
 * �e�X�g�̏������A��Еt����ǉ�����f�R���[�^�B<br>
 * Decorator to set up and tear down additional fixture state.
 *
 * �ۗL���� Test �̃��C�t�T�C�N�����Ǘ�����B
 */
class TestSetup : public TestDecorator
{
  public:
	/**
	 * �R���X�g���N�^�B
	 * @param test ���ɂȂ�e�X�g�B
	 */
	explicit TestSetup(Test* test);

	virtual void run(TestResult* result);

  protected:
	/** �e�X�g������������B */
	virtual void setUp() {}

	/** �e�X�g�̌�Еt��������B */
	virtual void tearDown() {}

	/** ���ۂɃe�X�g�����s����B */
	void runBare();

//	#define TEST_ERROR(msg)
	/**
	 * �G���[��ǉ�����B
	 * @param msg  ���b�Z�[�W�B
	 * @param file ���������t�@�C�����B
	 * @param line ���������s�ԍ��B
	 * @see TEST_ERROR
	 */
	void addError(const cu_String& msg, const char* file, long line);

  private:
	TestSetup(const TestSetup& rhs);
	TestSetup& operator=(const TestSetup& rhs);

  private:
	bool m_hasError;
	TestResult* m_result;	// ���s�������Z�b�g�����B
};

cu_NAMESPACE_END

#endif /* !cppunit_TestSetup_h */
