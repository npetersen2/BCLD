#ifndef PB_WORKER_H
#define PB_WORKER_H

#include "LED_Constants.h"

// Class that listens to a PB_Master and reads data
class PB_Worker {

private:
  byte m_ledPosX; // current X position of incoming data
  byte m_ledPosY; // current Y position of incoming data
  byte m_data[PB_NUM_DATA_LENGTH]; // incoming data buffer
  byte m_dataIndex; // current data index (range is 0-3)

public:
  PB_Worker();
  ~PB_Worker() {}

  // Method that resets PB_Worker member variables
  void reset();

  // Method that returns true if PB_Master sent a byte
  bool byteAvailable() { return (digitalRead(PIN_BYTE_READY) == HIGH); }
  
  // Method that reads the incoming byte from PB_Master into class
  void readByte();

  // Method that resets m_dataIndex if class has received the wanted number of bytes
  bool hasBytes(int num) {
    if (m_dataIndex >= num) {
      m_dataIndex = 0;
      return true;
    } else {
      return false;
    }
  }

  // Method that returns ledPosX and optionally increments member variable
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

  // Method that returns ledPosY and optionally increments member variable
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

  // Methods that return parts of data buffer
  byte command() { return m_data[0]; }
  byte r() { return m_data[1]; }
  byte g() { return m_data[2]; }
  byte b() { return m_data[3]; }
};

#endif