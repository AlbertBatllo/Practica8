# Practica8: Busos de comunicació IV (UART)

L'objectiu de la pràctica és comprendre el funcionament de la comunicació sèrie asincrona usart (Universal Syncronous Asyncronous Receiver Transmitter).
Aquesta comunicacio és molt utilitzada en totes les pràctiques que hem fet, l'estem usant quan ens referim a la impressora sèrie Serial.println("").

## Codi

```
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
```

## Explicació del codi

**Set Up:**

En el setup inicialitzem els dos serials, el primer serà per llegir i el segon per escriure:

```
void setup() {
 
 Serial.begin(115200);
 Serial2.begin(115200, SERIAL_8N1, 16, 17);
}
```

**Loop:**

dins del loop tenim dos whiles:

```
void loop() { //Choose Serial1 or Serial2 as required
```

Un per llegir:

```
 if (Serial.available()) { // Si hay datos disponibles en la UART0
    char data = Serial.read(); // Se lee un byte de la UART0
    Serial2.write(data); // Se envía el byte a la UART2
  }
 ```
 
 I l'altre per escriure:
 ```
 if (Serial2.available()) { // Si hay datos disponibles en la UART2
    char data = Serial2.read(); // Se lee un byte de la UART2
    Serial.write(data); // Se envía el byte a la UART0
  }
 ```
 Finalment tanquem el loop:
 
 ```
 }
 
 
