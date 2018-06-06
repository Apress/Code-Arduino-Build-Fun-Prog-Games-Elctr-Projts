byte randomNum1; // Teacher joke program, first attempt
byte randomNum2;
boolean counter;
const int trigger = 7;
byte trigState;
byte trigLatch;
String firstPart;
String secondPart;
byte oldRandomNum1;
byte oldRandomNum2;

void setup() {
  pinMode (trigger, INPUT_PULLUP);
  Serial.begin (9600);
  Serial.println ("Tap a wire from pin 7 to ground for a joke");
  Serial.println ();
  Serial.println ();
  randomSeed (analogRead(5));
}

void loop() {
  trigState = digitalRead (trigger);
  if (trigState == LOW) {
    trigLatch = 1;
    do {
      randomNum1 = random (0, 10);
    }
    while (oldRandomNum1 == randomNum1); // checks and eliminates //redundancy in the first part
    do {
      randomNum2 = random (0, 10);
    }
    while (oldRandomNum2 == randomNum2); // eliminates redundancy //in the second part
  }

  oldRandomNum1 = randomNum1;
  oldRandomNum2 = randomNum2;

  while (trigLatch == 1) {
    subRoutine1();
    subRoutine2();
    Serial.print ("My teachers are so ");
    Serial.print (firstPart);
    Serial.print (" they ");
    Serial.print (secondPart);
    Serial.println (" ");
    Serial.println (" ");
    trigLatch = 0;
    delay (500);
  }
} //end of main loop

void subRoutine1() {
  switch (randomNum1) {
    case 9:
      firstPart = "fat,";
      break;
    case 8:
      firstPart = "big,";
      break;
    case 7:
      firstPart = "tall,";
      break;
    case 6:
      firstPart = "old,";
      break;
    case 5:
      firstPart = "cheap,";
      break;
    case 4:
      firstPart = "smelly,";
      break;
    case 3:
      firstPart = "ugly,";
      break;
    case 2:
      firstPart = "messed Up,";
      break;
    case 1:
      firstPart = "nasty,";
      break;
    case 0:
      firstPart = "skinny,";
      break;
  }
}

void subRoutine2() {
  switch (randomNum2) {
    case 9:
      secondPart = "block the sunshine";
      break;
    case 8:
      secondPart = "scare themselves";
      break;
    case 7:
      secondPart = "melt snow in the winter";
      break;
    case 6:
      secondPart = "make cabbage smell good";
      break;
    case 5:
      secondPart = "make water run up-hill";
      break;
    case 4:
      secondPart = "cause bill collectors to pay them money";
      break;
    case 3:
      secondPart = "make robbers run the other way";
      break;
    case 2:
      secondPart = "cause rocks to break apart";
      break;
    case 1:
      secondPart = "make quick sand slow";
      break;
    case 0:
      secondPart = "cause trees to lose their leaves";
      break;
  }
}
