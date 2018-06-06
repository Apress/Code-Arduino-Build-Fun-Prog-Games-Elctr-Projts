unsigned long currentMillis; //First establishes the tone frequency
unsigned long lastMillis; //then finds the dot time
unsigned int duration; //and uses Morse transmission spacing to
int pulseHigh; //recover coded letters and words
int pulseLow;
long halfCycles;
long cycles;
int in;
unsigned int pulseTime;
unsigned long startNext;
unsigned long stopLast;
int space;
unsigned long wordEnd;
unsigned int wordLast;
boolean dotDash;
String strOne;
int wordNumber;
void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to the Code Reader Program");
}
void loop() {
sampleStart:
  cycles = 0;
  halfCycles = 0;
  lastMillis = millis();
  do {
    in = analogRead(A0); //output of the circuit to the analog pin
    currentMillis = millis();
    duration = currentMillis - lastMillis; //loops for 10 ms
    if (in > 540) {
      pulseHigh = 1;
    }
    if (in < 500) {
      pulseLow = 1;
    }
    if (pulseHigh == 1 && pulseLow == 1) {
      halfCycles = halfCycles + 1;
      pulseHigh = 0;
      pulseLow = 0;
    }
  }
  while (duration < 10); //counts half cycles for 10 ms
  //multiply by 100 for cycles per second (cps)
  cycles = (100) * (halfCycles / 2);//two half per cycle
  if (cycles > 500 && cycles < 3500) { //looks for an approx 2 khz tone
    pulseTime = pulseTime + 1; //each pulseTime period is 10 ms
    goto sampleStart; // goes back, to sample while tone is present
  }
  pulseTime = pulseTime * 10; //times ten for 10 ms of elapsed time
  if (pulseTime > 150 && pulseTime < 350) { //looks for dots
    stopLast = millis();
    space = stopLast - startNext;
    space = space - 250; //subtract dot time
    routine();
    startNext = millis();
    pulseTime = 0;
    dotDash = 1;
    strOne = strOne + "dot";
  }
  if (pulseTime > 650 && pulseTime < 850) { //looks for dashes
    stopLast = millis();
    space = stopLast - startNext;
    space = space - 750; //subtract dash time
    routine();
    startNext = millis();
    pulseTime = 0;
    dotDash = 1;
    strOne = strOne + "dash";
  }
  wordEnd = millis(); //identifies the last word
  wordLast = wordEnd - startNext;
  if ((wordLast > 1850 && wordLast < 1950) && (dotDash == 1)) {
    routineLetters();
    strOne = ("");
    Serial.println (""); //”ln" makes a new line after last word
    dotDash = 0;
  }
  if (wordNumber > 32) {
    Serial.println ("");//"ln" makes a new line to keep on pc screen
    wordNumber = 0;
  }
}
//////////////////////subroutines////////////////////
void routine() {
  if (space > 700 && space < 800) { //letter space
    routineLetters();
    strOne = ("");
  }
  if (space > 1700 && space < 1800 ) { //word space
    routineLetters();
    strOne = ("");
    Serial.print (" ");
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
