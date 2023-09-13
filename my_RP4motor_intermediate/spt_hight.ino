void fw_ch_r(int sp, volatile int encoderPos_R_fw)
  {
    if(red_box == 1 && green_box == 1 && blue_box == 1 && yello_box == 1)
      {
        bz(300);bz(300);bz(300);
        servo(28, 20);
        goto end_line;        
      }
    while(encoderPos_R < encoderPos_R_fw)      
        {          
          check_color_roll();
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (5 * P) + (0.00015 * I) +(15* D); 
          
          Motor(sp - PID_output, sp + PID_output, sp - PID_output, sp + PID_output); 
          if(digitalRead(27)==0)
            {
               Motor(-60,-60,-60,-60);delay(70);
               Motor(0,0,0,0);delay(100);
               encoderPos_R=0; 
               while(encoderPos_R < 450)
                  { 
                    errors = error_Yaw_float();
                    I = 0;
                    previous_I = 0;
                    previous_error = 0;
                    P = errors;
                    I = I + previous_I;
                    D = errors - previous_error ;            
                    previous_I=I;
                    previous_error=errors  ;  
                    PID_output = (5 * P) + (0.00015 * I) +(15* D); 
                    
                    Motor(50 - PID_output, 50 + PID_output, 50 - PID_output, 50 + PID_output); 
                  }
               Motor(0,0,0,0);delay(200);
               encoderPos_R=0;
               while(encoderPos_R < 300)
                  { 
                    errors = error_Yaw_float();
                    I = 0;
                    previous_I = 0;
                    previous_error = 0;
                    P = errors;
                    I = I + previous_I;
                    D = errors - previous_error ;            
                    previous_I=I;
                    previous_error=errors  ;  
                    PID_output = (5 * P) + (0.00015 * I) +(15* D); 
                    
                    Motor(50 - PID_output, 50 + PID_output, 50 - PID_output, 50 + PID_output); 
                    if(digitalRead(27)==0)
                      {
                        chopsticks = 1;
                        bz(50);
                        break;
                      }
                  }
               Motor(0,0,0,0);delay(200);
               encoderPos_R=0; 
               ch_bridge = 1;
               bridge(60, 1000);  ///---------------------->>  ขึ้นสะพานและตะเกียบ
               goto bridge_ch;             
            }   
          if(mcp_f(0) < md_sensors(0)||mcp_f(1) < md_sensors(1))
            {              
               color_ch="none";
               Motor(-80,-80,-80,-80);delay(80);
               Motor(0,0,0,0);delay(200);
               check_color_roll_bz();
               if(color_ch=="yello")
                  {
                     servo_yello(); 
                     yello_box =1;
                     encoderPos_R=0; 
                     ch_line_r = 0;
                     calibration_Yak();
                     bw(55, 755);
                     slide_l_online();
                     color_ch="none";
                     goto end_line;
                  }
               else if(color_ch=="red"||color_ch=="green"||color_ch=="blue")
                  {                            
                     set_bl(1);
                     check_color_roll_bz();
                     if(color_ch=="red"||color_ch=="green"||color_ch=="blue")
                       {                   
                         check_color_roll_bz();
                         if(color_ch=="red")
                            {
                              servo_red(); 
                              red_box =1; 
                            }
                         else if(color_ch=="green")
                            {
                              servo_green();
                              green_box =1;  
                            }
                         else if(color_ch=="blue")
                            {
                              servo_blue();
                              blue_box =1; 
                            }
                         else if(color_ch=="yello")
                            {
                              servo_yello(); 
                              yello_box =1;
                            }
                         mydisplay_background(black);
                         mydisplay(color_ch, 20, 10, 2, white); 
                         do{Motor(-40,-40,-40,-40);}while(mcp_f(1)<md_sensors(1));
                         set_bl(1);
                       }                    
                    
                     encoderPos_R=0; 
                     ch_line_r = 0;
                     calibration_Yak();
                     bw(55, 755);
                     slide_l_online();
                     color_ch="none";
                     goto end_line; 
                  }
               else
                  {                      
                     set_cop();
                     if(digitalRead(27)==0)
                        {
                           chopsticks = 1;
                           encoderPos_R=0; 
                           while(encoderPos_R < 400)
                              {         
                                check_color_roll();
                                errors = error_Yaw_float();
                                I = 0;
                                previous_I = 0;
                                previous_error = 0;
                                P = errors;
                                I = I + previous_I;
                                D = errors - previous_error ;            
                                previous_I=I;
                                previous_error=errors  ;  
                                PID_output = (5 * P) + (0.00015 * I) +(15* D); 
                                
                                Motor(sp - PID_output, sp + PID_output, sp - PID_output, sp + PID_output); 
                              }
                           set_bl(1);
                           Motor(0,0,0,0);delay(200);
                           encoderPos_R=0; 
                           ch_bridge = 1;
                           bridge(60, 1800);  ///---------------------->>  ขึ้นสะพานและตะเกียบ
                           goto bridge_ch;             
                        } 
                     encoderPos_R=0; 
                     ch_line_r = 0;
                     calibration_Yak();
                     
                     bw(55, 150);
                     slide_l_online();
                     goto end_line;
                  }
               
            }  
          
          if(color_ch=="yello")
            {
               Motor(-40,-40,-40,-40);delay(40);
               Motor(0,0,0,0);delay(30);sw();
               check_color_roll_bz();
               do{Motor(40,40,40,40);}while(mcp_f(0)<md_sensors(0));
               set_bl(1);
               encoderPos_R=0; 
               calibration_Yak(); 
               bw(55, 150);
               check_color_roll_bz();sw();
               if(color_ch == "yello")
                  {
                    encoderPos_R=0; 
                    bw(55, 200);
                    servo_yello();
                    yello_box =1;
                  }
                encoderPos_R=0;
                calibration_Yak();  
                bw(55, 755);
                slide_l_online();
                color_ch="none";
                goto end_line;      
            }
         if(color_ch=="red"||color_ch=="green"||color_ch=="blue")
                  {                            
                     set_bl(1);
                     check_color_roll_bz();
                     if(color_ch=="red"||color_ch=="green"||color_ch=="blue")
                       {                   
                         check_color_roll_bz();
                         if(color_ch=="red")
                            {
                              servo_red(); 
                              red_box =1; 
                            }
                         else if(color_ch=="green")
                            {
                              servo_green();
                              green_box =1;  
                            }
                         else if(color_ch=="blue")
                            {
                              servo_blue();
                              blue_box =1; 
                            }
                         else if(color_ch=="yello")
                            {
                              servo_yello(); 
                              yello_box =1;
                            }
                         mydisplay_background(black);
                         mydisplay(color_ch, 20, 10, 2, white); 
                         do{Motor(-40,-40,-40,-40);}while(mcp_f(1)<md_sensors(1));
                         set_bl(1);
                       }                    
                    
                     encoderPos_R=0; 
                     ch_line_r = 0;
                     calibration_Yak();
                     bw(55, 755);
                     slide_l_online();
                     color_ch="none";
                     goto end_line; 
                  }
                
       }
    Motor(-60,-60,-60,-60);delay(70);
    Motor(0,0,0,0);delay(300);

    bridge_ch:delay(10); //------------>> เมื่อมีการขึ้นสะพานมา
    
    //--------------------------------->> สไลข้างขวาพร้อมเช็ค เส้นดำ
    encoderPos_R=0;
    while(encoderPos_R > -455)        
        {          
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (6 * P) + (0.00015 * I) +(15* D); 
          
          Motor(55-PID_output, -(55 - PID_output),-(55 + PID_output), 55 + PID_output); 
         // Motor(55, -55,-55, 55); 
          if(mcp_f(1)<md_sensors(1) || mcp_f(3)<md_sensors(3))
            {
              Motor(-70,70,70,-70);delay(70);
              if(mcp_f(1)<md_sensors(1)&& mcp_f(3)>md_sensors(3))
                {
                  do{Motor(-10,10,-70,70);}while(mcp_f(3)>md_sensors(3));
                  Motor(0,0,-60,60);delay(55);
                  Motor(0,0,0,0);delay(200);
                }
              else if(mcp_f(3)<md_sensors(3)&& mcp_f(1)>md_sensors(1))
                {
                  do{Motor(70,-70,10,-10);}while(mcp_f(1)>md_sensors(1));
                  Motor(-60,60,0,0);delay(55);   
                  Motor(0,0,0,0);delay(200);               
                }
              else
                {                   
                   //Motor(0,0,0,0);delay(200);
                }
              ch_line_r = 1;
              //Motor(-60,60,60,-60);delay(70);
              Motor(0,0,0,0);delay(300);
               
              encoderPos_R=0;
              while(encoderPos_R < dis_line_r)        
                {                  
                  errors = error_Yaw_float();
                  I = 0;
                  previous_I = 0;
                  previous_error = 0;
                  P = errors;
                  I = I + previous_I;
                  D = errors - previous_error ;            
                  previous_I=I;
                  previous_error=errors  ;  
                  PID_output = (5 * P) + (0.00015 * I) +(15* D); 
                  
                  //Motor(-55, 55, 55, -55);
                  Motor(-(55 + PID_output), 55+PID_output, 55 - PID_output, -(55 - PID_output));
                 
               }
              Motor(55,-55,-55,55);delay(70);
              Motor(0,0,0,0);delay(300);
              break;   
            }          
       }
     if(ch_line_r == 0)  //------------------>>  ด้านข้างไม่มีเส้น
      {
        Motor(-60,60,60,-60);delay(70);
        Motor(0,0,0,0);delay(300);
        encoderPos_R=0;
        while(encoderPos_R < 530)        
           {                  
             errors = error_Yaw_float();
             I = 0;
             previous_I = 0;
             previous_error = 0;
             P = errors;
             I = I + previous_I;
             D = errors - previous_error ;            
             previous_I=I;
             previous_error=errors  ;  
             PID_output = (5 * P) + (0.00015 * I) +(15* D); 
                  
             Motor(-(55 + PID_output), 55+PID_output, 55 - PID_output, -(55 - PID_output));
             //Motor(-55, 55, 55, -55);    
           }
         Motor(55,-55,-55,55);delay(30);
         Motor(0,0,0,0);delay(200);

         //-------------------------------------------->>> หมุน 90 องศา
         calibration_Yak(); 
         do{Motor(55,-55,55,-55);}while(error_Yaw_float()< 85);
         Motor(-55,55,-55,55);delay(100);
         Motor(0,0,0,0);delay(200);
            
      } 

    end_line:delay(10);
    encoderPos_R=0; 
    ch_line_r = 0;
    calibration_Yak();
    ch_bridge = 0;

    
  }

void set_bl(int num)
  {
    for(int i=0; i< num; i++)
      {      
        encoderPos_R=0;
        do{Motor(-55,-55,-55,-55);}while(encoderPos_R > -200);
        Motor(55,55,55,55);delay(55);
        while(1)
          {
            if(mcp_f(0)<md_sensors(0) && mcp_f(1)>md_sensors(1))
              {
                do{Motor(-55,70,-55,70);}while(mcp_f(1)>md_sensors(1));
                Motor(55,-70,55,-70);delay(55);
                break;
              }
            else if(mcp_f(0)> md_sensors(0) && mcp_f(1)<md_sensors(1))
              {
                do{Motor(70,-55,70,-55);}while(mcp_f(0)>md_sensors(0));
                Motor(-70,55,-70,55);delay(55);
                break;
              }
            else if(mcp_f(0)< md_sensors(0) && mcp_f(1)<md_sensors(1))
              {
                break;
              }
            else
              {
                Motor(45,45,45,45);
              }
          }
         Motor(0,0,0,0);delay(300);
      }
  }

void set_cop()
  {
    while(1)
          {
            if(mcp_f(0)<md_sensors(0) && mcp_f(1)>md_sensors(1))
              {
                do{Motor(-55,70,-55,70);}while(mcp_f(1)>md_sensors(1));
                Motor(55,-70,55,-70);delay(55);
                break;
              }
            else if(mcp_f(0)> md_sensors(0) && mcp_f(1)<md_sensors(1))
              {
                do{Motor(70,-55,70,-55);}while(mcp_f(0)>md_sensors(0));
                Motor(-70,55,-70,55);delay(55);
                break;
              }
            else if(mcp_f(0)< md_sensors(0) && mcp_f(1)<md_sensors(1))
              {
                break;
              }
            else
              {
                Motor(45,45,45,45);
              }
          }
         Motor(0,0,0,0);delay(300);
     
  }
void bw(int sp, volatile int tm)
  {
    encoderPos_R=0;
    while(encoderPos_R > -tm)     
        {
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (5 * P) + (0.00015 * I) +(15* D); 
          
          Motor(-(sp + PID_output), -(sp - PID_output), -(sp + PID_output), -(sp - PID_output));
                 
       }
     Motor(-sp,-sp,-sp,-sp);delay(70);
     Motor(0,0,0,0);delay(300);
  }

void slide_l_online()
  {
    for(int i=0; i<4; i++)
      {
        sensor_maxs[i] = mcp_f(i);
        delay(10);
      }
    encoderPos_R=0;
    while(encoderPos_R < 455)        
        {          
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (5 * P) + (0.00015 * I) +(15* D); 
          
          Motor(-(55 + PID_output), 55+PID_output, 55 - PID_output, -(55 - PID_output));
          if(mcp_f(0)<sensor_maxs[0]-100 && mcp_f(2)<sensor_maxs[2]-100)
            {
              Motor(40,-40,-40,40);delay(40);
              Motor(0,0,0,0);delay(50);
              if(mcp_f(2)<md_sensors(2))
                {
                  ch_line_r = 1;
                  Motor(60,-60,-60,60);delay(70);
                  Motor(0,0,0,0);delay(200);
    
                  encoderPos_R=0;
                  while(encoderPos_R > -dis_line_r)        
                    {                  
                      errors = error_Yaw_float();
                      I = 0;
                      previous_I = 0;
                      previous_error = 0;
                      P = errors;
                      I = I + previous_I;
                      D = errors - previous_error ;            
                      previous_I=I;
                      previous_error=errors  ;  
                      PID_output = (5 * P) + (0.00015 * I) +(15* D); 
                      Motor(55-PID_output, -(55 - PID_output),-(55 + PID_output), 55 + PID_output);
                     
                   }
                  Motor(-55,55,55,-55);delay(30);
                  Motor(0,0,0,0);delay(300);
                  break;  
                }
              else
                {
                  break;
                }
            }          
       }
     if(ch_line_r == 0)
      {
        Motor(60,-60,-60,60);delay(70);
        Motor(0,0,0,0);delay(300);
        encoderPos_R=0;
        while(encoderPos_R > -435)        
           {                  
             errors = error_Yaw_float();
             I = 0;
             previous_I = 0;
             previous_error = 0;
             P = errors;
             I = I + previous_I;
             D = errors - previous_error ;            
             previous_I=I;
             previous_error=errors  ;  
             PID_output = (5 * P) + (0.00015 * I) +(15* D); 
                  
             Motor(55-PID_output, -(55 - PID_output),-(55 + PID_output), 55 + PID_output);
                 
           }
         Motor(-55,55,55,-55);delay(30);
         Motor(0,0,0,0);delay(300);

         //-------------------------------------------->>> หมุน 90 องศา
         calibration_Yak(); 
         do{Motor(-55,55,-55,55);}while(error_Yaw_float()> -85);
         Motor(55,-55,55,-55);delay(70);
         Motor(0,0,0,0);delay(300);
      }
    else
      {
         //-------------------------------------------->>> หมุน 180 องศา
         calibration_Yak(); 
         do{Motor(55,-55,55,-55);}while(error_Yaw_float()<173);
         Motor(-55,55,-55,55);delay(55);
         Motor(0,0,0,0);delay(300);
      }
  }
