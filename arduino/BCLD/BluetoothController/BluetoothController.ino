// Arduino/Arduino communication pins definitions
static const int PARALELL_BUS[] = {4,5,6,7,8,9,A0,A1};
static const int BYTE_READY = 2;
static const int BYTE_RECEIVED = 3;

void sendByte(byte byteToSend);
byte packColor(byte r, byte g, byte b);

void setup() {
  Serial.begin(9600);

  // Arduino/Arduino communication pins setup
  for (int i = 0; i < 8; i++) pinMode(PARALELL_BUS[i], OUTPUT);
  pinMode(BYTE_READY, OUTPUT);
  pinMode(BYTE_RECEIVED, INPUT);

  digitalWrite(BYTE_READY, LOW);
}

void loop() {
  static byte rgb[3];
  for (int i = 0; i < 3; i++) {
    rgb[i] = random(0, 256);
  }

  for (int i = 0; i < 256; i++) {
    sendByte(0);  // cmd byte
    for (int c = 0; c < 3; c++) sendByte(rgb[c]); // color bytes
  }

  // SHOW()
  sendByte(1);  // cmd byte
  for (int c = 0; c < 3; c++) sendByte(1);

  for (int i = 0; i < 3; i++) {
    rgb[i] = random(0, 256);
  }
}

void sendByte(byte byteToSend) {
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

byte packColor(byte r, byte g, byte b) {
  byte color = 0;

  r = constrain(r, 0, 7);
  g = constrain(g, 0, 7);
  b = constrain(b, 0, 3);

  color = color | (r << 5);
  color = color | (g << 2);
  color = color | b;

  return color;
}