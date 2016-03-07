int up; //2
int down; //3
int enter; //4
int led = 11;
int cycle;
int increment = 64;
unsigned long pT1 = 0;
unsigned long pT2 = 0;
unsigned long pT3= 0;
const int interval = 10;

int ledFade;
int lastValue = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  myFunction(2, lastValue);
  debug();
}


int myFunction( int pin, int lastValue) {
  long cT = millis();
  up = digitalRead(2);
  down = digitalRead(3);
  enter = digitalRead(4);
  if (up != lastValue) {
    if (cT - pT1 >= interval) {
      if (cycle < 1023) cycle += increment;
      pT1 = cT;
    }
  }
  if (down != lastValue) {
    if (cT - pT2 >= interval) {
      if (cycle > 0 )cycle -= increment;
      pT2 = cT;
    }
  }

  if (enter != lastValue) {
    if (cT - pT3 >= interval) {
      pT3 = cT;
      ledFade = map(cycle, 0, 1023, 0, 255);
      analogWrite(led, ledFade);
    }
  }
  return (digitalRead(pin));
}

