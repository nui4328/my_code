

void arm_ready()
  {
    servo(8, servo_down);
    servo(0, servo_close-50);
  }

void arm_down_open()
  {
    servo(8, servo_down);delay(200);
    servo(0, servo_close - 60);delay(300);
  }
void arm_down_close()
  {
    servo(8, servo_down);
    servo(0, servo_close);
  }

void arm_close_up()
  {
    servo(0, servo_close); delay(200);
    servo(8, servo_down+90);delay(200);
  }
void slow_dopwn()
  {
    for(int i=servo_down+80; i>servo_down+10; i--)
      {
        servo(8, i);delay(7);
      }
  }
void place_right_in(int sp, int deg)
  {
    int en_coder = map(deg, 0, 90, 0, 600);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(sp, -1); }while( encoder.Poss_L() < en_coder );
    Motor(-sp, 1); delay(40);
    Motor(-1, 1); delay(40);
  }

void place_right_out(int sp, int deg)
  {
    int en_coder = map(deg, 0, 90, 0, 600);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(-sp, 1); }while( encoder.Poss_L() > -en_coder );
    Motor(sp, -1); delay(40);
    Motor(1, -1); delay(40);
  }
void place_letf_in(int sp, int deg)
  {
    int en_coder = map(deg, 0, 90, 0, 600);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(-1, sp); }while( encoder.Poss_R() < en_coder );
    Motor(1, -sp); delay(40);
    Motor(1, -1); delay(40);
  }

void place_letf_out(int sp, int deg)
  {
    int en_coder = map(deg, 0, 90, 0, 600);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(1, -sp); }while( encoder.Poss_R() > -en_coder );
    Motor(-1, sp); delay(40);
    Motor(-1, 1); delay(40);
  }

  
  
