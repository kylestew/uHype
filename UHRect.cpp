#include "UHRect.h"

void UHRect::draw(CRGB *leds, int rows, int columns) const {
  // single dot
  // TODO: rect calculation with proper clipping
  int idx = (y - 1) * columns + (x - 1);
  leds[idx] = color;
}
