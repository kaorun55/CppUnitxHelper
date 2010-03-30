/*
 * AllTests
 */

// for Leak Check
#include <cppunit/cudebug.h>

#include "SimpleStringTest.h"
#include "SimpleListTest.h"
#include "SimpleAutoPtrTest.h"
#include "TestUtilityTest.h"
#include "TestResultTest.h"
#include "TestCaseTest.h"
#include "TestCallerTest.h"
#include "TestSuiteTest.h"
#include "TestRegistryTest.h"
#include "TestDecoratorTest.h"
#include "RepeatedTestTest.h"
#include "TestSetupTest.h"
#include "CppUnitTest.h"
#include <cppunit/TestRunner.h>

int main(int argc, char* argv[])
{
#if defined(ENABLE_LEAK_CHECKER) && !defined(_MSC_VER)
	LeakChecker checker;
#endif
	CPPUNIT::TestRunner runner;
	runner.addTest("SimpleStringTest",  SimpleStringTest::suite());
	runner.addTest("SimpleListTest",    SimpleListTest::suite());
	runner.addTest("SimpleAutoPtrTest", SimpleAutoPtrTest::suite());
	runner.addTest("TestUtilityTest",   TestUtilityTest::suite());
	runner.addTest("TestResultTest",    TestResultTest::suite());
	runner.addTest("TestCaseTest",      TestCaseTest::suite());
	runner.addTest("TestCallerTest",    TestCallerTest::suite());
	runner.addTest("TestSuiteTest",     TestSuiteTest::suite());
	runner.addTest("TestRegistryTest",  TestRegistryTest::suite());
	runner.addTest("TestDecoratorTest", TestDecoratorTest::suite());
	runner.addTest("RepeatedTestTest",  RepeatedTestTest::suite());
	runner.addTest("TestSetupTest",     TestSetupTest::suite());
	runner.addTest("CppUnitTest",       CppUnitTest::suite());
	return runner.run(argc, argv);
}

#ifdef USE_DEBUGTOOLS
#  include <debug/debugtools.cpp>
#endif

#if defined(ENABLE_LEAK_CHECKER) && defined(_MSC_VER)
#  pragma warning(disable:4073)
#  pragma init_seg(lib)
LeakChecker g_leakChecker;
#endif
