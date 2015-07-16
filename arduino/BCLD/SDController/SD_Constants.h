#ifndef SD_CONSTANTS_H
#define SD_CONSTANTS_H

#include <Arduino.h> // needed for using A0 and A1

// Arduino/Arduino communication pins definitions
static const int PB_NUM_DATA_PINS = 8;
static const int PB_NUM_DATA_LENGTH = 4;

static const int PARALELL_BUS[PB_NUM_DATA_PINS] = {4, 5, 6, 7, 8, 9, A0, A1};
static const int BYTE_READY = 2;
static const int BYTE_RECEIVED = 3;

// Arduino/Arduino communication commands
static const int CMD_ADD_COLOR = 0;
static const int CMD_SHOW = 1;
static const int CMD_FILL_SCREEN = 2;
static const int CMD_DELAY = 3;
static const int CMD_CLEAR = 255;

// SD card pin definitions
static const int SD_CS = 10;
static const char SD_FILE_NAME[] = "data.txt";

#endif;
