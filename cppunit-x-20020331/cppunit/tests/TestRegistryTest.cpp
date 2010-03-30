/*
 * TestRegistryTest.cpp
 */

#include <cppunit/cudebug.h>
#include "TestRegistryTest.h"
#include "TestCaseTest.h"
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestResult.h>

USING_NAMESPACE_CPPUNIT

void TestRegistryTest::setUp()
{
	m_registry = new TestRegistry();
	m_registry->addTest("SuccessTest",
			new TestCaseTest::SuccessTestCase("SuccessTestCase"));
	m_registry->addTest("FailureTest",
			new TestCaseTest::FailureTestCase("FailureTestCase"));
	m_registry->addTest("FailureTest",
			new TestCaseTest::FailTestCase("FailTestCase"));
}

void TestRegistryTest::tearDown()
{
	delete m_registry;
	m_registry = 0;
}

void TestRegistryTest::testRunTests()
{
	TEST_ASSERT(!m_registry->hasAvailables());
	TEST_ASSERT_EQUALS(3, m_registry->entries().size());

	bool found = m_registry->setAvailable("a");
	TEST_ASSERT(!found);
	TEST_ASSERT(!m_registry->hasAvailables());

	found = m_registry->setAvailable("FailureTest");
	TEST_ASSERT(found);
	TEST_ASSERT(m_registry->hasAvailables());
	cu_List::const_iterator p = m_registry->entries().begin();
	TEST_ASSERT(!((TestRegistry::Entry*)*p)->isAvailable());
	++p;
	TEST_ASSERT(((TestRegistry::Entry*)*p)->isAvailable());
	++p;
	TEST_ASSERT(((TestRegistry::Entry*)*p)->isAvailable());

	TestResult result;
	m_registry->runTests(&result);
	TEST_ASSERT_EQUALS(2, result.runCount());
	TEST_ASSERT_EQUALS(2, result.failureCount());
	TEST_ASSERT_EQUALS(0, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());

	found = m_registry->setAvailable("FailureTest", false);
	TEST_ASSERT(found);
	TEST_ASSERT(!m_registry->hasAvailables());
}

void TestRegistryTest::testRunAllTests()
{
	TEST_ASSERT(!m_registry->hasAvailables());
	TEST_ASSERT_EQUALS(3, m_registry->entries().size());

	m_registry->setAllAvailable();
	TEST_ASSERT(m_registry->hasAvailables());
	cu_List::const_iterator p = m_registry->entries().begin();
	TEST_ASSERT(((TestRegistry::Entry*)*p)->isAvailable());
	++p;
	TEST_ASSERT(((TestRegistry::Entry*)*p)->isAvailable());
	++p;
	TEST_ASSERT(((TestRegistry::Entry*)*p)->isAvailable());

	TestResult result;
	m_registry->runTests(&result);
	TEST_ASSERT_EQUALS(3, result.runCount());
	TEST_ASSERT_EQUALS(2, result.failureCount());
	TEST_ASSERT_EQUALS(0, result.errorCount());
	TEST_ASSERT(!result.wasSuccessful());

	m_registry->setAllAvailable(false);
	TEST_ASSERT(!m_registry->hasAvailables());
}

DECLARE_TEST_CALLER(TestRegistryTest)

Test* TestRegistryTest::suite()
{
	TestSuite* suite = new TestSuite("TestRegistryTest");
	suite->addTest(new TEST_CALLER(TestRegistryTest, testRunTests));
	suite->addTest(new TEST_CALLER(TestRegistryTest, testRunAllTests));
	return suite;
}
