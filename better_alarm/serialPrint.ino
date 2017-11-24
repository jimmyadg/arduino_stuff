void serialPrint(int x) {
  if (x == 1) {
    Serial.print(t.year, DEC);
    Serial.print("/");
    Serial.print(rtc.getMonthStr());
    Serial.print("/");
    Serial.print(t.date, DEC);
    Serial.print(",");
    Serial.print(t.hour, DEC);
    Serial.print(":");
    Serial.print(t.min, DEC);
    Serial.print(":");
    Serial.print(t.sec, DEC);
    Serial.print(",");
    Serial.print("ON");
    Serial.print(",");
    Serial.print(pos);
    Serial.println();
  } else if (x == 2) {
    Serial.print(t.year, DEC);
    Serial.print("/");
    Serial.print(rtc.getMonthStr());
    Serial.print("/");
    Serial.print(t.date, DEC);
    Serial.print(",");
    Serial.print(t.hour, DEC);
    Serial.print(":");
    Serial.print(t.min, DEC);
    Serial.print(":");
    Serial.print(t.sec, DEC);
    Serial.print(",");
    Serial.print("OFF");
    Serial.print(",");
    Serial.print(pos);
    Serial.println();
  }
}

