#include "Counter.h"

Counter::Counter() : value_(0) {
}

Counter::~Counter() {}

int Counter::value() const {
  return value_;
}

void Counter::incr() {
  ++value_;
}

void Counter::decr() {
  --value_;
}

void Counter::clear() {
  value_ = 0;
}
