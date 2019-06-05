const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;

const int intesity1 = 1000;
const int intesity2 = 2000;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  analogWrite(RED, intesity1);
  delay(1000);
  analogWrite(GREEN, intesity1);
  delay(1000);
  analogWrite(BLUE, intesity1);
  delay(1000);
  analogWrite(RED, intesity2);
  delay(1000);
  analogWrite(GREEN, intesity2);
  delay(1000);
  analogWrite(BLUE, intesity2);
  delay(1000);
}

