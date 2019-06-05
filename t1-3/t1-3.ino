/*
 * Copyrights reserved to KSV Suhas
 * refer to pg 22 question 3
 * 
*/
const int led1 = 4;
const int led2 = 5;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);
  // delay(1000); first I kept this now the task is to flash one after another refer to timing diagram in axis bank dairy
  digitalWrite(led2 , LOW);
  delay(1000);
  digitalWrite(led1, LOW);
  // delay(1000); first I kept this now the task is to flash one after another refer to timing diagram in axis bank dairy
  digitalWrite(led2, HIGH);
  delay(1000);
}

