#include <SPI.h>
#include <EEPROM.h>
#include <boards.h>
#include <RBL_nRF8001.h>
#include <Servo.h>

#define ledPin 12
#define fadePin 11
#define potPin A5
void setup() {

  ble_begin();
  Serial.begin(57600);
  pinMode(ledPin, OUTPUT);

}


void loop() {
  static boolean analog_enabled = false;
  while (ble_available()) {
    byte data0 = ble_read();
    byte data1 = ble_read();
    byte data2 = ble_read();
    if (data0 == 0x01) {
      if (data1 == 0x01) digitalWrite(ledPin, HIGH);
      else digitalWrite(ledPin, LOW);

    }
    else if (data0 == 0xA0) // Command is to enable analog in reading
    {
      if (data1 == 0x01)
        analog_enabled = true;
      else
        analog_enabled = false;
    }
    else if (data0 == 0x02) // Command is to control PWM pin
    {
      analogWrite(potPin, data1);
    }
    else if (data0 == 0x04)
    {
      analog_enabled = false;
      digitalWrite(ledPin, LOW);
      analogWrite(potPin, 0);
    }
  }
  if (analog_enabled)  // if analog reading enabled
  {
    // Read and send out
    uint16_t value = analogRead(potPin); 
    ble_write(0x0B);
    ble_write(value >> 8);
    ble_write(value);
  }
  ble_do_events();
}

