
void setup() 
{
	Serial.begin(9600);              // allows output to display 
	pinMode(2, OUTPUT);              // define digital pin 2 as an output (output to LED)
	pinMode(13, INPUT);               // define digital pin 3 as an input (input from sensor)
}

void loop()
{
	tone(2,38000);                   // output a LOW HIGH LOW sequence at 38,000 Hz
	int IR_status= digitalRead(13);   // acquire the status of the IR sensor  
	Serial.println(IR_status);       // display the status of the IR sensor
	delay(100);                      // wait 100ms between sensor queries
}

/*
long freq = 38000;
long period;
int IR_status;

void setup()
{
	Serial.begin(9600);
	pinMode(2,OUTPUT);
	pinMode(13,INPUT);
	period=1000000/freq/2;                // compute the half period in microseconds
}

void loop()
{
	for(int i=0;i<200;i++)               // detector needs lots of pulses to work (try 200)
	{
		digitalWrite(2,HIGH);             // manually build a square wave for IR LED
		delayMicroseconds(period);
		digitalWrite(2,LOW);
		delayMicroseconds(period);
		IR_status = digitalRead(13);       // read the status of the sensor 
	}

	Serial.println(IR_status);          // print the status of the sensor
	delay(200);
}

*/
