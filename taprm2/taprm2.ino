const int led1 = 13;
//const int led2 = 10;
const int interrupt = 2;

int count = 0;


void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  //pinMode(led2, OUTPUT);
  digitalWrite(led1, LOW);
  //digitalWrite(led2, LOW);
  pinMode(interrupt, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt), bp, CHANGE);
  // this is to interrupt arduino
}

void loop() {
}

void bp() {
  
  int re = 0;
  
  count++;  
 
  re = count % 2; // this line calculate remainder

  if (re == 0) {
    Serial.println(re, count);
    digitalWrite(led1, HIGH);
    //digitalWrite(led2, LOW);
  }
  else {
    Serial.println(re, count);
    digitalWrite(led1, LOW);
  //  digitalWrite(led2, HIGH);
  }
}


