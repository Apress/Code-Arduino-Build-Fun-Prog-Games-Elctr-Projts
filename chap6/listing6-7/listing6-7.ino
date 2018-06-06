int randomNum1;
int randomNum2;
const int trigger = 7;
int trigState;
int trigLatch;
int roll;
int point;
int counter;

void setup() {
  pinMode (trigger, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println ("Ground pin 7 to roll");
  Serial.println (" ");

  randomSeed(analogRead(5));
}
void loop() {
  trigState = digitalRead(trigger);
  if (trigState == LOW) {
    trigLatch = 1;
  }
  while (trigLatch == 1) {
    randomNum1 = random(1, 7); //gets a random 1 through 6 for die one
    Serial.println (randomNum1);
    delay (700);

    randomNum2 = random(1, 7); //gets a random 1 through 6 for die two
    Serial.println (randomNum2);
    delay (700);

    roll = (randomNum1 + randomNum2); //get total
    delay (300);
    Serial.print ("You rolled ");
    Serial.println (roll);
    delay (700);
    trigLatch = 0;
    // FIRST TIME THROUGH COUNTER IS ZERO//
    if (counter == 0) {
      if (roll == 7 || roll == 11) { //7 or 11 win
        Serial.print (roll);
        Serial.println (" is a Winner");
        Serial.println ("");
        delay (800);
        counter = 0;
        roll = 0;
        trigLatch = 0;
      }
      if (roll == 2 || roll == 3 || roll == 12) { //2, 3, or 12 lose
        Serial.println ("You Lose");
        Serial.println ("");
        delay (800);
        counter = 0;
        roll = 0;
        trigLatch = 0;
      }
      if (roll == 4 || roll == 5 || roll == 6 || roll == 8 || roll == 9 || roll == 10) {
        point = roll;
        Serial.println ("Roll again to hit the point");
        delay(400);
        counter++;
        roll = 0;//needed to negate second code section on first roll
        trigLatch = 0;
      }
    }
    //SECOND TIME THROUGH COUNTER > ZERO//
    if (counter > 0) {
      counter++;
      if (roll == point) {
        Serial.println ("You Win, You hit the Point");
        Serial.println ("");
        delay (700);
        counter = 0;
        roll = 0;
        trigLatch = 0;
      }
      if (roll == 7) {
        Serial.println ("You lose");
        Serial.println ("");
        delay (700);
        counter = 0;
        roll = 0;
        trigLatch = 0;
      }
      if (counter == 4) { //helpful comments to the user
        delay (200);
        Serial.print ("**You need ");
        Serial.println (point);
        delay (700);
        trigLatch = 0;
      }
      if (counter == 7) {
        delay (200);
        Serial.print ("**Looking for ");
        Serial.println (point);
        delay (700);
        trigLatch = 0;
      }
      if (counter == 10) {
        delay (200);
        Serial.print ("**This is taking awhile, You need ");
        Serial.println (point);
        delay (700);
        trigLatch = 0;
      }
    }
  }
}
