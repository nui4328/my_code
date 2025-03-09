//#include <my2wd_encoder.h>
#include <my_MINI_RP.h>
#define EEPROM_ADDR 0x50
#include <my_mpu6050.h>

#include <EncoderLibrary.h>
EncoderLibrary encoder(6, 7, 15, 20);

//const int pulsesPerRevolution = 440;  // จำนวนพัลส์ต่อการหมุนหนึ่งรอบของล้อ
//const float wheelDiameter = 0.048;      // เส้นผ่านศูนย์กลางของล้อ (เมตร)
//const float wheelCircumference = wheelDiameter * 3.14159;  // เส้นรอบวงของล้อ (เมตร)

float lastEncoderPos_L = 0.0;           // ตำแหน่งล่าสุดของ encoder
float lastEncoderPos_R = 0.0;           // ตำแหน่งล่าสุดของ encoder
//unsigned long lastTime = 0;           // เวลาอ่านล่าสุด (มิลลิวินาที)

// ค่าคงที่สำหรับการคำนวณ
const float wheelDiameter = 4.8;                      // เส้นผ่านศูนย์กลางล้อ (เซนติเมตร)
const float wheelCircumference = PI * wheelDiameter;  // เส้นรอบวงล้อ
const int pulsesPerRevolution = 440;                  // จำนวนพัลส์ต่อรอบ
const float pulsesPerCm = pulsesPerRevolution / wheelCircumference; // พัลส์ต่อเซนติเมตร

// ค่าคงที่ของ PID
float Kp = 1.0;  // ค่าคงที่สำหรับ Proportional
float Ki = 0.1;  // ค่าคงที่สำหรับ Integral
float Kd = 0.05; // ค่าคงที่สำหรับ Derivative

// ตัวแปรสำหรับการคำนวณ PID
float targetYaw = 0.0;        // เป้าหมายมุม Yaw ที่ต้องการ
float errorSum = 0.0;         // ค่า error สะสม
float lastError = 0.0;        // ค่า error ล่าสุด
unsigned long lastTime = 0;   // เวลา (millis) ของรอบที่แล้ว

void setup() 
  {    
      _seting();    
      setup_mpu(); //-------------------->> ฟังก์ชัน ตั้งค่าต่าง ๆ ใน tab seting
      encoder.setupEncoder();    //-------------------->> เรียกฟังก์ชัน setupEncoder
      encoder.resetEncoders();  //--------------------->> ฟังก์ชันรอก
      lastEncoderPos_L = encoder.Poss_L();  // อ่านตำแหน่งเริ่มต้น
      lastEncoderPos_R = encoder.Poss_R();  // อ่านตำแหน่งเริ่มต้น
      lastTime = millis();

     

      sw();             //-------------------->> ฟังก์ชันรอกดปุ่ม       
  
///------------------------------------------------------------------>>>>  เขียนโค๊ดที่นี่     

  
    moveForwardWithPID(55, 25);
     rotateRobotPID(90, 1.5, 0.3, 2.0);
    moveForwardWithPID(55, 25);
    rotateRobotPID(-90, 1.5, 0.3, 2.0);
    moveForwardWithPID(55, 25);
    rotateRobotPID(-90, 1.5, 0.3, 2.0);
    moveForwardWithPID(55, 28);
    rotateRobotPID(-90, 1.5, 0.3, 2.0);
    moveForwardWithPID(55, 20);
    rotateRobotPID(-90, 1.5, 0.3, 2.0);
    moveForwardWithPID(55, 27);
    rotateRobotPID(90, 1.5, 0.3, 2.0);
    moveForwardWithPID(55, 20);
    rotateRobotPID(90, 1.5, 0.3, 2.0);
    moveForwardWithPID(55, 40);
    sw_st();
    moveForwardWithPID(40, 20);
    rotateRobot(50, 90);
    moveForwardWithPID(40, 20);
    rotateRobot(50, 90);
    moveForwardWithPID(40, 20);
    rotateRobot(50, 90);
    moveForwardWithPID(40, 20);
    rotateRobot(50, 90);
    moveForwardWithPID(40, 20);
    rotateRobot(50, 180);
    moveForwardWithPID(25, 30);

///------------------------------------------------------------------>>>>  เขียนโค๊ดที่นี่ 

  }  ///-->> บรรทัดห้ามลบ


///-------------------------->> คงไว้ห้ามลบ
void loop() 
  {

    Serial.print("Encoder_L: ");
        Serial.print(encoder.Poss_L());
        Serial.print("     ");
        Serial.print("Encoder_R: ");
        Serial.println(encoder.Poss_R());
    /*    
    diplay_mpu();
    Serial.print("pitch: "); 
    Serial.print(readPitch()); 
    
    Serial.print("  yaw: "); 
    Serial.print(readYaw()); 

    Serial.print("   roll: ");
    Serial.println(readRoll()); 
    if(digitalRead(9)==0)
      {
        reset_Yaw();  
        reset_PitchRoll();     
        bz(100);
      }
    delay(10);
  */
  }
///-------------------------->> คงไว้ห้ามลบ
