#ifndef PB_MASTER_H
#define PB_MASTER_H

#include "SD_Constants.h"

// Class that serves as Parallel Bus Master
class PB_Master {

private:
  // sends four bytes to PB_Slave Arduino
  void sendPackage(byte command, byte r, byte g, byte b);

  // sends one byte to PB_Slave Arduino
  void sendByte(byte byteToSend);

public:
  PB_Master();
  ~PB_Master() {}

  // sends the "show" command to the PB_Slave Arduino.
  void show() { sendPackage(CMD_SHOW, 0, 0, 0); }

  // sends the "clear" command to the PB_Slave Arduino.
  void clear() { sendPackage(CMD_CLEAR, 0, 0, 0); }

  // sends one pixel of data to the PB_Slave Arduino.
  void sendPixel(byte r, byte g, byte b) { sendPackage(CMD_ADD_COLOR, r, g, b); }

  // sends command to fill screen to PB_Slave Arduino
  void fillScreen(byte r, byte g, byte b) { sendPackage(CMD_FILL_SCREEN, r, g, b); }
};

#endif;