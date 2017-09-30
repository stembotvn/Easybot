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
/////////////////
Chương trình Demo thuật toán dò đường đơn giản		
---------------------------------------------------------------------------------------------------------------*/		
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Easybot.h"

EasybotNano Robot; 

int distance; //tạo một biến để ghi giá trị khoảng cách vật cản trước mặt robot, đơn vị là cm
 
void setup() {
Serial.begin(9600);  
distance = Robot.readSonar();   

while (distance > 10)    /// chờ vẫy tay trước mắt robot để khởi động
{
    Serial.print("READY! Sonar Sensor: "); Serial.println(distance); 
    delay(1000);
    distance = Robot.readSonar();  
 }
Serial.println("START!");  
Robot.moveForward(100);
}

///////
void loop()
{
distance = Robot.readSonar();
Serial.println(distance); 
  if (distance < 15) //nếu có vật cản gần hơn 15cm
    {
     Robot.turnRight(70,3); // quay trái ở tốc độ 70%, thời gian quay 0.3s
     distance = Robot.readSonar(); 
     if (distance < 15) Robot.turnLeft(70,8); //nếu có vật cản gần hơn 15cm thì quay ra sau (tốc độ 70, thời gian quay 8);
    }
  else Robot.moveForward(80);  //không có vật cản thì đi thẳng



}









