const int digitalInPin = 8;
const int armedLedPin = 3;
const int motionLedPin = 2;
const int buzzer = 10;
const int pacePin = A1;
const int waitPin = A2;
int val;
int waitPinVal;
int pacePinVal;
int pace;
int wait;

void setup() {
  // put your setup code here, to run once:
  pinMode(motionLedPin, OUTPUT);
  pinMode(armedLedPin, OUTPUT);
  digitalWrite(armedLedPin, HIGH);
  randomSeed(analogRead(A0));
  Serial.begin(9600);
}

void loop() {
  tick();
  if (random(0, 10) == 0) {
    go();
    int state = motionRead(digitalInPin);
    digitalWrite(motionLedPin, state);
    rearm();
    digitalWrite(motionLedPin, LOW);
  }

}


int motionRead(int pin) {
  waitPinVal = analogRead(waitPin);
  wait = map(waitPinVal, 0, 1023, 500, 2000);
  Serial.print("  wait = ");
  Serial.print(wait);
  Serial.println();
  delay(wait);
  val = digitalRead(pin);
  if (val == 1) {
    winFunction();
    return val;
  }else{
    failFunction();
    return val;
  }
}


void rearm() {
  digitalWrite(armedLedPin, LOW);
  for (int x = 3; x > 0; x--) {
    Serial.print("Rearming in ");
    Serial.print(x);
    Serial.println();
    delay(1000);
    if (x == 0) break;
  }
  Serial.println("Re-armed");
  digitalWrite(armedLedPin, HIGH);
}

void tick() {
  Serial.println("Tick...");
  tone(buzzer, 4000, 5);
  tone(buzzer, 3000, 10);
  pacePinVal = analogRead(pacePin);
  pace = map(pacePinVal, 0, 1023, 100, 900);
  Serial.print("  pace = ");
  Serial.print(pace);
  Serial.println();
  delay(pace);
}

void go() {
  Serial.println("Go!");
  tone(buzzer, 1000, 1000);
}

void winFunction() {
  Serial.println("Win");
  tone(buzzer, 3000, 200);
  tone(buzzer, 2000, 100);
}

void failFunction() {
  Serial.println("Fail");
  tone(buzzer, 100, 1000);
}


