const int BUTTON = 7;
const int LED = 13;
const int buzzer = 8;
int BUTTONState = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  BUTTONState = digitalRead(BUTTON);
  if (BUTTONState == HIGH) {
     digitalWrite(LED, HIGH);
     digitalWrite(buzzer, HIGH);
   }
 else {
    digitalWrite(LED, LOW);
    digitalWrite(buzzer, LOW);
   }
}
