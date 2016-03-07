#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
int interval = 100;
int pos;
int pos2;
float counter;


void setup() {
  myservo1.attach(9);
  myservo2.attach(10);
  myservo3.attach(11);
  myservo4.attach(6);
  Serial.begin(9600);
}

void loop() {
  long start = millis();
  counter = 128 + 127 * cos (0.25 * PI / interval * (interval - start));
  pos = map(counter, 0, 255, 40, 135);
  pos2 = map(counter, 0, 255, 135, 40);
  myservo1.write(pos);
  myservo3.write(pos2);
  myservo2.write(pos);
  myservo4.write(pos2);
  debug();
}
