#include <my_rp_pro.h>
#include <my_TCS34725.h> 
float rotA, rot, high, lowA, low;
float theta1,theta2,theta3;
#define ROBOT_ARM_LOW 60
#define ROBOT_ARM_HIGH 65
#define ROBOT_ARM_EE_OFFSET 0

int servo_tim23 = 0;
int servo_tim8 = 0;
int servo_tim7 = 0;
// Number of steps
int num_steps = 20;

// Initial angles
float s23_before_deg = 90 + servo_tim23;
float s8_before_deg = 90 + servo_tim8;
float s7_before_deg = 90 ;

int random_tour[4] = {1, 1, 1, 0 } ;

void setup() 
  {    
      _seting();         //-------------------->> ฟังก์ชัน ตั้งค่าต่าง ๆ ใน tab seting
     
      //co_xyz(65, 60, 20);
     servo(1, 65); servo(29, 65); delay(500);
     servo(1, 120); servo(29, 120); delay(500);
     servo(23, 165);delay(500);servo(23, 125);delay(500); servo(23, 165);
     co_xyz(65, 60, 20);co_xyz(65, 0, 20);co_xyz(65, 60, 20);co_xyz(45, 60, 20);
      //co_xyz(65, 60, 20);
      //co_xyz(85, -10, 20);delay(300);
      sw();             //-------------------->> ฟังก์ชันรอกดปุ่ม       
      //test_bord();
///------------------------------------------------------------------>>>>  เขียนโค๊ดที่นี่   

      
      out_box();
         
      //Pooparterb();
      //Poonorom();
      //Market_home();
      //Sparn_pra();
     //Moohan();
      //Songnang();
    //tour_1();
     //tour_2();
     //tour_3();
     //tour_4();
     //tour_5();

     
///------------------------------------------------------------------>>>>  เขียนโค๊ดที่นี่ 

  }  ///-->> บรรทัดห้ามลบ


///-------------------------->> คงไว้ห้ามลบ
void loop() {

     Serial.println(analogRead(28));
     
     //Serial.print(encoder.Poss_L());
     //Serial.print(" ");
     //Serial.println(encoder.Poss_R());
     //Serial.println(my_tcs('r'));
  }
///-------------------------->> คงไว้ห้ามลบ
