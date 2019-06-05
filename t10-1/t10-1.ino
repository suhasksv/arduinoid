#include <LiquidCrystal.h>
const int LDR = A0;
int input_val = 0;

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  analogWrite(6,20);
  lcd.begin(16,2);
}

void loop() {
  input_val = analogRead(LDR);
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("Luminous int. is :");
  lcd.setCursor(0,1);
  lcd.print(input_val);
}

