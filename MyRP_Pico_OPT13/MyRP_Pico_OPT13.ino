#include <my_MINI_RP.h>
#define EEPROM_ADDR 0x50
#include <EncoderLibrary.h>
EncoderLibrary encoder(6, 7, 15, 20);
#include <my_TCS34725.h> 
my_TCS34725 tcss = my_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
float PID_outputs=0,errorss=0,Is=0,Ds=0;
int num_place_left = 0;
int num_place_right = 0;
int num_place_total;
int ch_floor ;
int ch_can ;
int end_13s = 0;
int none_13 = 0;
int dis_bw_end = 54;
int ch_dis_can = 1400;  // ---->> วัดระยะตอนไม่มีกระป๋อง
int ch_collor_can = 5000;  //----->> ตั้งค่ากลางระหว่างสีของกระป๋อง
int servo_down = 50;      //-------------------->> ตั้งค่า มื่อจับลงขนานกับพื้น
int servo_close = 160;

void setup() 
  {    
      _seting();                 //-------------------->> ฟังก์ชัน ตั้งค่าต่าง ๆ ใน tab seting
      encoder.setupEncoder();    //-------------------->> เรียกฟังก์ชัน setupEncoder
      encoder.resetEncoders();  //--------------------->> ฟังก์ชันรอก
     

      //arm_down_open();
      //arm_down_close();
      servo(8, servo_down+80);delay(200);
      
      
      sw();             //-------------------->> ฟังก์ชันรอกดปุ่ม       
  
///------------------------------------------------------------------>>>>  เขียนโค๊ดที่นี่ 
    start_robot();   
    st_game();  

    
  
///------------------------------------------------------------------>>>>  เขียนโค๊ดที่นี่ 

  }  ///-->> บรรทัดห้ามลบ


///-------------------------->> คงไว้ห้ามลบ
void loop() {
  //Motor(30, 30);
  //check_can();
      Serial.print(analogRead(28));
      Serial.print("     ");
      Serial.println(color_can());
    // Serial.print(encoder.Poss_L());
    // Serial.print(" ");
    // Serial.println(encoder.Poss_R());
     delay(10);
  }
///-------------------------->> คงไว้ห้ามลบ
