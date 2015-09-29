#include <RBL_nRF8001.h>
#include <RBL_services.h>
const int led = 12;
int ledState = LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, ledState);
  

}
