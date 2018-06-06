const int LED = 13;
int lowLight;
boolean on;
void setup() { //analog pins are inputs by default
  pinMode (LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("the serial monitor is displaying the light value");
}
void loop () {
  lowLight = analogRead (0); //reads voltage at 1024 steps
  if (lowLight > 140) { //ambient light low, turn on LED
    digitalWrite (LED, HIGH);
    on = true;
  }
  if ((lowLight <= 140) && (on == false)) {
    digitalWrite(LED, LOW); // ambient light high, turn off LED
  }
  if ((lowLight <= 120) && (on == true)) { //hysteresis
    digitalWrite(LED, LOW);
  }
  Serial.println (lowLight);
  delay (500);
}
