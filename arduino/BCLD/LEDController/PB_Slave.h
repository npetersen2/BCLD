#ifndef PB_SLAVE_H
#define PB_SLAVE_H

#include "LED_Constants.h"

class PB_Slave {

private:
  byte m_ledPosX;
  byte m_ledPosY;
  byte m_data[4];
  byte m_dataIndex;

public:
  PB_Slave();
  ~PB_Slave() {}

  void reset();

  bool byteAvailable() { return (digitalRead(BYTE_READY) == HIGH); }
  void readByte();

  bool hasBytes(int num) {
    if (m_dataIndex >= num) {
      m_dataIndex = 0;
      return true;
    } else {
      return false;
    }
  }

  byte ledPosX(bool increment) {
    if (increment) {
      if (m_ledPosX >= 15) {
        m_ledPosX = 0;
        return 15;
      } else {
        return m_ledPosX++;        
      }
    } else {
      return m_ledPosX;
    }
  }

  byte ledPosY(bool increment) {
    if (increment) {
      if (m_ledPosY >= 15) {
        m_ledPosY = 0;
        return 15;
      } else {
        return m_ledPosY++;        
      }
    } else {
      return m_ledPosY;
    }
  }

  byte command() { return m_data[0]; }
  byte r() { return m_data[1]; }
  byte g() { return m_data[2]; }
  byte b() { return m_data[3]; }
};

#endif