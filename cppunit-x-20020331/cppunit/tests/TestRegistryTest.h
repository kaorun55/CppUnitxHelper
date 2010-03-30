/*
 * TestRegistryTest.h
 */

#ifndef cppunit_tests_TestRegistryTest_h
#define cppunit_tests_TestRegistryTest_h

#include <cppunit/TestCase.h>
#include <cppunit/TestRegistry.h>

USING_NAMESPACE_CPPUNIT

class TestRegistryTest : public TestCase
{
  public:
	explicit TestRegistryTest(const char* name)
		: TestCase(name), m_registry(0) {}
	virtual void setUp();
	virtual void tearDown();
	void testRunTests();
	void testRunAllTests();
	static Test* suite();

  private:
	TestRegistry* m_registry;
};

#endif /* !cppunit_tests_TestRegistryTest_h */
