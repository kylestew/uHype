#ifndef FASTLED_H
#define FASTLED_H

#include <iostream>

class CFastLED {
public:
  void clear() {}
};
CFastLED FastLED;


struct CRGB {
  union {
    struct {
      uint8_t r;
      uint8_t g;
      uint8_t b;
    };
    uint8_t raw[3];
  };

  // default constructor
  inline CRGB() : r(0), g(0), b(0) {}
  // R G B
  inline CRGB(uint8_t ir, uint8_t ig, uint8_t ib) : r(ir), g(ig), b(ib) {}
  // 0xRRGGBB
  inline CRGB(uint32_t colorcode)
    : r((colorcode >> 16) & 0xFF), g((colorcode >> 8) & 0xFF), b((colorcode >> 0) & 0xFF) {}
};

  // override cout stream for output
std::ostream& operator << (std::ostream &out, const CRGB &val) {
  out << val.r;
  return out;
}

// struct CHSV {
//   uint8_t raw[3];
// }

void fill_solid(struct CRGB *leds, int numToFill, const struct CRGB& color) {
  for(int i = 0; i < numToFill; i++) {
    leds[i] = color;
  }
}

#endif
