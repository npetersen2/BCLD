#include "PB_Master.h"

// PB_Master() is the constructor of the PB_Master class
// On instantiation, the class sets the pin modes for all communication pins  
PB_Master::PB_Master() {
  // Arduino/Arduino communication pins setup
  for (int i = 0; i < PB_NUM_DATA_PINS; i++) pinMode(PARALELL_BUS[i], OUTPUT);
  pinMode(BYTE_READY, OUTPUT);
  pinMode(BYTE_RECEIVED, INPUT);

  digitalWrite(BYTE_READY, LOW);
}

// This method, sendPackage(byte, byte, byte, byte), encapsulates the function, sendByte(byte)
// Data must be send in four wide byte chunks
// By encapsulating the sendByte(byte) function, this ensures the correct amount of bytes is transmitted
void PB_Master::sendPackage(byte data0, byte data1, byte data2, byte data3) {
  sendByte(data0);
  sendByte(data1);
  sendByte(data2);
  sendByte(data3);
}

// This method, sendByte(byte), takes one byte and transmits it across eight wires to a slave Arduino
// Each wire is one bit, thus eight wires must be used for data transmission
// Two extra wires are required for status of sending and receiving data
// BYTE_READY wire is used to signify that the PB_Master has pushed data to the eight data pins
// BYTE_RECEIVED wire is used for PB_Slave to acknowledge (ACK) it has processed data
void PB_Master::sendByte(byte byteToSend) {
  for (int i = 0; i < PB_NUM_DATA_PINS; i++) {
    if (byteToSend & 1) {
      digitalWrite(PARALELL_BUS[i], HIGH);
    } else {
      digitalWrite(PARALELL_BUS[i], LOW);
    }

    byteToSend = byteToSend >> 1;
  }

  digitalWrite(BYTE_READY, HIGH); // data ready...
  while (digitalRead(BYTE_RECEIVED) != HIGH); // wait for Display Controller ACK
  digitalWrite(BYTE_READY, LOW); // reset for next time
}