void reset() {
  if (caseState == 4) {
    counter = 30000;
  } else {
    counter = 0;
  }
  caseState = 0;
  r = 0;
  g = 0;
  b = 0;
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
  digitalWrite(nightPin, LOW);
}

