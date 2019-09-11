/*
 * Autor: Bruno Queiroz
 * Data: 11/09/2019
 * Função: Programa responsavel por ficar monitorando o solo onde estar a planta,
 *         monitorar o nivel da água do reservatorio para acionar a bomba d'água 
 *         junto com os leds que funcionará como sinal para o usuário se o reservatorio
 *         precisa de mais água ou não.
*/

#define analog_sinal_pin A0
#define analog_reservoir_pin A1
#define pin_led_red 4
#define pin_led_green 5
#define pin_water_pump 6
#define pin_reservoir_limit 7

int reservoir_sensor;
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

  //Verifica solo não esta umido, para acende
  if(analog_value > 800 && analog_value < 1024){    
    digitalWrite(pin_water_pump, HIGH);
  }
  
  delay(100);
}

void turnOffLeds()
{
  digitalWrite(pin_led_red, LOW);
  digitalWrite(pin_led_green, LOW);  
}

void turnOnLeds()
{
  digitalWrite(pin_led_red, HIGH);
  digitalWrite(pin_led_green, HIGH);  
}

void turnOnSensors() {
  digitalWrite(analog_sinal_pin,HIGH);
  digitalWrite(analog_reservoir_pin,HIGH); 
}

void turnOffSensors() {
  digitalWrite(analog_sinal_pin,LOW);
  digitalWrite(analog_reservoir_pin,LOW); 
}

int readReservoirSensor() {
  turnOnSensors();
  delay(10);
  return analogRead(analog_reservoir_pin);
  turnOffSensors();
}
