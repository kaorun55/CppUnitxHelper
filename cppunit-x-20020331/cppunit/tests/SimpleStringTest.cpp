/*
 * SimpleStringTest.cpp
 */

#include <cppunit/cudebug.h>
#include "SimpleStringTest.h"
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#ifndef cu_NO_EXCEPTIONS
#  include <stdexcept>
#endif

USING_NAMESPACE_CPPUNIT

void SimpleStringTest::testCreate()
{
	// SimpleString()
	SimpleString s1;
	TEST_ASSERT_EQUALS("", s1.c_str());
	// SimpleString(const SimpleString&)
	SimpleString s2(m_string);
	TEST_ASSERT_EQUALS("12345", s2.c_str());
	// SimpleString(const SimpleString&, size_type, size_type)
	SimpleString s3(m_string, 1, 2);
	TEST_ASSERT_EQUALS("23", s3.c_str());

	const char* values = "12345";
	// SimpleString(const value_type*)
	SimpleString s4(values);
	TEST_ASSERT_EQUALS("12345", s4.c_str());
	// SimpleString(const value_type* size_type)
	SimpleString s5(values, 2);
	TEST_ASSERT_EQUALS("12", s5.c_str());
	// SimpleString(size_type, value_type)
	SimpleString s6(2, 'a');
	TEST_ASSERT_EQUALS("aa", s6.c_str());
	// SimpleString(const_iterator, const_iterator)
	SimpleString s7(values, values + 2);
	TEST_ASSERT_EQUALS("12", s7.c_str());

#ifndef cu_NO_EXCEPTIONS
	try {
		SimpleString s8(SimpleString::npos, 'a');
		TEST_FAIL("length_error not thrown");
	} catch (cu_STD::length_error& e) {
		cu_TRACE1("catch length_error: %s\n", e.what());
	}
#endif
}

void SimpleStringTest::testAssign()
{
	SimpleString s1;
	TEST_ASSERT_EQUALS("", s1.c_str());
	// assign(const SimpleString&)
	s1.assign(m_string);
	TEST_ASSERT_EQUALS("12345", s1.c_str());
	// assign(const SimpleString&, size_type, size_type)
	s1.assign(m_string, 1, 2);
	TEST_ASSERT_EQUALS("23", s1.c_str());

	const char* values = "12345";
	// assign(const value_type*)
	s1.assign(values);
	TEST_ASSERT_EQUALS("12345", s1.c_str());
	// assign(const value_type*, size_type)
	s1.assign(values, 2);
	TEST_ASSERT_EQUALS("12", s1.c_str());
	// assign(size_type, value_type)
	s1.assign(2, 'a');
	TEST_ASSERT_EQUALS("aa", s1.c_str());
	// assign(const_iterator, const_iterator)
	s1.assign(values, values + 2);
	TEST_ASSERT_EQUALS("12", s1.c_str());

	// operator=(const SimpleString&)
	s1 = m_string;
	TEST_ASSERT_EQUALS("12345", s1.c_str());
	// operator=(const value_type*)
	s1 = values;
	TEST_ASSERT_EQUALS("12345", s1.c_str());
	// operator=(value_type)
	s1 = 'a';
	TEST_ASSERT_EQUALS("a", s1.c_str());
}

void SimpleStringTest::testIterator()
{
	TEST_ASSERT_EQUALS('1', *m_string.begin());
	TEST_ASSERT_EQUALS('5', *(m_string.end() - 1));
}

void SimpleStringTest::testAccessor()
{
	TEST_ASSERT_EQUALS("12345", m_string.c_str());
	TEST_ASSERT_EQUALS('2', m_string[1]);
	m_string[1] = 'a';
	TEST_ASSERT_EQUALS("1a345", m_string.c_str());
	TEST_ASSERT_EQUALS('3', m_string.at(2));
	m_string.at(2) = 'b';
	TEST_ASSERT_EQUALS("1ab45", m_string.c_str());

#ifndef cu_NO_EXCEPTIONS
	try {
		TEST_ASSERT_EQUALS(' ', m_string.at(SimpleString::npos));
		TEST_FAIL("out_of_range not thrown");
	} catch (cu_STD::out_of_range& e) {
		cu_TRACE1("catch out_of_range: %s\n", e.what());
	}
#endif
}

void SimpleStringTest::testAppend()
{
	const char* abcde = "abcde";
	SimpleString tmp(abcde);
	TEST_ASSERT_EQUALS("12345", m_string.c_str());
	// append(const SimpleString&)
	m_string.append(tmp);
	TEST_ASSERT_EQUALS("12345abcde", m_string.c_str());
	// append(const SimpleString&, size_type, size_type)
	m_string.append(tmp, 1, 2);
	TEST_ASSERT_EQUALS("12345abcdebc", m_string.c_str());
	// erase(size_type)
	m_string.erase(5);
	TEST_ASSERT_EQUALS("12345", m_string.c_str());

	// append(const value_type*)
	m_string.append(abcde);
	TEST_ASSERT_EQUALS("12345abcde", m_string.c_str());
	// append(const value_type*, size_type)
	m_string.append(abcde, 2);
	TEST_ASSERT_EQUALS("12345abcdeab", m_string.c_str());
	// erase(size_type)
	m_string.erase(5);
	TEST_ASSERT_EQUALS("12345", m_string.c_str());
	// append(size_type, value_type)
	m_string.append(2, 'a');
	TEST_ASSERT_EQUALS("12345aa", m_string.c_str());
	// append(const_iterator, const_iterator)
	m_string.append(abcde, abcde + 2);
	TEST_ASSERT_EQUALS("12345aaab", m_string.c_str());
	// erase(size_type)
	m_string.erase(5);
	TEST_ASSERT_EQUALS("12345", m_string.c_str());

	// operator+=(const SimpleString&)
	m_string += tmp;
	TEST_ASSERT_EQUALS("12345abcde", m_string.c_str());
	// operator+=(const value_type*)
	m_string += abcde;
	TEST_ASSERT_EQUALS("12345abcdeabcde", m_string.c_str());
	// operator+=(value_type)
	m_string += 'a';
	TEST_ASSERT_EQUALS("12345abcdeabcdea", m_string.c_str());
}

void SimpleStringTest::testInsert()
{
	const char* abcde = "abcde";
	SimpleString tmp(abcde);
	TEST_ASSERT_EQUALS("12345", m_string.c_str());
	// insert(size_type, const SimpleString&)
	m_string.insert(1, tmp);
	TEST_ASSERT_EQUALS("1abcde2345", m_string.c_str());
	// insert(size_type, const SimpleString&, size_type, size_type)
	m_string.insert(6, tmp, 1, 2);
	TEST_ASSERT_EQUALS("1abcdebc2345", m_string.c_str());
	// erase(size_type, size_type)
	m_string.erase(1, 7);
	TEST_ASSERT_EQUALS("12345", m_string.c_str());

	// insert(size_type, const value_type*)
	m_string.insert(1, abcde);
	TEST_ASSERT_EQUALS("1abcde2345", m_string.c_str());
	// insert(size_type, const value_type*, size_type)
	m_string.insert(6, abcde, 2);
	TEST_ASSERT_EQUALS("1abcdeab2345", m_string.c_str());
	// erase(size_type, size_type)
	m_string.erase(1, 7);
	TEST_ASSERT_EQUALS("12345", m_string.c_str());
	// insert(size_type, size_type, value_type)
	m_string.insert(1, 2, 'a');
	TEST_ASSERT_EQUALS("1aa2345", m_string.c_str());
	// erase(size_type, size_type)
	m_string.erase(1, 2);
	TEST_ASSERT_EQUALS("12345", m_string.c_str());

	// insert(iterator, value_type)
	m_string.insert(m_string.begin() + 1, 'a');
	TEST_ASSERT_EQUALS("1a2345", m_string.c_str());
	// erase(iterator)
	m_string.erase(m_string.begin() + 1);
	TEST_ASSERT_EQUALS("12345", m_string.c_str());
	// insert(iterator, size_type, value_type)
	m_string.insert(m_string.begin() + 1, 2, 'a');
	TEST_ASSERT_EQUALS("1aa2345", m_string.c_str());
	// insert(iterator, const_iterator, const_iterator)
	m_string.insert(m_string.begin() + 3, abcde, abcde + 2);
	TEST_ASSERT_EQUALS("1aaab2345", m_string.c_str());
	// erase(iterator, iterator)
	m_string.erase(m_string.begin() + 1, m_string.begin() + 5);
	TEST_ASSERT_EQUALS("12345", m_string.c_str());
}

void SimpleStringTest::testReplace()
{
	const char* abcde = "abcde";
	SimpleString tmp(abcde);
	TEST_ASSERT_EQUALS("12345", m_string.c_str());
	// replace(size_type, size_type, const SimpleString&)
	m_string.replace(1, 1, tmp);
	TEST_ASSERT_EQUALS("1abcde345", m_string.c_str());
	// replace(size_type, size_type, const SimpleString&, size_type, size_type)
	m_string.replace(6, 1, tmp, 1, 2);
	TEST_ASSERT_EQUALS("1abcdebc45", m_string.c_str());

	// replace(size_type, size_type, const value_type*)
	m_string.replace(1, 7, abcde);
	TEST_ASSERT_EQUALS("1abcde45", m_string.c_str());
	// replace(size_type, size_type, const value_type*, size_type)
	m_string.replace(6, 1, abcde, 2);
	TEST_ASSERT_EQUALS("1abcdeab5", m_string.c_str());
	// replace(size_type, size_type, size_type, value_type)
	m_string.replace(1, 7, 2, 'a');
	TEST_ASSERT_EQUALS("1aa5", m_string.c_str());
	// replace(size_type, size_type, const value_type*)
	m_string.replace(0, SimpleString::npos, "12345");
	TEST_ASSERT_EQUALS("12345", m_string.c_str());

	// replace(iterator, iterator, const SimpleString&)
	m_string.replace(m_string.begin() + 1, m_string.begin() + 2, tmp);
	TEST_ASSERT_EQUALS("1abcde345", m_string.c_str());
	// replace(iterator, iterator, const value_type*)
	m_string.replace(m_string.begin() + 6, m_string.begin() + 7, abcde);
	TEST_ASSERT_EQUALS("1abcdeabcde45", m_string.c_str());
	// replace(iterator, iterator, const value_type*, size_type)
	m_string.replace(m_string.begin() + 11, m_string.begin() + 12, abcde, 2);
	TEST_ASSERT_EQUALS("1abcdeabcdeab5", m_string.c_str());
	// replace(iterator, iterator, size_type, value_type)
	m_string.replace(m_string.begin() + 1, m_string.begin() + 13, 2, 'a');
	TEST_ASSERT_EQUALS("1aa5", m_string.c_str());
	// replace(iterator, iterator, const_iterator, const_iterator)
	m_string.replace(m_string.begin() + 1, m_string.begin() + 3,
			tmp.begin(), tmp.end());
	TEST_ASSERT_EQUALS("1abcde5", m_string.c_str());
}

void SimpleStringTest::testCopy()
{
	char buf[4];
	size_t n;
	n = m_string.copy(buf, 2); buf[n] = 0;
	TEST_ASSERT_EQUALS("12", buf);
	n = m_string.copy(buf, SimpleString::npos, 2); buf[n] = 0;
	TEST_ASSERT_EQUALS("345", buf);
}

void SimpleStringTest::testSubstr()
{
	TEST_ASSERT_EQUALS("2345", m_string.substr(1).c_str());
	TEST_ASSERT_EQUALS("23", m_string.substr(1, 2).c_str());
}

void SimpleStringTest::testCompare()
{
	SimpleString s1 = "12345";
	SimpleString s2 = "abc";
	TEST_ASSERT(m_string.compare(s1) == 0);
	TEST_ASSERT(m_string.compare(s2) < 0);
	TEST_ASSERT(s1.compare(m_string) == 0);
	TEST_ASSERT(s2.compare(m_string) > 0);

	TEST_ASSERT(m_string.compare("abc") < 0);
	TEST_ASSERT(m_string.compare("12345") == 0);
	TEST_ASSERT(m_string.compare("") > 0);
}

void SimpleStringTest::testResize()
{
	TEST_ASSERT(!m_string.empty());
	TEST_ASSERT_EQUALS(5, m_string.size());
	TEST_ASSERT_EQUALS("12345", m_string.c_str());
	m_string.resize(7, 'a');
	TEST_ASSERT_EQUALS(7, m_string.length());
	TEST_ASSERT_EQUALS("12345aa", m_string.c_str());
	m_string.resize(2);
	TEST_ASSERT_EQUALS(2, m_string.size());
	TEST_ASSERT_EQUALS("12", m_string.c_str());
	m_string.erase();
	TEST_ASSERT(m_string.empty());
	TEST_ASSERT_EQUALS(0, m_string.length());
	TEST_ASSERT_EQUALS("", m_string.c_str());
}

void SimpleStringTest::testSwap()
{
	SimpleString s1(2, 'a');
	TEST_ASSERT_EQUALS("12345", m_string.c_str());
	TEST_ASSERT_EQUALS("aa", s1.c_str());
	m_string.swap(s1);
	TEST_ASSERT_EQUALS("aa", m_string.c_str());
	TEST_ASSERT_EQUALS("12345", s1.c_str());
}

DECLARE_TEST_CALLER(SimpleStringTest)

Test* SimpleStringTest::suite()
{
	TestSuite* suite = new TestSuite("SimpleStringTest");
	suite->addTest(new TEST_CALLER(SimpleStringTest, testCreate));
	suite->addTest(new TEST_CALLER(SimpleStringTest, testAssign));
	suite->addTest(new TEST_CALLER(SimpleStringTest, testIterator));
	suite->addTest(new TEST_CALLER(SimpleStringTest, testAccessor));
	suite->addTest(new TEST_CALLER(SimpleStringTest, testAppend));
	suite->addTest(new TEST_CALLER(SimpleStringTest, testInsert));
	suite->addTest(new TEST_CALLER(SimpleStringTest, testReplace));
	suite->addTest(new TEST_CALLER(SimpleStringTest, testCopy));
	suite->addTest(new TEST_CALLER(SimpleStringTest, testSubstr));
	suite->addTest(new TEST_CALLER(SimpleStringTest, testCompare));
	suite->addTest(new TEST_CALLER(SimpleStringTest, testResize));
	suite->addTest(new TEST_CALLER(SimpleStringTest, testSwap));
	return suite;
}
