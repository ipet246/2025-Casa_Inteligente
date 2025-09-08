int puerta = 6;
char letra;
void setup() {
  pinMode(puerta,OUTPUT);
  Serial.begin(9600);
}
void loop() {
    if(Serial.available()>0){
      letra = Serial.read();
    }
    
    switch(letra){
      case 'a' :
      digitalWrite(puerta,HIGH);
      break;
    
      case 'b' :
      digitalWrite(puerta,LOW);
      delay(30);   
      digitalWrite(puerta,HIGH);
      break;
    }
}