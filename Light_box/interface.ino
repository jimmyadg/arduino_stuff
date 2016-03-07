void function() {
  long start = millis();
  //long touchVar = cs_4_2.capacitiveSensor(30);
  darkState = analogRead(photoPin);
  potState = analogRead(potPin);



  //delay(10);


  switch (caseState) {
    case 0: //red indicator state
      digitalWrite(redPin, HIGH);
      if (potState != 123) {
        reset();
        caseState = 1;
      }
      break;
    case 1: //green indicator state
      digitalWrite(greenPin, HIGH);
      digitalWrite(nightPin, HIGH);
      if (potState >= 470) {
        reset();
        caseState = 2;
      }
      break;
    case 2: //fade indicator fade up state
      analogWrite(bluePin, fadeLevel * 5);
      fadeLevel++;
      if (fadeLevel == 46) caseState = 3;
      if (darkState < 200) {
        fadeLevel = 0;
        analogWrite(bluePin, fadeLevel);
        caseState = 4;
      }
      if (potState >= 820) {
       reset();
        caseState = 6;
      }
      break;
    case 3: //fade indicator fade down state
      analogWrite(bluePin, fadeLevel * 5);
      fadeLevel--;
      if (fadeLevel == 0) caseState = 2;
      if (darkState < 200) {
        fadeLevel = 0;
        analogWrite(bluePin, fadeLevel);
        caseState = 4;
      }
      if (potState >= 820) {
        reset();
        caseState = 6;
      }
      break;
    case 4: //night light on state
      analogWrite(nightPin, nightLevel);
      fadeUp = true;
      if (fadeUp == true) nightLevel++;
      if (nightLevel == 100) {
        fadeUp = false;
        caseState = 5;
      }
      if (darkState > 200) {
        nightLevel = 0;
        analogWrite(nightPin, nightLevel);
        caseState = 2;
      }
      break;
    case 5: //night light turn off timer state
      analogWrite(nightPin, nightLevel);
      counter++;
      if (counter == 3000) {
        nightLevel = 0;
        analogWrite(nightPin, nightLevel);
        reset();
        caseState = 2;
      }
      if (darkState > 200) {
        nightLevel = 0;
        analogWrite(nightPin, nightLevel);
        caseState = 2;
      }
      break;
    case 6: //animation mode 1

      if (start - previousMillis >= rgbDuration) {
        previousMillis = start;
        counter += 8;
        {
          // fading between 7 colors
          r = ((counter < 255) * counter) + ((counter >= 255) * 255) + ((counter > 511) * (512 - counter)) + ((counter > 766) * (counter - 766)) + ((counter >= 1276) * (counter - 1276)) + ((counter > 1530) * (1530 - counter)) + ((counter > 1786) * (1786 - counter));
          g = (counter < 256) * (1) + (counter > 255) * (counter - 255) + (counter > 510) * (510 - counter) + (counter > 1020) * (1020 - counter) + (counter > 1274) * (counter - 1274) + (counter > 1530) * (counter - 1531) + (counter > 1785) * (3571 - (2 * counter));
          b = (counter < 764) * (1) + (counter > 765) * (counter - 765) + (counter > 1020) * (1020 - counter) + (counter > 1786) * (1786 - counter);
        }

        if (counter > 2040) //
        {
          //reset rgb
          r = 0;
          g = 0;
          b = 0;
          counter = 0;
        }
      }
      analogWrite(redPin, r);
      analogWrite(greenPin, g);
      analogWrite(bluePin, b);

    //      if (touchVar >= 1000) caseState = 7;
    //      break;
    case 7: //reset back to red indicator state
      caseState = 0;
      counter = 0;
      r = 0;
      g = 0;
      b = 0;
      analogWrite(redPin, r);
      analogWrite(greenPin, g);
      analogWrite(bluePin, b);
      break;

//    case 8: //reset back to fade up state
//      if (darkState > 250) {
//        counter = 0;
//        caseState = 2;
//      }
//      break;
  }
}

void reset() {
  caseState = 0;
  counter = 0;
  r = 0;
  g = 0;
  b = 0;
  nightLevel = 0;
  analogWrite(nightPin, nightLevel);
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);

}

