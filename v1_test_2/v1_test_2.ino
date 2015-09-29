//create variables for pins
const int buttonPin = 2;
const int ledPin =  12;
const int fadeLed = 11;
const int potPin = 0;
const int lightPin = 1;
const int speaker = 6;

// LED fading variables
boolean fadeUp = true;
int fadeLevel = 0;
//LED blinking variables
int ledState = LOW;
//button variables
int buttonState = 0;
int prebuttonState = 0;
boolean pressed = false;
//analog sensor variables
int lightVar = 0;
int potVar = 0;
int speakerState = LOW;
const long interval = 10;
unsigned long previousMillis = 0;

//state machine
int stateVar;



void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(fadeLed, OUTPUT);
  pinMode(speaker, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightVar = analogRead(lightPin);
  potVar = analogRead(potPin);
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && prebuttonState == LOW) {
    delay(5);
    stateVar++;
    if (stateVar >= 4) stateVar = 0;
  }
  prebuttonState = buttonState;

  unsigned long currentMillis = millis();

  switch (stateVar) {
    case 0:
      //Serial.println("nightlight mode");
      ledState = LOW;
      //Pot sensor to start fadeLed
      if (lightVar <= 600 ) {
        fadeUp = true;
      } else {
        fadeUp = false;
      }

      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        //controlling fadeLed
        if (fadeUp == true) {
          if (fadeLevel != 255)
            fadeLevel++;
        } else {
          if (fadeLevel != 0) fadeLevel--;
        }

      }
      break;
    case 1:
      fadeLevel = 0;
      stateVar = 2;
    case 2:
      ledState = HIGH;
      speakerState = HIGH;
      //Serial.println("projector mode");
      break;
    case 3:
      ledState = LOW;
      speakerState = LOW;
      stateVar = 0;
      break;
      
  }

  digitalWrite(ledPin, ledState);
  //Serial.println(lightVar);
  Serial.println(speakerState);
  analogWrite(fadeLed, fadeLevel);
}



