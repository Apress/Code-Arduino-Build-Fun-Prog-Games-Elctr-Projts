/* Blink the LED Five Times
  This code blinks the LED connected to pin 13 for five times and then stops.
  It does this through the use of a while statement.
*/
// the declaration identifies variable “count” as interger, and sets //size in memory
int count;
// next, the setup section assigns digital pin 13 as an output.
void setup() {
  pinMode (13, OUTPUT);
}
// the loop function would blink the LED forever if no while statement
void loop() {
  while (count < 5) { // goes for 5 blinks, zero through four
    digitalWrite (13, HIGH); // turn the LED on with a HIGH
    delay(1000); // wait for a 1000 ms (1 second)
    digitalWrite (13, LOW); // turn the LED off by making with LOW
    delay(1000); // wait for a second
    count = count + 1; //adds one to the count of the number of blinks
  } //you can press the Arduino board reset button to start again
}
