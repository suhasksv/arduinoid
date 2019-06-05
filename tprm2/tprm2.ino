#include <LiquidCrystal.h>
const int LDR = A0;
int input_val = 0;
const int motor = 7;
const int led = 8;
const int buzzer = 1;

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  analogWrite(6,20);
  lcd.begin(16,2);
  pinMode(motor, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  input_val = analogRead(LDR);
  //delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Luminous int. is :");
  lcd.setCursor(0,1);
  lcd.print(input_val);
  if (input_val <= 400) {
    digitalWrite(motor, HIGH);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, HIGH);
  }
  else {
    digitalWrite(buzzer, LOW);
    digitalWrite(motor, LOW);
    digitalWrite(led, HIGH);
  }
}

