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

void UHype::add(UHDrawable* drawable) {
  // store pointer
  _drawables[drawCount++] = drawable;


  // TODO: make dynamic
  // create new larger array
  // UHDrawable *temp = new UHDrawable[drawCount + 1];
  //
  // // copy old array into temp
  // if (_drawables != nullptr) {
  //   memcpy(temp, _drawables, drawCount * sizeof(UHDrawable));
  // }
  //
  // // insert new item
  // temp[drawCount] = pixel;
  //
  // // delete old array
  // delete[] _drawables;
  //
  // // set temp as new array
  // _drawables = temp;
  // drawCount++;
}

void UHype::draw() {
  if (_autoClear) {
    clear();
  } else {
    // TODO: fade
  }

  // perform draw on all drawables
  // AUTO?
  for (int i = 0; i < drawCount; i++) {
    // why the '&'???
    UHDrawable *drawable = _drawables[i];

    // is it onscreen?
  //   if (pixel.x < _ledRows + 1 && pixel.y < _ledColumns + 1) {
  //     int idx = (pixel.y - 1) * _ledColumns + (pixel.x - 1);
  //     _leds[idx] = pixel.color;
  //   }

    drawable->draw(_leds, _ledRows, _ledColumns);
  }

  FastLED.show();
}

void UHype::delayFPS(int targetFPS) {
  // TODO: temperal dithering delay
  FastLED.delay(20); // TODO: calculation and timing loop
}
