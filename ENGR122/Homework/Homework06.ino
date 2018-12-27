#include <Servo.h>
Servo s;

void setup() {
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8, OUTPUT);
  s.attach(8);
  
	s.writeMicroseconds(1700);
    
	delay(2000);
	s.writeMicroseconds(1500);
}

void loop() {
    
}
//113.7g
