#include <Servo.h>

Servo servo1;

void setup() {
  servo1.attach(5);
}

void loop () {
  int potent = analogRead(5);
  potent = map(potent, 0, 1023, 0, 100);
  servo1.write(potent);
  delay(2);
}

