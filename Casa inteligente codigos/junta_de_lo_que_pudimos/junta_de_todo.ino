// Puerta Principal (Bluetooth) //
int puerta = 12; 
char letra;

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

void setup(){
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
  //Puerta (Bletooth) y Alarmas//
  unsigned long tiempoActual = millis();

    if(Serial.available()>0){
      letra = Serial.read();
    }
    
    switch(letra){
    
    case '1' :
    digitalWrite(puerta,HIGH);
    break;
    
    case '2' :
    digitalWrite(puerta,LOW);
    delay(30);   
    digitalWrite(puerta,HIGH);
    break;

    case '3':
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

    case '4':
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
    break;
    }
}
