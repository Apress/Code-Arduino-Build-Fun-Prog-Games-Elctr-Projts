//This program produces 10 random numbers with no duplication:
int ArrayOne [10];
int ArrayMirror [10];
int i;
int j;
const int trigger = 7;
boolean trigState;

void setup() {
  pinMode (trigger, INPUT_PULLUP);
  randomSeed (analogRead(5));
  Serial.begin (9600);
  Serial.println ("Ground pin 7 for a set of ten different numbers");
}
void loop() {
  trigState = digitalRead (trigger);
  while (trigState == LOW) {
    delay (200);
    Serial.println ("Please wait");
dupeRestart:
    //this section sets up your numbers, creates a copy, and prints
    for ( i = 0; i < 10; i++ ) {
      ArrayOne [ i ] = random (0, 10);
      ArrayMirror [ j ] = ArrayOne [ i ];
      j ++;
    }
    j = 0;
    for ( i = 0; i < 10; i++ ) { //this section looks for dupes
      for ( j = 0; j < 10; j++ ) {
        if ( ( i != j ) && ( ArrayOne [ i ] == ArrayMirror [ j ] ) ) {
          j = 0;
          goto dupeRestart;
          // if a dupe encountered, goes to dupeRestart
        }
      }
    }
    //this section prints the array with no dupes
    Serial.println (" ");
    for ( j = 0; j < 10; j++ ) {
      Serial.print (ArrayMirror [ j ] );
      Serial.println (" ");
    }
    trigState = HIGH;
  }
}
