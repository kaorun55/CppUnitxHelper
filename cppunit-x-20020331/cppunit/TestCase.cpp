/*
 * TestCase.cpp
 */

#include "cuconfig.h"
#include "cudebug.h"
#include "TestCase.h"
#include "TestResult.h"
#include "TestFailure.h"
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#ifndef cu_NO_EXCEPTIONS
#  include <exception>
#  ifndef cu_NO_RTTI
#    include <typeinfo>
#  endif
#endif

cu_NAMESPACE_BEGIN(cppunit)

TestCase::TestCase(const char* name)
	: m_name(name), m_hasError(false)
{
}

TestCase::~TestCase()
{
}

void TestCase::run(TestResult* result)
{
	startTest(result);
	cu_TRY {
		runBare();
#ifndef cu_NO_EXCEPTIONS
	} catch (cu_STD::exception& e) {
#  ifndef cu_NO_RTTI
		cu_String msg(typeid(e).name()); msg += ": ";
#  else
		cu_String msg("exception: ");
#  endif
		msg += e.what();
		addError(msg, __FILE__, __LINE__);
	} catch (...) {
		addError("unknown exception", __FILE__, __LINE__);
#endif /* !cu_NO_EXCEPTIONS */
	}
	endTest(result);
}

int TestCase::countTestCases() const
{
	return 1;
}

const char* TestCase::getName() const
{
	return m_name.c_str();
}

cu_String TestCase::toString() const
{
	return m_name;
}

void TestCase::startTest(TestResult* result)
{
	m_hasError = false;
	m_result = result;
	result->startTest(this);
}

void TestCase::endTest(TestResult* result)
{
	result->endTest(this);
	m_result = 0;
}

void TestCase::runBare()
{
	setUp();
	if (m_hasError) return;
	cu_TRY {
		runTest();
	} cu_CATCH_ALL {
		tearDown();
		cu_RETHROW;
	}
	tearDown();
}

void TestCase::addFailure(const cu_String& msg, const char* file, long line)
{
	TestFailure failure(this, msg, file, line);
	m_result->addFailure(&failure);
	m_hasError = true;
}

void TestCase::addError(const cu_String& msg, const char* file, long line)
{
	TestFailure error(this, msg, file, line);
	m_result->addError(&error);
	m_hasError = true;
}

bool TestCase::assertEqualsImpl(
		int expected, int actual, const char* file, long line)
{
	if (expected == actual) return true;
	addFailure(notEqualsMessage(expected, actual), file, line);
	return false;
}

bool TestCase::assertEqualsImpl(
		long expected, long actual, const char* file, long line)
{
	if (expected == actual) return true;
	addFailure(notEqualsMessage(expected, actual), file, line);
	return false;
}

bool TestCase::assertEqualsImpl(double expected, double actual,
		const char* file, long line, double delta)
{
	if (equals(expected, actual, delta)) return true;
	addFailure(notEqualsMessage(expected, actual), file, line);
	return false;
}

bool TestCase::assertEqualsImpl(const char* expected, const char* actual,
		const char* file, long line)
{
	if (equals(expected, actual)) return true;
	addFailure(notEqualsMessage(expected, actual), file, line);
	return false;
}

bool TestCase::equals(double x1, double x2, double delta)
{
	// HUGE_VAL ëŒçÙÅB
	if (x1 == x2) return true;
	return (fabs(x1 - x2) <= delta);
}

bool TestCase::equals(const char* s1, const char* s2)
{
	if (s1 == s2) return true;
	if (s1 == 0 || s2 == 0) return false;
	return (strcmp(s1, s2) == 0);
}

cu_String TestCase::notEqualsMessage(int expected, int actual)
{
	char buf[80];
	sprintf(buf, "expected:<%d> but was:<%d>", expected, actual);
	return cu_String(buf);
}

cu_String TestCase::notEqualsMessage(long expected, long actual)
{
	char buf[80];
	sprintf(buf, "expected:<%ld> but was:<%ld>", expected, actual);
	return cu_String(buf);
}

#define cu_DOUBLE_FORMAT "<%." cu_TEXT(DBL_DIG) "g>"

cu_String TestCase::notEqualsMessage(double expected, double actual)
{
	char buf[80];
	sprintf(buf, "expected:" cu_DOUBLE_FORMAT
			" but was:" cu_DOUBLE_FORMAT, expected, actual);
	return cu_String(buf);
}

cu_String TestCase::notEqualsMessage(const char* expected, const char* actual)
{
#if defined(TEST_MAX_STRLEN) && TEST_MAX_STRLEN > 3
	const size_t MAX_STRLEN = TEST_MAX_STRLEN;
#else
	const size_t MAX_STRLEN = 0;
#endif
	cu_String result("expected:<");
	if (expected == 0) {
		result.append("(null)>");
	} else if (MAX_STRLEN == 0 || strlen(expected) <= MAX_STRLEN) {
		result.append(expected).append(">");
	} else {
		result.append(expected, MAX_STRLEN - 3).append("...>");
	}
	result.append(" but was:<");
	if (actual == 0) {
		result.append("(null)>");
	} else if (MAX_STRLEN == 0 || strlen(actual) <= MAX_STRLEN) {
		result.append(actual).append(">");
	} else {
		result.append(actual, MAX_STRLEN - 3).append("...>");
	}
	return result;
}

cu_NAMESPACE_END
