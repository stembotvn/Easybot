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
////////////////////////////////////////////////
Chương trình Demo thuật toán dò đường mịn 		
---------------------------------------------------------------------------------------------------------------

 */

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Easybot.h"

EasybotNano robot; 

 
 int linespeed = 90 ;              //speed for linefollow process
 int adjspeed = 60; 
 int turn_speed = 65;
 bool r=0;   // biến boolean lưu cờ nhớ trạng thái lệch trái
 bool l=0;   // biến boolean lưu cờ nhớ trạng thái lệch phải
 
void setup() {

Serial.begin(9600);
delay(2000);
}

///////
void loop()
{
 
 if (robot.centerSensor() == true) {  //process if center sensor detected
  robot.moveForward(linespeed);
  }   

else if (robot.leftSensor() == true) {     //process if left Sensor detected
robot.moveForward(adjspeed,linespeed);l=1;
}
 else if (robot.rightSensor() == true) {   //process if right Sensor detected          
 robot.moveForward(linespeed,adjspeed);
 r=1; 
 }
  else                                    //process if no line detected -> loss line
  {
   if (l==true)  {robot.turnLeft(turn_speed);
   l=false;
   } 
   else if (r ==true) {robot.turnRight(turn_speed);
   r=false;
   }
  }


}










