/*
 * SimpleString.cpp
 */

#include "cuconfig.h"
#include "cudebug.h"
#include "SimpleString.h"
#include <string.h>

#ifndef cu_NO_EXCEPTIONS
#  include <stdexcept>
#  define cu_OUT_OF_RANGE(e) \
	do { if (e) throw cu_STD::out_of_range(#e); } while (0)
#  define cu_LENGTH_ERROR(e) \
	do { if (e) throw cu_STD::length_error(#e); } while (0)
#else
#  define cu_OUT_OF_RANGE(e) cu_ASSERT(!(e))
#  define cu_LENGTH_ERROR(e) cu_ASSERT(!(e))
#endif

#ifdef DEBUG
#  define cu_REPORT_STRING_CLONE(s, e) \
	((e) ? cu_TRACE1("clone \"%s\"\n", s) : (void)0)
#  define cu_REPORT_STRING_REALLOC(s, n1, n2) \
	((n1) ? cu_TRACE3("realloc \"%s\" (%u->%u)\n", s, n1, n2) : (void)0)
#else
#  define cu_REPORT_STRING_CLONE(s, e)        (void)0
#  define cu_REPORT_STRING_REALLOC(s, n1, n2) (void)0
#endif

cu_NAMESPACE_BEGIN(cppunit)

const SimpleString::size_type SimpleString::npos = size_type(-1);

SimpleString::SimpleString()
	: m_length(0), m_capacity(0), m_data(0)
{
	assign((size_type)0, (value_type)0);
}

SimpleString::SimpleString(const SimpleString& s, size_type pos, size_type n)
	: m_length(0), m_capacity(0), m_data(0)
{
	assign(s, pos, n);
}

SimpleString::SimpleString(const value_type* p, size_type n)
	: m_length(0), m_capacity(0), m_data(0)
{
	assign(p, n);
}

SimpleString::SimpleString(size_type n, value_type c)
	: m_length(0), m_capacity(0), m_data(0)
{
	assign(n, c);
}

SimpleString::SimpleString(const_iterator first, const_iterator last)
	: m_length(0), m_capacity(0), m_data(0)
{
	assign(first, last);
}

SimpleString::~SimpleString()
{
	delete[] m_data;
}

SimpleString& SimpleString::assign(const SimpleString& s)
{
	if (this == &s) return *this;
	cu_REPORT_STRING_CLONE(s.c_str(), true);
	return assign(s.begin(), s.end());
}

SimpleString& SimpleString::assign(
		const SimpleString& s, size_type pos, size_type n)
{
	size_t len = s.length();
	cu_REPORT_STRING_CLONE(s.c_str(), pos == 0 && len <= n);
	cu_OUT_OF_RANGE(len < pos);
	if (len - pos < n) n = len - pos;
	return assign(s.begin() + pos, s.begin() + pos + n);
}

SimpleString& SimpleString::assign(const value_type* p, size_type n)
{
	size_t len = strlen(p);
	if (len < n) n = len;
	return assign(p, p + n);
}

SimpleString& SimpleString::assign(size_type n, value_type c)
{
	cu_LENGTH_ERROR(n > max_size());
	size_t size= frobSize(n + 1);
	if (capacity() < size) {
		cu_REPORT_STRING_REALLOC(c_str(), capacity(), size);
		value_type* data = new value_type[size];
		delete[] m_data;
		m_data = data;
		m_capacity = size;
	}
	memset(m_data, c, n);
	m_data[n] = 0;
	m_length = n;
	return *this;
}

SimpleString& SimpleString::assign(const_iterator first, const_iterator last)
{
	size_t n = last - first;
	cu_LENGTH_ERROR(n > max_size());
	size_t size = frobSize(n + 1);
	if (capacity() < size) {
		cu_REPORT_STRING_REALLOC(c_str(), capacity(), size);
		value_type* data = new value_type[size];
		memcpy(data, first, n);
		delete[] m_data;
		m_data = data;
		m_capacity = size;
	} else {
		memmove(m_data, first, n);
	}
	m_data[n] = 0;
	m_length = n;
	return *this;
}

SimpleString::reference SimpleString::at(size_type pos)
{
	cu_OUT_OF_RANGE(length() <= pos);
	return (*this)[pos];
}

SimpleString::const_reference SimpleString::at(size_type pos) const
{
	cu_OUT_OF_RANGE(length() <= pos);
	return (*this)[pos];
}

SimpleString::iterator SimpleString::insert(iterator pos, value_type c)
{
	size_type index = pos - begin();
	insert(index, 1, c);
	return begin() + index;
}

SimpleString& SimpleString::replace(
		size_type pos, size_type n, const SimpleString& s)
{
	size_t len = length();
	cu_OUT_OF_RANGE(len < pos);
	if (len - pos < n) n = len - pos;
	return replace(begin() + pos, begin() + pos + n, s.begin(), s.end());
}

SimpleString& SimpleString::replace(
		size_type pos, size_type n,
		const SimpleString& s, size_type pos2, size_type n2)
{
	size_t len = length();
	cu_OUT_OF_RANGE(len < pos);
	size_t len2 = s.length();
	cu_OUT_OF_RANGE(len2 < pos2);
	if (len - pos < n) n = len - pos;
	if (len2 - pos2 < n2) n2 = len2 - pos2;
	return replace(begin() + pos, begin() + pos + n,
			s.begin() + pos2, s.begin() + pos2 + n2);
}

SimpleString& SimpleString::replace(
		size_type pos, size_type n, const value_type* p, size_type n2)
{
	size_t len = length();
	cu_OUT_OF_RANGE(len < pos);
	size_t len2 = strlen(p);
	if (len - pos < n) n = len - pos;
	if (len2 < n2) n2 = len2;
	return replace(begin() + pos, begin() + pos + n, p, p + n2);
}

SimpleString& SimpleString::replace(
		size_type pos, size_type n, size_type n2, value_type c)
{
	size_t len = length();
	cu_OUT_OF_RANGE(len < pos);
	if (len - pos < n) n = len - pos;
	size_t newLen = len - n + n2;
	cu_LENGTH_ERROR(newLen > max_size());
	size_t size = frobSize(newLen + 1);
	if (capacity() < size) {
		cu_REPORT_STRING_REALLOC(c_str(), capacity(), size);
		value_type* data = new value_type[size];
		memcpy(data, m_data, pos);
		memcpy(data + pos + n2, m_data + pos + n, len - (pos + n));
		memset(data + pos, c, n2);
		delete[] m_data;
		m_data = data;
		m_capacity = size;
	} else {
		memmove(m_data + pos + n2, m_data + pos + n, len - (pos + n));
		memset(m_data + pos, c, n2);
	}
	m_data[newLen] = 0;
	m_length = newLen;
	return *this;
}

SimpleString& SimpleString::replace(
		iterator first, iterator last,
		const_iterator first2, const_iterator last2)
{
	size_t n = last - first;
	size_t n2 = last2 - first2;
	size_t newLen = length() - n + n2;
	cu_LENGTH_ERROR(newLen > max_size());
	size_t size = frobSize(newLen + 1);
	size_t pos = first - m_data;
	if (capacity() < size) {
		cu_REPORT_STRING_REALLOC(c_str(), capacity(), size);
		value_type* data = new value_type[size];
		memcpy(data, m_data, pos);
		memcpy(data + pos + n2, last, end() - last);
		memcpy(data + pos, first2, n2);
		delete[] m_data;
		m_data = data;
		m_capacity = size;
	} else {
		memmove(m_data + pos + n2, last, end() - last);
		memcpy(m_data + pos, first2, n2);
	}
	m_data[newLen] = 0;
	m_length = newLen;
	return *this;
}

SimpleString::iterator SimpleString::erase(iterator pos)
{
	size_type index = pos - begin();
	replace(index, 1, (size_type)0, (value_type)0);
	return begin() + index;
}

SimpleString::iterator SimpleString::erase(iterator first, iterator last)
{
	size_type index = first - begin();
	replace(index, last - first, (size_type)0, (value_type)0);
	return begin() + index;
}

SimpleString::size_type SimpleString::copy(
		value_type* p, size_type n, size_type pos) const
{
	size_type len = length();
	cu_OUT_OF_RANGE(len < pos);
	if (len - pos < n) n = len - pos;
	memcpy(p, m_data + pos, n);
	return n;
}

int SimpleString::compare(const SimpleString& s) const
{
	return strcmp(c_str(), s.c_str());
}

int SimpleString::compare(const value_type* p) const
{
	return strcmp(c_str(), p);
}

void SimpleString::resize(size_type n, value_type c)
{
	cu_LENGTH_ERROR(n > max_size());
	if (length() < n) {
		append(n - length(), c);
	} else {
		erase(n);
	}
}

void SimpleString::swap(SimpleString& rhs)
{
	size_type tmp1;
	tmp1 = m_length;   m_length   = rhs.m_length;   rhs.m_length   = tmp1;
	tmp1 = m_capacity; m_capacity = rhs.m_capacity; rhs.m_capacity = tmp1;
	value_type* tmp2 = m_data; m_data = rhs.m_data; rhs.m_data = tmp2;
}

SimpleString::size_type SimpleString::frobSize(size_type n)
{
	// realloc —}§‚Ì‚½‚ß‰Šú’l‚ð‘å‚«‚ß‚ÉÝ’èB
	size_type size = 32;
	while (size < n) size *= 2;
	return size;
}

cu_NAMESPACE_END
