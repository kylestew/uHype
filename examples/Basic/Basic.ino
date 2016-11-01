#include <UHype.h>

/* Pixels */
// uint8_t NEOPIXEL_PIN = 7;
UHype hype(8, 8); // geometry: 8 x 8

void setup() {
  hype.init();
  hype.brightness(33);
  hype.background(0x000000);
  hype.autoClear(true);
  // hype.fade(2);

  UHPixel pixel(3.0, 2.0, 0xff0000);
  hype.add(pixel);
}

void loop() {
  hype.draw();
  hype.delayFPS(30);
}
