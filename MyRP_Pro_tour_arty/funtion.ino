void T_right(int sp, int deg)
  {
    int en_coder = map(deg, 0, 90, 0, 300);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(sp, -sp); }while( encoder.Poss_L() < en_coder );
    Motor(-sp, sp); delay(40);
    Motor(-1, 1); delay(40);
    if(mcp_f(3) > md_mcp_f(3) && mcp_f(2) < md_mcp_f(2))
      {
        do{Motor(-30, 30);}while(mcp_f(3) > md_mcp_f(3));
        Motor(30, -30); delay(20);
        Motor(0, 0); delay(20);
      }
    else if(mcp_f(4) > md_mcp_f(4) && mcp_f(5) < md_mcp_f(5))
      {
        do{Motor(30, -30);}while(mcp_f(4) > md_mcp_f(4));
        Motor(-30, 30); delay(20);
        Motor(0, 0); delay(20);
      }
  }

void T_left(int sp, int deg)
  {
    int en_coder = map(deg, 0, 90, 0, 300);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(-sp, sp); }while( encoder.Poss_L() < en_coder );
    Motor(sp, -sp); delay(40);
    Motor(1, -1); delay(40);
    if(mcp_f(3) > md_mcp_f(3) && mcp_f(2) < md_mcp_f(2))
      {
        do{Motor(-30, 30);}while(mcp_f(3) > md_mcp_f(3));
        Motor(30, -30); delay(40);
        Motor(0, 0); delay(20);
      }
    else if(mcp_f(4) > md_mcp_f(4) && mcp_f(5) < md_mcp_f(5))
      {
        do{Motor(30, -30);}while(mcp_f(4) > md_mcp_f(4));
        Motor(-30, 30); delay(40);
        Motor(0, 0); delay(20);
      }
  }

void T_right_sensor_F(int sp, int deg)
  {
    
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(sp, -sp); }while( encoder.Poss_L() < 180 );
    do{ Motor(sp, -sp); }while( mcp_f(deg) > min_mcp_f(deg)+70);
    Motor(-sp, sp); delay(30);
    Motor(-1, 1); delay(40);
    
  }

void T_right_sensor_B(int sp, int deg)
  {
    
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(sp, -sp); }while( encoder.Poss_L() < 180 );
    do{ Motor(sp, -sp); }while( mcp_b(deg) > min_mcp_b(deg)+70);
    Motor(-sp, sp); delay(30);
    Motor(-1, 1); delay(40);
    
  }

void T_left_sensor_F(int sp, int deg)
  {
    
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(-sp, sp); }while( encoder.Poss_L() > -180 );
    do{ Motor(-sp, sp); }while( mcp_f(deg) > min_mcp_f(deg)+70);
    Motor(sp, -sp); delay(30);
    Motor(-1, 1); delay(40);
    
  }

void T_left_sensor_B(int sp, int deg)
  {
    
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(-sp, sp); }while( encoder.Poss_L() > -180 );
    do{ Motor(-sp, sp); }while( mcp_b(deg) > min_mcp_b(deg)+100);
    Motor(sp, -sp); delay(50);
    Motor(-1, 1); delay(40);
    
  }
void move_F_center(int encoderss)
  {
    encoder.resetEncoders();
    while(encoder.Poss_L() < encoderss)
      {
            float error_L = map(mcp_f(3), min_mcp_f(3), max_mcp_f(3), 0, 20 );
            float error_R = map(mcp_f(4), min_mcp_f(4), max_mcp_f(4), 0, 20 );
            errors = error_L - error_R;     
            P = errors;
            I = I + errors;
            D = errors - previous_error;                    
            previous_error=errors  ;
            PID_output = (0.15 * P) + (0.00001 * I) + (0.15* D); 
            
            Motor(20 + PID_output, 20 - PID_output);delayMicroseconds(50);
      }
    Motor(-20, -20); delay(30);
    Motor(-1, 1); delay(100);
  }

void move_B_center()
  {
    encoder.resetEncoders();
    while(encoder.Poss_L() > -250)
      {
        Motor(-20, -20);  delayMicroseconds(50);  
      }
    Motor(20, 20); delay(30);
    Motor(-1, -1); delay(100);
  }
  
void bw67(int sl,int sr,float kp,int sensor, int ofset)
  {
    while(true)
      {
            float error_L = map(mcp_b(6), min_mcp_b(6), max_mcp_b(6), 0, 20 );
            float error_R = map(mcp_b(7), min_mcp_b(7), max_mcp_b(7), 0, 20 );
            errors = error_R - error_L;     
            P = errors;
            I = I + errors;
            D = errors - previous_error;                    
            previous_error=errors  ;
            PID_output = (kp * P) + (0.00001 * I) + (0.15* D); 
            
            Motor(-(sl + PID_output), -(sr - PID_output));delayMicroseconds(50);
            if(sensor == 4)
              {
                if(mcp_b(4) < md_mcp_b(4))
                  {
                    break;
                  }
              }
            if(sensor == 27)
              {
                if(analogRead(27) < md_adc(27) - 200)
                  {
                    break;
                  }
              }
            if(sensor == 3)
              {
                if(mcp_f(3) < md_mcp_f(3))
                  {
                    break;
                  }
              }
            
            
      }
    Motor(sl, sr); delay(ofset);
    Motor(1, 1); delay(10);
  }
void bw_encoder67(int sl,int sr, float kp,int enc, int ofset)
  {
    encoder.resetEncoders();
    while(true)
      {
            float error_L = map(mcp_b(6), min_mcp_b(6), max_mcp_b(6), 0, 20 );
            float error_R = map(mcp_b(7), min_mcp_b(7), max_mcp_b(7), 0, 20 );
            errors = error_R - error_L;     
            P = errors;
            I = I + errors;
            D = errors - previous_error;                    
            previous_error=errors  ;
            PID_output = (kp * P) + (0.00001 * I) + (0.15* D); 
            
            Motor(-(sl + PID_output), -(sr - PID_output));delayMicroseconds(50);

            if(encoder.Poss_L() < -enc)
              {
                break;
              }
      }
    Motor(sl, sr); delay(ofset);
    Motor(1, 1); delay(10);
  }
void fw_encoder67(int sl,int sr, float kp,int enc, int ofset)
  {
    encoder.resetEncoders();
    while(true)
      {
            float error_L = map(mcp_f(6), min_mcp_f(6), max_mcp_f(6), 0, 20 );
            float error_R = map(mcp_f(7), min_mcp_f(7), max_mcp_f(7), 0, 20 );
            errors = error_L - error_R;     
            P = errors;
            I = I + errors;
            D = errors - previous_error;                    
            previous_error=errors  ;
            PID_output = (kp * P) + (0.00001 * I) + (0.15* D); 
            
            Motor(sl + PID_output, sr - PID_output);delayMicroseconds(50);

            if(encoder.Poss_L() > enc)
              {
                break;
              }
      }
    Motor(-sl, -sr); delay(ofset);
    Motor(1, 1); delay(10);
  }
