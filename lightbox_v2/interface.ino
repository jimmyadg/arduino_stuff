void interface() {
  long start = millis();
  switch (caseState) {

    case 0: //red indicator state
      digitalWrite(redPin, HIGH);
      x = false;
      break;

    case 1: // green indicator state
      digitalWrite(greenPin, HIGH);
      digitalWrite(nightPin, HIGH);
      break;

    case 2: //animation without light
      r = random (0, 255);
      g = random(0, 255);
      b = random(0 , 255);

      analogWrite(redPin, r);
      analogWrite(greenPin, g);
      analogWrite(bluePin, b);
      digitalWrite(nightPin, HIGH);

      turn = true;
      if (x == true) {
        turn = false;
      }
      break;

    case 3: //animation 2
      digitalWrite(nightPin, HIGH);
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

      break;

    case 4: // night light mode
      if (darkState > 200) {
        x = true;
        fadeLevel = 128 + 127 * cos(0.25 * PI / interval * (rgbDuration - start));
        if (start - previousMillis >= rgbDuration) {
          previousMillis = start;
          analogWrite(bluePin, fadeLevel);
        }
      }

      if (darkState < 200) {
        digitalWrite(bluePin, LOW);
        nightLevel = HIGH;
        if (start - previousMillis >= counter) {
          nightLevel = LOW;
          reset();
        }
        digitalWrite(nightPin,nightLevel);
      }
      break;
  }
}

