int x=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String test="Hello, my name is Steven. I have said this ";
  test+=x++;
  Serial.print(test+" times.\n");
}
