#include <Arduino.h>

#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(115200);
  delay(1000);
  Serial.println("Buscando dispositivos I2C...");
  
  for (byte i = 1; i < 127; i++) {
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0) {
      Serial.print("Encontrado dispositivo en 0x");
      Serial.println(i, HEX);
      delay(5);
    }
  }
}

void loop() {
  
}
