#ifndef UHOSCILLATOR_H
#define UHOSCILLATOR_H

#include "FastLED.h"

class UHOscillator {
public:
  UHOscillator()
    : target(target) {
  }

private:
  UHDrawable* target;

  //??? mode - sin/cos/tan/quadratic/???
  // how to declare the effected property?
  double frequency;
  double phase; // starting angle allows specific starting point in oscillation
  double min;
  double max;
};

#endif
