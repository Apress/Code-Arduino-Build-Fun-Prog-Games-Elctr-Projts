/*BlackJack (21) game
  Written 6/15/16 as a learning tool to aid students
  in exploring program development.*/
byte hello;
byte randomNum1;
byte randomNum2;
byte randomNum3;
byte randomNum4;
byte randomNum5;
byte randomNum6;
boolean win;
boolean lose;
byte win_lose;
byte hits;
byte hitCounter;
byte dealer;
byte player;
byte playerSticks;
byte dealerSticks;
boolean trigState;
boolean trigLatch;
int timed;
boolean ace = false;
byte ace10;
byte ace1;
int aceLatch;
const byte trigger1 = 7;
const byte triggerYes = 2; //pin 2 is hardware interrupt 0
const byte triggerNo = 3; //pin 3 is hardware interrupt 1
void setup() {
  pinMode (trigger1, INPUT_PULLUP);
  pinMode (triggerYes, INPUT_PULLUP);
  pinMode (triggerNo, INPUT_PULLUP);
  Serial.begin(9600);
  randomSeed(analogRead(5));
  attachInterrupt (0, yes_ISR, LOW);
  attachInterrupt (1, no_ISR, LOW);
}

void loop() {
  if (hello == 0) { //messages outside of game loop
    delay (500);
    Serial.println (" ");
    Serial.println ("Welcome to The Game of Twenty One");
    Serial.println (" ");
    delay (1000);
    Serial.println ("Sorry, no splitting cards");
    Serial.println (" ");
    delay (1500);
    Serial.println ("Ground Pin 7, to Start the Game");
    Serial.println (" ");
    hello = 1;
  }
  if (hello == 2) {
    delay (500);
    Serial.println (" ");
    Serial.print ( "To Play Again");
    Serial.print (" ");
    delay (1000);
    Serial.println ("Ground Pin 7");
    Serial.println (" ");
    hello = 3;
  }
  if (hello == 5) {
    delay (500);
    Serial.println (" ");
    Serial.print ( "Remember, casinos aren't in business to lose!");
    delay (1000);
    Serial.print (" ");
    Serial.println (" ");
    hello = 6;
  }
  if (hello == 8) {
    delay (500);
    Serial.println (" ");
    Serial.print ( "Nothing is up my sleeve!");
    delay (1000);
    Serial.print (" ");
    Serial.println (" ");
    hello = 9;
  }
  randomNum5 = 0;
  randomNum6 = 0;
  win = 0;
  lose = 0;
  win_lose = 0;
  hitCounter = 0;
  hits = 0;
  dealer = 0;
  player = 0;
  playerSticks = 0;
  dealerSticks = 0;
  trigState = 0;
  trigLatch = 0;
  timed = 0;
  ace = false;
  ace10 = 0;
  ace1 = 0;
  aceLatch = 0;
  trigState = digitalRead(trigger1); //game start
  if (trigState == LOW) {
    trigLatch = 1;
    hello++;
  }
  while (trigLatch == 1) {
    delay (500);
    randomNum1 = random (2, 15);
    Serial.println (" ");
    Serial.println ("********");
    Serial.println (" ");
    Serial.print ("Your First Card is "); //your first card:
    switch (randomNum1) {
      case 11:
        Serial.print ("an Ace, worth ");
        ace = true;
        break;
      case 12:
        Serial.print ("a Jack, worth ");
        break;
      case 13:
        Serial.print ("a Queen, worth ");
        break;
      case 14:
        Serial.print ("a King, worth ");
        break;
    }
    if (randomNum1 > 11) {
      randomNum1 = 10;
    }
    Serial.print (randomNum1);
    delay (1500);
    // your first card, end code:
    //****************
    // your second card, begin code:
    randomNum3 = random (2, 15);
    Serial.print (", Your Second Card is ");
    switch (randomNum3) {
      case 11:
        Serial.print ("an Ace, worth ");
        ace = true;
        break;
      case 12:
        Serial.print ("a Jack, worth ");
        break;
      case 13:
        Serial.print ("a Queen, worth ");
        break;
      case 14:
        Serial.print ("a King, worth ");
        break;
    }
    if (randomNum3 > 11) {
      randomNum3 = 10;
    } //may remove to split
    //not allow a player bust with 2 aces = 22, makes the second ace = 1
    if ((randomNum1 == 11) && (randomNum3 == 11)) {
      randomNum3 = 1;
    }
    Serial.print (randomNum3);
    Serial.println (" ");
    Serial.println (" "); // your second card, end code:
    delay (3000);
    //**********************
    // Dealer's first card, begin code:
    randomNum2 = random (2, 15);
    Serial.print ("The Dealer's First Card is ");
    switch (randomNum2) {
      case 11:
        Serial.print ("an Ace, worth ");
        break;
      case 12:
        Serial.print ("a Jack, worth ");
        break;
      case 13:
        Serial.print ("a Queen, worth ");
        break;
      case 14:
        Serial.print ("a King, worth ");
        break;
    }
    if (randomNum2 > 11) {
      randomNum2 = 10;
    }
    Serial.print (randomNum2);
    delay (2000);
    //Dealer's first card , end code
    //***********************
    // dealer's second card, begin code:
    randomNum4 = random (2, 15);
    Serial.print (", The Dealer's Second Card is ");
    switch (randomNum4) {
      case 11:
        Serial.print ("an Ace, worth ");
        break;
      case 12:
        Serial.print ("a Jack, worth ");
        break;
      case 13:
        Serial.print ("a Queen, worth ");
        break;
      case 14:
        Serial.print ("a King, worth ");
        break;
    }
    if (randomNum4 > 11) {
      randomNum4 = 10;
    }
    if ((randomNum2 == 11) && (randomNum4 == 11)) {
      randomNum4 = 1; //no dealer bust with 2 aces = 22,
    } //makes the second ace = 1
    Serial.print (randomNum4);
    delay (3500);
    Serial.println (" ");
    // dealer's second card, end code:
    //**************************
    dealer = (randomNum2 + randomNum4);
    player = (randomNum1 + randomNum3);
    Serial.println (" ");
    Serial.println (" ");
    Serial.print ("Your Total is ");
    Serial.println (player);
    Serial.println (" ");
    delay (1000);
    Serial.print ("The Dealer's Total is ");
    Serial.println (dealer);
    delay (1000);
    Serial.println (" ");
    if (dealer == 21) { //dealer gets blackjack, you lose
      lose = 1;
      win_lose = 1;
    }
    if (dealer > 16) {
      Serial.println (" ");
      Serial.print ("*** Dealer Sticks at ");
      Serial.print (dealer);
      Serial.println (" ***");
      dealerSticks = 1;
    }

    if (ace == true) { //player selects Ace for 1 or 10 points
      Serial.println (" ");
      Serial.println (" ");
      Serial.print("??? Want the Ace to be 1 or 11 points ???");
      Serial.println (" *** (pin 2 for 11 points, pin 3 for 1 point) ***");
      timed = 0;
      while (timed < 6000) {
        delay (10);
        if (timed == 3000) { //nag
          Serial.println (" ");
          Serial.println ("Ace 1 or 11 points ?");
          Serial.println (" ");
          Serial.println ("If no decision in 30 seconds, it remains 11 points");
          Serial.println (" ");
        }
        if (timed == 4500) {
          Serial.println (" ");
          Serial.println ("Ace 1 or 11 points ? ");
          Serial.println (" ");
        }
        timed++;
      }
      delay (10);
      switch (aceLatch) {
        case 10:
          player = player; //nothing changes Leave as Ace
          break;
        case 1:
          player = player - 10;
          break;
      }
      if ((player > dealer) && (dealerSticks == 1)) {
        win = 1; //dealer sticks and you win
        win_lose = 2;
      }
      //displays values after Ace selection
      Serial.println (" ");
      Serial.print ("OK Your Total is ");
      Serial.print (player);
      Serial.print (", and the Dealer's Total is ");
      Serial.println (dealer);
      delay (1000);
      ace = false;
      aceLatch = 0;
      Serial.println (" ");
    } // end of ace

    ///////////////////////////////////////// code for hits
    while ((player < 21) && (playerSticks == 0) && (win == 0) && (lose == 0)) {
      Serial.println (" ");
      delay (500);
      Serial.println ("Would You Like a Hit ?");
      Serial.println (" ");
      Serial.println ("(pin 2 if yes, pin 3 if no)");
      Serial.println (" ");
      timed = 0;
      while ( timed < 6000 ) { //loops while player decides hit or stay
        delay (10);
        if (timed == 3000) { //nag message
          Serial.println (" ");
          Serial.print ("If no decision in 30 seconds, hit = NO");
          Serial.println (" ");
        }
        if (timed == 4500) {
          Serial.println (" ");
          Serial.println ("***Hit ? ***");
          Serial.println (" ");
        }
        if (timed == 5999) {
          playerSticks = 1;
        }
        timed++;
      }
      delay (100);
      if ((playerSticks == 0) && (hitCounter < 3)) {
        hitCounter++;
        Serial.println (" ");
        Serial.print ("Your next Card is ");//your third card, begin
        switch (randomNum5) {
          case 11:
            Serial.print ("an Ace, worth ");
            ace = 1;
            break;

          case 12:
            Serial.print ("a Jack, worth ");
            break;
          case 13:
            Serial.print ("a Queen, worth ");
            break;
          case 14:
            Serial.print ("a King, worth ");
            break;
        }
        if (randomNum5 > 11) {
          randomNum5 = 10;
        }
        Serial.print (randomNum5);
        Serial.println (" ");
        Serial.println (" ");
        delay (1000);
        player = player + randomNum5;
        Serial.print ("Your Total is ");
        Serial.print (player);
        delay (1500);
        Serial.println (" ");
        Serial.println (" ");
        delay (1000);
        Serial.print ("The Dealer's Total is ");
        Serial.println (dealer);
        delay (1500);
        Serial.println (" ");
        if (ace == 1) { //player selects Ace as 1 or 10 points
          Serial.println (" ");
          Serial.print(" ?? ? Want the Ace to be 1 or 11 points ?? ? ");
          Serial.println (" *** (pin 2) is 11 points, (pin 3) is one point ***");
          timed = 0;
          while (timed < 6000) {
            delay (10);
            if (timed == 3000) { //nag
              Serial.println (" ");
              Serial.println ("Ace 11 or 1 point ? ");
              Serial.println (" ");
              Serial.println ("If no decision it remains worth 11 points");
              Serial.println (" ");
            }
            if (timed == 4500) {
              Serial.println (" ");
              Serial.println ("Ace 11 or 1 point ? ");
              Serial.println (" ");
            }
            if (timed == 5999) {
              aceLatch = 10;
            }
            timed++;
          }
          switch (aceLatch) {
            case 10:
              player = player; //nothing changes Leave as Ace
              break;
            case 1:
              player = player - 10;
              break;
          }
        } //end of ace
      } // end of player sticks
      if (aceLatch == 1) {
        Serial.println (" ");
        Serial.println (" ");
        Serial.print ("OK Your Total is ");
        Serial.println (player);
      }
      delay (1500);
      ace = 0;
      aceLatch = 0;
      if ((hitCounter == 3) && (player < 22)) { //5 cards
        win = 1;
        hits = 1;
      } //end of 5 card win
    } // end of player under 21
    if (player > 21) { /////player over 21
      win_lose = 4;
      lose = 1;
    }
    while ((dealerSticks == 0) && (dealer < player) && (dealer < 21) && (win == 0) && (lose == 0)) {
      //Dealer's next card
      randomNum6 = random (2, 15);
      Serial.println (" ");
      Serial.print ("The Dealer's Next Card is ");//dealer's next card
      switch (randomNum6) {
        case 11 :
          Serial.print ("an Ace worth ");
          ace = 1;
          break;
        case 12:
          Serial.print ("a Jack worth ");
          break;
        case 13:
          Serial.print ("a Queen worth ");
          break;
        case 14:
          Serial.print ("a King worth ");
          break;
      }
      delay (10);
      if (randomNum6 > 11) {
        randomNum6 = 10;
      }
      dealer = dealer + randomNum6;
      if ((dealer > 21) && (ace == 1)) {
        randomNum6 = 1;
        dealer = dealer - 10;
        ace = 0;
        aceLatch = 0;
      }
      Serial.print (randomNum6);
      Serial.println (" ");
      delay (2000);
      Serial.print ("Dealer total = ");
      Serial.print (dealer);
      Serial.println (" "); // dealer's next card, end code:
      ace = 0;
      aceLatch = 0;
      delay (1500);
    }
    if ( hits == 1) { //5 card win
      win_lose = 3;
      win = 1;
    }
    if ((player > dealer) && (player < 22) && (hits != 1)) { //player
      //wins
      win_lose = 5;
      win = 1;
    }
    if ((dealer >= player) && (dealer < 22)) { //dealer beats player
      win_lose = 6;
      lose = 1;
    }
    if (dealer > 21) { //dealer busted
      win_lose = 7;
      win = 1;
    } //****************
    switch (win_lose) {
      case 1:
        Serial.println (" ");
        Serial.println (" ");
        Serial.print ("The Dealer's Gets BlackJack, You Lose");
        delay (500);
        Serial.println (" ");
        Serial.println (" ");
        break;
      case 2:
        Serial.println (" ");//dealer sticks, player higher without hit
        Serial.println (" ");
        Serial.print ("Dealer sticks, and Player Wins");
        delay (500);
        Serial.println (" ");
        Serial.println (" ");
        break;
      case 3:
        Serial.println (" "); //5 card win
        Serial.println (" ");
        Serial.print ("Player Wins with Five Cards");
        delay (500);
        Serial.println (" ");
        Serial.println (" ");
        break;
      case 4:
        Serial.println (" "); //player goes over 21
        Serial.println (" ");
        Serial.print ("PLAYER BUSTED");
        delay (500);
        Serial.println (" ");
        Serial.println (" Sorry, You Lose ");
        Serial.println (" ");
        break;
      case 5:
        Serial.println (" "); //player gets a higher score
        Serial.println (" ");
        Serial.print ("! Player beats Dealer !");
        delay (500);
        Serial.println (" ");
        Serial.println (" ");
        break;
      case 6:
        Serial.println (" "); //dealer beats player
        Serial.println (" ");
        Serial.print ("! Dealer beats Player !");
        delay (500);
        Serial.println (" ");
        Serial.println (" ");
        break;
      case 7:
        Serial.println (" "); //dealer goes over 21
        Serial.println (" ");
        Serial.print ("! D E A L E R B U S T E D !");
        delay (500);
        Serial.println (" ");
        Serial.println ("!!! You Win!!! ");
        Serial.println (" ");
        delay (500);
        break;
    }
    delay (10);
    trigState = 0;
    trigLatch = 0;
  } //end of trigLatch
} //end of main loop
//******** hardware interrupts *********

//must guard against switch bounce
void yes_ISR() {
  if (ace == true) {
    aceLatch = 10;
    timed = 6000;
  }
  else {
    randomNum5 = random (2, 15);
    timed = 6000;
  } // ace yes, and your next card end code:
}
void no_ISR() {
  if (ace == true) {
    aceLatch = 1;
    timed = 6000;
  }
  else {
    playerSticks = 1;
    timed = 6000;
  }
}

