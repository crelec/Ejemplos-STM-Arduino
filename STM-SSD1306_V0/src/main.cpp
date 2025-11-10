#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int contador = 0;

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("Fallo al iniciar pantalla SSD1306");
    for(;;);
  }

  display.clearDisplay();
}

void loop() {
  display.clearDisplay();          // Borra pantalla
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  display.print("Cont: ");
  display.println(contador);

  display.display();               // Actualiza pantalla

  contador++;
  delay(1000);                     // Espera 1 segundo
}
