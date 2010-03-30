/*
 * TestSuiteTest.h
 */

#ifndef cppunit_tests_TestSuiteTest_h
#define cppunit_tests_TestSuiteTest_h

#include <cppunit/TestCase.h>

USING_NAMESPACE_CPPUNIT

class TestSuiteTest : public TestCase
{
  public:
	explicit TestSuiteTest(const char* name) : TestCase(name) {}
	virtual void runTest();
	static Test* suite() { return new TestSuiteTest("TestSuiteTest"); }
};

#endif /* !cppunit_tests_TestSuiteTest_h */
