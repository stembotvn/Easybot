#include "Easybot.h"
#include <SPI.h>
#include "RF24.h"

EasybotNano Robot; 
RF24 radio(CE_PIN, CSN_PIN);
int Data[8];
int BF,BB,BL,BR,BZ,BLED,BX,BY; 
int Speed;
int updated;

void Move()
{
  if(BZ==0)
  {}
    //Negendo.tone(500,200);
  else if(BF==0)
    Robot.moveForward(90);
  else if(BB==0)
    Robot.moveBack(90);
  else if(BL==0)
    Robot.turnLeft(60);
  else if(BR==0)
    Robot.turnRight(60);
  else if(BX==0)
    Robot.setServo(90);
  else if (BY==0)
    Robot.setServo(0);
//  else if(BF==0 && BL==0)
//    Negendo.moveLeft(Speed);
//  else if(BF==0 && BR==0)
//    Negendo.moveRight(Speed);
//  else if(BB==0 && BL==0)
//    Negendo.moveBackLeft(Speed);
//  else if(BB==0 && BR==0)
//    Negendo.moveBackRight(Speed);
  else
  {
    Robot.stop();
  }
}

void readRadio()
{
  if ( radio.available())
  {
    while(radio.available())
    {
      //Serial.println("asad");
      radio.read( Data, sizeof(Data));
      updated = 1;
    }
  }
  ////////////////////////////////
  if(updated)
  {
    BF = Data[0];
    BB = Data[1];
    BL = Data[2];
    BR = Data[3];
    BZ = Data[4];
    BLED = Data[5];
    BX = Data[6];
    BY = Data[7];
    Speed = Data[8];
    updated = 0;
  }
  Move();
}

void setup()  
{
  Robot.initNRF24L01();
}
void loop()   
{
  Robot.setAddress();
  readRadio();
  //Serial.println("asad");
}
