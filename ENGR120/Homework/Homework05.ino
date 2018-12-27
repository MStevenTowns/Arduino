int photo = 0;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  photo = analogRead(3);
  Serial.println(photo);
  if (photo < 600)
  {
    digitalWrite(13, HIGH);
    delay(300);
    digitalWrite(13, LOW);
    delay(300);
  }

}

  /*
    val1=digitalRead(7);
    //0 or 1
    //less than 2 volts =0
    //greater than 3 volts=1
    //(2,3) very bad

    val2=analogRead(5);
    //0-1023
    //proportional to 0-5v
    //2.5v would return 511
    //voltage=val2*(5/1023)
  */

