// Luces de afuera //
int led = 13;
int valorLuz = 0;

// Puerta Principal (Bluetooth) //
int puerta = 12; 
char letra;
unsigned long tiempoAnterior = 0;  
int intervalo = 300; 

// Alarma y PIRes //
int LED1 = 7;
int PIR1 = 8;

int LED2 = 6;
int PIR2 = 2;

int LED3 = 5;
int PIR3 = 3;

int value = 0;
int value2 = 0;
int value3 = 0;

const byte buzzer_pin = 10;
byte salida= 11;
 
void setup() {
  // Leds de afuera //
  
  pinMode(led, OUTPUT);
  
  // Puerta Principal //
  
  pinMode(puerta,OUTPUT);
  Serial.begin(9600);

  // Alarma Y PIRes //

  pinMode(LED1, OUTPUT);
  pinMode(PIR1, INPUT);

  pinMode(LED2, OUTPUT);
  pinMode(PIR2, INPUT);

  pinMode(LED3,OUTPUT);
  pinMode(PIR3, INPUT);

  pinMode(buzzer_pin, OUTPUT);
}

void loop() {
  // Puerta Principal (Bluetooth) //

    unsigned long tiempoActual = millis();

    if(Serial.available()>0){
      letra = Serial.read();
    }
    
    switch(letra){
    
    case 'a' :
    digitalWrite(puerta,HIGH);
    break;
    
    case 'b' :
    if (tiempoActual - tiempoAnterior >= intervalo) {
      digitalWrite(puerta,LOW);
      tiempoAnterior = tiempoActual;   // reiniciar el contador
      digitalWrite(puerta,HIGH);
      break;
      }
    case 'c':
    value = digitalRead(PIR1);
    value2 = digitalRead(PIR2);
    value3 = digitalRead(PIR3);
    if (value == 1) {
      digitalWrite(LED1, HIGH);
      delay(00);
      }
    else{
          digitalWrite(LED1, LOW);
    }
    if(value2 == 1){
      digitalWrite(LED2, HIGH);
      delay(00);
    }
    else{
          digitalWrite(LED2, LOW);
    }
    if(value3 == 1){
      digitalWrite(LED3, HIGH);
      delay(00);
    }
    else{
          digitalWrite(LED3, LOW);
    }
    break;
    case 'd':
    value = digitalRead(PIR1);
    if (value == 1) {
      digitalWrite(buzzer_pin, HIGH);
      analogWrite(buzzer_pin, OUTPUT);
      delay(00);
      }
    else
    {
      digitalWrite(buzzer_pin, LOW);
      Serial.println("seguro");
      delay(00);
      }
// Luces de afuera //

  valorLuz = analogRead(A0);
  if (valorLuz > 30){
  	digitalWrite(led, LOW);
  }
  else {
  	digitalWrite(led,HIGH);
  }
// Alarma y PIRes //

  value = digitalRead(PIR1);
  if (value == 1) {
   digitalWrite(buzzer_pin, HIGH);
   analogWrite(buzzer_pin, OUTPUT);
   delay(00);
  }
  else
  {
    digitalWrite(buzzer_pin, LOW);
    Serial.println("seguro");
    delay(00);
  }
  value2 = digitalRead(PIR2);
 	if (value2 == 1) {
		digitalWrite(LED2, HIGH); 
    digitalWrite(buzzer_pin, HIGH);
    Serial.println("¡intruso!");
    analogWrite(buzzer_pin, OUTPUT);
    delay(00);
    //digitalWrite(LED,LOW);   		
  }
  else
  {
    digitalWrite(buzzer_pin, LOW);
    delay(00);
  }

  value3  = digitalRead(PIR3);
 	if (value3 == 1) {
		digitalWrite(LED3, HIGH); 
    digitalWrite(buzzer_pin, HIGH);
    Serial.println("¡intruso!");
    analogWrite(buzzer_pin, OUTPUT);
    delay(00);
  }
  else
  {
    digitalWrite(buzzer_pin, LOW);
    delay(00);
  }
}
}


//puerta

unsigned long tiempoAnteriorPUERTA = 0;
int intervaloPUERTA = 300;
char letra;
int puerta=5;


void setup() {
  pinMode(puerta,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long tiempoActual = millis();

    if(Serial.available()>0)
      {
         letra = Serial.read();
      }
      switch(letra){
      case 'a' :
      digitalWrite(puerta,HIGH);
      break;
      case 'b' :
      digitalWrite(puerta,LOW);
      if (tiempoActual - tiempoAnteriorPUERTA >= intervaloPUERTA){
        tiempoAnteriorPUERTA = tiempoActual;   // reiniciar el contador
      }
      break;
    }
}


//ventilador

unsigned long tiempoAnteriorVENTILADOR = 0;
int intervaloVENTILADOR = 200;

#include "DHT.h" // Incluye la biblioteca DHT
#define DHTPIN 2 // Define el pin digital al que está conectado el DHT11
#define DHTTYPE DHT11 // Especifica que es un sensor DHT11
DHT dht(DHTPIN, DHTTYPE); // Crea una instancia del objeto DHT
int fanpin = 3;

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial
  dht.begin(); // Inicia el sensor
  pinMode(fanpin, OUTPUT);
}

void loop() {
  unsigned long tiempoActual = millis();
    if (tiempoActual - tiempoAnteriorVENTILADOR >= intervaloVENTILADOR){
      tiempoAnteriorVENTILADOR = tiempoActual;   // reiniciar el contador
    }
  
  float t = dht.readTemperature();
  
  if (isnan(t)) {
    Serial.println(F("Fallo al leer del sensor DHT!"));
    return;
  }
  if (t>20){
    digitalWrite(fanpin, HIGH);
  }
  else{
    digitalWrite(fanpin, LOW);
  }
  Serial.print(F("%   Temperatura: "));
  Serial.print(t);
  Serial.println(F("°C"));
}
