const int analog_ip = A0;
const int LED = 3;
int inputVal = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  inputVal = analogRead(analog_ip);
  Serial.println(inputVal);
  analogWrite(LED, inputVal/4);
  delay(500);
}

