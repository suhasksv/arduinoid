// Arduino Mega code (head)
#include <VirtualWire.h>
const int receiver_pin = 4;

String message;
String myString;

//for joystick
int xvalue; 
int yvalue;
int buttonf;
int xdata; 
int ydata; 
int bfdata; // buttonflag 

//for L298N motor driver
int ena = 10;
int enb = 5;

int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;

void setup() {
  delay(1000);
  Serial.begin(9600);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  analogWrite(ena, 0);
  analogWrite(enb, 0);
  delay(1000);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
  vw_set_rx_pin(receiver_pin);
  
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);  // Bits per sec
  
  vw_rx_start(); 
  
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) {
    int i;

    for (i = 0; i < buflen; i++) {
      char c = (buf[i]);
            message = message + c ;
    } 
     myString = message; 
    Serial.println(message);
    
    String l = getValue(myString, ',', 0); // xvalue
    String m = getValue(myString, ',', 1); // yvalue
    String n = getValue(myString, ',', 2); // buttonf
      
    xdata = l.toInt();
    ydata = m.toInt();
    bfdata = n.toInt();

    if( ((xdata >= 480)&&(xdata <= 510)) && ( (ydata>=480) && (ydata<=510) ) ) {
      Serial.println("Stopped");
      analogWrite(ena, 0);
      analogWrite(enb, 0);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
    
    if(bfdata == 0) {
      analogWrite(ena, 0); 
      analogWrite(enb, 0);
      digitalWrite(in1, LOW); 
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      }
    if ( ((xdata > 510)&&(xdata <= 1023)) && ( (ydata>=480) && (ydata<=510) ) ) {
     Serial.println("forward"); 
     int xmapped = map(xmapped, xdata, 1023, 255,0);
     int ymapped = map(ymapped, xdata, 1023, 255,0);
     analogWrite(ena, xmapped); 
     analogWrite(enb, ymapped);
 
     digitalWrite(in1, HIGH); 
     digitalWrite(in2, LOW);
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
    }
  if ( ((xdata >= 0)&&(xdata < 480)) && ( (ydata>=480) && (ydata<=510) ) ){
     Serial.println("reverse");
     int xmapped = map(xmapped, xdata, 479, 255,0);
     int ymapped = map(ymapped, xdata, 479, 255,0);
     analogWrite(ena, xmapped); 
     analogWrite(enb, ymapped);
   
    digitalWrite(in1, LOW); 
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    }
  
  if (  ( (ydata> 510) && (ydata <= 1023) ) && ( bfdata == 1) ) {
   Serial.println("Right");
   int ymapped = map(ymapped, ydata, 1023, 255,0);
   analogWrite(ena, ymapped); 
   analogWrite(enb, 0);
   
   digitalWrite(in1, HIGH); 
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);
   }
  if (  ( (ydata >= 0) && (ydata <= 479) && ( bfdata == 1) ) ) {
   Serial.println("left");
   int ymapped = map(ymapped, ydata, 479, 255,0);
   analogWrite(ena, 0); 
   analogWrite(enb, ymapped);
   
   digitalWrite(in1, LOW); 
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
   }
    message = "";
  }  
}

String getValue(String data, char separator, int index) {
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
 
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

