
/*Easybot is a simple designed for early learing code for kids, this library . This is one of STEM education projects of Things Changing Technology Co. Ltd
Link: http://stembot.vn
 Easybot is suitable for 9-15 years old.
 Easybot is compatible with SmartCar Robot Models

*--Robot:
Core: Arduino Nano (Protoype)/Arduino Mini (Product)
Motor Driver: L9110S

Sensor: IR reflect sensor x 3 for line following 
        Sonar Range Finder sensor:  SRF04
---------------------------------------------------------------------------------------------------------------------
-Chương trình mẫu cho Smart Glove Control Robot - (Transmitter mode)
            
*----------------------------------------------------------------------------------------------------------------*/
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#define CE_PIN   7
#define CSN_PIN 8
#define x A2
#define y A1
#define z A0
#define debug_EN 2
#define Maxspeed    80
#define RED 
//const uint64_t pipe = 0xE8E8F0F0E1LL;
//const uint64_t pipe = 0xE8E8F0F0BBLL;  // robot do 
#ifndef RED
const uint64_t pipe = 0xE8E8F0F0CCLL;  // robot xanh
#else const uint64_t pipe = 0xE8E8F0F0BBLL;  // robot do 
#endif
byte address[2][6] = {"robot1","robot2"};      
RF24 radio(CE_PIN, CSN_PIN); // Activate  the Radio
int button=0;
int old_button=0;
int data[4];  // Two element array holding the Joystick readings
int old_data[4];
bool updated = 0;
int Cx,Cy,Cz,RCx,RCy,RCz;

int l = 0;
int r = 0;
int Calib_Max =400;
int Calib_Zero = 330 ;
//int Calib_Max =400;
//int Calib_Zero = 330 ;
int Calib_Min = 2*Calib_Zero - Calib_Max;


void readsensor()
{
  RCx = analogRead(x); //Serial.print("Raw_X = "); Serial.print(Cx);
  RCy = analogRead(y);// Serial.print("__Raw_Y = "); Serial.print(Cy);
  RCz = analogRead(z);// Serial.print("__Raw_Z = "); Serial.println(Cz);
 if (!digitalRead(debug_EN))
 {
    Serial.print("Raw_X = "); Serial.print(RCx);
    Serial.print("__Raw_Y = "); Serial.print(RCy);
    Serial.print("__Raw_Z = "); Serial.println(RCz);
    
  }
   Cx = map(RCx, Calib_Min, Calib_Max , -Maxspeed, +Maxspeed);
   Cy = map(RCz, Calib_Min, Calib_Max , +Maxspeed, -Maxspeed);
     // Cz = map(RCz, Calib_Min, Calib_Max , +Maxspeed, -Maxspeed);
  if (!digitalRead(debug_EN)) 
  
{
    Serial.print(Cx);Serial.print(",");Serial.println(Cy);
    
  }
 //delay(1000);
  //Plotting Data to Graphic 
  //Serial.print(RCx);Serial.print(",");Serial.println(RCy);Serial.print(",");
  

/*  
  Serial.print("Cx = ");
  Serial.print(Cx);
  Serial.print(" --- ");
  Serial.print("Cy = ");
  Serial.print(Cy);
  Serial.print(" --- ");
  Serial.print("Cz = ");
  Serial.println(Cz);
  */
 
 
}
void setup()   
{
   Serial.begin(9600); 

  pinMode(debug_EN,INPUT_PULLUP);
  radio.begin();
  #ifndef RED
  radio.setChannel(120);
  #else   radio.setChannel(108);
  #endif 

  radio.setDataRate(RF24_1MBPS);    // Tốc độ truyền
  radio.setPALevel(RF24_PA_HIGH);
   radio.openWritingPipe(pipe);
  Serial.println("Start");
  delay(1000);
}


void loop()   
{
  readsensor();
  data[0] = Cx;
  data[1] = Cy;
  data[2] = Cz;
  data[3] = 127; //for test transmitter
//  if (data[0]!=old_data[0] || data[1] != old_data[1] || data[2] != old_data[2]) 
//     { updated = 1; old_data[0] = data[0];old_data[1]=data[1];old_data[2]=data[2];}

//if (updated) 
 {
   if (radio.write( data, sizeof(data) )) Serial.println("Data sent!");
   else Serial.println("Fail!");
 /*  radio.write(data,sizeof(data)); 
   bool ok = radio.txStandBy();
   if (ok) Serial.println("Data sent!");
   else Serial.println("Fail!");*/
  //  ;updated = 0;    
 }
}