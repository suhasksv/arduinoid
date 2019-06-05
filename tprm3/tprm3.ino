#include <LiquidCrystal.h>
const int LM_35 = A0;
int input_val = 0;
float temp = 0;
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
  input_val = analogRead(LM_35);
  temp = (5.0 * input_val * 100.0) / 1024;
 // delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Temperature is:");
  lcd.setCursor(0,1);
  lcd.print(temp);
  if (temp <= 35) {
    digitalWrite(led, HIGH);
    digitalWrite(motor, LOW);
    digitalWrite(buzzer, LOW);
  }
  else {
  digitalWrite(led, LOW);
  digitalWrite(motor, HIGH);
  digitalWrite(buzzer, HIGH);
  }
}

