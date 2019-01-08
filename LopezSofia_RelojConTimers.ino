
#include <LiquidCrystal.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); // RS, E, D4, D5, D6, D7 pines de lcd a arduino
#include <MsTimer2.h>

int on = 0;
int seg = 0;
int minutos = 0;
int hora =0;

void setup() {
  lcd.begin(16, 2);
  MsTimer2::set(1000, rutina);
  lcd.setCursor(4, 1);
  lcd.print("00:00:00");
  attachInterrupt(0, sistema, LOW);
}

void loop() {
}

void sistema() {
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

void rutina() {
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
