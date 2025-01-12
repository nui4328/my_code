void start_robot()
  {
    fline(40,40,0.25,10,'c','r',50, "a5", 50);
    fline(50,50,0.25,35,'f','s',50, "a2", 2);
    fw_x_right(200, 40, -30, 90, 30);
    
    fline(20,20,0.25,25,'n','s',50, "a2", 20);
    delay(200);
    check_floor();
        
    bline_setpoint(40,40,0.25, 50,"b0", 1);
    bw_x_right(160, 40, -40, 92, 30);
    fline(50,50,0.25,35,'c','r',50, "a5", 40);
  }
