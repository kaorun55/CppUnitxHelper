/*
 * SimpleAutoPtr.h
 */

#ifndef cppunit_SimpleAutoPtr_h
#define cppunit_SimpleAutoPtr_h

#include "cuconfig.h"

#ifndef cu_NO_TEMPLATES

#define SIMPLE_AUTO_PTR(T) CPPUNIT::SimpleAutoPtr<T>

cu_NAMESPACE_BEGIN(cppunit)

/**
 * �ȈՃI�[�g�|�C���^�B
 */
template <class T>
class SimpleAutoPtr
{
  public:
	typedef T element_type;

  public:
	explicit SimpleAutoPtr(T* p = 0) cu_NOTHROW : m_ptr(p) {}
	~SimpleAutoPtr() cu_NOTHROW { delete m_ptr; }

	T& operator*() const cu_NOTHROW { return *m_ptr; }
	T* operator->() const cu_NOTHROW { return m_ptr; }
	T* get() const cu_NOTHROW { return m_ptr; }
	T* release() cu_NOTHROW { T* tmp = m_ptr; m_ptr = 0; return tmp; }
	void reset(T* p = 0) cu_NOTHROW
		{ if (p != m_ptr) { delete m_ptr; m_ptr = p; } }

  private:
	// std::auto_ptr ��݊��B
	SimpleAutoPtr(SimpleAutoPtr& rhs) cu_NOTHROW;
	SimpleAutoPtr& operator=(SimpleAutoPtr& rhs) cu_NOTHROW;

  private:
	T* m_ptr;
};

cu_NAMESPACE_END

#else /* cu_NO_TEMPLATES */

/**
 * �[���e���v���[�g�}�N���B
 *
 * ���� a �̐錾�͗Ⴆ�� b �̂悤�ɓW�J�����B
 * <pre>
 *   a) SIMPLE_AUTO_PTR(Object) object(new Object());
 *   b) class SimpleAutoPtrObject_1000 { ... } object(new Object());
 * </pre>
 *
 * �����N���X�� SimpleAutoPtr �𑽗p����ꍇ�́Atypedef ���������悢�B
 * <pre>
 *   eg) typedef SIMPLE_AUTO_PTR(Object) ObjectAutoPtr;
 *       ObjectAutoPtr object(new Object());
 * </pre>
 */
#define SIMPLE_AUTO_PTR(T) SimpleAutoPtr(T)

#define SimpleAutoPtrX(T) cu_NAME4(SimpleAutoPtr, T, _, __LINE__)
#define SimpleAutoPtr(T) \
class SimpleAutoPtrX(T) { \
  public: \
	typedef T element_type; \
	explicit SimpleAutoPtrX(T)(T* p = 0) cu_NOTHROW : m_ptr(p) {} \
	~SimpleAutoPtrX(T)() cu_NOTHROW { delete m_ptr; } \
	T& operator*() const cu_NOTHROW { return *m_ptr; } \
	T* operator->() const cu_NOTHROW { return m_ptr; } \
	T* get() const cu_NOTHROW { return m_ptr; } \
	T* release() cu_NOTHROW { T* tmp = m_ptr; m_ptr = 0; return tmp; } \
	void reset(T* p = 0) cu_NOTHROW \
		{ if (p != m_ptr) { delete m_ptr; m_ptr = p; } } \
  private: \
	SimpleAutoPtrX(T)(SimpleAutoPtrX(T)& rhs) cu_NOTHROW; \
	SimpleAutoPtrX(T)& operator=(SimpleAutoPtrX(T)& rhs) cu_NOTHROW; \
	T* m_ptr; \
}

#endif /* cu_NO_TEMPLATES */

#endif /* !cppunit_SimpleAutoPtr_h */
