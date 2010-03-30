/*
 * TestSetup.cpp
 */

#include "cuconfig.h"
#include "cudebug.h"
#include "TestSetup.h"
#include "TestResult.h"
#include "TestFailure.h"

#ifndef cu_NO_EXCEPTIONS
#  include <exception>
#  ifndef cu_NO_RTTI
#    include <typeinfo>
#  endif
#endif

cu_NAMESPACE_BEGIN(cppunit)

TestSetup::TestSetup(Test* test)
	: TestDecorator(test), m_hasError(false)
{
}

void TestSetup::run(TestResult* result)
{
	m_hasError = false;
	m_result = result;
	cu_TRY {
		runBare();
#ifndef cu_NO_EXCEPTIONS
	} catch (cu_STD::exception& e) {
#ifndef cu_NO_RTTI
		cu_String msg(typeid(e).name()); msg += ": ";
#else
		cu_String msg("exception: ");
#endif
		msg += e.what();
		addError(msg, __FILE__, __LINE__);
	} catch (...) {
		addError("unknown exception", __FILE__, __LINE__);
#endif /* !cu_NO_EXCEPTIONS */
	}
	m_result = 0;
}

void TestSetup::runBare()
{
	setUp();
	if (m_hasError) return;
	TestDecorator::run(m_result);
	tearDown();
}

void TestSetup::addError(const cu_String& msg, const char* file, long line)
{
	TestFailure error(this, msg, file, line);
	m_result->addError(&error);
	m_hasError = true;
}

cu_NAMESPACE_END
