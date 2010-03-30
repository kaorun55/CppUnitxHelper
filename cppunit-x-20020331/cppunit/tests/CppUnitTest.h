/*
 * CppUnitTest.h
 */

#ifndef cppunit_tests_CppUnitTest_h
#define cppunit_tests_CppUnitTest_h

#include <cppunit/TestCase.h>

USING_NAMESPACE_CPPUNIT

class CppUnitTest : public TestCase
{
  public:
	explicit CppUnitTest(const char* name) : TestCase(name) {}
	void testCppUnit15();
	void testCppUnit16();
	static Test* suite();
};

#endif /* !cppunit_tests_CppUnitTest_h */
