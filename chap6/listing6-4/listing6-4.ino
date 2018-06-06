int ArrayOne [10]; //produces ten non-duplicate numbers efficiently
int ArrayMirror [10]; //by adding to the non-duplicate array
int ArrayDupes [10]; //progressive iterations
int i;
int j;
int d;
const int trigger = 7;
boolean trigState;
boolean goToReset;

void setup() {
  pinMode (trigger, INPUT_PULLUP);
  randomSeed (analogRead(5));
  Serial.begin (9600);
  Serial.println ("Ground pin 7 to start");
  Serial.println (" ");
}

void loop() {
  trigState = digitalRead (trigger);
  delay (100);
  while (trigState == LOW) { //this section sets up your numbers,
    //creates a copy, and prints number
    Serial.println (" ");
    Serial.println ("Original Numbers ");
    Serial.println (" ");
    for (i = 0; i < 10; i++) {
      ArrayOne [i] = random (1, 11);
      ArrayMirror [j] = ArrayOne [i];
      Serial.print ( ArrayOne [i] );
      Serial.println (" ");
      j++;
    }
reset: //restarts here to clear duplicate numbers
    goToReset = false;

    for ( d = 0; d < 10; d++ ) { //zeros the dupe array
      ArrayDupes [d] = 0;
    }

    for ( i = 0; i < 10; i++ ) {
      for ( j = 0; j < 10; j++ ) { //tests for dupes
        if ( (ArrayOne [ i ] == ArrayMirror [ j] ) && ( i > j) && ( i != 0 )) {

          ArrayDupes [i] = ArrayOne [i]; // gives array of dupes
          // gives zeros for none
        }
      }
    }
    i = 0;
    for ( d = 0; d < 10; d++ ) { //if ArrayDupes numbers are dupes // picks a new random number
      if ( ArrayDupes [ d ] != 0 ) {
        ArrayOne [ d ] = random (1, 11);
        goToReset = true;
      }
    }
    j = 0;
    for ( i = 0; i < 10; i++ ) {
      ArrayMirror [ j ] = ArrayOne [ i ];
      j++;
    }
    if (goToReset == true) {
      goto reset; // since there were dupes, goes back to
      //run dupe test again
    }
    Serial.println (" ");
    Serial.println ("Non-Duplicate Numbers ");
    Serial.println (" ");
    for (i = 0; i < 10; i++ ) { //prints an array of no dupes
      Serial.print (" ");
      Serial.print ( ArrayOne [ i ] );
      Serial.println (" ");
    }
    Serial.println (" ");
    i = 0;
    j = 0;
    d = 0;
    for ( i = 0; i < 10; i++ ) { //zeros the ArrayOne array at end
      //of the game
      ArrayOne [ i ] = 0;
    }
    trigState = HIGH;
  }
}
