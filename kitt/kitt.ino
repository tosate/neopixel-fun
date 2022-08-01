// Playing around with NeoPixels

#include <Adafruit_NeoPixel.h>

// Which pin oth the Arduino is connected to the NeoPixels?
int pin = 6;

// How many NeoPixels are attached to the Arduino?
int numPixels = 10;

// NeoPixel color format & data rate.
int pixelFormat = NEO_RGB + NEO_KHZ800;

// Rather than declaring the whole NeoPixel object here, we just create
// a pointer for one, which we'll then allocate later...
Adafruit_NeoPixel *pixels;

void setup() {
  pixels = new Adafruit_NeoPixel(numPixels, pin, pixelFormat);
  pixels->begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels->show();            // Turn OFF all pixels ASAP
  pixels->setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  // K.I.T.T.
  for(int i=0; i<5; i++) {
    kittScanner(255, 0, 0);
  }
  // K.A.R.R
  for(int i=0; i<5; i++) {
    kittScanner(255, 255, 0);
  }
  // Blue
  for(int i=0; i<5; i++) {
    kittScanner(0, 0, 255);
  }
}

void kittScanner(int r, int g, int b) {
  int center1 = numPixels / 2;
  while(center1 > 0) {
    resetAll();
    pixels->setPixelColor(center1, pixels->Color(r, g, b));
    pixels->setPixelColor(center1 + 1, pixels->Color(r, g, b));
    pixels->setPixelColor(center1 - 1, pixels->Color(r/2, g/2, b/2));
    pixels->setPixelColor(center1 + 2, pixels->Color(r/2, g/2, b/2));
    pixels->show();
    delay(50);
    center1--;
  }

  while(center1 < numPixels) {
    resetAll();
    pixels->setPixelColor(center1, pixels->Color(r, g, b));
    pixels->setPixelColor(center1 + 1, pixels->Color(r, g, b));
    pixels->setPixelColor(center1 - 1, pixels->Color(r/2, g/2, b/2));
    pixels->setPixelColor(center1 + 2, pixels->Color(r/2, g/2, b/2));
    pixels->show();
    delay(50);
    center1++;
  }

  while(center1 > numPixels / 2) {
    resetAll();
    pixels->setPixelColor(center1, pixels->Color(r, g, b));
    pixels->setPixelColor(center1 + 1, pixels->Color(r, g, b));
    pixels->setPixelColor(center1 - 1, pixels->Color(r/2, g/2, b/2));
    pixels->setPixelColor(center1 + 2, pixels->Color(r/2, g/2, b/2));
    pixels->show();
    delay(50);
    center1--;
  }
}

void resetAll() {
  for(int i=0; i<numPixels; i++) {
    pixels->setPixelColor(i, pixels->Color(0, 0, 0));
  }
}
