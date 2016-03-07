void logic() {
  long start = millis();
  switch (caseState) {
    case 0:
      timer = 0;
      myservo1.write(180);
      myservo3.write(0);
      myservo2.write(0);
      myservo4.write(180);
      break;
    case 1:

      myservo1.write(90);
      myservo3.write(90);
      myservo2.write(90);
      myservo4.write(90);

      break;

    case 2:
      timer = (int)random(50, 300);
      counter = 128 + 127 * cos (0.25 * PI / interval * (interval - start));
      pos = map(counter, 0, 255, 40, 135);
      pos2 = map(counter, 0, 255, 135, 40);
      myservo1.write(pos);
      myservo3.write(pos2);
      myservo2.write(pos);
      myservo4.write(pos2);
      break;

    case 3:
      myservo1.write(155);
      myservo3.write(90);
      myservo2.write(25);
      myservo4.write(90);
      break;
    case 4:// dead
      myservo1.write(40);
      myservo3.write(0);
      myservo2.write(30);
      myservo4.write(40);
      break;
  }
}

