# Easybot

Arduino C/C++, Mblock Scratch (đang trong quá trình xây dựng)

Easybot là bộ thư viện viết riêng cho Board EasyControl V1, Core Arduino Nano V3 do STEMbot.vn phát triển

STEMbot.vn phát triển bộ thư viện Easybot có thể giúp các bạn mới làm quen với Arduino và Robot tiếp cận dễ dàng hơn bao giờ hết. Code đơn giản, ngắn gọn để các bạn chỉ tập trung vào thuận toán giải quyết các vấn đề. 

STEMbot đang tích hợp việc lập trình Easybot từ Mblock Scratch, ngôn ngữ dựa trên hình ảnh dành cho trẻ em để có thể mang việc lập trình robot dễ dàng hơn với các trẻ từ 7-12 tuổi.

## Cài Đặt Thư viện
  Download code từ thư mục này theo định dạng .Zip file. 
  Trên Phần mềm Arduino IDE: chọn Sketch/Include Library/Add Zip Library -> Chọn đường dẫn đến file .Zip vừa tải về. 
  Khởi động lại Arduino IDE, chọn Tools/Board/Arduino Nano
  Vào Files/Examples/Easybot để xem code mẫu
##Sử dụng thư viện:
    1. Khai báo thư viện: #include <Easybot.h>
    2. Tạo đối tượng robot: EasybotNano Robot; // Một đối tượng robot tên là Robot được tạo ra từ lớp EasybotNano
   ### Các thuộc tính di chuyển của robot:
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
   ### Các thuộc tính xử lý cảm biến:
  *  Cảm biến dò Line 3 kênh Analog:
  
   int value = Robot.readSensor(Channel);  //gán giá trị Analog đọc từ sensor vào biến value kiểu Interger, Channel = LEFTSENSOR,CENTERSENSOR, RIGHTSENSOR
	- In ra màn hình để kiểm tra: 				
   Serial.println(value); //xuất giá trị analog từ Sensor 
   bool result = Robot.left(); // Trả về giá trị Logic là 0 hay 1 (True or False) cho cảm biến dò line trái (0: không có vạch, 1: có vạch)
   Serial.print(Robot.leftSensor());//xuất giá trị kết quả (1 or 0) phân tích từ analog Sensor, ngưỡng mặc định so sánh để phát hiện vạch kẻ là 400
    Nâng cao:
	- Nếu muốn thay đổi ngưỡng phát hiện vạch (tùy vào chất liệu và độ phản quan của sân chơi) thì
     #define line_detect  number 
	  trước khi #include <Easybot.h>; 
	  
	vd: #define line_detect 250 //ngưỡng phát hiện vạch là 250
        #include <Easybot.h>
     your code .......		
    
   * Cảm biến siêu âm đo khoảng cách SRF04
    
	-   int value = Robot.readSonar(); //gán giá trị đo khoảng cách tính bằng Cm vào biến Value kiểu Interger
	
 
    
  
  
