

#include "Easybot.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define CE_PIN   7
#define CSN_PIN  8
EasybotNano Robot; 
int speed=100;

byte address[1][6] = {"robot"};              // Radio pipe addresses for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;

/*-----Object Declaration ----*/

RF24 radio(CE_PIN, CSN_PIN); // Activate the Radio

/*-----Declaration of Variables -----*/

int data[3];  //  Two element array holding the data readings
bool done = false;
bool debug = 1; 
int x,y,l,r;
int Cx,Cy,Cz;
bool updated = 0;
void setup()  
{
  Serial.begin(9600); /* Opening the Serial Communication */

  Serial.println("Nrf24L01 Receiver Starting");
  radio.begin();
    radio.setChannel(108);
    radio.setDataRate(RF24_1MBPS);    // Tốc độ truyền
  radio.setPALevel(RF24_PA_HIGH);
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
  }
  else
  {    
    //  Serial.println("No radio available");
     // delay(500);
    // l=0;r=0;
    // Robot.stop();
  }

     if(updated){
     Cx = data[0];
     Cy = data[1];
     Cz = data[2];
     
      l = Cy+Cx; r = Cx-Cy; 
      if (l>100) l = 100; 
      else if (l<-100) l = -100;
      if (r>100) r = 100;
      else if (r<-100) r=-100; 
      if(debug){
      Serial.print("X = ");
      Serial.print(Cx);
      Serial.print(" Y = ");      
      Serial.print(Cy);
      Serial.print("     L = ");
      Serial.print(l);
      Serial.print(" R = ");
      Serial.println(r);
      }
  //    Robot.moveForward(l,r);
      }
      
      
      updated = 0;
   
    
 }