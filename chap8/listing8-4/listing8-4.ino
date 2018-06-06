//freq counter reads sine, square, and triangle waves
unsigned long currentMillis; // works from 1 Hz to 20 Khz
unsigned long lastMillis; //samples once a second
unsigned long duration;
int pulseHigh;
int pulseLow;
long halfCycles;
long cycles;
int in = LOW;
void setup() {
  pinMode(3, INPUT);
  Serial.begin(9600);
  Serial.println("The frequency is displayed in Hertz");
}

void loop() {
  lastMillis = millis();
  do {
    in = digitalRead(3);
    currentMillis = millis();
    duration = currentMillis - lastMillis;

    if (in == HIGH) {
      pulseHigh = 1;
    }
    if (in == LOW) {
      pulseLow = 1;
    }
    if (pulseHigh == 1 && pulseLow == 1) {
      halfCycles = halfCycles + 1;
      pulseHigh = 0;
      pulseLow = 0;
    }
  } while (duration < 1000); //looks for cycles per second

  cycles = halfCycles / 2; //divide by two, there are two half cycles
  //in a cycle
  Serial.println(cycles);
  cycles = 0;
  halfCycles = 0;
  delay (1000);
}
