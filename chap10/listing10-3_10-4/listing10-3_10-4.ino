int keys;//generates Morse code from sentences typed in serial monitor
int line; //also displays letters on screen as they are sent
int ASCII;//the delay function starts at the beginning of the tone
int dot = 250;//we use 250 ms as dot time
int dash; //a dash is 3 dot times.
int space; //space between letters three dot times
int wordSpace;//7 dot times between words
boolean fast;
boolean med;
boolean slow;
unsigned int led;

void setup () {
  pinMode (10, INPUT_PULLUP);
  pinMode (9, INPUT_PULLUP);
  pinMode (8, INPUT_PULLUP);
  pinMode (7, OUTPUT);
  Serial.begin (9600);
  Serial.println ("This program will transmit Morse code");
  Serial.println ("up to 64 characters per line (about 10 words)");
  Serial.println ("default speed is 5 WPM");
  Serial.println ("pin 9 gives 10 WPM, and pin 10 is for 15 WPM");
  Serial.println ("tapping pin 8 to ground returns to 5 WPM.");
  Serial.println ("***Type text and enter***");
}
void loop () {
  led = 38000;
  fast = digitalRead (10);
  med = digitalRead (9);
  slow = digitalRead (8);
  if (fast == LOW) {
    dot = 83;
  }
  else if (med == LOW) {
    dot = 125;
  }
  else if (slow == LOW) {
    dot = 250;
  }
  dash = 3 * dot;
  space = dash;
  wordSpace = (7 * dot) - space; //subtracting the letter delay

  while (Serial.available () > 0) {//grabs a byte from the buffer
    line = 1;
    keys = Serial.read ();

    switch (keys) { //ASCII decoding section
    case 32: //space bar case, detects space between words
      delay (wordSpace); //seven dot time periods between words
      break;
      //************ Numbers go here ************

      // *********** Letters s and o ***********

    case 111: //letter o
    case 79:
      tone (7, led);
      delay(dash);
      noTone (7);
      delay (dot);
      tone (7, led);
      delay (dash);
      noTone (7);
      delay (dot);
      tone (7, led);
      delay (dash);
      noTone (7);
      delay (space);
      break;

    case 115: //letter s
    case 83:
      tone (7, led);
      delay (dot);
      noTone (7);
      delay (dot);
      tone (7, led);
      delay (dot);
      noTone (7);
      delay (dot);
      tone (7, led);
      delay (dot);
      noTone (7);
      delay (space);
      break;
    }
    Serial.print (keys, ASCII);
  }//now all characters in buffer have been sent and displayed
  if (line == 1) {
    Serial.println(); //prints next sentence on a new line
    line = 0;
  }
}

