void set_bl(int num)
  {
    Motor(0,0,0,0);delay(50);
    encoderPoss=0;
    do{Motor(-55,-55,-55,-55);}while(encoderPoss > -90);
    for(int i=0; i< num; i++)
      {      
        
        while(1)
          {
            if(mcp_f(0)<sensor_maxs[0]-200 && mcp_f(1)>sensor_maxs[1]-200)
              {
                do{Motor(-30,50,-30,50);}while(mcp_f(1)>sensor_maxs[1]-200);
                Motor(20,-45,20,-45);delay(50);
                break;
              }
            else if(mcp_f(0)> sensor_maxs[0]-200 && mcp_f(1)<sensor_maxs[1]-200)
              {
                do{Motor(50,-30,50,-30);}while(mcp_f(0)>sensor_maxs[0]-200);
                Motor(-45,20,-45,20);delay(50);
                break;
              }
            else if(mcp_f(0)< sensor_maxs[0]-200 && mcp_f(1)<sensor_maxs[1]-150)
              {
                Motor(0,0,0,0);delay(150);
                break;
              }
            else
              {
                Motor(45,45,45,45);
              }
          }
        Motor(0,0,0,0);delay(50);
        encoderPoss=0;
        do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
        Motor(0,0,0,0);delay(250);
        while(1)
          {
            if(mcp_f(0)<sensor_maxs[0]-200 && mcp_f(1)>sensor_maxs[1]-200)
              {
                do{Motor(-30,45,-30,45);}while(mcp_f(1)>sensor_maxs[1]-200);
                Motor(20,-45,20,-45);delay(50);
                break;
              }
            else if(mcp_f(0)> sensor_maxs[0]-200 && mcp_f(1)<sensor_maxs[1]-200)
              {
                do{Motor(50,-30,50,-30);}while(mcp_f(0)>sensor_maxs[0]-200);
                Motor(-45,20,-45,20);delay(50);
                break;
              }
            else if(mcp_f(0)< sensor_maxs[0]-200 && mcp_f(1)<sensor_maxs[1]-150)
              {
                Motor(0,0,0,0);delay(150);
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
void set_bl_yello(int num)
  {
    for(int i=0; i<5; i++)
      {
        sensor_maxs[i] = mcp_f(i);
        delay(10);
      }
    encoderPoss=0;
    while(mcp_f(0)>sensor_maxs[0]-200)
      {
        Motor(40,40,40,40);
        if(encoderPoss > 150)
          {              
            Motor(0,0,0,0);delay(50);   
            check_color_roll_bz(); 
            if(color_ch == "none")
              {                
                none_yello = 1;  //------------->>> ตัวแปร ไม่ใช่เหลือง
                break;                
              }
            else{break;}
          }
      }
    if(none_yello == 1)
      {
        goto en_ch_yelo;
      }
    Motor(0,0,0,0);delay(100);
    encoderPoss=0;
    do{Motor(-50,-50,-50,-50);}while(encoderPoss > -50);
    Motor(0,0,0,0);delay(50);
    for(int i=0; i< num; i++)
      {          
        while(1)
          {
            if(mcp_f(0)<sensor_maxs[0]-150 && mcp_f(1)>sensor_maxs[1]-150)
              {
                do{Motor(-20, 45,-20, 45);}while(mcp_f(1)>sensor_maxs[1]-150);
                
                break;
              }
            else if(mcp_f(0)> sensor_maxs[0]-150 && mcp_f(1)<sensor_maxs[1]-150)
              {
                do{Motor(45,-20,45,-20);}while(mcp_f(0)>sensor_maxs[0]-150);
                
                break;
              }
            else if(mcp_f(0)< sensor_maxs[0]-150 && mcp_f(1)<sensor_maxs[1]-150)
              {
                
                break;
              }
            else
              {
                Motor(40,40,40,40);
              }
          }
        Motor(0,0,0,0);delay(50);
        encoderPoss=0;
        do{Motor(-50,-50,-50,-50);}while(encoderPoss > -70);
        Motor(0,0,0,0);delay(50);
        
      }
    while(1)
          {
            if(mcp_f(0)<sensor_maxs[0]-150 && mcp_f(1)>sensor_maxs[1]-150)
              {
                do{Motor(-20,45,-20,45);}while(mcp_f(1)>sensor_maxs[1]-150);
                
                break;
              }
            else if(mcp_f(0)> sensor_maxs[0]-150 && mcp_f(1)<sensor_maxs[1]-150)
              {
                do{Motor(45,-20,45,-20);}while(mcp_f(0)>sensor_maxs[0]-150);
                
                break;
              }
            else if(mcp_f(0)< sensor_maxs[0]-150 && mcp_f(1)<sensor_maxs[1]-150)
              {
                
                break;
              }
            else
              {
                Motor(40,40,40,40);
              }
          }
         en_ch_yelo: delay(10);
         Motor(0,0,0,0);delay(200);
  }
void set_cop()
  {
    while(1)
          {
            if(mcp_f(0)<md_sensors(0) && mcp_f(1)>md_sensors(1))
              {
                do{Motor(-20,50,-20,50);}while(mcp_f(1)>md_sensors(1));
                Motor(0,0,0,0);delay(200);
                break;
              }
            else if(mcp_f(0)> md_sensors(0) && mcp_f(1)<md_sensors(1))
              {
                do{Motor(50,-20,50,-20);}while(mcp_f(0)>md_sensors(0));
                Motor(0,0,0,0);delay(200);
                break;
              }
            else if(mcp_f(0)< md_sensors(0) && mcp_f(1)<md_sensors(1))
              {
                break;
              }
            else
              {
                Motor(40,40,40,40);
              }
          }
         Motor(0,0,0,0);delay(300);
     
  }
void bw(int sp, volatile int tm)
  {
    calibration_Yak();
    encoderPoss=0;
    while(encoderPoss > -tm)     
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
          PID_output = (6 * P) + (0.00015 * I) +(8* D); 
          
          Motor(-(sp + PID_output), -(sp - PID_output), -(sp + PID_output), -(sp - PID_output));
                 
       }
     //Motor(-sp,-sp,-sp,-sp);delay(70);
     Motor(0,0,0,0);delay(300);
     for(int i=0; i<5; i++)
      {
        sensor_maxs[i] = mcp_f(i);
        delay(10);
      }
  }

void slide_l_online()
  {
    for(int i=0; i<5; i++)
      {
        sensor_maxs[i] = mcp_f(i);
        delay(10);
      }
    encoderPoss=0;
    while(encoderPoss < 235)         
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
          PID_output = (6 * P) + (0.00015 * I) +(10* D); 
          
          Motor(-(52 + PID_output), 52+PID_output, 52 - PID_output, -(52 - PID_output));  //------> สไลซ้ายเข้าหาเส้น
          if(mcp_f(0)<sensor_maxs[0]-150 || mcp_f(2)<sensor_maxs[2]-150)
            {
              Motor(40,-40,-40,40);delay(40);
              Motor(0,0,0,0);delay(50);
              if(mcp_f(2)<md_sensors(2))
                {
                  ch_line_r = 1;
                  Motor(60,-60,-60,60);delay(70);
                  Motor(0,0,0,0);delay(200);
    
                  encoderPoss=0;
                  while(encoderPoss > -140)   //-------------------->>  สไลขวาออกมา     
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
                       PID_output = (7 * P) + (0.00015 * I) +(15* D); 
                            
                       Motor(52-PID_output, -(52 - PID_output),-(52 + PID_output), 52 + PID_output);
                           
                     }
                  Motor(-61,61,61,-61);delay(30);
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
        encoderPoss=0;
        while(encoderPoss > -195)        
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
             PID_output = (7 * P) + (0.00015 * I) +(15* D); 
                  
             Motor(61-PID_output, -(61 - PID_output),-(61 + PID_output), 61 + PID_output);
                 
           }
         Motor(-61,61,61,-61);delay(30);
         Motor(0,0,0,0);delay(300);

         //-------------------------------------------->>> หมุน 90 องศา
         calibration_Yak(); 
         do{Motor(-61,61,-61,61);}while(error_Yaw_float()> -85);
         Motor(61,-61,61,-61);delay(70);
         Motor(0,0,0,0);delay(300);
         for(int i=0; i<5; i++)
            {
              sensor_maxs[i] = mcp_f(i);
              delay(10);
            }
      }
    else
      {
         //-------------------------------------------->>> หมุน 180 องศา
         calibration_Yak(); 
         do{Motor(61,-61,61,-61);}while(error_Yaw_float()<173);
         Motor(-61,61,-61,61);delay(61);
         Motor(0,0,0,0);delay(300);
         for(int i=0; i<5; i++)
          {
            sensor_maxs[i] = mcp_f(i);
            delay(10);
          }
      }
  }

void slide_r()
  {
    Motor(0,0,0,0);delay(200);
    calibration_Yak();
    encoderPoss=0;
    while(1)           
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
          if(mcp_f(4)<md_sensors(4) || mcp_f(3)<md_sensors(3)) //----------------->> ถ้ามีเส้นดำด้านข้าง
            {
              Motor(-80,80,80,-80);delay(60);
              Motor(0,0,0,0);delay(100);
              
              encoderPoss=0;
              while(encoderPoss < 120)      //----------------->> สไลออกมา 
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
  }
