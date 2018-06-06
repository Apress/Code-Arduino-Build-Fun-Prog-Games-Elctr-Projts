const int A = 1; //pin names to connect to each segment of the display
const int B = 13;
const int C = 10;
const int D = 8;
const int E = 7;
const int F = 2;
const int G = 11;
const int trigPin = 6;
int trigLatch; //variables
boolean trigState = HIGH;
int maxCount;
int timer;

void setup() {
  pinMode (A, OUTPUT); //display segments
  pinMode (B, OUTPUT);
  pinMode (C, OUTPUT);
  pinMode (D, OUTPUT);
  pinMode (E, OUTPUT);
  pinMode (F, OUTPUT);
  pinMode (G, OUTPUT);
  pinMode (trigPin, INPUT_PULLUP);
}
void loop() {
  digitalWrite (A, LOW); //lows light up, this starts with zero
  digitalWrite (B, LOW);
  digitalWrite (C, LOW);
  digitalWrite (D, LOW);
  digitalWrite (E, LOW);
  digitalWrite (F, LOW);
  digitalWrite (G, HIGH); //high disables the middle segment
  trigState = digitalRead (trigPin); //looks for low on pin 8 to start
  if (trigState == 0) {
    trigLatch = 1;
  }
  while (trigLatch == 1) { //starts counting
    while (maxCount < 10) { //resets and stops after number nine
      do {
        timer = timer + 1;
        switch (maxCount) {
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
          case 7:
            digitalWrite (A, LOW);
            digitalWrite (B, LOW);
            digitalWrite (C, LOW);
            digitalWrite (D, HIGH);
            digitalWrite (E, HIGH);
            digitalWrite (F, HIGH);
            digitalWrite (G, HIGH);
            break;
          case 8:
            digitalWrite (A, LOW);
            digitalWrite (B, LOW);
            digitalWrite (C, LOW);
            digitalWrite (D, LOW);
            digitalWrite (E, LOW);
            digitalWrite (F, LOW);
            digitalWrite (G, LOW);
            break;
          case 9:
            digitalWrite (A, LOW);
            digitalWrite (B, LOW);
            digitalWrite (C, LOW);
            digitalWrite (D, HIGH);
            digitalWrite (E, HIGH);
            digitalWrite (F, LOW);
            digitalWrite (G, LOW);
            break;
        }
        delay (10);
      } while (timer < 100);
      resetSubroutine();
      maxCount = maxCount + 1;
      timer = 0;
    } //exits this while loop when maxCount = 10
    trigLatch = 0;//resets trigger latch, makes ready for next trigger
    maxCount = 0;
    timer = 0;
  } //ends trigState
}//end loop
void resetSubroutine() {
  digitalWrite (A, HIGH); //turns off segment A //resets
  digitalWrite (B, HIGH); //turns off segment B
  digitalWrite (C, HIGH); //turns off segment C
  digitalWrite (D, HIGH); //turns off segment D
  digitalWrite (E, HIGH); //turns off segment E
  digitalWrite (F, HIGH); //turns off segment F
  digitalWrite (G, HIGH); //turns off segment G
}
