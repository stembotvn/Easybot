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

 
 
void setup() {
Robot.setup_lineSensor(BLACK,400);    //Set up cảm biến dò line nhận line màu đen nền trắng, ngưỡng phát hiện là 400 (dãi : có vạch 900, không vạch 30)
int distance = Robot.readSonar();  
while (distance > 10)  
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
 if (Robot.centerSensor() == true) { Robot.moveForward(100);}     

else if (Robot.leftSensor() == true) {
Robot.turnLeft(90);
}
 else if (Robot.rightSensor() == true) {
  Robot.turnRight(90);
 }

// delay(5);


}









