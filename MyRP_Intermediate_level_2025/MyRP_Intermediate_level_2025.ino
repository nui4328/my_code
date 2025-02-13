
#include <my2wd_encoder_high.h>
//#include <my2wd_encoder.h>

#include <Wire.h>
#include <my_mpu6050.h> 
#include <EEPROM.h>
#define EEPROM_ADDR 0x50

// ค่าคงที่สำหรับการคำนวณ
const float wheelDiameter = 5.0;                      // เส้นผ่านศูนย์กลางล้อ (เซนติเมตร)
const float wheelCircumference = PI * wheelDiameter;  // เส้นรอบวงล้อ
const int pulsesPerRevolution = 420;                  // จำนวนพัลส์ต่อรอบ
const float pulsesPerCm = pulsesPerRevolution / wheelCircumference; // พัลส์ต่อเซนติเมตร

bool lines;
bool lines_fw;
bool ch_lr = false;
bool ch_set_fb = false;
bool ch_bw = false;
bool line_l = true;
bool line_r = true;
char ch_lrs;

String set_bb;
int motor_slow = 20;
int fw_to_rotate = 280;

void setup()
  {    
     Serial.begin(9600);
     sensor_set();              // ค่าเริ่มต้น eeprom, bit_analogRead=>12   
     setup_mpu(); 
     mydisplay_background(black);
     mydisplay("MY-MAKERS", 20, 30, 2, white);
     
     servo(20, 160);
     sw_start();
//\\------------------------------------------->>>>>  เขียนโค๊ดที่นี้

   
    move_fw(50, 50, 30, "none_line"); 
    rotate_right(70, 330);
    set_b(2);
    
    move_fw(50, 50, 30, "none_line"); 
    rotate_right(70, 330);
    set_b(2);

    move_fw_none(30, 30, 70, "none_line"); 
    rotate_right(70, 330);
    
    move_fw(50, 50, 30, "line"); 
    rotate_left(70, 330);
    set_b(2);

     
   
//\\------------------------------------------->>>>>   เขียนโค๊ดที่นี้ 
     
      
  }

void loop() 
  {  
    for(int i = 0; i<8; i++)
      {
        Serial.print(md_mcp_f(i));
        Serial.print("  ");
      }
   Serial.println("  ");   
   // Serial.println(analogRead(28)); 
   //mydisplay_background(black);
   //mydisplay("MY-MAKERS", 20, 30, 2, white);

  }
