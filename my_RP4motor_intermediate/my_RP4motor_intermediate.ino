#include <my_rp_4wd.h>
#include <Wire.h>
#include <my_TCS34725.h>  
#include <my_mpu6050.h> 
#include <EEPROM.h>
#define EEPROM_ADDR 0x50
  
unsigned long lasts_time=millis();
//------------------------->>
// กำหนดพินอินพุตตัวเข้ารหัส
const int pin_RA =16;
const int pin_RB = 17;

const int pin_LA =0;
const int pin_LB = 1;

// กำหนดตัวแปรเพื่อติดตามตำแหน่งและทิศทางของตัวเข้ารหัส
volatile int encoderPos_R = 0;
volatile int encoderPos_L = 0;
int encoderDir_R = 1;
int encoderDir_L = 1;
int prevAVal_R, prevAVal_L;
//------------------------->>

int ch_line_r = 0;
int dis_line_r = 310;
int ch_bridge;
int chopsticks;

String color_ch;

int sensor_maxs[] = {936, 942, 925, 955, 941, 922}; 
int sensor_mins[] = {189, 189, 175, 186, 189, 184}; 

int TR = 400;
int TL = 400;
 
int red_box, green_box, blue_box, yello_box;
my_TCS34725 tcss = my_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
void setup()
  {    
     Serial.begin(9600);
     sensor_set();              // ค่าเริ่มต้น eeprom, bit_analogRead=>12   
    // setup_mpu();
     setup_encoder();
    // calibration_Yak();   
     mydisplay_background(black);
     mydisplay("MY-MAKERS", 20, 30, 2, white);
     pinMode(27,INPUT_PULLUP);

     servo(22, 90);
     servo(23, 90);
     //servo(28, 20);
     sw_start();    
         //cal_censor(0, 0);sw();
         //test_line_r();
         
//\\------------------------------------------->>>>>  เขียนโค๊ดที่นี้ 
  
   
 box1();
 box2();
 box3();
 box4();
 
   
//\\------------------------------------------->>>>>   เขียนโค๊ดที่นี้ 
     
      
  }

void loop() 
  {  
    Serial.println(digitalRead(27));

   /*
    float red, green, blue;
     uint16_t r, g, b, c;
     tcss.getRawData(&r, &g, &b, &c);     
     float averag = (r+g+b)/3;
     red = r/averag; ;
     green = g/averag; 
     blue = b/averag;
    float color[3] = {red, green, blue};
    for(int i = 0; i<3; i++)
      {
        Serial.print(color[i]);Serial.print("  ");
      }
     Serial.println(" ");
     delay(4);
     check_color_roll_bz();
   */
   delay(10);
  }
