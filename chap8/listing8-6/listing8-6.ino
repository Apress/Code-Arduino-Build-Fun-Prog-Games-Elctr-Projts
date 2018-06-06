//code to enter frequency for pulse generation

unsigned int inputNumbers;
unsigned int frequency;
String numbers = ""; // empty string for input numbers
const int LED = 13;

void setup() {
  pinMode (LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("This program is for pulse generation");
  Serial.println();
  Serial.println("Enter a number from 500 hz up to 5000 hz");
  Serial.println();
  Serial.println("(You must put hz after the number, and then press enter or click send.)");
  Serial.println();
}
void loop() {
  while (Serial.available() > 0) { // user keys in data
    inputNumbers = Serial.read();
    if (isDigit(inputNumbers)) {
      numbers += (char)inputNumbers;
      //puts the numbers in sequence as string, converts to numbers
    } // now looks for the upper or lower case ASCII code for h:
    if ((inputNumbers == 104) || (inputNumbers == 72)) {
      Serial.print("You entered a pulse frequency of: ");
      Serial.print(numbers.toInt());
      Serial.println(" hz");
      Serial.println("re-enter if incorrect, to end enter x");
      Serial.println();
      frequency = (numbers.toInt());
      tone (LED, frequency);
      //clears variables
      inputNumbers = 0;
      numbers = "";
    }
    if ((inputNumbers == 120) || (inputNumbers == 88)) {
      // upper or lower case x, shuts off tone function
      inputNumbers = 0; //clears variables
      numbers = "";
      Serial.println("idle, enter frequency for output:");
      Serial.println();
      noTone (LED);
    }
  }
}
