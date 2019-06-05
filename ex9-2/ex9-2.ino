const int LM_35= A0;
int input_val = 0;
float temp = 0;
float f = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to IoT .....! :) :( (::)");
  delay(9000);
}

void loop() {
  input_val = analogRead(LM_35);
  temp = (5.0 * input_val * 100.0) / 1024;
  f = (temp*9/5)+32;
  Serial.print("Temperature is : ");
  Serial.print(temp);
  Serial.print("'Celcius  -- ");
  Serial.print(f);
  Serial.println("'fahrenheit ");
  delay(2000);
}

