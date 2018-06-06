//blink program using the Arduino internal timer
//two functions and stops long flash on pin 13 at five flashes
const int led = 13; //internal LED
const int ledShort = 12; //pin 12 used for external LED and series resistor
unsigned long oldTime;
unsigned long oldTimeShort;
unsigned long newTime;
unsigned long newTimeShort;
unsigned int timeDelay;
unsigned int timeDelayShort;
boolean ledOn;
boolean ledOnShort;
volatile int longFlash; //ISR resettable variable
const int resetPin = 2;

void setup() {
  pinMode (led, OUTPUT);
  pinMode (ledShort, OUTPUT);
  pinMode (resetPin, INPUT_PULLUP);
  attachInterrupt (0, ISR_RESET, LOW);
}

void loop() {
  newTime = millis();
  newTimeShort = millis();
  timeDelay = (newTime - oldTime);
  timeDelayShort = (newTimeShort - oldTimeShort);

  if ((timeDelay > 1000) && (ledOn == 0) && (longFlash < 5)) {

    digitalWrite (led, HIGH);
    ledOn = 1;
    oldTime = newTime;
    timeDelay = 0;
  }
  if (timeDelayShort > 500 && ledOnShort == 0) { //half second LED on
    digitalWrite (ledShort, HIGH);
    ledOnShort = 1;
    oldTimeShort = newTimeShort;
    timeDelayShort = 0;
  }

  if (timeDelay > 1000 && ledOn == 1) { //one second LED off
    digitalWrite (led, LOW);
    longFlash = longFlash + 1; // keeps track of the long flashes
    ledOn = 0;
    oldTime = newTime;
    timeDelay = 0;
  }
  if (timeDelayShort > 500 && ledOnShort == 1) { //half second LED off
    digitalWrite (ledShort, LOW);
    ledOnShort = 0;
    oldTimeShort = newTimeShort;
    timeDelayShort = 0;
  }
} //End of main loop
//Interrupt Service Routines and Subroutines are outside main loop
void ISR_RESET() {
  longFlash = 0;
}
