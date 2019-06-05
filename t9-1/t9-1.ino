#include <LiquidCrystal.h>
const int LM_35 = A0;
int input_val = 0;
float temp = 0;

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  analogWrite(6,20);
  lcd.begin(16,2);
}

void loop() {
  input_val = analogRead(LM_35);
  temp = (5.0 * input_val * 100.0) / 1024;
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("The temperature is :");
  lcd.setCursor(0,1);
  lcd.println(temp);
}

