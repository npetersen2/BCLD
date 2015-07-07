#include <Adafruit_NeoPixel.h>
#include "LED_Constants.h"
#include "PB_Slave.h"

Adafruit_NeoPixel strip = Adafruit_NeoPixel(256, 10, NEO_GRB + NEO_KHZ800); // numOfPixels, pin, constants
PB_Slave pb_slave = PB_Slave();

byte getIndex(byte x, byte y);

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
          strip.setPixelColor(getIndex(pb_slave.ledPosX(false), pb_slave.ledPosY(false)), pb_slave.r(), pb_slave.g(), pb_slave.b());
          if (pb_slave.ledPosX(true) >= 15) pb_slave.ledPosY(true);
          break;

        case 1: // SHOW()
          strip.show();
          pb_slave.reset();
          break;

        case 2: // FILL SCREEN
          for (int i = 0; i < 256; i++) strip.setPixelColor(i, pb_slave.r(), pb_slave.g(), pb_slave.b());
          break;

        case 255: // CLEAR()
          strip.clear();
          pb_slave.reset();
          break;

        default:
          break;
      }
    }
  }
}

byte getIndex(byte x, byte y) {
  byte index;

  if (y == 0) {
    index = 15 - x;
  } else if (y % 2 != 0) {
    index = y * 16 + x;
  } else {
    index = (y * 16 + 15) - x;
  }

  return index;
}