//#include <CapacitiveSensor.h>
//CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);
int redPin = 3;
int greenPin = 5;
int bluePin = 6;
int photoPin = 0;
int potPin = 1;
int nightPin = 11;
int nightLevel = 0;
int caseState;
int fadeLevel = 0;
int darkState;
int counter = 0;
int potState;
boolean fadeUp = false;
int r;
int g;
int b;
unsigned long previousMillis = 0; 
const long interval = 1000;
const long rgbDuration = 20;

void setup() {
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);
pinMode(nightPin,OUTPUT);
Serial.begin(9600);

}

void loop() {
function();
serialDisplay();
}
