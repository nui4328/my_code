void fw_x_right(int dis, int spl, int spr,  int deg, int offset)
  {
    int en_coder = map(deg, 0, 90, 0, 290);
    encoder.resetEncoders();
    while(encoder.Poss_R() < dis)
      {
        float error_L = map(mcp_b(3), min_mcp_b(3), max_mcp_b(3), 0, 30 );
        float error_R = map(mcp_b(4), min_mcp_b(4), max_mcp_b(4), 0, 30 );
        errors = error_L - error_R;     
        P = errors;
        I = I + errors;
        D = errors - previous_error;                    
        previous_error=errors  ;
        PID_output = (0.25 * P) + (0.00001 * I) + (0.15* D); 
          
        Motor(20 + PID_output, 20 - PID_output);delayMicroseconds(50);
      }
    Motor(-20, -20); delay(20);
    Motor(-1, 1); delay(100);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(spl, spr); }while( encoder.Poss_L() < en_coder+20 );
    Motor(-spl, -spr); delay(offset);
    Motor(-1, 1); delay(40);    
  }
  
void fw_x_left(int dis, int spl, int spr,  int deg, int offset)
  {
    int en_coder = map(deg, 0, 90, 0, 270);
    encoder.resetEncoders();
    while(encoder.Poss_R() < dis)
      {
        float error_L = map(mcp_b(3), min_mcp_b(3), max_mcp_b(3), 0, 30 );
        float error_R = map(mcp_b(4), min_mcp_b(4), max_mcp_b(4), 0, 30 );
        errors = error_L - error_R;     
        P = errors;
        I = I + errors;
        D = errors - previous_error;                    
        previous_error=errors  ;
        PID_output = (0.25 * P) + (0.00001 * I) + (0.15* D); 
          
        Motor(20 + PID_output, 20 - PID_output);delayMicroseconds(50);
      }
    Motor(-20, -20); delay(20);
    Motor(-1, 1); delay(100);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(spl, spr); }while( encoder.Poss_R() < en_coder );
    Motor(-spl, -spr); delay(offset);
    Motor(-1, 1); delay(40);    
  }

void bw_x_right(int dis, int spl, int spr, int deg, int offset)
  {
    int en_coder = map(deg, 0, 90, 0, 280);
    encoder.resetEncoders();
    while(encoder.Poss_R() > -dis)
      {
        float error_L = map(mcp_b(3), min_mcp_b(3), max_mcp_b(3), 0, 30 );
        float error_R = map(mcp_b(4), min_mcp_b(4), max_mcp_b(4), 0, 30 );
        errors = error_L - error_R;     
        P = errors;
        I = I + errors;
        D = errors - previous_error;                    
        previous_error=errors  ;
        PID_output = (0.25 * P) + (0.00001 * I) + (0.15* D); 
          
        Motor(-(20 - PID_output), -(20 + PID_output));delayMicroseconds(50);
      }
    Motor(-20, -20); delay(30);
    Motor(-1, 1); delay(100);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(spl, spr); }while( encoder.Poss_L() < en_coder );
    Motor(-spl, -spr); delay(offset);
    Motor(-1, 1); delay(40);    
  }

void bw_x_left(int dis, int spl, int spr, int deg, int offset)
  {
    int en_coder = map(deg, 0, 90, 0, 280);
    encoder.resetEncoders();
    while(encoder.Poss_R() > -dis)
      {
        float error_L = map(mcp_b(3), min_mcp_b(3), max_mcp_b(3), 0, 30 );
        float error_R = map(mcp_b(4), min_mcp_b(4), max_mcp_b(4), 0, 30 );
        errors = error_L - error_R;     
        P = errors;
        I = I + errors;
        D = errors - previous_error;                    
        previous_error=errors  ;
        PID_output = (0.25 * P) + (0.00001 * I) + (0.15* D); 
          
        Motor(-(20 - PID_output), -(20 + PID_output));delayMicroseconds(50);
      }
    Motor(-20, -20); delay(30);
    Motor(-1, 1); delay(100);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(spl, spr); }while( encoder.Poss_R() < en_coder );
    Motor(-spl, -spr); delay(offset);
    Motor(-1, 1); delay(40);    
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
