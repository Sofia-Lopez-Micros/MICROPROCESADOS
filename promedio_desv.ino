
int cont = 0;
float promedio = 0;
float desEs = 0; //desviacion estandar
float desEsTotal = 0;
extern float Points_ecg[640];
void setup() {
  Serial.begin(9600);

}

void loop() {
  for (; cont < 10; cont++) {
    promedio = promedio + Points_ecg[cont];

  }
  promedio = promedio / 10;
  Serial.println(promedio);

  cont = 0;
  for (; cont < 10; cont++) {
    desEs = desEs + pow(Points_ecg[cont] - promedio, 2); //pow(valor,potencia)
    desEs = desEs / 9;
    desEsTotal = sqrt(desEs);
    Serial.println(desEsTotal);
  }
}
