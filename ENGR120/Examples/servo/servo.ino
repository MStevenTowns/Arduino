#include <Servo.h>
Servo ser1;
Servo ser2;

void setup() {
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  ser1.attach(2);
  ser2.attach(3);
}

void loop() {
  if (digitalRead(8) == LOW && digitalRead(9) == LOW) backward();
  else if (digitalRead(9) == LOW) right();
  else if (digitalRead(8) == LOW) left();
  else forward();
}

void forward()
{
  ser1.writeMicroseconds(1700);
  ser2.writeMicroseconds(1300);
}
void backward()
{
  ser1.writeMicroseconds(1300);
  ser2.writeMicroseconds(1700);
}
void right()
{
  ser1.writeMicroseconds(1700);
  ser2.writeMicroseconds(1700);
}
void left()
{
  ser1.writeMicroseconds(1300);
  ser2.writeMicroseconds(1300);
}
