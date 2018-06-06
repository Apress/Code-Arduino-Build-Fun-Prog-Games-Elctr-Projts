const int A = 1; //pin names
const int B = 13;
const int C = 10;
const int D = 8;
const int E = 7;
const int F = 2;
const int G = 11;
const int trans1 = 3;
const int trans2 = 4;
const int trigPin = 6;
const int buzzer = 5;
boolean trigState = HIGH; //variables
int x;
int rollCounter;
int roll;
int point;
boolean win;
int randomNum1;
int randomNum2;
int dicePiece;
int loopDisplay;
int multiplex;
void setup() {
  pinMode (A, OUTPUT); //display segments
  pinMode (B, OUTPUT);
  pinMode (C, OUTPUT);
  pinMode (D, OUTPUT);
  pinMode (E, OUTPUT);
  pinMode (F, OUTPUT);
  pinMode (G, OUTPUT);
  pinMode (buzzer, OUTPUT);
  pinMode (trans1, OUTPUT); //display selection transistors
  pinMode (trans2, OUTPUT);
  pinMode (trigPin, INPUT_PULLUP);
  randomSeed (analogRead(5));
}
void loop() {
  trigState = digitalRead (trigPin);
  if (trigState == LOW) {
    resetSubroutine(); //calls the reset subroutine
    randomNum1 = random (1, 7); //generates the dice numbers
    randomNum2 = random (1, 7);
    rollCounter = rollCounter + 1;
    roll = randomNum1 + randomNum2;
    for (x = 0; x < 3; x++) { //used to go around a circle 3 times
      while (loopDisplay < 6) {//0 through 5 cases for circle segments
        switch (loopDisplay) { //this section circles the dice
          case 0:
            digitalWrite (A, LOW); //turns on segment A
            while (multiplex < 5) {
              digitalWrite (trans1, HIGH); //turns on display 1
              digitalWrite (trans2, LOW); //turns off display 2
              delay (5);
              digitalWrite (trans1, LOW); //turns off display 1
              digitalWrite (trans2, HIGH); //turns on display 2
              delay (5);
              multiplex ++;
            }
            loopDisplay++;
            multiplex = 0;
            break;
          case 1:
            digitalWrite (B, LOW); //turns on segment B
            while (multiplex < 5) {
              digitalWrite (trans1, HIGH); //turns on display 1
              digitalWrite (trans2, LOW); //turns off display 2
              delay (5);
              digitalWrite (trans1, LOW); //turns off display 1
              digitalWrite (trans2, HIGH); //turns on display 2
              delay (5);
              multiplex ++;
            }
            loopDisplay++;
            multiplex = 0;
            break;
          case 2:
            digitalWrite (C, LOW); //turns on segment C
            while (multiplex < 5) {
              digitalWrite (trans1, HIGH); //turns on display 1
              digitalWrite (trans2, LOW); //turns off display 2
              delay (5);
              digitalWrite (trans1, LOW); //turns off display 1
              digitalWrite (trans2, HIGH); //turns on display 2
              delay (5);
              multiplex ++;
            }
            loopDisplay++;
            multiplex = 0;
            break;
          case 3:
            digitalWrite (D, LOW); //turns on segment D
            while (multiplex < 5) {
              digitalWrite (trans1, HIGH); //turns on display 1
              digitalWrite (trans2, LOW); //turns off display 2
              delay (5);
              digitalWrite (trans1, LOW); //turns off display 1
              digitalWrite (trans2, HIGH); //turns on display 2
              delay (5);
              multiplex ++;
            }
            loopDisplay++;
            multiplex = 0;
            break;
          case 4:
            digitalWrite (E, LOW); //turns on segment E
            while (multiplex < 5) {
              digitalWrite (trans1, HIGH); //turns on display 1
              digitalWrite (trans2, LOW); //turns off display 2
              delay (5);
              digitalWrite (trans1, LOW); //turns off display 1
              digitalWrite (trans2, HIGH); //turns on display 2
              delay (5);
              multiplex ++;
            }
            loopDisplay++;
            multiplex = 0;
            break;
          case 5:
            digitalWrite (F, LOW); //turns on segment F
            while (multiplex < 5) {
              digitalWrite (trans1, HIGH); //turns on display 1
              digitalWrite (trans2, LOW); //turns off display 2
              delay (5);
              digitalWrite (trans1, LOW); //turns off display 1
              digitalWrite (trans2, HIGH); //turns on display 2
              delay (5);
              multiplex ++;
            }
            loopDisplay++;
            multiplex = 0;
            break;
        }
        resetSubroutine(); //calls the reset subroutine
      }
      loopDisplay = 0;
    } //ends segment circle
  } //ends trigState
  if (x == 3) { //x is 3 after the segments have circled 3 times
    x = 0; //reusing the x counter
    if (rollCounter == 1) {
      switch (roll) {
        case 7: //win
          tone (buzzer, 4000);
          win = 1;
          rollCounter = 0;
          break;
        case 11: //win
          tone (buzzer, 4000);
          win = 1;
          rollCounter = 0;
          break;
        case 2: //lose
          tone (buzzer, 600);
          rollCounter = 0;
          break;
        case 3: //lose
          tone (buzzer, 600);
          rollCounter = 0;
          break;
        case 12: //lose
          tone (buzzer, 600);
          rollCounter = 0;
          break;
      }//end switch case
      point = roll; //does this if no case met
    }//end if
    if (rollCounter > 1) {
      if (roll == point) { //win, hits point
        tone (buzzer, 4000);
        win = 1;
        rollCounter = 0;
      }
      if (roll == 7) { //lose
        tone (buzzer, 600);
        rollCounter = 0;
      }
    }//end if
    do {
      ////DISPLAY SECTION////
      digitalWrite (trans1, HIGH); //turns on display 1
      dicePiece = randomNum1; //cases for first die
      displaySubroutine();
      delay(10);
      resetSubroutine();
      digitalWrite (trans2, HIGH); //turns on display 2
      dicePiece = randomNum2; //cases for second die
      displaySubroutine();
      delay(10);
      resetSubroutine();
      x++; //increment the counter
      if (win == 1) {
        switch (x) { //pulses winning tone
          case 25: //shuts off
            noTone(buzzer);
            break;
          case 50: //turns on
            tone (buzzer, 4000);
            break;
          case 75://shuts off
            noTone (buzzer);
            break;
          case 100:
            tone (buzzer, 4000); //turns on
            break;
          case 125:
            noTone (buzzer); //shuts off
            break;
          case 150:
            tone (buzzer, 4000); //turns on
            win = 0;
            break;
        }
      }
    } while (x < 200); //end of do section loop
    noTone(buzzer);
    win = 0;
  } //end if for starting numbers display
  x = 0;
} //ends loop
void resetSubroutine() {
  digitalWrite (A, HIGH); //turns off segment A //resets
  digitalWrite (B, HIGH); //turns off segment B
  digitalWrite (C, HIGH); //turns off segment C
  digitalWrite (D, HIGH); //turns off segment D
  digitalWrite (E, HIGH); //turns off segment E
  digitalWrite (F, HIGH); //turns off segment F
  digitalWrite (G, HIGH); //turns off segment G
  digitalWrite (trans1, LOW); //turns off display 1
  digitalWrite (trans2, LOW); //turns off display 2
}
void displaySubroutine() {
  switch (dicePiece) {
    case 1:
      digitalWrite (A, HIGH); //segments low light up
      digitalWrite (B, LOW);
      digitalWrite (C, LOW);
      digitalWrite (D, HIGH);
      digitalWrite (E, HIGH);
      digitalWrite (F, HIGH);
      digitalWrite (G, HIGH);
      break;
    case 2:
      digitalWrite (A, LOW);
      digitalWrite (B, LOW);
      digitalWrite (C, HIGH);
      digitalWrite (D, LOW);
      digitalWrite (E, LOW);
      digitalWrite (F, HIGH);
      digitalWrite (G, LOW);
      break;
    case 3:
      digitalWrite (A, LOW);
      digitalWrite (B, LOW);
      digitalWrite (C, LOW);
      digitalWrite (D, LOW);
      digitalWrite (E, HIGH);
      digitalWrite (F, HIGH);
      digitalWrite (G, LOW);
      break;
    case 4:
      digitalWrite (A, HIGH);
      digitalWrite (B, LOW);
      digitalWrite (C, LOW);
      digitalWrite (D, HIGH);
      digitalWrite (E, HIGH);
      digitalWrite (F, LOW);
      digitalWrite (G, LOW);
      break;
    case 5:
      digitalWrite (A, LOW);
      digitalWrite (B, HIGH);
      digitalWrite (C, LOW);
      digitalWrite (D, LOW);
      digitalWrite (E, HIGH);
      digitalWrite (F, LOW);
      digitalWrite (G, LOW);
      break;
    case 6:
      digitalWrite (A, LOW);
      digitalWrite (B, HIGH);
      digitalWrite (C, LOW);
      digitalWrite (D, LOW);
      digitalWrite (E, LOW);
      digitalWrite (F, LOW);
      digitalWrite (G, LOW);
      break;
  }
}
