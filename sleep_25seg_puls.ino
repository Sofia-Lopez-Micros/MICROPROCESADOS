/*
   Nombre: Sofia Lopez
   Fecha:  04 de Febrero del 2019
   Instruccion:
               Estimados estudiantes: Realizar un programa que permita poner al sistema
               19 segundos en modo sleep, se despierte, realice un lectura del conversor análogo digital,
               lo imprima por comunicación serial y vuelva a dormir 19 segundos.
*/


#include <LowPower.h> // librería para hacer dormir en cierto periodo al sistema
// periodos de LowPower-> 1S, 2S, 4S, 8S
#include <TimerOne.h>// librería para contador 
int cont = 0;     // variable de contador
void setup() {
  Serial.begin(9600);     // inicialización del monitor serial
  attachInterrupt(0, activar, HIGH );
}


void loop() {

}
void activar() {     // método conteo de Timer1, creado en setup
  Serial.println("ON");
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
