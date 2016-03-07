const int pot = A0;
const int fadeLed = 6;
const int led = 4;
const int buttonPin = A1;
const int photoPin = A2;
int potValue;
int buttonValue;
int photoValue;

float counter;
int interval = 1000;
int t = 100;
unsigned long prevTime = 0;


void setup() {
  pinMode(fadeLed, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}



void loop() {
  long start = millis();
  
  if (photoValue <= 500) {
    counter = 128 + 127 * cos (0.25 * PI / interval * (interval - start));
    if(start - prevTime >= t){
    prevTime = start;
    analogWrite(fadeLed, counter);
    }
  } else if(photoValue > 500) {
    analogWrite(fadeLed, 0);
  }
  
  digitalWrite(led, HIGH);
  potValue = analogRead(pot);
  buttonValue = digitalRead(buttonPin);
  photoValue = analogRead(photoPin);
  printserial();

}
