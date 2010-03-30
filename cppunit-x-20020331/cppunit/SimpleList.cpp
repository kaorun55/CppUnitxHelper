/*
 * SimpleList.cpp
 */

#include "cuconfig.h"
#include "cudebug.h"
#include "SimpleList.h"

cu_NAMESPACE_BEGIN(cppunit)

SimpleList::SimpleList()
	: m_node(createDummyNode())
{
}

SimpleList::SimpleList(size_type n, value_type value)
	: m_node(createDummyNode())
{
	insert(begin(), n, value);
}

SimpleList::SimpleList(const_pointer first, const_pointer last)
	: m_node(createDummyNode())
{
	insert(begin(), first, last);
}

SimpleList::SimpleList(const_iterator first, const_iterator last)
	: m_node(createDummyNode())
{
	insert(begin(), first, last);
}

SimpleList::SimpleList(const SimpleList& rhs)
	: m_node(createDummyNode())
{
	insert(begin(), rhs.begin(), rhs.end());
}

SimpleList::Node* SimpleList::createDummyNode()
{
	Node* node = new Node();
	node->next = node;
	node->prev = node;
	return node;
}

SimpleList::~SimpleList()
{
	clear();
	delete m_node;
}

SimpleList& SimpleList::operator=(const SimpleList& rhs)
{
	if (this == &rhs) return *this;
	iterator first1 = begin();
	iterator last1  = end();
	const_iterator first2 = rhs.begin();
	const_iterator last2  = rhs.end();
	while (first1 != last1 && first2 != last2) {
		*first1++ = *first2++;
	}
	if (first2 == last2) {
		erase(first1, last1);
	} else {
		insert(last1, first2, last2);
	}
	return *this;
}

void SimpleList::assign(size_type n, value_type value)
{
	iterator pos = begin();
	while (pos != end() && n > 0) {
		*pos = value;
		++pos; --n;
	}
	if (n > 0) {
		insert(end(), n, value);
	} else {
		erase(pos, end());
	}
}

void SimpleList::assign(const_pointer first, const_pointer last)
{
	iterator first1 = begin();
	iterator last1  = end();
	while (first1 != last1 && first != last) {
		*first1++ = *first++;
	}
	if (first == last) {
		erase(first1, last1);
	} else {
		insert(last1, first, last);
	}
}

void SimpleList::assign(const_iterator first, const_iterator last)
{
	iterator first1 = begin();
	iterator last1  = end();
	while (first1 != last1 && first != last) {
		*first1++ = *first++;
	}
	if (first == last) {
		erase(first1, last1);
	} else {
		insert(last1, first, last);
	}
}

SimpleList::iterator SimpleList::insert(iterator pos, value_type value)
{
	Node* tmp = new Node(value);
	tmp->next = pos.node;
	tmp->prev = pos.node->prev;
	pos.node->prev->next = tmp;
	pos.node->prev = tmp;
	return tmp;
}

void SimpleList::insert(iterator pos, size_type n, value_type value)
{
	while (n > 0) {
		insert(pos, value); --n;
	}
}

void SimpleList::insert(iterator pos, const_pointer first, const_pointer last)
{
	while (first != last) {
		insert(pos, *first++);
	}
}

void SimpleList::insert(iterator pos, const_iterator first, const_iterator last)
{
	while (first != last) {
		insert(pos, *first++);
	}
}

SimpleList::iterator SimpleList::erase(iterator pos)
{
	Node* nextNode = pos.node->next;
	Node* prevNode = pos.node->prev;
	prevNode->next = nextNode;
	nextNode->prev = prevNode;
	delete pos.node;
	return nextNode;
}

SimpleList::iterator SimpleList::erase(iterator first, iterator last)
{
	while (first != last) {
		erase(first++);
	}
	return last;
}

void SimpleList::clear()
{
	Node* current = m_node->next;
	while (current != m_node) {
		Node* tmp = current;
		current = current->next;
		delete tmp;
	}
	m_node->next = m_node;
	m_node->prev = m_node;
}

SimpleList::size_type SimpleList::size() const
{
	size_type result = 0;
	const_iterator first = begin();
	const_iterator last  = end();
	while (first++ != last) ++result;
	return result;
}

void SimpleList::resize(size_type n, value_type value)
{
	iterator pos = begin();
	while (pos != end() && n > 0) {
		++pos; --n;
	}
	if (n > 0) {
		insert(end(), n, value);
	} else {
		erase(pos, end());
	}
}

void SimpleList::swap(SimpleList& rhs)
{
	Node* tmp = m_node;
	m_node = rhs.m_node;
	rhs.m_node = tmp;
}

void SimpleList::remove(value_type value)
{
	iterator first = begin();
	iterator last  = end();
	while (first != last) {
		iterator tmp = first;
		++first;
		if (*tmp == value) erase(tmp);
	}
}

SimpleList::Iterator SimpleList::Iterator::operator++(int)
{
	Iterator result = *this;
	++(*this);
	return result;
}

SimpleList::Iterator SimpleList::Iterator::operator--(int)
{
	Iterator result = *this;
	--(*this);
	return result;
}

SimpleList::const_Iterator SimpleList::const_Iterator::operator++(int)
{
	const_Iterator result = *this;
	++(*this);
	return result;
}

SimpleList::const_Iterator SimpleList::const_Iterator::operator--(int)
{
	const_Iterator result = *this;
	--(*this);
	return result;
}

cu_NAMESPACE_END
