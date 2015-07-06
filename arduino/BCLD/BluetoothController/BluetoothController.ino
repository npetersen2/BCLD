#include "Constants.h"
#include "PB_Master.h"

PB_Master pb_master = PB_Master();

void setup() {
  Serial.begin(9600);
}

void loop() {

  static byte r = 30;
  static byte g = 178;
  static byte b = 244;

  pb_master.clear();
  //pb_master.fillScreen(r, g, b);
  for (int i = 0; i < 256; i++) pb_master.sendPackage(0, r * .25, g * .25, b * .25);
  pb_master.show();

  r += 100;
  g += 200;
  b += 300;

  /*
  static int counter = 0;
  static unsigned long start = millis();
  static unsigned long end = start + 10000; // 10 sec later
  if (millis() > end) {
    Serial.print("Frames in last 10 sec: ");
    Serial.println(counter);
    counter = 0;

    start = millis();
    end = start + 10000;
  }
  counter++;
  */
}