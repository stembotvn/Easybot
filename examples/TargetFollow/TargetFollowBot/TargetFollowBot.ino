#include "Easybot.h"

EasybotNano Robot; 
float distance, rDis, newDis; 
int dir;

#define moveforward  { moveOneStep(0); }
#define turnleft(angl)    { Robot.turnLeft(80,angl/30); }
#define turnright(angl)   { Robot.turnRight(80,angl/30); }


void setup() {
  do {
    distance=Robot.readSonar();
  } while (distance>40);
  do {
    moveOneStep(0);
    distance=Robot.readSonar();
  } while (distance>15);
  Robot.stop();
  distance=Robot.readSonar();
  dir=0;
}

void loop() {
  newDis=Robot.readSonar();
  if (newDis>30) { moveOneStep(0); } else // kc quá xa thì tiến lại gần
    if (newDis<10) { moveOneStep(6); } else // kc quá gần thì lùi ra xa
      if (((newDis-distance)>2) && (distance>10)) { // nếu khoảng cách vẫn nằm trong 10-15cm nhưng tăng lên quá 1.2cm (mà không phải do robot lùi thì dò tìm
        distance=Robot.readSonar(); dir=0;
        turnright(30); rDis=Robot.readSonar();
        if (rDis<distance) { distance=rDis; dir=3; }
        turnleft(60); rDis=Robot.readSonar(); 
        if (rDis<distance) { distance=rDis; dir=9; }
        
        if (dir==9) { moveOneStep(0); } else 
          { 
            turnright(30);
            if (dir==0) moveOneStep(0); else 
              { turnright(30); moveOneStep(0); }
          }
      }
  distance=newDis;
}

void moveOneStep(int dir) {
  if (dir==0) Robot.moveForward(80); else 
  if (dir==3) Robot.moveRight(60); else 
  if (dir==6) Robot.moveBack(50); else 
  if (dir==9) Robot.moveLeft(60); 
  delay (150); Robot.stop();
}
