/*
   CONTADOR VISUALIZADO EN DIAPLAYS 
   el uso de displays se hace mediante la multiplexación

   Configuración:
      Primer display pertenece a las unidades
      Segundo display pertenece a las decenas

      El contador se hace mediante pulsadores uno para aumentar(b1) y otro para disminuir(b2)
      El contador empieza en 1 y termina en 40
      
   Se crea un metodo llamado "display" para la sucesión de números del 0 al 9 
     
 *  */
int A = 5;
int B = 4;
int C = 3;
int D = 2;
int b1 = 6;
int b2 = 7;

int i = 1;
int dec = 9;
int uni = 8;
int unidades;
int decenas;

void setup() {
  // put your setup code here, to run once:

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);

  pinMode(b1, INPUT);
  pinMode(b2, INPUT);

  pinMode(dec, OUTPUT);
  pinMode(uni, OUTPUT);
}

void loop() {
  
  // pulsador para aumentar
  if (digitalRead(b1) == HIGH ) {
    delay(100);
    i++;
  }
  if (i > 39) {
    i = 40;
  }
  decenas = i / 10;
  unidades = i - (decenas * 10);

  // pulsador para disminuir
  if (digitalRead(b2) == HIGH) {
    delay(100);
    i--;
    if (i < 1) {
      i = 1;
    }
    decenas = i / 10;
    unidades = i - (decenas * 10);
  }

  // unidades

  digitalWrite(uni, HIGH);
  digitalWrite(dec, LOW);
  display(unidades);
  delay(100);

  // decenas
  digitalWrite(uni, LOW);
  digitalWrite(dec, HIGH);
  display(decenas);
  delay(100);
}
void display(int j) {

  switch (j) {

    //Numero 0
    case 0:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;

    //Numero 1
    case 1:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;

    //Numero 2
    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;

    //Numero 3
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;

    //Numero 4
    case 4:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;

    //Numero 5
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;

    //Numero 6
    case 6:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;

    //Numero 7
    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;

    //Numero 8
    case 8:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;

    //Numero 9
    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
  }
}
