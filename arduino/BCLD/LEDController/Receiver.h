#ifndef RECEIVER_H
#define RECEIVER_H

#include "Constants.h"

class Receiver {

private:
  byte m_ledPos;
  byte m_data[4];
  byte m_dataIndex;

public:
  Receiver();
  ~Receiver() {}

  void reset();

  bool byteAvailable() { return (digitalRead(BYTE_READY) == HIGH); }
  bool readByte();

  byte ledPos(bool increment) {
    if (increment) {
      return m_ledPos++;
    } else {
      return m_ledPos;
    }
  }

  byte command() { return m_data[0]; }
  byte r() { return m_data[1]; }
  byte g() { return m_data[2]; }
  byte b() { return m_data[3]; }
};

#endif