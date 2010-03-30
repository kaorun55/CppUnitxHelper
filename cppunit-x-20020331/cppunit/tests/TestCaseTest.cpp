/*
 * TestCaseTest.cpp
 */

#include <cppunit/cudebug.h>
#include "TestCaseTest.h"
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestFailure.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <string.h>

USING_NAMESPACE_CPPUNIT

void TestCaseTest::testSuccess()
{
	SuccessTestCase testCase("SuccessTestCase");
	TestResult result;
	testCase.run(&result);
	TEST_ASSERT(testCase.wasSetUp);
	TEST_ASSERT(testCase.wasTornDown);
	TEST_ASSERT_EQUALS(1, result.runCount());
	TEST_ASSERT_EQUALS(0, result.failureCount());
	TEST_ASSERT_EQUALS(0, result.errorCount());
	TEST_ASSERT(result.wasSuccessful());
}

void TestCaseTest::testFailure()
{
	FailureTestCase testCase("FailureTestCase");
	TestResult result;
	testCase.run(&result);
	TEST_ASSERT(testCase.wasSetUp);
	TEST_ASSERT(testCase.wasTornDown);
	TEST_ASSERT_EQUALS(1, result.runCount());
	TEST_ASSERT_EQUALS(1, result.failureCount());
	TEST_ASSERT_EQUALS(0, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());
}

void TestCaseTest::testAssertMessage()
{
	MessageTestCase testCase("MessageTestCase");
	TestResult result;
	testCase.run(&result);
	TEST_ASSERT(testCase.wasSetUp);
	TEST_ASSERT(testCase.wasTornDown);
	TEST_ASSERT_EQUALS(1, result.runCount());
	TEST_ASSERT_EQUALS(1, result.failureCount());
	TEST_ASSERT_EQUALS(0, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());

	TestFailure* failure = (TestFailure*)result.failures().front();
	TEST_ASSERT_EQUALS("fail", failure->what());
}

void TestCaseTest::testIntEqualsSuccess()
{
	TEST_ASSERT_EQUALS(0, 0);
	TEST_ASSERT_EQUALS(12, 12);
	TEST_ASSERT_EQUALS(INT_MIN, INT_MIN);
	TEST_ASSERT_EQUALS(INT_MAX, INT_MAX);
}

void TestCaseTest::IntEqualsFailureTestCase::runTest()
{
	int n = 12;
	TEST_ASSERT_EQUALS(12, ++n);
}

void TestCaseTest::testIntEqualsFailure()
{
	IntEqualsFailureTestCase testCase("IntEqualsFailureTestCase");
	TestResult result;
	testCase.run(&result);
	TEST_ASSERT(testCase.wasSetUp);
	TEST_ASSERT(testCase.wasTornDown);
	TEST_ASSERT_EQUALS(1, result.runCount());
	TEST_ASSERT_EQUALS(1, result.failureCount());
	TEST_ASSERT_EQUALS(0, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());

	TestFailure* failure = (TestFailure*)result.failures().front();
	TEST_ASSERT_EQUALS("expected:<12> but was:<13>", failure->what());
}

void TestCaseTest::testLongEqualsSuccess()
{
	TEST_ASSERT_EQUALS(0L, 0L);
	TEST_ASSERT_EQUALS(12L, 12L);
	TEST_ASSERT_EQUALS(LONG_MIN, LONG_MIN);
	TEST_ASSERT_EQUALS(LONG_MAX, LONG_MAX);
}

void TestCaseTest::LongEqualsFailureTestCase::runTest()
{
	long n = 12L;
	TEST_ASSERT_EQUALS(12L, ++n);
}

void TestCaseTest::testLongEqualsFailure()
{
	LongEqualsFailureTestCase testCase("LongEqualsFailureTestCase");
	TestResult result;
	testCase.run(&result);
	TEST_ASSERT(testCase.wasSetUp);
	TEST_ASSERT(testCase.wasTornDown);
	TEST_ASSERT_EQUALS(1, result.runCount());
	TEST_ASSERT_EQUALS(1, result.failureCount());
	TEST_ASSERT_EQUALS(0, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());

	TestFailure* failure = (TestFailure*)result.failures().front();
	TEST_ASSERT_EQUALS("expected:<12> but was:<13>", failure->what());
}

void TestCaseTest::testDoubleEqualsSuccess()
{
	TEST_ASSERT_EQUALS(0.0, 0.0);
	TEST_ASSERT_EQUALS(1.2, 1.2);
	TEST_ASSERT_EQUALS_DOUBLE(1.0, 1.02, 0.3);
	TEST_ASSERT_EQUALS(DBL_EPSILON, DBL_EPSILON);
	TEST_ASSERT_EQUALS(DBL_MIN, DBL_MIN);
	TEST_ASSERT_EQUALS(DBL_MAX, DBL_MAX);
	TEST_ASSERT_EQUALS(HUGE_VAL, HUGE_VAL);
}

void TestCaseTest::DoubleEqualsFailureTestCase::runTest()
{
	double x = 1.23456789012345;
	TEST_ASSERT_EQUALS_DOUBLE(1.2, x *= 1e+36, 0.1);
}

void TestCaseTest::testDoubleEqualsFailure()
{
	DoubleEqualsFailureTestCase testCase("DoubleEqualsFailureTestCase");
	TestResult result;
	testCase.run(&result);
	TEST_ASSERT(testCase.wasSetUp);
	TEST_ASSERT(testCase.wasTornDown);
	TEST_ASSERT_EQUALS(1, result.runCount());
	TEST_ASSERT_EQUALS(1, result.failureCount());
	TEST_ASSERT_EQUALS(0, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());

	TestFailure* failure = (TestFailure*)result.failures().front();
#if defined(_MSC_VER)
	const char* expected = "expected:<1.2> but was:<1.23456789012345e+036>";
	TEST_ASSERT_EQUALS(expected, failure->what());
#elif defined(__BORLANDC__) || (__GNUC__)
	const char* expected = "expected:<1.2> but was:<1.23456789012345e+36>";
	TEST_ASSERT_EQUALS(expected, failure->what());
#else
	const char* expected = "expected:<1.2> but was:<1.23456789";
	cu_String what(failure->what());
	TEST_ASSERT_EQUALS(expected, what.substr(0, strlen(expected)));
#endif
}

void TestCaseTest::testStringEqualsSuccess()
{
	const char* s1 = "abc";
	cu_String   s2 = "xyz";
	TEST_ASSERT_EQUALS((char*)0, (char*)0);
	TEST_ASSERT_EQUALS("abc", s1);
	TEST_ASSERT_EQUALS(cu_String("abc"), s1);
	TEST_ASSERT_EQUALS("xyz", s2);
	TEST_ASSERT_EQUALS(cu_String("xyz"), s2);
}

void TestCaseTest::StringEqualsFailureTestCase::runTest()
{
	const char* s = "abcd";
	TEST_ASSERT_EQUALS("abc", s);
}

void TestCaseTest::testStringEqualsFailure()
{
	StringEqualsFailureTestCase testCase("StringEqualsFailureTestCase");
	TestResult result;
	testCase.run(&result);
	TEST_ASSERT(testCase.wasSetUp);
	TEST_ASSERT(testCase.wasTornDown);
	TEST_ASSERT_EQUALS(1, result.runCount());
	TEST_ASSERT_EQUALS(1, result.failureCount());
	TEST_ASSERT_EQUALS(0, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());

	TestFailure* failure = (TestFailure*)result.failures().front();
	TEST_ASSERT_EQUALS("expected:<abc> but was:<abcd>", failure->what());
}

void TestCaseTest::StringEqualsFailureTestCase2::runTest()
{
	TEST_ASSERT_EQUALS("abc", 0);
}

void TestCaseTest::testStringEqualsFailure2()
{
	StringEqualsFailureTestCase2 testCase("StringEqualsFailureTestCase2");
	TestResult result;
	testCase.run(&result);
	TEST_ASSERT(testCase.wasSetUp);
	TEST_ASSERT(testCase.wasTornDown);
	TEST_ASSERT_EQUALS(1, result.runCount());
	TEST_ASSERT_EQUALS(1, result.failureCount());
	TEST_ASSERT_EQUALS(0, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());

	TestFailure* failure = (TestFailure*)result.failures().front();
	TEST_ASSERT_EQUALS("expected:<abc> but was:<(null)>", failure->what());
}

void TestCaseTest::StringEqualsFailureTestCase3::runTest()
{
	cu_String s = "xy";
	TEST_ASSERT_EQUALS("xy", s += 'z');
}

void TestCaseTest::testStringEqualsFailure3()
{
	StringEqualsFailureTestCase3 testCase("StringEqualsFailureTestCase3");
	TestResult result;
	testCase.run(&result);
	TEST_ASSERT(testCase.wasSetUp);
	TEST_ASSERT(testCase.wasTornDown);
	TEST_ASSERT_EQUALS(1, result.runCount());
	TEST_ASSERT_EQUALS(1, result.failureCount());
	TEST_ASSERT_EQUALS(0, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());

	TestFailure* failure = (TestFailure*)result.failures().front();
	TEST_ASSERT_EQUALS("expected:<xy> but was:<xyz>", failure->what());
}

void TestCaseTest::testFail()
{
	FailTestCase testCase("FailTestCase");
	TestResult result;
	testCase.run(&result);
	TEST_ASSERT(testCase.wasSetUp);
	TEST_ASSERT(testCase.wasTornDown);
	TEST_ASSERT_EQUALS(1, result.runCount());
	TEST_ASSERT_EQUALS(1, result.failureCount());
	TEST_ASSERT_EQUALS(0, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());

	TestFailure* failure = (TestFailure*)result.failures().front();
	TEST_ASSERT_EQUALS("fail", failure->what());
}

void TestCaseTest::testSetUpError()
{
	SetUpErrorTestCase testCase("SetUpErrorTestCase");
	TestResult result;
	testCase.run(&result);
	TEST_ASSERT(!testCase.wasSetUp);
	TEST_ASSERT(!testCase.wasTornDown);
	TEST_ASSERT_EQUALS(1, result.runCount());
	TEST_ASSERT_EQUALS(0, result.failureCount());
	TEST_ASSERT_EQUALS(1, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());

	TestFailure* error = (TestFailure*)result.errors().front();
	TEST_ASSERT_EQUALS("setup error", error->what());
}

void TestCaseTest::testTearDownError()
{
	TearDownErrorTestCase testCase("TearDownErrorTestCase");
	TestResult result;
	testCase.run(&result);
	TEST_ASSERT(testCase.wasSetUp);
	TEST_ASSERT(!testCase.wasTornDown);
	TEST_ASSERT_EQUALS(1, result.runCount());
	TEST_ASSERT_EQUALS(1, result.failureCount());
	TEST_ASSERT_EQUALS(1, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());

	TestFailure* error = (TestFailure*)result.errors().front();
	TEST_ASSERT_EQUALS("tear down error", error->what());
}

#ifndef cu_NO_EXCEPTIONS
void TestCaseTest::testException()
{
	ExceptionTestCase testCase("ExceptionTestCase");
	TestResult result;
	testCase.run(&result);
	TEST_ASSERT(testCase.wasSetUp);
	TEST_ASSERT(testCase.wasTornDown);
	TEST_ASSERT_EQUALS(1, result.runCount());
	TEST_ASSERT_EQUALS(0, result.failureCount());
	TEST_ASSERT_EQUALS(1, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());
}
#endif

DECLARE_TEST_CALLER(TestCaseTest)

Test* TestCaseTest::suite()
{
	TestSuite* suite = new TestSuite("TestCaseTest");
	suite->addTest(new TEST_CALLER(TestCaseTest, testSuccess));
	suite->addTest(new TEST_CALLER(TestCaseTest, testFailure));
	suite->addTest(new TEST_CALLER(TestCaseTest, testAssertMessage));
	suite->addTest(new TEST_CALLER(TestCaseTest, testIntEqualsSuccess));
	suite->addTest(new TEST_CALLER(TestCaseTest, testIntEqualsFailure));
	suite->addTest(new TEST_CALLER(TestCaseTest, testLongEqualsSuccess));
	suite->addTest(new TEST_CALLER(TestCaseTest, testLongEqualsFailure));
	suite->addTest(new TEST_CALLER(TestCaseTest, testDoubleEqualsSuccess));
	suite->addTest(new TEST_CALLER(TestCaseTest, testDoubleEqualsFailure));
	suite->addTest(new TEST_CALLER(TestCaseTest, testStringEqualsSuccess));
	suite->addTest(new TEST_CALLER(TestCaseTest, testStringEqualsFailure));
	suite->addTest(new TEST_CALLER(TestCaseTest, testStringEqualsFailure2));
	suite->addTest(new TEST_CALLER(TestCaseTest, testStringEqualsFailure3));
	suite->addTest(new TEST_CALLER(TestCaseTest, testFail));
	suite->addTest(new TEST_CALLER(TestCaseTest, testSetUpError));
	suite->addTest(new TEST_CALLER(TestCaseTest, testTearDownError));
#ifndef cu_NO_EXCEPTIONS
	suite->addTest(new TEST_CALLER(TestCaseTest, testException));
#endif
	return suite;
}
