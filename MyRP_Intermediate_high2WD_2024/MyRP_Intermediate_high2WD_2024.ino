
#include <my2wd_encoder_high.h>
#include <Wire.h>
#include <my_mpu6050.h> 
#include <my_TCS34725.h>

//------------------------->>
//my_TCS34725 tcss = my_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
// กำหนดพินอินพุตตัวเข้ารหัส


double cr[] = {444.00, 118.00, 118.00};
double cg[] = {98.00, 192.00, 151.00};
double cb[] = {90.00, 147.00, 231.00};
double cy[] = {980.00, 748.00, 293.00};

int red_box, green_box, blue_box, yello_box, ch_poit;
int servo20 = 95;
int servo28 = 95;
int num_encoder = 0;
int roll_L = 900;

String floor_R;
String floor_M;
String floor_L;

String can;

String color_ch="none";

const int pinA = 11;
const int pinB = 10;

// กำหนดตัวแปรเพื่อติดตามตำแหน่งและทิศทางของตัวเข้ารหัส
volatile int encoderPos = 0;
volatile int encoderPos_r = 0;
int encoderDir = 1;
int prevAVal;
//------------------------->>
char lr ;
bool lines;
bool lines_fw;
bool ch_lr = false;
bool ch_set_fb = false;
bool ch_bw = false;
bool line_l = true;
bool line_r = true;
bool LR_free = false;
bool ch_point;
int motor_slow = 15;
int fw_to_rotate = 350;  
int get_encode_toline;

int rotate_left = 570;  // หมุนซ้ายกลับออกมาหากไม่ตรงให้ปรับค่าตรงนี้  หมุนซ้ายมากให้ลดลง //---------------------->>>
int rotate_right = 570;

int Back_from_line = 340;       // เจอเส้นแล้วถอยหลังก่อนจะหมุ่นตัวซ้ายเพื่อเดินต่อ
int Forward_not_finding_line = 500;  // เดินหน้าต่อเมื่อไม่เจอเส้น ให้ถึงกลางบล๊อก

int start_begin = 0;
int rotate_color = 600;  // หมุนซ้ายกลับออกมาหลังจากวางกล่องตามสี
int speed_rotate = 30;

void setup()
  {    
     Serial.begin(9600);
     sensor_set();              // ค่าเริ่มต้น eeprom, bit_analogRead=>12   
     setup_encoder();

     mydisplay_background(black);
     mydisplay("MY-MAKERS", 20, 30, 2, white);
     read_eppcolor();
     servo(20, servo20);
     servo(28, servo28);
     servo(27, 20);

     begin_robot();
     //servo(27, 120);sw();
     
//\\------------------------------------------->>>>>  เขียนโค๊ดหุ่นยนต์ที่นี้
   
      encoderPos = 0;
      do{Motor(30, 30);} while(encoderPos < 1700);     
      
      speed_rotate = 30;           //------------>>  ตั้งความเร็วในการหมุน ซ้ายขวา
      rotate_right = 630;           //------------>>  ตั้งค่า องศา ในการหมุน ขวา 
      rotate_left = 570;           //------------>>  ตั้งค่า องศา ในการหมุน ซ้าย
      
      rotate_color = 580;           //------------>>  ตั้งค่า องศา ในการหมุน ซ้าย หลังจากที่ถอยออกมา
      while(1)
        {
          move_fw(25, 25, 1580);     //------------>>  ตั้งค่า 30, 30  คือความเร็วของมอเตอร์  ซ้าย และ ขวา  1600 คือ ระยะทางเดิน ระหว่างบล๊อก 
        }
  

      
//\\------------------------------------------->>>>>   เขียนโค๊ดที่นี้ 
     
      
  }

void loop() 
  {  
  }
