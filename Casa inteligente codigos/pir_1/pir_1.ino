int pir=10;
int led=8;

int pir2=11;
int led2=7;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(pir2, INPUT);
}
void loop() {
  if (digitalRead(pir) == HIGH){
    digitalWrite(led, HIGH);
    delay(00);
  }
  else{
    digitalWrite(led, LOW);
    delay(00);
  }
  
  if (digitalRead(pir2) == HIGH){
    digitalWrite(led2, HIGH);
    delay(00);
  }
  else{
    digitalWrite(led2, LOW);
    delay(00);
  }
}