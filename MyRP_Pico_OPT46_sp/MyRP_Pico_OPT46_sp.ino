#include <my_MINI_RP.h>
#define EEPROM_ADDR 0x50
#include <EncoderLibrary.h>
EncoderLibrary encoder(6, 7, 15, 20);
#include <my_TCS34725.h> 
#include <EEPROM.h>
#define EEPROM_ADDR 0x50

my_TCS34725 tcss = my_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
int num_place_right = 0;
int num_place_left = 0;
int num_place_center = 0;
int num_place_total;
int ch_floor ;
int ch_can ;
String collor_can;

String collor_floor[] = {"red", "yellow", "green"} ;

int dis_bw_end = 54;
int ch_dis_can = 700;  // ---->> วัดระยะตอนไม่มีกระป๋อง
int ch_collor_can = 5000;
int end_13s = 0;
int none_13 = 0;

float PID_outputs=0,errorss=0,Is=0,Ds=0;
int servo_down = 50;      //-------------------->> ตั้งค่า มื่อจับลงขนานกับพื้น
int servo_close = 150;
int restarts = 0;
int dis_canst2 = 29;  //------------------>> ตั้งค่าตอนคีบกระป๋องที่ 2 ข้างบนไม่ถึง ถ้าชนให้ลด  

uint16_t count_cans = 0;
uint16_t count_cans_ree = 13;
uint16_t readEEP_cans ;
uint16_t readEEP_cans_ree;

void setup() 
  {    
      _seting();                 //-------------------->> ฟังก์ชัน ตั้งค่าต่าง ๆ ใน tab seting
      encoder.setupEncoder();    //-------------------->> เรียกฟังก์ชัน setupEncoder
      encoder.resetEncoders();  //--------------------->> ฟังก์ชันรอก
     

      //arm_down_open();
      arm_down_close();delay(500);
      
      
      sw();             //-------------------->> ฟังก์ชันรอกดปุ่ม       
  
///------------------------------------------------------------------>>>>  เขียนโค๊ดที่นี่ 
   
   //start_robot();
    //can_5(); sw();
     //can_6();sw();
      //can_7();sw();
       //can_8();sw();
        can_9();sw();
   

///------------------------------------------------------------------>>>>  เขียนโค๊ดที่นี่ 

  }  ///-->> บรรทัดห้ามลบ


///-------------------------->> คงไว้ห้ามลบ
void loop() {
  
      //Serial.println(analogRead(28));
    Serial.println(check_color());
    // Serial.print(encoder.Poss_L());
    // Serial.print(" ");
    // Serial.println(encoder.Poss_R());
     delay(10);
  }
///-------------------------->> คงไว้ห้ามลบ
