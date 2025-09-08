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
 
void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(PIR1, INPUT);

  pinMode(LED2, OUTPUT);
  pinMode(PIR2, INPUT);

  pinMode(LED3,OUTPUT);
  pinMode(PIR3, INPUT);

  pinMode(buzzer_pin, OUTPUT);
  Serial.begin(150); 
}
 
void loop()
{
  value = digitalRead(PIR1);
 	if (value == 1) {
		digitalWrite(LED1, HIGH); 
    digitalWrite(buzzer_pin, HIGH);
    Serial.println("¡intruso!");
    analogWrite(buzzer_pin, OUTPUT);
    delay(00);
    //digitalWrite(LED,LOW);   		
  }
  else
  {
    digitalWrite(LED1, LOW);
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
    digitalWrite(LED2, LOW);
    digitalWrite(buzzer_pin, LOW);
    Serial.println("seguro");
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
    digitalWrite(LED3, LOW);
    digitalWrite(buzzer_pin, LOW);
    Serial.println("seguro");
    delay(00);
  }
  
}
