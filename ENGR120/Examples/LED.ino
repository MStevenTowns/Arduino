int a = 5;
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(a, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  for(int i=0;i<3;i++)
  {
    digitalWrite(a, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(250);              // wait for a second
    digitalWrite(a, LOW);    // turn the LED off by making the voltage LOW
    delay(250);
  }
  for(int i=0;i<3;i++)
  {
    digitalWrite(a, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(750);              // wait for a second
    digitalWrite(a, LOW);    // turn the LED off by making the voltage LOW
    delay(250);
  }
  for(int i=0;i<3;i++)
  {
    digitalWrite(a, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(250);              // wait for a second
    digitalWrite(a, LOW);    // turn the LED off by making the voltage LOW
    delay(250);
  }
  delay(750);
}
