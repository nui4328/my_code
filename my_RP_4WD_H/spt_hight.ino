void fw_ch_r(int sp, volatile int encoderPoss_fw)
  {
     volatile int encoderPos_last = 0;
     volatile int encoderPos_fw = 0;
     if(bg_st == 1)
      {
        goto bridge_ch; 
      }
    //-------------->>
    //------------------>> เดินหน้าที่ละแผ่น
    for(int i=0; i<5; i++)
      {
        sensor_maxs[i] = mcp_f(i);
        delay(10);
      }
    color_ch="none";
    encoderPoss = 0;
    while(encoderPoss < encoderPoss_fw)      
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
          PID_output = (6 * P) + (0.00015 * I) +(8* D); 
          
          Motor(sp - PID_output, sp + PID_output, sp - PID_output, sp + PID_output); 

          //---------------------------------->> ตรวจสอบลิมิทสวิต ด้านหน้า
          if(digitalRead(26)==0)
            {
              Motor(0,0,0,0);delay(10);
               encoderPoss=0; 
               while(encoderPoss < 350)
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
                    PID_output = (8 * P) + (0.00015 * I) +(15* D); 
                    
                    Motor(70 - PID_output, 70 + PID_output, 70 - PID_output, 70 + PID_output); 
                    if(digitalRead(27)==0)
                      {
                        chopsticks = 1;    //-------> chopsticks = 1 คือ ตะเกียบ
                      }
                  }
               Motor(0,0,0,0);delay(100);
               encoderPoss=0;               
               
               bridge(60, time_bridge);  ///---------------------->>  ขึ้นสะพานและตะเกียบ   1000 คือค่าที่วิ่งขึ้นไปกลางสะพาน หรือผ่านตะเกียบ
               
               goto bridge_ch;             
            }   
          if(mcp_f(0) < md_sensors(0)||mcp_f(1) < md_sensors(1))  //------->> ตวจสอบเส้นด้านหน้า
            {              
               color_ch="none";
               encoderPos_last = encoderPoss ;  
               encoderPos_fw = encoderPoss_fw - encoderPos_last;
              
               if(mcp_f(0) > md_sensors(0)&& mcp_f(1) < md_sensors(1))
                  {                    
                    while(1)
                      {
                        Motor(40,40,40,40);
                        if( mcp_f(0) < md_sensors(0))
                          {
                             Motor(-100,-100,-100,-100);delay(100);
                             Motor(0,0,0,0);delay(300);
                            break;
                          }
                        if( mcp_f(4) < md_sensors(4))
                          {
                            Motor(-80,-80,-80,-80);delay(50);
                            Motor(0,0,0,0);delay(200);
                            Motor(-60,60,60,-60);delay(200);
                            Motor(0,0,0,0);delay(200);
                            encoderPoss=0; 
                            do{Motor(50,50,50,50);}while(encoderPoss < encoderPos_fw-50); //------->> 
                             Motor(0,0,0,0);delay(200);
                            goto en_r_line;
                          }
                      }
                  }
               else if(mcp_f(0) < md_sensors(0)&& mcp_f(1) > md_sensors(1))
                  {
                    while(1)
                      {
                        Motor(40,40,40,40);
                        if( mcp_f(1) < md_sensors(1))
                          {
                             Motor(-100,-100,-100,-100);delay(100);
                              Motor(0,0,0,0);delay(300);
                            break;
                          }
                        if( mcp_f(2) < md_sensors(2))
                          {
                            Motor(-80,-80,-80,-80);delay(50);
                            Motor(0,0,0,0);delay(200);
                            Motor(60,-60,-60,60);delay(200);
                            Motor(0,0,0,0);delay(200);
                            encoderPoss=0; 
                            do{Motor(50,50,50,50);}while(encoderPoss < encoderPos_fw-50);
                            Motor(0,0,0,0);delay(200);
                            goto en_r_line;
                          }
                      }
                  }
              
               set_bl(1);
               check_color_roll_bz();
               if(color_ch=="yello")  //------>> ตรวจสอบสีเหลือง
                  {
                     servo_yello(); 
                     yello_box =1;
                     encoderPoss=0; 
                     ch_line_r = 0;
                     calibration_Yak();
                     bw(61, 101);
                     slide_l_online();
                     color_ch="none";
                     goto end_line;
                  }
               else if(color_ch=="red"||color_ch=="green"||color_ch=="blue")  //------>> ตรวจสอบสี
                  {                            
                     
                     check_color_roll_bz();
                     if(color_ch=="red"||color_ch=="green"||color_ch=="blue")
                       {                   
                         check_color_roll_bz();
                         if(color_ch=="red")
                            {
                              red_box =1; 
                              servo_red(); 
                              
                            }
                         else if(color_ch=="green")
                            {
                              green_box =1; 
                              servo_green();                               
                            }
                         else if(color_ch=="blue")
                            {
                              blue_box =1;
                              servo_blue();                               
                            }
                         else if(color_ch=="yello")
                            {
                              yello_box =1;
                              servo_yello(); 
                              
                            }
                         mydisplay_background(black);
                         mydisplay(color_ch, 20, 10, 2, white); 
                         do{Motor(-40,-40,-40,-40);}while(mcp_f(1)<md_sensors(1));
                         slide_r();
                         set_bl(1);
                       }                    
                    
                     encoderPoss=0; 
                     ch_line_r = 0;
                     calibration_Yak();
                     bw(51, 351);
                     slide_l_online();
                     color_ch="none";
                     goto end_line; 
                  }
               else
                  {                      
                                         
                     bw(61, 100);
                     slide_l_online();
                     goto end_line;
                  }               
            }  
          
          if(color_ch=="yello")
            {
               Motor(0,0,0,0);delay(30);
               check_color_roll_bz();                   
               set_bl_yello(1);
               if(none_yello == 1)  //------------------->> เจอจุดเช็คพอยต์  
                  {
                    none_yello = 0;
                    goto bridge_ch;  
                  }
               encoderPoss=0; 
               calibration_Yak();                       
               encoderPoss=0; 
               bw(41, 250);
               yello_box =1;
               servo_yello();                        
               
                slide_r();
                encoderPoss=0;
                calibration_Yak();  
                bw(51, 351);
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
                              red_box =1; 
                              servo_red();                               
                            }
                         else if(color_ch=="green")
                            {
                              green_box =1;  
                              servo_green();                              
                            }
                         else if(color_ch=="blue")
                            {
                              blue_box =1; 
                              servo_blue();                              
                            }
                         else if(color_ch=="yello")
                            {
                              yello_box =1;
                              servo_yello();                               
                            }
                         mydisplay_background(black);
                         mydisplay(color_ch, 20, 10, 2, white); 
                         do{Motor(-40,-40,-40,-40);}while(mcp_f(1)<md_sensors(1));
                         slide_r();
                         set_bl(1);
                       }                    
                     
                     encoderPoss=0; 
                     ch_line_r = 0;
                     calibration_Yak();
                     bw(61, 101);
                     slide_l_online();
                     color_ch="none";
                     goto end_line; 
                  }
                
       }
   // Motor(-60,-60,-60,-60);delay(70);
    Motor(0,0,0,0);delay(300);

    bridge_ch:delay(10); //------------>> เมื่อมีการขึ้นสะพานมา
    
    bg_st = 0;
    for(int i=0; i<5; i++)
      {
        sensor_maxs[i] = mcp_f(i);
        delay(10);
      }
    //--------------------------------->> สไลข้างขวาพร้อมเช็ค เส้นดำ


    calibration_Yak();
    en_r_line: delay(10);
    begin_slide_R: delay(10);    //----------------->??
    encoderPoss=0;
    while(encoderPoss > -255)           
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
          PID_output = (4 * P) + (0.00015 * I) +(8* D); 
          
          Motor(52-PID_output, -(52 - PID_output),-(52 + PID_output), 52 + PID_output); 
         // Motor(61, -61,-61, 61); 
          if(mcp_f(1)<md_sensors(1) || mcp_f(3)<md_sensors(3)) //----------------->> ถ้ามีเส้นดำด้านข้าง
            {
              Motor(-80,80,80,-80);delay(70);
              if(mcp_f(1)<md_sensors(1)&& mcp_f(4)>md_sensors(4))
                {
                  encoderPoss=0;
                  while(mcp_f(4)> md_sensors(4))
                    {
                      Motor(60,40,-60,80);
                      if(encoderPoss < -55)
                        {
                          Motor(0,0,0,0);delay(300); 
                          do{Motor(-60,-40,60,-60);}while(encoderPoss <65);     
                          Motor(0,0,0,0);delay(300); 
                          Motor(-40,-40,-40,-40); delay(200); 
                          Motor(0,0,0,0);delay(300); 
                          goto begin_slide_R;        //-------------------->??
                                          
                        }
                    }
                  Motor(0,0,0,0);delay(300);
                }
              else if(mcp_f(3)<md_sensors(3)&& mcp_f(4)>md_sensors(4))
                {
                  do{Motor(60,-60,-80,-40);}while(mcp_f(4)>md_sensors(4));
                  Motor(0,0,0,0);delay(300);               
                }
              else
                {                   
                   //Motor(0,0,0,0);delay(200);
                }

               Motor(-60,60,60,-60);delay(100);
              Motor(0,0,0,0);delay(200);
              while(1)
                {
                  if(mcp_f(1)<md_sensors(1) || mcp_f(3)<md_sensors(3)) //----------------->> ถ้ามีเส้นดำด้านข้าง
                    {
                      Motor(0,0,0,0);delay(50);
                      if(mcp_f(1)<md_sensors(1)&& mcp_f(4)>md_sensors(4))
                        {
                          do{Motor(60,40,-60,80);}while(mcp_f(4)>md_sensors(4));
                          Motor(0,0,0,0);delay(300);
                          
                        }
                      else if(mcp_f(3)<md_sensors(3)&& mcp_f(4)>md_sensors(4))
                        {
                          do{Motor(60,-60,-80,-40);}while(mcp_f(4)>md_sensors(4));
                          Motor(0,0,0,0);delay(300);      
                                 
                        }
                      break;
                    }
                  else
                    {                   
                      Motor(40,-40,-40,40);
                    }
                }
              ch_line_r = 1;
              //Motor(-60,60,60,-60);delay(70);
              Motor(0,0,0,0);delay(300);
               
              encoderPoss=0;
              while(encoderPoss < dis_line_r)      //----------------->> สไลออกมา 
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
                  PID_output = (4 * P) + (0.00015 * I) +(10* D); 
                  
                  //Motor(-61, 61, 61, -61);
                  Motor(-(52 + PID_output), 52+PID_output, 52 - PID_output, -(52 - PID_output));
                 
               }
              Motor(61,-61,-61,61);delay(70);
              Motor(0,0,0,0);delay(300);
              break; 
            }          
       }
     if(ch_line_r == 0)  //------------------>>  ด้านข้างไม่มีเส้น
      {
        Motor(-60,60,60,-60);delay(70);
        Motor(0,0,0,0);delay(300);
        encoderPoss=0;
        while(encoderPoss < 250)          
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
             PID_output = (5 * P) + (0.00015 * I) +(10* D); 
                  
             Motor(-(52 + PID_output), 52+PID_output, 52 - PID_output, -(52 - PID_output));
             //Motor(-61, 61, 61, -61);    
           }
         Motor(61,-61,-61,61);delay(30);
         Motor(0,0,0,0);delay(400);

         //-------------------------------------------->>> หมุน 90 องศา
         calibration_Yak(); 
         do{Motor(61,-61,61,-61);}while(error_Yaw_float()< deg_90_R);
         Motor(-61,61,-61,61);delay(100);
         Motor(0,0,0,0);delay(200);
         for(int i=0; i<5; i++)
          {
            sensor_maxs[i] = mcp_f(i);
            delay(10);
          }
            
      } 

    end_line:delay(10);
    encoderPoss=0; 
    ch_line_r = 0;
    calibration_Yak();
    ch_bridge = 0;
    bg_st = 0;

    
  }
void fw_begin(int sp, volatile int encoderPoss_fw)
  {
    
    encoderPoss = 0;
    while(encoderPoss < encoderPoss_fw)      
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
          PID_output = (5 * P) + (0.00015 * I) +(8* D); 
          
          Motor(sp - PID_output, sp + PID_output, sp - PID_output, sp + PID_output); 
        }
      Motor(0,0,0,0);delay(200);
     for(int i=0; i<5; i++)
      {
        sensor_maxs[i] = mcp_f(i);
        delay(10);
      }
      
  }
