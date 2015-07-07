#ifndef BT_CONSTANTS_H
#define BT_CONSTANTS_H

#include <Arduino.h>

// Arduino/Arduino communication pins definitions
static const int PARALELL_BUS[8] = {4,5,6,7,8,9,A0,A1};
static const int BYTE_READY = 2;
static const int BYTE_RECEIVED = 3;
static const int SD_CS = 10;

#endif;