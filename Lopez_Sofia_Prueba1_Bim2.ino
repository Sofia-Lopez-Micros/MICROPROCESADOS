#include <EEPROM.h>
/*
   Se necesita emular el funcionamiento de un control de auto ChevyStar. Para ello, se tienen las siguientes características.

  • Se cuenta con 4 botones, uno máster y 3 para la contraseña.
  • La contraseña es de 5 dígitos que debe ser la combinación de los 3 botones.
  • El sistema al presionar una vez (solo botón máster) y sin contraseña envía por comunicación serial el mensaje de activado o desactivado.
  • Si es digitada la contraseña es correcta (se presiona la combinación de los 3 botones y luego el máster), envía por mensaje serial
  que se puede encender el carro. Caso contrario, se tendrá hasta 2 intentos más para acertar a la contraseña.
  Si no es el caso, el control se reinicia y genera otra contraseña de forma aleatoria de la combinación de los pulsadores.
  La nueva contraseña se envía por comunicación serial.
*/

#define A 13
#define B 12
#define C 11
int num1 = 0;
int num2 = 0;
int num3 = 0;
int cont = 0;
int funcionamiento = 0;   // variable de interrupt 0
String dato;              // variable de rx serial
char digito0;
char digito1;
char digito2;
char digito3;
char digito4;
int pos0;
int pos1;
int pos2;
int pos3;
int pos4;
String ingreso;
int tam;
int conversion;
int x = 0;
char vector[5];
int a = 0;
void setup() {
  attachInterrupt(0, sistema, FALLING);
  Serial.begin(9600);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  //      EEPROM.write(0, 1);
  //      EEPROM.write(1, 2);
  //      EEPROM.write(2, 3);
  //      EEPROM.write(3, 1);
  //      EEPROM.write(4, 2);
}

void loop() {
  if (funcionamiento == 2) {
    if (digitalRead(A) == LOW) {
      delay(200);
      vector[a] = 1;
      a++;
      Serial.print("1");
      delay(200);
    }
    if (digitalRead(B) == LOW) {
      delay(200);
      vector[a] = 2;
      a++;
      Serial.print("2");
      delay(200);
    }
    if (digitalRead(C) == LOW) {
      delay(200);

      vector[a] = 3;
      a++;
      Serial.print("3");
      delay(200);
    }
  }


  if (funcionamiento == 3 || funcionamiento == 4 || funcionamiento == 5) {
    pos0 = EEPROM.read(0);
    pos1 = EEPROM.read(1);
    pos2 = EEPROM.read(2);
    pos3 = EEPROM.read(3);
    pos4 = EEPROM.read(4);

    if ( (vector[0] == pos0) && (vector[1] == pos1) && (vector[2] == pos2) && (vector[3] == pos3) && (vector[4] == pos4)) {
      Serial.println("La clave ingresada es correcta");
      Serial.println("Puede encender el carro");
      delay(300);
    } else {
      Serial.println("Clave incorrecta");
      delay(300);
      cont++;
      if (cont == 3) {
        Serial.println("Intentos acabados");
        delay(300);
        
      }
    }
  }
}

void sistema () {
  switch (funcionamiento) {
    case 0:
      Serial.println("ACTIVADO");
      funcionamiento ++;
      break;

    case 1:
      Serial.println("Ingrese clave");
      funcionamiento ++;
      break;

    case 2:
      funcionamiento ++;
      break;

    case 3:
      funcionamiento ++;
      break;

    case 4:
      funcionamiento ++;
      break;

    case 5:
      Serial.println("DESACTIVADO");
      funcionamiento = 0;
      break;
  }
}
