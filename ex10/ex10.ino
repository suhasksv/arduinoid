const int LDR = A0;
int input_val = 0;

void setup () {
  Serial.begin(9600);
}

void loop () {
  input_val = analogRead(LDR);
  Serial.print("LRD value is : ");
  Serial.println(input_val);
  delay(1000);
}

