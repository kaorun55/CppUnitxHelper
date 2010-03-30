/*
 * TestDecoratorTest.cpp
 */

#include <cppunit/cudebug.h>
#include "TestDecoratorTest.h"
#include "TestCaseTest.h"
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestDecorator.h>

USING_NAMESPACE_CPPUNIT

void TestDecoratorTest::runTest()
{
	TestSuite* suite = new TestSuite("2Tests");
	suite->addTest(new TestCaseTest::SuccessTestCase("SuccessTestCase"));
	suite->addTest(new TestCaseTest::FailureTestCase("FailureTestCase"));
	TestDecorator test(suite);
	TEST_ASSERT_EQUALS(2, test.countTestCases());
	TEST_ASSERT_EQUALS("2Tests", test.getName());
	TEST_ASSERT_EQUALS("suite 2Tests", test.toString());

	TestResult result;
	test.run(&result);
	TEST_ASSERT_EQUALS(2, result.runCount());
	TEST_ASSERT_EQUALS(1, result.failureCount());
	TEST_ASSERT_EQUALS(0, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());
}
