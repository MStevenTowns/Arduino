/*       * 5v > Left Servo > Ground
 *
 * 5v > Right Servo > Ground
 *
 * Pin6 > Left Servo
 *
 * Pin7 > Right Servo
 *
 * 5V > Photoresistor > 10k ohm Resistor > Ground
 *                    >analogInput5
 * */

#include <Servo.h>
Servo left;
Servo right;
int light;
void challenge();
void setup()
{
  left.attach(6);
  right.attach(7);
  Serial.begin(9600);
  challenge();
}
void loop() {}

void challenge()
{
  photoResistor();
  chemicals();
  delay(5000);//10 second delay
  battery();
  car();
  delay(5000);//10 second delay
  pump();
  delay(5000);//10 second delay
  beam();
  delay(5000);//10 second delay
  path();
  left.detach();
  right.detach();
}


void photoResistor()
{
  forward();//move to shade
  delay(1500);
  back();//leave duck
  delay(425);
  rightTurn();//face chemicals
  delay(700);
}

void chemicals()
{
  forward();//move to chemicals
  delay(3000);
  rightTurn();//face base
  delay(900);
  forward();//move to base
  delay(1500);
  halt();
}

void battery()
{
  forward();//to corner of grate
  delay(2400);
  leftTurn();//face up
  delay(250);
  forward(); //pass grate
  delay(1500);
  leftTurn();//angle toward resistor
  delay(480);
  forward();//move to resistor
  delay(3400);
  back();//leave duck
  delay(550);
  leftTurn();//face car
  delay(800);
}

void car()
{
  forward(); //move to duck
  delay(1100);
  leftTurn();//face parallel to grate
  delay(400);
  forward(); //move to end of grate
  delay(1000);
  rightTurn();//face down
  delay(200);
  forward(); //pass grate
  delay(600);
  rightTurn();//face toward base
  delay(300);
  forward(); //move to base
  delay(1000);
  halt();
}


void pump()
{

  forward();//move to line
  delay(2400);
  leftTurn();//face up
  delay(250);
  forward();//pass grate
  delay(1000);
  leftTurn();//face child
  delay(500);
  forward();//move to child
  delay(800);
  back(); //leave pump
  delay(500);
  leftTurn();//down
  delay(600);
  forward();//pass grate
  delay(2000);
  rightTurn();//face toward base
  delay(400);
  forward();//move to base
  delay(1000);

}

void beam()
{
  forward();//move to position
  delay(1000);
  back();//move back to base
  delay(1300);
}

void path()
{
  back();//move to right of begining of line
  delay(900);
  while (1)
  {
    light = analogRead(5);
    if (light < 900) leftCurve();//if over black, move left
    else if (light > 900) rightCurve();//if over white, move right
    delay(50);//delay to give time to move before checking
    Serial.println(light);
  }
}

void forward()//move full speed forward
{
  left.writeMicroseconds(1700);
  right.writeMicroseconds(1300);
}

void halt()//come to complete stop
{
  left.writeMicroseconds(1500);
  right.writeMicroseconds(1500);
}

void back()//move full speed backward
{
  left.writeMicroseconds(1300);
  right.writeMicroseconds(1700);
}

void leftTurn()//full speed 0 degree turn to left
{
  left.writeMicroseconds(1300);
  right.writeMicroseconds(1300);
}

void rightTurn()//full speed 0 degree turn to right
{
  left.writeMicroseconds(1700);
  right.writeMicroseconds(1700);
}

void leftCurve()//slow curve to left
{
  left.writeMicroseconds(1500);
  right.writeMicroseconds(1700);
}

void rightCurve()//slow curve to right
{
  left.writeMicroseconds(1300);
  right.writeMicroseconds(1500);
}



