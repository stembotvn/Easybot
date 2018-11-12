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
////////////////////////////////
void EasybotNano::setup_lineSensor(int color, int threshold_detect){
_LINE_COLOR = color;
_line_detect = threshold_detect; 
pinMode(lineSensor_enable,OUTPUT);
}

//////////////////////////////////
int EasybotNano::readSensor(int channel)
{
digitalWrite(lineSensor_enable,HIGH);
 int line_value = analogRead(channel);
digitalWrite(lineSensor_enable,LOW);

 return line_value;
}
///////////////////////////////////////////////////////
bool EasybotNano::leftSensor(){
bool color;	
int value;
digitalWrite(lineSensor_enable,HIGH);
value = analogRead(leftline_pin);
digitalWrite(lineSensor_enable,LOW);

color  =  _LINE_COLOR; 
   if (color == BLACK) 
    {
     if (value>_line_detect) return 1;
     else return 0;
    }
   else 
   {
      if (value<_line_detect) return 1;
      else return 0;
   }
}
////////////////////////////////////////////////////////
bool EasybotNano::rightSensor(){
bool color;
int value;		

digitalWrite(lineSensor_enable,HIGH);
 value = analogRead(rightline_pin);
digitalWrite(lineSensor_enable,LOW);

 color  =  _LINE_COLOR; 
   if (color == BLACK) 
    {
     if (value>_line_detect) return 1;
     else return 0;
    }
   else 
   {
      if (value<_line_detect) return 1;
      else return 0;
   }

}
///////////////////////////////////////////////////
bool EasybotNano::centerSensor(){
bool color;
int value;	

digitalWrite(lineSensor_enable,HIGH);
 value = analogRead(centerline_pin);
digitalWrite(lineSensor_enable,LOW);
 
 color  =  _LINE_COLOR; 
   if (color == BLACK) 
    {
     if (value>_line_detect) return 1;
     else return 0;
    }
   else 
   {
      if (value<_line_detect) return 1;
      else return 0;
   }
}

///////////////////////////////////
float EasybotNano::readSonar() {
  float range = Distance.Ranging(CM);
  delay(100);
return range;
    }
void EasybotNano::setServo(int Angle)
{
// if (!servo.attached) 
  servo.attach(Servo_Pin);
 servo.write(Angle);
}
//////////// NRF24L01 /////////////////////////
void EasybotNano::init()
{
  pinMode(Buzzer_Pin, OUTPUT);
  pinMode(RGB_Pin, OUTPUT);
  pixels.begin();
}
void EasybotNano::initNRF()
{
  Serial.begin(9600);

  radio.begin();
  radio.setChannel(108);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_PA_HIGH);
  convertAdd();
}
void EasybotNano::convertAdd()
{
  _readAdd = EEPROM.read(0);
  _AddRandom = (_AddDefault & ~0xFFLL) | _readAdd;
  radio.openReadingPipe(1,_AddRandom);
  radio.startListening();
  Serial.print("Address: ");
  Serial.print((unsigned long)(_AddRandom >> 32), 16);
  Serial.println((unsigned long)_AddRandom, 16); 
  Serial.println("Ready to receive data");
}

void EasybotNano::setAddress()
{
  pinMode(Button_Pin, INPUT);
  if(!digitalRead(Button_Pin))
  {
    Serial.println("Set Address");
    Serial.println("Wait 5s...");
    _startTime = millis();
    while(!digitalRead(Button_Pin))
    {
      if(millis() - _startTime == 5000)
      {
        Sound.sing(S_mode3);
      }
    }
    _duration = millis() - _startTime;
    if(_duration > 5000)
    {
      radio.openReadingPipe(1,_AddDefault);
      radio.startListening();
      Serial.println("Ready to receive new address...");
      for(unsigned long starts = millis(); (millis() - starts) < _timeout;)
      {
        if(radio.available())
        {
          radio.read(_Add, sizeof(_Add));
          _address = _Add[0];
          EEPROM.write(0,_address);
          Serial.println("Set address done.");
          Sound.sing(S_connection);
          break;
        }
      }
      convertAdd();
    }
    else
    {
      Sound.sing(S_cuddly);
    }
  }
}
int EasybotNano::readLDRRight()
{
  LDRR = analogRead(LDR1);
  LDRR = map(LDRR,0,800,0,100);
  LDRR = LDRR > 100 ? 100 : LDRR;
  return LDRR;
}
int EasybotNano::readLDRLeft()
{
  LDRL = analogRead(LDR2);
  LDRL = map(LDRL,0,800,0,100);
  LDRL = LDRL > 100 ? 100 : LDRR;
  return LDRL;
}
void EasybotNano::setColor(byte R, byte G, byte B)
{
  R = R > 255 ? 255 : R;
  G = G > 255 ? 255 : G;
  B = B > 255 ? 255 : B;

  pixels.setPixelColor(0, pixels.Color(R,G,B));
  pixels.show();
}
void EasybotNano::offRGB()
{
  pixels.setPixelColor(0, pixels.Color(0,0,0));
  pixels.show();
}
bool EasybotNano::readButton()
{
  int BT = analogRead(Button_Pin);
  if(BT > 1020)
    return 1;
  else
    return 0;
}
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
