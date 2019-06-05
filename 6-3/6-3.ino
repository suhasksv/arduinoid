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
  delay(1000);
  analogWrite(green, 200000);
  delay(1000);
  analogWrite(blue, 500000);
  delay(1000);
  analogWrite(red, 100);
  delay(1000);
  analogWrite(green, 200);
  delay(1000);
  analogWrite(blue, 300);
  delay(1000);
}

