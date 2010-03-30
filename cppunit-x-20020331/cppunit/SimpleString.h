/*
 * SimpleString.h
 */

#ifndef cppunit_SimpleString_h
#define cppunit_SimpleString_h

#include "cuconfig.h"

cu_NAMESPACE_BEGIN(cppunit)

/**
 * ä»à’ï∂éöóÒÉNÉâÉXÅB
 */
class SimpleString
{
  public:
	typedef char value_type;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
	typedef value_type* iterator;
	typedef const value_type* const_iterator;
	static const size_type npos;

  public:
	SimpleString();
	SimpleString(const SimpleString& s, size_type pos = 0, size_type n = npos);
	// not explicit
	SimpleString(const value_type* p, size_type n = npos);
	SimpleString(size_type n, value_type c);
	SimpleString(const_iterator first, const_iterator last);
	~SimpleString();

	SimpleString& operator=(const SimpleString& rhs) { return assign(rhs); }
	SimpleString& operator=(const value_type* rhs) { return assign(rhs); }
	SimpleString& operator=(value_type rhs) { return assign(1, rhs); }

	SimpleString& assign(const SimpleString& s);
	SimpleString& assign(const SimpleString& s, size_type pos, size_type n);
	SimpleString& assign(const value_type* p, size_type n = npos);
	SimpleString& assign(size_type n, value_type c);
	SimpleString& assign(const_iterator first, const_iterator last);

	iterator begin() { return m_data; }
	const_iterator begin() const { return m_data; }
	iterator end() { return m_data + m_length; }
	const_iterator end() const { return m_data + m_length; }

	reference operator[](size_type pos) { return m_data[pos]; }
	const_reference operator[](size_type pos) const { return m_data[pos]; }
	reference at(size_type pos);
	const_reference at(size_type pos) const;

	SimpleString& operator+=(const SimpleString& rhs) { return append(rhs); }
	SimpleString& operator+=(const value_type* rhs) { return append(rhs); }
	SimpleString& operator+=(value_type rhs) { return append(1, rhs); }

	SimpleString& append(const SimpleString& s)
		{ return replace(length(), 0, s); }
	SimpleString& append(const SimpleString& s, size_type pos, size_type n)
		{ return replace(length(), 0, s, pos, n); }
	SimpleString& append(const value_type* p, size_type n = npos)
		{ return replace(length(), 0, p, n); }
	SimpleString& append(size_type n, value_type c)
		{ return replace(length(), 0, n, c); }
	SimpleString& append(const_iterator first, const_iterator last)
		{ return replace(end(), end(), first, last); }

	SimpleString& insert(size_type pos, const SimpleString& s)
		{ return replace(pos, 0, s); }
	SimpleString& insert(size_type pos,
			const SimpleString& s, size_type pos2, size_type n)
		{ return replace(pos, 0, s, pos2, n); }
	SimpleString& insert(size_type pos, const value_type* p, size_type n = npos)
		{ return replace(pos, 0, p, n); }
	SimpleString& insert(size_type pos, size_type n, value_type c)
		{ return replace(pos, 0, n, c); }

	iterator insert(iterator pos, value_type c);
	void insert(iterator pos, size_type n, value_type c)
		{ replace(pos, pos, n, c); }
	void insert(iterator pos, const_iterator first, const_iterator last)
		{ replace(pos, pos, first, last); }

	SimpleString& replace(size_type pos, size_type n, const SimpleString& s);
	SimpleString& replace(size_type pos, size_type n,
			const SimpleString& s, size_type pos2, size_type n2);
	SimpleString& replace(size_type pos, size_type n,
			const value_type* p, size_type n2 = npos);
	SimpleString& replace(size_type pos, size_type n,
			size_type n2, value_type c);

	SimpleString& replace(iterator first, iterator last, const SimpleString& s)
		{ return replace(first - begin(), last - first, s); }
	SimpleString& replace(iterator first, iterator last,
			const value_type* p, size_type n = npos)
		{ return replace(first - begin(), last - first, p, n); }
	SimpleString& replace(iterator first, iterator last,
			size_type n, value_type c)
		{ return replace(first - begin(), last - first, n, c); }
	SimpleString& replace(iterator first, iterator last,
			const_iterator first2, const_iterator last2);

	SimpleString& erase(size_type pos = 0, size_type n = npos)
		{ return replace(pos, n, (size_type)0, (value_type)0); }
	iterator erase(iterator pos);
	iterator erase(iterator first, iterator last);

	const value_type* c_str() const { return m_data; }
	const value_type* data() const { return m_data; }
	size_type copy(value_type* p, size_type n, size_type pos = 0) const;

	SimpleString substr(size_type pos = 0, size_type n = npos) const
		{ return SimpleString(*this, pos, n); }

	int compare(const SimpleString& s) const;
	int compare(const value_type* p) const;

//	int compare(size_type pos, size_type n, const SimpleString& s) const;
//	int compare(size_type pos, size_type n,
//			const SimpleString& s, size_type pos2, size_type n2) const;
//	int compare(size_type pos, size_type n,
//			const value_type* p, size_type n2 = npos) const;

	bool empty() const { return size() == 0; }
	size_type size() const { return length(); }
	size_type length() const { return m_length; }
	size_type max_size() const { return npos / sizeof (value_type) - 1; }
	void resize(size_type n, value_type c = 0);
	size_type capacity() const { return m_capacity; }
	void reserve(size_type n = 0) {}

	void swap(SimpleString& rhs);

  protected:
	static size_type frobSize(size_type n);

  private:
	size_type m_length;
	size_type m_capacity;
	value_type* m_data;
};

inline SimpleString operator+(const SimpleString& lhs, const SimpleString& rhs)
	{ SimpleString s(lhs); s.append(rhs); return s; }
inline SimpleString operator+(const SimpleString& lhs, const char* rhs)
	{ SimpleString s(lhs); s.append(rhs); return s; }
inline SimpleString operator+(const SimpleString& lhs, char rhs)
	{ SimpleString s(lhs); s.append(1, rhs); return s; }
inline SimpleString operator+(const char* lhs, const SimpleString& rhs)
	{ SimpleString s(lhs); s.append(rhs); return s; }
inline SimpleString operator+(char lhs, const SimpleString& rhs)
	{ SimpleString s(1, lhs); s.append(rhs); return s; }

inline bool operator==(const SimpleString& lhs, const SimpleString& rhs)
	{ return (lhs.compare(rhs) == 0); }
inline bool operator==(const SimpleString& lhs, const char* rhs)
	{ return (lhs.compare(rhs) == 0); }
inline bool operator==(const char* lhs, const SimpleString& rhs)
	{ return (rhs.compare(lhs) == 0); }

inline bool operator!=(const SimpleString& lhs, const SimpleString& rhs)
	{ return (lhs.compare(rhs) != 0); }
inline bool operator!=(const SimpleString& lhs, const char* rhs)
	{ return (lhs.compare(rhs) != 0); }
inline bool operator!=(const char* lhs, const SimpleString& rhs)
	{ return (rhs.compare(lhs) != 0); }

inline bool operator<(const SimpleString& lhs, const SimpleString& rhs)
	{ return (lhs.compare(rhs) < 0); }
inline bool operator<(const SimpleString& lhs, const char* rhs)
	{ return (lhs.compare(rhs) < 0); }
inline bool operator<(const char* lhs, const SimpleString& rhs)
	{ return (rhs.compare(lhs) > 0); }

inline bool operator<=(const SimpleString& lhs, const SimpleString& rhs)
	{ return (lhs.compare(rhs) <= 0); }
inline bool operator<=(const SimpleString& lhs, const char* rhs)
	{ return (lhs.compare(rhs) <= 0); }
inline bool operator<=(const char* lhs, const SimpleString& rhs)
	{ return (rhs.compare(lhs) >= 0); }

inline bool operator>(const SimpleString& lhs, const SimpleString& rhs)
	{ return (lhs.compare(rhs) > 0); }
inline bool operator>(const SimpleString& lhs, const char* rhs)
	{ return (lhs.compare(rhs) > 0); }
inline bool operator>(const char* lhs, const SimpleString& rhs)
	{ return (rhs.compare(lhs) < 0); }

inline bool operator>=(const SimpleString& lhs, const SimpleString& rhs)
	{ return (lhs.compare(rhs) >= 0); }
inline bool operator>=(const SimpleString& lhs, const char* rhs)
	{ return (lhs.compare(rhs) >= 0); }
inline bool operator>=(const char* lhs, const SimpleString& rhs)
	{ return (rhs.compare(lhs) <= 0); }

cu_NAMESPACE_END

#endif /* !cppunit_SimpleString_h */
