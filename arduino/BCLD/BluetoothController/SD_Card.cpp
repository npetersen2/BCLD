#include "SD_Card.h"

SD_Card::SD_Card() {
  pinMode(SD_CS, OUTPUT); // CS for SD library
  SD.begin(SD_CS);
  
  m_file = SD.open("data.txt");
}

SD_Card::~SD_Card() {
  m_file.close();
}

bool SD_Card::readBytes(byte bytes[], int length) {
  for (int i = 0; i < length; i++) {
    if (m_file.available() > 0) {
      bytes[i] = m_file.read();
    } else {
      return false;
    }
  }
}