
/*  UNIVERSIDAD TECNICA DEL NORTE
      FACULTAD DE INGENIERIA EN CIENCIAS APLICADAS
  CARRERA DE INGENIERIA ELECTRONICA Y REDES DE COMUNICACION
    NOMBRE: Sofia Lopez
    DEBER: Contador de vocales*/

int x = 0;
int cont = 0;
String pal;
int tam;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ((Serial.available() > 0) ) {
    pal = Serial.readString();
    tam = pal.length();
    char vector[tam];
    pal.toCharArray(vector, tam + 1);
    for (x ; x < tam; x++) {
      if ((vector[x] == 'a') || (vector[x] == 'A') ) {
        cont++;
      }
      if ((vector[x] == 'e') || (vector[x] == 'E') ) {
        cont++;
      }
      if ((vector[x] == 'i') || (vector[x] == 'I') ) {
        cont++;
      }
      if ((vector[x] == 'o') || (vector[x] == 'O') ) {
        cont++;
      }
      if ((vector[x] == 'u') || (vector[x] =='U') ) {
        cont++;
      }

    } //Serial.println("");
    Serial.println(cont);
    delay(200);

  } 
}
