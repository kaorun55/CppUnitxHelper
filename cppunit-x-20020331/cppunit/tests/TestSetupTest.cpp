/*
 * TestSetupTest.cpp
 */

#include <cppunit/cudebug.h>
#include "TestSetupTest.h"
#include "TestCaseTest.h"
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestResult.h>

USING_NAMESPACE_CPPUNIT

void TestSetupTest::testTestSetup()
{
	TestSuite* suite = new TestSuite("2Tests");
	suite->addTest(new TestCaseTest::SuccessTestCase("SuccessTestCase"));
	suite->addTest(new TestCaseTest::FailureTestCase("FailureTestCase"));
	TestTestSetup test(suite);
	TEST_ASSERT_EQUALS(2, test.countTestCases());
	TEST_ASSERT_EQUALS("2Tests", test.getName());
	TEST_ASSERT_EQUALS("suite 2Tests", test.toString());

	TestResult result;
	test.run(&result);
	TEST_ASSERT(test.wasSetUp);
	TEST_ASSERT(test.wasTornDown);
	TEST_ASSERT_EQUALS(2, result.runCount());
	TEST_ASSERT_EQUALS(1, result.failureCount());
	TEST_ASSERT_EQUALS(0, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());
}

void TestSetupTest::testSetUpError()
{
	SetUpErrorTestSetup
	test(new TestCaseTest::SuccessTestCase("SuccessTestCase"));
	TEST_ASSERT_EQUALS(1, test.countTestCases());
	TEST_ASSERT_EQUALS("SuccessTestCase", test.getName());
	TEST_ASSERT_EQUALS("SuccessTestCase", test.toString());

	TestResult result;
	test.run(&result);
	TEST_ASSERT(!test.wasSetUp);
	TEST_ASSERT(!test.wasTornDown);
	TEST_ASSERT_EQUALS(0, result.runCount());
	TEST_ASSERT_EQUALS(0, result.failureCount());
	TEST_ASSERT_EQUALS(1, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());
}

void TestSetupTest::testTearDownError()
{
	TearDownErrorTestSetup
	test(new TestCaseTest::FailureTestCase("FailureTestCase"));
	TEST_ASSERT_EQUALS(1, test.countTestCases());
	TEST_ASSERT_EQUALS("FailureTestCase", test.getName());
	TEST_ASSERT_EQUALS("FailureTestCase", test.toString());

	TestResult result;
	test.run(&result);
	TEST_ASSERT(test.wasSetUp);
	TEST_ASSERT(!test.wasTornDown);
	TEST_ASSERT_EQUALS(1, result.runCount());
	TEST_ASSERT_EQUALS(1, result.failureCount());
	TEST_ASSERT_EQUALS(1, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());
}

DECLARE_TEST_CALLER(TestSetupTest)

Test* TestSetupTest::suite()
{
	TestSuite* suite = new TestSuite("TestSetupTest");
	suite->addTest(new TEST_CALLER(TestSetupTest, testTestSetup));
	suite->addTest(new TEST_CALLER(TestSetupTest, testSetUpError));
	suite->addTest(new TEST_CALLER(TestSetupTest, testTearDownError));
	return suite;
}
