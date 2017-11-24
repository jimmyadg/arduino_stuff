void setHue(){
  t = rtc.getTime();
  setPos(0, 60, 0, 24, 6, 19, 155, 5); //use min for demostration purpose
  pos = map(t.sec, 0, 60, 0, 24); //mapping time range to led pos 
  long cTime = millis();
  if (cTime - pTime >= 1000) {
    if (pos == 0) {
      leds[23] = CRGB::Black;
    } else {
      leds[pos - 1] = CRGB::Black;
    }
    leds[pos] = CHSV(hue, 255, 255);
    //debug(3);
    pTime = cTime;
  }
  FastLED.show();
}

