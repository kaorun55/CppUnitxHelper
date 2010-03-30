/*
 * TestResultTest.cpp
 */

#include <cppunit/cudebug.h>
#include "TestResultTest.h"
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestFailure.h>

USING_NAMESPACE_CPPUNIT

void TestResultTest::setUp()
{
	m_mutex  = new TestMutex();
	m_result = new TestResult(m_mutex);
}

void TestResultTest::tearDown()
{
	delete m_result;
	m_mutex  = 0;
	m_result = 0;
}

void TestResultTest::testStartTest()
{
	TestTestListener listener;
	m_result->addListener(&listener);
	TEST_ASSERT_EQUALS(0, listener.started);
	TEST_ASSERT_EQUALS(0, m_result->runCount());

	EmptyTest test("EmptyTest");
	m_result->startTest(&test);
	TEST_ASSERT_EQUALS(1, listener.started);
	TEST_ASSERT_EQUALS(1, m_result->runCount());
}

void TestResultTest::testEndTest()
{
	TestTestListener listener;
	m_result->addListener(&listener);
	TEST_ASSERT_EQUALS(0, listener.ended);

	EmptyTest test("EmptyTest");
	m_result->endTest(&test);
	TEST_ASSERT_EQUALS(1, listener.ended);
}

void TestResultTest::testAddFailure()
{
	TestTestListener listener;
	m_result->addListener(&listener);
	TEST_ASSERT_EQUALS(0, listener.failures);
	TEST_ASSERT_EQUALS(0, m_mutex->locked);
	TEST_ASSERT_EQUALS(0, m_mutex->unlocked);
	TEST_ASSERT_EQUALS(0, m_result->failureCount());
	TEST_ASSERT(m_result->wasSuccessful());

	int locked = m_mutex->locked;
	EmptyTest test("EmptyTest");
	TestFailure failure(&test, "message", "", 0);
	m_result->addFailure(&failure);
	TEST_ASSERT_EQUALS(1, listener.failures);
	TEST_ASSERT_EQUALS(locked + 1, m_mutex->locked);
	TEST_ASSERT_EQUALS(m_mutex->locked, m_mutex->unlocked);
	TEST_ASSERT_EQUALS(1, m_result->failureCount());
	TEST_ASSERT(!m_result->wasSuccessful());

	TestFailure* entry = (TestFailure*)m_result->failures().front();
	TEST_ASSERT_EQUALS("EmptyTest", entry->failedTest()->getName());
	TEST_ASSERT_EQUALS("message", entry->what());
}

void TestResultTest::testAddError()
{
	TestTestListener listener;
	m_result->addListener(&listener);
	TEST_ASSERT_EQUALS(0, listener.errors);
	TEST_ASSERT_EQUALS(0, m_mutex->locked);
	TEST_ASSERT_EQUALS(0, m_mutex->unlocked);
	TEST_ASSERT_EQUALS(0, m_result->errorCount());
	TEST_ASSERT(m_result->wasSuccessful());

	int locked = m_mutex->locked;
	EmptyTest test("EmptyTest");
	TestFailure error(&test, "message", "", 0);
	m_result->addError(&error);
	TEST_ASSERT_EQUALS(1, listener.errors);
	TEST_ASSERT_EQUALS(locked + 1, m_mutex->locked);
	TEST_ASSERT_EQUALS(m_mutex->locked, m_mutex->unlocked);
	TEST_ASSERT_EQUALS(1, m_result->errorCount());
	TEST_ASSERT(!m_result->wasSuccessful());

	TestFailure* entry = (TestFailure*)m_result->errors().front();
	TEST_ASSERT_EQUALS("EmptyTest", entry->failedTest()->getName());
	TEST_ASSERT_EQUALS("message", entry->what());
}

void TestResultTest::testStop()
{
	TEST_ASSERT(!m_result->shouldStop());
	m_result->stop();
	TEST_ASSERT(m_result->shouldStop());
}

DECLARE_TEST_CALLER(TestResultTest)

Test* TestResultTest::suite()
{
	TestSuite* suite = new TestSuite("TestResultTest");
	suite->addTest(new TEST_CALLER(TestResultTest, testStartTest));
	suite->addTest(new TEST_CALLER(TestResultTest, testEndTest));
	suite->addTest(new TEST_CALLER(TestResultTest, testAddFailure));
	suite->addTest(new TEST_CALLER(TestResultTest, testAddError));
	suite->addTest(new TEST_CALLER(TestResultTest, testStop));
	return suite;
}
