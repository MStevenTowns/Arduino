/*Pin7 > NO switch1 > buzzer > Ground
 *     > No switch2 ^
 *     
 *Pin6 > Servo control >Ground
 *5V   > Servo Power > Ground
 *      
 *5V > photoResistor > APin3
 *                   > 10,000 Resistor > Ground
 */

#include <Servo.h>
Servo ser;
int buzz = 7;
int photo = 3;

void setup() {
  ser.attach(6);
  pinMode(buzz, OUTPUT);
}

void loop() {
  int test = analogRead(3);
  //Serial.println(test);
  if (test < 600) ser.writeMicroseconds(1700);
  else if (test > 800) ser.writeMicroseconds(1300);
  else ser.writeMicroseconds(1500);
  sound();
}

void sound()
{
  int change = 8;
  for (int i = 1500; i > 300; i -= change)
  {
    digitalWrite(buzz, HIGH);
    delayMicroseconds(i);
    digitalWrite(buzz, LOW);
    delayMicroseconds(i);
  }
  delay(300);
  for (int i = 1500; i > 300; i -= change)
  {
    digitalWrite(buzz, HIGH);
    delayMicroseconds(i);
    digitalWrite(buzz, LOW);
    delayMicroseconds(i);
  }
  for (int i = 300; i < 1500; i += change)
  {
    digitalWrite(buzz, HIGH);
    delayMicroseconds(i);
    digitalWrite(buzz, LOW);
    delayMicroseconds(i);
  }
  delay(300);
}

