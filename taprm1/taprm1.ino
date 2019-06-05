const int button = 3;
const int led = 2;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

int buttonstate = 0;
void loop() {
  buttonstate = digitalRead(button);
  if (buttonstate == HIGH) {
    digitalWrite(led, HIGH); 
   }
   else {
    digitalWrite(led, LOW);
  }
}

