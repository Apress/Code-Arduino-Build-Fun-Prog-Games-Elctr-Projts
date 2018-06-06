const int LED = 9; // A three intensity LED program
const int highPin = 7;
const int medPin = 6;
const int lowPin = 5;
boolean high;
boolean med;
boolean low;
void setup() {
  pinMode (LED, OUTPUT);
  pinMode (highPin, INPUT_PULLUP);
  pinMode (medPin, INPUT_PULLUP);
  pinMode (lowPin, INPUT_PULLUP);
}
void loop() {
  high = digitalRead (highPin);
  med = digitalRead (medPin);
  low = digitalRead (lowPin);
  if (high == LOW) {
    analogWrite(LED, 255);
  }
  if (med == LOW) {
    analogWrite(LED, 125);
  }
  if (low == LOW) {
    analogWrite(LED, 60);
  }
  delay(100);
}
