/***************************************************
  uHype - RGB LED Animation Library

  TODO: License info here

 ****************************************************/
#ifndef UHRECT_H
#define UHRECT_H

#include "UHDrawable.h"

class UHRect : public UHDrawable {
public:
  UHRect(float _x, float _y, int _width, int _height, CRGB _color)
    : x{_x}, y{_y}, width{_width}, height{_height}, color{_color}
  {}

  float x, y;
  int width, height;
  CRGB color;

  void draw(CRGB *leds, int rows, int columns) const override;
private:
};

#endif
