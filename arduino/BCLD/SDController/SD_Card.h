#ifndef PB_SD_CARD_H
#define PB_SD_CARD_H

#include <SPI.h>
#include <SD.h>
#include "SD_Constants.h"


// Class that encapsulates the SD library
class SD_Card {

private:
  File m_file; // main data.txt file

public:
  SD_Card();
  ~SD_Card();


  // reads length number of bytes into bytes
  bool readBytes(byte bytes[], int length);


  // seeks file reading position
  void seek(int num) { m_file.seek(num); }

};

#endif;