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
    do{ Motor(-sp, sp); }while( encoder.Poss_R() < en_coder );
    Motor(sp, -sp); delay(40);
    Motor(1, -1); delay(40);
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

void T_right_sensor_F(int sp, int deg)
  {
    
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(sp, -sp); }while( encoder.Poss_L() < 150 );
    do{ Motor(sp, -sp); }while( mcp_f(deg) > min_mcp_f(deg)+70);
    Motor(-sp, sp); delay(30);
    Motor(-1, 1); delay(40);
    
  }

void T_right_sensor_B(int sp, int deg)
  {
    
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(sp, -sp); }while( encoder.Poss_L() < 150 );
    do{ Motor(sp, -sp); }while( mcp_b(deg) > min_mcp_b(deg)+70);
    Motor(-sp, sp); delay(30);
    Motor(-1, 1); delay(40);
    
  }

void T_left_sensor_F(int sp, int deg)
  {
    
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(-sp, sp); }while( encoder.Poss_L() > -150 );
    do{ Motor(-sp, sp); }while( mcp_f(deg) > min_mcp_f(deg)+70);
    Motor(sp, -sp); delay(30);
    Motor(-1, 1); delay(40);
    
  }

void T_left_sensor_B(int sp, int deg)
  {
    
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(-sp, sp); }while( encoder.Poss_L() > -150 );
    do{ Motor(-sp, sp); }while( mcp_b(deg) > min_mcp_b(deg)+70);
    Motor(sp, -sp); delay(30);
    Motor(-1, 1); delay(40);
    
  }
