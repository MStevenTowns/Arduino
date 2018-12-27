void setup() {
  Serial.begin(9600);
  pinMode(1, OUTPUT);
  Serial.write(12);
  Serial.write(22);

  Serial.write(128);
  Serial.write("CONDUCTIVITY SENSOR");
  Serial.write(152);
  Serial.write("CALIBRATION");
  Serial.write(189);
  Serial.write("analog input=");
}

void loop() {
  for (int i = 1; i <= 14; i++)
  {
    Serial.print(i);
    Serial.write(" ");
    Serial.write(202);
    delay(1000);
  }
  for (int i = 15; i > 1; i--)
  {
    Serial.print(i);
    Serial.write(" ");
    Serial.write(202);
    delay(1000);
  }
}
