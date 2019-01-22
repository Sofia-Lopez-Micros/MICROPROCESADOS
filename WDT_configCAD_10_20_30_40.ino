
/*
   Estimados estudiantes: Realizar un programa que permita que el conversor análogo digital
   configure al perro guardían a 10,20,30 y 40 segundos. Este proceso se visualiza en una lcd.
*/
#include <TimerOne.h>
#include <avr/wdt.h>  // libreria avr
#include <LiquidCrystal.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); // RS, E, D4, D5, D6, D7 pines de lcd a arduino

int dato;
float conversion;
int i = 0;
int on = 0;
void setup() {
  lcd.begin(16, 2);
  attachInterrupt(0, activacion, LOW);
  lcd.setCursor(1, 1);
  lcd.print("RESET");
  delay(200);
}
void loop() {
  dato = (analogRead(0) * 5.0 / 1023.0);
  lcd.setCursor(1, 0);
  lcd.print("CAD:");
  lcd.setCursor(6, 0);
  lcd.print(dato);
  delay(200);
}

void activacion() {
  on = 1 - on;
  if (on == 1) {
    wdt_disable();
  }
  else {
    Timer1.initialize(1000000);
    Timer1.attachInterrupt(conteo);
    //    wdt_reset();
    //    wdt_enable(WDTO_4S);
  }
}
//void activacion() {
//  Timer1.initialize(1000000);
//  Timer1.attachInterrupt(conteo);
//  Serial.println("El sistema se reiniciara");
//}

void conteo() {
  i++;
  lcd.setCursor(1, 1);
  lcd.print("Cont:");
  lcd.setCursor(6, 1);
  lcd.print(i);
  delay(200);
  if (i == 6 && dato == 1) {
    wdt_enable(WDTO_4S);
  }

  if (i == 16 && dato == 2) {
    wdt_enable(WDTO_4S);
  }

  if (i == 26 && dato == 3) {
    wdt_enable(WDTO_4S);
  }

  if (i == 36 && dato == 4) {
    wdt_enable(WDTO_4S);
  }
}
