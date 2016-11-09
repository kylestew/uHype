/***************************************************
  uHype - RGB LED Animation Library
 ****************************************************/
#ifndef UHDRAWABLE_H
#define UHDRAWABLE_H

#include "FastLED.h"

class UHDrawable {
public:
  virtual void draw(CRGB *leds, int rows, int columns) const = 0;
protected:
};

#endif
