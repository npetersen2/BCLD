#ifndef PB_SD_CARD_H
#define PB_SD_CARD_H

#include <SPI.h>
#include <SD.h>
#include "BT_Constants.h"

class SD_Card {

private:
  File m_file;

public:
  SD_Card();
  ~SD_Card();

  bool readBytes(byte bytes[], int length);
  void seek(int num) { m_file.seek(num); }

};

#endif;