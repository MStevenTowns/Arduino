void setup() 
{
	Serial.begin(9600);
	pinMode(1, OUTPUT);
	Serial.write(12);
	Serial.write(22);

	Serial.write(132);
	Serial.write("ANALOG INPUT");
	Serial.write(154);
	Serial.write("raw=");
	Serial.write(172);
	Serial.write("volts=");
	Serial.write(194);
	Serial.write("LED=");
}
void loop()
{
	int light=analogRead(0);
	int volts=5000*light/1023;
	Serial.write(178);
	Serial.print(light);
	Serial.Write("   ");
	Serial.write(188);
	Serial.print(volts/1000,2);
	Serial.write("   ");
	if (light>=1023/2)
	{
		digitalWrite(7, HIGH);
		Serial.write(198);
		Serial.write("ON ");
	}
	else
	{
		digitalWrite(7, LOW);
		Serial.write(198);
		Serial.write("OFF");
	}
	delay(1000);
}
