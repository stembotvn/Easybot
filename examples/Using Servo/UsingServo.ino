#include "Easybot.h"
EasybotNano Robot; //tạo đối tượng Robot
//ServoTimer2 myservo; 
 int pos = 0;

void setup() {
Serial.begin(9600);
Serial.println("START!");  
Robot.moveForward(50);
}

///////
void loop()
{
 for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Robot.setServo(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    Robot.setServo(pos);              // tell servo to go to position in variable 'pos'
    delay(15);    
  }
}