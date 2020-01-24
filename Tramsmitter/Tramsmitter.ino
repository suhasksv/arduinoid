//Arduino uno (remote)
#include <VirtualWire.h>
const int transmit_pin = 10;

String str;
char cstr[100];
String message = "";
unsigned int mlength;

// for joystick
int flag = 0;
int power = 3;
int buttonf = 0;
int button = 2;
int vrx = A0;
int vry = A1;

int xdata = 0;
int ydata = 0;

void setup() {
  vw_set_tx_pin(transmit_pin);
  vw_setup(2000);
  Serial.begin(9600);

  pinMode(vrx, INPUT);
  pinMode(vry, INPUT);
  pinMode(power, OUTPUT);
  digitalWrite(power, HIGH);

  pinMode(button, INPUT);
  digitalWrite(button, HIGH);
}

void loop() {
  control();

  if (button == 1) {
    xdata = analogRead(vrx);  
    ydata = analogRead(vry);

    SendData(xdata,ydata,buttonf);
  }

  if (buttonf == 0) {
    SendData(0,0,0);
    delay(100);
  }
}

void SendData(int xvalue, int yvalue, int buttonstatus) {
  message = message + xvalue + "," + yvalue + "," + buttonstatus;
  mlength = message.length();
  str = message;
  str.toCharArray(cstr, 100);  
  vw_send((uint8_t *)cstr, mlength);
  vw_wait_tx();
  str = "";
  message = "";
  
}

void control() {
  if ((digitalRead(button) == LOW) && (buttonf == 0)) {
    Serial.println("started");
    buttonf = 1;
    delay(1000);
  }
  if ((digitalRead(button) == LOW) && (buttonf == 1)) {
    Serial.println("Ended");
    buttonf = 0;
    delay(1000);
  }
  digitalWrite(button, HIGH);
}

