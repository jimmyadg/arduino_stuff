const int ledPin = 12;
int ledState = LOW;
int x;
int y = 0;
int z = 1000;
void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
pinMode(13, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
x = millis();

if (x - y >= z) {
  x = y;

  if (ledState == LOW) {
    ledState = HIGH;
  }else{
    ledState = LOW;
  }
  digitalWrite(ledPin, ledState);
}
Serial.println(ledState);
}
