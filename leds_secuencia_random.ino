/* Programa de secuencia de LEDs escrito para Arduino MEGA 2560 
   Uso de bucles for para inicialización de pines
   Función random() para determinar leds a encender

   Proyecto didáctico Arduino con mínimos componentes.

  06 (seis) LEDs 3mm
  06 (seis) Resistencias 220 Ohm 
  01 (uno) servo motor RG90
  01 Arduino UNO R3
  01 Protoboard
  Cables M-M cantidad necesaria
*/

#define PIN_INICIO 22
#define CANTIDAD_LEDS 6

void setup() {

  // Inicializando pines
  for(int i=PIN_INICIO; i<(PIN_INICIO + CANTIDAD_LEDS); i++){
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);

}

void loop() {

  // Apagando LEDs
  for(int j=PIN_INICIO; j<(PIN_INICIO + CANTIDAD_LEDS); j++){
    digitalWrite(j, LOW);
  }

  // Pseudoaleatoriamente se decide hasta qué pin encender
  int tope = random(PIN_INICIO, (PIN_INICIO + CANTIDAD_LEDS));

  Serial.print("--- Iniciando secuencia de encendido hasta LED: ");
  Serial.println(tope);
  
  for(int k=PIN_INICIO; k<=tope; k++){
    digitalWrite(k, HIGH);
    Serial.print("Pin ");
    Serial.print(k);
    Serial.print(" ON | ");
    delay(500);
  }
  Serial.println();

  Serial.println("--- Secuencia finalizada!! ---");
  delay(2500);

}
