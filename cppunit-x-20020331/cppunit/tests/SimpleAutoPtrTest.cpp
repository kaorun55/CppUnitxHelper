/*
 * SimpleAutoPtrTest.cpp
 */

#include <cppunit/cudebug.h>
#include "SimpleAutoPtrTest.h"
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

USING_NAMESPACE_CPPUNIT

SimpleAutoPtrTest::Object::Object(SimpleAutoPtrTest* test, int id)
	: m_test(test), m_id(id)
{
	test->addObject(this);
}

SimpleAutoPtrTest::Object::~Object()
{
	m_test->removeObject(this);
}

void SimpleAutoPtrTest::setUp()
{
	m_objects.clear();
}

void SimpleAutoPtrTest::addObject(const Object* object)
{
	m_objects.push_back((void*)object);
}

void SimpleAutoPtrTest::removeObject(const Object* object)
{
	m_objects.remove((void*)object);
}

void SimpleAutoPtrTest::testDestroy()
{
	TEST_ASSERT_EQUALS(0, m_objects.size());
	do {
		ObjectAutoPtr ap(new Object(this));
		TEST_ASSERT_EQUALS(1, m_objects.size());
		TEST_ASSERT(ap.get() == m_objects.front());
		TEST_ASSERT((*ap).getTest() == this);
		TEST_ASSERT_EQUALS(0, ap->getID());
	} while (0);
	TEST_ASSERT_EQUALS(0, m_objects.size());
}

void SimpleAutoPtrTest::testRelease()
{
	TEST_ASSERT_EQUALS(0, m_objects.size());
	ObjectAutoPtr ap(new Object(this, 1));
	TEST_ASSERT_EQUALS(1, m_objects.size());
	TEST_ASSERT(ap.get() == m_objects.front());
	TEST_ASSERT((*ap).getTest() == this);
	TEST_ASSERT_EQUALS(1, ap->getID());

	ObjectAutoPtr ap2(ap.release());
	TEST_ASSERT_EQUALS(1, m_objects.size());
	TEST_ASSERT(ap.get() == 0);
	TEST_ASSERT(ap2.get() == m_objects.front());
	TEST_ASSERT((*ap2).getTest() == this);
	TEST_ASSERT_EQUALS(1, ap2->getID());
}

void SimpleAutoPtrTest::testReset()
{
	TEST_ASSERT_EQUALS(0, m_objects.size());
	ObjectAutoPtr ap(new Object(this, 1));
	TEST_ASSERT_EQUALS(1, m_objects.size());
	TEST_ASSERT(ap.get() == m_objects.front());
	TEST_ASSERT((*ap).getTest() == this);
	TEST_ASSERT_EQUALS(1, ap->getID());

	ap.reset(new Object(this, 2));
	TEST_ASSERT_EQUALS(1, m_objects.size());
	TEST_ASSERT(ap.get() == m_objects.front());
	TEST_ASSERT((*ap).getTest() == this);
	TEST_ASSERT_EQUALS(2, ap->getID());

	ap.reset();
	TEST_ASSERT_EQUALS(0, m_objects.size());
	TEST_ASSERT(ap.get() == 0);
}

DECLARE_TEST_CALLER(SimpleAutoPtrTest)

Test* SimpleAutoPtrTest::suite()
{
	TestSuite* suite = new TestSuite("SimpleAutoPtrTest");
	suite->addTest(new TEST_CALLER(SimpleAutoPtrTest, testDestroy));
	suite->addTest(new TEST_CALLER(SimpleAutoPtrTest, testRelease));
	suite->addTest(new TEST_CALLER(SimpleAutoPtrTest, testReset));
	return suite;
}
