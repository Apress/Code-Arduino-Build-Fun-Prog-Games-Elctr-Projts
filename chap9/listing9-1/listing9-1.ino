int ArrayOne [72]; //produces ten non-duplicate numbers efficiently
int ArrayMirror [72];//progressively adds to the non-dupe array
int ArrayDupes [72]; //used to deal two hands of 5 card poker
int ArrayDeal [52];
byte ArrayPlayerCard [5];
byte ArrayPlayerSuit [5];
byte ArrayDealerCard [10];
byte ArrayDealerSuit [10];
byte suit;
byte card;
byte x;
byte i;
byte j;
byte d;
byte match;
byte cardMatched;
const byte trigger = 7;
boolean trigState;
boolean goToReset;
boolean pair;
boolean twoPair;
boolean threeOfKind;
boolean fourOfKind;
boolean fullHouse;
byte matchedCard;
byte matchedCardTwo;
byte hearts;
byte spades;
byte diamonds;
byte clubs;
byte largestPlayerCard;
byte largestDealerCard;
byte smallestPlayerCard;
byte smallestDealerCard;
byte straight;
byte distance;
boolean suitFlush;
byte royalFlush;
byte playerSuit;
byte dealerSuit;
boolean playerAce;
boolean dealerAce;

void setup() {
  pinMode (trigger, INPUT_PULLUP);
  randomSeed (analogRead(5));
  Serial.begin (9600);
  Serial.println ("Ground pin 7 to start");
  Serial.println (" ");
}
void loop() {
  trigState = digitalRead (trigger);
  delay (100);
  while (trigState == LOW) { //this section sets up numbers, makes copy
    Serial.println (" ");
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
        if ( (ArrayOne [i] == ArrayMirror [j]) && (i > j) && (i != 0 )) {
          //tests for dupes
          ArrayDupes [i] = ArrayOne [i]; // gives an array of dupes,
        } // and zeros for no dupes
      }
    }
    i = 0;
    for (d = 0; d < 72; d++) { //if ArrayDupes number is dupe, pick new
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
      goto reset;// since there were dupes, go back to run test again
    }
    for (i = 0; i < 52; i++) { //Now no dupes, get good random numbers

      if ((ArrayOne [i] < 14) || ((ArrayOne [i] > 20) && (ArrayOne [i] < 34)) ||
          ((ArrayOne [i] > 40) && (ArrayOne [i] < 53)) || (ArrayOne [i] > 60)) {
        ArrayDeal [x] = ArrayOne [i];
        x++;
      }
    }
    //**************testing section***************
    //section below if added gives player royal flush and dealer 1
    //pair for testing
    //ArrayDeal[0] = 1; // this section tests player possibilities
    //ArrayDeal[1] = 13; //remove to run game
    //ArrayDeal[2] = 12; //install to test
    //ArrayDeal[3] = 11;
    //ArrayDeal[4] = 10;

    //ArrayDeal[5] = 23; // this section tests dealer possibilities
    //ArrayDeal[6] = 43; //remove to run game
    //ArrayDeal[7] = 61; //install to test
    //ArrayDeal[8] = 5;
    //ArrayDeal[9] = 2;
    //*********end of testing section************
    Serial.println (" ");
    for (x = 0; x < 10; x++) { //converting array to cards
      if (ArrayDeal [x] > 60) {
        suit = 3;
        card = ArrayDeal [x] - 60;
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
        delay (1000);
        Serial.println (" ");
      }
      if (card == 1) {
        Serial.print ("The Ace");//converting cards larger than 10
      }
      else if (card == 11) {
        Serial.print ("Jack");
      }
      else if (card == 12) {
        Serial.print ("Queen");
      }
      else if (card == 13) {
        Serial.print ("King");
      }
      else {
        Serial.print (card); // for 10 to two, shows cards directly
      }
      Serial.print (" of ");
      switch (suit) { //shows suit
        case 3:
          Serial.print ("Hearts");
          hearts = 1;
          break;
        case 2:
          Serial.print ("Spades");
          spades = 1;
          break;
        case 1:
          Serial.print ("Diamonds");
          diamonds = 1;
          break;
        case 0:
          Serial.print ("Clubs");
          clubs = 1;
          break;
      }
      //loads arrays for outcome
      if (x < 5) {
        if (card == 1) { //check for player ace for straight
          playerAce = true;
        }
        ArrayPlayerCard[x] = card;
        ArrayPlayerSuit[x] = suit;
        playerSuit = clubs + diamonds + spades + hearts;
      }
      if (x == 4) { //zeros suit after player, checks for dealer flush
        clubs = 0;
        diamonds = 0;
        spades = 0;
        hearts = 0;
      }
      if ((x > 4) && ( x < 10)) {
        if (card == 1) {
          dealerAce = true; //check for dealer ace for straight
        }
        ArrayDealerCard[x] = card;
        ArrayDealerSuit[x] = suit;
        dealerSuit = clubs + diamonds + spades + hearts;
      }
    }
    Serial.println (" ");
    smallestPlayerCard = 13;//set up for finding smallest card before //entering loop
    for (x = 0; x < 5; x++) { //player outcome follows:
      for (i = 0; i < 5; i++) {
        if ((ArrayPlayerCard[i] == ArrayPlayerCard[x]) && (i > x) && (i != 0)) { //if a match enter loop
          match = match + 1;
          if (match == 1) {
            matchedCard = ArrayPlayerCard[i]; //one pair
            pair = true;
          }
          if ((match == 2) && (matchedCard != ArrayPlayerCard[i])) {
            twoPair = true;
          }
          if ((match == 3) && (matchedCard == ArrayPlayerCard[i])) {
            threeOfKind = true;
          }
          else if (match == 4) {
            fullHouse = true;
          }
          if ((match == 4) && (matchedCard == ArrayPlayerCard[i]) &&
              (threeOfKind == true)) {
            fourOfKind = true;
          }
        }
        if ((ArrayPlayerCard[x] > ArrayPlayerCard[i]) && (ArrayPlayerCard[x] > largestPlayerCard)) { //finds player highest
          largestPlayerCard = ArrayPlayerCard[x];
        }
        if ((ArrayPlayerCard[x] < ArrayPlayerCard[i]) && (ArrayPlayerCard[x] < smallestPlayerCard) && (ArrayPlayerCard[x] != 1)) { //finds smallest
          smallestPlayerCard = ArrayPlayerCard[x];
        }
      }
    } // end of player for loop
    distance = largestPlayerCard - smallestPlayerCard;//checks for
    //straight
    if ((distance == 4) && (match == 0) && (playerAce != true)) {
      straight = true;
    }
    if (((distance == 3) && (largestPlayerCard == 5) && (match == 0) && (playerAce == true)) || //check for high/low ace straight
        ((distance == 3) && (largestPlayerCard == 13) && (match == 0) && (playerAce == true))) {
      straight = true;
    }
    if (playerSuit == 1) {
      suitFlush = true;
    }
    if ((straight == true) && (suitFlush == true) && (largestPlayerCard == 13) && (playerAce == true)) {
      royalFlush = true;
    }
    delay (1000);
    Serial.println (" ");
    Serial.println (" ");
    Serial.print ("Player's hand is "); //condition testing
    if (royalFlush == true) {
      Serial.print ("royal flush ");
    }
    else if (fourOfKind == true) {
      Serial.print ("four of a kind ");
    }
    else if ((suitFlush == true ) && (straight == true)) {
      Serial.print ("a straight flush ");
    }
    else if (fullHouse == true) {
      Serial.print ("full house ");
    }
    else if (suitFlush == true) {
      Serial.print ("a flush ");
    }
    else if (straight == true) {
      Serial.print ("a straight ");
    }
    else if (threeOfKind == true) {
      Serial.print ("three of a kind ");
    }
    else if (twoPair == true) {
      Serial.print ("two pair ");
    }
    else if (pair == true) {
      Serial.print ("one pair ");
    }
    else {
      Serial.print("high card ");
    }
    match = 0;
    pair = false;
    twoPair = false;
    threeOfKind = false;
    fourOfKind = false;
    fullHouse = false;
    matchedCard = 0;
    matchedCardTwo = 0;
    straight = false;
    suitFlush = false;
    royalFlush = false;
    distance = 0;
    //dealer outcome follows:
    smallestDealerCard = 13; //set up for finding smallest card before //entering loop
    for (x = 5; x < 10; x++) {
      for (i = 5; i < 10; i++) {
        if ((ArrayDealerCard[i] == ArrayDealerCard[x]) && (i > x) && (i != 0)) { //if a match, enter loop
          match = match + 1;
          if (match == 1) {
            matchedCard = ArrayDealerCard[i];
            pair = true;
          }
          if ((match == 2) && (matchedCard != ArrayDealerCard[i])) {
            twoPair = true;
          }
          if ((match == 3) && (matchedCard == ArrayDealerCard[i])) {
            threeOfKind = true;
          }
          else if (match == 4) {
            fullHouse = true;
          }
          if ((match == 4) && (matchedCard == ArrayDealerCard[i]) && (threeOfKind == true)) {
            fourOfKind = true;
          }
        }
        if ((ArrayDealerCard[x] > ArrayDealerCard[i]) && (ArrayDealerCard[x] > largestDealerCard)) { //finds the high card
          largestDealerCard = ArrayDealerCard[x];
        }

        if ((ArrayDealerCard[x] < ArrayDealerCard[i]) && (ArrayDealerCard[x] < smallestDealerCard) && (ArrayDealerCard[x] != 1)) { //finds dealer small card
          smallestDealerCard = ArrayDealerCard[x];
        }
      }
    } // end of dealer for loop
    distance = (largestDealerCard - smallestDealerCard); //checks for
    //straight
    if ((distance == 4) && (match == 0) && (dealerAce != true)) {
      straight = true;
    }
    if (((distance == 3) && (largestDealerCard == 5) && (match == 0) && (dealerAce == true)) || //check for high/low ace straight
        ((distance == 3) && (largestDealerCard == 13) && (match == 0) && (dealerAce == true))) {
      straight = true;
    }
    if (dealerSuit == 1) {
      suitFlush = true;
    }
    if ((straight == true) && (suitFlush == true) && (largestDealerCard == 13) && (dealerAce == true)) {
      royalFlush = true;
    }
    delay (1000);
    Serial.println (" ");
    Serial.println (" ");
    Serial.print ("Dealer's hand is "); //condition testing
    if (royalFlush == true) {
      Serial.print ("Royal Flush ");
    }
    else if (fourOfKind == true) {
      Serial.print ("four of a kind ");
    }
    else if ((suitFlush == true ) && (straight == true)) {
      Serial.print ("a straight flush ");
    }
    else if (fullHouse == true) {
      Serial.print ("full house ");
    }
    else if (suitFlush == true) {
      Serial.print ("a flush ");
    }
    else if (straight == true) {
      Serial.print ("a straight ");
    }
    else if (threeOfKind == true) {
      Serial.print ("three of a kind ");
    }
    else if (twoPair == true) {
      Serial.print ("two pair ");
    }
    else if (pair == true) {
      Serial.print ("one pair ");
    }
    else {
      Serial.print("high card ");
    }
    Serial.println (" ");
    x = 0;
    i = 0;
    j = 0;
    d = 0;
    match = 0;
    pair = 0;
    twoPair = 0;
    threeOfKind = 0;
    fourOfKind = 0;
    fullHouse = 0;
    matchedCard = 0;
    matchedCardTwo = 0;
    largestPlayerCard = 0;
    largestDealerCard = 0;
    smallestPlayerCard = 0;
    smallestDealerCard = 0;
    straight = 0;
    playerSuit = 0;
    dealerSuit = 0;
    suitFlush = 0;
    royalFlush = 0;
    distance = 0;
    playerAce = 0;

    dealerAce = 0;
    for (i = 0; i < 52; i++) {
      ArrayOne[i] = 0;
    }
    for (i = 0; i < 10; i++) { //zeros at end of the game
      ArrayPlayerCard[i];
      ArrayPlayerSuit[i];
      ArrayDealerCard[i];
      ArrayDealerSuit[i];
    }
    Serial.println (" ");
    Serial.println ("___________________________________________________");
    Serial.println (" ");
    trigState = HIGH;
  }
}
