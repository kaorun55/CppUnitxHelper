/*
 * TestCallerTest.h
 */

#ifndef cppunit_tests_TestCallerTest_h
#define cppunit_tests_TestCallerTest_h

#include <cppunit/TestCase.h>

USING_NAMESPACE_CPPUNIT

class TestCallerTest : public TestCase
{
  public:
	explicit TestCallerTest(const char* name) : TestCase(name) {}
	virtual void runTest();
	static Test* suite() { return new TestCallerTest("TestCallerTest"); }

  public:
	class TestCallerTestCase : public TestCase {
	  public:
		explicit TestCallerTestCase(const char* name) : TestCase(name),
				wasSetUp(false), wasTornDown(false), wasRun(false) {}
		virtual void setUp() { wasSetUp = true; }
		virtual void tearDown() { wasTornDown = true; TEST_ERROR("error"); }
		void testRun() { wasRun = true; TEST_FAIL("fail"); }
		bool wasSetUp, wasTornDown, wasRun;
	};
};

#endif /* !cppunit_tests_TestCallerTest_h */
