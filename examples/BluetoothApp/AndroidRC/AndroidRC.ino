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
Chương trình mẫu điều khiển SmartCar qua Android SmartPhone, sử dụng App: Arduino Bluetooth RC Car của tác giả Andi.Co 
Link: https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller&hl=en		
Sử dụng: Gắn module HC05/HC06 vào cổng HC05 trên Board Easybot Nano 
			Easybot Nano (Vcc Gnd Rx Tx) <--> HC05/06(Vcc Gnd Tx Rx)
			Bật chức năng Bluetooth trên điện thoại Android, Scan BlueTooth Device tìm module HC05 -> Nhập Pass 1234 để pair 2 thiết bị 
			Vào App Bluetooth RC Control, vào Setting, chọn "Connect to car" , chọn module HC05 (đã Paired) trong list thiết bị, nếu kết nối thành công thì đèn kết nối ở góc trái sáng màu xanh
			Điều khiển Robot với các chức năng cơ bản: tới, lùi, quay trái, quay phải. 
						
*----------------------------------------------------------------------------------------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Easybot.h"

EasybotNano Robot; 
SoftwareSerial BT(BT_Rx_Pin,BT_Tx_Pin);
char data; 
int  Speed = 100;
int  Mode = 0; // Mode = 0: Remote control, Mode = 1: Avoid Obstacle, Mode = 2: Line Following
 
void setup() {

BT.begin(9600);         // HC05 Bluetooth baurate Speed is 9600 bps
Serial.begin(9600);     //Serial Monitor baurate Speed is 9600;
Serial.println(" Example for Bluetooth Experience ");
delay(2000);
Robot.setup_lineSensor(BLACK,400);    //Set up cảm biến dò line nhận line màu đen nền trắng, ngưỡng phát hiện là 400 (dãi : có vạch 900, không vạch 30)

}
/////
void moving (char MoveID)
{
  char dataR = MoveID;
  switch (dataR) { 
    case 'S':  
       Robot.stop();    //Stop
       break;
    case 'F':  
      Robot.moveForward(Speed);    // Forward
       break;
    case 'G':  
       Robot.moveForward(Speed/2,Speed); //Forward Left
       break;
    case 'I':  
      Robot.moveForward(Speed,Speed/3);   //Forward Right
       break;   
    case 'H':  
       Robot.moveForward(-Speed/3,-Speed);   //Back Left 
       break;
    case 'J':  
      Robot.moveForward(-Speed,-Speed/2);   //Back Right
      break;
    case 'L':  
      Robot.turnLeft(Speed);  
      break;
    case 'R':  
      Robot.turnRight(Speed);  
      break;  
    case 'B':  
      Robot.moveBack(Speed);  
      break;  

    }     //Back Right 
}
////////////////////////////////////////////////
void Avoid_obstacle()
{
  int distance = Robot.readSonar();
  Serial.println(distance); 
  if (distance < 15) //nếu có vật cản gần hơn 15cm
    {
      Robot.stop();
      delay(100);
      Robot.moveForward(-70);
      delay(300);
      Robot.turnRight(70,3); // quay trái ở tốc độ 70%, thời gian quay 0.3s
      distance = Robot.readSonar(); 
      if (distance < 15) Robot.turnLeft(70,8); //nếu có vật cản gần hơn 15cm thì quay ra sau (tốc độ 70, thời gian quay 0.8s);
    }
  else Robot.moveForward(Speed);  //không có vật cản thì đi thẳng

}
///
void Line_following(){
if (Robot.centerSensor() == true) { Robot.moveForward(Speed);}     

else if (Robot.leftSensor() == true) {
Robot.turnLeft(Speed/2);
}
 else if (Robot.rightSensor() == true) {
  Robot.turnRight(Speed/2);
 }

}
/////////////////////////////////////////////////////////////////////
void loop() 
{
if (BT.available()>0 ) {
  data = BT.read();
   if (Mode == 0)
     {
      moving(data);
     }
  switch (data) { 
    case 'v':  
      Mode = 0;  Robot.stop();
      break;
    case 'V':
      Mode = 1;
      break;
    case 'x':
      Mode = 0; Robot.stop();
      break;
    case 'X':
      Mode = 2;
      break; 
    case '1':
      Speed = 10;
      break;  
    case '2':
      Speed = 20;
      break; 
    case '3':
      Speed = 30;
      break;
    case '4':
      Speed = 40;
      break;  
    case '5':
      Speed = 50;
      break;
    case '6':
      Speed = 60;
      break;
    case '7':
      Speed = 70;
      break;
    case '8':
      Speed = 80;
      break;
    case '9':
      Speed = 90;
      break;
    case 'q':
      Speed = 100;
      break;                                   
      }
  }
 
  if (Mode == 1) 
    {
    Avoid_obstacle();
    } 
  else if (Mode ==2)   
   {
   Line_following();
   }
}

