
int myArray[6];
int ledPins[6] = {3, 5, 6, 9, 10, 11};
int myVar = -1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int thisPin; thisPin < 6; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
 myArray[myVar] = 1;
delay(50);
 myVar++;

 for (int thisPin; thisPin < 6; thisPin++) { 
  digitalWrite(ledPins[thisPin], myArray[thisPin]);
 }
Serial.println(myVar);
}
