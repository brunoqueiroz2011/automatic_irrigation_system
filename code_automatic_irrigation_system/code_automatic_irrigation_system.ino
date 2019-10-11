/*
 * Autor: Bruno Queiroz
 * Data: 11/09/2019
 * Função: Programa responsável por monitorar o solo, para acionar a bomba d'água 
 *         e os LEDs funcionarão como sinal de estado do solo.
*/

#define analog_sinal_pin A0
#define pin_led_red 4
#define pin_led_green 5
#define pin_water_pump 6

int analog_value;

void setup() {
  Serial.begin(9600);
  pinMode(analog_sinal_pin, INPUT);
  pinMode(pin_led_red, OUTPUT);
  pinMode(pin_led_green, OUTPUT);
  pinMode(pin_water_pump, OUTPUT);  
}

void loop() {
  //Realiza a monitoração do pino A0 do sensor
  analog_value = analogRead(analog_sinal_pin);

  //Mostra o valor da porta analogica no serial monitor
  Serial.print("Porta analogica: ");
  Serial.print(analog_value);

  //Desliga os LEDs
  turnOffLeds();
  
  //Verifica solo não esta umido, para acende
  if(analog_value > 0 && analog_value < 400){
    Serial.println(" Status: Solo umido");
    digitalWrite(pin_led_green, HIGH);  
    digitalWrite(pin_water_pump, LOW);
  }
  
  //Verifica solo não esta umido, para acende
  if(analog_value > 800 && analog_value < 1024){
    Serial.println(" Status: Solo seco");
    digitalWrite(pin_led_red, HIGH);        
    digitalWrite(pin_water_pump, HIGH);
  }
  
  delay(100);
}

void turnOffLeds()
{
  digitalWrite(pin_led_red, LOW);
  digitalWrite(pin_led_green, LOW);  
}
