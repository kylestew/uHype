#include <iostream>
#include "Hype.h"
using namespace std;

const int ANIM_FPS = 30;

const int WIDTH = 320;
const int HEIGHT = 240;
Hype hype(WIDTH, HEIGHT);

int main() {
  hype.setBackground(0xff2299);
  // hype.autoClear();

  // hype.add(new Point(2, 3));
  // hype.add(new Rect(10, 20, 30, 40));
  // hype.add(Circle(5, 15, 12));
  // TODO: line

  // TODO: render loop
  const int LOOPS = 4;
  for (int i = 0; i < LOOPS; ++i) {
    hype.draw();
    hype.delayFPS(ANIM_FPS);
  }

  return 0;
}
