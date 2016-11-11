#ifndef DRAWABLE_H
#define DRAWABLE_H

class Drawable {
public:
  Drawable(float x, float y) : x{x}, y{y} {};
  virtual void draw() const = 0;
protected:
  float x, y;
};

#endif
