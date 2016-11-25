#include <iostream>
#include "UHype.h"
using namespace std;

const int ANIM_FPS = 30;
const int PIXELS_WIDTH = 8;
const int PIXELS_HEIGHT = 8;
UHype hype(PIXELS_WIDTH, PIXELS_HEIGHT);

int main() {
  hype.setBackground(0x000000);

  // build a color palette
  CRGB colorList[] = {0xFFFFFF, 0xF7F7F7, 0xECECEC, 0x333333, 0x0095a8, 0x00616f, 0xFF3300, 0xFF6600};
  UHColorPool colors(colorList, sizeof(colorList)/sizeof(colorList[0]));

  // create line of points
  // for (int i = 0; i < PIXELS_WIDTH; i++) {
  //   hype.add(new UHPoint(i, 0.0, colors.getColor()));
  // }

  UHPoint point = new UHPoint(0.0, 0.0, colors.getColor());
  hype.add(point);
  hype.add(new UHOscillator(point));

  // render some test frames
  const int LOOPS = 1;
  for (int i = 0; i < LOOPS; ++i) {
    hype.update();
    hype.draw();
    hype.delayFPS(ANIM_FPS);
  }

  return 0;
}
