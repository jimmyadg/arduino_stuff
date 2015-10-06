int ledPin1 = 8;
int ledPin2 = 9;
int ledPin3 = 10;
int ledPin4 = 11;
int ledPin5 = 12;
int ledPin6 = 13;
void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  // The analog pin reads from 0 to 1023.
  // This commands maps those numbers from 4 to 0
  // So 0 becomes 4 and 1023 becomes 0
  int mappedSensorValue = map( sensorValue, 0, 1023, 7, 0);
  //Here we test the mappedsensorvalue. If it is greater then 1 we turn
  // on the LED on Pin 2 and then see if it is greater then 2.
  
  if (mappedSensorValue > 1) {
  digitalWrite(ledPin6, HIGH);
  if (mappedSensorValue > 2) {
    digitalWrite(ledPin5, HIGH);
    if (mappedSensorValue > 3) {
      digitalWrite(ledPin4, HIGH);
      if (mappedSensorValue > 4) {
        digitalWrite(ledPin3, HIGH);
        if (mappedSensorValue > 5) {
          digitalWrite(ledPin2, HIGH);
          if(mappedSensorValue > 6) {
          digitalWrite(ledPin1, HIGH);
          } else {
            digitalWrite(ledPin1, LOW);
          }
        } else {
          digitalWrite(ledPin2, LOW);
        }
      } else {
        digitalWrite(ledPin3, LOW);
      }
    } else {
      digitalWrite(ledPin4, LOW);
    }
  } else {
    digitalWrite(ledPin5, LOW);
  }
} else {
  digitalWrite(ledPin6, LOW);
}
}
