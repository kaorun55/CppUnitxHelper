/*
 * TestSuite.h
 */

#ifndef cppunit_TestSuite_h
#define cppunit_TestSuite_h

#include "cuconfig.h"
#include "Test.h"

cu_NAMESPACE_BEGIN(cppunit)

/**
 * 複数のテストの組。<br>
 * A Composite of Tests.
 *
 * It runs a collection of test cases.<br>
 * Here is an example:
 * <pre>
 *     Test* suite = new TestSuite("MathTest");
 *     suite->addTest(new TEST_CALLER(MathTest, testAdd));
 *     suite->addTest(new TEST_CALLER(MathTest, testDivideByZero));
 * </pre>
 *
 * Note that TestSuites assume lifetime control for any tests
 * added to them.
 *
 * @see Test
 * @see TestCaller
 */
class TestSuite : public Test
{
  public:
	/**
	 * コンストラクタ。
	 * @param name テストの名前。
	 */
	explicit TestSuite(const char* name = "");

	/**
	 * 保有する Test を全て削除する。<br>
	 * Deletes all tests in the suite.
	 */
	virtual ~TestSuite();

	virtual void run(TestResult* result);
	virtual int countTestCases() const;
	virtual const char* getName() const;
	virtual cu_String toString() const;

	/**
	 * テストを追加する。<br>
	 * Adds a test to the suite.
	 */
	void addTest(Test* test);

  private:
	TestSuite(const TestSuite& rhs);
	TestSuite& operator=(const TestSuite& rhs);

  private:
	cu_String m_name;
	cu_List m_tests;	// list<Test*>
};

cu_NAMESPACE_END

#endif /* !cppunit_TestSuite_h */
