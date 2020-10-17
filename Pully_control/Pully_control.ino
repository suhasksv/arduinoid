//for L298N motor driver
const int in1 = 6;
const int in2 = 7;

const int in3 = 8;
const int in4 = 9;

//for L298N motor driver
const int button1 = 11; //motor used for locomotion (forward)
const int button2 = 12; //motor used for locomotion (forward)
const int button3 = 0;  //motor used for locomotion (backward)
const int button4 = 1   //motor used for locomotion (backward)
//pully control
const int button5 = 13; //motor used for pully (forward)
const int button6 = 10; //motor used for pully (backward)

int a=b=c=d=e=f=0;

void setup() {
  //for L298N motor driver
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  //for L293D
  
  //for button
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
}

void loop() {
  a = digitalRead(button1);
  b = digitalRead(button2);
  c = digitalRead(button3);
  d = digitalRead(button4);
  e = digitalRead(button5);
  f = digitalRead(button6);

  if (a == HIGH) {
    digitalWrite(in1, HIGH);
  }
  else {
    digitalWrite(in1, LOW);
  }
  
  if (b == HIGH) {
    digitalWrite(in3, HIGH);
  }
  else {
    digitalWrite(in3, LOW);
  }
  
  if (c == HIGH) {
    digitalWrite(in2, HIGH);
  }
  else {
    digitalWrite(in2, LOW);
  }
  
  if (d == HIGH) {
    digitalWrite(in4, HIGH); 
  }
  else {
    digitalWrite(in4, LOW);
  }

  if (e == HIGH){
    
  }
  else {
    
  }

  if (f == HIGH) {
    
  }
  else {
    
  }
}


