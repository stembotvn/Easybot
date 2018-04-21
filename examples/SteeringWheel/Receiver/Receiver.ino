

#include "Easybot.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define CE_PIN   7
#define CSN_PIN  8

#define offset      20   // stop if below value 
#define Range       80   // Max speed 

EasybotNano Robot; 
int speed=100;
byte address[1][6] = {"robot"};              // Radio pipe addresses for the 2 nodes to communicate.
//const uint64_t pipe = 0xE8E8F0F0E1LL;
//const uint64_t pipe = 0xE8E8F0F0BBLL;  // robot do 
const uint64_t pipe = 0xE8E8F0F0CCLL;  // robot xanh

/*-----Object Declaration ----*/

RF24 radio(CE_PIN, CSN_PIN); // Activate the Radio

/*-----Declaration of Variables -----*/

int data[4];  //  Two element array holding the data readings
bool debug = 1; 
int l,r;
int Cx,Cy,Cz;
bool updated = 0;
void setup()  
{
  Serial.begin(9600); /* Opening the Serial Communication */

  Serial.println("Nrf24L01 Receiver Starting");
  radio.begin();
    radio.setChannel(120);
    radio.setDataRate(RF24_1MBPS);    // Tốc độ truyền
 radio.setPALevel(RF24_PA_HIGH);
   //radio.setAutoAck(0);
  radio.openReadingPipe(1,pipe);
  radio.startListening();
  l=0;r=0;  //left speed = 0; right speed = 0; 
    delay(1000);
}//--(end setup )---


void loop()   
{
  if ( radio.available() )
  {
    // Reading the data payload until the RX received everything
  //done = false;
   while (radio.available()) {                                   // While there is data ready
        radio.read( data, sizeof(data));    // Get the payload
        updated = 1; 
       
      }
   Serial.println("updated"); 
   Serial.println(data[3]);   
  }
  
  if(updated){
     Cx = data[0];
     Cy = data[1];
     Cz = data[2];
     Serial.print(Cx);Serial.print(",");Serial.println(Cy);

    
      l = Cy+Cx; r = Cy-Cx; 
      if (l>Range) l = Range; 
      else if (l<-Range) l = -Range;
      if (r>Range) r = Range;
      else if (r<-Range) r=-Range; 
     
      if((Cy<offset && Cy >-offset) && (Cx <offset && Cx >-offset))
          {
            Robot.stop();
          }
      else   Robot.moveForward(l,r);
      updated = 0;
      }
      
      
      
      
   
    
 }