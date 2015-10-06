#include <OneSheeld.h>

int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  OneSheeld.begin();
  pinMode(ledPin, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (Mic.getValue() > 40) {
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
}
