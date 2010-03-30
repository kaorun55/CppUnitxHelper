/*
 * SimpleStringTest.h
 */

#ifndef cppunit_tests_SimpleStringTest_h
#define cppunit_tests_SimpleStringTest_h

#include <cppunit/TestCase.h>
#include <cppunit/SimpleString.h>

USING_NAMESPACE_CPPUNIT

class SimpleStringTest : public TestCase
{
  public:
	explicit SimpleStringTest(const char* name) : TestCase(name) {}
	virtual void setUp() { m_string = "12345"; }
	void testCreate();
	void testAssign();
	void testIterator();
	void testAccessor();
	void testAppend();
	void testInsert();
	void testReplace();
	void testCopy();
	void testSubstr();
	void testCompare();
	void testResize();
	void testSwap();
	static Test* suite();

  private:
	SimpleString m_string;
};

#endif /* !cppunit_tests_SimpleStringTest_h */
