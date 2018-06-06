byte randomNum1; // teacher joke program, second attempt
byte randomNum2; // Expanded, and even more humorous
boolean counter;
const int trigger = 7;
byte trigState;
byte trigLatch;
String firstPart;
String secondPart;
byte oldRandomNum1;
byte oldRandomNum2;
byte veryOldRandomNum1;
byte veryOldRandomNum2;

void setup() {
  pinMode (trigger, INPUT_PULLUP);
  Serial.begin (9600);
  Serial.println ("tap a wire from pin 7 to ground for a joke");
  Serial.println ();
  Serial.println ();
  randomSeed (analogRead(5));
}

void loop() {
  trigState = digitalRead (trigger);
  if (trigState == LOW) {
    trigLatch = 1;
  }
  while (trigLatch == 1) {
    do {
      randomNum1 = random (0, 20);
    }
    while ((oldRandomNum1 == randomNum1) || (veryOldRandomNum1 == randomNum1));
    // put the line of code shown above on one line
    // checks and eliminates redundant phrases in the first

    do {
      if ((randomNum1 < 20) && (randomNum1 > 14)) {
        //picks 19, 18, 17, 16, 15
        randomNum2 = random (15, 20);
      }
      else if ((randomNum1 < 15) && (randomNum1 > 9)) {
        //picks 14, 13, 12, 11, 10
        randomNum2 = random (10, 15);
      }
      else if ((randomNum1 < 10) && (randomNum1 > 4)) {
        //picks 9, 8, 7, 6, 5
        randomNum2 = random (5, 10);
      }
      else { //picks 4, 3, 2, 1, 0
        randomNum2 = random (0, 5);
      }
    }
    while ((oldRandomNum2 == randomNum2) || (veryOldRandomNum2 == randomNum2));
    // put the line of code shown above on one line
    // checks and eliminates redundancy in the second part

    veryOldRandomNum1 = oldRandomNum1; //separates by two
    veryOldRandomNum2 = oldRandomNum2;
    oldRandomNum1 = randomNum1; //separates by three
    oldRandomNum2 = randomNum2;

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
    trigLatch = 0;
  }
} //end of main loop

void subRoutine1() {
  switch (randomNum1) {
    case 19:
      firstPart = "fat,";
      break;
    case 18:
      firstPart = "big,";
      break;
    case 17:
      firstPart = "humongous,";
      break;
    case 16:
      firstPart = "large,";
      break;
    case 15:
      firstPart = "giant,";
      break;
    case 14:
      firstPart = "ugly,";
      break;
    case 13:
      firstPart = "homely,";
      break;
    case 12:
      firstPart = "nasty lookin,";
      break;
    case 11:
      firstPart = "revolting,";
      break;
    case 10:
      firstPart = "beastly,";
      break;
    case 9:
      firstPart = "stupid,";
      break;
    case 8:
      firstPart = "clueless,";
      break;
    case 7:
      firstPart = "brainless,";
      break;
    case 6:
      firstPart = "dimwit,";
      break;
    case 5:
      firstPart = "thick headed,";
      break;
    case 4:
      firstPart = "cheap,";
      break;
    case 3:
      firstPart = "bargain-basement,";
      break;
    case 2:
      firstPart = "tight with a buck,";
      break;
    case 1:
      firstPart = "low-priced,";
      break;
    case 0:
      firstPart = "stingy,";
      break;
  }
}
void subRoutine2() {
  switch (randomNum2) {
    case 19:
      secondPart = "have hooves instead of feet";
      break;
    case 18:
      secondPart = "makes cows look skinny";
      break;
    case 17:
      secondPart = "block the Sunshine";
      break;
    case 16:
      secondPart = "shop for items that contain gluten";
      break;
    case 15:
      secondPart = "put the all-you-can-eat restaurants out-of-business";
      break;
    case 14:
      secondPart = "buy the extended warranty on mirrors";
      break;
    case 13:
      secondPart = "cause robbers to run the other way and turn themselves in";
      break;
    case 12:
      secondPart = "cause mirrors to refuse to show a reflection";
      break;
    case 11:
      secondPart = "have no bugs that will bite them";
      break;
    case 10:
      secondPart = "have the sun hiding behind the clouds when they're at the beach";
      break;
    case 9:
      secondPart = "think little people are inside of the TV";
      break;
    case 8:
      secondPart = "think you need to put a computer in the oven, if it freezes up";
      break;
    case 7:
      secondPart = "buy orange juice concentrate to get smarter";
      break;
    case 6:
      secondPart = "have the dog teaching them new tricks";
      break;
    case 5:
      secondPart = "keep calling the hospital asking for a hemorrhoid transplant";
      break;
    case 4:
      secondPart = "cause bill collectors to send them money";
      break;
    case 3:
      secondPart = "try to spend both sides of a dollar bill";
      break;
    case 2:
      secondPart = "reuse toothpaste";
      break;
    case 1:
      secondPart = "use both sides of toilet paper";
      break;
    case 0:
      secondPart = "save leaves in the fall, and paste them back on in the spring";
      break;
  }
}
