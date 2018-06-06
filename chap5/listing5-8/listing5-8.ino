int keyboardByte;
int oldKeyboardByte;
int counter;
String number;
float total; //float allows for fractional values
int inputNumbers;
int muffins;
float x;
float flour;
float powder;
float soda;
float salt;
float butter;
float sugar;
float eggs;
float milk;
float vanilla;
float chocolateChips;

void setup() {
  Serial.begin (9600);
}
void loop() { //displays an initial message
  if (counter == 0) {//can put it in the setup section without counter
    Serial.println ("Welcome to the Exact Baking Program");
    delay(2000);
    Serial.println ("(I only have muffins, and mcdonalds in my data base, so far.)");
    delay(2000);
    Serial.println ("What would like to bake?");
    Serial.println (" ");
    counter = 1;
  }

    while (Serial.available() > 0) { //keys were pressed, data in buffer
      keyboardByte = Serial.read(); //reads a keyboard byte from buffer
      oldKeyboardByte = oldKeyboardByte + keyboardByte;
      //stores letter as decimal value, and adds to total
      inputNumbers = oldKeyboardByte;//reads a keyboard byte from buffer
      if (isDigit(inputNumbers)) {
        number += (char)inputNumbers;
        total = (number.toInt());
        oldKeyboardByte = 0;
      }
    }
    switch (oldKeyboardByte) {
      case 949: //mcdonalds
        Serial.println ("OK, mcdonalds it is!");
        Serial.println ("If you're buying, I'll have two hamburgers and large fries");
        Serial.println (" ");
        Serial.println (" ");
        oldKeyboardByte = 0;
        break;
      case 760: //muffins
        Serial.println ("OK, muffins it is!");
        Serial.println ("How many would you like?");
        Serial.println ("(Please enter the number, followed by the letter x) ");
        Serial.println (" ");
        oldKeyboardByte = 0;
        break;
      case 120: //x
        Serial.print("Here's the recipe for ");
        Serial.print(total);
        Serial.println(" muffins:");
        muffin();
        Serial.print (flour); Serial.println (" Cups of flower");
        Serial.print (powder); Serial.println (" Tbsp baking powder");
        Serial.print (soda); Serial.println (" tsp of baking soda");
        Serial.print(salt); Serial.println (" tsp of salt");
        Serial.print(butter); Serial.println (" Cup of butter");
        Serial.print(sugar); Serial.println (" Cup of sugar");
        Serial.print(eggs); Serial.println (" eggs");
        Serial.print(milk); Serial.println (" Cup milk");
        Serial.print(vanilla); Serial.println (" Tbsp vanilla extract");
        Serial.print(chocolateChips); Serial.println (" Cup chocolate chips");
        Serial.println (" ");
        oldKeyboardByte = 0;
        number = "";
        total = 0;
        break;
      case 152: //space and x
        Serial.print("here's the recipe for ");
        Serial.print(total);
        Serial.println(" muffins");
        muffin();
        Serial.print (flour); Serial.println (" Cups of flower");
        Serial.print (powder); Serial.println (" Tbsp baking powder");
        Serial.print (soda); Serial.println (" tsp of baking soda");
        Serial.print(salt); Serial.println (" tsp of salt");
        Serial.print(butter); Serial.println (" Cup of butter");
        Serial.print(sugar); Serial.println (" Cup of sugar");
        Serial.print(eggs); Serial.println (" eggs");
        Serial.print(milk); Serial.println (" Cup milk");
        Serial.print(vanilla); Serial.println (" Tbsp vanilla extract");
        Serial.print(chocolateChips); Serial.println (" Cup chocolate chips");
        Serial.println (" ");
        oldKeyboardByte = 0;
        number = "";
        total = 0;
        break;
    }
  } //end main
  //subroutine follows
  void muffin() {
    x = total / 12;
    flour = 2.5 * x;
    powder = 1 * x;
    soda = 1 * x;
    salt = .25 * x;
    butter = .25 * x;
    sugar = 1 * x;
    eggs = 2 * x;
    milk = 1 * x;
    vanilla = 1 * x;
    chocolateChips = 1 * x;
  }
