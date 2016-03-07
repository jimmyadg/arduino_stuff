void printserial() {
  Serial.print("PotVal= \t");
  Serial.print(potValue);
  Serial.print("\tFade LED= \t");
  Serial.print(counter);
  Serial.print("\tButton Value= \t");
  Serial.print(buttonValue);
  Serial.print("\tPhoto Value= \t");
  Serial.print(photoValue);
  Serial.println();
}

