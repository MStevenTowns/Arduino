float tempToAR(float a)
{
	return 9.6595552893*a+249.1764222526;
}
float toTemp(float a)
{
	return (a-249.1764222526)/9.6595552893;
}

int heaterPin=4;
int thermPin=1;


int heatLast=0;
void setup()
{
	
	//pinMode(heaterPin, OUTPUT);
	Serial.begin(9600);
	Serial.println(toTemp((float)471));
	/*pinMode(3, OUTPUT);
	digitalWrite(3, HIGH);
  for(int i=0;i<20;i++)
  {
    Serial.println(analogRead(thermPin));
    delay(5000);
  }
  Serial.println("done");*/
  
}
void loop()
{	
	//Serial.println(analogRead(thermPin));
	/*if(analogRead(thermPin)<=510)
		{
			digitalWrite(heaterPin, HIGH);
			heatLast=(float)millis();
		}
		else
		{
			digitalWrite(heaterPin, LOW);
			heatLast=(float)millis();
		}
	}*/	
	delay(100);
}
/*22.75
 * 471
 * 
 * 
 * 47.35
 * 706
 * 
 * 13.7
 * 380
 *
 * 
 * 
 * 
 */
