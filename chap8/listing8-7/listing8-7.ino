/*This program causes a 7-segment display with a driver IC to count to nine
  The code will reset the count to zero, or pin 7 will reset during the count
  As an exercise, modify the code to only count up to the number 5
*/
int maxCount;
const int trigger = 8;
const int setReset = 7;
int trigState;
int trigLatch;
int timer;
boolean action;
void setup() {
  pinMode (trigger, INPUT_PULLUP);
  pinMode (setReset, INPUT_PULLUP);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);
}
void loop() {
  trigState = digitalRead (trigger); //looks for ground to start
  if (trigState == 0) {
    trigLatch = 1;
    maxCount = 1; //starts the count at one
  }
  while (trigLatch == 1) { //starts counting
    while (maxCount < 10) { //resets and stops after number nine
      do {
        timer = timer + 1;
        action = digitalRead (setReset); //looks for reset pin press
        if (action == LOW) { //if reset pin 8 is pressed
          maxCount = 0; // resets to 0 and continues to count to 9
        } //ends if
        switch (maxCount) { //selects the number to display
          case 1:
            digitalWrite (10, HIGH); //displays 1
            break;
          case 2:
            digitalWrite (11, HIGH);
            break;
          case 3:
            digitalWrite (10, HIGH);
            digitalWrite (11, HIGH);
            break;
          case 4:
            digitalWrite (12, HIGH);
            break;
          case 5:
            digitalWrite (10, HIGH);
            digitalWrite (12, HIGH);
            break;
          case 6:
            digitalWrite (11, HIGH);
            digitalWrite (12, HIGH);
            break;
          case 7:
            digitalWrite (10, HIGH);
            digitalWrite (11, HIGH);
            digitalWrite (12, HIGH);
            break;
          case 8:
            digitalWrite (13, HIGH);
            break;
          case 9:
            digitalWrite (10, HIGH); //displays 9
            digitalWrite (13, HIGH);
            break;
        }
        delay (10); //displays zero and resets display
        digitalWrite (10, LOW);
        digitalWrite (11, LOW);
        digitalWrite (12, LOW);
        digitalWrite (13, LOW);
      } while (timer < 100); //creates a do loop time to be visible
      maxCount = maxCount + 1;
      timer = 0; //resets loop timer
    } //exits this while loop when maxCount = 10
    trigLatch = 0; //resets the trigger latch, ready for new trigger
    maxCount = 0;
    timer = 0;
  }
}
