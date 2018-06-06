//blink program using the Arduino internal timer
const int led = 13;
unsigned long oldTime; //long used to allocate memory to large numbers
unsigned long newTime; // unsigned means no negative values
unsigned int timeDelay;
boolean ledOn;

void setup() {
  pinMode (led, OUTPUT);
}

void loop() {
  newTime = millis();
  timeDelay = (newTime - oldTime);

  if (timeDelay > 1000 && ledOn == 0) { //Note: && is the AND function
    digitalWrite (led, HIGH);
    ledOn = 1;
    oldTime = newTime;
    timeDelay = 0;
  }

  if (timeDelay > 1000 && ledOn == 1) {
    digitalWrite (led, LOW);
    ledOn = 0;
    oldTime = newTime;
    timeDelay = 0;
  }
}
