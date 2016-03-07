void displayInfo() {

  String outPutPot = String(potState, DEC);
  String outPutHealth = String(health, DEC);
  String outPutHappy = String(happy, DEC);

  //counter logic
  switch (counterState) {
    case 0:
      counter++;
      if (health <= 0) counterState = 2;
      if (health <= 0) counterState = 2;
      if (counter == 5) counterState = 1;
      break;

    case 1:
      health -= 5;
      if (health <= 0) counterState = 2;
      if (health <= 0) counterState = 2;
      happy -= 2;
      counter = 0;
      if (counter == 0) counterState = 0;
      break;

    case 2:
      counter = 0;
      caseState = 3;
  }

  //control graphic
  if (health <= 0) {
    dieGraphic();
  } else {
    gameGraphic();
  }

}



void serialPort() {
  Serial.print("Button State = \t");
  Serial.print(buttonState);
  Serial.print("\t Pot State = \t");
  Serial.print(potState);
  Serial.print("\t counter = \t");
  Serial.print(counter);
  Serial.print("\t counterState = \t");
  Serial.print(counterState);
  Serial.println();
}

