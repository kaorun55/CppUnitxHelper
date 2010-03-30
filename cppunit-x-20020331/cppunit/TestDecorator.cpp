/*
 * TestDecorator.cpp
 */

#include "cuconfig.h"
#include "cudebug.h"
#include "TestDecorator.h"

cu_NAMESPACE_BEGIN(cppunit)

TestDecorator::TestDecorator(Test* test)
	: m_test(test)
{
}

TestDecorator::~TestDecorator()
{
	delete m_test;
}

void TestDecorator::run(TestResult* result)
{
	m_test->run(result);
}

int TestDecorator::countTestCases() const
{
	return m_test->countTestCases();
}

const char* TestDecorator::getName() const
{
	return m_test->getName();
}

cu_String TestDecorator::toString() const
{
	return m_test->toString();
}

cu_NAMESPACE_END
