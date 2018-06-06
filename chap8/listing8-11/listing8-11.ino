int randomNum1; //LED dice game
int randomNum2;
const int trigger = 8;
const int winLED = A2;
const int buzzer = 11;
int trigState;
int time;
int roll;
int point;
int rollCounter;
int win;
void setup() {
  pinMode (trigger, INPUT_PULLUP); //throw the dice switch
  pinMode (10, OUTPUT); //LED 1
  pinMode (2, OUTPUT); //LED 2
  pinMode (3, OUTPUT); //LED 3
  pinMode (4, OUTPUT); //LED 4
  pinMode (5, OUTPUT); //LED 5
  pinMode (6, OUTPUT); //LED 6
  pinMode (7, OUTPUT); //LED 7
  pinMode (A0, OUTPUT); // die driver 1
  pinMode (A1, OUTPUT); //die driver 2
  pinMode (winLED, OUTPUT);
  pinMode (buzzer, OUTPUT);
  randomSeed(analogRead(5));//gets random number from noise on pin A5
}
void loop() {//looks for button press and displays two random numbers
  trigState = digitalRead (trigger); //pin 8
  while (trigState == 0) { //can run program in display mode
    //numbers 1 through 6 quickly flash for a nice visual effect
    digitalWrite(A0, HIGH);//selects dice one
    digitalWrite(A1, LOW);
    digitalWrite (4, HIGH); //displays a 1
    delay (90);
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH); //selects dice two
    delay (90);
    digitalWrite (4, LOW); //shuts off 1

    digitalWrite(A0, HIGH); //selects dice one
    digitalWrite(A1, LOW);
    digitalWrite (10, HIGH); //displays a 2
    digitalWrite (7, HIGH);
    delay (90);
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH); //selects dice two
    delay (90);
    digitalWrite (10, LOW); //shuts off 2
    digitalWrite (7, LOW);

    digitalWrite(A0, HIGH); //selects dice one
    digitalWrite(A1, LOW);
    digitalWrite (10, HIGH); //displays a 3
    digitalWrite (4, HIGH);
    digitalWrite (7, HIGH);
    delay (90);
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH); //selects dice two
    delay (90);
    digitalWrite (10, LOW); //shuts off 3
    digitalWrite (4, LOW);
    digitalWrite (7, LOW);

    digitalWrite(A0, HIGH); //selects dice one
    digitalWrite(A1, LOW);
    digitalWrite (10, HIGH); //displays a 4
    digitalWrite (3, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite (7, HIGH);
    delay (90);
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH); //selects dice two
    delay (90);
    digitalWrite (10, LOW); //shuts off 4
    digitalWrite (3, LOW);
    digitalWrite (5, LOW);
    digitalWrite (7, LOW);

    digitalWrite(A0, HIGH); //selects dice one
    digitalWrite(A1, LOW);
    digitalWrite (10, HIGH); //displays a 5
    digitalWrite (3, HIGH);
    digitalWrite (4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite (7, HIGH);
    delay (90);
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH); //selects dice two
    delay (90);
    digitalWrite (10, LOW); //shuts off 5
    digitalWrite (3, LOW);
    digitalWrite (4, LOW);
    digitalWrite (5, LOW);
    digitalWrite (7, LOW);

    digitalWrite(A0, HIGH); //selects dice one
    digitalWrite(A1, LOW);
    digitalWrite (10, HIGH); //displays a 6
    digitalWrite (2, HIGH);
    digitalWrite (3, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite (6, HIGH);
    digitalWrite (7, HIGH);
    delay (90);
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH); //selects dice two
    delay (90);
    digitalWrite (10, LOW); //shuts off 6
    digitalWrite (2, LOW);
    digitalWrite (3, LOW);
    digitalWrite (5, LOW);
    digitalWrite (6, LOW);
    digitalWrite (7, LOW);
    //start game
    rollCounter = rollCounter + 1; //rollCounter keeps track of rolls
    randomNum1 = random(1, 7);
    randomNum2 = random(1, 7);
    roll = randomNum1 + randomNum2; //dice total number
    if ( roll == 2 && rollCounter == 1) { //tests for snake eyes //on first pass
      tone(buzzer, 400);
      rollCounter = 0;
    }
    if (roll == 3 && rollCounter == 1) { //tests for a loss craps
      //on first pass
      tone(buzzer, 400);
      rollCounter = 0;
    }
    if (roll == 12 && rollCounter == 1) { //busted with 12
      //on first pass
      tone(buzzer, 400);
      rollCounter = 0;
    }
    if (roll == 7 && rollCounter > 1) { //after first pass,
      //playing for point but get 7
      tone(buzzer, 400);
      rollCounter = 0;
    }
    if (roll == 7 && rollCounter == 1) { //win, 7 on first pass
      digitalWrite(winLED, HIGH);
      tone(buzzer, 4000);
      win = 1;
      rollCounter = 0;
    }
    if (roll == 11 && rollCounter == 1) { //win, 11 on first pass
      digitalWrite(winLED, HIGH);
      tone(buzzer, 4000);
      win = 1;
      rollCounter = 0;
    }
    if (roll == point && rollCounter > 1) { //win, hit point
      digitalWrite(winLED, HIGH);
      tone(buzzer, 4000);
      win = 1;
      rollCounter = 0;
    }
    do {
      time = time + 1; //the do loops around 249 times,
      digitalWrite(A0, HIGH); //selects dice one
      digitalWrite(A1, LOW); //deselects dice two
      switch (randomNum1) { //picks the first dice LEDs to light
        case 1:
          digitalWrite (4, HIGH);
          break;
        case 2:
          digitalWrite (10, HIGH);
          digitalWrite (7, HIGH);
          break;
        case 3:
          digitalWrite (10, HIGH);
          digitalWrite (4, HIGH);
          digitalWrite (7, HIGH);
          break;
        case 4:
          digitalWrite (10, HIGH);
          digitalWrite (3, HIGH);
          digitalWrite (5, HIGH);
          digitalWrite (7, HIGH);
          break;
        case 5:
          digitalWrite (10, HIGH);
          digitalWrite (3, HIGH);
          digitalWrite (4, HIGH);
          digitalWrite (5, HIGH);
          digitalWrite (7, HIGH);
          break;
        case 6:
          digitalWrite (10, HIGH);
          digitalWrite (2, HIGH);
          digitalWrite (3, HIGH);
          digitalWrite (5, HIGH);
          digitalWrite (6, HIGH);
          digitalWrite (7, HIGH);
          break;
      }
      delay (10);
      digitalWrite (10, LOW); //shuts off the first dice LEDs
      digitalWrite (2, LOW);
      digitalWrite (3, LOW);
      digitalWrite (4, LOW);
      digitalWrite (5, LOW);
      digitalWrite (6, LOW);
      digitalWrite (7, LOW);
      digitalWrite(A0, LOW); //deselects dice one
      digitalWrite(A1, HIGH); //selects dice two
      switch (randomNum2) { //picks the second dice LEDs to light
        case 1:
          digitalWrite (4, HIGH);
          break;
        case 2:
          digitalWrite (10, HIGH);
          digitalWrite (7, HIGH);
          break;
        case 3:
          digitalWrite (10, HIGH);
          digitalWrite (4, HIGH);
          digitalWrite (7, HIGH);
          break;
        case 4:
          digitalWrite (10, HIGH);
          digitalWrite (3, HIGH);
          digitalWrite (5, HIGH);
          digitalWrite (7, HIGH);
          break;
        case 5:
          digitalWrite (10, HIGH);
          digitalWrite (3, HIGH);
          digitalWrite (4, HIGH);
          digitalWrite (5, HIGH);
          digitalWrite (7, HIGH);
          break;
        case 6:
          digitalWrite (10, HIGH);
          digitalWrite (2, HIGH);
          digitalWrite (3, HIGH);
          digitalWrite (5, HIGH);
          digitalWrite (6, HIGH);
          digitalWrite (7, HIGH);
          break;
      }
      delay (10);
      digitalWrite (10, LOW); //shuts off the second dice LEDs
      digitalWrite (2, LOW);
      digitalWrite (3, LOW);
      digitalWrite (4, LOW);
      digitalWrite (5, LOW);
      digitalWrite (6, LOW);
      digitalWrite (7, LOW);
      if (win == 1 && time == 10) { //winning buzzer beeps
        noTone(buzzer);
      }
      if (win == 1 && time == 20) {
        tone(buzzer, 4000);
      }
      if (win == 1 && time == 30) {
        noTone(buzzer);
      }
      if (win == 1 && time == 40) {
        tone(buzzer, 4000);
      }
      if (win == 1 && time == 50) {
        noTone(buzzer);
      }
      if (time > 70 && win != 1) { //short buzzer sound for loss
        noTone(buzzer);
      }
    }
    while (time < 250);//creates loop for both dice LEDs to be visible

    if (rollCounter == 1) { //if the pass went without win or loss
      point = roll; //loads the point in memory
    }
    trigState = 1; //resets trigger flag for program activation
    time = 0; //resets loop timer for LED display

    digitalWrite(A1, LOW);
    digitalWrite(winLED, LOW);
    win = 0;
  }
}
