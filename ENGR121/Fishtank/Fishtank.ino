/*
 * Code created for ENGR121 Fishtank Project
 * M. Steven Towns
 * Dominic Lallande
*/ 

/*float toAR(float a)//converts a given percent salinity value to an analogRead() value
{
	return 1277.6 * pow(a, 0.1165);
}
*/

float toAR(float a)//converts a given decimal salinity value to an analogRead() value
{
	return 3870.5105845651 * pow(a, 0.274848);
}

/*
float toSal(float a)//converts a given analogRead() value to the salinity expressed as a percent
{
	return pow(a / 1277.6 , 1.0 / .1165);
}
*/

float toSal(float a)//converts a given analogRead() value to the salinity expressed as a decimal
{
	return pow(a / 3870.5105845651 , 1.0 / .274848);
}



float tempToAR(float a)
{
	return 9.6595552893*a+249.1764222526;
}

float toTemp(float a)
{
	return (a-249.1764222526)/9.6595552893;
}


//variables that will be reused throughout the code
float c1 = 0.0; 				//analogRead() salinity value before correction
float c2 = 0.0; 				//target analogRead() salinity value after correction
float openTime= 0.0;
float openLast = 0.0;			//epoc time for when valve last opened; unsigned bc millis() returns unsigned
float deadTime = 5000.0; 		//ms that must pass before correcting again (5 seconds); unsigned bc millis() returns unsigned
float heatLast=0.0;
//float frGrey= 7.8;		//Flow Rate of valve w/ grey wire (g/s)
//float frYell= 7.5;		//Flow Rate of valve w/ yellow wire (g/s)
float frGrey = 0.468; 		//Flow Rate of valve w/ grey wire (salty) (L/min)
float frYell = 0.450; 		//Flow Rate of valve w/ Yellow wire (DI) (L/min)
float gain = 0.85;			//what part of correction we are attempting
float OF = 0.15; 			//portion of overflow from control tanks
float setPoint = 0.1;	//set point expressed as %
float decSetPoint = setPoint/100.0; //set point expressed as decimal
float arSetPoint = toAR(decSetPoint); //set point converted to an analogRead() value
float stdDev = 0.8276;	//analogRead() value for std deviation calculated in excel
float UCL = arSetPoint + 3.0 * stdDev+5;	// AR() value for UCL
float LCL = arSetPoint - 3.0 * stdDev-5;	// AR() value for LCL
float mass = 74.1;   //mass of tank given in grams

float heatSetPoint=25.0;
float ARHeatSetPoint=tempToAR(heatSetPoint);
float heatStdDev=0.9986833437;
float heatUCL=ARHeatSetPoint+3.0*heatStdDev;
float heatLCL=ARHeatSetPoint-3.0*heatStdDev;

float correction=0;

//varius pins used throughout the code.
int salPin = 0;
int greyPin = 6; //grey wire, Salty Tank
int yellowPin = 7; //relay on yellow line, DI tank
int heaterPin=4;
int thermPin=1;

void setup()//setup of varius components that will not change in execution
{
	delay(1500);// initial delay to allow everything to be ready before operation begins
	//the next lines set up the varius pins used
	pinMode(2, OUTPUT); //pin to energize for salinity testing
	pinMode(3, OUTPUT);     //current through the thermistor to detect changes in temperature
	digitalWrite(3, HIGH);  //set constantly high because there is no need to turn it off with the power the system is provided
	
	pinMode(1, OUTPUT);  //Pin for serial Monitor
	pinMode(greyPin, OUTPUT);//pin to control transistor to salty tank
	pinMode(yellowPin, OUTPUT);//pin to control pin to DI tank
	
	Serial.begin(9600);//the remainder of setup is dealing with the static portions of the LCD
	Serial.write(12); 
	Serial.write(22);
	Serial.write(132);
	Serial.write("LCL");
	Serial.write(139);
	Serial.write("SP");
	Serial.write(144);
	Serial.write("UCL");
	Serial.write(148);
	Serial.write("S: ");
	Serial.print(toSal(LCL)*100, 3);
	Serial.write(157);
	Serial.print(setPoint, 3);
	Serial.write(163);
	Serial.print(toSal(UCL)*100, 3);
	Serial.write(168);
	Serial.write("T:  ");
	Serial.write(172);
	Serial.print(toTemp(heatLCL),1);
	Serial.write("  ");
	Serial.write(178);
	Serial.print(heatSetPoint);
	Serial.write("   ");
	Serial.write(184);
	Serial.print(toTemp(heatUCL));
	Serial.write(188);
	Serial.write("S=");
	Serial.write(196);
	Serial.write("T=");
	Serial.write(203);
	Serial.write("H=");
}

void loop()//Repeating loop to manage fishtank opperation
{
	digitalWrite(2, HIGH);
	c1 = toSal((float)analogRead(salPin)); //current salinity expressed as decimal
	digitalWrite(2, LOW);

	Serial.write(190);
	Serial.print(c1 * 100.0, 3);
	Serial.write(198);
	Serial.print(toTemp(analogRead(thermPin)), 1);

	if ((float)millis() - deadTime - openTime > openLast) //if enough time has passed start testing salinity (float to allow for correct mathmatic opperations with time)
	{
		if (c1 > toSal(UCL)) //if too salty, add di
		{
			c2 = c1 - (c1 - decSetPoint) * gain;	//target=curret-difference*.7
			correction = (mass * (c1 - c2)) / (c1 * (1.0 - OF));		//correction in grams
			openTime = 60.0 * correction / frYell; //time needed to open DI valve
			openLast = ((float)millis());					//set openLast to the current time (float to allow for correct mathmatic opperations with time)

			digitalWrite(yellowPin, HIGH);
			digitalWrite(greyPin, LOW);
			//Serial.write("Deadband on");
		}
		else if (c1 < toSal(LCL)) //if not salty, add salt
		{
			c2 = c1 + (decSetPoint - c1) * gain;	//target=curret+difference*.7
			correction = (mass * (c2 - c1)) / ((1.0 - OF) * (0.01 - c1));	//correction in grams
			openTime = 60.0 * correction / frGrey;	//time needed to open Salty Valve in ms
			openLast = ((float)millis());					//set openLast to the current time (float to allow for correct mathmatic opperations with time)
			digitalWrite(greyPin, HIGH);
			digitalWrite(yellowPin, LOW);
			//Serial.write("Deadband on");
		}
		else //if just right, turn solenoids off (backup, shouldn't ever execute)
		{
			digitalWrite(yellowPin, LOW);
			digitalWrite(greyPin, LOW);
		}
	}
	else if ((float)millis() - openLast > openTime) //if from now to openLast is longer than openTime, turn valves off (float to allow for correct mathmatic opperations with time)
	{
		digitalWrite(yellowPin, LOW);
		digitalWrite(greyPin, LOW);
		//Serial.write("Deadband off");
	}
	if((float)analogRead(thermPin)<=heatLCL) //if the tank has cooled beyond the lower bound, begin heating
	{
		Serial.write(205);
		Serial.write("on ");
		digitalWrite(heaterPin, HIGH);
	}
	else if((float)analogRead(thermPin)>ARHeatSetPoint)//If the tank has reached the setpoint, stop heating (this prevents it from overheating and from bouncing arround on the lower bound)
	{
		Serial.write(205);
		Serial.write("off");
		digitalWrite(heaterPin, LOW);
	}
	//delay(100);//delay to allow for a readable LCD and to prevent transistor/relay overloading.
}

