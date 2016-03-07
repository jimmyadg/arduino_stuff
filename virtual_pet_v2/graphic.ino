void gameGraphic() {
  String outPutPot = String(potState, DEC);
  String outPutHealth = String(health, DEC);
  String outPutHappy = String(happy, DEC);

  if (potState <= 4) {
    if (happy <= 70) {
      rgb = COLOR_RED;
    } else {
      rgb = COLOR_YELLOW;
    }
  } else {
    if (happy <= 70) {
      rgb = COLOR_RED;
    } else {
      rgb = COLOR_GREEN;
    }
  }

  tft.fillCircle(80, 100, 30, rgb);
  tft.fillCircle(70, 100, 5, COLOR_BLACK);
  tft.fillCircle(70, 100, 1, COLOR_WHITE);
  tft.fillCircle(90, 100, 5, COLOR_BLACK);
  tft.fillCircle(90, 100, 1, COLOR_WHITE);
  if(health <= 60){
    tft.drawText(ILI9225_LCD_WIDTH / 11, ILI9225_LCD_HEIGHT / 1.1, "Health: " + outPutHealth, COLOR_RED);
  }else{
  tft.drawText(ILI9225_LCD_WIDTH / 11, ILI9225_LCD_HEIGHT / 1.1, "Health: " + outPutHealth, COLOR_WHITE);
  }
  tft.drawText(ILI9225_LCD_WIDTH / 1.8, ILI9225_LCD_HEIGHT / 1.1, "Happy: " + outPutHappy);
}



void dieGraphic() {
  rgb = COLOR_GRAY;
  tft.fillCircle(80, 100, 30, rgb);
  tft.drawText(ILI9225_LCD_WIDTH / 3.3, ILI9225_LCD_HEIGHT / 1.4, "I'm dead :(");
  tft.drawText(ILI9225_LCD_WIDTH / 1.8, ILI9225_LCD_HEIGHT / 1.1, "Happy: 00  ", COLOR_GRAY);
  tft.drawText(ILI9225_LCD_WIDTH / 11, ILI9225_LCD_HEIGHT / 1.1, "Health: 00", COLOR_GRAY);

}


void resetGame() {
  tft.clear();
  health = 99;
  happy = 99;
  caseState = 0;
  counterState = 0;
}

