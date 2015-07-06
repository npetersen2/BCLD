#include "Constants.h"
#include "PB_Master.h"

PB_Master pb_master = PB_Master();

void setup() {
  Serial.begin(9600);
}

void loop() {
  static byte rgb[3];
  for (int i = 0; i < 3; i++) rgb[i] = random(0, 256);



  pb_master.reset();
  pb_master.fillScreen(rgb[0], rgb[1], rgb[2]);
  // for (int i = 0; i < 256; i++) pb_master.sendPackage(0, rgb[0], rgb[1], rgb[2]);
  pb_master.show();



  for (int i = 0; i < 3; i++) {
    rgb[i] = random(0, 256);
  }
}