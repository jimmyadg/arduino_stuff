void setPos(int r1, int r2, int r3, int r4, int pos1, int pos2, int h1, int h2){
    pos = map(t.sec, r1, r2, r3, r4); //mapping time range to led pos

  if (pos >= pos1 && pos <= pos2) {
    hue = h1;
  } else {
    hue = h2;
  }
}

