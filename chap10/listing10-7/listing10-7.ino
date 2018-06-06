int ArrayLarge [6];
int ArraySmall [6];
int i;
int j;
float total;
float large;
float small;
const int trigger = 7;
boolean runState;

void setup() {
  pinMode (trigger, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println ("Momentarily press pin 7 to ground to run");
  Serial.println (" ");
}

void loop() {
  runState = digitalRead (trigger);
  while (runState == LOW) {
    delay (200);
    for (i = 0; i < 6; i++) {
      large = i * 7.75; //large size salad is using the slower //spinning outer loop
      for (j = 0; j < 6; j++) { //small size salad is using the faster //spinning inner loop
        small = j * 5.50;
        total = large + small;
        if (total == 42.00) {
          goto printOut; //calls print subroutine
        }
      }
      j = 0;
      total = 0;
    }
printOut: //print the result to screen subroutine
    Serial.print (i);
    Serial.println (" Large Salads");
    Serial.println (" ");
    Serial.print (j);
    Serial.println (" Small Salads");
    Serial.println (" ");
    runState = HIGH;
  }
}

