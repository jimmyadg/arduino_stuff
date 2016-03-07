void timeClock() {

  t = rtc.getTime();

  //display battery level
  if (t.hour >= 7) digitalWrite(green[0], HIGH);
  if (t.hour >= 8) digitalWrite(green[1], HIGH);
  if (t.hour >= 9) digitalWrite(green[2], HIGH);
  if (t.hour >= 10) digitalWrite(green[3], HIGH);
  if (t.hour >= 11) digitalWrite(green[4], HIGH);
  if (t.hour >= 12) digitalWrite(green[5], HIGH);
  if (t.hour >= 13) digitalWrite(green[5], LOW);
  if (t.hour >= 14) digitalWrite(green[4], LOW);
  if (t.hour >= 15) digitalWrite(green[3], LOW);
  if (t.hour >= 16) digitalWrite(green[2], LOW);
  if (t.hour >= 17) digitalWrite(green[1], LOW);
  if (t.hour >= 18) digitalWrite(green[0], LOW);



  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");

  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());

  //DS3231_Serial_Hard example
  Serial.println(t.hour);
  
for (int n = 0; n < pinCount; n++) {
      Serial.print(n + 1);
      Serial.print("\t");
      Serial.println(ledFade[n]);
    }

  // Wait one second before repeating :)
  delay (1000);
}

