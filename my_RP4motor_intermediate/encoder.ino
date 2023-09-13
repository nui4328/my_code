

// ฟังก์ชั่นการโทรกลับเมื่อมีการเปลี่ยนแปลงค่าในพิน A


void setup_encoder() {
    pinMode(pin_RA, INPUT_PULLUP);
    pinMode(pin_RB, INPUT_PULLUP);
    pinMode(pin_LA, INPUT_PULLUP);
    pinMode(pin_LB, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(pin_RA), encoderCallback_R, CHANGE);
    prevAVal_R = digitalRead(pin_RA);  
    attachInterrupt(digitalPinToInterrupt(pin_LA), encoderCallback_L, CHANGE);
    prevAVal_L = digitalRead(pin_LA);  
}
void encoderCallback_R() {
    int aVal = digitalRead(pin_RA);
    if (aVal != prevAVal_R) {
        if (digitalRead(pin_RB) != aVal) {
            encoderDir_R = -1;
        } else {
            encoderDir_R = 1;
        }
        encoderPos_R += encoderDir_R;
    }
    prevAVal_R = aVal;
}

void encoderCallback_L() {
    int aVal = digitalRead(pin_LA);
    if (aVal != prevAVal_L) {
        if (digitalRead(pin_LB) != aVal) {
            encoderDir_L = -1;
        } else {
            encoderDir_L = 1;
        }
        encoderPos_L += encoderDir_L;
    }
    prevAVal_L = aVal;
}
void loop_encoder() {
    Serial.print("Encoder position: ");
    Serial.println(encoderPos_R);
    delay(100);
}

void fw_encoder(int spl, int spr, volatile int pw, String line, char slr)
  {    

    int en_cal = map(spl, 0, 100, 500, 1000);
    encoderPos_R=0;
    while(encoderPos_R < pw*en_cal)      
        {
          Motor(spl, spr, spl, spr); 
          if(mcp_f(0)<md_sensors(0)-150)
              {
                while(1)
                  {
                    Motor(30, 30, 30, 30);
                    if(mcp_f(1)<md_sensors(1)+150) //------------->> มีเส้นข้างหน้า
                      {
                        Motor(-50, -50, -50, -50);delay(70);
                        Motor(0, 0, 0, 0);delay(50);
                        Motor(-40, -40, -40, -40);delay(150);
                        set_bl_box();
                        goto end_set_bl;
                      }
                    if(mcp_f(2)<md_sensors(2)) //------------->> มีเส้นด้านข้าง
                      {
                        //do{Motor(spl+20, -15, spl+20, -15);}while(mcp_f(0)>md_sensors(0));
                        do{Motor(spl+20, -15, spl+20, -15);}while(mcp_f(0)<md_sensors(0));
                        delay(20);
                        break;
                      }
                  }
              }
            else if(mcp_f(1)<md_sensors(1)-150)
              {
                while(1)
                  {
                    Motor(30, 30, 30, 30);
                    if(mcp_f(0)<md_sensors(0)+150) //------------->> มีเส้นข้างหน้า
                      {
                        Motor(-50, -50, -50, -50);delay(70);
                        Motor(0, 0, 0, 0);delay(50);
                        Motor(-40, -40, -40, -40);delay(150);
                        set_bl_box();
                        goto end_set_bl;
                      }
                    if(mcp_f(3)<md_sensors(3)) //------------->> มีเส้นด้านข้าง
                      {
                        //do{Motor(-15, spr+20, -15, spr+20);}while(mcp_f(1)>md_sensors(1));
                        do{Motor(-15, spr+20, -15, spr+20);}while(mcp_f(1)<md_sensors(1));
                        delay(20);
                        break;
                      }
                  }
              }         
        }
    if(pw == 0)
      {
        Motor(-spl, -spr, -spl, -spr);delay(10);
        Motor(0,0, 0,0);delay(250);
      }
    else
      {
        Motor(-spl, -spr, -spl, -spr);delay(50);
        Motor(0,0, 0,0);delay(150);
      }
    
    if(line == "line")
      {
         set_bl_fw(1);
         Motor(0,0, 0,0);delay(150);
      } 
    
    end_set_bl:  
    
    if(slr == 'r')
      {
        encoderPos_L=0;
        encoderPos_R=0;
        while(1)      
            {
              if(encoderPos_L > 340 && encoderPos_R < -340)
                {
                  break;
                }
              Motor(60, -60, 60, -60);          
            }
        Motor(-60, 60, -60, 60);delay(60);
        Motor(0,0, 0,0);delay(150);
      }
    else if(slr == 'l')
      {
        encoderPos_L=0;
        encoderPos_R=0;
        while(1)      
            {
              if(encoderPos_L < -340 && encoderPos_R > 340)
                {
                  break;
                }
              Motor(-60, 60, -60, 60);
            }
        Motor(60, -60, 60, -60);delay(60);
        Motor(0,0, 0,0);delay(150);
      }
    else
      {
        Motor(0,0, 0,0);delay(10);
      }
    Motor(0,0, 0,0);delay(100);
  }

void fw_encoder(int spl, int spr, volatile int pw)
  {    
    encoderPos_R=0;
    while(encoderPos_R < pw)      
        {
          Motor(spl, spr, spl, spr);           
        } 
    Motor(0,0, 0,0);delay(10);   
  }

void bw_encoder(int spl, int spr, volatile int pw, String line, char slr)
  {    

    int en_cal = map(spl, 0, 100, 500, 900);
    encoderPos_R=0;
    while(encoderPos_R > -(pw*en_cal))      
        {
          Motor(-spl, -spr, -spl, -spr); 
          if(mcp_f(4)<md_sensors(4))
              {
                while(1)
                  {
                    Motor(-30, -30, -30, -30);
                    if(mcp_f(5)<md_sensors(5)) //------------->> มีเส้นข้างหน้า
                      {
                        Motor(spl, spr, spl, spr);delay(50);
                        Motor(0, 0, 0, 0);delay(100);
                        Motor(40, 40, 40, 40);  delay(110);
                        Motor(0, 0, 0, 0);delay(100);
                        set_bl_bw(1);
                        goto end_set_bl;
                      }
                    if(mcp_f(2)<md_sensors(2)) //------------->> มีเส้นด้านข้าง
                      {
                        do{Motor(-(spl+20), 15, -(spl+20), 15);}while(mcp_f(4)>md_sensors(4));
                        do{Motor(-(spl+20), 15, -(spl+20), 15);}while(mcp_f(4)<md_sensors(4));
                        delay(20);
                        break;
                      }
                  }
              }
          else if(mcp_f(5)<md_sensors(5))
              {
                while(1)
                  {
                    Motor(-30, -30, -30, -30);
                    if(mcp_f(4)<md_sensors(4)) //------------->> มีเส้นข้างหน้า
                      {
                        Motor(40, 40, 40, 40);delay(50);
                        Motor(0, 0, 0, 0);delay(100);
                        Motor(40, 40, 40, 40);delay(110);
                        Motor(0, 0, 0, 0);delay(100);
                        set_bl_bw(1);
                        goto end_set_bl;
                      }
                    if(mcp_f(3)<md_sensors(3)) //------------->> มีเส้นด้านข้าง
                      {
                        do{Motor(15, -(spr+20), 15, -(spr+20));}while(mcp_f(5)>md_sensors(5));
                        do{Motor(15, -(spr+20), 15, -(spr+20));}while(mcp_f(5)<md_sensors(5));
                        delay(20);
                        break;
                      }
                  }
              }         
        }
    Motor(spl, spr, spl, spr);delay(100);
    Motor(0,0, 0,0);delay(150);
    end_set_bl: 
    if(line == "line")
      {
         set_bl_bw(1);
         Motor(0,0, 0,0);delay(150);
      }
    
    
    
    
    if(slr == 'r')
      {
        encoderPos_L=0;
        encoderPos_R=0;
        while(1)      
            {
              if(encoderPos_L > 340 && encoderPos_R < -340)
                {
                  break;
                }
              Motor(60, -60, 60, -60);          
            }
        Motor(-60, 60, -60, 60);delay(60);
        Motor(0,0, 0,0);delay(150);
      }
    else if(slr == 'l')
      {
        encoderPos_L=0;
        encoderPos_R=0;
        while(1)      
            {
              if(encoderPos_L < -340 && encoderPos_R > 340)
                {
                  break;
                }
              Motor(-60, 60, -60, 60);
            }
        Motor(60, -60, 60, -60);delay(60);
        Motor(0,0, 0,0);delay(150);
      }
    else
      {
        Motor(0,0, 0,0);delay(10);
      }
    Motor(0,0, 0,0);delay(10);
  }

void bw_encoder(int spl, int spr, volatile int pw)
  {    

    encoderPos_R=0;
    while(encoderPos_R > -pw)      
        {
          Motor(-spl, -spr, -spl, -spr);           
        } 
    Motor(0,0, 0,0);delay(10);   
  }

  
void set_bl_fw(int num)
  {
    for(int i=0; i< num; i++)
      {
        while(1)
          {         
             if(mcp_f(0)<md_sensors(0)+150 && mcp_f(1)>md_sensors(1))
                {
                  while(mcp_f(1)>md_sensors(1))
                    {
                      Motor(0,45,0,45);
                    }
                    
                  Motor(0,-25,0,-25);delay(40);
                  Motor(0,0, 0,0);delay(20);
                  break;
                    
               }
            else if(mcp_f(1)<md_sensors(1)+150&& mcp_f(0)>md_sensors(0))
               {
                  while(mcp_f(0)>md_sensors(0))
                      {
                        Motor(45,0,45,0);
                      }
                  Motor(-25,0,-25,0);delay(40);
                  Motor(0,0, 0,0);delay(20);
                  break;                    
              }
            else if(mcp_f(1)<md_sensors(1)+150 && mcp_f(0)< md_sensors(0)+150)
               {
                  Motor(-25,-25,-25,-25);delay(40);
                  Motor(0,0, 0,0);delay(20);
                  break;                    
              }
            else
              {
                Motor(25,25, 25,25);
              }
          }
      
       Motor(-40, -40, -40, -40);delay(100);  
       Motor(0,0,0,0);delay(100); 
      }
    encoderPos_R=0;
    while(encoderPos_R > -70)      
      {
        Motor(-30, -30, -30, -30);           
      }
    //Motor(30,30,30,30);delay(20);
    Motor(0,0,0,0);delay(100);
  }
void set_bl_bw(int num)
  {
    for(int i=0; i< num; i++)
      {
        while(1)
          {
             if(mcp_f(4)<md_sensors(4)&& mcp_f(5)>md_sensors(5))
                {                    
                   while(mcp_f(5)>md_sensors(5))
                      {
                        Motor(0,-45,0,-45);
                      }
                   
                    Motor(0,25, 0,25);delay(20);
                    Motor(0,0,0,0);delay(20);
                    break;
                    
                }
             else if(mcp_f(5)<md_sensors(5)&& mcp_f(4)>md_sensors(4))
               {
                     while(mcp_f(4)>md_sensors(4))
                      {
                        Motor(-45,0,-45,0);
                      }
                  
                    Motor(25,0, 25,0);delay(20);
                    Motor(0,0,0,0);delay(20);
                    break;  
              }
            else if(mcp_f(5)<md_sensors(5)&& mcp_f(4)<md_sensors(4))
               {
   
                    Motor(35,35, 35,35);delay(20);
                    Motor(0,0,0,0);delay(20);
                    break;  
              }
            else
              {
                Motor(-25,-25, -25,-25);
              }
          }

         Motor(40, 40, 40, 40); delay(100);
         //Motor(0, 0, 0, 0); delay(100);               
       }
     encoderPos_R=0;
     while(encoderPos_R < 80)      
        {
          Motor(40, 40, 40, 40);           
        }
      //Motor(-30,-30,-30,-30);delay(10);
      Motor(0,0,0,0);delay(100);
  }

void set_bl_box()
  {
 
       while(1)
          {         
             if(mcp_f(0)<md_sensors(0)+150 && mcp_f(1)>md_sensors(1))
                {
                  while(mcp_f(1)>md_sensors(1))
                    {
                      Motor(0,45,0,45);
                    }
                    
                  Motor(0,-25,0,-25);delay(40);
                  Motor(0,0, 0,0);delay(100);
                  break;
                    
               }
            else if(mcp_f(1)<md_sensors(1)+150&& mcp_f(0)>md_sensors(0))
               {
                  while(mcp_f(0)>md_sensors(0))
                      {
                        Motor(45,0,45,0);
                      }
                  Motor(-25,0,-25,0);delay(40);
                  Motor(0,0, 0,0);delay(100);
                  break;                    
              }
            else if(mcp_f(1)<md_sensors(1)&& mcp_f(0)<md_sensors(0))
               {
 
                  Motor(-25,-25,-25,-25);delay(20);
                  Motor(0,0, 0,0);delay(100);
                  break;                    
              }
        
            else
              {
                Motor(25,25, 25,25);
              }
          }
         
         Motor(0,0,0,0);delay(100);

  }
