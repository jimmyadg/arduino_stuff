#include <IRremote.h>
#include "DHT.h"

#define DHTPIN A0   
#define DHTTYPE DHT11 

IRsend irsend;
DHT dht(DHTPIN, DHTTYPE);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  //float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  
  for(int i =0; i<3; i++){
    irsend.sendSony(t,12);
    delay(100);
  }  
}
