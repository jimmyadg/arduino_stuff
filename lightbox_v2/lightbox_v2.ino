int redPin = 3;
int greenPin = 5;
int bluePin = 6;
int photoPin = 0;
int potPin = 1;
int nightPin = 11;
int nightLevel = 0;
int caseState;
int fadeLevel = 0;
int darkState;
int counter = 0;
int potState;
boolean turn = false;
boolean x = false;
//boolean fadeUp = false;
int r;
int g;
int b;
unsigned long previousMillis = 0;
const long interval = 1000;
const long rgbDuration = 20;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(nightPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  darkState = analogRead(photoPin);
  potState = analogRead(potPin);

  if (potState < 50 && turn == true) {
    reset();
    caseState = 4;
  } else if(potState < 50 && turn == false) {
    reset();
    caseState = 0;
  }

  
  if (potState >= 120 && turn == true) {
    caseState = 3;
  } else if (potState >= 150 && turn == false) {
    reset();
    caseState = 1;
  }

  if (potState >= 280) {
    reset();
    caseState = 2;
  }

  interface();
  serialDisplay();
}
