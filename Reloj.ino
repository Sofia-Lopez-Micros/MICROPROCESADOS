/*
   Nombre: Sofia Lopez
   Fecha:  04 de Febrero del 2019
   Instruccion:
                Estimados estudiantes: Realizar un reloj dentro del arduino
                con el menor coste computacional que se visualiza en una LCD
                (apagar los periféricos que no se usen).
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); // RS, E, D4, D5, D6, D7 pines de lcd a arduino
#include <MsTimer2.h>   // librería del contador
#include <avr/sleep.h>  // libreria para modos sleep
#include <avr/power.h>
int on = 0; // variable para ON/OFF e sistema
int seg = 0;  //variable para segundos del reloj
int minutos = 0;  // variable para los minutos del reloj
int hora = 0;     // variable para la hora del reloj

void setup() {
  set_sleep_mode(SLEEP_MODE_IDLE);  // Dormir la memoria del programa
  set_sleep_mode(SLEEP_MODE_ADC); //Apagar o dormir los conversores análogos digitales
  set_sleep_mode(SLEEP_MODE_PWR_SAVE);   //Dormir memorias
  set_sleep_mode(SLEEP_MODE_STANDBY);   //Modo de ahorro
  sleep_enable(); //Deshabilita la entrada de modos sleep
  lcd.begin(16, 2); // inicializa la lcd
  MsTimer2::set(1000, rutina);  // metodo rutina para el contador
  lcd.setCursor(4, 1);  // ubicacion de cursor en lcd
  lcd.print("00:00:00");  // impresion en lcd
  attachInterrupt(0, sistema, LOW); // intererupcion para encender y apagar el sistema
}

void loop() {
  power_adc_disable();  // apaga  periférico adc
  power_spi_disable();  // apaga  periférico spi
  power_timer0_disable();  // apaga  periférico timer0
  
}

void sistema() {  // metodo para el sistema 
  on = 1 - on;
  if (on == 1) {
    lcd.setCursor(5, 0);
    lcd.print("INICIO");
    MsTimer2::start();
  }
  else {
    MsTimer2::stop();
    lcd.setCursor(5, 0);
    lcd.print("PARAR ");
  }
}

void rutina() {   // metodo para el reoj
  seg++;
  if (seg <= 60) {
    if (seg < 10) {
      lcd.setCursor(10, 1);
      lcd.print("0");
      lcd.setCursor(11, 1);
      lcd.print(seg);
    } else if (seg <= 59) {
      lcd.setCursor(10, 1);
      lcd.print(seg);
    }
    if (seg == 60) {
      lcd.setCursor(10, 1);
      lcd.print("00");
      seg = 0;
      minutos++;
      if (minutos <= 60) {
        if (minutos < 10) {
          lcd.setCursor(7, 1);
          lcd.print("0");
          lcd.setCursor(8, 1);
          lcd.print(minutos);
        } else if (minutos <= 59) {
          lcd.setCursor(7, 1);
          lcd.print(minutos);
        }

        if (minutos == 60) {
          lcd.setCursor(7, 1);
          lcd.print("00");
          minutos = 0;
          hora++;
          if (hora <= 24) {
            if (hora < 10) {
              lcd.setCursor(4, 1);
              lcd.print("0");
              lcd.setCursor(5, 1);
              lcd.print(hora);
            } else if (hora <= 23) {
              lcd.setCursor(4, 1);
              lcd.print(hora);
            }

            if (hora == 24) {
              lcd.setCursor(4, 1);
              lcd.print("00:00:00");
              seg = 0;
              minutos = 0;
              hora = 0;

            }
          }
        }
      }
    }
  }
}
