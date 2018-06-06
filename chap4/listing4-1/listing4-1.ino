const int led = 13; //program for flashing an LED 5 times with reset
const int resetPin = 2;
volatile int reset;
volatile int loopCounter;
int counter1;
int counter2;
int insideLoop;

void setup() {
  pinMode (led, OUTPUT);
  pinMode (resetPin, INPUT_PULLUP);
  attachInterrupt (0, ISR_RESET, LOW);
}
void loop() {
  while (loopCounter < 5) { //loop counter keeps track of total flashes
    insideLoop = 1; //insideloop tells ISR that flashing was in progress

    for (counter1 = 0; counter1 < 100; counter1++) {
      if (reset == 1) { //ISR makes reset 1
        break; //breaks out of the LED on for loop
      }
      digitalWrite (led, HIGH); //lights LED 1 second (10 ms x 100)
      delay (10);
    }
    for (counter2 = 0; counter2 < 100; counter2++) {

      digitalWrite (led, LOW); // this section shuts off LED 1 second
      delay (10);
    }
    loopCounter++; //add 1 to loopcounter
    insideLoop = 0; //tells IRQ flashing not in progress
    reset = 0; //allows LED on loop to run next time
  }
} //end of main loop

void ISR_RESET() {
  if (insideLoop == 1) {
    loopCounter = - 1; //because on first exit after ISR one is added
    reset = 1;
  }
  else {
    loopCounter = 0; //starts the five flashes
  }
}
