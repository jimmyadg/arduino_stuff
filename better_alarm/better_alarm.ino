#include "FastLED.h"
#include "DS3231.h"
#define NUM_LEDS 24
#define DATA_PIN 8
#define CLOCK_PIN 9
int pos;
int hue;
unsigned long pTime;
unsigned long dTime;
int potVal;

int StartHour;
int StartMin;
int StartSec;
int StartPos;

int StopHour;
int StopMin;
int StopSec;
int StopPos;

bool on = false;
bool off = false;

DS3231  rtc(SDA, SCL);
CRGB leds[NUM_LEDS];

Time t;

void setup() {
  LEDS.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  LEDS.setBrightness(60);
  rtc.begin();
  //rtc.setDOW(SATURDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(22, 3,00 );     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(7, 5, 2016);   // Set the date to January 1st, 2014
  Serial.begin(9600);

}

void loop() {
  long cTime = millis();
  potVal = analogRead(A3);
  if (cTime - dTime >= 500) {
    if (potVal >= 400) {
      int nStartP = pos;
      on = false;
      if (nStartP != StartPos) {
        if (off == false) {
          serialPrint(1);
          StartPos = nStartP;
          off = true; // make serial print once only
        }
      }
    } else {
      off = false;
      int nStopP = pos;
      if (nStopP != StopPos) {
        if (on == false) {
          serialPrint(2);
          StopPos = nStopP;
          on = true; // make serial print once only
        }
      }

    }
    dTime = cTime;
  }
  setHue();

}
