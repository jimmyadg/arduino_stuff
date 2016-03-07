#include <IRremote.h>
#include "DHT.h"

#define DHTPIN A0   
#define DHTTYPE DHT11 

IRsend irsend;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
    for (int i = 0; i < 3; i++) {
      digitalWrite(13,HIGH);
      irsend.sendSony(x,12);
      delay(40);
    }
  Serial.print("H = ");
  Serial.print(h,12);
  Serial.print("\tT = ");
  Serial.print(t,12);
  Serial.println();
}
