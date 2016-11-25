#ifndef UHDRAWABLE_H
#define UHDRAWABLE_H

#include "FastLED.h"

class UHDrawable {
public:
  UHDrawable(double x, double y, CRGB color) : x{x}, y{y}, color{color} {};
  virtual void draw(struct CRGB *pixels, int width, int height) const = 0;
protected:
  double x, y;
  CRGB color;
};

#endif
