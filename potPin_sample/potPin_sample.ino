int potPin = 1;
int potState;
int caseState;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potState = analogRead(potPin);
  potState = map(potState, 0, 1023, 0, 3);
caseState = potState;
  switch (caseState) {
    case 0:
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      break;

    case 1:
      digitalWrite(6, LOW);
      digitalWrite(5, HIGH);
      break;
    case 2:
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      break;
  }
  Serial.println(potState);
}
