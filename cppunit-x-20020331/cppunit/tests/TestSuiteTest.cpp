/*
 * TestSuiteTest.cpp
 */

#include <cppunit/cudebug.h>
#include "TestSuiteTest.h"
#include "TestCaseTest.h"
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>

USING_NAMESPACE_CPPUNIT

void TestSuiteTest::runTest()
{
	TestSuite suite("TestSuiteTest");
	suite.addTest(new TestCaseTest::SuccessTestCase("SuccessTestCase"));
	suite.addTest(new TestCaseTest::FailureTestCase("FailureTestCase"));
	suite.addTest(new TestCaseTest::FailTestCase("FailTestCase"));
	suite.addTest(new TestCaseTest::SetUpErrorTestCase("SetUpErrorTestCase"));
	suite.addTest(new TestCaseTest::TearDownErrorTestCase("TearDownErrorTestCase"));
	TEST_ASSERT_EQUALS(5, suite.countTestCases());
	TEST_ASSERT_EQUALS("TestSuiteTest", suite.getName());
	TEST_ASSERT_EQUALS("suite TestSuiteTest", suite.toString());

	TestResult result;
	suite.run(&result);
	TEST_ASSERT_EQUALS(5, result.runCount());
	TEST_ASSERT_EQUALS(3, result.failureCount());
	TEST_ASSERT_EQUALS(2, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());
}
