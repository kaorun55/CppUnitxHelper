/*
 * TestRegistry.cpp
 */

#include "cuconfig.h"
#include "cudebug.h"
#include "TestRegistry.h"
#include "TestResult.h"
#include <string.h>

cu_NAMESPACE_BEGIN(cppunit)

TestRegistry::~TestRegistry()
{
	for (cu_List::iterator p = m_entries.begin(); p != m_entries.end(); ++p) {
		delete (Entry*)*p;
	}
}

void TestRegistry::addTest(const char* name, Test* test)
{
	m_entries.push_back(new Entry(name, test));
}

bool TestRegistry::setAvailable(const char* name, bool value)
{
	bool result = false;
	for (cu_List::iterator p = m_entries.begin(); p != m_entries.end(); ++p) {
		Entry* entry = (Entry*)*p;
		if (strcmp(entry->getName(), name) == 0) {
			result = true;
			entry->setAvailable(value);
		}
	}
	return result;
}

void TestRegistry::setAllAvailable(bool value)
{
	for (cu_List::iterator p = m_entries.begin(); p != m_entries.end(); ++p) {
		((Entry*)*p)->setAvailable(value);
	}
}

bool TestRegistry::hasAvailables() const
{
	for (cu_List::const_iterator p = m_entries.begin();
			p != m_entries.end(); ++p) {
		if (((Entry*)*p)->isAvailable()) return true;
	}
	return false;
}

void TestRegistry::runTests(TestResult* result)
{
	for (cu_List::iterator p = m_entries.begin(); p != m_entries.end(); ++p) {
		Entry* entry = (Entry*)*p;
		if (entry->isAvailable()) {
			entry->getTest()->run(result);
			if (result->shouldStop()) break;
		}
	}
}

cu_NAMESPACE_END
