/*
   Nombre: Sofia Lopez
   Fecha:  04 de Febrero del 2019
   Instruccion:
               Estimados estudiantes: Realizar un sistema que permita configurar por comunicación serial
               o por pulsadores el modo sleep cada 25 segundos.
*/


#include <LowPower.h> // librería para hacer dormir en cierto periodo al sistema
// periodos de LowPower-> 1S, 2S, 4S, 8S
#include <TimerOne.h>// librería para contador 
int cont = 0;     // variable de contador
void setup() {
  Serial.begin(9600);     // inicialización del monitor serial
  attachInterrupt(0, activar, HIGH );   // interrupcion en el pin 0
}


void loop() {

}
void activar() {     // método de interrupcion, creado en setup
  Serial.println("ON");   // mensaje de activado el sleep, cuando se presiona el pulsador
  delay(100);
  if (cont <= 5) {   //condición para que se active el modo sleep
    cont++;    //aumento de contador
    LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF); // modo sleep por 4 segundos
  } else {
    Serial.println(analogRead(0));    // impresion CAD
    delay(200);   // espera 200 ms
    cont = 0;     // contador vuelve a cero para reinicio de ciclo
  }
}
