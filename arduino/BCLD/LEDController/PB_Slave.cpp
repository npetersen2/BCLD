#include "PB_Slave.h"

PB_Slave::PB_Slave() {
  // Arduino/Arduino communication pins setup
  for (int i = 0; i < 8; i++) pinMode(PARALELL_BUS[i], INPUT);
  pinMode(BYTE_READY, INPUT);
  pinMode(BYTE_RECEIVED, OUTPUT);
  
  digitalWrite(BYTE_RECEIVED, LOW);

  reset();
}

void PB_Slave::reset() {
  m_ledPosX = 0;
  m_ledPosY = 0;
  for (int i = 0; i < 4; i++) m_data[i] = 0;
  m_dataIndex = 0;    
}

void PB_Slave::readByte() {
  byte inData = 0;
  
  for (int i = 0; i < 8; i++) {
    if (digitalRead(PARALELL_BUS[i]) == HIGH) {
      inData += (1 << i);
    }
  }
  
  digitalWrite(BYTE_RECEIVED, HIGH);
  while (digitalRead(BYTE_READY) != LOW); // wait for Bluetooth Controller ack
  digitalWrite(BYTE_RECEIVED, LOW);

  m_data[m_dataIndex++] = inData;
}