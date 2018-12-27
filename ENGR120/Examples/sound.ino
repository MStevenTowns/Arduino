int pin = 7;
void setup() {
  pinMode(pin, OUTPUT);

}
int change = 10;
void loop() {
  for (int i = 1500; i > 300; i -= change)
  {
    digitalWrite(pin, HIGH);
    delayMicroseconds(i);
    digitalWrite(pin, LOW);
    delayMicroseconds(i);
  }
  delay(300);
  for (int i = 1500; i > 300; i -= change)
  {
    digitalWrite(pin, HIGH);
    delayMicroseconds(i);
    digitalWrite(pin, LOW);
    delayMicroseconds(i);
  }
  for (int i = 300; i < 1500; i += change)
  {
    digitalWrite(pin, HIGH);
    delayMicroseconds(i);
    digitalWrite(pin, LOW);
    delayMicroseconds(i);
  }
  delay(300);
}
