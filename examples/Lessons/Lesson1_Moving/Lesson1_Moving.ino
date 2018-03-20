#include "Easybot.h"

EasybotNano Robot; //tạo đối tượng Robot

 
 
void setup() {

Robot.waitStart(5); // Chờ phất dấu hiệu khởi động trước mặt robot để bắt đầu
Serial.println("START!");  
Robot.moveForward(100);
}

///////
void loop()
{


}