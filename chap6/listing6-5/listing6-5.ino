int ArrayOne [72]; //5 card poker with no dupes
int ArrayMirror [72];
int ArrayDupes [72];
int ArrayDeal [52];
int ArrayPlayer [5];
int ArrayDealer [5];
int suit;
int card;
int x;
int i;
int j;
int d;
const int trigger = 7;
boolean trigState;
boolean goToReset;

void setup() {
  pinMode (trigger, INPUT_PULLUP);
  randomSeed (analogRead(5));
  Serial.begin (9600);
  Serial.println ("Ground pin 7 to deal");
  Serial.println (" ");
}

void loop() {
  trigState = digitalRead (trigger);
  delay (100);
  while (trigState == LOW) {
    Serial.println (" ");
    Serial.println ("Please Wait");
    for (i = 0; i < 72; i++) {
      ArrayOne [i] = random (1, 74);
      ArrayMirror [j] = ArrayOne [i];
      j++;
    }
reset: //restarts here to clear duplicate numbers
    goToReset = false;

    for (d = 0; d < 72; d++) { //zeros the dupe array
      ArrayDupes [d] = 0;
    }

    for (i = 0; i < 72; i++) {
      for (j = 0; j < 72; j++) {
        if ( (ArrayOne [i] == ArrayMirror [j]) && (i > j) && (i != 0 )) { //dupes test
          ArrayDupes [i] = ArrayOne [i]; //array of dupes and zeros
          //for none
        }
      }
    }
    i = 0;
    for (d = 0; d < 72; d++) { //if numbers are dupes,
      //picks a new number
      if (ArrayDupes [d] != 0) {
        ArrayOne [d] = random (1, 74);
        goToReset = true;
      }
    }
    j = 0;
    for (i = 0; i < 72; i++) { //loads mirror array
      ArrayMirror [j] = ArrayOne [i];
      j++;
    }
    if (goToReset == true) {
      goto reset; // since dupes, goes back to run the dupe test again
    }
    for (i = 0; i < 52; i++) { 
      //Dupes are gone, grabbing the first 10 good random numbers generated
      if ((ArrayOne [i] < 14) || ((ArrayOne [i] > 20) && (ArrayOne [i] < 34)) || ((ArrayOne [i] > 40) && (ArrayOne [i] < 53)) || (ArrayOne [i] > 60)) {
        ArrayDeal [x] = ArrayOne [i];
        x++;
      }
    }
    Serial.println (" ");
    //now test print of original random numbers-remove to play normally
    for (x = 0; x < 10; x++) {
      Serial.println (ArrayDeal [x]);
    }

    Serial.println (" ");
    for (x = 0; x < 10; x++) {

      if (ArrayDeal [x] > 60) {
        suit = 3;
        card = ArrayDeal [x] - 60; //this normalizes the card value
      }
      else if (ArrayDeal [x] > 40) {
        suit = 2;
        card = ArrayDeal [x] - 40;
      }
      else if (ArrayDeal [x] > 20) {
        suit = 1;
        card = ArrayDeal [x] - 20;
      }
      else if (ArrayDeal [x] < 14) {
        suit = 0;
        card = ArrayDeal [x];
        //card = card
      }
      Serial.println (" ");
      if (x == 0) {
        Serial.println ("Player's Cards:");
        Serial.println (" ");
      }
      if (x == 5) {

        Serial.println (" ");
        Serial.println ("***************");
        Serial.println (" ");
        Serial.println ("Dealer's Cards:");
        delay (2000);
        Serial.println (" ");
      }

      if (card == 1) {
        Serial.print ("The Ace");
      }
      else if (card == 11) {
        Serial.print ("The Jack");
      }
      else if (card == 12) {
        Serial.print ("The Queen");
      }
      else if (card == 13) {
        Serial.print ("The King");
      }
      else {
        Serial.print (card);
      }

      Serial.print (" of ");

      switch (suit) {
        case 3:
          Serial.print ("Hearts");
          break;
        case 2:
          Serial.print ("Spades");
          break;
        case 1:
          Serial.print ("Diamonds");
          break;
        case 0:
          Serial.print ("Clubs");
          break;
      }
    }
    Serial.println (" ");
    x = 0;
    i = 0;
    j = 0;
    d = 0;
    for (i = 0; i < 72; i++) { //zeros ArrayOne array at end of game
      ArrayOne [i] = 0;
    }
    trigState = HIGH;
  }
}
