void tcs_vs_husky()
  {
    digitalWrite(rgb[0],0);
    digitalWrite(rgb[1],0);
    digitalWrite(rgb[2],0);
    delay(300);
    get_color_tcs();delay(300);
    get_color_tcs();
    if(husky_color == tcs_color)
      {
        arm_ready_min();

        delay(300);
        servo(35, servo_down + 50);
        delay(300);
      }
    else{

    }
    delay(300);
  }

void check_mission()
  {
    fline(10, 10, 0.35, 10, 'n', 's', 50, "a1", 20);  //
  }