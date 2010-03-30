/*
 * TestFailure.cpp
 */

#include "cuconfig.h"
#include "cudebug.h"
#include "TestFailure.h"
#include "Test.h"

cu_NAMESPACE_BEGIN(cppunit)

TestFailure::TestFailure(
		Test* test, const cu_String& msg, const char* file, long line)
	: m_failedTest(test), m_message(msg), m_file(file), m_line(line)
{
}

cu_String TestFailure::toString() const
{
	return m_failedTest->toString() + ": " + m_message;
}

cu_NAMESPACE_END
