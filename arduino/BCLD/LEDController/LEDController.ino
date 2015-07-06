#include "Constants.h"

//#include <Adafruit_GFX.h>
//#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#include "PB_Slave.h"

// numOfPixels, pin, constants
Adafruit_NeoPixel strip = Adafruit_NeoPixel(256, 10, NEO_GRB + NEO_KHZ800);

PB_Slave pb_slave = PB_Slave();

void setup() {
  Serial.begin(9600);
  
  strip.begin();
  strip.setBrightness(255);
  strip.show();
}

void loop() {
  if (pb_slave.byteAvailable()) {
    pb_slave.readByte();

    if (pb_slave.hasBytes(4)) {
      // done with 4-byte chunk

      switch (pb_slave.command()) {
        case 0: // ADD COLOR()
          strip.setPixelColor(pb_slave.ledPos(true), pb_slave.r(), pb_slave.g(), pb_slave.b());
          break;

        case 1: // SHOW()
          strip.show();
          pb_slave.reset();
          break;

        case 2: // FILL SCREEN
          for (int i = 0; i < 256; i++) strip.setPixelColor(i, pb_slave.r(), pb_slave.g(), pb_slave.b());
          break;

        case 255: // RESET()
          strip.clear();
          pb_slave.reset();
          break;

        default:
          break;
      }
    }
  }
}