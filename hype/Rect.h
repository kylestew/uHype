#ifndef RECT_H
#define RECT_H

#include "Drawable.h"

class Rect : public Drawable {
public:
  Rect(float x, float y, float width, float height)
    : Drawable(x, y), width{width}, height{height} {}
  void draw() const override {
    std::cout << "Rectangle: (" << x << ", " << y << ", " << width << ", " << height << ")\n";
  }
private:
  float width, height;
};

#endif
