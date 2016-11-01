/***************************************************
  uHype - RGB LED Animation Library

  TODO: License info here

 ****************************************************/
#ifndef UHPIXEL_H
#define UHPIXEL_H

#include "FastLED.h"

class UHPixel {
public:
  UHPixel();
  UHPixel(float _x, float _y, CRGB _color);

  float x, y;
  CRGB color;

private:

};

#endif // UHPIXEL_H
