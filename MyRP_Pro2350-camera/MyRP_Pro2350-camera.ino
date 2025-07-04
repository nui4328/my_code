
#include <Wire.h>
#include <my_GYRO.h>
#include "my_MCP3008.h"
my_MCP3008 adc;
#include <my_TCS34725.h>
#include <EncoderLibrary.h>
EncoderLibrary encoder(6, 7, 15, 20);

#include "HUSKYLENS.h"

HUSKYLENS huskylens;
//HUSKYLENS green line >> SDA; blue line >> SCL
void printResult(HUSKYLENSResult result);


#define EEPROM_ADDR 0x50
#include <my_TCS34725.h>

// ฟังก์ชันสำหรับเขียนข้อมูล 16 บิตลง CAT24C128
// ที่อยู่สำหรับเก็บค่าสีใน EEPROM
#define RED_SET_ADDR 80    // เก็บชุดค่าสีแดง (R, G, B)
#define GREEN_SET_ADDR 90  // เก็บชุดค่าสีเขียว (R, G, B)
#define BLUE_SET_ADDR 100  // เก็บชุดค่าสีน้ำเงิน (R, G, B)
#define YELLOW_SET_ADDR 110 // เก็บชุดค่าสีเหลือง (R, G, B)


// สถานะการเลือกสี
enum ColorState { NONE, RED, GREEN, BLUE, YELLOW, SEARCH };
ColorState currentState = NONE;
bool colorsStored = false; // ตัวแปรเพื่อตรวจสอบว่าเก็บครบ 4 สีแล้วหรือไม่
String color_tcs;

my_TCS34725 tcss = my_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

// กำหนดพินควบคุมมอเตอร์


#define PWMA 6     // PWM ซ้าย
#define AIN1 22
#define AIN2 23

#define PWMB 3     // PWM ขวา
#define BIN1 21
#define BIN2 20
//___--------------------------------------------->>
#define EEPROM_ADDRESS 0x50 // ที่อยู่ I2C ของ CAT24C256
const int numSensors = 8;
const int numSamples = 1000;
int sensorValuesA[numSensors][numSamples]; // เก็บข้อมูลเซนเซอร์จาก read_sensorA
int sensorMaxA[numSensors];
int sensorMinA[numSensors];
int sensorValuesB[numSensors][numSamples]; // เก็บข้อมูลเซนเซอร์จาก read_sensorB
int sensorMaxB[numSensors];
int sensorMinB[numSensors];
int sensorValuesC[2][numSamples]; // เก็บข้อมูลจาก analogRead(46) และ analogRead(47)
int sensorMaxC[2]; // Max สำหรับพิน 46 และ 47
int sensorMinC[2]; // Min สำหรับพิน 46 และ 47
int sensorMax_A[numSensors];
int sensorMin_A[numSensors];
int sensorMax_B[numSensors];
int sensorMin_B[numSensors];
int sensorMax_C[2]; // Max สำหรับพิน 26 และ 27
int sensorMin_C[2]; // Min สำหรับพิน 26 และ 27
float P, I, D, previous_I, previous_error,errors, PID_output, present_position, previous_integral; 
int numSensor = 6; 
int state_on_Line = 0;
int setpoint;
int _lastPosition;
int sensor_pin_A[] = {1,2,3,4,5,6}; 
int sensor_pin_B[] = {1,2,3,4,5,6}; 
const float I_MAX = 1000.0; // ขีดจำกัดบนของ integral
const float I_MIN = -1000.0; // ขีดจำกัดล่างของ integral

//-------------------------------------------------------->>fline
int rgb[] = {24, 25, 28};
bool pid_error = true;

//___--------------------------------------------->>

String husky_color = "none";
String tcs_color = "none";
void get_color_husky(void);

void setup() {
  Wire.begin();
  Serial.begin(115200);
  my_GYRO::begin();
  my_GYRO::resetAngles();
  setup_husky();
  setup_tcs();
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(32, OUTPUT);

  pinMode(33, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  for(int i = 0; i<2; i++)
    {
      for(int i = 0; i<3; i++)
        {
          digitalWrite(rgb[i],1);
          delay(150);
          digitalWrite(rgb[i],0);
          delay(150);
        }
    }
  digitalWrite(rgb[2],1);

  
   arm_ch_collor();
 // arm_down_open();
   get_EEP_Program();
   read_sensorA_program();
   sw(); 
   
 /*
   storeColors(); // เรียกฟังก์ชันเก็บค่าสี กดปุ่ม GP33 ครั้งแรก สีแดง  ครั้งที่ 2 สีเขียว ครั้งที่ น้ำเงิน สีเหลือง และครั้งที่ 3 สีเหลือง
   while(digitalRead(33) == 1)
    {
      searchColor();Serial.print("  ");delay(10);
    }
    tone(32, 950, 400);
    delay(500);
*/
  
  ///-------------------------------------------------------------------->>>>

  
   
   arm_ch_collor();
   fline(10, 10, 0.35, 10, 'n', 's', 50, "a1", 20);  //
   get_color_husky(); delay(500);
   arm_ready_min();delay(500);
   fline(10, 10, 0.35, 10, 'n', 's', 50, "a1", 20); 
   arm_down_close();delay(500);
   bline(20, 20, 0.35, 10, 'n', 'l', 40, "a3", 40);  //
   fline(40, 40, 0.45, 0, 'f', 's', 50, "a1", 20);  // 
   place_left_in(30, 20, 20) ;
   tcs_vs_husky();delay(200);
   place_left_out(30, 20, 20) ;

   bline(20, 20, 0.35, 10, 'n', 'l', 40, "a3", 40);  //
   fline(40, 40, 0.45, 0, 'f', 's', 50, "a1", 20);  // 
   place_left_in(30, 20, 20) ;
   tcs_vs_husky();delay(200);
   place_left_out(30, 20, 20) ;


    bline(40, 40, 0.35, 30, 'n', 's', 40, "a3", 40);  //
    place_right_out(30, 90, 20) ;
   fline(40, 40, 0.45, 0, 'c', 'r', 50, "a4", 20);  // 
   fline(40, 40, 0.45, 0, 'f', 's', 50, "a1", 20);  // 
   place_left_in(30, 20, 20) ;
   
   tcs_vs_husky();delay(200);
   place_left_out(30, 20, 20) ;

   
  
  


  
  ///-------------------------------------------------------------------->>>>
  ///-------------------------------------------------------------------->>>>
  


}

void loop() {
  //get_color_husky();
  //loop_husky();
  //searchColor();Serial.print("  ");


  //Serial.print(my_tcs('r')); Serial.print("  "); Serial.print(my_tcs('g')); Serial.print("  "); Serial.println(my_tcs('b'));
  //get_color_husky();
   //Serial.print( analogRead(46) );   Serial.print( "   " );   Serial.println( analogRead(47) ); 
    //Serial.print( "   " );
  //Serial.print( md_sensorC(0) );   Serial.print( "   " );   Serial.println( md_sensorC(1) );  
  //Serial.print(digitalRead(19));Serial.println("  ");
  //Serial.print( position_B()); Serial.print("  ");  Serial.println(error_B());
  //Serial.println(my.gyro('z'));   
  delay(10);

}

