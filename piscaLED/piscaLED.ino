// Define o número do pino do LED
const int ledPin = 15;  // O número 15 corresponde ao GPIO 15 do ESP32
 
void setup() {
  // Configura o pino do LED como saída
  pinMode(ledPin, OUTPUT);  // Define o pino como saída para controle do LED
}
 
void loop(){
  // Aumentar a intensidade do brilho do LED
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // A função analogWrite controla a intensidade do LED com PWM (modulação por largura de pulso)
    // A variável dutyCycle vai de 0 a 255, que representa os níveis de intensidade
    analogWrite(ledPin, dutyCycle);  // Aplica o valor do ciclo de trabalho ao pino do LED
    delay(15);  // Pausa de 15 milissegundos entre os ajustes de brilho
  }
 
  // Diminuir a intensidade do brilho do LED
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // A função analogWrite controla a intensidade do LED com PWM
    analogWrite(ledPin, dutyCycle);  // Aplica o valor do ciclo de trabalho ao pino do LED
    delay(15);  // Pausa de 15 milissegundos entre os ajustes de brilho
  }
}