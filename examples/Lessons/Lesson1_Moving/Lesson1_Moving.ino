#include "Easybot.h"

EasybotNano Robot; //tạo đối tượng Robot

 
 
void setup() {

Robot.waitStart(5);
Serial.println("START!");  
Robot.moveForward(100);
}

///////
void loop()
{


}