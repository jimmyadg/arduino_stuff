void interface() {


  switch (caseState) {
    case 0:
      if (potState == 9) caseState = 0;

      if (potState >= 2 ) {
        tft.drawRectangle(20, 20, 70, 40, COLOR_BLACK);
        tft.drawRectangle(85, 20, 135, 40, COLOR_WHITE);
        if (buttonState == HIGH) {
          caseState = 2;
        }
      } else if (potState == 0) {
        tft.drawRectangle(20, 20, 70, 40, COLOR_WHITE);
        tft.drawRectangle(85, 20, 135, 40, COLOR_BLACK);
        if (buttonState == HIGH) {
          caseState = 1;
        }
      }

      tft.drawText(ILI9225_LCD_WIDTH / 6, ILI9225_LCD_HEIGHT / 8, "Feed ");
      tft.drawText(ILI9225_LCD_WIDTH / 1.8, ILI9225_LCD_HEIGHT / 8, "Play");
      break;

    case 1:

      if (potState == 9) caseState = 0;

      if (potState >= 2) {
        tft.drawRectangle(85, 20, 135, 40, COLOR_WHITE);
        tft.drawRectangle(20, 20, 70, 40, COLOR_BLACK);

        if (buttonState == HIGH && health < 99) {

          if (health <= 87) health += 10;
          if (health > 87) health += 1;
        }else if(health >= 99){
          health = 99;
        }

      } else if (potState == 0) {
        tft.drawRectangle(85, 20, 135, 40, COLOR_BLACK);
        tft.drawRectangle(20, 20, 70, 40, COLOR_WHITE);

        if (buttonState == HIGH && health < 99) {
          health += 1;
        } else if (health >= 99) {
          health == 99;
        }
      }


      tft.drawText(ILI9225_LCD_WIDTH / 6, ILI9225_LCD_HEIGHT / 8, "Apple");
      tft.drawText(ILI9225_LCD_WIDTH / 1.8, ILI9225_LCD_HEIGHT / 8, "Milk");
      break;



    case 2:
      if (potState == 9) caseState = 0;

      if (potState >= 2 ) {
        tft.drawRectangle(20, 20, 70, 40, COLOR_BLACK);
        tft.drawRectangle(85, 20, 135, 40, COLOR_WHITE);

        if (buttonState == HIGH && happy < 99) {
          if (happy <= 92) happy += 5;
          if (happy > 92) happy += 1;
        }else if(happy >= 99){
          happy = 99;
        }

      } else if (potState == 0) {
        tft.drawRectangle(20, 20, 70, 40, COLOR_WHITE);
        tft.drawRectangle(85, 20, 135, 40, COLOR_BLACK);

        if (buttonState == HIGH && happy < 99) {
          if (happy <= 96) happy += 2;
          if (happy > 96) happy += 1;
        }else if(happy >= 99){
          happy = 99;
        }
      }


      tft.drawText(ILI9225_LCD_WIDTH / 6, ILI9225_LCD_HEIGHT / 8, "Fetch");
      tft.drawText(ILI9225_LCD_WIDTH / 1.8, ILI9225_LCD_HEIGHT / 8, "Pet ");

      break;

    case 3:
      tft.drawText(ILI9225_LCD_WIDTH / 6, ILI9225_LCD_HEIGHT / 8, "RESTART:");
      tft.drawText(ILI9225_LCD_WIDTH / 1.8, ILI9225_LCD_HEIGHT / 8, "GO! ");
      tft.drawRectangle(20, 20, 70, 40, COLOR_BLACK);
      tft.drawRectangle(85, 20, 135, 40, COLOR_WHITE);
      if (buttonState == HIGH) {
        resetGame();
      }
      break;

  }
}

