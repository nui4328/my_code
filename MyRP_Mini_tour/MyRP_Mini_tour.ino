#include <my_MINI_RP.h>
#define EEPROM_ADDR 0x50
#include <EncoderLibrary.h>
EncoderLibrary encoder(6, 7, 15, 20);
#include <my_TCS34725.h> 

float rotA, rot, high, lowA, low;
float theta1,theta2,theta3;
#define ROBOT_ARM_LOW 80
#define ROBOT_ARM_HIGH 75
#define ROBOT_ARM_EE_OFFSET 0

int servo_tim8 = 0;
int servo_tim0 = 0;
int servo_tim1 = 0;
// Number of steps
int num_steps = 20;

// Initial angles
float s8_before_deg = 90 + servo_tim8;
float s0_before_deg = 90 + servo_tim0;
float s1_before_deg = 90 ;


void setup() 
  {    
      _seting();                 //-------------------->> ฟังก์ชัน ตั้งค่าต่าง ๆ ใน tab seting
      encoder.setupEncoder();    //-------------------->> เรียกฟังก์ชัน setupEncoder
      encoder.resetEncoders();  //--------------------->> ฟังก์ชันรอก
     

      //arm_down_open();
      //servo(8, 90);
      
      sw();             //-------------------->> ฟังก์ชันรอกดปุ่ม 
      //test_bord(); sw();      
  
///------------------------------------------------------------------>>>>  เขียนโค๊ดที่นี่      
   /*
   co_xyz(75, 80, 40); 
   co_xyz(40, -40, 40); delay(1000);
   move_bed(180); delay(1000);
   move_bed(90); delay(1000);
   */
   start_game();
   tour_1();

///------------------------------------------------------------------>>>>  เขียนโค๊ดที่นี่ 

  }  ///-->> บรรทัดห้ามลบ


///-------------------------->> คงไว้ห้ามลบ
void loop() {

     Serial.println(encoder.Poss_R());
     delay(10);
  }
///-------------------------->> คงไว้ห้ามลบ
