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
boolean gameOn = false;

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
if(distance <= 7){
  caseState = 3;
  timer--;
  if(timer <=0 && distance <= 7){
    caseState = 0;
  }
}else{
  caseState = 2;
}

  logic();
  proximity();
  debug();

}

