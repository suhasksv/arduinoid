const int BUTTON = 3;
const int LED = 9;
int BUTTONState = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  BUTTONState = digitalRead(BUTTON);
  if (BUTTONState == HIGH) {
     digitalWrite(LED, HIGH);
   }
 else {
    digitalWrite(LED, LOW);
   }
}
