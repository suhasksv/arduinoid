const int lm_35 = A0;
int input_Val = 0;
float temp = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  input_Val = analogRead(lm_35);
  temp =(5.0 * input_Val * 100.0)/1024;
  Serial.print("The temperature is:");
  Serial.println(temp); 
  delay(1000);
}

