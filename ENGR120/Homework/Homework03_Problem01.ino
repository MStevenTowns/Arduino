int a=5;//what port will be given power.
void setup() {
  // put your setup code here, to run once:
  pinMode(a, OUTPUT);
  for(int i=0;i<3;i++)
  {
    digitalWrite(a, HIGH);    // turn the LED on (HIGH is the voltage level)
    delay(800);              // wait
    digitalWrite(a, LOW);     // turn the LED off by making the voltage LOW
    delay(400);               // wait
  }
}
void loop(){
  digitalWrite(a, HIGH);    // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait
  digitalWrite(a, LOW);     // turn the LED off by making the voltage LOW
  delay(1000);              // wait
}
