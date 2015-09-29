const int buttonPin = 11;
const int ledPin = 12;
int buttonState = LOW;
int ledState = LOW;
boolean pressed = false;

void setup() {
pinMode(buttonPin, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}


void loop() {
  
buttonState = digitalRead(buttonPin);
ledState = digitalRead(ledPin);

if (buttonState == HIGH && pressed == false) { 
    if (ledState == LOW) {
      ledState = HIGH;
    }else {
      ledState = LOW;
    }
    pressed = true;
}

if (buttonState == LOW && pressed == true) {
  pressed = false;
}

digitalWrite(ledPin, ledState);
Serial.println(pressed, buttonState);
}


