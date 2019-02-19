
/*
   Nombre: Sofia Lopez
   Fecha:  22 de Enero de 2019
   Instruccion:
               Estimados estudiantes: Realizar un programa que permita que el conversor análogo digital
               configure al perro guardían a 10,20,30 y 40 segundos. Este proceso se visualiza en una lcd.
*/
#include <EEPROM.h>
#include <avr/wdt.h>  // libreria avr
#include <LiquidCrystal.h>    //libreria para lcd
#include <TimerOne.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); // RS, E, D4, D5, D6, D7 pines de lcd a arduino
#define red 7
#define green 6
#define switch1 4
#define switch2 5
int sw1;
int sw2;

int dato; // variable para obtener el CAD
int on = 0;     // variable para encender el sistema
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);   //inicializa la lcd
  // attachInterrupt(1, dormir, FALLING);
  attachInterrupt(0, activacion, FALLING);
  lcd.setCursor(1, 1);    // ubicacion del cursor
  lcd.print("INICIO");   // impresion de mensaje
  delay(200);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  Timer1.initialize(1000000); // si on es igual a 0 se activa el timer
  Timer1.attachInterrupt(conteo);
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);

  //EEPROM.write(0,0);
  EEPROM.read(0);
}
void loop() {
  //  dato = (analogRead(0) * 5.0 / 1023.0);    // regla de tres para obteneer el CAD
  //  lcd.setCursor(1, 0);  // ubicacion de cursor en lcd
  //  lcd.print("CAD:");  // impresion de mensaje
  //  lcd.setCursor(6, 0);  // ubicacion de cursor en lcd
  //  lcd.print(dato);    // impresion de dato CAD
  //  delay(200);

}

void activacion() {
  on = 1 - on;
  if (on == 1) {
    lcd.setCursor(13, 0);
    lcd.print("ON ");
    delay(100);
    dormir();
    EEPROM.write(5, 1);
  }
  else {
    lcd.setCursor(13, 0);
    lcd.print("OFF");
    delay(100);
    wdt_disable(); // desactiva el wdt
    EEPROM.write(5, 0);
  }
}
void dormir() {
  sw1 = digitalRead(switch1);
  sw2 = digitalRead(switch2);

  if (sw1 == LOW && sw2 == LOW) {

    lcd.setCursor(13, 1);
    lcd.print("0");
    delay(10);
    EEPROM.update(0, 0);
  }

  if (sw1 == HIGH && sw2 == LOW) { // condicion para activar el wdt en 2s
    wdt_enable(WDTO_2S);
    lcd.setCursor(13, 1);
    lcd.print("2");
    delay(10);
    EEPROM.update(0, 1);

  }

  if (sw1 == LOW && sw2 == HIGH) { // condicion para activar el wdt en 4s
    wdt_enable(WDTO_4S);
    lcd.setCursor(13, 1);
    lcd.print("4");
    delay(10);
    EEPROM.update(0, 2);

  }

  if ( sw1 == HIGH && sw2 == HIGH) { // condicion para activar el wdt en 8s
    wdt_enable(WDTO_8S);
    lcd.setCursor(13, 1);
    lcd.print("8");
    delay(10);
    EEPROM.update(0, 3);

  }
}

void conteo() {

}
