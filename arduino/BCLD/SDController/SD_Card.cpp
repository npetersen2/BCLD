#include "SD_Card.h"

// SD_Card() is the constructor of the SD_Card class
// On instantiation, the class sets the pin modes SD card communication, starts SD card comm., and opens a file 
SD_Card::SD_Card() {
  pinMode(SD_CS, OUTPUT); // CS for SD library
  SD.begin(SD_CS);
  
  m_file = SD.open(SD_FILE_NAME, FILE_READ);
}

SD_Card::~SD_Card() {
  m_file.close();
}

// This method, readBytes(byte[], int), reads a variable amount of bytes from m_file into the supplied buffer
// It returns false at the end of the file
bool SD_Card::readBytes(byte bytes[], int length) {
  for (int i = 0; i < length; i++) {
    if (m_file.available() > 0) {
      bytes[i] = m_file.read();
    } else {
      return false;
    }
  }
}