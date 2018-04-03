
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
const uint64_t pipe = 0xE8E8F0F0E1LL;
byte address[][6] = {"robot"};      
RF24 radio(CE_PIN, CSN_PIN); // Activate  the Radio
int button=0;
int old_button=0;
int data[3];  // Two element array holding the Joystick readings
int old_data[3];
bool updated = 0;
int Cx;
int Cy;
int Cz;
int l = 0;
int r = 0;
void readsensor()
{
  Cx = analogRead(x); //Serial.print("Raw_X = "); Serial.print(Cx);
  Cy = analogRead(y);// Serial.print("__Raw_Y = "); Serial.print(Cy);
  Cz = analogRead(z);// Serial.print("__Raw_Z = "); Serial.println(Cz);

 // Cx = map(Cx, 300, 450 , -100, +100);
 // Cy = map(Cy, 300, 450 , -100, +100);
 // Cz = map(Cz, 300, 450 , -100, +100);
  
  Serial.print("Cx = ");
  Serial.print(Cx);
  Serial.print(" --- ");
  Serial.print("Cy = ");
  Serial.print(Cy);
  Serial.print(" --- ");
  Serial.print("Cz = ");
  Serial.println(Cz);
 
 
}
void setup()   
{
   Serial.begin(9600); 

  
  radio.begin();
  radio.setChannel(108);
  radio.setDataRate(RF24_1MBPS);    // Tốc độ truyền
  //radio.setAutoAck(0);
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
  if (data[0]!=old_data[0] || data[1] != old_data[1] || data[2] != old_data[2]) 
     { updated = 1; old_data[0] = data[0];old_data[1]=data[1];old_data[2]=data[2];}

//if (updated) 
 {
   radio.write( data, sizeof(data) );updated = 0;    
 }
}