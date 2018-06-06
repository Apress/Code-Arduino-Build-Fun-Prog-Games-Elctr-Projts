const int voltageIn = A0; //Makes a volt meter up to 5 volts
int voltLevel;
float actualVoltage;
void setup () {
  Serial.begin(9600);
  pinMode (voltageIn, INPUT);
}
void loop() {
  voltLevel = analogRead(voltageIn);
  actualVoltage = (voltLevel * .004883); //volt steps are .004883
  Serial.println();
  Serial.print("The level is ");
  Serial.println (voltLevel);
  Serial.print("The actual voltage is ");
  Serial.println (actualVoltage);
  Serial.println();
  Serial.println();
  delay(1000);
}
