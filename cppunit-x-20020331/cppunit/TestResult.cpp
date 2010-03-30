/*
 * TestResult.cpp
 */

#include "cuconfig.h"
#include "cudebug.h"
#include "TestResult.h"
#include "TestFailure.h"
#include "TestListener.h"
#include "Test.h" /* for LynxOS */

cu_NAMESPACE_BEGIN(cppunit)

void TestResult::Mutex::lock()   { /* cu_TRACE("lock!!\n");   */ }
void TestResult::Mutex::unlock() { /* cu_TRACE("unlock!!\n"); */ }

TestResult::TestResult(Mutex* mutex)
	: m_mutex(mutex), m_runCount(0), m_shouldStop(false)
{
	if (mutex == 0) m_mutex = new Mutex();
}

TestResult::~TestResult()
{
	cu_List::iterator p;
	for (p = m_failures.begin(); p != m_failures.end(); ++p) {
		delete (TestFailure*)*p;
	}
	for (p = m_errors.begin(); p != m_errors.end(); ++p) {
		delete (TestFailure*)*p;
	}
	delete m_mutex;
}

void TestResult::addListener(TestListener* listener)
{
	m_listeners.push_back(listener);
}

void TestResult::startTest(Test* test)
{
	do {
		AutoMutexLock lock(m_mutex);
		++m_runCount;
	} while (0);
	for (cu_List::iterator p = m_listeners.begin();
			p != m_listeners.end(); ++p) {
		((TestListener*)(*p))->startTest(test);
	}
}

void TestResult::endTest(Test* test)
{
	for (cu_List::iterator p = m_listeners.begin();
			p != m_listeners.end(); ++p) {
		((TestListener*)(*p))->endTest(test);
	}
}

void TestResult::addFailure(const TestFailure* failure)
{
	do {
		AutoMutexLock lock(m_mutex);
		m_failures.push_back(new TestFailure(*failure));
	} while (0);
	for (cu_List::iterator p = m_listeners.begin();
			p != m_listeners.end(); ++p) {
		((TestListener*)(*p))->addFailure(failure);
	}
}

void TestResult::addError(const TestFailure* error)
{
	do {
		AutoMutexLock lock(m_mutex);
		m_errors.push_back(new TestFailure(*error));
	} while (0);
	for (cu_List::iterator p = m_listeners.begin();
			p != m_listeners.end(); ++p) {
		((TestListener*)(*p))->addError(error);
	}
}

int TestResult::runCount() const
{
	AutoMutexLock lock(m_mutex);
	return m_runCount;
}

int TestResult::failureCount() const
{
	AutoMutexLock lock(m_mutex);
	return m_failures.size();
}

int TestResult::errorCount() const
{
	AutoMutexLock lock(m_mutex);
	return m_errors.size();
}

bool TestResult::wasSuccessful() const
{
	AutoMutexLock lock(m_mutex);
	return (m_failures.size() == 0 && m_errors.size() == 0);
}

bool TestResult::shouldStop() const
{
	AutoMutexLock lock(m_mutex);
	return m_shouldStop;
}

void TestResult::stop()
{
	AutoMutexLock lock(m_mutex);
	m_shouldStop = true;
}

cu_NAMESPACE_END
