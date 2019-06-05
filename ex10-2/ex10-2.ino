const int ldr = A0;
int input_Val = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  input_Val = analogRead(ldr);
  Serial.print("LDR value is: ");
  Serial.println(input_Val);
  delay(1000);
}
