void demoMode() {
  long currentTime = millis();
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
          reverse = false;
        }
        break;
    }
    prevTime = currentTime;
    Serial.println(potVal);
    Serial.println(caseState);
    Serial.println(currentTime);
    for (int n = 0; n < pinCount; n++) {
      Serial.print(n + 1);
      Serial.print("\t");
      Serial.println(ledFade[n]);
    }
  }

  for (int n = 0; n < pinCount; n++) {
    digitalWrite(green[n], ledFade[n]);
  }
}

void reset() {
  for (int n = 0; n < pinCount; n++) {
    digitalWrite(green[n], LOW);
  }
  reverse == false;
}

