#include "DHT.h"
#define DHTPIN 8   
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600);
dht.begin();
}


void loop() {
float h = dht.readHumidity();
float t = dht.readTemperature();
if (isnan(t) || isnan(h)) {
  Serial.println("Failed to read from DHT");
  }
else {
  Serial.print("Temp= \t");
  Serial.print(t);
  Serial.print(" *C");
  Serial.print("\tHumidity=\t");
  Serial.print(h);
  Serial.print("% ");
  Serial.println();
  delay(500);
 }
}
