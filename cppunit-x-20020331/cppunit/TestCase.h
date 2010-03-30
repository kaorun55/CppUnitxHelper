/*
 * TestCase.h
 */

#ifndef cppunit_TestCase_h
#define cppunit_TestCase_h

#include "cuconfig.h"
#include "Test.h"

cu_NAMESPACE_BEGIN(cppunit)

/**
 * �e�X�g�P�[�X�B<br>
 * A single test object.
 *
 * This class is used to implement a simple test case:
 * define a subclass that overrides the runTest method.
 *
 * A test case defines the fixture to run multiple tests.
 * To define a test case, do the following:
 * -# implement a subclass of TestCase
 * -# the fixture is defined by instance variables
 * -# initialize the fixture state by overriding setUp
 *   (i.e. construct the instance variables of the fixture)
 * -# clean-up after a test by overriding tearDown.
 *
 * Each test runs in its own fixture so there can be no side effects
 * among test runs.<br>
 * Here is an example:
 * <pre>
 * class MathTest : public TestCase {
 *   protected:
 *     int m_value1;
 *     int m_value2;
 *
 *   public:
 *     explicit MathTest(const char* name) : TestCase(name) {}
 *
 *     virtual void setUp() {
 *         m_value1 = 2;
 *         m_value2 = 3;
 *     }
 * };
 * </pre>
 *
 * For each test implement a method which interacts with the fixture.<br>
 * Verify the expected results with assertions specified by calling<br>
 * <code>TEST_ASSERT</code> on the expression you want to test:
 * <pre>
 *   public:
 *     void testAdd() {
 *         int result = m_value1 + m_value2;
 *         TEST_ASSERT(result == 5);
 *     }
 * </pre>
 *
 * Once the methods are defined you can run them. To do this,
 * use a TestCaller.
 * <pre>
 *     Test* test = new TEST_CALLER(MathTest, testAdd);
 *     TestResult result;
 *     test->run(&amp;result);
 * </pre>
 *
 * The tests to be run can be collected into a TestSuite.
 * <pre>
 *   public:
 *     static Test* MathTest::suite() {
 *         TestSuite* suite = new TestSuite("MathTest");
 *         suite->addTest(new TEST_CALLER(MathTest, testAdd));
 *         suite->addTest(new TEST_CALLER(MathTest, testDivideByZero));
 *         return suite;
 *     }
 * </pre>
 *
 * @see TestSuite
 * @see TestCaller
 * @see TestResult
 */
class TestCase : public Test
{
  public:
	/**
	 * �R���X�g���N�^�B
	 * @param name �e�X�g�̖��O�B
	 */
	explicit TestCase(const char* name);

	/** �f�X�g���N�^�B */
	virtual ~TestCase();

	virtual void run(TestResult* result);
	virtual int countTestCases() const;
	virtual const char* getName() const;
	virtual cu_String toString() const;

	/**
	 * �e�X�g������������B<br>
	 * A hook for fixture set up.
	 */
	virtual void setUp() {}

	/**
	 * �e�X�g�̌�Еt��������B<br>
	 * A hook for fixture tear down.
	 */
	virtual void tearDown() {}

//	static Test* suite();

  protected:
	/** TestResult �Ƀe�X�g�̊J�n��ʒm����B */
	void startTest(TestResult* result);

	/** TestResult �Ƀe�X�g�̏I����ʒm����B */
	void endTest(TestResult* result);

	/** ���ۂɃe�X�g�����s����B */
	void runBare();

	/**
	 * �e�X�g�̓��e���`����B<br>
	 * All the work for runTest is deferred to subclasses.
	 */
	virtual void runTest() = 0;

	/**
	 * �e�X�g�p ASSERT �}�N���B
	 * @param cond �������ׂ������B
	 */
	#define TEST_ASSERT(cond) \
		if (!(cond)) TEST_FAIL(#cond)

	/**
	 * �e�X�g�p ASSERT �}�N���B
	 *
	 * ���I���W�i���ƈ����̏������t�Ȃ̂Œ���!!
	 *   J2SE 1.4 �� assert ���Ɠ����� (�b��d�l)�B
	 *
	 * @param cond �������ׂ������B
	 * @param msg  ���b�Z�[�W�B
	 */
	#define TEST_ASSERT_MESSAGE(cond, msg) \
		if (!(cond)) TEST_FAIL(msg)

	/**
	 * �e�X�g�p ASSERT �}�N���B
	 * @param expected ���҂����l�B
	 * @param actual   ���ۂ̒l�B
	 */
	#define TEST_ASSERT_EQUALS(expected, actual) \
		if (!assertEqualsImpl(expected, actual, __FILE__, __LINE__)) return

	/**
	 * �e�X�g�p ASSERT �}�N���B
	 * @param expected ���҂����l�B
	 * @param actual   ���ۂ̒l�B
	 * @param delta    �덷�͈̔́B
	 */
	#define TEST_ASSERT_EQUALS_DOUBLE(expected, actual, delta) \
		if (!assertEqualsImpl(expected, actual, __FILE__, __LINE__, delta)) return

	/**
	 * �e�X�g�p FAIL �}�N���B
	 * @param msg ���b�Z�[�W�B
	 */
	#define TEST_FAIL(msg) \
		do { addFailure(msg, __FILE__, __LINE__); return; } while (0)

	/**
	 * �e�X�g�p ERROR �}�N���B
	 * @param msg ���b�Z�[�W�B
	 */
	#define TEST_ERROR(msg) \
		do { addError(msg, __FILE__, __LINE__); return; } while (0)

	/**
	 * �e�X�g�̎��s��ǉ�����B
	 * @param msg  ���b�Z�[�W�B
	 * @param file ���������t�@�C�����B
	 * @param line ���������s�ԍ��B
	 */
	void addFailure(const cu_String& msg, const char* file, long line);

	/**
	 * �G���[��ǉ�����B
	 * @param msg  ���b�Z�[�W�B
	 * @param file ���������t�@�C�����B
	 * @param line ���������s�ԍ��B
	 */
	void addError(const cu_String& msg, const char* file, long line);

	// ������2��]�������̂�h�����߁B
	bool assertEqualsImpl(int expected, int actual,
			const char* file, long line);
	bool assertEqualsImpl(long expected, long actual,
			const char* file, long line);
	bool assertEqualsImpl(double expected, double actual,
			const char* file, long line, double delta = 0);
	bool assertEqualsImpl(const char* expected, const char* actual,
			const char* file, long line);

	// �ȉ��A�S�ăI�[�o���[�h���Ă����K�v������B
#if defined(cu_NO_MEMBER_TEMPLATES) || defined(cu_NO_STD_STRING)
	bool assertEqualsImpl(const char* expected, const cu_String& actual,
			const char* file, long line)
		{ return assertEqualsImpl(expected, actual.c_str(), file, line); }
	bool assertEqualsImpl(const cu_String& expected, const char* actual,
			const char* file, long line)
		{ return assertEqualsImpl(expected.c_str(), actual, file, line); }
	bool assertEqualsImpl(const cu_String& expected, const cu_String& actual,
			const char* file, long line)
		{ return assertEqualsImpl(expected.c_str(), actual.c_str(), file, line); }
#else
	template <class Ch, class Tr, class Alloc>
	bool assertEqualsImpl(const char* expected,
			const cu_STD::basic_string<Ch, Tr, Alloc>& actual,
			const char* file, long line)
		{ return assertEqualsImpl(expected, actual.c_str(), file, line); }
	template <class Ch, class Tr, class Alloc>
	bool assertEqualsImpl(
			const cu_STD::basic_string<Ch, Tr, Alloc>& expected,
			const char* actual, const char* file, long line)
		{ return assertEqualsImpl(expected.c_str(), actual, file, line); }
	template <class Ch, class Tr, class Alloc>
	bool assertEqualsImpl(
			const cu_STD::basic_string<Ch, Tr, Alloc>& expected,
			const cu_STD::basic_string<Ch, Tr, Alloc>& actual,
			const char* file, long line)
		{ return assertEqualsImpl(expected.c_str(), actual.c_str(), file, line); }
#endif

	static bool equals(double x1, double x2, double delta = 0);
	static bool equals(const char* s1, const char* s2);

	static cu_String notEqualsMessage(int expected, int actual);
	static cu_String notEqualsMessage(long expected, long actual);
	static cu_String notEqualsMessage(double expected, double actual);
	static cu_String notEqualsMessage(const char* expected, const char* actual);

  private:
	TestCase(const TestCase&);
	TestCase& operator=(const TestCase&);

  private:
	cu_String   m_name;
	bool        m_hasError;
	TestResult* m_result;	// ���s�������Z�b�g�����B
};

cu_NAMESPACE_END

// TestCaller �̑���Ɉȉ��̃}�N���𗘗p���邱�Ƃ��ł���B
/**
 * �R���X�g���N�^�}�N���B
 *
 * ���� a �̋L�q�� b �̂悤�ɓW�J�����B
 * <pre>
 *   a) new TEST_CASE(ATest, testSomething);
 *   b) new ATest("ATest::testSomething", &ATest::testSomething);
 * </pre>
 *
 * @param Fixture TestCase �̃T�u�N���X�B
 * @param method  �e�X�g���\�b�h�B
 */
#define TEST_CASE(Fixture, method) \
	Fixture(#Fixture "::" #method, &Fixture::method)

/**
 * �e�X�g�P�[�X�̋��ʒ�`�B
 * @param Fixture TestCase �̃T�u�N���X�B
 */
#define TEST_CASE_COMMON(Fixture) \
  public: \
	typedef void (Fixture::*TestMethod)(); \
	Fixture(const char* name, TestMethod method) \
		: TestCase(name), m_method(method) {} \
	virtual void runTest() { (this->*m_method)(); } \
  private: \
	 TestMethod m_method;

/*
 * �I���W�i�� CppUnit �݊��}�N���B
 */
#ifdef CPPUNIT_COMPATIBLE
#  include <assert.h>
#  undef  assert
#  define assert(condition) TEST_ASSERT(condition)
#  define assertEquals(expected, actual) \
	TEST_ASSERT_EQUALS(expected, actual)
#  define assertLongsEqual(expected, actual) \
	TEST_ASSERT_EQUALS(expected, actual)
#  define assertDoublesEqual(expected, actual, delta) \
	TEST_ASSERT_EQUALS_DOUBLE(expected, actual, delta)
#endif /* CPPUNIT_COMPATIBLE */

#ifdef CPPUNIT16_COMPATIBLE
#  define CPPUNIT_ASSERT(condition) TEST_ASSERT(condition)
#  define CPPUNIT_ASSERT_MESSAGE(message, condition) \
	TEST_ASSERT_MESSAGE(condition, message)
#  define CPPUNIT_ASSERT_EQUAL(expected, actual) \
	TEST_ASSERT_EQUALS(expected, actual)
#  define CPPUNIT_ASSERT_DOUBLES_EQUAL(expected, actual, delta) \
	TEST_ASSERT_EQUALS_DOUBLE(expected, actual, delta)
#endif /* CPPUNIT16_COMPATIBLE */

#endif /* !cppunit_TestCase_h */
