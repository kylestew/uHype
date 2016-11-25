#ifndef UHCOLORPOOL_H
#define UHCOLORPOOL_H

#include "FastLED.h"

class UHColorPool {
public:
  UHColorPool(CRGB colors[], int length)
    : colors{colors}, length{length} {
    srand(time(NULL));
    // srand(analogRead(0));
  }

  CRGB getColor() {
    return colors[rand() % length];
  }

private:
  CRGB *colors;
  int length;
};

#endif
