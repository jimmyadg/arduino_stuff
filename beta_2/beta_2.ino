const int potenPin = 0;
const int photoPin = 1;
const int indexPin = 13;
const int ledPin = 11;
int fadeLevel = 0;
boolean fadeUp = true;
int ledState = LOW;
int indexState = LOW;
int x = 0;
int y = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(indexPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  x = analogRead(potenPin);
  y = analogRead(photoPin);
  indexState = analogRead(photoPin);
  analogWrite(ledPin, fadeLevel / 2);

  if (y > 550) {
    indexState = HIGH;
  }else{
    indexState = LOW;
  }

  if (y >= 550) {
    ledState = HIGH;
    if (ledState == HIGH) {
      if (fadeUp == true) {
        fadeLevel++;
        if (fadeLevel == 510) {
          fadeUp = false;
        }
      }
    }
  }

  if (y < 550) {
    ledState = LOW;
    if (ledState == LOW) {
      if (fadeUp == false) {
        fadeLevel--;
        if (fadeLevel == 0){
          fadeUp = true;
        }
      }
    }
  }

  Serial.println(fadeLevel);
  digitalWrite(indexPin, indexState);
}
