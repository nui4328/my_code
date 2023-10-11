#include <my_rp_4wd.h>
#include <Wire.h>
#include <my_TCS34725.h>  
#include <my_mpu6050.h> 
#include <EEPROM.h>
#define EEPROM_ADDR 0x50
  
unsigned long lasts_time=millis();
//------------------------->>
// กำหนดพินอินพุตตัวเข้ารหัส

const int encoderPinA = 0; 
const int encoderPinB = 1; 

// กำหนดตัวแปรเพื่อติดตามตำแหน่งและทิศทางของตัวเข้ารหัส
volatile int encoderPoss = 0;  // Variable to store the encoder position
int encoderPinALast = LOW;  
int n = LOW;
//------------------------->>

int ch_line_r = 0;
int ch_line_l = 0;
int dis_line_r = 150;  /////////////////------->>  สไลออกมา
int time_bridge = 600;
int time_chopsticks = 600;
int ch_encoder = 0;
float deg_90_R = 85.0;


int ch_bridge;
int chopsticks;
int ch_l, ch_r;
int bg_st=0;
String color_ch="none";
int none_yello = 0;
int ch_line;
int ch_mcp_f5;
int ch_line_bridge;
int sensor_maxs[] = {750, 750, 711, 735,770,770}; 
int sensor_mins[] = {180, 178, 117, 120, 110, 110}; 
int red_box, green_box, blue_box, yello_box, ch_poit;

int mcp_f0 = 0;
int mcp_f1 = 0;

int servo23 = 80;
int servo22 = 85;

my_TCS34725 tcss = my_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
void setup()
  {    
     Serial.begin(9600);
     sensor_set();              // ค่าเริ่มต้น eeprom, bit_analogRead=>12   
     setup_mpu();
     setup_encoder_fw();
     calibration_Yak();   
     mydisplay_background(black);
     mydisplay("MY-MAKERS", 20, 30, 2, white);
     pinMode(27,INPUT_PULLUP);
     pinMode(26,INPUT_PULLUP);

     servo(22, servo22);
     servo(23, servo23);
     //servo(28, 20);  // ----> เซอร์โวยกธง servo(28, 20) ยกธงขึ้น;

   
     sw_start();    
         //cal_censor(0, 0);sw_md();
     
//\\------------------------------------------->>>>>  เขียนโค๊ดที่นี้ 
    
    //Motor(50,50,50,50);delay(2000);
    fw_begin(50, 500);   
     
    for(int i = 0; i<200; i++)
      {
        fw_ch_r(50, 500);
      }

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
