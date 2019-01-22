
/*
 * Nombre: Sofia Lopez
 * Fecha:  22 de Enero de 2019
 * Instruccion: 
               Estimados estudiantes: Realizar un programa que permita que el conversor análogo digital
               configure al perro guardían a 10,20,30 y 40 segundos. Este proceso se visualiza en una lcd.
*/
#include <TimerOne.h>   //libreria del contador 
#include <avr/wdt.h>  // libreria avr
#include <LiquidCrystal.h>    //libreria para lcd
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); // RS, E, D4, D5, D6, D7 pines de lcd a arduino

int dato; // variable para obtener el CAD 
int i = 0;    // contador 
int on = 0;     // variable para encender el sistema
void setup() {
  lcd.begin(16, 2);   //inicializa la lcd
  attachInterrupt(0, activacion, LOW);  // interrupcion del sistema para activar/desactivar el wdt y timer 
  lcd.setCursor(1, 1);    // ubicacion del cursor 
  lcd.print("RESET");   // impresion de mensaje
  delay(200);     
}
void loop() {
  dato = (analogRead(0) * 5.0 / 1023.0);    // regla de tres para obteneer el CAD
  lcd.setCursor(1, 0);  // ubicacion de cursor en lcd
  lcd.print("CAD:");  // impresion de mensaje 
  lcd.setCursor(6, 0);  // ubicacion de cursor en lcd
  lcd.print(dato);    // impresion de dato CAD
  delay(200);
}

void activacion() { 
  on = 1 - on;
  if (on == 1) {
    wdt_disable(); // desactiva el wdt
  }
  else {
    Timer1.initialize(1000000); // si on es igual a 0 se activa el timer
    Timer1.attachInterrupt(conteo);
  }
}


void conteo() {   // metodo del timer
  i++;
  lcd.setCursor(1, 1);  // ubicacion de cursor en lcd
  lcd.print("Cont:");  // impresion de mensaje 
  lcd.setCursor(6, 1);  // ubicacion de cursor en lcd
  lcd.print(i);    // impresion contador 
  delay(200);
  if (i == 6 && dato == 1) {  // condicion para activar el wdt en 10s
    wdt_enable(WDTO_4S);
  }

  if (i == 16 && dato == 2) { // condicion para activar el wdt en 20s
    wdt_enable(WDTO_4S);
  }

  if (i == 26 && dato == 3) { // condicion para activar el wdt en 30s
    wdt_enable(WDTO_4S);
  }

  if (i == 36 && dato == 4) {   // condicion para activar el wdt en 40s
    wdt_enable(WDTO_4S);
  }
}
