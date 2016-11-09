/***************************************************
  uHype - RGB LED Animation Library
 ****************************************************/
#ifndef UHCOLORPOOL_H
#define UHCOLORPOOL_H

#include "FastLED.h"

class UHColorPool {
public:
  UHColorPool(CRGB colors[], int length) {
    _colors = colors;
    _length = length;

    srand(analogRead(0));
  }

  CRGB getColor() {
    return _colors[rand() % _length];
  }

private:
  CRGB *_colors;
  int _length;
};

#endif
