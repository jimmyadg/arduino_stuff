#include <DS3231.h> // Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/


DS3231  rtc(SDA, SCL);


int green[6] = {13, 12, 11, 10, 9, 8};
int pinCount = 6;
int ledFade[6];
int i;
int caseState = 0;
int modeState = 0;
int interval = 800;
int potPin = 0;
int potVal;
boolean reverse = false;
unsigned long prevTime;
Time t;
void setup() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(green[thisPin], OUTPUT);
  }
  Serial.begin(9600);
  rtc.begin();
  //rtc.setDOW(MONDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(17, 7,00 );     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(2, 8, 2016);   // Set the date to January 1st, 2014
}

void loop() {
  long currentTime = millis();
  potVal = analogRead(potPin);

  if (potVal > 600) {
    modeState = 1;
  } else {
    modeState = 0;
  }

  switch (modeState) {
    case 0:
      reset();
      timeClock();
      break;

    case 1:
      demoMode();
      break;
  }
}
