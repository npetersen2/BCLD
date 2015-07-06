#ifndef PB_MASTER_H
#define PB_MASTER_H

#include "Constants.h"

class PB_Master {

private:

public:
  PB_Master();
  ~PB_Master() {}

  void show();
  void reset();
  void fillScreen(byte r, byte g, byte b);

  void sendPackage(byte command, byte r, byte g, byte b);

  void sendByte(byte byteToSend);
};

#endif;