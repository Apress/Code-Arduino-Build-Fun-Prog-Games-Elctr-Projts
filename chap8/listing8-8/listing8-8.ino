int randomNum1;
int randomNum2;
const int trigger = 8; //pin 8 initiates the dice roll
int trigState;
int time;

void setup() {
  pinMode (trigger, INPUT_PULLUP);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (A0, OUTPUT);
  pinMode (A1, OUTPUT);
  randomSeed(analogRead(5));
}

//looks for button press, generates and displays two random numbers
void loop() {
  trigState = digitalRead (trigger);
  if (trigState == 0) {
    randomNum1 = random(1, 7);
    randomNum2 = random(1, 7);

    do { //sequentially displays each of the two numbers
      time = time + 1;
      digitalWrite(A0, HIGH); //selects die one switching transistor
      digitalWrite(A1, LOW);
      switch (randomNum1) { //selects LEDs to light for the random numbers //generated 1 through 6
        case 1:
          digitalWrite (10, HIGH); //binary 1
          break;
        case 2:
          digitalWrite (11, HIGH); //binary 2
          break;
        case 3:
          digitalWrite (10, HIGH); //binary 1
          digitalWrite (11, HIGH); //binary 2, total is 3
          break;
        case 4:
          digitalWrite (12, HIGH); //binary 4
          break;
        case 5:
          digitalWrite (12, HIGH); //binary 4
          digitalWrite (10, HIGH); //binary 1, total is 5
          break;
        case 6:
          digitalWrite (12, HIGH); //binary 4
          digitalWrite (11, HIGH); //binary 2, total is 6
          break;
      }
      delay (10); //keeps first display on 10 ms in loop
      digitalWrite (10, LOW);
      digitalWrite (11, LOW);
      digitalWrite (12, LOW);
      digitalWrite (A0, LOW);
      digitalWrite (A1, HIGH); //selects die two switching transistor

      switch (randomNum2) {
        case 1:
          digitalWrite (10, HIGH);
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
          digitalWrite (12, HIGH);
          digitalWrite (10, HIGH);
          break;
        case 6:
          digitalWrite (12, HIGH);
          digitalWrite (11, HIGH);
          break;
      }
      delay (10); //keeps second display on 10 ms in loop
      digitalWrite (10, LOW);
      digitalWrite (11, LOW);
      digitalWrite (12, LOW);
      digitalWrite (A0, LOW);
      digitalWrite (A1, LOW); //shuts off both displays
    } while (time < 200); //back to do, until end of 4 second loop
    trigState = 1; // resets trigger to high
    time = 0; //resets time
  } //ends if
} //ends loop
