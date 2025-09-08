int pir=3;
int led=2;
int pir2=5;
int led2=4;
int pir3=6;
int led3=7;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(pir2, INPUT);
  pinMode(led3, OUTPUT);
  pinMode(pir3, INPUT);


}

void loop()
{
  if (digitalRead(pir) == HIGH){
    digitalWrite(led, HIGH);
  }
  else{
     digitalWrite(led, LOW);
  }
  if (digitalRead(pir2) == HIGH){
    digitalWrite(led2, HIGH);
  }
  else{
     digitalWrite(led2, LOW);
  }
  if (digitalRead(pir3) == HIGH){
    digitalWrite(led3, HIGH);
  }
  else{
    digitalWrite(led3, LOW);
  }
}