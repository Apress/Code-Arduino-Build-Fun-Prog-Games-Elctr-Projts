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
      //************ Numbers ************
      case 48: //number 0
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dash);
        delay (dash + space);
        break;

      case 49: //number 1
        tone (7, 2000, dot);
        delay(dot + dot);
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay (dash + space);
        break;
      case 50: //number 2
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay (dash + space);
        break;
      case 51: //number 3
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay (dash + space);
        break;
      case 52: //number 4
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dash);
        delay(dash + space);
        break;
      case 53: //number 5
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      case 54: //number 6
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      case 55: //number 7
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      case 56: //number 8
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay(dot + space);
        break;
      case 57: //number 9
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      // *********** Letters ***********
      case 97: // letter a - lower case
      case 65: // letter a - upper case
        tone (7, 2000, dot);
        delay(dot + dot);
        tone (7, 2000, dash);
        delay(dash + space);
        break;
      case 98: // letter b
      case 66:
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay(dot + space);
        break;
      case 99: //letter c
      case 67:
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      case 100: //letter d
      case 68:
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      case 101: //letter e
      case 69:
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      case 70:
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      case 103: //letter g
      case 71:
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      case 104: //letter h
      case 72:
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      case 105: //letter i
      case 73:
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      case 106: //letter j
      case 74:
        tone (7, 2000, dot);
        delay(dot + dot);
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dash);
        delay (dash + space);
        break;
      case 107: //letter k
      case 75:
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dash);
        delay (dash + space);
        break;
      case 108: //letter l
      case 76:
        tone (7, 2000, dot);
        delay(dot + dot);
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      case 109: //letter m
      case 77:
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dash);
        delay (dash + space);
        break;
      case 110: //letter n
      case 78:
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      case 111: //letter o
      case 79:
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dash);
        delay (dash + space);
        break;
      case 112: //letter p
      case 80:
        tone (7, 2000, dot);
        delay(dot + dot);
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      case 113: //letter q
      case 81:
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay(dot + dot);
        tone (7, 2000, dash);
        delay(dash + space);
        break;
      case 114: //letter r
      case 82:
        tone (7, 2000, dot);
        delay(dot + dot);
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      case 115: //letter s
      case 83:
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
      case 116: //letter t
      case 84:
        tone (7, 2000, dash);
        delay(dash + space);
        break;
      case 117: //letter u
      case 85:
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dash);
        delay (dash + space);
        break;
      case 118: //letter v
      case 86:
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dash);
        delay(dash + space);
        break;
      case 119: //letter w
      case 87:
        tone (7, 2000, dot);
        delay(dot + dot);
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay(dash + space);
        break;
      case 120: //letter x
      case 88:
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dash);
        delay(dash + space);
        break;
      case 121: //letter y
      case 89:
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay (dot + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dash);
        delay(dash + space);
        break;
      case 122: //letter z
      case 90:
        tone (7, 2000, dash);
        delay(dash + dot);
        tone (7, 2000, dash);
        delay (dash + dot);
        tone (7, 2000, dot);
        delay(dot + dot);
        tone (7, 2000, dot);
        delay (dot + space);
        break;
    }
    Serial.print (keys, ASCII);
  }//now all characters in buffer have been sent and displayed
  if (line == 1) {
    Serial.println(); //prints next sentence on a new line
    line = 0;
  }
}
