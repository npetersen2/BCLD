#include "PB_Master.h"

PB_Master::PB_Master() {
  // Arduino/Arduino communication pins setup
  for (int i = 0; i < 8; i++) pinMode(PARALELL_BUS[i], OUTPUT);
  pinMode(BYTE_READY, OUTPUT);
  pinMode(BYTE_RECEIVED, INPUT);

  digitalWrite(BYTE_READY, LOW);
}

void PB_Master::sendPackage(byte command, byte r, byte g, byte b) {
  sendByte(command);
  sendByte(r);
  sendByte(g);
  sendByte(b);
}

void PB_Master::sendByte(byte byteToSend) {
  for (int i = 0; i < 8; i++) {
    if (byteToSend & 1) {
      digitalWrite(PARALELL_BUS[i], HIGH);
    } else {
      digitalWrite(PARALELL_BUS[i], LOW);
    }

    byteToSend = byteToSend >> 1;
  }

  digitalWrite(BYTE_READY, HIGH);
  while (digitalRead(BYTE_RECEIVED) != HIGH); // wait for Display Controller ack
  digitalWrite(BYTE_READY, LOW);
}