#include <SPI.h>  
#include <Pixy.h>
#include "Easybot.h"

EasybotNano Robot; 
Pixy pixy;

void setup()
{
  Serial.begin(9600);
  Serial.print("Starting...\n");
  pixy.init();
}

void loop()
{ 
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  
  // grab blocks!
  blocks = pixy.getBlocks();
  
  // If there are detect blocks, print them!
  if (blocks)
  {
    {
      i++;
      if (i%10==0)
      {
        if (((pixy.blocks[0].y) <150) && (((pixy.blocks[0].x) > 80) && (pixy.blocks[0].x) < 150))
        {
          Robot.moveForward(30, 30);
        }
        else if (((pixy.blocks[0].y) < 150) && ((pixy.blocks[0].x) < 80))
        {
          Robot.moveForward(30,40);
        }
        else if (((pixy.blocks[0].y) < 150) && ((pixy.blocks[0].x) > 150))
        {
          Robot.moveForward(40,30);
        }
        else if (((pixy.blocks[0].y) > 150) && (((pixy.blocks[0].x) > 80) && (pixy.blocks[0].x) < 150))
        {
          Robot.moveForward(-30, -30);
        }
        else
        {
          Robot.stop();
          //delay(5);
        }
      }
    }
  }
}

