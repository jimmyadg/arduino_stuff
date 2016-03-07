#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
int pos = 0;


void setup() {
  myservo1.attach(9);
  myservo2.attach(10);
  myservo3.attach(11);
  myservo4.attach(6);
  Serial.begin(9600);
}

void loop() {
  for (pos = 20; pos <= 140; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);  
    myservo2.write(pos);
    myservo3.write(pos);  
    myservo4.write(pos);// tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 140; pos >= 20; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);  
    myservo4.write(pos);// tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
}
