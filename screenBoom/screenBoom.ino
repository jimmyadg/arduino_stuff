/*
  This is an arduino timer that will
  automatically log you out of your computer
            ***beware of unsaved files!!!***
  Screen Timer v2
  Aurthor: James Shih
  references
  https://www.arduino.cc/en/Reference/KeyboardModifiers
  https://www.arduino.cc/en/Reference/KeyboardPress
*/
#include <LiquidCrystal.h>
#include <Keyboard.h>
#include <HID.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char cmdKey = KEY_LEFT_GUI;
char shfKey = KEY_LEFT_SHIFT;
char rtnKey = KEY_RETURN;
int potPin = A0;
int photoPin = A1;
int val = 0;
int photoVal = 0;
int counter = 0;
int countNum = 0;
int caseState = 0;
unsigned long pTime = 0;

void setup() {
  Keyboard.begin();
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potPin);
  photoVal = analogRead(photoPin);
  counter = map(val, 0, 1016, 0, 600); //map to 600 seconds
  long cTime = millis();
  Serial.print(photoVal);
  Serial.print("      ");
  Serial.print(counter);
  Serial.print("      ");
  Serial.print(countNum);
  Serial.println();

  switch (caseState) {
    case 0:
      lcd.setCursor(0, 0);
      lcd.print("Set Timer:");
      lcd.setCursor(0, 1);
      lcd.print("    ");
      lcd.print(counter);
      lcd.print("  seconds");
      lcd.print("    ");

      if (photoVal <= 300) {
        tone(9, 3000, 100); //set time sound
        countNum = counter;
        lcd.clear();
        caseState++;
      }
      break;

    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Time Left:");
      lcd.setCursor(0, 1);
      if (cTime - pTime >= 1000 && countNum > 0) {
        pTime = cTime;
        tone(9, 2500, 100);
        countNum--;
        lcd.print("    ");
        lcd.print(countNum);
        lcd.print("  seconds");
        lcd.print("    ");
      } else if (countNum <= 0) {
        lcd.clear();
        caseState++;
      }
      break;

    case 2:
      lcd.setCursor(0, 0);
      lcd.print("     ");
      lcd.print("BOOM!");
      lcd.setCursor(0, 1);
      lcd.print("");
      //Boom sound effect
      tone(9, 400, 800);
      delay(400);
      tone(9, 200, 1000);
      //Logout Mac
      Keyboard.press(cmdKey);
      Keyboard.press(shfKey);
      Keyboard.press('q');
      delay(100);
      Keyboard.releaseAll();
      Keyboard.press(rtnKey);
      Keyboard.releaseAll();
      delay(6000);
      lcd.clear();
      caseState = 0;
      break;
  }
}
