#include "SPI.h"
#include "TFT_22_ILI9225.h"

#define TFT_RST 8
#define TFT_RS  9
#define TFT_CS  10  // SS
#define TFT_SDI 11  // MOSI
#define TFT_CLK 13  // SCK
#define TFT_LED 0

TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_LED);


void setup() {
  tft.begin();
  tft.setOrientation(ILI9225_VERTICAL_WINDOW_ADDR2);
  Serial.begin(9600);
}


void loop() {
  tft.drawRectangle(0, 0, tft.maxX() - 1, tft.maxY() - 1, COLOR_WHITE);
  tft.setFont(Terminal6x8);
  tft.drawText(ILI9225_LCD_WIDTH/2, ILI9225_LCD_HEIGHT/2.5, "hello!");
  delay(1000);    
}
