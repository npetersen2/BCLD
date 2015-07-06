#ifndef PB_SLAVE_H
#define PB_SLAVE_H

#include "Constants.h"

class PB_Slave {

private:
  byte m_ledPos;
  byte m_data[4];
  byte m_dataIndex;

public:
  PB_Slave();
  ~PB_Slave() {}

  void reset();

  bool byteAvailable() { return (digitalRead(BYTE_READY) == HIGH); }
  void readByte();

  bool hasFourBytes() {
    if (m_dataIndex >= 4) {
      m_dataIndex = 0;
      return true;
    } else {
      return false;
    }
  }

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