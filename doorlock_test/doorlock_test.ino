void setup() {
  // put your setup code here, to run once:
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
}
