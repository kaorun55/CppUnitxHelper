/*
 * TestCaller.h
 */

#ifndef cppunit_TestCaller_h
#define cppunit_TestCaller_h

#include "cuconfig.h"
#include "Test.h"

#ifndef cu_NO_TEMPLATES

cu_NAMESPACE_BEGIN(cppunit)

/**
 * ���\�b�h���e�X�g�P�[�X�ɕϊ�����A�_�v�^�B<br>
 * Generate a test case from a fixture method.
 *
 * A test caller provides access to a test case method
 * on a test case class.<br>
 * Test callers are useful when you want to run an individual test
 * or add it to a suite.<br>
 * Test Callers invoke only one Test (i.e. test method)
 * on one Fixture of a TestCase.<br>
 * Here is an example:
 * <pre>
 * class MathTest : public TestCase {
 *     ...
 *   public:
 *     virtual void setUp();
 *     virtual void tearDown();
 *
 *     void testAdd();
 *     void testSubtract();
 *
 *     static Test* suite();
 * };
 *
 * Test* MathTest::suite() {
 *     TestSuite* suite = new TestSuite("MathTest");
 *     suite->addTest(new TEST_CALLER(MathTest, testAdd));
 *     return suite;
 * }
 * </pre>
 *
 * You can use a TestCaller to bind any test method on a TestCase class,<br>
 * as long as it accepts void and returns void.
 *
 * @see TestCase
 */
template <class Fixture>
class TestCaller : public Test
{ 
  public:
	typedef void (Fixture::*TestMethod)();

  public:
	/**
	 * �R���X�g���N�^�}�N���B
	 *
	 * ���� a �̋L�q�� b �̂悤�ɓW�J�����B
	 * <pre>
	 *   a) new TEST_CALLER(ATest, testSomething);
	 *   b) new TestCaller<ATest>("ATest::testSomething", &ATest::testSomething);
	 * </pre>
	 *
	 * @param Fixture TestCase �̃T�u�N���X�B
	 * @param method  �e�X�g���\�b�h�B
	 */
	#define TEST_CALLER(Fixture, method) \
		CPPUNIT::TestCaller<Fixture>(#Fixture "::" #method, &Fixture::method)

	/**
	 * �R���X�g���N�^�B<br>
	 * @param name �e�X�g�̖��O�B
	 * @param method �e�X�g���\�b�h�B
	 */
	TestCaller(const char* name, TestMethod method) : m_impl(name, method) {}

	virtual void run(TestResult* result) { m_impl.run(result); }
	virtual int countTestCases() const { return m_impl.countTestCases(); }
	virtual const char* getName() const { return m_impl.getName(); }
	virtual cu_String toString() const { return m_impl.toString(); }

	/** Fixture ��Ԃ��B */
	const Fixture* fixture() const { return &m_impl; }

  private:
	TestCaller(const TestCaller& rhs);
	TestCaller& operator=(const TestCaller& rhs);

  private:
	/**
	 * TestCaller �̎����N���X�B
	 *
	 * TestCaller ������ Fixture ���p������� VC++
	 * �ŃR���p�C���ł��Ȃ����Ƃ����邽�߁A���̃N���X��ݒu�B
	 */
	class CallerImpl : public Fixture {
	  public:
		CallerImpl(const char* name, TestMethod method)
			: Fixture(name), m_method(method) {}
		virtual void runTest() { (this->*m_method)(); }
	  private:
		TestMethod m_method;
	} m_impl;
};

cu_NAMESPACE_END

#define DECLARE_TEST_CALLER(Fixture)

#else /* cu_NO_TEMPLATES */

#define TEST_CALLER(Fixture, method) \
	TestCaller(Fixture)(#Fixture "::" #method, &Fixture::method)

#define DECLARE_TEST_CALLER(Fixture) TestCallerdeclare(Fixture)

#define TestCaller(Fixture) TestCaller ## Fixture
#define TestCallerdeclare(Fixture) \
class TestCaller(Fixture) : public Fixture { \
  public: \
	typedef void (Fixture::*TestMethod)(); \
	TestCaller(Fixture)(const char* name, TestMethod method) \
		: Fixture(name), m_method(method) {} \
	virtual void runTest() { (this->*m_method)(); } \
	const Fixture* fixture() const { return this; } \
  private: \
	TestMethod m_method; \
};

#endif /* cu_NO_TEMPLATES */

#endif /* !cppunit_TestCaller_h */
