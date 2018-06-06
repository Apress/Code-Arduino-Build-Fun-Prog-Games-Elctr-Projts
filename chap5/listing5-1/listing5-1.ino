unsigned int i; //program to generate powers of 2, up to 32k
unsigned int x; //long int would be needed if you want to go higher

void setup() { //setup code only runs once
  Serial.begin (9600);
  Serial.println ("generating powers of two"); // prints title
  Serial.println();
}

void loop() {
  for (i = 0; i < 16; i++) { //16 loops, starting with exponent //zero and ending with exponent 15
    x = pow(2, i);

    if (i > 1) { //there is no direct power function in C++
      x = x + 1; //the Arduino command for power has a //glitch when used repeatedly.
    } //after two entries we correct for the problem by //adding a one to the result with x=x+1
    Serial.print (x); //x++ could also be used to increment x
    delay (1000);
    Serial.print(" ");
  }
  Serial.println();
  Serial.println();
}
