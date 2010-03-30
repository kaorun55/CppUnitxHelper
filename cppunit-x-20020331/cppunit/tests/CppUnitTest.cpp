/*
 * CppUnitTest.cpp
 */

#define CPPUNIT_COMPATIBLE
#define CPPUNIT16_COMPATIBLE

#include <cppunit/cudebug.h>
#include "CppUnitTest.h"
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

USING_NAMESPACE_CPPUNIT

void CppUnitTest::testCppUnit15()
{
	assert(true);
	assertLongsEqual(12L, 12L);
	assertDoublesEqual(1.0, 1.02, 0.3);
}

void CppUnitTest::testCppUnit16()
{
	CPPUNIT_ASSERT(true);
	CPPUNIT_ASSERT_MESSAGE("fail", true);
	CPPUNIT_ASSERT_EQUAL(12L, 12L);
	CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, 1.02, 0.3);
}

DECLARE_TEST_CALLER(CppUnitTest)

Test* CppUnitTest::suite()
{
	TestSuite* suite = new TestSuite("CppUnitTest");
	suite->addTest(new TEST_CALLER(CppUnitTest, testCppUnit15));
	suite->addTest(new TEST_CALLER(CppUnitTest, testCppUnit16));
	return suite;
}
