//create variables for pins
const int buttonPin = 2;
const int ledPin =  12;
const int fadeLed = 11;
const int potPin = 0;
const int lightPin = 1;

// LED fading variables
boolean fadeUp = true;
int fadeLevel = 0;
//LED blinking variables
int ledState = LOW;
//button variables
int buttonState = 0;
boolean pressed = false;
//analog sensor variables
int lightVar = 0;
int potVar = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(fadeLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVar = analogRead(lightPin);
  if (lightVar <= 600) {
    ledState = HIGH;
    if (ledState == HIGH && fadeUp == true) {
      fadeLevel++;
      if (fadeLevel == 510) { //LED has reached the top
        fadeUp = false; // LED is fading down
      }
    } else {
      fadeLevel--;
      if (fadeLevel == 0) { // fadeLevel has reached the bottom
        fadeUp = true; // so start fading up
      }
    }
  } else {
    ledState = LOW;
  }

  if (ledState == LOW && fadeLevel--){
    fadeLevel++;
    fadeLevel = 0;
  }
  digitalWrite(ledPin, ledState);
  Serial.println(fadeLevel);
  analogWrite(fadeLed,fadeLevel/2);

}
