
const int LED = 11;
int brightness = 0;
int fade = 5;

void setup() {
  pinMode (LED, OUTPUT);

}

void loop() {
  analogWrite(LED, brightness);
  brightness = brightness + fade;

  if (brightness == 0 || brightness == 255) {
    fade = -fade;
  }
  delay(40);
}
