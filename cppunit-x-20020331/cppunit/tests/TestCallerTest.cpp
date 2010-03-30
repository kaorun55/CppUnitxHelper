/*
 * TestCallerTest.cpp
 */

#include <cppunit/cudebug.h>
#include "TestCallerTest.h"
#include <cppunit/TestCaller.h>
#include <cppunit/TestResult.h>

#if defined(cu_NO_TEMPLATES) || defined(cu_HAS_INNER_CLASS_BUG)
typedef TestCallerTest::TestCallerTestCase TestCallerTestCase;
DECLARE_TEST_CALLER(TestCallerTestCase)
#endif

USING_NAMESPACE_CPPUNIT

void TestCallerTest::runTest()
{
#ifdef cu_NO_TEMPLATES
	typedef TestCaller(TestCallerTestCase) Caller;
#else
	typedef TestCaller<TestCallerTestCase> Caller;
#endif
	cu_AUTO_PTR(Caller) test(new TEST_CALLER(TestCallerTestCase, testRun));
	const char* testName = "TestCallerTestCase::testRun";
	TEST_ASSERT_EQUALS(1, test->countTestCases());
	TEST_ASSERT_EQUALS(testName, test->getName());
	TEST_ASSERT_EQUALS(testName, test->toString());

	TestResult result;
	test->run(&result);
	TEST_ASSERT(test->fixture()->wasSetUp);
	TEST_ASSERT(test->fixture()->wasRun);
	TEST_ASSERT(test->fixture()->wasTornDown);
	TEST_ASSERT_EQUALS(1, result.runCount());
	TEST_ASSERT_EQUALS(1, result.failureCount());
	TEST_ASSERT_EQUALS(1, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());
}
