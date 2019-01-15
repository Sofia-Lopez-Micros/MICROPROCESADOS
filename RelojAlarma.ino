
#include <LiquidCrystal.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); // RS, E, D4, D5, D6, D7 pines de lcd a arduino
#include <MsTimer2.h>

int on = 0;
int seg = 0;
int minutos = 0;
int hora = 0;
int pulsador = 5;
int alarma;
String hora_alarma;
String minutos_alarma;
int cont = 0;
void setup() {
  pinMode(pulsador, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  MsTimer2::set(1000, rutina);
  lcd.setCursor(8, 0);
  lcd.print("00:00:00");
  attachInterrupt(0, sistema, LOW);
}

void loop() {

  if (digitalRead(pulsador) == HIGH && cont == 0) {
    lcd.setCursor(0, 1);
    lcd.print("Alarma");
    lcd.setCursor(8, 1);
    lcd.print("00:00:00");
    Serial.println("   CONFIGURE LA ALARMA   ");
    Serial.println("Ingrese la hora, formato(hora:minutos)");
    Serial.println("Ejemplo: 05:15");
    delay(1000);
    if (Serial.available() > 0) {
      hora_alarma = Serial.readString();
      int hora_alarma1=hora_alarma.toInt();
      lcd.setCursor(8, 1);
      lcd.print(hora_alarma);
      cont++;
    }
  }

  if (digitalRead(pulsador) == HIGH && cont == 1) {
    Serial.println("Alarma encendida");
    delay(200);
    if (Serial.available() > 0) {
      hora_alarma = Serial.readString();
      lcd.setCursor(8, 1);
      lcd.print(hora_alarma);
      cont++;
    }
  }
  if ( digitalRead(pulsador) == HIGH && cont == 3) {

  }

  if (minutos_alarma!= 0 && hora_alarma != 0 && minutos == minutos_alarma  && hora==hora_alarma ) {
    delay(400);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("DESPIERTAA!!");
    delay(2000);
  }
}


void sistema() {
  on = 1 - on;
  if (on == 1) {
    lcd.setCursor(0, 0);
    lcd.print("INICIO");
    MsTimer2::start();
  }
  else {
    MsTimer2::stop();
    lcd.setCursor(0, 0);
    lcd.print("PARAR ");
  }
}

void rutina() {
  seg++;
  if (seg <= 60) {
    if (seg < 10) {
      lcd.setCursor(14, 0);
      lcd.print("0");
      lcd.setCursor(15, 0);
      lcd.print(seg);
    } else if (seg <= 59) {
      lcd.setCursor(14, 0);
      lcd.print(seg);
    }
    if (seg == 60) {
      lcd.setCursor(14, 0);
      lcd.print("00");
      seg = 0;
      minutos++;
      if (minutos <= 60) {
        if (minutos < 10) {
          lcd.setCursor(11, 0);
          lcd.print("0");
          lcd.setCursor(12, 0);
          lcd.print(minutos);
        } else if (minutos <= 59) {
          lcd.setCursor(11, 0);
          lcd.print(minutos);
        }

        if (minutos == 60) {
          lcd.setCursor(11, 0);
          lcd.print("00");
          minutos = 0;
          hora++;
          if (hora <= 24) {
            if (hora < 10) {
              lcd.setCursor(8, 0);
              lcd.print("0");
              lcd.setCursor(9, 0);
              lcd.print(hora);
            } else if (hora <= 23) {
              lcd.setCursor(8, 0);
              lcd.print(hora);
            }

            if (hora == 24) {
              lcd.setCursor(8, 0);
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
