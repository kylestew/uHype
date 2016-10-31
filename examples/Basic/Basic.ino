#include <UHype.h>

/* Pixels */
const int NEOPIXEL_PIN = 11;
const int NEOPIXEL_COUNT = 40;

UHype hype;

void setup() {
  hype.init(NEOPIXEL, NEOPIXEL_PIN, NEOPIXEL_COUNT);
  //.background(0, 0, 0).autoClear(false).fade(2);
  // hype.setBrightness();


  // Pixel pixel = new UHPixel();
  // pixel.position(0, 25);
  // hype.add(pixel);


}

void loop() {
  hype.draw();
}
