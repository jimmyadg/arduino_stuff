#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
int caseState;
int interval = 100;
int pos;
int pos2;
int echoPin = 13;
int trigPin = 12;
float counter;
float pingTime;
float distance;
float speedOfSound = 776.5;
int timer;

//bluetooth
char val;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo1.attach(9);
  myservo2.attach(10);
  myservo3.attach(11);
  myservo4.attach(6);
  Serial.begin(9600);
}


void loop() {
  if (Serial.available()) {
    val = Serial.read();
  }
  if (val == 'A') caseState = 0;
  if (val == 'B') caseState = 1;
  if (val == 'C') caseState = 2;
  if (val == 'D') caseState = 3;
  if (val == 'E') caseState = 4;
  if (val == 'X') {
    if (distance <= 4) {
      caseState = 3;
      timer--;
      if (timer <= 0 && distance <= 4) {
        caseState = 0;
      }
    } else {
      caseState = 2;
    }
  }
  logic();
  proximity();
  //debug();

}
