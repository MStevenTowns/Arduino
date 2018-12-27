int relay=6;
void setup()
{
	for(int i=0;i<10;i++)
	{
		digitalWrite(relay, HIGH);
		delay(1000);
		digitalWrite(relay, LOW);
		delay(1000);
	}
}

void loop()
{

}
