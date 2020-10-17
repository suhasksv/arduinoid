const int LED_ao = 3;

void setup() {
  pinMode(LED_ao, OUTPUT);
}

void loop() {
  for (int brightness = 1; brightness <= 55; brightness++)
{
   analogWrite(LED_ao, brightness);
   delay(10); 
  }
 for (int brightness = 55; brightness > 0; brightness--)
  {
    analogWrite(LED_ao, brightness);
    delay(10); 
   }
}

