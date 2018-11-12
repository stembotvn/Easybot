#include "Easybot.h"
#include "LiquidCrystal_I2C.h"


EasybotNano Robot;

void setup() 
{

  Serial.begin(9600);  
  Robot.init();
}
void loop()
{
  Robot.setColor(255,0,0);
}
