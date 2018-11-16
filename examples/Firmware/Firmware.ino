#include "Easybot.h"

EasybotNano Robot;

//////////////////////////////////////
void setup()
{
  Robot.init(0);
}
///////////////////////////
void loop()
{
  Robot.run();
}
