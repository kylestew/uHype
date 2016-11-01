#include "UHype.h"

UHype::UHype(int rows, int columns) {
  _background = 0x000000;
  _autoClear = true;
  _fade = 0;
  _ledRows = rows;
  _ledColumns = columns;
  _ledCount = _ledRows * _ledColumns;
  _leds = new CRGB[_ledCount];
}

void UHype::init() {
  // TODO: dynamic pin setting
  FastLED.addLeds<NEOPIXEL, 7>(_leds, _ledCount);
}

void UHype::brightness(uint8_t brightness) {
  // 0-100 --> 0-255
  FastLED.setBrightness((brightness/100.0) * 255);
}

void UHype::background(CRGB background) {
  _background = background;
}

void UHype::autoClear(boolean autoClear) {
  _autoClear = autoClear;
}

void UHype::fade(uint8_t amount) {
  _fade = amount;
}

void UHype::clear() {
  FastLED.clear();
  fill_solid(&(_leds[0]), _ledCount, _background);
}

void UHype::add(UHPixel pixel) {
  _pixel = pixel;
}

void UHype::draw() {
  if (_autoClear) {
    clear();
  } else {
    // TODO: fade
  }

  // is pixel onscreen?
  if (_pixel.x < _ledRows && _pixel.y < _ledColumns) {
    int idx = (_pixel.y - 1) * _ledColumns + (_pixel.x - 1);
    _leds[idx] = _pixel.color;
  }

  FastLED.show();
}

void UHype::delayFPS(int targetFPS) {
  // TODO: temperal dithering delay
  FastLED.delay(20); // TODO: calculation and timing loop
}
