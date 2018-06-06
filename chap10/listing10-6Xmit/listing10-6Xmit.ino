////////Code for the transmitter, Arduino board one
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int out = 7;
int A;
int B;
int C;
int light;
int timer;
void setup() {
  pinMode (led1, INPUT_PULLUP);
  pinMode (led2, INPUT_PULLUP);
  pinMode (led3, INPUT_PULLUP);
  pinMode (out, OUTPUT);
}
void loop() {
  A = digitalRead (led1);
  B = digitalRead (led2);
  C = digitalRead (led3);
  if (A == LOW) {
    light = 1;
  }
  if (B == LOW) {
    light = 2;
  }
  if (C == LOW) {
    light = 3;
  }
  switch (light) {
    case 1:
      while (timer < 10) {
        tone (out, 38000);//outputs a short duration 38,000 tone
        delay (2);
        noTone (out);
        delay (8); //total period 10 ms
        timer = timer + 1;
      }
      break;
    case 2:
      while (timer < 10) {
        tone (out, 38000);
        delay (2);
        noTone (out);
        delay (18); //period 20 ms
        timer = timer + 1;
      }
      break;
    case 3:
      while (timer < 10) {
        tone (out, 38000);
        delay (2);
        noTone (out);
        delay (28); //period 30 ms
        timer = timer + 1;
      }
      break;
  }
  light = 0;
  timer = 0;
}

