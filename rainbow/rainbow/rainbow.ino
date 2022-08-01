
#include <Adafruit_NeoPixel.h>
#include "rainbow.h"
// which pin on the Arduino is connected to the NeoPixels?
int pin = 6;

// How many NeoPixels are attached to the Arduino?
int numPixels = 10;

// NeoPixel color format & data rate
int pixelFormat = NEO_RGB + NEO_KHZ800;

// Rather than declaring the whole NeoPixel object here, we just create
// a pointer for one, which we'll then allocate later...
Adafruit_NeoPixel *pixels;

void setup() {
  pixels = new Adafruit_NeoPixel(numPixels, pin, pixelFormat);
  pixels->begin();          // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels->show();           // Torn OFF all pixels ASAP
  pixels->setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void calculateColor(int angle, pixelColor *pixel) {
  if (angle<60) {
    pixel->red = 255;
    pixel->green = round(angle*4.25-0.01);
    pixel->blue = 0;
  } else if (angle<120) {
    pixel->red = round((120-angle)*4.25-0.01);
    pixel->green = 255;
    pixel->blue = 0;
  } else if (angle<180) {
    pixel->red = 0;
    pixel->green = 255;
    pixel->blue = round((angle-120)*4.25-0.01);
  } else if (angle<240) {
    pixel->red = 0;
    pixel->green = round((240-angle)*4.25-0.01);
    pixel->blue = 255;
  } else if (angle<300) {
    pixel->red = round((angle-240)*4.25-0.01);
    pixel->green = 0;
    pixel->blue = 255;
  } else {
    pixel->red = 255;
    pixel->green = 0;
    pixel->blue = round((360-angle)*4.25-0.01);
  }
}

void loop() {
  int i = 0;
  
  pixelColor color;
  while(true) {
    resetAll();
    for(int i=0; i<numPixels; i++) {
      calculateColor(i * 36 % 360, &color);
      pixels->setPixelColor(i, pixels->Color(color.red, color.green, color.blue));
    }
    pixels->show();
    delay(1000);
  }
}

void resetAll() {
  for(int i=0; i<numPixels; i++) {
    pixels->setPixelColor(i, pixels->Color(0, 0, 0));
  }
}
