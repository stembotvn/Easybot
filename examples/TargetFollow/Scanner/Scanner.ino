#include "Easybot.h"

EasybotNano Robot;
float distance;
int angle, nStep;
#define lost              (distance>20)
#define lookup            distance=Robot.readSonar()
#define turnleft(angl)    Robot.turnLeft(35,angl/10) 
#define turnright(angl)   Robot.turnRight(35,angl/10)
#define reset             { angle=nStep=0; Robot.stop(); }

void setup() {
  do {
    lookup;
  } while (distance>30);
  do {
    Robot.moveForward(70);
    lookup;    
  } while (lost);
  Robot.stop();
  reset;
}

void loop() {
  lookup; // tim muc tieu
  if (!lost) { reset; } else
  { // neu khong thay, bat dau tim kiem
    if (nStep>=3) { // neu da va tien 3 buoc ma van khong thay, doi huong tim kiem
      turnleft(40); //quay trai 
      reset;
    }
    delay(100);
    
    do { //quet ben trai truoc
      turnleft(10); angle+=10;
      lookup;
    } while (lost && (angle<180)); // dung lai khi tim thay hoac da quet het ben trai
    delay(100);
    
    lookup; // tim muc tieu
    if (!lost) { //neu thay
      reset;
    } else { // neu van khong thay, quet tiep ben phai
        turnright(90); angle=0;  delay(100); // quay lai vi tri goc ban dau =0
        
        do { // bat dau quet ben phai
          turnright(10); angle+=10;
          lookup;
        } while (lost && (angle<180)); //dung lai khi tim thay hoac da quet het ben phai
        delay(100);
        
        lookup; // tim muc tieu
        if (!lost) { //neu thay
          reset;
        } else { // da quet het ca 2 ben ma van khong thay
            turnright(90); angle=0; // quay lai vi tri goc ban dau =0
            Robot.moveForward(100); delay(200); Robot.stop(); // tien len 1 buoc
            nStep++; delay(1000);
          }
      } // end else 
  } // end if (lost)
}


