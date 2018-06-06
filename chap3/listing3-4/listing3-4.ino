//program to flash an LED 7 times with interrupt reset
volatile int count; //volatile used for variables inside interrupts
const int LED = 13;
const int button = 2;

void setup() {
  pinMode (LED, OUTPUT);
  pinMode (button, INPUT_PULLUP);
  attachInterrupt (0, reset_ISR, LOW);
}
void loop() {
  while (count < 7) {
    digitalWrite (LED, HIGH);
    delay(500);
    digitalWrite (LED, LOW);
    delay(500);
    count = count + 1;
  }
}
// notice the ISR goes outside of the main loop
void reset_ISR() {
  count = 0;
}
