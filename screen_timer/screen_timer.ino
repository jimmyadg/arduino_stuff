/*
  Screen Timer v1
  Aurthor: James Shih
  references
  https://www.arduino.cc/en/Reference/KeyboardModifiers
  https://www.arduino.cc/en/Reference/KeyboardPress
*/

#include <Keyboard.h>
#include <HID.h>

char cmdKey = KEY_LEFT_GUI;
char shfKey = KEY_LEFT_SHIFT;
char rtnKey = KEY_RETURN;
int caseState = 0;
void setup() {
  Keyboard.begin();
}

void loop() {
  switch (caseState) {
    case 0:
      delay(1000);
      caseState++;
      break;

    case 1:
      //Logout Mac
      Keyboard.press(cmdKey);
      Keyboard.press(shfKey);
      Keyboard.press('q');
      //delay(100);
      //Keyboard.press(rtnKey);
      delay(100);
      Keyboard.releaseAll();
      delay(100);
      caseState++;
      break;

    case 2:
      Serial.println('END');
      break;
  }


}
