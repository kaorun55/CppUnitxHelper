/*
 * TestUtilityTest.h
 */

#ifndef cppunit_tests_TestUtilityTest_h
#define cppunit_tests_TestUtilityTest_h

#include <cppunit/TestCase.h>

USING_NAMESPACE_CPPUNIT

class TestUtilityTest : public TestCase
{
  public:
	explicit TestUtilityTest(const char* name) : TestCase(name) {}
	void testTrimFileName();
	static Test* suite();
};

#endif /* !cppunit_tests_TestUtilityTest_h */
