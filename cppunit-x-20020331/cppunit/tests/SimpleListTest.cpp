/*
 * SimpleListTest.cpp
 */

#include <cppunit/cudebug.h>
#include "SimpleListTest.h"
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

USING_NAMESPACE_CPPUNIT

void SimpleListTest::setUp()
{
	const char* values[] = { "1st", "2nd", "3rd", "4th", "5th" };
	m_list.assign((void**)values, (void**)values + 5);
}

void SimpleListTest::testCreate()
{
	// SimpleList()
	SimpleList v1;
	TEST_ASSERT_EQUALS("{}", c_str(v1));
	// SimpleList(size_type, value_type)
	SimpleList v2(2, (void*)"a");
	TEST_ASSERT_EQUALS("{a, a}", c_str(v2));
	const char* values[] = { "1st", "2nd" };
	// SimpleList(const_pointer, const_pointer)
	SimpleList v3((void**)values, (void**)values + 2);
	TEST_ASSERT_EQUALS("{1st, 2nd}", c_str(v3));
	// SimpleList(const_iterator, const_iterator)
	SimpleList v4(m_list.begin(), ++(++m_list.begin()));
	TEST_ASSERT_EQUALS("{1st, 2nd}", c_str(v4));
	// SimpleList(const SimpleList&)
	SimpleList v5(m_list);
	TEST_ASSERT_EQUALS("{1st, 2nd, 3rd, 4th, 5th}", c_str(v5));
}

void SimpleListTest::testAssign()
{
	SimpleList v1;
	TEST_ASSERT_EQUALS("{}", c_str(v1));
	// assign(size_type, value_type)
	v1.assign(2, (void*)"a");
	TEST_ASSERT_EQUALS("{a, a}", c_str(v1));
	const char* ab[] = { "a", "b" };
	// assign(const_pointer, const_pointer)
	v1.assign((void**)ab, (void**)ab + 2);
	TEST_ASSERT_EQUALS("{a, b}", c_str(v1));
	// assign(const_iterator, const_iterator)
	v1.assign(m_list.begin(), ++(++m_list.begin()));
	TEST_ASSERT_EQUALS("{1st, 2nd}", c_str(v1));

	// operator=(const SimpleList&)
	v1 = m_list;
	TEST_ASSERT_EQUALS("{1st, 2nd, 3rd, 4th, 5th}", c_str(v1));
}

void SimpleListTest::testIterator()
{
	TEST_ASSERT_EQUALS("1st", c_str(*m_list.begin()));
	TEST_ASSERT_EQUALS("5th", c_str(*(--m_list.end())));
}

void SimpleListTest::testAccessor()
{
	TEST_ASSERT_EQUALS("1st", c_str(m_list.front()));
	TEST_ASSERT_EQUALS("5th", c_str(m_list.back()));
}

void SimpleListTest::testStackOperation()
{
	TEST_ASSERT_EQUALS("{1st, 2nd, 3rd, 4th, 5th}", c_str(m_list));
	m_list.push_front((void*)"a");
	TEST_ASSERT_EQUALS("{a, 1st, 2nd, 3rd, 4th, 5th}", c_str(m_list));
	m_list.pop_front();
	TEST_ASSERT_EQUALS("{1st, 2nd, 3rd, 4th, 5th}", c_str(m_list));
	m_list.push_back((void*)"a");
	TEST_ASSERT_EQUALS("{1st, 2nd, 3rd, 4th, 5th, a}", c_str(m_list));
	m_list.pop_back();
	TEST_ASSERT_EQUALS("{1st, 2nd, 3rd, 4th, 5th}", c_str(m_list));
}

void SimpleListTest::testListOperation()
{
	TEST_ASSERT_EQUALS("{1st, 2nd, 3rd, 4th, 5th}", c_str(m_list));
	// insert(iterator, value_type)
	m_list.insert(++m_list.begin(), (void*)"a");
	TEST_ASSERT_EQUALS("{1st, a, 2nd, 3rd, 4th, 5th}", c_str(m_list));
	// erase(iterator)
	m_list.erase(++m_list.begin());
	TEST_ASSERT_EQUALS("{1st, 2nd, 3rd, 4th, 5th}", c_str(m_list));
	// insert(iterator, size_type, value_type)
	m_list.insert(++m_list.begin(), 2, (void*)"a");
	TEST_ASSERT_EQUALS("{1st, a, a, 2nd, 3rd, 4th, 5th}", c_str(m_list));
	// erase(iterator, iterator)
	m_list.erase(++m_list.begin(), ++(++(++m_list.begin())));
	TEST_ASSERT_EQUALS("{1st, 2nd, 3rd, 4th, 5th}", c_str(m_list));

	const char* ab[] = { "a", "b" };
	// insert(iterator, const_pointer, const_pointer)
	m_list.insert(++m_list.begin(), (void**)ab, (void**)ab + 2);
	TEST_ASSERT_EQUALS("{1st, a, b, 2nd, 3rd, 4th, 5th}", c_str(m_list));
	SimpleList tmp((void**)ab, (void**)ab + 2);
	// insert(iterator, const_iterator, const_iterator)
	m_list.insert(--m_list.end(), tmp.begin(), tmp.end());
	TEST_ASSERT_EQUALS("{1st, a, b, 2nd, 3rd, 4th, a, b, 5th}", c_str(m_list));
}

void SimpleListTest::testResize()
{
	TEST_ASSERT(!m_list.empty());
	TEST_ASSERT_EQUALS(5, m_list.size());
	TEST_ASSERT_EQUALS("{1st, 2nd, 3rd, 4th, 5th}", c_str(m_list));
	m_list.resize(7, (void*)"a");
	TEST_ASSERT_EQUALS(7, m_list.size());
	TEST_ASSERT_EQUALS("{1st, 2nd, 3rd, 4th, 5th, a, a}", c_str(m_list));
	m_list.resize(2);
	TEST_ASSERT_EQUALS(2, m_list.size());
	TEST_ASSERT_EQUALS("{1st, 2nd}", c_str(m_list));
	m_list.clear();
	TEST_ASSERT(m_list.empty());
	TEST_ASSERT_EQUALS(0, m_list.size());
	TEST_ASSERT_EQUALS("{}", c_str(m_list));
}

void SimpleListTest::testSwap()
{
	SimpleList v1(2, (void*)"a");
	TEST_ASSERT_EQUALS("{1st, 2nd, 3rd, 4th, 5th}", c_str(m_list));
	TEST_ASSERT_EQUALS("{a, a}", c_str(v1));
	m_list.swap(v1);
	TEST_ASSERT_EQUALS("{a, a}", c_str(m_list));
	TEST_ASSERT_EQUALS("{1st, 2nd, 3rd, 4th, 5th}", c_str(v1));
}

void SimpleListTest::testRemove()
{
	TEST_ASSERT_EQUALS("{1st, 2nd, 3rd, 4th, 5th}", c_str(m_list));
	m_list.remove(*(++m_list.begin()));
	TEST_ASSERT_EQUALS("{1st, 3rd, 4th, 5th}", c_str(m_list));
}

const char* SimpleListTest::c_str(const SimpleList& values)
{
	SimpleList::const_iterator p = values.begin();
	if (p == values.end()) return "{}";
	m_buffer.assign(1, '{');
	m_buffer.append((const char*)*p);
	while (++p != values.end()) {
		m_buffer.append(", ").append((const char*)*p);
	}
	m_buffer.append(1, '}');
	return m_buffer.c_str();
}

DECLARE_TEST_CALLER(SimpleListTest)

Test* SimpleListTest::suite()
{
	TestSuite* suite = new TestSuite("SimpleListTest");
	suite->addTest(new TEST_CALLER(SimpleListTest, testCreate));
	suite->addTest(new TEST_CALLER(SimpleListTest, testAssign));
	suite->addTest(new TEST_CALLER(SimpleListTest, testIterator));
	suite->addTest(new TEST_CALLER(SimpleListTest, testAccessor));
	suite->addTest(new TEST_CALLER(SimpleListTest, testStackOperation));
	suite->addTest(new TEST_CALLER(SimpleListTest, testListOperation));
	suite->addTest(new TEST_CALLER(SimpleListTest, testResize));
	suite->addTest(new TEST_CALLER(SimpleListTest, testSwap));
	suite->addTest(new TEST_CALLER(SimpleListTest, testRemove));
	return suite;
}
