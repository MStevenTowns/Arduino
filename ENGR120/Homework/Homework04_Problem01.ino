int LED1=11;
int LED2=12;
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  for(int i=0;i<10;i++)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    delay(100);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    delay(100);
  }
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(1000);
  for(int i=0;i<4;i++)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    delay(300);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    delay(300);
  }
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(500);
}
