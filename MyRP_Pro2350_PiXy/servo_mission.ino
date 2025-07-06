


void arm_ready()
  {
    servo(35, servo_down);
    servo(34, servoL_open - 30);
    servo(36, servoR_open + 30);
  }
void arm_ready_min()
  {
    servo(35, servo_down);
    servo(34, servoL_open - 65);
    servo(36, servoR_open + 65);
  }
void arm_ready_r()
  {
    servo(35, servo_down);
    servo(34, servoL_open - 30);
    servo(36, servoR_open + 70);
  }

void arm_ready_l()
  {
    servo(35, servo_down);
    servo(34, servoL_open - 70);
    servo(36, servoR_open + 30);
  }

void arm_open_min_up()
  {
    servo(35, servo_down);
    servo(34, servoL_open - 60);
    servo(36, servoR_open + 60);
    delay(200);
    servo(35, servo_down + 90);
    delay(200);
  }

void arm_down_open()
  {
    servo(35, servo_down);
    servo(34, servoL_open);
    servo(36, servoR_open);
  }
void arm_up_open()
  {
    servo(35, servo_down + 90);
    servo(34, servoL_open);
    servo(36, servoR_open);
  }
void arm_down_close()
  {
    servo(35, servo_down);
    servo(34, servoL_open-116);
    servo(36, servoR_open+120);
  }
void arm_big_box()
  {
    servo(35, servo_down);
    servo(34, servoL_open - 70);
    servo(36, servoR_open + 70);
  }

