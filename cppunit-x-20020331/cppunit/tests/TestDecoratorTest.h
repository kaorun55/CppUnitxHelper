/*
 * TestDecoratorTest.h
 */

#ifndef cppunit_tests_TestDecoratorTest_h
#define cppunit_tests_TestDecoratorTest_h

#include <cppunit/TestCase.h>

USING_NAMESPACE_CPPUNIT

class TestDecoratorTest : public TestCase
{
  public:
	explicit TestDecoratorTest(const char* name) : TestCase(name) {}
	virtual void runTest();
	static Test* suite() { return new TestDecoratorTest("TestDecoratorTest"); }
};

#endif /* !cppunit_tests_TestDecoratorTest_h */
