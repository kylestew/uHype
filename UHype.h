/***************************************************
  uHype - RGB LED Animation Library

  TODO: License info here

 ****************************************************/
#ifndef UHYPE_H
#define UHYPE_H

#include "FastLED.h"

#include "UHPixel.h"

class UHype {
public:
  UHype(int rows, int columns);

  void init();
  void brightness(uint8_t brightness); // 0-100
  void background(CRGB);
  void autoClear(boolean autoClear);
  void fade(uint8_t amount); // 0-100

  void add(UHPixel pixel);

  void draw();
  void delayFPS(int targetFPS);

private:
  struct CRGB *_leds;
  int _ledCount, _ledRows, _ledColumns;
  CRGB _background;
  boolean _autoClear;
  uint8_t _fade;

  UHPixel _pixel;

  void clear();
};

#endif // UHYPE_H
