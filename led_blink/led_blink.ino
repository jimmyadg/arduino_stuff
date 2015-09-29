

int x;
int y;



void setup() {

pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
Serial.begin(9600);
}

void loop() {

x++;
y++;
if (x == 100) {
  digitalWrite(13, LOW);
} else if (x >= 200) {
  digitalWrite(13, HIGH);
  x = 0;
}

if (y == 50) {
  digitalWrite(12, HIGH);
} if (y == 220) {
  digitalWrite(12, LOW);
} if (y == 400) {
  digitalWrite(12, HIGH);
} if (y == 420) {
  digitalWrite(12, LOW);
} if (y == 440) {
  digitalWrite(12, HIGH);
} if (y == 460) {
  digitalWrite(12, LOW);
} if (y == 480) {
  digitalWrite(12, HIGH);
} if (y == 500) {
  digitalWrite(12, LOW);
  y = 0;
}
Serial.println(y);
}
