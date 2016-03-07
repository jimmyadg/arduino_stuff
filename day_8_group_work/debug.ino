void debug(){
  Serial.print("Current increments = \t");
  Serial.print(increment);
  Serial.print("\tBrightness= \t");
  Serial.print(cycle);
  Serial.print("\tUp= \t");
  Serial.print(up);
  Serial.print("\tDown= \t");
  Serial.print(down);
  Serial.print("\tEnter= \t");
  Serial.print(enter);
  Serial.print("\tCycle= \t");
  Serial.print(cycle);
  Serial.print("\tledFade= \t");
  Serial.print(ledFade);
  Serial.println();
}

