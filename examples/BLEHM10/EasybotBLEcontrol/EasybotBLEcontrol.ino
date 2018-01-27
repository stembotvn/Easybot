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

 
void setup() {

BT.begin(9600);         // HC05 Bluetooth baurate Speed is 9600 bps
Serial.begin(9600);     //Serial Monitor baurate Speed is 9600;
Serial.println(" Example for Testing HC05 Bluetooth Data ");
delay(2000);
}

void loop() 
{
if (BT.available()>0 ) 
  {
  data = BT.read();
    if (data == 'S')  { Robot.stop();delay(1);}
  else if (data == 'F') {Robot.moveForward(Speed);//delay(300);
  Serial.print(data);}
  else if (data == 'B') {Robot.moveBack(Speed);//delay(300);
  Serial.print(data);}
  else if (data == 'L') {Robot.turnLeft(Speed);//delay(300);
  Serial.print(data);}
  else if (data == 'R') {Robot.turnRight(Speed);//delay(300);
  Serial.print(data);}
  
  }

}

