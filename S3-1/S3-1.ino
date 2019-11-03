#include<LiquidCrystal.h>

const int led2 = 13;
const int ldr = A1;
const int button = 7;
const int interrupt = 2;
const int buzzer = 8;

int v = 0;
int g = 0;

LiquidCrystal MYLCD(12,11,5,4,3,1);

void setup() {
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  analogWrite(6,20);  
  MYLCD.begin(16,2);
  MYLCD.home();
  MYLCD.setCursor(0,0);
  MYLCD.print("LDR value is: ");
  MYLCD.setCursor(0,1);
  MYLCD.print(v);
  attachInterrupt(digitalPinToInterrupt(interrupt), dp, CHANGE);
}

void dp() {
  g = analogRead(button);
  if (g == HIGH)
  {
    digitalWrite(led2, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    digitalWrite(led2, LOW);
    digitalWrite(buzzer, LOW);
  }
}

void loop() {
  v = analogRead(ldr);
  Serial.print("LDR value:");
  Serial.println(v);
  delay(1000);
  
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

