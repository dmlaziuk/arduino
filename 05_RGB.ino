
const int RLED = 11;
const int GLED = 10;
const int BLED = 9;
const int BUTTON = 2;

boolean lastButton = LOW;
boolean currentButton = LOW;
int ledMode = 0;

void setup() {
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(BUTTON, INPUT);
}


boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);
  if (last != current)
  {
    delay (10);
    current = digitalRead(BUTTON);
  }
  return current;
}

void writeRGB(int red, int green, int blue)
{
  digitalWrite(RLED, red);
  digitalWrite(GLED, green);
  digitalWrite(BLED, blue);
}

void setMode(int mode)
{
  switch (mode) {
    case 1:
      writeRGB(255, 0, 0);   // красный
      break;
    case 2:
      writeRGB(0, 255, 0);   // зеленый
      break;
    case 3:
      writeRGB(0, 0, 255);   // синий
      break;
    case 4:
      writeRGB(127, 0, 127); // пурпурный
      break;
    case 5:
      writeRGB(0, 127, 127); // бирюзовый
      break;
    case 6:
      writeRGB(127, 127, 0); // оранжевый
      break;
    case 7:
      writeRGB(85, 85, 85);  // белый
      break;
    default:
      writeRGB(0, 0, 0);     // выкл (черный)
      break;
  }
}

void loop() {
  boolean currentButton = debounce(lastButton);

  if (lastButton == LOW && currentButton == HIGH)
  {
    ledMode++;
  }
  lastButton = currentButton;
  if (ledMode == 8) ledMode = 0;
  setMode(ledMode);
}

