#ifndef PB_MASTER_H
#define PB_MASTER_H

#include "BT_Constants.h"

class PB_Master {

private:

public:
  PB_Master();
  ~PB_Master() {}

  void show() { sendPackage(1, 0, 0, 0); }
  void clear() { sendPackage(255, 0, 0, 0); }
  void sendPixel(byte r, byte g, byte b) { sendPackage(0, r, g, b); }
  void fillScreen(byte r, byte g, byte b) { sendPackage(2, r, g, b); }

  void sendPackage(byte command, byte r, byte g, byte b);

  void sendByte(byte byteToSend);
};

#endif;