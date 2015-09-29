int x;
const int buttonPin = 11;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(buttonPin, OUTPUT);
pinMode(12, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 
 buttonState = digitalRead(buttonPin); 
 
  if (buttonState == HIGH) {
    x++;
    if (x == 1){
      digitalWrite(12, HIGH);
  } 
    if (x != 1) {
      digitalWrite(12, LOW); 
      x = 0;
  }
 }


  
Serial.println(x);

}
