const int red = 11;
const int green = 10;
const int blue = 9;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  analogWrite(red, 100000);
  analogWrite(green, 200000);
  analogWrite(blue, 50000);
  delay(1000);
  analogWrite(red, 100);
  analogWrite(green, 200);
  analogWrite(blue, 500);
  delay(1000);
}

