/*
 * SimpleAutoPtrTest.h
 */

#ifndef cppunit_tests_SimpleAutoPtrTest_h
#define cppunit_tests_SimpleAutoPtrTest_h

#include <cppunit/TestCase.h>
#include <cppunit/SimpleAutoPtr.h>

USING_NAMESPACE_CPPUNIT

class SimpleAutoPtrTest : public TestCase
{
  public:
	explicit SimpleAutoPtrTest(const char* name) : TestCase(name) {}
	virtual void setUp();
	void testDestroy();
	void testRelease();
	void testReset();
	static Test* suite();

  private:
	class Object {
	  public:
		explicit Object(SimpleAutoPtrTest* test, int id = 0);
		~Object();
		SimpleAutoPtrTest* getTest() const { return m_test; }
		int getID() const { return m_id; }
	  private:
		SimpleAutoPtrTest* m_test;
		int m_id;
	};
	typedef SIMPLE_AUTO_PTR(Object) ObjectAutoPtr;

  public:
	void addObject(const Object* object);
	void removeObject(const Object* object);

  private:
	cu_List m_objects;		// list<const Object*>
};

#endif /* !cppunit_tests_SimpleAutoPtrTest_h */
