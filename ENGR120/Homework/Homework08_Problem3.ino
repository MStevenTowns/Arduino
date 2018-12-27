void setup() {
  pinMode(3, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
}

void loop() {
  if (digitalRead(8) == LOW && digitalRead(9) == HIGH)
  {
    digitalWrite(3, HIGH);
    delayMicroseconds(1300);
    digitalWrite(3, LOW);
  }
  else if (digitalRead(9) == LOW && digitalRead(8) == HIGH)
  {
    digitalWrite(3, HIGH);
    delayMicroseconds(1700);
    digitalWrite(3, LOW);
  }
  else
  {
    digitalWrite(3, HIGH);
    delayMicroseconds(1500);
    digitalWrite(3, LOW);
  }
  delay(20);
}
