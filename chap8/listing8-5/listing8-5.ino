unsigned long duration;
unsigned long currentMillis;
unsigned long lastMillis;
int pulseHigh;
int pulseLow;
long halfCycles;
long cycles;
int in = LOW;
const int LED = 13;
void setup() {
  pinMode(3, INPUT);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
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

  cycles = halfCycles / 2;

  Serial.println(cycles);
  if ((cycles > 90) && (cycles < 110)) {
    digitalWrite (LED, HIGH);
  }
  cycles = 0;
  halfCycles = 0;
  delay (1000);
  digitalWrite (LED, LOW);
}
