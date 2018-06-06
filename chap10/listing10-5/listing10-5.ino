unsigned long currentMillis; //IR Morse code decode program
unsigned long lastMillis;
unsigned int duration;
boolean pulseHigh;
boolean pulseLow;
boolean in = HIGH;
unsigned long startNext;
unsigned long stopLast;
int space;
unsigned long wordEnd;
unsigned int wordLast;
boolean dotDash;
String strOne;
int wordNumber;
int dot;
int dash;
void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to the IR Code Reader Program");
}
void loop() {
  dot = 250;
  dash = 3 * dot;
  in = digitalRead (7); // checks IR detector for a low
  if (in == LOW && pulseLow == 0) { //goes from high to low
    lastMillis = millis();
    pulseLow = 1;
  }
  if (in == HIGH && pulseLow == 1) { //goes from low to high
    currentMillis = millis();
    pulseHigh = 1;
  }
  if (pulseLow == 1 && pulseHigh == 1) {
    duration = currentMillis - lastMillis;
    pulseHigh = 0;
    pulseLow = 0;
  }
  if ((duration > (dot - dot / 3)) && (duration < (dot + dot / 3))) { //looks for dots
    dotDash = 1;
    stopLast = millis();
    space = stopLast - startNext;
    space = space - dot; //subtract dot time
    routine();
    startNext = millis();
    strOne = strOne + "dot";
    duration = 0;
  }
  if (duration > (dash - dash / 3) && duration < (dash + dash / 3)) { //dashes
    dotDash = 1;
    stopLast = millis();
    space = stopLast - startNext;
    space = space - dash; //subtract dash time
    routine();
    startNext = millis();
    strOne = strOne + "dash";
    duration = 0;
  }
  wordEnd = millis(); //identifies the last word
  wordLast = wordEnd - startNext;
  if ((wordLast > (12 * dot - dot / 3) && wordLast < (12 * dot + dot / 3)) &&
      dotDash == 1) {
    routineLetters();
    Serial.println (""); //”ln" makes a new line after last word
    dotDash = 0;
  }
  if (wordNumber > 32) {
    Serial.println ("");//"ln" makes a new line to keep on pc screen
    wordNumber = 0;
  }
} //////////////////////subroutines////////////////////
void routine() {
  if (space > (3 * dot - dot / 3) && space < (3 * dot + dot / 3)) {
    //letter space
    routineLetters(); //calls next subroutine, gets letter or number
  }
  if (space > (7 * dot - dot / 3) && space < (7 * dot + dot / 3)) { //word
    dotDash = 0;
    routineLetters();
    Serial.print (" "); //adds a space between words
    wordNumber = wordNumber + 1;
  }
}
void routineLetters() {
  if (strOne == "dotdotdot") {
    Serial.print ("S");
    strOne = ("");
  }
  else if (strOne == "dashdashdash") {
    Serial.print ("O");
    strOne = ("");
  }
}
