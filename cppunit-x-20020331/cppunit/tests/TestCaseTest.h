/*
 * TestCaseTest.h
 */

#ifndef cppunit_tests_TestCaseTest_h
#define cppunit_tests_TestCaseTest_h

#include <cppunit/TestCase.h>

#ifndef cu_NO_EXCEPTIONS
#  include <stdexcept>
#endif

USING_NAMESPACE_CPPUNIT

class TestCaseTest : public TestCase
{
  public:
	explicit TestCaseTest(const char* name) : TestCase(name) {}
	void testSuccess();
	void testFailure();
	void testAssertMessage();
	void testIntEqualsSuccess();
	void testIntEqualsFailure();
	void testLongEqualsSuccess();
	void testLongEqualsFailure();
	void testDoubleEqualsSuccess();
	void testDoubleEqualsFailure();
	void testStringEqualsSuccess();
	void testStringEqualsFailure();
	void testStringEqualsFailure2();	// actual == 0
	void testStringEqualsFailure3();	// string&
	void testFail();
	void testSetUpError();
	void testTearDownError();
#ifndef cu_NO_EXCEPTIONS
	void testException();
#endif
	static Test* suite();

  public:
	class TestTestCase : public TestCase {
	  public:
		explicit TestTestCase(const char* name)
			: TestCase(name), wasSetUp(false), wasTornDown(false) {}
		virtual void setUp()    { wasSetUp    = true; }
		virtual void tearDown() { wasTornDown = true; }
		bool wasSetUp, wasTornDown;
	};

	class SuccessTestCase : public TestTestCase {
	  public:
		explicit SuccessTestCase(const char* name) : TestTestCase(name) {}
		virtual void runTest() { TEST_ASSERT(true); }
	};

	class FailureTestCase : public TestTestCase {
	  public:
		explicit FailureTestCase(const char* name) : TestTestCase(name) {}
		virtual void runTest() { TEST_ASSERT(false); }
	};

	class MessageTestCase : public TestTestCase {
	  public:
		explicit MessageTestCase(const char* name) : TestTestCase(name) {}
		virtual void runTest() { TEST_ASSERT_MESSAGE(false, "fail"); }
	};

	class IntEqualsFailureTestCase : public TestTestCase {
	  public:
		explicit IntEqualsFailureTestCase(const char* name)
			: TestTestCase(name) {}
		virtual void runTest();
	};

	class LongEqualsFailureTestCase : public TestTestCase {
	  public:
		explicit LongEqualsFailureTestCase(const char* name)
			: TestTestCase(name) {}
		virtual void runTest();
	};

	class DoubleEqualsFailureTestCase : public TestTestCase {
	  public:
		explicit DoubleEqualsFailureTestCase(const char* name)
			: TestTestCase(name) {}
		virtual void runTest();
	};

	class StringEqualsFailureTestCase : public TestTestCase {
	  public:
		explicit StringEqualsFailureTestCase(const char* name)
			: TestTestCase(name) {}
		virtual void runTest();
	};

	class StringEqualsFailureTestCase2 : public TestTestCase {
	  public:
		explicit StringEqualsFailureTestCase2(const char* name)
			: TestTestCase(name) {}
		virtual void runTest();
	};

	class StringEqualsFailureTestCase3 : public TestTestCase {
	  public:
		explicit StringEqualsFailureTestCase3(const char* name)
			: TestTestCase(name) {}
		virtual void runTest();
	};

	class FailTestCase : public TestTestCase {
	  public:
		explicit FailTestCase(const char* name) : TestTestCase(name) {}
		virtual void runTest() { TEST_FAIL("fail"); }
	};

	class SetUpErrorTestCase : public TestTestCase {
	  public:
		explicit SetUpErrorTestCase(const char* name) : TestTestCase(name) {}
		virtual void setUp() { TEST_ERROR("setup error"); }
		virtual void runTest() {}
	};

	class TearDownErrorTestCase : public TestTestCase {
	  public:
		explicit TearDownErrorTestCase(const char* name) : TestTestCase(name) {}
		virtual void runTest() { TEST_FAIL("fail"); }
		virtual void tearDown() { TEST_ERROR("tear down error"); }
	};

#ifndef cu_NO_EXCEPTIONS
	class ExceptionTestCase : public TestTestCase {
	  public:
		explicit ExceptionTestCase(const char* name) : TestTestCase(name) {}
		virtual void runTest() { throw cu_STD::logic_error("logic error"); }
	};
#endif
};

#endif /* !cppunit_tests_TestCaseTest_h */
