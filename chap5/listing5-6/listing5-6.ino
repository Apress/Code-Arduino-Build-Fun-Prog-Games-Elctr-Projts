/* Using a random number generator to get a number between 1 and 99,
  the player guesses if the next number is less or greater than the first number. It uses the serial monitor,
  and three digital I/O pins which are activated when momentarily touched to a ground point such as the USB shield box. 
*/
int randomNum1;
int randomNum2;
const int button = 7; //starts game round
const int lowButton = 8; //player picks lower
const int highButton = 9; //player picks higher
int start;
int clocked;
int lower;
int higher;
int counter;
void setup () {
  pinMode (button, INPUT_PULLUP);
  pinMode (lowButton, INPUT_PULLUP);
  pinMode (highButton, INPUT_PULLUP);
  randomSeed(analogRead(5));
  Serial.begin (9600);
  Serial.println ("Ground pin 7 to start ");//displays message once
}
void loop () {
  start = digitalRead(button);
  if (start == LOW) { //game begins
    randomNum1 = random (1, 100);
    Serial.println (" ");
    Serial.println ("_____________________");
    Serial.println ("Playing between 1 and 99:");
    delay (1500);
    Serial.print ("The computer generated number is ");
    Serial.println (randomNum1);
    delay(2000);
    Serial.println (" ");
    Serial.println ("Do you think the next will be higher or lower?");
    delay(2000);
    Serial.print (" (momentarily ground Pin 8 for Lower, or 9 for Higher) ");
    Serial.println (" ");
    Serial.println (" ");
    for (clocked = 0; clocked < 2000; clocked = clocked + 1) { //waiting
      lower = digitalRead (lowButton);
      higher = digitalRead (highButton);
      if (lower == LOW || higher == LOW) {
        break;
      }
      delay (10);
    } //unbroken loop circulates 2000 times giving 20 seconds delay
rerun:
    randomNum2 = random (1, 100);
    counter = counter + 1; //starts count at 1 and 1 adds each time
    if (counter % 3 != 0) { //counter mod 3 not=0, cheat code runs
      if (lower == LOW && randomNum2 < randomNum1) {
        Serial.print ("cheated ");
        Serial.print (counter);
        Serial.println (" times");
        goto rerun; //goes back and gets another second number
      }
      if (higher == LOW && randomNum2 > randomNum1) {
        Serial.print ("cheated ");
        Serial.print (counter);
        Serial.println (" times");
        goto rerun; //goes back and gets another second number
      }
    }
    Serial.println (" ");
    Serial.print("The Second number is ");
    Serial.println (randomNum2);
    Serial.println (" ");
    Serial.println ("*****");
    Serial.println (" ");
    if (clocked == 2000) {
      Serial.println ("SORRY TIME OUT");// the player did not pick
    }
    else if (randomNum1 == randomNum2) {
      Serial.println ("It's a Draw___Play Again");//randoms equal
    }
    else if (higher == LOW && randomNum1 < randomNum2) {
      Serial.println("You WIN !!! "); //picked higher and was higher
    }
    else if (lower == LOW && randomNum1 > randomNum2) {
      Serial.println("You WIN !!!"); //picked lower and was lower
    }
    else {
      Serial.println ("You Lose");
    }
    delay(2000);
    Serial.println (" ");
    Serial.println ("Ground pin 7 to play again ");
    counter = 0;
  } //end of game
} //end of main loop
