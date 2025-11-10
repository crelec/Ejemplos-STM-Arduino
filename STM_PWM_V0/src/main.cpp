#include <Arduino.h>

HardwareTimer timer4(TIM4);

int freq = 1000; //Frecuencia inicial en Hz
int duty = 0;    // Ciclo de trabajo inicial en %

void flushSerialIn() {
  while (Serial.available()) Serial.read();
}

void updatePWM() {
  timer4.setPWM(1, D10, freq, 0); 
  delay(2);
  uint32_t arr = timer4.getOverflow();
  uint32_t pulse = (arr * duty) / 100;
  timer4.setCaptureCompare(1, pulse);
}

void setup() {
  Serial.begin(115200);
  delay(300);

  Serial.println("\n=== CONTROL PWM NUCLEO-F446RE ===");
  Serial.println("Salida PWM: D10 (TIM4_CH1)");
  Serial.println("Frecuencia: 1000 Hz");
  Serial.println("Ciclo inicial: 0% (DESACTIVADO)");
  Serial.println("\nIngrese el ciclo de trabajo (0 - 100)% y presione ENTER.\n");

  updatePWM(); // Inicia en 0%
}

void loop() {

  if (!Serial.available()) return;

  duty = Serial.parseInt(); // Leer número ingresado

  flushSerialIn(); // LIMPIA LOS '\n' Y '\r'

  // Validar rango
  duty = constrain(duty, 0, 100);

  updatePWM(); // Aplicar el nuevo PWM

  Serial.print("Ciclo de trabajo actualizado a: ");
  Serial.print(duty);
  Serial.println("% \n");
}