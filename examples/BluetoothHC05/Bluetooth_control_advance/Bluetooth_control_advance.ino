#include "Easybot.h"

EasybotNano Robot; 
SoftwareSerial BT(BT_Rx_Pin,BT_Tx_Pin);
char data; 
int  Speed = 100;

void setup() {
  BT.begin(9600);         // HC05 Bluetooth baurate Speed is 9600 bps
  Serial.begin(9600);     //Serial Monitor baurate Speed is 9600;
  Serial.println(" Example for Testing HC05 Bluetooth Data ");
  delay(2000);
}

void loop() {
  if (BT.available()>0 ) {
    data = BT.read();
    if (data == 'S') { Robot.stop();delay(1); } else 
    if (data == 'F') { Robot.moveForward(Speed);} else 
    if (data == 'B') { Robot.moveBack(Speed); } else 
    if (data == 'L') { Robot.moveLeft(Speed); } else
    if (data == 'R') { Robot.moveRight(Speed);} else
    if (data == 'G') { Robot.moveForward(50,Speed);} else
    if (data == 'I') { Robot.moveForward(Speed,50);} else
    if (data == 'H') { Robot.moveForward(-50,-Speed);} else
    if (data == 'J') { Robot.moveForward(-Speed,-50);}
    
    if (data != 'S') Serial.println(data);
  }
}
