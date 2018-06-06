//blink program using the Arduino internal timer
//two functions stops long flash on pin 13 at five flashes
const int led = 13; //long flashes on pin 13 onboard LED
const int ledShort = 12; //shorter flashing to external LED on pin 12
unsigned long oldTime;
unsigned long oldTimeShort;
unsigned long newTime;
unsigned long newTimeShort;
unsigned int timeDelay;
unsigned int timeDelayShort;
boolean ledOn;
boolean ledOnShort;
int longFlash;

void setup() {
  pinMode (led, OUTPUT);
  pinMode (ledShort, OUTPUT);
}

void loop() {
  newTime = millis();
  newTimeShort = millis();
  timeDelay = (newTime - oldTime);
  timeDelayShort = (newTimeShort - oldTimeShort);

  //one second LED on, for 5 total flashes on pin 13
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
  if (timeDelay > 1000 && ledOn == 1) { //one second LED off pin 13
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
}
