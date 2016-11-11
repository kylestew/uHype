#ifndef POINT_H
#define POINT_H

#include "Drawable.h"

class Point : public Drawable {
public:
  using Drawable::Drawable;
  void draw() const override {
    std::cout << "Point: (" << x << ", " << y << ")\n";
  }
};

#endif
