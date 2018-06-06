const byte triggerPin = 7;
int randomNumbers [4]; //declares an array of 4 values, (0 thru 3)
boolean trigState;
boolean trigLatch;
byte counter;

void setup() { // this section sets I/O, runs only once
  pinMode (triggerPin, INPUT_PULLUP);
  Serial.begin (9600);
  Serial.println ("Ground pin 7 to start");
  Serial.println ();
  randomSeed (analogRead(5));
}

void loop() { // Main Program Loop Begins:
  trigState = digitalRead (triggerPin);
  if (trigState == LOW) {
    trigLatch = true;
  }
  while (trigLatch == true) { //trigLatch = false stops this loop
    getNumbers(); //calls the function/subroutine getnumbers
    for (counter = 0; counter < 4; counter++) {
      Serial.println (randomNumbers[counter]); //prints numbers
      delay(1000); //the delay makes it interesting to watch
    }
    trigLatch = false;
    Serial.println ();
  } //end of trig latch
} // end of main loop

// Functions, subroutines, and Interrupts are below,
//outside of the main program:

void getNumbers() {
  for (counter = 0; counter < 4; counter++) {
    randomNumbers[counter] = random(2, 15);
  }
}
