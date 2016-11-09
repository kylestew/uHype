/***************************************************
  uHype - RGB LED Animation Library

  TODO: License info here

 ****************************************************/
#ifndef UHLINE_H
#define UHLINE_H

#include "UHDrawable.h"

class UHLine : UHDrawable {
public:
  UHLine(float x0, float y0, CRGB _color);

  float x0, y0, x1, y1;
  CRGB color;

private:

};

#endif
