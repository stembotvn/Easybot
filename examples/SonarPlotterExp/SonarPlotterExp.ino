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
---- "Easybot là thư viện đơn giản mục đích cho trẻ em và học sinh có thể tiếp cận ban đầu với công nghệ trên nền tảng ARDUINO, tương thích với các dòng Robot thuộc dự án STEMbot (stembot.vn)
-----Cấu hình Robot------------------------------------------------------------------------------
Board mạch: Arduino Nano (chú ý chọn Board: Arduino Nano 328) 
Chip điều khiển động cơ: L9110S
Sensor: 3 IR Line detect sensor
        Cảm biến siêu âm đo khoảng cách SRF04
		///////////////////////////////////////////
Cách sử dụng hàm liên quan Sensor siêu âm SRF04: object.readSonar(); //trả về giá trị khoảng cách phía trước, đơn vị là CM 
  Khai báo thư viện sử dụng: 
  #include <Easybot.h>
  Tạo đối tượng (object) tên là Robot từ lớp EasybotNano: 
	- EasybotNano Robot; 		
    - Tạo biến chứa giá trị khoảng cách:        int value; 
	- gán giá trị đọc từ SRF04 vào biến value:  value = Robot.readSonar(); 
	- In ra màn hình để kiểm tra: 				Serial.println(value); 


*----------------------------------------------------------------------------------------------------------------*/


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Easybot.h"

EasybotNano Robot; 
float value; 
 
 
void setup() {

Serial.begin(9600);         //

}

void loop() {


 
//Serial.println(" Read Distance from Sonar Sensor in Cm ");
//Serial.print("Distance is :");


value = Robot.readSonar();
Serial.println(value); 
//Serial.print(" ");
   



}
