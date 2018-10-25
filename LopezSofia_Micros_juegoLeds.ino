/* 
 *  Título: Deber #1 Juego de leds
 *  Nombre: Sofía López
 *  Encender y apagar leds mediante juegos de luces
 *  Estructuras de programación:
       *   pinMode(pin, MODE);
                    MODE: INPUT OR OUTPUT
       *   digitalWrite(pin,MODE);
                           MODE: HIGH OR LOW
       *   delay(ms); 
       *   Random(min,máx);
 *   
 *   SECCIONES DEL PROGRAMA:
 *   1.- juego de luces que se prendan secuencialmente los leds impares(7,9,11)
 *   2.- programa que se enciendan uno por uno los leds pares(6,8,10)
 *   3.- juego que se enciendan y apaguen los leds de forma aleatoria con la función random()
*/

int pin;

void setup() {
  // put your setup code here, to run once:
  for(pin=6; pin<=11 ;pin++){
  pinMode(pin, OUTPUT);
    }
    pin=0;
  randomSeed(6);
}

void loop() {

    // PRIMERA SECCIÓN
      for(pin=7; pin<=11; pin=pin+2){
      digitalWrite(pin,HIGH);
      delay(200);      
      }
      for(pin=7; pin<=11; pin=pin+2){
      digitalWrite(pin,LOW);
      delay(200);      
      }
      pin=0;


    // SEGUNDA SECCIÓN
      for(pin=6; pin<=10; pin=pin+2){
      digitalWrite(pin,HIGH);
      delay(200);      
      digitalWrite(pin,LOW);
      delay(200);      
      }
      pin=0;

    
    // TERCERA SECCIÓN
     
      for(pin=6; pin<=11; pin=random(6,12)){
      digitalWrite(pin,HIGH);
      delay(200);      
      digitalWrite(pin,LOW);
      delay(200);      
      }
      pin=0;

      }
