/*
16X2 LCD Tutorial by ROBO INDIA
http://roboindia.com/

https://roboindia.com/tutorials/arduino-16x2-lcd-2
*/

#include <LiquidCrystal.h> //includes LCD library.


LiquidCrystal MyLCD(12, 11, 5, 4, 3, 2); // Definining LCD.
int counterVal = 0;  // Variable for counter.

void setup() {
   MyLCD.begin(16, 2); // Initializing 16X2 LCD.
   MyLCD.home(); // Home location : 0,0 
   MyLCD.print("Robo India"); // Print on LCD.
   MyLCD.setCursor(0, 1);
   MyLCD.print("16x2LCD Tutorial");
   delay(2000);
  
}

