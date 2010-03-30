/*
 * SampleTest.cpp
 *
 * Test Framework �̃T���v���v���O�����B
 */

// for Leak Check
#include <cppunit/cudebug.h>

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestRunner.h>
#include <string.h>

USING_NAMESPACE_CPPUNIT

/**
 * runTest() ���㏑�������B
 */
class SampleTest1 : public TestCase
{
  public:
	/// �����܂�̃R���X�g���N�^�B
	explicit SampleTest1(const char* name) : TestCase(name) {}

	/// �e�X�g�{�̂����s����B
	virtual void runTest() {
		// �����Ƀe�X�g�������B
		short num = 12;
		TEST_ASSERT_EQUALS(12, num);
		const char* str = "abc";
		TEST_ASSERT_EQUALS("ABC", str);
	}
};

/**
 * TEST_CASE �}�N�����g�p�����B
 * ���s����e�X�g�𑮐��Ƃ��Ď����Ă���B
 *
 * @see TEST_CASE() (in TestCase.h)
 */
class SampleTest2 : public TestCase
{
	// �R���X�g���N�^�ArunTest() ���̒�`�B
	TEST_CASE_COMMON(SampleTest2)

  public:
	/// �e�X�g������������B
	virtual void setUp() {
		m_num = new int(12);
		strcpy(m_str, "abc");
	}

	/// �e�X�g�̌�Еt��������B
	virtual void tearDown() {
		delete m_num;
	}

	/// ���l�̔�r�e�X�g�B
	void testNumberEquals() {
		TEST_ASSERT_EQUALS(13, *m_num);
	}

	/// ������̔�r�e�X�g�B
	void testStringEquals() {
		TEST_ASSERT_EQUALS("abc", m_str);
	}

	/// �S�Ẵe�X�g�̏W����Ԃ��B��`���Ă����ƕ֗��B
	static Test* suite() {
		TestSuite* suite = new TestSuite("SampleTest2");
		// TEST_CASE �}�N�����g�p���ăe�X�g�I�u�W�F�N�g�𐶐��B
		suite->addTest(new TEST_CASE(SampleTest2, testNumberEquals));
		suite->addTest(new TEST_CASE(SampleTest2, testStringEquals));
		return suite;
	}

  private:
	int* m_num;
	char m_str[80];
};

/**
 * TestCaller ���g�p�����B
 *
 * @see TestCaller
 */
class SampleTest3 : public TestCase
{
  public:
	/// �����܂�̃R���X�g���N�^�B
	explicit SampleTest3(const char* name) : TestCase(name) {}

	/// �e�X�g������������B
	virtual void setUp() {
		m_num = new int(12);
		strcpy(m_str, "abc");
	}

	/// �e�X�g�̌�Еt��������B
	virtual void tearDown() {
		delete m_num;
	}

	/// ���l�̔�r�e�X�g�B
	void testNumberEquals() {
		TEST_ASSERT_EQUALS(13, *m_num);
	}

	/// ������̔�r�e�X�g�B
	void testStringEquals() {
		TEST_ASSERT_EQUALS("abc", m_str);
	}

	/// �������̃e�X�g�B
	void testNotImplemented() {
		TEST_ERROR("not implemented yet");
	}

	/// �S�Ẵe�X�g�̏W����Ԃ��B��`���Ă����ƕ֗��B
	static Test* suite();

  private:
	int* m_num;
	char m_str[80];
};

// template ���g�p�ł��Ȃ����ł͂����ǉ��B
DECLARE_TEST_CALLER(SampleTest3)

/**
 * �S�Ẵe�X�g�̏W����Ԃ��B
 */
Test* SampleTest3::suite()
{
	TestSuite* suite = new TestSuite("SampleTest3");
	// TestCaller �̋L�q�̓}�N�����g�p����ƊȒP�ɂȂ�B
	suite->addTest(new TEST_CALLER(SampleTest3, testNumberEquals));
	suite->addTest(new TEST_CALLER(SampleTest3, testStringEquals));
	suite->addTest(new TEST_CALLER(SampleTest3, testNotImplemented));
	return suite;
}

/**
 * �T���v���̃��C���֐��B
 */
int main(int argc, char* argv[])
{
#if defined(ENABLE_LEAK_CHECKER) && !defined(_MSC_VER)
	LeakChecker checker;
#endif

	// TestRunner �Ƀe�X�g��ǉ����Ď��s����B
	TestRunner runner;
	runner.addTest("SampleTest1", new SampleTest1("SampleTest1"));
	runner.addTest("SampleTest2", SampleTest2::suite());
	runner.addTest("SampleTest3", SampleTest3::suite());
	return runner.run(argc, argv);
}

// �ȉ��̋L�q�̓f�o�b�O�p�Ȃ̂Ŗ������Ă��������B
#ifdef USE_DEBUGTOOLS
#  include <debug/debugtools.cpp>
#endif

#if defined(ENABLE_LEAK_CHECKER) && defined(_MSC_VER)
#  pragma warning(disable:4073)
#  pragma init_seg(lib)
LeakChecker g_leakChecker;
#endif
