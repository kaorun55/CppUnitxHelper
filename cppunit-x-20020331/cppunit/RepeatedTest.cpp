/*
 * RepeatedTest.cpp
 */

#include "cuconfig.h"
#include "cudebug.h"
#include "RepeatedTest.h"
#include "TestResult.h"

cu_NAMESPACE_BEGIN(cppunit)

RepeatedTest::RepeatedTest(Test* test, int repeat)
	: TestDecorator(test), m_timesRepeat(repeat)
{
}

void RepeatedTest::run(TestResult* result)
{
	for (int i = 0; i < m_timesRepeat; ++i) {
		if (result->shouldStop()) break;
		TestDecorator::run(result);
	}
}

int RepeatedTest::countTestCases() const
{
	return TestDecorator::countTestCases() * m_timesRepeat;
}

cu_String RepeatedTest::toString() const
{
	return TestDecorator::toString() + " (repeated)";
}

cu_NAMESPACE_END
