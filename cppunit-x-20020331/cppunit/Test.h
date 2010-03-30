/*
 * Test.h
 */

#ifndef cppunit_Test_h
#define cppunit_Test_h

#include "cuconfig.h"

cu_NAMESPACE_BEGIN(cppunit)

class TestResult;

/**
 * �S�Ẵe�X�g�̊��N���X�B<br>
 * Base class for all test objects.
 *
 * All test objects should be a subclass of Test.<br>
 * Some test objects, TestCase for example, represent one individual test.<br>
 * Other test objects, such as TestSuite, are comprised of several tests.
 *
 * When a Test is run, the result is collected by a TestResult object.
 * 
 * @see TestCase
 * @see TestSuite
 * @see TestResult
 */
class Test
{
  public:
	/** �f�X�g���N�^�B */
	virtual ~Test() {}

	/**
	 * �e�X�g�����s���A���ʂ��W�߂�B<br>
	 * Run the test, collecting results.
	 *
	 * @param result �e�X�g���ʁB
	 */
	virtual void run(TestResult* result) = 0;

	/**
	 * �e�X�g�P�[�X�̌���Ԃ��B<br>
	 * Return the number of test cases invoked by run().
	 *
	 * The base unit of testing is the class TestCase.<br>
	 * This method returns the number of TestCase objects invoked
	 * by the run() method.
	 */
	virtual int countTestCases() const = 0;

	/**
	 * �e�X�g�̖��O��Ԃ��B<br>
	 * Returns the test name.
	 * 
	 * Each test has a name.
	 * This name may be used to find the test in a suite of tests.
	 */
	virtual const char* getName() const = 0;

	/**
	 * ������ɕϊ�����B<br>
	 * Description of the test, for diagnostic output.
	 *
	 * The test description will typically include the test name,
	 * but may have additional description.<br>
	 * For example, a test suite named <code>ComplexTest</code> may be
	 * described as <code>suite ComplexTest</code>.
	 */
	virtual cu_String toString() const = 0;
};

cu_NAMESPACE_END

#endif /* !cppunit_Test_h */
