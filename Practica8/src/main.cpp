#include <Arduino.h>

void setup() {
  Serial.begin(115200); // Se inicia la comunicación por la UART0 con una velocidad de 115200 baudios
  Serial2.begin(115200, SERIAL_8N1, 16, 17); // Se inicia la comunicación por la UART2 con una velocidad de 115200 baudios
  // Los pines 16 y 17 se utilizan para la UART2 en la ESP32
}

void loop() {
  if (Serial.available()) { // Si hay datos disponibles en la UART0
    char data = Serial.read(); // Se lee un byte de la UART0
    Serial2.write(data); // Se envía el byte a la UART2
  }
  
  if (Serial2.available()) { // Si hay datos disponibles en la UART2
    char data = Serial2.read(); // Se lee un byte de la UART2
    Serial.write(data); // Se envía el byte a la UART0
  }
}
