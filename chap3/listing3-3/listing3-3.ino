int count;
const int LED = 13;
const int button = 7;
boolean reset; //Boolean declarations take a small amount of memory

void setup() {
  pinMode (LED, OUTPUT);
  pinMode (button, INPUT_PULLUP);
}

void loop() {
  while (count < 7) {
    digitalWrite (LED, HIGH);
    delay(500);
    digitalWrite (LED, LOW);
    delay(500);
    count = count + 1;
  }
  reset = digitalRead (button);
  if (reset == LOW) {
    count = 0;
  }
}
