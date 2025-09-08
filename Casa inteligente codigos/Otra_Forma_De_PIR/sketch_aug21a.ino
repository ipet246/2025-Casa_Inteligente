int pir = 2;
int led = 3; 
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(pir)==HIGH){
    digitalWrite(led, HIGH);
    Serial.println("high");
  }
  else {
    digitalWrite(led, LOW);
    Serial.println("low");
  }
  delay(1000);
  
}
