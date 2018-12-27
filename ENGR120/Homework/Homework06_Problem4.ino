/*pin 13 > 470Ω > LED  > Ground
 * 
 *                   >Pin6
 * 5V > NC Switch(L) > 10,000Ω > Ground
 * 
 *                   > Pin7
 * 5V > NC Switch(R) > 10,000Ω > Ground
 * 
 * when switch is pressed(digitalRead()==LOW), it starts looking for that switch to be 
 * unpressed(digitalRead()==HIGH), when it is it changes blinking appropriatly
 */
boolean clickedL = false;
boolean clickedR = false;
boolean blinking=false;
int led = 13;
void setup() {
  pinMode(6, INPUT); //LW
  pinMode(7, INPUT); //RW
  pinMode(led, OUTPUT); //LED
}
void loop() {
  if (digitalRead(6) == LOW) clickedL=true;
  if(clickedL&&digitalRead(6)==HIGH)
  {
    blinking=true;
    clickedL=false;
  }
  if(digitalRead(7)==LOW) clickedR=true;
  if(clickedR&&digitalRead(7)==HIGH)
  {
    blinking=false;
    clickedR=false;
  }
  if(blinking)
  {
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
  }
}
