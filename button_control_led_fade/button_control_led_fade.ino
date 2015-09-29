const int buttonPin = 2;
const int ledPin = 13;
const int fadePin = 11;
int buttonState = LOW;
int ledState = LOW;
int fadeLevel = 0;
boolean fadeUp = true;
boolean pressed = false;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(fadePin, OUTPUT);
  Serial.begin(9600);
}


void loop() {

  buttonState = analogRead(buttonPin);
  ledState = digitalRead(ledPin);
  analogRead(ledPin);
  analogWrite(fadePin, fadeLevel / 2);
  
//BUTTON
  if (buttonState == HIGH && pressed == false) {
    if (ledState == LOW) {
      ledState = HIGH; //TURN ON LED
    } else {
      ledState = LOW; //TURN OFF LED
    }
    pressed = true;
  }

  if (buttonState == LOW && pressed == true) {
    pressed = false; //RESET PRESSED VALUE
  }

//FADE LED START
  if (ledState == HIGH) {
    if (fadeUp == true) {
      fadeLevel++;
      if (fadeLevel == 510) {
        fadeUp = false;
      }
    } else {
      fadeLevel--;
      if (fadeLevel == 0) {
        fadeUp = true;
      }
    }
  } if (ledState == LOW) {
    fadeLevel = 0; //TURN OFF FADE LED
  }


  digitalWrite(ledPin, ledState);
  Serial.println(fadeLevel / 2);
}


