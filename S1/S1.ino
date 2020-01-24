const int led = 1;
const int LL = A0;
int d = 0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  d = analogRead(LL);
  Serial.print("LDR value is: ");
  Serial.println(d);
  delay(1000);

  if (d <= 300) {
    digitalWrite(led, HIGH);    
  }
  else {
    digitalWrite(led, LOW);
  }
}

