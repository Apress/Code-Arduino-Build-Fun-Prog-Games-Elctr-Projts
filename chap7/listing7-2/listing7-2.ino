//second version of 21, picture cards ok for player not dealer yet
const byte triggerPin = 7;
int randomNumbers [4];//this declares an array of 4 values (0 thru 3)
boolean trigState;
boolean trigLatch;
byte counter;
byte yourTotal;
byte dealerTotal;

void setup() {
  pinMode (triggerPin, INPUT_PULLUP);
  Serial.begin (9600);
  randomSeed (analogRead(5));
  Serial.println (" ");
  Serial.println ("Ground pin 7 to play");
  Serial.println (" ");
}
void loop() { //main program loop
  trigState = digitalRead(triggerPin);
  if (trigState == LOW) {
    trigLatch = true;
  }
  while (trigLatch == true) { //to exit this loop make trigLatch = false
    getNumbers();
    Serial.println (" ");
    Serial.println ("****NEW GAME****");
    Serial.println (" ");
    delay (1000);
    Serial.print (" Your First Card is ");
    switch (randomNumbers [0]) {
      case (11):
        Serial.print ("an Ace worth ");
        break;
      case (12):
        Serial.print ("a jack worth ");
        break;
      case (13):
        Serial.print ("a Queen worth ");
        break;
      case (14):
        Serial.print ("a King worth ");
        break;
    }
    if ((randomNumbers [0]) > 11) {
      (randomNumbers [0]) = 10;
    }
    Serial.print (randomNumbers [0]);
    delay (1500);
    Serial.print (", Your Second Card is ");
    switch (randomNumbers [1]) {
      case (11):
        Serial.print ("an Ace worth ");
        break;
      case (12):
        Serial.print ("a Jack worth ");
        break;
      case (13):
        Serial.print ("a Queen worth ");
        break;
      case (14):
        Serial.print ("a King worth ");
        break;
    }
    if ((randomNumbers [1]) > 11) {
      (randomNumbers [1]) = 10;
    }
    Serial.println (randomNumbers [1]);
    delay (2000);
    Serial.println (" ");
    Serial.println (" ");
    Serial.print (" The Dealer's First Card is ");
    Serial.print (randomNumbers [2]);
    delay (1500);
    Serial.print (", The Dealer's Second Card is ");
    Serial.print (randomNumbers [3]);
    delay (2500);
    yourTotal = randomNumbers [0] + randomNumbers [1];
    dealerTotal = randomNumbers [2] + randomNumbers [3];
    Serial.println (" ");
    Serial.println (" ");
    Serial.println (" _____________________________");
    Serial.print (" Your total is ");
    Serial.println (yourTotal);
    Serial.println (" ");
    delay (2000);
    Serial.print (" The Dealer's Total is ");
    Serial.println (dealerTotal);
    Serial.println (" ");

    trigLatch = false;

  } //end of trig latch
} // end of main loop

///// this is the function used to generate the random numbers /////

void getNumbers() {
  for (counter = 0; counter < 4; counter++) {
    randomNumbers[counter] = random(2, 15);
  }
}
