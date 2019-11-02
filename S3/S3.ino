#include<LiquidCrystal.h>

const int led2 = 6;
const int ldr = A1;
const int button = 7;
const int interrupt = 2;

int v = 0;
int g = 0;

LiquidCrystal lcd(12,11,5,4,3,1);

void setup() {
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  analogWrite(6,20);  
  lcd.begin(16,2);
  attachInterrupt(digitalPinToInterrupt(interrupt), dp, CHANGE);
}

void dp() {
  g = analogRead(button);
  if (g == HIGH)
  {
    digitalWrite(led2, HIGH);
  }
  else
  {
    digitalWrite(led2, LOW);
  }
}

void loop() {
  v = analogRead(ldr);
  Serial.print(v);
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("LDR value is: ");
  lcd.setCursor(0,1);
  lcd.print(v);
  
  if (v <=200) {
    for (int brightness=0; brightness<=555; brightness++)
    {
     analogWrite(led2, brightness);
     delay(1000);
    }
   for(int brightness=555; brightness>256; brightness--)
   {
      analogWrite(led2, brightness);
      delay(1000);  
   }
  }
  
  else if (v <= 700 and v >= 201)
  {
    for (int brightness=0; brightness<=255; brightness++)
    {
     analogWrite(led2, brightness);
     delay(1000);
    }
   for(int brightness=255; brightness>50; brightness--)
   {
      analogWrite(led2, brightness);
      delay(1000);  
   }
  }
   
   else 
   {
    analogWrite(led2, LOW);
   }
}

