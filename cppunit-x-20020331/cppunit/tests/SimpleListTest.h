/*
 * SimpleListTest.h
 */

#ifndef cppunit_tests_SimpleListTest_h
#define cppunit_tests_SimpleListTest_h

#include <cppunit/TestCase.h>
#include <cppunit/SimpleList.h>

USING_NAMESPACE_CPPUNIT

class SimpleListTest : public TestCase
{
  public:
	explicit SimpleListTest(const char* name) : TestCase(name) {}
	virtual void setUp();
	void testCreate();
	void testAssign();
	void testIterator();
	void testAccessor();
	void testStackOperation();
	void testListOperation();
	void testResize();
	void testSwap();
	void testRemove();
	static Test* suite();

  private:
	const char* c_str(void* s) { return s ? (char*)s : ""; }
	const char* c_str(const SimpleList& values);

	SimpleList m_list;
	cu_String m_buffer;
};

#endif /* !cppunit_tests_SimpleListTest_h */
