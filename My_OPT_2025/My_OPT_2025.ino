#include <my2wd_encoder.h>
#include <my_gyro.h>
#include <my_TCS34725.h>
my_gyro my;

void setup() {
  Serial.begin(9600);
  pinMode(21, OUTPUT);
  my.begin();
  sw_st();
  rotate(55, 50, -90);
  Motor(-40, -40);
  delay(1000);
  rotate(75, 0, -90);
  sw_st();
  rotate(75, 0, -90);
  sw_st();
  rotate(75, 0, -90);
  sw_st();
  rotate(75, 0, -90);
  sw_st();
  rotate(75, 0, -90);
}

void loop() {
  

}
