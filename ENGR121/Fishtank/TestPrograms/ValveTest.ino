int grey=6;
int yellow=7;
void setup()
{
	pinMode(grey,OUTPUT);
	pinMode(yellow, OUTPUT);
	/*delay(1000);
	for (int i=0;i<10;i++)
	{
		digitalWrite(grey, HIGH);
		delay(1000);
		digitalWrite(grey, LOW);
		delay(1000);
		
		
	}*/
}
void loop()
{
	digitalWrite(grey, HIGH);
	delay(1000);
	digitalWrite(grey, LOW);
	delay(1000);
	
	digitalWrite(yellow, HIGH);
	delay(1000);
	digitalWrite(yellow, LOW);
	delay(2000);
}

//grey =7.8g/s
//yellow = 7.5g/s
