#include "Arduino.h"
#include "Easybot.h"




/*void EasybotNano::begin(){
 
}*/

///////////////////////////////////////
void EasybotNano::moveForward(int speed){
 int movespeed = speed*255/100; 
 LeftMotor.run(movespeed);
 RightMotor.run(movespeed);
}
////
void EasybotNano::moveBack(int speed){
int  movespeed = speed*255/100; 
 LeftMotor.run(-movespeed);
 RightMotor.run(-movespeed);	
}
////////////////////////////////////////////
 void EasybotNano::moveForward(int leftspeed,int rightspeed)
 {
 	int Lspeed = leftspeed*255/100;
 	int Rspeed = rightspeed*255/100;
 	LeftMotor.run(Lspeed);
 	RightMotor.run(Rspeed);
 }

 void EasybotNano::moveRight(int speed)
 {
//int rspeed;
//rspeed = speed*255/100; 	
moveForward(speed,0);

 }
 ///
 void EasybotNano::moveLeft(int speed)
 {
//int rspeed;
//rspeed = speed*255/100; 	
moveForward(0,speed);
 }
 
//////////////////////////////
void EasybotNano::stop()
{
	LeftMotor.stop();
  RightMotor.stop();
}
///////////////////////////////

void EasybotNano::turnRight(int speed){
int turnspeed = speed*255/100;

LeftMotor.run(turnspeed);
RightMotor.run(-turnspeed);

}
/////////////////////////////////////////
void EasybotNano::turnRight(int speed,int time)
{
int turnspeed = speed*255/100;
int i = 0;

LeftMotor.run(turnspeed);
RightMotor.run(-turnspeed);
for (i=0;i<time;i++)
 {
  delay(100);
 }
 stop();
 delay(200);
}
/////////////////////
void EasybotNano::turnLeft(int speed){
int turnspeed = speed*255/100;
//LeftMotor.stop();
//RightMotor.stop();
//delayMicroseconds(deadband_time);
	 LeftMotor.run(-turnspeed);
	 RightMotor.run(turnspeed);
//delay(turn_duration_time);
//LeftMotor.stop();
//RightMotor.stop();
//delay(deadband_time);
}
//////////
void EasybotNano::turnLeft(int speed,int time)
{
int turnspeed = speed*255/100;
int i = 0;

LeftMotor.run(-turnspeed);
RightMotor.run(turnspeed);
for (i=0;i<time;i++)
 {
  delay(100);
 }
 stop();
 delay(200);

}

//////////////////////////////////
int EasybotNano::readSensor(int channel)
{

 int line_value = analogRead(channel);
 return line_value;
}
///////////////////////////////////////////////////////
bool EasybotNano::leftSensor(){
bool color;	
int value;
value = analogRead(leftline_pin);
color  =  LINE_COLOR; 
   if (color == BLACK) 
    {
     if (value>line_detect) return 1;
     else return 0;
    }
   else 
   {
      if (value<line_detect) return 1;
      else return 0;
   }
}
////////////////////////////////////////////////////////
bool EasybotNano::rightSensor(){
bool color;
int value;		
 value = analogRead(rightline_pin);
 color  =  LINE_COLOR; 
   if (color == BLACK) 
    {
     if (value>line_detect) return 1;
     else return 0;
    }
   else 
   {
      if (value<line_detect) return 1;
      else return 0;
   }

}
///////////////////////////////////////////////////
bool EasybotNano::centerSensor(){
bool color;
int value;		
 value = analogRead(centerline_pin);
 color  =  LINE_COLOR; 
   if (color == BLACK) 
    {
     if (value>line_detect) return 1;
     else return 0;
    }
   else 
   {
      if (value<line_detect) return 1;
      else return 0;
   }
}

///////////////////////////////////
int EasybotNano::readSonar() {
return (Distance.Ranging(CM));
    }
 /////////////////////////////////////////////////////////////////////////////////   
/*
 //////////////////////////////////
 
void Easybot::lookright()
{
	
Headservo.attach(Servo1_pin);   	
Headservo.write(Right_angle);
delay(500);
Headservo.detach();//release for using PWM on Pin 9,10


}

//////
void Easybot::lookleft()
{

Headservo.attach(Servo1_pin); 	
Headservo.write(Left_angle);
delay(500);
Headservo.detach();//release for using PWM on Pin 9,10


}
///
void Easybot::lookfront()
{

Headservo.attach(Servo1_pin); 
Headservo.write(Center_angle);
delay(500);
Headservo.detach();//release for using PWM on Pin 9,10


}

*/
