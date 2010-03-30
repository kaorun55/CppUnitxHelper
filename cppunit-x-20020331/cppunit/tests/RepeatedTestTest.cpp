/*
 * RepeatedTestTest.cpp
 */

#include <cppunit/cudebug.h>
#include "RepeatedTestTest.h"
#include "TestCaseTest.h"
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/RepeatedTest.h>

USING_NAMESPACE_CPPUNIT

void RepeatedTestTest::runTest()
{
	TestSuite* suite = new TestSuite("2Tests");
	suite->addTest(new TestCaseTest::SuccessTestCase("SuccessTestCase"));
	suite->addTest(new TestCaseTest::FailureTestCase("FailureTestCase"));
	RepeatedTest test(suite, 3);
	TEST_ASSERT_EQUALS(6, test.countTestCases());
	TEST_ASSERT_EQUALS("2Tests", test.getName());
	TEST_ASSERT_EQUALS("suite 2Tests (repeated)", test.toString());

	TestResult result;
	test.run(&result);
	TEST_ASSERT_EQUALS(6, result.runCount());
	TEST_ASSERT_EQUALS(3, result.failureCount());
	TEST_ASSERT_EQUALS(0, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());
}
