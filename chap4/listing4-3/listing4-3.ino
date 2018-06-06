//blink program using the Arduino internal timer to mimic multitasking
const int led = 13;
const int ledShort = 12;
unsigned long oldTime;
unsigned long oldTimeShort;
unsigned long newTime;
unsigned long newTimeShort;
unsigned int timeDelay;
unsigned int timeDelayShort;
boolean ledOn;
boolean ledOnShort;

void setup() {
  pinMode (led, OUTPUT);
  pinMode (ledShort, OUTPUT);
}

void loop() {
  newTime = millis();
  newTimeShort = millis();
  timeDelay = (newTime - oldTime);
  timeDelayShort = (newTimeShort - oldTimeShort);

  if (timeDelay > 1000 && ledOn == 0) { //one second LED on
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
