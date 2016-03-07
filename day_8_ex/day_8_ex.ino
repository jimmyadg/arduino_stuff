#include <Servo.h>

Servo myservo;


int val;
int ledVal;
int low = 1023;
int high = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(A2, INPUT);
  pinMode(6, OUTPUT);
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(A2);
  if (val > high) high = val;
  if (val < low) low = val;

  val = map(val, low, high, 10, 170);
  ledVal = map(val, low, high, 255, 0);
  myservo.write(val);
  analogWrite(6, ledVal);
    Serial.println(low);
  Serial.println(high);
  //delay(100);
}
