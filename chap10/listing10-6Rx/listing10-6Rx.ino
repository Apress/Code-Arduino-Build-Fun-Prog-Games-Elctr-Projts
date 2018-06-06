////////Code for the receiver, Arduino board two
const int in = 7;
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
int pulseTone;
int pulsePeriod;
unsigned long currentTime;
unsigned long oldTime;
int i;
void setup() {
  pinMode (in, INPUT_PULLUP);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  Serial.begin (9600); //can use serial monitor to see pulse width
}
void loop() {
  pulseTone = digitalRead (in);
  if (pulseTone == LOW) {
    currentTime = millis();
    pulsePeriod = currentTime - oldTime; //picks up the second burst
    oldTime = currentTime;
    if (pulsePeriod > 6 && pulsePeriod < 14) {
      Serial.println (pulsePeriod);
      for (i; i < 100; i++) {
        digitalWrite (led1, HIGH);
        delay (30); //turns on led for 3 seconds
      }
      digitalWrite (led1, LOW);
      pulsePeriod = 0;
    }
    if (pulsePeriod > 16 && pulsePeriod < 24) {
      Serial.print (pulsePeriod);
      for (i; i < 100; i++) {
        digitalWrite (led2, HIGH);
        delay (30); //turns on led for 3 seconds
      }
      digitalWrite (led2, LOW);
      pulsePeriod = 0;
    }
    if (pulsePeriod > 26 && pulsePeriod < 34) {
      for (i; i < 100; i++) {
        digitalWrite (led3, HIGH);
        delay (30); //turns on led for 3 seconds
      }
      digitalWrite (led3, LOW);
      pulsePeriod = 0;
    }
  }
  pulsePeriod = 0;
  i = 0;
}
