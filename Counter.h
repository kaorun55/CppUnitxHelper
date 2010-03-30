#ifndef __COUNTER_H__
#define __COUNTER_H__

class Counter {
public:
  Counter();
 ~Counter();
  int value() const;
  void incr();
  void decr();
  void clear();

private:
  int value_;
};
#endif
