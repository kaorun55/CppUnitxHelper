/*
 * SimpleList.h
 */

#ifndef cppunit_SimpleList_h
#define cppunit_SimpleList_h

#include "cuconfig.h"

cu_NAMESPACE_BEGIN(cppunit)

/**
 * 簡易リストクラス。
 */
class SimpleList
{
  public:
	typedef void* value_type;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;

	/** リストノード。 */
	struct Node {
		explicit Node(value_type value = 0)
			: next(0), prev(0), data(value) {}
		Node* next;
		Node* prev;
		value_type data;
	};

	/** リストイテレータのベース。 */
	struct IteratorBase {
		// not explicit
		IteratorBase(Node* node) : node(node) {}
		void next() { node = node->next; }
		void prev() { node = node->prev; }
		bool operator==(const IteratorBase& rhs) const
			{ return (node == rhs.node); }
		bool operator!=(const IteratorBase& rhs) const
			{ return (node != rhs.node); }
		Node* node;
	};

	/** リストイテレータ。 */
	struct Iterator : public IteratorBase {
		// not explicit
		Iterator(Node* node = 0) : IteratorBase(node) {}
		reference operator*() const { return node->data; }
		pointer operator->() const { return &node->data; }
		Iterator& operator++() { next(); return *this; }
		Iterator operator++(int);
		Iterator& operator--() { prev(); return *this; }
		Iterator operator--(int);
	};

	/** リストイテレータの const バージョン。 */
	struct const_Iterator : public IteratorBase {
		// not explicit
		const_Iterator(Node* node = 0) : IteratorBase(node) {}
		// ↓コピーコンストラクタではない!!
		const_Iterator(const Iterator& rhs) : IteratorBase(rhs.node) {}
		const_reference operator*() const { return node->data; }
		const_pointer operator->() const { return &node->data; }
		const_Iterator& operator++() { next(); return *this; }
		const_Iterator operator++(int);
		const_Iterator& operator--() { prev(); return *this; }
		const_Iterator operator--(int);
	};

	typedef Iterator iterator;
	typedef const_Iterator const_iterator;

  public:
	SimpleList();
	explicit SimpleList(size_type n, value_type value = 0);
	SimpleList(const_pointer first, const_pointer last);
	SimpleList(const_iterator first, const_iterator last);
	SimpleList(const SimpleList& rhs);
	~SimpleList();

	SimpleList& operator=(const SimpleList& rhs);
	void assign(size_type n, value_type value);
	void assign(const_pointer first, const_pointer last);
	void assign(const_iterator first, const_iterator last);

	iterator begin() { return m_node->next; }
	const_iterator begin() const { return m_node->next; }
	iterator end() { return m_node; }
	const_iterator end() const { return m_node; }

	reference front() { return *begin(); }
	const_reference front() const { return *begin(); }
	reference back() { return *(--end()); }
	const_reference back() const { return *(--end()); }

	void push_front(value_type value) { insert(begin(), value); }
	void pop_front() { erase(begin()); }
	void push_back(value_type value) { insert(end(), value); }
	void pop_back() { erase(--end()); }

	iterator insert(iterator pos, value_type value);
	void insert(iterator pos, size_type n, value_type value);
	void insert(iterator pos, const_pointer first, const_pointer last);
	void insert(iterator pos, const_iterator first, const_iterator last);
	iterator erase(iterator pos);
	iterator erase(iterator first, iterator last);
	void clear();

	bool empty() const { return begin() == end(); }
	size_type size() const;
	size_type max_size() const { return size_type(-1); }
	void resize(size_type n, value_type value = 0);
	void swap(SimpleList& rhs);

	void remove(value_type value);

  protected:
	Node* createDummyNode();

  private:
	Node* m_node;
};

cu_NAMESPACE_END

#endif /* !cppunit_SimpleList_h */
