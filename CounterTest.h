#ifndef __COUNTERTEST_H__
#define __COUNTERTEST_H__

#include "Counter.h"

class CounterTest : public TestCase
{
public:

    // いつもきまった書き方のコンストラクタ
    CounterTest( const char* name ) : TestCase( name ) {}

    void setUp() {
      // 前準備
    }

    void tearDown() {
      // 後始末
    }

    ////////////// TEST CASES //////////////////

    void test_init() {
      Counter c;
      assertEquals( 0, c.value() );
    }

    void test_incr() {
      Counter c;
      assertEquals( 0, c.value() );
      c.incr();
      assertEquals( 1, c.value() );
      c.incr();
      assertEquals( 2, c.value() );
    }

    void test_decr() {
      Counter c;
      assertEquals( 0, c.value() );
      c.decr();
      assertEquals( -1, c.value() );
      c.decr();
      assertEquals( -2, c.value() );
    }

    void test_clear() {
      Counter c;
      assertEquals( 0, c.value() );
      c.incr();
      assertEquals( 1, c.value() );
      c.clear();
      assertEquals( 0, c.value() );
    }

};

#endif
