void sw_st()
  {
    bz(100);bz(100);
    mydisplay_background(black);
    mydisplay("MY-MAKERS", 20, 30, 2, white);delay(500);
    while(digitalRead(9) == 1)
      {
        
        diplay_mpu();
      }

     bz(100);
  }
