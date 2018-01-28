
const int RLED = 11;
const int GLED = 10;
const int BLED = 9;
const int BUTTON = 2;

void setup() {
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(BUTTON, INPUT);
  for (int i = 0; i < 256; i++) {
    writeRGB(i, 0, 0);
    delay(10);
  }
}

void writeRGB(int red, int green, int blue)
{
  analogWrite(RLED, red);
  analogWrite(GLED, green);
  analogWrite(BLED, blue);
}

void loop() {
  int red = 255;
  int green = 0;
  int blue = 0;

  for (green = 0; green < 256;) {
    writeRGB(red, green, blue);
    delay(10);
    red--;
    green++;
  }
  for (blue = 0; blue < 256;) {
    writeRGB(red, green, blue);
    delay(10);
    green--;
    blue++;
  }
  for (red = 0; red < 256;) {
    writeRGB(red, green, blue);
    delay(10);
    blue--;
    red++;
  }
}

