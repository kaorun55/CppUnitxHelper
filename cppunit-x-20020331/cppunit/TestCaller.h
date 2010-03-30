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
 * メソッドをテストケースに変換するアダプタ。<br>
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
	 * コンストラクタマクロ。
	 *
	 * 次の a の記述は b のように展開される。
	 * <pre>
	 *   a) new TEST_CALLER(ATest, testSomething);
	 *   b) new TestCaller<ATest>("ATest::testSomething", &ATest::testSomething);
	 * </pre>
	 *
	 * @param Fixture TestCase のサブクラス。
	 * @param method  テストメソッド。
	 */
	#define TEST_CALLER(Fixture, method) \
		CPPUNIT::TestCaller<Fixture>(#Fixture "::" #method, &Fixture::method)

	/**
	 * コンストラクタ。<br>
	 * @param name テストの名前。
	 * @param method テストメソッド。
	 */
	TestCaller(const char* name, TestMethod method) : m_impl(name, method) {}

	virtual void run(TestResult* result) { m_impl.run(result); }
	virtual int countTestCases() const { return m_impl.countTestCases(); }
	virtual const char* getName() const { return m_impl.getName(); }
	virtual cu_String toString() const { return m_impl.toString(); }

	/** Fixture を返す。 */
	const Fixture* fixture() const { return &m_impl; }

  private:
	TestCaller(const TestCaller& rhs);
	TestCaller& operator=(const TestCaller& rhs);

  private:
	/**
	 * TestCaller の実装クラス。
	 *
	 * TestCaller が直接 Fixture を継承すると VC++
	 * でコンパイルできないことがあるため、このクラスを設置。
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
