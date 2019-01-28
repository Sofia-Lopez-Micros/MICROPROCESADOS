#define ARM_MATH_CM3 //cortex M3
#include <arm_math.h>
#define tam_inputSignal 640
extern float32_t Points_ecg_1kHz_15kHz[tam_inputSignal];
float32_t promedio;
float32_t tam_impl 29
float32_t Impulse_response;
float32_t signalOut[tam_inputSignal + tam_impl]
float32_t des_estand;
float32_t var;
uint32_t i = 0;
void setup() {
  Serial.begin(9600);
  //promedio
  arm_mean_f32(&Points_ecg_1kHz_15kHz[0], tam_inputSignal, &promedio);
  Serial.println(promedio);
  //varianza
  arm_var_f32(&Points_ecg_1kHz_15kHz[0], tam_inputSignal, &var);
  Serial.println(var);
}

void loop() {
  /*for(; i<tam_inputSignal; i++ ){
    promedio=promedio/tam_inputSignal;
    Serial.println(promedio);
    }*/
  
  convolucion(Points_ecg_1kHz_15kHz,
              Impulse_response,
              tam_inputSignal,
              tam_impl);
  plot_sig(signalOut,
           tam_inputSignal + tam_impl);
}

void plot_sig(float32_t*sig_entrada, uint32_t tam_sig) {
  uint32_t i;
  for (i = 0; i < tam_sig; i++) {
    Serial.println(sig_entrada[i] * 100);
    delay(10);
  }
}

void convolucion(float32_t * sig_entrada ,
                 float32_t * sig_impulse,
                 uint32_t tam_sig_entr,
                 uint32_t tam_impulse) {
  uint32_t i, j;
  for (i = 0; i < tam_sig_entr; i++) {
    signalOut[i + j] = signalOut[i + j] + sig_entrada[i] * sig_impulse[j];
  }

}
