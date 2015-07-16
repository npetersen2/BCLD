#include <Adafruit_NeoPixel.h>
#include "LED_Constants.h"
#include "PB_Worker.h"

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PANEL_NUM_PIXELS, PANEL_PIN, NEO_GRB + NEO_KHZ800);
PB_Worker pb_worker = PB_Worker();


// since LED matrix is wired in a zigzag, this function converts coordinates into absolute position on strip
byte getIndex(byte x, byte y);


// called once when Arduino turns on
void setup() {
  strip.begin();
  strip.setBrightness(255); // 0 to 255, 255 full brightness
  strip.show();
}


// called over and over again
void loop() {
  if (pb_worker.byteAvailable()) {
    pb_worker.readByte();

    if (pb_worker.hasBytes(PB_NUM_DATA_LENGTH)) {
      // done with 4-byte chunk

      switch (pb_worker.command()) {
        case CMD_ADD_COLOR:
          strip.setPixelColor(getIndex(pb_worker.ledPosX(false),
                                pb_worker.ledPosY(false)),
                                pb_worker.r(),
                                pb_worker.g(),
                                pb_worker.b());
          if (pb_worker.ledPosX(true) >= PANEL_WIDTH - 1) {
            pb_worker.ledPosY(true); // increment y-pos at the end of a row
          }
          break;

        case CMD_SHOW:
          strip.show();
          pb_worker.reset();
          break;

        case CMD_FILL_SCREEN:
          for (int i = 0; i < PANEL_NUM_PIXELS; i++) {
            strip.setPixelColor(i, pb_worker.r(), pb_worker.g(), pb_worker.b());
          }
          break;

        case CMD_CLEAR:
          strip.clear();
          pb_worker.reset();
          break;

        default:
          break;
      }
    }
  }
}

// This function takes a coordinate (x,y) and maps it to the corresponding position on the matrix LED string
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