/*
 * RepeatedTestTest.h
 */

#ifndef cppunit_tests_RepeatedTestTest_h
#define cppunit_tests_RepeatedTestTest_h

#include <cppunit/TestCase.h>

USING_NAMESPACE_CPPUNIT

class RepeatedTestTest : public TestCase
{
  public:
	explicit RepeatedTestTest(const char* name) : TestCase(name) {}
	virtual void runTest();
	static Test* suite() { return new RepeatedTestTest("RepeatedTestTest"); }
};

#endif /* !cppunit_tests_RepeatedTestTest_h */
