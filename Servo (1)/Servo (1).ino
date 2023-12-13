#include <Servo.h> // Khai báo thư viện servo

Servo myservo;// Tạo đối tượng tên myservo

int pos = 0;//Tạo biến nhận giá trị góc quay

void setup() {

  myservo.attach(5,500,2500);  // Chân 5, Chu kỳ Min, Max

}

void loop() {

  //Điều khiển servo quay một góc 90 độ

  for (pos = 0; pos <= 90; pos += 1) { //Biến pos sẽ chạy từ 0-90

    myservo.write(pos);              //ra lệnh servo quay một góc “pos”
    delay(15);                       // Chờ 15ms để động cơ đạt đến vị trí pos

  }

  delay(500); //Khi quay đến vị trí góc 180 độ dừng 2s

  //Điều khiển servo quay về vị trí 0 độ

  for (pos = 92; pos >= 0; pos -= 1) { //Biến pos sẽ chạy từ 180 về 0

    myservo.write(pos);            

    delay(15);                      

  }

  delay(500); //Khi quay đến vị trí góc 0 độ dừng 2s

}
