int keys;
int ASCII;

void setup () {
  Serial.begin (9600);
}

void loop () {
  if (Serial.available () > 0) {
    keys = Serial.read ();
    if (keys != 10) { //ignores enter key
      Serial.println(); //skips a space
      Serial.print ("For the letter ");
      Serial.print (keys, ASCII); //prints the letter
      Serial.print (" the code in binary is ");
      Serial.println (keys, BIN); //prints the binary number
      Serial.print ("the decimal number is ");
      Serial.println (keys, DEC); //prints the decimal number
      //you may wish to add code to print the hex number in this area:
    }
  }
}
