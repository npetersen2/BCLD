#include "Constants.h"

//#include <Adafruit_GFX.h>
//#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#include "Receiver.h"

// numOfPixels, pin, constants
Adafruit_NeoPixel strip = Adafruit_NeoPixel(256, 10, NEO_GRB + NEO_KHZ800);

Receiver receiver = Receiver();

void setup() {
  Serial.begin(9600);
  
  strip.begin();
  strip.setBrightness(255);
  strip.show();
}

void loop() {
  if (receiver.byteAvailable()) {
    if (receiver.readByte()) {
      // done with 4-byte chunk

      switch (receiver.command()) {
        case 0: // SHOW()
          strip.show();
          receiver.reset();
          break;

        case 1: // ADD COLOR()
          strip.setPixelColor(receiver.ledPos(true), receiver.r(), receiver.g(), receiver.b());
          break;

        case 2: // RESET()
          strip.clear();
          break;

        default:
          break;
      }
    }
  }
}