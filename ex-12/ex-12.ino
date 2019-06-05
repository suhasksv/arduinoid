const int tran = 2;

void setup() {
  pinMode(tran, OUTPUT);
}

void loop() {
  digitalWrite(tran, HIGH);
  delay(1000);
  digitalWrite(tran, LOW);
  delay(1000);
  for (int i = 0; i < 55; i++) {
    digitalWrite(tran, LOW);
    delay(5);
  }
  for (int i = 55; i< 0; i--) {
    digitalWrite(tran, LOW);
    delay(5);
  }
}

