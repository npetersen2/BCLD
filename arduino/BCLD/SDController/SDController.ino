#include <SPI.h>
#include <SD.h>

#include "SD_Constants.h"
#include "SD_Card.h"
#include "PB_Master.h"

PB_Master pb_master = PB_Master(); // the Parallel Bus Master
SD_Card sd_card = SD_Card();

// runs once when Arduino turns on
void setup() {}

// called over and over again
void loop() {
  byte data[PB_NUM_DATA_LENGTH]; // storage for data from SD card

  if (sd_card.readBytes(data, PB_NUM_DATA_LENGTH)) {
    // not at the end of file...

    switch(data[0]) {
      case CMD_ADD_COLOR:
        pb_master.sendPixel(data[1], data[2], data[3]);
        break;

      case CMD_SHOW:
        pb_master.show();
        break;

      case CMD_FILL_SCREEN:
        pb_master.fillScreen(data[1], data[2], data[3]);
        break;

      case CMD_DELAY:
        delay(data[1]);
        break;

      case CMD_CLEAR:
        pb_master.clear();
        break;

      default:
        break;
    }
  } else {
    // end of file
    sd_card.seek(0); // go back to beginning;
    pb_master.clear(); // empty parallel bus
  }
}