void fw_x_right(int dis, int spl, int spr,  int deg, int offset)
  {
    int en_coder = map(deg, 0, 90, 0, 290);
    set34();
    encoder.resetEncoders();
    while(encoder.Poss_R() < dis && encoder.Poss_L() < dis)
      {
        float error_L = map(mcp_f(3), min_mcp_f(3), max_mcp_f(3), 0, 30 );
        float error_R = map(mcp_f(4), min_mcp_f(4), max_mcp_f(4), 0, 30 );
        errors = error_L - error_R;     
        P = errors;
        I = I + errors;
        D = errors - previous_error;                    
        previous_error=errors  ;
        PID_output = (0.15 * P) + (0.00001 * I) + (0.15* D); 
          
        Motor(25 + PID_output, 25- PID_output);delayMicroseconds(50);
      }
    Motor(-20, -20); delay(20);
    Motor(-1, -1); delay(100);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(spl, spr); }while( encoder.Poss_L() < en_coder+20 );
    Motor(-spl, -spr); delay(offset);
    Motor(-1, -1); delay(40);    
  }
  
void fw_x_left(int dis, int spl, int spr,  int deg, int offset)
  {
    int en_coder = map(deg, 0, 90, 0, 270);
    set34();
    encoder.resetEncoders();
    while(encoder.Poss_R() < dis && encoder.Poss_L() < dis)
      {
        float error_L = map(mcp_f(3), min_mcp_f(3), max_mcp_f(3), 0, 30 );
        float error_R = map(mcp_f(4), min_mcp_f(4), max_mcp_f(4), 0, 30 );
        errors = error_L - error_R;     
        P = errors;
        I = I + errors;
        D = errors - previous_error;                    
        previous_error=errors  ;
        PID_output = (0.15 * P) + (0.00001 * I) + (0.15* D); 
          
        Motor(25 + PID_output, 25- PID_output);delayMicroseconds(50);
      }
    Motor(-20, -20); delay(20);
    Motor(-1, -1); delay(100);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(spl, spr); }while( encoder.Poss_R() < en_coder );
    Motor(-spl, -spr); delay(offset);
    Motor(-1, -1); delay(40);    
  }

void bw_x_right(int dis, int spl, int spr, int deg, int offset)
  {
    int en_coder = map(deg, 0, 90, 0, 280);
    set34();
    encoder.resetEncoders();
    while(encoder.Poss_R() > -dis && encoder.Poss_L() > -dis)
      {
        float error_L = map(mcp_b(3), min_mcp_b(3), max_mcp_b(3), 0, 30 );
        float error_R = map(mcp_b(4), min_mcp_b(4), max_mcp_b(4), 0, 30 );
        errors = error_L - error_R;     
        P = errors;
        I = I + errors;
        D = errors - previous_error;                    
        previous_error=errors  ;
        PID_output = (0.15 * P) + (0.00001 * I) + (0.15* D); 
          
        Motor(-(20 - PID_output), -(20 + PID_output));delayMicroseconds(50);
      }
    Motor(-20, -20); delay(30);
    Motor(-1, -1); delay(100);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(spl, spr); }while( encoder.Poss_L() < en_coder );
    Motor(-spl, -spr); delay(offset);
    Motor(-1, -1); delay(40);    
  }

void bw_x_left(int dis, int spl, int spr, int deg, int offset)
  {
    int en_coder = map(deg, 0, 90, 0, 280);
    set34();
    encoder.resetEncoders();
    while(encoder.Poss_R() > -dis && encoder.Poss_L() > -dis)
      {
        float error_L = map(mcp_b(3), min_mcp_b(3), max_mcp_b(3), 0, 30 );
        float error_R = map(mcp_b(4), min_mcp_b(4), max_mcp_b(4), 0, 30 );
        errors = error_L - error_R;     
        P = errors;
        I = I + errors;
        D = errors - previous_error;                    
        previous_error=errors  ;
        PID_output = (0.15 * P) + (0.00001 * I) + (0.15* D); 
          
        Motor(-(20 - PID_output), -(20 + PID_output));delayMicroseconds(50);
      }
    Motor(-20, -20); delay(30);
    Motor(-1, -1); delay(100);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(spl, spr); }while( encoder.Poss_R() < en_coder );
    Motor(-spl, -spr); delay(offset);
    Motor(-1, -1); delay(40);    
  }

void fw24_x_left(int dis, int spl, int spr,  int deg, int offset)
  {
    int en_coder = map(deg, 0, 90, 0, 270);
    set34();
    encoder.resetEncoders();
    while(encoder.Poss_R() < dis && encoder.Poss_L() < dis)
      {
        float error_L = map(mcp_f(2), min_mcp_f(2), max_mcp_f(2), 0, 30 );
        float error_R = map(mcp_f(4), min_mcp_f(4), max_mcp_f(4), 0, 30 );
        errors = error_L - error_R;     
        P = errors;
        I = I + errors;
        D = errors - previous_error;                    
        previous_error=errors  ;
        PID_output = (0.35 * P) + (0.00001 * I) + (0.15* D); 
          
        Motor(35 + PID_output, 35- PID_output);delayMicroseconds(50);
      }
    Motor(-40, -40); delay(20);
    Motor(-1, -1); delay(100);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(spl, spr); }while( encoder.Poss_R() < en_coder );
    Motor(-spl, -spr); delay(offset);
    Motor(-1, -1); delay(40);    
  }

void fw35_x_right(int dis, int spl, int spr,  int deg, int offset)
  {
    int en_coder = map(deg, 0, 90, 0, 290);
    set34();
    encoder.resetEncoders();
    while(encoder.Poss_R() < dis && encoder.Poss_L() < dis)
      {
        float error_L = map(mcp_f(3), min_mcp_f(3), max_mcp_f(3), 0, 30 );
        float error_R = map(mcp_f(5), min_mcp_f(5), max_mcp_f(5), 0, 30 );
        errors = error_L - error_R;     
        P = errors;
        I = I + errors;
        D = errors - previous_error;                    
        previous_error=errors  ;
        PID_output = (0.15 * P) + (0.00001 * I) + (0.15* D); 
          
        Motor(25 + PID_output, 25- PID_output);delayMicroseconds(50);
      }
    Motor(-20, -20); delay(20);
    Motor(-1, -1); delay(100);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(spl, spr); }while( encoder.Poss_L() < en_coder+20 );
    Motor(-spl, -spr); delay(offset);
    Motor(-1, -1); delay(40);    
  }

void fw_4sensor(int spl, int spr, float kp, int dis, String sensor, int offset)
  {
    if(dis > 0)
      {
        encoder.resetEncoders();
        while(encoder.Poss_R() < dis )
          {              
            P = error_4sensor();
            I = I + error_4sensor();
            D = error_4sensor() - previous_error;                    
            previous_error=error_4sensor() ;
            PID_output = (kp * P) + (0.00001 * I) + (0.15* D); 
              
            Motor(spl - PID_output, spr + PID_output);delayMicroseconds(50);             
          }
      }
    while(1)
      {          
        P = error_4sensor();
        I = I + error_4sensor();
        D = error_4sensor() - previous_error;                    
        previous_error=error_4sensor() ;
        PID_output = (kp * P) + (0.00001 * I) + (0.15* D); 
          
        Motor(spl - PID_output, spr + PID_output);delayMicroseconds(50); 
        if(sensor == "a7")
          {
            if(mcp_f(7) < md_mcp_f(7))
              {
                 break;           
              }
          }
        else if(sensor == "a0")
          {
            if(mcp_f(0) < md_mcp_f(0))
              {
                 break;           
              }
          }
        else if(sensor == "26")
          {
            if(analogRead(26) < md_adc(26))
              {
                 break;           
              }
          }
        else if(sensor == "27")
          {
            if(analogRead(27) < md_adc(27))
              {
                 break;           
              }
          }
        
      }
    if(offset > 0)
      {
        Motor(-spl, -spr); delay(offset);
        Motor(-1, -1); delay(40);
      }
     
  }
void set34()
  {
    if(mcp_f(3)> md_mcp_f(3) && mcp_f(4)> md_mcp_f(4) && mcp_f(2)< md_mcp_f(2) || mcp_f(1)< md_mcp_f(1)  )
       {
         do{Motor(-15, 20);}while(mcp_f(4)> md_mcp_f(4));
         Motor(-1, -1);  delay(50);
       }
     else if(mcp_f(3)> md_mcp_f(3) && mcp_f(4)> md_mcp_f(4) && mcp_f(5)< md_mcp_f(5) || mcp_f(6)< md_mcp_f(6)  )
       {
         do{Motor(20, -15);}while(mcp_f(3)> md_mcp_f(3));
         Motor(-1, -1); delay(50);
       }
     else{}
  }
void encoder_poss()
  {    
    Serial.print("Encoder_L: ");
    Serial.print(encoder.Poss_L());
    Serial.print("     ");
    Serial.print("Encoder_R: ");
    Serial.println(encoder.Poss_R());

    delay(100);  // Delay for better readability in serial out
  }
