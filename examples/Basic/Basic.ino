#include <UHype.h>

/* Pixels */
// uint8_t NEOPIXEL_PIN = 7;
const int PIXELS_WIDTH = 8; // geometry: 8 x 8
const int PIXELS_HEIGHT = 8;
UHype hype(PIXELS_WIDTH, PIXELS_HEIGHT);

void setup() {
  hype.init();
  hype.brightness(33);
  hype.background(0x000000);


  // build a color palette
  CRGB colorList[] = {0xFFFFFF, 0xF7F7F7, 0xECECEC, 0x333333, 0x0095a8, 0x00616f, 0xFF3300, 0xFF6600};
  UHColorPool colors(colorList, sizeof(colorList)/sizeof(colorList[0]));

  // create line of pixels
  for (int i = 0; i < PIXELS_WIDTH; i++) {
    hype.add(new UHRect(i + 1, 1.0, 1, 1, colors.getColor()));
  }
}

void loop() {


  // new HOscillator()
  //   .target(pixel)
  //   .property(Y)
  //   .range(0, height)
  //   .freq(2) // Hz
  //   .phase()


  hype.draw();
  hype.delayFPS(30);
}
