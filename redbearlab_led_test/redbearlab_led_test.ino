#include <SPI.h>
#include <BLEPeripheral.h>

#define LED_PIN 6
#define BLE_REQ 9
#define BLE_RDY 8
#define BLE_RST UNUSED

BLEPeripheral blePeripheral = BLEPeripheral(BLE_REQ, BLE_RDY, BLE_RST);
BLEService ledService = BLEService("FF10");
BLECharCharacteristic switchCharacteristic = BLECharCharacteristic("FF11", BLERead | BLEWrite);
BLEDescriptor switchDescriptor = BLEDescriptor("2901", "Switch");
BLEUnsignedCharCharacteristic dimmerCharacteristic = BLEUnsignedCharCharacteristic("FF12", BLERead | BLEWrite);
BLEDescriptor dimmerDescriptor = BLEDescriptor("2901", "Dimmer");

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_PIN, OUTPUT);
  Serial.println(9600);

  blePeripheral.addAttribute(ledService);
  blePeripheral.addAttribute(switchCharacteristic);
  blePeripheral.addAttribute(switchDescriptor);
  blePeripheral.addAttribute(dimmerCharacteristic);
  blePeripheral.addAttribute(dimmerDescriptor);
  switchCharacteristic.setEventHandler(BLEWritten, switchCharacteristicWritten);
  dimmerCharacteristic.setEventHandler(BLEWritten, dimmerCharacteristicWritten);
    blePeripheral.setAdvertisedServiceUuid(ledService.uuid());
    blePeripheral.setLocalName("LED");
    blePeripheral.begin();

  }

  void loop() {
  // put your main code here, to run repeatedly:
  blePeripheral.poll();
}

void switchCharacteristicWritten(BLECentral& central, BLECharacteristic& characteristic) {

if (switchCharacteristic.value()) {
  Serial.println(F("LED ON"));
  digitalWrite(LED_PIN, HIGH);
}else{
  Serial.println(F("LED OFF"));
  digitalWrite(LED_PIN, LOW);
}
}

void dimmerCharacteristicWritten(BLECentral & central, BLECharacteristic& characteristic) {
  Serial.print(F("Dimmer set to: "));
  Serial.println(dimmerCharacteristic.value());

  analogWrite(LED_PIN, dimmerCharacteristic.value());
}

