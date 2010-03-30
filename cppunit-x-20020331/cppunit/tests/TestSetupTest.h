/*
 * TestSetupTest.h
 */

#ifndef cppunit_tests_TestSetupTest_h
#define cppunit_tests_TestSetupTest_h

#include <cppunit/TestCase.h>
#include <cppunit/TestSetup.h>

USING_NAMESPACE_CPPUNIT

class TestSetupTest : public TestCase
{
  public:
	explicit TestSetupTest(const char* name) : TestCase(name) {}
	void testTestSetup();
	void testSetUpError();
	void testTearDownError();
	static Test* suite();

  public:
	class TestTestSetup : public TestSetup {
	  public:
		explicit TestTestSetup(Test* test)
			: TestSetup(test), wasSetUp(false), wasTornDown(false) {}
		virtual void setUp()    { wasSetUp    = true; }
		virtual void tearDown() { wasTornDown = true; }
		bool wasSetUp, wasTornDown;
	};

	class SetUpErrorTestSetup : public TestTestSetup {
	  public:
		explicit SetUpErrorTestSetup(Test* test) : TestTestSetup(test) {}
		virtual void setUp() { TEST_ERROR("setup error"); }
	};

	class TearDownErrorTestSetup : public TestTestSetup {
	  public:
		explicit TearDownErrorTestSetup(Test* test) : TestTestSetup(test) {}
		virtual void tearDown() { TEST_ERROR("tear down error"); }
	};
};

#endif /* !cppunit_tests_TestSetupTest_h */
