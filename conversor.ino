
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
int i = 0;
int sw1;
int sw2;
int inferior;
int superior;
int cont = 0;
String ingreso;
int conversor;

int tam;
String dato; // variable para obtener el CAD
int on = 0;     // variable para encender el sistema
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);   //inicializa la lcd
  // attachInterrupt(1, dormir, FALLING);
  attachInterrupt(0, lectura, FALLING);
  lcd.setCursor(1, 1);    // ubicacion del cursor
  lcd.print("INICIO");   // impresion de mensaje
  delay(200);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);

//  EEPROM.write(0, 0);
//  EEPROM.write(1, 0);
}
void loop() {
  if (i == 2) {
    if (Serial.available() > 0) {
      dato = Serial.readString();
      superior = dato.toInt();
      EEPROM.write(0, superior);
      Serial.println(EEPROM.read(0));
    }
  }

  if (i == 3) {
    if (Serial.available() > 0) {
      dato = Serial.readString();
      inferior = dato.toInt();
      EEPROM.write(1, inferior);
      Serial.println(EEPROM.read(1));
    }
  }
  if (i == 4) {
    conversor = (analogRead(0) * 10.0 / 1023.0);
    Serial.println(conversor);
    delay(2000);
    if (EEPROM.read(0) > superior || EEPROM.read(1) < inferior) {
      Serial.println("ALARMA");
      delay(300);
      digitalWrite(red, HIGH);
    }
  }
}


void lectura() {
  switch (i) {
    case 0:
      Serial.println("ON ");
      i++;
      break;
    case 1:
      Serial.println("Ingrese dato inferior");
      i++;
      break;

    case 2:
      Serial.print("Ingrese dato superior ");
      Serial.println(conversor);
      i++;
      break;

    case 3:
      Serial.println("Compara");
      i++;
      break;

    case 4:
      Serial.println("SISTEMA OFF");
      i = 0;
      break;
  }
}
void conteo() {
}
