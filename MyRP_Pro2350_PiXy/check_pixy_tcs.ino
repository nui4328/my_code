void pixy_vs_tcs()
  {
    digitalWrite(rgb[0],0);
    digitalWrite(rgb[1],0);
    digitalWrite(rgb[2],0);
    delay(500);
    searchColor();
    delay(300);

    if(pixy_color == tcs_color)
      {
        arm_ready();delay(200);
        servo(35, servo_down + 90);
        delay(200);
      }
  }