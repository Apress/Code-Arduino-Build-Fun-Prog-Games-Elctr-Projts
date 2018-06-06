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
    in = analogRead(A0); //connect output of circuit to the analog pin
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
  cycles = (100) * (halfCycles / 2);//divide by two there are two half //cycles, per cycle
  if (cycles > 500 && cycles < 3500) { //looks for an approx 2 khz tone
    pulseTime = pulseTime + 1; //each pulseTime period is 10 ms
    goto sampleStart; //go back to sample while tone present
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
    Serial.print ("dot");
  }
  if (pulseTime > 650 && pulseTime < 850) { //looks for dashes
    stopLast = millis();
    space = stopLast - startNext;
    space = space - 750; //subtract dash time
    routine();
    startNext = millis();
    pulseTime = 0;
    dotDash = 1;
    Serial.print ("dash");
  }
  wordEnd = millis(); //identifies the last word
  wordLast = wordEnd - startNext;
  if ((wordLast > 1850 && wordLast < 1900) && (dotDash == 1)) {
    Serial.print (" word ");
    dotDash = 0;
  }
}
//////////////////////subroutine////////////////////
void routine() {
  if (space > 200 && space < 300) {
    Serial.print ("-");
  }
  if (space > 700 && space < 800) {
    Serial.print (" letter ");
  }
  if (space > 1700 && space < 1800 ) {
    Serial.print (" word ");
  }
}
