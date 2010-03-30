/*
 * TestUtilityTest.cpp
 */

#include <cppunit/cudebug.h>
#include "TestUtilityTest.h"
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestUtility.h>

USING_NAMESPACE_CPPUNIT

void TestUtilityTest::testTrimFileName()
{
	const char*
	name = TestUtility::trimFileName("/home/hoge/file.ext");
	TEST_ASSERT_EQUALS("file.ext", name);
	name = TestUtility::trimFileName("C:\\Home\\Hoge\\file.ext");
	TEST_ASSERT_EQUALS("file.ext", name);
	name = TestUtility::trimFileName("D:file.ext");
	TEST_ASSERT_EQUALS("file.ext", name);
}

DECLARE_TEST_CALLER(TestUtilityTest)

Test* TestUtilityTest::suite()
{
	TestSuite* suite = new TestSuite("TestUtilityTest");
	suite->addTest(new TEST_CALLER(TestUtilityTest, testTrimFileName));
	return suite;
}
