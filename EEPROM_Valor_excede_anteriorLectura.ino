#include <EEPROM.h>
/*
    Sistema que guarda en una posición de la memoria EEPROM solo cuando su valor exceda a la anterior lectura.
    Funciones:
                 EEPROM.read(posicion) -> posicion entre 0 y 255 a ser leida
                 EEPROM.write(dato); -> elige el tipo de dato
                 EEPROM.update -> actualiza datos
*/

int pos = 0;
String val_ingresado;
int val_actual = 0;
int valor;
String ingreso;
void setup() {
  Serial.begin(9600);
  // Grabar datos iniciales en la memoria
  /* EEPROM.write(pos,val_actual);
    Serial.println(val_actual);
    delay(300);*/
  val_actual = EEPROM.read(pos);
  Serial.println(val_actual);
  Serial.println("Ingrese el valor a guardar");
  delay(200);
}

void loop() {
  if (Serial.available() > 0) {
    ingreso = Serial.readString();
    int tam = ingreso.length();
    char vector[tam];
    ingreso.toCharArray(vector, tam + 1);
    valor = ingreso.toInt();
    if (valor < 255 ) {
      if (valor > val_actual) {
        EEPROM.update(pos, valor);
        Serial.print("Valor actual: ");
        Serial.println(valor);
        Serial.println("Ingrese el valor a guardar");
        delay(200);
        val_actual = valor;
      } else {
        Serial.println("Valor ingresado es menor al valor anterior");
        Serial.print("Valor actual: ");
        Serial.println(val_actual);
        Serial.println("Ingrese el valor a guardar");
        delay(200);
      }
    } else {
      Serial.println("El valor ingresado excede el numero de bits");
    }
  }
}
