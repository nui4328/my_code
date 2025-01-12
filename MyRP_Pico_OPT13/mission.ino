void place_left()
  {
    num_place_total++;
    fline(30,30,0.25,0,'c','l',40, "a2", 30);    
    fline_setpoint(50, 50, 0.35, 50, "a0", 2); 
    
    if(num_place_left==0)
      {
        fw_x_right(300, 40, -30, 90, 30);
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 60, "a0", 40);
        arm_down_open();
        
        bline_setpoint(40,40,0.25, 40,"b0", 1);
        bw_x_right(160, 40, -40, 92, 30);
        fline(50,50,0.25,35,'c','r',50, "a5", 40);
      }
    else if(num_place_left==1)
      {
        fw_x_right(300, 40, -30, 100, 30);
        slow_dopwn();
        fline_setpoint(30, 30, 0.35, 30, "a0", 40);
        arm_down_open();
        
        bline_setpoint(40,40,0.25, 70,"b0", 1);
        bw_x_right(160, 40, -40, 92, 30);
        fline(50,50,0.25,35,'c','r',50, "a5", 40);
      }
    else if(num_place_left==2)
      {
        fw_x_right(300, 40, -30, 84, 30);
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 50, "a0", 40);
        arm_down_open();
        bline_setpoint(40,40,0.25, 30,"b0", 1);
        bw_x_right(160, 40, -40, 92, 30);
        fline(50,50,0.25,35,'c','r',50, "a5", 40);
      }
    else if(num_place_left==3)
      {
        fw_x_right(300, 40, -30, 100, 30);
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 30, "a0", 40);
        arm_down_open();
        bline_setpoint(40,40,0.25, 70,"b0", 1);
        bw_x_right(160, 40, -40, 92, 30);
        fline(50,50,0.25,35,'c','r',50, "a5", 40);
      }
    else if(num_place_left==4)
      {
        fw_x_right(300, 40, -30, 90, 30);
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 60, "a0", 40);   
        arm_down_open();
        bline_setpoint(40,40,0.25, 50,"b0", 1);
        bw_x_right(160, 40, -40, 92, 30);
        fline(50,50,0.25,35,'c','r',50, "a5", 40);
      }
    else 
      {
        fw_x_right(300, 40, -30, 90, 30);
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 60, "a0", 40);   
        arm_down_open();
        bline_setpoint(40,40,0.25, 50,"b0", 1);
        bw_x_right(160, 40, -40, 92, 30);
        fline(50,50,0.25,35,'c','r',50, "a5", 40);
      }
    num_place_left++;    
      if(num_place_total == 10 || end_13s == 1)
        {
          bline(40,40,0.25,dis_bw_end,'n','s',50, "a5", 40);
           servo(8, servo_down+80);delay(200);
          sw();
        }
  }

void place_right()
  {
    num_place_total++;
    fline(30,30,0.25,0,'c','r',40, "a5", 30);
    fline_setpoint(50, 50, 0.35, 50, "a7", 2); 
    
    if(num_place_right==0)
      {
        fw_x_left(320, -30, 40, 90, 30);
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 40, "a0", 40);   
        arm_down_open();
        bline_setpoint(40,40,0.25, 60,"b7", 1);
        bw_x_left(160, -40, 40, 92, 30);
        fline(50,50,0.25,35,'c','l',50, "a2", 40);        
      }
    else if(num_place_right==1)
      {
        fw_x_left(320, -30, 40, 84, 30);
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 30, "a0", 40);   
        arm_down_open();
        
        bline_setpoint(40,40,0.25, 70,"b7", 1);
        bw_x_left(160, -40, 40, 92, 30);
        fline(50,50,0.25,35,'c','l',50, "a2", 40);
      }
    else if(num_place_right==2)
      {
        fw_x_left(320, -30, 40, 100, 40);
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 50, "a0", 40);   
        arm_down_open();
        
        bline_setpoint(40,40,0.25, 50,"b7", 1);
        bw_x_left(160, -40, 40, 92, 30);
        fline(50,50,0.25,35,'c','l',50, "a2", 40);
      }
    else if(num_place_right==3)
      {
        fw_x_left(320, -30, 40, 90, 30);
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 40, "a0", 40);   
        arm_down_open();
        
        bline_setpoint(40,40,0.25, 40,"b7", 1);
        bw_x_left(160, -40, 40, 92, 30);
        fline(50,50,0.25,35,'c','l',50, "a2", 40);
      }
    else if(num_place_right==4)
      {
        fw_x_left(320, -30, 40, 100, 40);
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 70, "a0", 40);   
        arm_down_open();    
        
        bline_setpoint(40,40,0.25, 30,"b7", 1);
        bw_x_left(160, -40, 40, 92, 30);
        fline(50,50,0.25,35,'c','l',50, "a2", 40);   
      }
    else
      {
        fw_x_left(320, -30, 40, 100, 30);
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 60, "a0", 40);   
        arm_down_open();   
        
        bline_setpoint(40,40,0.25, 40,"b7", 1);
        bw_x_left(160, -40, 40, 92, 30);
        fline(50,50,0.25,35,'c','l',50, "a2", 40);   
      }
    num_place_right++;
    if(num_place_total == 10 || end_13s == 1)
        {
          bline(40,40,0.25,dis_bw_end,'n','s',50, "a5", 40);
          servo(8, servo_down+80);delay(200);
          sw();
        }
    
  }
