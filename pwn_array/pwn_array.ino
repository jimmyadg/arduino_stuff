int ledPins[] = { 3, 5, 6, 9, 10, 11 };
int pinCount = 6;
int ledFade[6];
int i;
int caseState = 0;
int prevTime;
int interval = 300;
boolean reverse = false;
void setup() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println();
  Serial.println("Begin");
}

void loop() {
  int currentTime = millis();
  if (currentTime - prevTime >= interval) {
    switch (caseState) {
      case 0:
        if (reverse == false) {
          if (ledFade[i] == 0) {
            ledFade[i] = 1;
          } else {
            ledFade[i] = 0;
          }
          i++;
          if (i == 6) {
            caseState = 1;
            reverse = true;
          }
        } else {
          ledFade[2] = 1;
          ledFade[3] = 1;
          caseState = 2;
        }
        break;
      case 1:

        if (i == 6 && reverse == true) {
          ledFade[i] = 1;
        } else {
          ledFade[i] = 0;
        }
        i--;

        if (ledFade[0] == 0) {
          caseState = 0;
        }
        break;
      case 2:
        ledFade[2] = 0;
        ledFade[3] = 0;
        ledFade[1] = 1;
        ledFade[4] = 1;
        caseState = 3;
        break;
      case 3:
        ledFade[1] = 0;
        ledFade[4] = 0;
        ledFade[0] = 1;
        ledFade[5] = 1;
        caseState = 4;
        break;
      case 4:
        ledFade[0] = 0;
        ledFade[5] = 0;
        reverse = false;
        caseState = 0;
        break;
    }

    prevTime = currentTime;
    Serial.println(currentTime);
    for (int n = 0; n < pinCount; n++) {
      Serial.print(n + 1);
      Serial.print("\t");
      Serial.println(ledFade[n]);

    }
  }

  for (int n = 0; n < pinCount; n++) {
    digitalWrite(ledPins[n], ledFade[n]);
  }
}

