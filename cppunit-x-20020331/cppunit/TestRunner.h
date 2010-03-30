/*
 * TestRunner.h
 */

#ifndef cppunit_TestRunner_h
#define cppunit_TestRunner_h

#include "cuconfig.h"
#include "TestRegistry.h"

cu_NAMESPACE_BEGIN(cppunit)

class Test;
class TestResult;

/**
 * �e�L�X�g�Ńe�X�g�����i<br>
 * A text mode test runner.
 *
 * The test runner manage the life cycle of the added tests.
 *
 * TestRunner prints out a trace as the tests are executed followed by
 * a summary at the end.
 *
 * Here is an example:
 * <pre>
 * class ATestCase : public TestCase { ... };
 *
 * int main(int argc, char* argv[]) {
 *     TestRunner runner;
 *     runner.addTest("ATestCase", new ATestCase("ATestCase"));
 *     return runner.run(argc, argv);
 * }
 * </pre>
 */
class TestRunner
{
  public:
	/** �R���X�g���N�^�B */
	TestRunner();

	/** �f�X�g���N�^�B */
	~TestRunner() {}

	/**
	 * �e�X�g��ǉ�����B
	 * @param test �ǉ�����e�X�g�B
	 */
	void addTest(Test* test);

	/**
	 * �e�X�g��ǉ�����B
	 * @param name �e�X�g���B
	 * @param test �ǉ�����e�X�g�B
	 */
	void addTest(const char* name, Test* test);

	/**
	 * �e�X�g�����s����B
	 * @param argc �R�}���h���C�������̌��B
	 * @param argv �R�}���h���C�������̔z��B
	 * @return ���s���ʁB0: SUCCESS, 1: FAILURE, etc.
	 */
	int run(int argc, char* argv[]);

  protected:
	/**
	 * �R�}���h���C����������͂���B
	 * @param argc �R�}���h���C�������̌��B
	 * @param argv �R�}���h���C�������̔z��B
	 */
	int parseArgs(int argc, char* argv[]);

	/** �e�X�g�����s����B */
	int runTests();

	/** �L�[�{�[�h����̓��͂�҂B */
	void wait();

	/**
	 * �g�p�@��\������B
	 * @param command �R�}���h���B
	 */
	void printUsage(const char* command) const;

	/**
	 * �e�X�g���ʂ�\������B
	 * @param result �e�X�g���ʁB
	 */
	void printResult(const TestResult& result) const;

	/**
	 * �e�X�g���ʂ̃w�b�_��\������B
	 * @param result �e�X�g���ʁB
	 */
	void printHeader(const TestResult& result) const;

	/**
	 * ���s�����e�X�g�̃��X�g��\������B
	 * @param failures ���s�����e�X�g�̃��X�g�B
	 */
	void printFailures(const cu_List& failures) const;

	/**
	 * �G���[�̃��X�g��\������B
	 * @param errors �G���[�̃��X�g�B
	 */
	void printErrors(const cu_List& errors) const;

  private:
	TestRunner(const TestRunner& rhs);
	TestRunner& operator=(const TestRunner& rhs);

  private:
	bool m_help;
	bool m_wait;
	bool m_verbose;
	const char*  m_logfile;
	TestRegistry m_registry;

  private:
	class Utility;
	class SimpleListener;
	class Logger;
};

cu_NAMESPACE_END

#endif /* !cppunit_TestRunner_h */
