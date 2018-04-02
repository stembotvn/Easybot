
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
-Chương trình mẫu cho bộ thu RF24L01 sử dụng cho Board Joystick Shield gắn với Arduino Uno
            
*----------------------------------------------------------------------------------------------------------------*/
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#define CE_PIN   9
#define CSN_PIN 10
#define JOYSTICK_X A0
#define JOYSTICK_Y A1
#define KeyA 2
#define KeyB 3
#define KeyC 4
#define KeyD 5
#define KeyE 6
const uint64_t pipe = 0xE8E8F0F0E1LL;
byte address[][6] = {"robot"};      
RF24 radio(CE_PIN, CSN_PIN); // Activate  the Radio
int button=0;
int joystick[3];  // Two element array holding the Joystick readings
int Val1 = 0;
int Val2 = 0;
int old_button = 0; 
int old_Val1 = 0;
int old_Val2 = 0;
bool updated = 0;
#define Tolerance 5
void setup()   
{
   Serial.begin(9600); 
   pinMode(KeyA,INPUT);
   pinMode(KeyB,INPUT);
   pinMode(KeyC,INPUT);
   pinMode(KeyD,INPUT);
   pinMode(KeyE,INPUT);
  
  radio.begin();
  radio.setChannel(108);
  radio.setDataRate(RF24_1MBPS);    // Tốc độ truyền
  radio.setPALevel(RF24_PA_HIGH);
  radio.openWritingPipe(pipe);
  Serial.println("Start");
  delay(1000);
}


void loop()   
{
  
  int Val1 = analogRead(JOYSTICK_X); 
  int Val2 = analogRead(JOYSTICK_Y); 
  if (abs(Val1 - old_Val1)> Tolerance) {
        updated = 1;
        old_Val1 = Val1;
        joystick[0] = Val1;}
   if (abs(Val2- old_Val2)> Tolerance) {
        updated = 1;
        old_Val2 = Val2;
        joystick[1] = Val2;}
  if (!digitalRead(KeyA)) button = 1;
  else if (!digitalRead(KeyB)) button = 2;
  else if (!digitalRead(KeyC)) button = 3;
  else if (!digitalRead(KeyD)) button = 4;
  else if (!digitalRead(KeyE)) button = 5;
     
  else button = 0;
  
if (button!=old_button)
{  updated =1; 
   joystick[2]= button;
   old_button = button; 
  
 
   // delay(500);
    }
if (updated) 
 {
   radio.write( joystick, sizeof(joystick) );updated = 0;    
 }
}