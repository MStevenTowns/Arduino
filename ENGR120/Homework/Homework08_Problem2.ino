void setup() {
  pinMode(3, OUTPUT); //Both servos connected to same lines
}

void loop() {
  digitalWrite(3, HIGH);
  delayMicroseconds(1500);
  digitalWrite(3, LOW);
  delay(20);
}
