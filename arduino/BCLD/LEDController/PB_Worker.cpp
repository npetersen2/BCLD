#include "PB_Worker.h"

// Constructor that sets pin modes for parallel bus
PB_Worker::PB_Worker() {
  // Arduino/Arduino communication pins setup
  for (int i = 0; i < PB_NUM_DATA_PINS; i++) pinMode(PIN_PARALLEL_BUS[i], INPUT);
  pinMode(PIN_BYTE_READY, INPUT);
  pinMode(PIN_BYTE_RECEIVED, OUTPUT);
  
  digitalWrite(PIN_BYTE_RECEIVED, LOW);

  reset();
}

// Method that sets member variables to original state
void PB_Worker::reset() {
  m_ledPosX = 0;
  m_ledPosY = 0;
  for (int i = 0; i < PB_NUM_DATA_LENGTH; i++) m_data[i] = 0;
  m_dataIndex = 0;    
}

// Method that reads one byte from PB_Master
// Uses eight, one bit pins for data transfer and two pins for transfer status
void PB_Worker::readByte() {
  byte inData = 0;
  
  for (int i = 0; i < PB_NUM_DATA_PINS; i++) {
    if (digitalRead(PIN_PARALLEL_BUS[i]) == HIGH) {
      inData += (1 << i);
    }
  }
  
  digitalWrite(PIN_BYTE_RECEIVED, HIGH);
  while (digitalRead(PIN_BYTE_READY) != LOW); // wait for SD Controller ACK
  digitalWrite(PIN_BYTE_RECEIVED, LOW);

  m_data[m_dataIndex++] = inData;
}