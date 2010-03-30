#define CPPUNIT_COMPATIBLE
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TestCaller.h>
USING_NAMESPACE_CPPUNIT
using namespace std;

#include "CounterTest.h"
class tmpCounterTest : public CounterTest
{
public:
	tmpCounterTest( const char* name ) : CounterTest( name ) {}
	static Test* suite()
	{
		TestSuite* suite = new TestSuite( "CounterTest");
		suite->addTest( new TEST_CALLER( CounterTest, test_init));
		suite->addTest( new TEST_CALLER( CounterTest, test_incr));
		suite->addTest( new TEST_CALLER( CounterTest, test_decr));
		suite->addTest( new TEST_CALLER( CounterTest, test_clear));
		return suite;
	}
};

#include "QuizTest.h"
class tmpQuizTest : public QuizTest
{
public:
	tmpQuizTest( const char* name ) : QuizTest( name ) {}
	static Test* suite()
	{
		TestSuite* suite = new TestSuite( "QuizTest");
		suite->addTest( new TEST_CALLER( QuizTest, testQuestion));
		suite->addTest( new TEST_CALLER( QuizTest, testAnswer));
		return suite;
	}
};

int main( int argc, char* argv[] )
{
	TestRunner runner;
	runner.addTest( "CounterTest", tmpCounterTest::suite() );
	runner.addTest( "QuizTest", tmpQuizTest::suite() );
	return runner.run( argc, argv );
}
