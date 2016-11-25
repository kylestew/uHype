#ifndef UHYPE_H
#define UHYPE_H

#include "FastLED.h"

#include "UHDrawable.h"
#include "UHPoint.h"

#include "UHColorPool.h"

#include "UHOscillator.h"

class UHype {
public:
  UHype(int width, int height)
    : width{width}, height{height}, frameCount{0}, autoClear{true} {
    pixelCount = width * height;
    pixels = new CRGB[pixelCount];
    clear();
  }
  ~UHype() {
    delete[] pixels;

    // TODO: loop delete all drawables
  }

  void setBackground(CRGB _background) {
    background = _background;
  }

  void add(UHDrawable* drawable) {
    drawables[drawCount++] = drawable;
  }

  void add(UHOscillator* osc) {
    effectors[effectorCount++] = osc;
  }

  void update() {
    // TODO: run update on all effectors
    for (int i = 0; i < effectorCount; i++) {
      UHOscillator *osc = effectors[i];
      osc->update(timeDelta);
    }
  }

  void draw() {
    if (autoClear)
      clear();
    // else: fade

    for (int i = 0; i < drawCount; i++) {
      UHDrawable *drawable = drawables[i];
      drawable->draw(pixels, width, height);
    }

    std::cout << "Draw Frame: " << frameCount << std::endl;
    dumpBMP();
    frameCount++;
  }

  void delayFPS(int targetFPS) {}

private:
  int width, height;
  int pixelCount;
  struct CRGB *pixels;
  CRGB background;
  int frameCount;
  bool autoClear;

  // TODO: simplify?
  int drawCount = 0;
  UHDrawable **drawables = new UHDrawable*[100];

  int effectorCount = 0;
  UHOscillator **effectors = new UHOscillator*[10];

  void clear() {
    FastLED.clear();
    fill_solid(&(pixels[0]), pixelCount, background);
  }

  /*=== NON-ARDUINO ===*/
  void dumpBMP() {
    // draw bitmap to disk
    FILE *f;
    unsigned char *img = NULL;
    char filename[22];
    snprintf(filename, sizeof(char) * 22, "./output/out_%04d.bmp", frameCount);
    int filesize = 54 * 3*width*height; // 54 byte header + 3 bytes per pixel
    if (img)
      free(img);
    img = (unsigned char *)malloc(3*width*height);
    memset(img, 0, sizeof(3*width*height));

    // fill image with actual data
    int x, y;
    int r, g, b;
    for (int col = 0; col < width; ++col) { // scan left-to-right
      for (int row = 0; row < height; ++row) { // scan up-to-down
        // x=col; y=(height-1)-j; // drawing upside down
        x=col; y=row; // drawing upside down

        int idx = col+(width*row);
        r = pixels[idx].r;
        g = pixels[idx].g;
        b = pixels[idx].b;

        if (r>255) r = 255;
        if (g>255) g = 255;
        if (b>255) b = 255;
        img[(x+y*width)*3+2] = (unsigned char)(r);
        img[(x+y*width)*3+1] = (unsigned char)(g);
        img[(x+y*width)*3+0] = (unsigned char)(b);
      }
    }

    // BITMAPFILEHEADER (14 bytes)
    // BM [SIZE] 0 0 [OFFSET TO DATA]
    // 54 is the header size - offset always past that static size
    unsigned char bmpfileheader[14] = {'B', 'M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
    bmpfileheader[ 2] = (unsigned char)(filesize    );
    bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
    bmpfileheader[ 4] = (unsigned char)(filesize>>16);
    bmpfileheader[ 5] = (unsigned char)(filesize>>24);

    // BITMAPINFOHEADER (40 bytes)
    // [HEADER SIZE] [IMAGE WIDTH] [IMAGE HEIGHT] ...
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24, 0};
    bmpinfoheader[ 4] = (unsigned char)( width    );
    bmpinfoheader[ 5] = (unsigned char)( width>> 8);
    bmpinfoheader[ 6] = (unsigned char)( width>>16);
    bmpinfoheader[ 7] = (unsigned char)( width>>24);
    bmpinfoheader[ 8] = (unsigned char)(height    );
    bmpinfoheader[ 9] = (unsigned char)(height>> 8);
    bmpinfoheader[10] = (unsigned char)(height>>16);
    bmpinfoheader[11] = (unsigned char)(height>>24);

    f = fopen(filename, "wb");
    fwrite(bmpfileheader,1,14,f);
    fwrite(bmpinfoheader,1,40,f);
    unsigned char bmppad[3] = {0,0,0};
    for(int i=0; i<height; i++) {
      fwrite(img+(width*(height-i-1)*3),3,width,f);
      fwrite(bmppad,1,(4-(width*3)%4)%4,f); // need to pad out each line
    }
    fclose(f);
  }
};

#endif
