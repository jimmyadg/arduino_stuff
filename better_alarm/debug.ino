void debug(int x) {
  if (x == 1) {
    Serial.print(t.year, DEC);
    Serial.print("  ");
    Serial.print(rtc.getMonthStr());
    Serial.print("  ");
    Serial.print(t.date, DEC);
    Serial.print("  ");
    Serial.print(t.hour, DEC);
    Serial.print(":");
    Serial.print(t.min, DEC);
    Serial.print(":");
    Serial.print(t.sec, DEC);
    Serial.print("  ");
    Serial.print(pos);
    Serial.print("  ");
    Serial.print(potVal);
    Serial.println();
  } else if (x == 2) {
    Serial.println(potVal);
  } else if (x == 3) {
    //Serial.print("Start Time: ");
    Serial.print(StartHour);
    Serial.print(StartMin);
    Serial.print(StartSec);
    Serial.print(",");
    Serial.print(StartPos);
    Serial.print(",");
    //Serial.print("    Stop Time: ");
    Serial.print(StopHour);
    Serial.print(StopMin);
    Serial.print(StopSec);
    Serial.print(",");
    Serial.print(StopPos);
    Serial.println();
  }


}

