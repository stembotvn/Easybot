
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
#include <nRF24L01.h>
#include <RF24.h>

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
  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(pipe);
  Serial.println("Start");
  delay(1000);
}


void loop()   
{
  joystick[0] = analogRead(JOYSTICK_X); 
  joystick[1] = analogRead(JOYSTICK_Y); 
  if (!digitalRead(KeyA)) button = 1;
  else if (!digitalRead(KeyB)) button = 2;
   else if (!digitalRead(KeyC)) button = 3;
    else if (!digitalRead(KeyD)) button = 4;
    else if (!digitalRead(KeyE)) button = 5;
     else button = 0;
   joystick[2]= button;
   radio.write( joystick, sizeof(joystick) );
      delay(50);
}