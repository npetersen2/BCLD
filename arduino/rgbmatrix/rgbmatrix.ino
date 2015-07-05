#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#include <avr/pgmspace.h>

// Color definitions
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0
#define WHITE    0xFFFF

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(16, 16, 5, NEO_MATRIX_ROWS + NEO_MATRIX_RIGHT + NEO_MATRIX_TOP + NEO_MATRIX_ZIGZAG + NEO_GRB + NEO_KHZ800);

#define HEADER_PIXEL(data,pixel) {\
uint8_t d0 = pgm_read_byte_near(data + 0), d1 = pgm_read_byte_near(data + 1), d2 = pgm_read_byte_near(data + 2), d3 = pgm_read_byte_near(data + 3);\
pixel[0] = (((d0 - 33) << 2) | ((d1 - 33) >> 4)); \
pixel[1] = ((((d1 - 33) & 0xF) << 4) | ((d2 - 33) >> 2)); \
pixel[2] = ((((d2 - 33) & 0x3) << 6) | ((d3 - 33))); \
data += 4; \
}

//#define EMOJI_PURPLE_DUDE
//#define EMOJI_SMILEY
//#define EMOJI_EARTH
//#define EMOJI_THUMBS_UP
//#define EMOJI_WOMAN
//#define EMOJI_100
//#define PIXMAP_HULK
#define PIXMAP_MARIO
//#define PIXMAP_GRADIENT

#include "designs.h"


void setup() {  
  matrix.begin();
  matrix.setRotation(3);
  matrix.setBrightness(255);
  matrix.fillScreen(BLACK);
  matrix.show(); 
  
  
  //return;
  
  
  char* x = (char*)header_data;
  
  for (int row = 0; row < 16; row++) {
    for (int col = 0; col < 16; col++) {
      uint8_t p[3];
      HEADER_PIXEL(x, p);
      matrix.drawPixel(row, col, matrix.Color(p[0], p[1], p[2]));
    }
  }
  
  matrix.show();
}

void loop() {
  /*
  // expanding squares pattern
  for (int i = 0; i <= 7; i++) {
    int ii = 7 - i;
    matrix.fillScreen(BLACK);
    matrix.drawRect(ii, ii, 16-(2*ii), 16-(2*ii), WHITE);
    matrix.show();
    
    delay(10);
  }
  */
  
  /*
  // bouncing ball pattern
  #define randDelta() (float)random(8,12) / 10.0
  #define round_int(d) floor(d + 0.5)

  static float ballPosX = random(0, 16);
  static float ballPosY = random(0, 16);
  static float deltaX = randDelta();
  static float deltaY = randDelta();
  static int signX = (random(0, 2) ? -1 : 1);
  static int signY = (random(0, 2) ? -1 : 1);
  
  matrix.drawPixel(round_int(ballPosX - signX*deltaX), round_int(ballPosY - signY*deltaY), BLACK); // clear previous position
  matrix.drawPixel(round_int(ballPosX), round_int(ballPosY), BLUE);
  matrix.show();
  
  // move ball to next spot
  if (ballPosX + signX*deltaX > 15 || ballPosX + signX*deltaX < 0) signX = -signX; deltaX = randDelta();
  if (ballPosY + signY*deltaY > 15 || ballPosY + signY*deltaY < 0) signY = -signY; deltaY = randDelta();
  ballPosX += signX*deltaX;
  ballPosY += signY*deltaY;
  
  delay(2);
  */
}
