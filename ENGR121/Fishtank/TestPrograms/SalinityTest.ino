int salPin=0;
int relayPin=6; //grey wire
int yellowpin=7; //relay on yellow line
void setup() {
	Serial.begin(9600);
	pinMode(relayPin, OUTPUT);
	/*
	pinMode(1, OUTPUT);
	Serial.write(12);
	Serial.write(22);

	Serial.write(128);
	Serial.write("raw=");
	Serial.write(148);
	Serial.write("vol=");
	*/
	Serial.println("\n\n\n\n\n");
	for (int j=0;j<20;j++)
	{
		int salSense = analogRead(salPin);
		//Serial.write(132);
		Serial.println(salSense);
		/*double volts=salSense*(5.0/1023);
		Serial.write(152)
		Serial.print(i,4);*/
		delay(500);
	}//10 seconds of data before dump
	Serial.println(analogRead(salPin));
	Serial.println("Valve Open");
	digitalWrite(relayPin, HIGH);
	delay(500);
	Serial.println(analogRead(salPin));
	delay(500);
	digitalWrite(relayPin, LOW);
	Serial.println("Valve Closed");
	//dump salty water
}

void loop(){
	int salSense = analogRead(salPin);
	//Serial.write(133);
	Serial.print(salSense);
	Serial.println("   ");
	/*	
	double volts=salSense*(5.0/1023);
	Serial.write(152)
	Serial.print(volts,4);
	*/
    delay(500);
}

/*
 * 0.00% = 3
 * 0.05% = 442
 * 0.10% = 564
 * 0.15% =  600
 */






/*
create command to call the make file

analogRead=1091.6201811902(concentration)^0.2748483517
analogRead()/1091.6201811902=(concentration)^0.2748483517

output>UCL
target=(current-(current-setpoint)*gain)
						error	 *gain
							correction
output<LCL
target=(current+(current-setpoint)*gain)
						error	 *gain
							correction
*/
