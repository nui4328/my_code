
#include <my2wd_encoder.h>


void setup()
  {    
     Serial.begin(9600);
     sensor_set();              // ค่าเริ่มต้น eeprom, bit_analogRead=>12  
     mydisplay_background(black);
     mydisplay("MY-MAKERS", 20, 30, 2, white);

     servo(28,60);
     servo(27,90);
     begin_robot();
     //test_bord();
  
//\\------------------------------------------->>>>>  เขียนโค๊ดที่นี้   

/*
   for(int i=0; i<5; i++)
    {
      fw (40, 40, 0.85, 50);
      bw (40, 40, 0.85, 50); 
    }
   
 */    
  
//\\------------------------------------------->>>>>   เขียนโค๊ดที่นี้ 
     
      
  }

void loop() 
  {  
     Serial.println(error_20());delay(10);

    
      

  }
