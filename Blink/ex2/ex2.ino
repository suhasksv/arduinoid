const int LED_ao = 11;
void setup() {
  pinMode(LED_ao, OUTPUT);
}
void loop() {
  for (int brightness=1; brightness<=50000; brightness++)
{
   analogWrite(LED_ao, brightness);
   delay(1000);
  }
 for(int brightness=50000; brightness>0; brightness--)
  {
    analogWrite(LED_ao, brightness);
    delay(1000);
  }
}
