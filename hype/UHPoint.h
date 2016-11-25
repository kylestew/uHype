#ifndef UHPOINT_H
#define UHPOINT_H

#include "UHDrawable.h"

class UHPoint : public UHDrawable {
public:
  using UHDrawable::UHDrawable;
  void draw(struct CRGB *pixels, int width, int height) const override {
    int idx = x+(width*y);
    pixels[idx] = color;
  }
};

#endif
