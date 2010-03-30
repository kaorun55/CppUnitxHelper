/*
 * TestSuite.cpp
 */

#include "cuconfig.h"
#include "cudebug.h"
#include "TestSuite.h"
#include "TestResult.h"

cu_NAMESPACE_BEGIN(cppunit)

TestSuite::TestSuite(const char* name)
	: m_name(name)
{
}

TestSuite::~TestSuite()
{
	for (cu_List::iterator p = m_tests.begin(); p != m_tests.end(); ++p) {
		delete (Test*)*p;
	}
}

void TestSuite::run(TestResult* result)
{
	for (cu_List::iterator p = m_tests.begin(); p != m_tests.end(); ++p) {
		if (result->shouldStop()) break;
		((Test*)(*p))->run(result);
	}
}

int TestSuite::countTestCases() const
{
	int count = 0;
	for (cu_List::const_iterator p = m_tests.begin(); p != m_tests.end(); ++p) {
		count += ((Test*)(*p))->countTestCases();
	}
	return count;
}

const char* TestSuite::getName() const
{
	return m_name.c_str();
}

cu_String TestSuite::toString() const
{
	return "suite " + m_name;
}

void TestSuite::addTest(Test* test)
{
	m_tests.push_back(test);
}

cu_NAMESPACE_END
