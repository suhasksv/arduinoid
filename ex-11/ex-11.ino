const int photo_diode = A0;
int inputVal = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  inputVal = analogRead(photo_diode);
  Serial.print("Input value:");
  Serial.println(inputVal);
  delay(1000);
}

