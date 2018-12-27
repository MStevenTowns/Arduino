/*
 * pin 13 > 470Ω > LED > NO Switch > Ground
 * When the switch is pressed, the circuit is complete, and the light blinks
 */
int led=13;
void setup() {
  pinMode(led, OUTPUT);
}
void loop() {
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  delay(100);
}
