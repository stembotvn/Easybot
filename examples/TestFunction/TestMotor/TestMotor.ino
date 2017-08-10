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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
Example để test các động cơ trái phải, thử các động tác đi tới đi lùi, quay trái, quay phải
Cách sử dụng các chức năng di chuyển cơ bản và nâng cao:
  Khai báo thư viện sử dụng: 
  #include <Easybot.h>
  Tạo đối tượng tên là Robot từ lớp EasybotNano: 
	- EasybotNano Robot; 
  Hàm đi thẳng: 
		- Robot.moveForward(speed); //với speed = 0-100(%) 	điều khiển robot di chuyển đi tới với tốc độ speed (bánh bên phải chạy với tốc độ = speed, bánh trái chạy với tốc độ = speed
  Hàm đi thẳng nâng cao: 
        - Robot.moveForward(LeftSpeed,rightSpeed); //với leftSpeed, rightSpeed = 0-100 (%), điều khiển robot đi thẳng với tốc độ bên trái và bên phải tùy chỉnh. 
  Hàm đi lùi:
		- Robot.moveBack(speed); // với speed = 0-100(%) 	điều khiển robot di chuyển đi lùi với tốc độ speed (bánh bên phải chạy với tốc độ = speed, bánh trái chạy với tốc độ = speed
  Hàm quay trái cơ bản:
		- Robot.turnLeft(speed); //với speed = 0 - 100(%), điều khiển robot quay trái, tâm quay tại tâm robot, bánh trái quay lùi với tốc độ speed, bánh phải quay tới với tốc độ speed 
  Hàm quay phải cơ bản: 
		- Robot.turnRight(speed); //với speed = 0 - 100(%), điều khiển robot quay phải, tâm quay tại tâm robot, bánh phải quay lùi với tốc độ speed, bánh trái quay tới với tốc độ speed 
  Hàm quay trái nâng cao:
		- Robot.turnLeft(speed,time); với speed = 0 - 100(%): tham số tốc độ , time = 0 -10 :tham số thời gian-> Quay trái robot với tốc độ = speed trong khoảng thời gian là time x 0.1s
  Hàm quay phải nâng cao:
		- Robot.turnright(speed,time); với speed = 0 - 100(%): tham số tốc độ , time = 0 -10 :tham số thời gian-> Quay phải robot với tốc độ = speed trong khoảng thời gian là time x 0.1s 		
*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <Easybot.h> 
EasybotNano Robot;
void setup() {

Serial.begin(9600); // Khởi tạo chức năng Serial để gửi dữ liệu kiểm tra lên máy tính thông qua công cụ Serial Monitor 

}

void loop() {
 
Robot.moveForward(100);
delay(3000);
Robot.stop();
delay(200);

Robot.moveBack(100);
delay(3000);
Robot.stop();
delay(200);

Robot.turnLeft(100);
delay(3000);
Robot.stop();
delay(200);

Robot.turnRight(100);
delay(3000);
Robot.stop();
delay(200);

}