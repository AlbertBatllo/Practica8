# Practica8: Busos de comunicació IV (UART)

L'objectiu de la pràctica és comprendre el funcionament de la comunicació sèrie asincrona usart (Universal Syncronous Asyncronous Receiver Transmitter).
Aquesta comunicacio és molt utilitzada en totes les pràctiques que hem fet, l'estem usant quan ens referim a la impressora sèrie Serial.println("").

## Codi

```
#include <Arduino.h>

void setup() {
 
 Serial.begin(115200);
 Serial2.begin(115200);
}
 
void loop() { //Choose Serial1 or Serial2 as required
 while (Serial.available()) {
   Serial2.print(char(Serial.read()));
 }
 while (Serial2.available()) {
   Serial.print(char(Serial2.read()));
 }
}
```

## Explicació del codi

**Set Up:**

En el setup inicialitzem els dos serials, el primer serà per llegir i el segon per escriure:

```
void setup() {
 
 Serial.begin(115200);
 Serial2.begin(115200);
}
```

**Loop:**

dins del loop tenim dos whiles:

```
void loop() { //Choose Serial1 or Serial2 as required
```

Un per llegir:

```
 while (Serial.available()) {
   Serial2.print(char(Serial.read()));
 }
 ```
 
 I l'altre per escriure:
 ```
  while (Serial2.available()) {
   Serial.print(char(Serial2.read()));
 }
 ```
 Finalment tanquem el loop:
 
 ```
 }
 
 
