const int led1 = 4;
const int led2 = 3;
const int interrupt = 2;

int count = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  attachInterrupt(digitalPinToInterrupt(interrupt), bp, CHANGE);
  // this is to interrupt arduino
}

void loop() {
}

void bp() {
  int re = 0;
  
  count++;
  
  re = count % 3; // this line calculate remainder

  if (re == 0) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
}

