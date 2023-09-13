void bridge(int sp, volatile int encoderPos_R_fw)
  {
    while(encoderPos_R < encoderPos_R_fw)      
        {          
          //check_color_roll();
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
    Motor(-60,-60,-60,-60);delay(70);
    Motor(0,0,0,0);delay(300);

    if(chopsticks == 1)
       {
         goto end_bridge;
       }
    for(int i=0; i<4; i++)
      {
        sensor_maxs[i] = mcp_f(i);
        delay(10);
      }


    //--------------------------------->> สไลข้างขวาพร้อมเช็ค เส้นดำ
    encoderPos_R=0;
    while(encoderPos_R > -1000)        
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
          if(mcp_f(1)<sensor_maxs[1]-100 && mcp_f(3)<sensor_maxs[3]-100)
            {
              Motor(-40,40,40,-40);delay(40);
              Motor(0,0,0,0);delay(40);
       
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
              else
                {
                  break;          
                }
            }
       }
     if(ch_line_r == 0)  //------------------>>  ด้านข้างไม่มีเส้น
      {
        Motor(-60,60,60,-60);delay(70);
        Motor(0,0,0,0);delay(300);
        encoderPos_R=0;
        while(encoderPos_R < 380)        
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
         do{Motor(55,-55,55,-55);}while(error_Yaw_float()< 87);
         Motor(-55,55,-55,55);delay(100);
         Motor(0,0,0,0);delay(200);
         calibration_Yak(); 
         slide_r_blalan();   
      } 

    end_line:delay(10);
    re_bri: delay(10);
    encoderPos_R=0; 
    ch_line_r = 0;
    calibration_Yak();    
    while(digitalRead(27)==1)     //----->> เดินลงสะพาน 
        {          
          //check_color_roll();
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
          if(mcp_f(0) < md_sensors(0)-100||mcp_f(1) < md_sensors(1)-100)
            {              
               Motor(-70,-70,-70,-70);delay(80);
               Motor(0,0,0,0);delay(200);               
               set_bl(1);
               encoderPos_R=0; 
               ch_line_r = 0;
               calibration_Yak();
               
               bw(55, 170);
               calibration_Yak(); 
               do{Motor(-55,55,-55,55);}while(error_Yaw_float()> -87);
               Motor(55,-55,55,-55);delay(70);
               Motor(0,0,0,0);delay(300);
               calibration_Yak(); 
               goto re_bri;  //------------->> กลับขึ้นข้างบน ลงสะพานใหม่
            }  
         
       }
     
      encoderPos_R=0; 
      while(encoderPos_R < 600)     //----->> เดินลงสะพาน 
        {          
          //check_color_roll();
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
    Motor(-60,-60,-60,-60);delay(70);
    Motor(0,0,0,0);delay(300);
    end_bridge:delay(10);

    
  }


void slide_r_blalan()
  {
    encoderPos_R=0;
    while(encoderPos_R < 1005)        
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
          
          Motor(-(55 + PID_output), 55+PID_output, 55 - PID_output, -(55 - PID_output));
          if(mcp_f(0)<md_sensors(0) || mcp_f(2)<md_sensors(2))
            {
              Motor(70,-70,-70,70);delay(100);
              Motor(0,0,0,0);delay(100); 
              if(mcp_f(0)<md_sensors(0)&& mcp_f(2)>md_sensors(2))
                {
                  do{Motor(10,-10,70,-70);}while(mcp_f(2)>md_sensors(2));
                  Motor(0,0,-50,50);delay(50);
                  Motor(0,0,0,0);delay(200);
                  break; 
                }
              else if(mcp_f(2)<md_sensors(2)&& mcp_f(0)>md_sensors(0))
                {
                  do{Motor(-70,70,-10,10);}while(mcp_f(0)>md_sensors(0));
                  Motor(50,-50,0,0);delay(50);   
                  Motor(0,0,0,0);delay(200); 
                  break;              
                }
              else
                {                   
                   Motor(0,0,0,0);delay(200);
                   break; 
                }

             }
        }
     encoderPos_R=0;
        while(encoderPos_R > -270)        
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
                  
             Motor(50-PID_output, -(50 - PID_output),-(50 + PID_output), 50 + PID_output);
                 
           }
         Motor(-55,55,55,-55);delay(30);
         Motor(0,0,0,0);delay(300);
    
  }
