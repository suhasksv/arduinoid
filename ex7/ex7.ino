#include <Servo.h>
Servo servo_1;
int inputval = 0;

void setup() {
  servo_1.attach(3);
}

void loop() {
  servo_1.write(45);
  delay(1000);
  servo_1.write(180);
  delay(1000);
  servo_1.write(30);
  delay(100);
  servo_1.write(120); 
}

