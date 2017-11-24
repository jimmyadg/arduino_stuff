
#include "SPI.h"
#include "TFT_22_ILI9225.h"
#include <TFT.h> 

#define TFT_RST 8
#define TFT_RS  9
#define TFT_CS  10  // SS
#define TFT_SDI 11  // MOSI
#define TFT_CLK 13  // SCK
#define TFT_LED A0

#define BUTTON_LED   6
//#define speaker      5
#define POT_LED      3
#define BUTTON       12
#define POT          2

int buttonState;
int potState;
int rgb;
int health = 99;
int happy = 99;
int caseState = 0;
int counter;
int counterState;
String outPutHealth;
String outPutPot;
String outPutHappy;

TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_LED);

void setup() {

  pinMode(BUTTON_LED, OUTPUT);
  pinMode(POT_LED, OUTPUT);
  pinMode(BUTTON, INPUT);

  tft.begin();
  tft.setOrientation(2);
  tft.setFont(Terminal6x8);
  //tft.drawText(10, 10, "hello!");
  Serial.begin(9600);

}

void loop() {

  buttonState = digitalRead(BUTTON);
  potState = analogRead(POT);
  potState = map(potState, 0, 1023, 0, 9);
  interface();
  displayInfo();
  serialPort();
  digitalWrite(BUTTON_LED, HIGH);
  digitalWrite(POT_LED, HIGH);
  //tone(speaker, 0);
}


