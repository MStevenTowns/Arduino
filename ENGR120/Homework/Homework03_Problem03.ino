int LED1=5;
int LED2=6;
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  for(int i = 0;i<5;i++)
  {
    digitalWrite(LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(LED2, LOW);
    delay(300);
    digitalWrite(LED1, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(LED2, HIGH);
    delay(300);
  }
  digitalWrite(LED1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED2, LOW);
  delay(1000);
}
void loop() {
    digitalWrite(LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(LED2, HIGH);
    delay(50);
    digitalWrite(LED1, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(LED2, LOW);
    delay(50);
}
