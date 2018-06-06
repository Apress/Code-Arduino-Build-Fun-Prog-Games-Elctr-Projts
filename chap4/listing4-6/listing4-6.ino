/*The intermittent windshield wiper implemented by a microprocessor program.
The pause is 3 seconds for mist and 1 second otherwise
*/
const int startStopPin = 2; //pin names
const int changeSpeedPin = 3;
const int wipeRight = 8;
const int wipeLeft = 9;
int wiperLatch; //variable names
int startStop;
boolean toggleSpeed;
int dwellSpeed;
int count;
int delayChange;
void setup() {
  pinMode (startStopPin, INPUT_PULLUP);
  pinMode (changeSpeedPin, INPUT_PULLUP);
  pinMode (wipeRight, OUTPUT);
  pinMode (wipeLeft, OUTPUT);
}
void loop() {
  startStop = digitalRead (startStopPin);
  delay(200);
  if (startStop == LOW) {
    wiperLatch = 1;
  }
  dwellSpeed = 100;
  while (wiperLatch == 1) { //wipers are on.
    for (count = 0; count < 100; count++) {
      digitalWrite (wipeRight, HIGH);
      delay (10);
      subroutine();
    }
    count = 0;
    digitalWrite (wipeRight, LOW);

    for (count = 0; count < 100; count++) {
      digitalWrite (wipeLeft, HIGH);
      delay(10);
      subroutine();
    }
    count = 0;
    digitalWrite (wipeLeft, LOW);
    for (count = 0; count < dwellSpeed; count++) { //pauses here
      delay(10);
      subroutine();
    }
    count = 0;
    if (delayChange == 1 && dwellSpeed == 100) {
      dwellSpeed = 300; //3 sec dwell for mist
    }
    else if (delayChange == 1 && dwellSpeed == 300) { //controls intermittent delay
      dwellSpeed = 100;//1 sec dwell for light rain, starts by default
    }
    delayChange = 0;
  } //end of while loop
} //end of main loop

void subroutine() {
  startStop = digitalRead (startStopPin);
  if (startStop == LOW) {
    wiperLatch = 0;
    dwellSpeed = 100;
  }
  toggleSpeed = digitalRead (changeSpeedPin);
  if (toggleSpeed == LOW) {
    delayChange = 1;
  }
}
