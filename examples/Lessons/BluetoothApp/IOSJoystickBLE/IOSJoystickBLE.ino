/*Easybot is a simple designed for early learing code for kids, this library . This is one of STEM education projects of Things Changing Technology Co. Ltd
Link: http://stembot.vn
 Easybot is suitable for 9-15 years old.
 Easybot is compatible with SmartCar Robot Models

*--Robot:
Core: Arduino Nano (Protoype)/Arduino Mini (Product)
Motor Driver: L9110S

Sensor: IR reflect sensor x 3 for line following 
        Sonar Range Finder sensor:  SRF04
---------------------------------------------------------------------------------------------------------------------
---- "Easybot là thư viện đơn giản mục đích cho trẻ em và học sinh có thể tiếp cận ban đầu với công nghệ trên nền tảng ARDUINO, tương thích với các dòng Robot thuộc dự án STEMbot (stembot.vn)
-----Cấu hình Robot------------------------------------------------------------------------------
Board mạch: Arduino Nano (chú ý chọn Board: Arduino Nano 328) 
Chip điều khiển động cơ: L9110S
Sensor: 3 IR Line detect sensor
        Cảm biến siêu âm đo khoảng cách SRF04
/////////////////////////////////////////////////////////////////////////////////////////////////////////
Chương trình mẫu điều khiển SmartCar trên SmartPhone qua Bluetooth Low Energy (Bluetooth 4.0) dựa trên chip CC2540, sử dụng App BLEJoystick cho cả IOS và Android
Android app Link :https://play.google.com/store/apps/details?id=iyok.com.blejoystick&hl=en  
IOS app Link: https://itunes.apple.com/us/app/ble-joystick/id1098200556?mt=8
Sử dụng: Gắn module JYD-08 hoặc HM-10 vào khe cắm Bluetooth 
      Bật bluetooth trên điện thoại
      Mở App BLEJoystick, bấm vào biểu tượng Bluetooth -> Scan BlueTooth Device tìm module JDY-08 hoặc HM-10  để kết nối
      
            
*----------------------------------------------------------------------------------------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Easybot.h"

EasybotNano Robot; 
SoftwareSerial BT(BT_Rx_Pin,BT_Tx_Pin);
char cmd;

void setup() {

BT.begin(115200);         // Bluetooth baurate Speed is 115200 bps for JDY-08 Module, 9600 for HM-10 module
Serial.begin(9600);     //Serial Monitor baurate Speed is 9600;
Serial.println(" Example for BLE Control on IOS and Android BLEJoystick App ");
delay(2000);

}



void loop() 
{

if (BT.available()>0) 
  {
  cmd = BT.read();
  Serial.print(cmd);
  Serial.println((int)cmd);
  }
  
 

  switch (cmd) {
   case 0: 
     Robot.stop();
      break;
   case 'A':
     Robot.moveForward(50);
      break;
   case 'a':
     Robot.moveForward(100);
      break;   
   case 'B':
     Robot.turnRight(50);
     break;
   case 'b':
     Robot.turnRight(70);
     break;  
   case 'D':
     Robot.turnLeft(50);
     break;
   case 'd':
     Robot.turnLeft(70);
     break;  
   case 'C':
     Robot.moveBack(60); 
     break;
    case 'c':
     Robot.moveBack(100); 
     break;  
     case 'H':
     Robot.stop(); 
     break;   
   default: 
  
     break;         
 
     }
  
  // else Robot.stop();

}
