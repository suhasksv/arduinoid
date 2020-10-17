const int button = 2;
const int led = 3;
int s = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  s = digitalRead(button);
  if (s == HIGH) {
    digitalWrite(led, HIGH);
  } 
  else {
    digitalWrite(led, LOW);
  }
}

