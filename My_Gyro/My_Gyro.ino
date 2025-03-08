#include <myencoder_2motor.h>
#include <my2WD_encoder_3sensor.h>

#include <my_gyro.h>
#include <my_TCS34725.h>
int input_gyroY[5];
int input_gyroY_sticks[25];
int max_gyroY;
int min_gyroY;

float lastEncoderPos_L = 0.0;           // ตำแหน่งล่าสุดของ encoder
float lastEncoderPos_R = 0.0;           // ตำแหน่งล่าสุดของ encoder
//unsigned long lastTime = 0;           // เวลาอ่านล่าสุด (มิลลิวินาที)

// ค่าคงที่สำหรับการคำนวณ
const float wheelDiameter = 4.8;                      // เส้นผ่านศูนย์กลางล้อ (เซนติเมตร)
const float wheelCircumference = PI * wheelDiameter;  // เส้นรอบวงล้อ
const int pulsesPerRevolution = 440;                  // จำนวนพัลส์ต่อรอบ
const float pulsesPerCm = pulsesPerRevolution / wheelCircumference; // พัลส์ต่อเซนติเมตร

// ค่าคงที่ของ PID
float Kp = 0.55;  // ค่าคงที่สำหรับ Proportional
float Ki = 0.0001;  // ค่าคงที่สำหรับ Integral
float Kd = 0.05; // ค่าคงที่สำหรับ Derivative

// ตัวแปรสำหรับการคำนวณ PID
float targetYaw = 0.0;        // เป้าหมายมุม Yaw ที่ต้องการ
float errorSum = 0.0;         // ค่า error สะสม
float lastError = 0.0;        // ค่า error ล่าสุด
unsigned long lastTime = 0;   // เวลา (millis) ของรอบที่แล้ว

void setup() 
  {
    bz(100);bz(100);
    set_gyro();
    sensor_set();
    sw_st();
   
   move_fw();
   move_tl();
   
  }

void loop() 
  {
   
    spi_gyro('z');
    //Serial.println();
    if(digitalRead(9) == 0)
      {
        angleX = 0;
        angleY = 0;
        angleZ = 0;
        bz(50);
      }

  }
