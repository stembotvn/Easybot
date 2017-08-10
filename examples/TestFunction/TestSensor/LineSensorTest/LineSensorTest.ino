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
////////////////////////////////////////////////////////////////////////////////		
Cách sử dụng hàm liên quan Sensor dò line: 
	- object.readSensor(channel); //trả về giá trị thô đọc được từ ADC  kiểu int  theo các kênh là chân tín hiệu trực tiếp đến cảm biến,  Channel: LEFTSENSOR, RIGHTSENSOR, CENTERSENSOR; 
	- object.leftSensor(); //trả về giá trị đã qua xử lý kiểu Boolean (True or False) nếu có phát hiện vạch từ Sensor bên trái
	- object.centerSensor(); //trả về giá trị đã qua xử lý kiểu Boolean (True or False) nếu có phát hiện vạch từ Sensor giữa
	- object.rightSensor(); //trả về giá trị đã qua xử lý kiểu Boolean (True or False) nếu có phát hiện vạch từ Sensor bên phải


  Khai báo thư viện sử dụng: 
  #include <Easybot.h>
  Tạo đối tượng (object) tên là Robot từ lớp EasybotNano: 
	- EasybotNano Robot; 		
    - Tạo biến chứa giá trị đọc:        int value; 
	- gán giá trị Analog đọc từ sensor dò line vào biến value:  value = Robot.readSensor(); 
	- In ra màn hình để kiểm tra: 				Serial.println(value); //xuất giá trị analog từ Sensor 
												Serial.print(Robot.leftSensor());//xuất giá trị kết quả (1 or 0) phân tích từ analog Sensor, ngưỡng mặc định so sánh để phát hiện vạch kẻ là 400
    Nâng cao:
	- Nếu muốn thay đổi ngưỡng phát hiện vạch (tùy vào chất liệu và độ phản quan của sân chơi) thì #define line_detect  number 
	  trước khi #include <Easybot.h>; 
	  
	vd: #define line_detect 250 //ngưỡng phát hiện vạch là 250
        #include <Easybot.h>
     your code .......		
*----------------------------------------------------------------------------------------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Easybot.h"

EasybotNano Robot; 
int value; 
 
 
void setup() {

Serial.begin(9600);         //

}

///////
void loop()
{
Serial.println("Reading Line Sensor");
//Serial.print("Detect value: ");Serial.println(line_detect);

Serial.print("Left Sensor : ");
value = Robot.readSensor(LEFTSENSOR);
Serial.print(value);  
Serial.print(" ---Line detect: ");
Serial.print(Robot.leftSensor());
Serial.print("------");

Serial.print("Center Sensor : ");
value = Robot.readSensor(CENTERSENSOR);
Serial.print(value);  
Serial.print(" --Line detect: ");
Serial.print(Robot.centerSensor());
Serial.print("------");

Serial.print("Right Sensor : ");
value = Robot.readSensor(RIGHTSENSOR);
Serial.print(value);  
Serial.print(" --Line detect: ");
Serial.println(Robot.rightSensor());



delay(1000);  //repeat after 1s 
}









