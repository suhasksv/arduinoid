const int datapin = 2;
const int clockpin = 3;
const int latchpin = 4;

void setup() {
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(latchpin, OUTPUT);
}

void loop() {
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, LSBFIRST, 255);
  digitalWrite(latchpin, HIGH);
  delay(1000);
  shiftOut(datapin, clockpin, LSBFIRST, 0);
  digitalWrite(latchpin, HIGH);
  delay(1000);
}

