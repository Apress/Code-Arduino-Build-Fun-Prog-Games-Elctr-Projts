int myArray [3][3]; //each dimension has 3 possibilities 0, 1, and 2
int i;
void setup() {
  Serial.begin (9600);
}
void loop() {
  myArray[0][0] = 1; //loads array locations
  myArray[0][1] = 2;
  myArray[0][2] = 3;
  myArray[1][0] = 4;
  myArray[1][1] = 5;
  myArray[1][2] = 6;
  myArray[2][0] = 7;
  myArray[2][1] = 8;
  myArray[2][2] = 9;

  while (i < 1) { //runs only one time
    Serial.println (myArray[0][0]); //prints values in the array
    Serial.println (myArray[0][1]);
    Serial.println (myArray[0][2]);
    Serial.println (myArray[1][0]);
    Serial.println (myArray[1][1]);
    Serial.println (myArray[1][2]);
    Serial.println (myArray[2][0]);
    Serial.println (myArray[2][1]);
    Serial.println (myArray[2][2]);
    i++;
  }
}
