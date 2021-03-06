#include <CapacitiveSensor.h> // the capacitive sensor library
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4, 2); //setup pins 4 and 2 for the sensor. 2 has the probe.
int leds[] = { 3, 5, 6, 9, 10, 11}; // array of all the pwm pins
int pinCount = 6; // how many pwm pins
int ledFade[6]; // an array to hold the fade values for the leds
int ledPin = 13; // use the Arduino's built-in led for debugging
int i; // a variable later use in the logic
int prevTime; // a variable for the logic timing
int interval = 500; // length of time for logic time
int fadeSpeed = 5; // length of time for when to change the fade out of the led
int prevFadeTime; // a variable for the fade timing
int touched;
int stateVar;
int lightVar;

void setup() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) { // set the 6 led pins to output
    pinMode(leds[thisPin], OUTPUT);
  }
  pinMode(ledPin, OUTPUT); // set the debug led to output
  Serial.begin(9600);
}

void loop() {
  int darkVar = darkSense();
  int  touchVar = touchSense(); // call the function "touchSense" and put the result in touchVar
  if (touchVar >= 1000 && touched == 0) {
    touched = 1;
  } else if (touchVar < 1000){
    touched = 0;
  }
  debug(lightVar); // call the function "debug" with the argument touchVar
  logic(); // call the function "logic"
  fade(); // call the function "fade"
  display(); // call the function "display"

  //Serial.print("stateVar =\t");
  
  Serial.print(stateVar);
  Serial.print("\ttouched =\t");
  Serial.print(touched);
  Serial.print("\tlightVar =\t");
  Serial.print(lightVar);
    Serial.print("\ttouchVar =\t");
  Serial.print(touchVar);
      Serial.print("\tdarkVar =\t");
  Serial.println(darkVar);
}
