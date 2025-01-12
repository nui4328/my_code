void place_left()
  {
    fline(40,40,0.25,0,'f','s',40, "a2", 0);
    fw_x_left(220, -40, 40, 94, 50);
    fw_x_right(280, 40, -40, 80, 50);
    fw_x_left(250, -35, 45, 92, 40);  
    set34();
    
    fline(50,50,0.25,20,'f','s',50, "a2", 2);
    fw_x_right(180, 50, -30, 97, 30);
    if(num_place_left==0)
      {        
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 60, "a0", 1);
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);
        
        bline_setpoint(40,40,0.25, 40,"b0", 1);
        bw_x_right(160, 40, -40, 92, 30);
      }
    else if(num_place_left==1)
      {
        slow_dopwn();
        fline_setpoint(30, 30, 0.35, 30, "a0", 1);
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);
        
        bline_setpoint(40,40,0.25, 70,"b0", 1);
        bw_x_right(160, 40, -40, 92, 30);
      }
    else if(num_place_left==2)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 50, "a0", 1);
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);
        bline_setpoint(40,40,0.25, 30,"b0", 1);
        bw_x_right(160, 40, -40, 92, 30);
      }
    else if(num_place_left==3)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 30, "a0", 1);
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);
        bline_setpoint(40,40,0.25, 70,"b0", 1);
        bw_x_right(160, 40, -40, 92, 30);
      }
    else if(num_place_left==4)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 60, "a0", 1);   
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);
        bline_setpoint(40,40,0.25, 50,"b0", 1);
        bw_x_right(160, 40, -40, 92, 30);
      }
    else 
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 60, "a0", 1);   
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);
        bline_setpoint(40,40,0.25, 50,"b0", 1);
        bw_x_right(160, 40, -40, 92, 30);
      }
     num_place_left++;    
     fline(40,40,0.25,30,'f','s',50, "a5", 10);
     fw_x_right(220, 40, -40, 85, 50);
     fw_x_left(300, -40, 40, 89, 50);
     fw_x_right(280, 40, -40, 88, 50);
     set34();
    if(num_place_total == 15)
      {
        servo(8, servo_down+90);
        do{Motor(-20, -20);}while(mcp_f(0)> md_mcp_f(0));delay(10);
        do{Motor(-20, -20);}while(mcp_f(0)> md_mcp_f(0));
        Motor(-30, -30); delay(50);
        Motor(1, 1); delay(500);sw();
      }
    num_place_left ++;
  }

void place_right()
  {
    fline(40,40,0.25,0,'f','s',50, "a5", 0);
    fw_x_right(220, 40, -40, 84, 50);
    fw_x_left(300, -40, 40, 90, 50);
    fline(30,30,0.25,0,'c','r',40, "a5", 40);
    set34();
    fline(50,50,0.25,20,'f','s',50, "a2", 2);
    fw_x_left(220, -30, 50, 110, 30);
    if(num_place_right==0)
      {        
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 40, "a0", 1);  
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);
        bline_setpoint(40,40,0.25, 60,"b7", 1);
        bw_x_left(160, -40, 40, 92, 30);        
      }
    else if(num_place_right==1)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 30, "a0", 1); 
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);  
        
        bline_setpoint(40,40,0.25, 70,"b7", 1);
        bw_x_left(160, -40, 40, 92, 30);
      }
    else if(num_place_right==2)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 50, "a0", 1);
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);   
        
        bline_setpoint(40,40,0.25, 50,"b7", 1);
        bw_x_left(160, -40, 40, 92, 30);
      }
    else if(num_place_right==3)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 40, "a0", 1);
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);  
        
        bline_setpoint(40,40,0.25, 40,"b7", 1);
        bw_x_left(160, -40, 40, 92, 30);
      }
    else if(num_place_right==4)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 70, "a0", 1); 
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);  
           
        
        bline_setpoint(40,40,0.25, 30,"b7", 1);
        bw_x_left(160, -40, 40, 92, 30); 
      }
    else
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 60, "a0", 1);
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);   
          
        
        bline_setpoint(40,40,0.25, 40,"b7", 1);
        bw_x_left(160, -40, 40, 92, 30);   
      }
    num_place_right++;
    fline(40,40,0.25,30,'f','s',50, "a5", 10);
    fw_x_left(220, -40, 40, 92, 50);
    fw_x_right(300, 40, -40, 83, 50);
    fline_setpoint(20,20,0.25, 50,"27", 40);
    fline(0,0,0.0,0,'n','l',40, "a2", 40); 
    set34();   
     if(num_place_total == 15 )
      {
        servo(8, servo_down+90);
        do{Motor(-20, -20);}while(mcp_f(0)> md_mcp_f(0));delay(10);
        do{Motor(-20, -20);}while(mcp_f(0)> md_mcp_f(0));
        Motor(-30, -30); delay(50);
        Motor(1, 1); delay(500);sw();
      } 
     num_place_right ++;
  }

void place_center()
  {
    fline_2sensor(40, 40, 0.45, 0, "3:4","a0", 's', 0);
    fw_x_right(220, 40, -40, 83, 40);
    fw_x_left(290, -40, 40, 87, 40);
    fw24_x_left(600, -40, 40, 90, 40);  //---------------------->>
    fw35_x_right(260, 30, -30, 84, 30); 
    
    if(num_place_center==0)
      {        
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 40, "a0", 1);        
        encoder.resetEncoders();
        do{Motor(15, 15);}while(encoder.Poss_R() < 100);      
        Motor(-1, -1); delay(100);
        arm_place();delay(200); 
        bline_setpoint(20,20,0.25, 60,"b7", 1);
      }
    else if(num_place_center==1)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 30, "a0", 40);   
        encoder.resetEncoders();
        do{Motor(15, 15);}while(encoder.Poss_R() < 100);      
        Motor(-1, -1); delay(100);
        arm_place();delay(200); 
        bline_setpoint(20,20,0.25, 70,"b7", 1);
      }
    else if(num_place_center==2)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 50, "a0", 40);   
        encoder.resetEncoders();
        do{Motor(15, 15);}while(encoder.Poss_R() < 100);      
        Motor(-1, -1); delay(100);
        arm_place();delay(200); 
        bline_setpoint(20,20,0.25, 50,"b7", 1);
      }
    else if(num_place_center==3)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 40, "a0", 40);  
        encoder.resetEncoders();
        do{Motor(15, 15);}while(encoder.Poss_R() < 100);      
        Motor(-1, -1); delay(100);
        arm_place();delay(200); 
        bline_setpoint(20,20,0.25, 40,"b7", 1);
      }
    else if(num_place_center==4)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 64, "a0", 40);   
        encoder.resetEncoders();
        do{Motor(15, 15);}while(encoder.Poss_R() < 100);      
        Motor(-1, -1); delay(100);
        arm_place();delay(200);
        bline_setpoint(20,20,0.25, 30,"b7", 1);
      }
    else
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 60, "a0", 40);  
        encoder.resetEncoders();
        do{Motor(15, 15);}while(encoder.Poss_R() < 100);      
        Motor(-1, -1); delay(100);
        arm_place();delay(200);
        bline_setpoint(20,20,0.25, 40,"b7", 1);
      }
    bw_x_left(150, -40, 40, 91, 40);
    fline_setpoint(20, 20, 0.0, 50, "27", 40);
    fw_x_left(0, -40, 40, 90, 40);
    fw24_x_left(650, -40, 40, 89, 50); //-------------------------->>
    fw_x_right(270, 40, -40, 84, 50); 
    set34();
    if(num_place_total == 15 )
      {
        servo(8, servo_down+90);
        do{Motor(-20, -20);}while(mcp_f(0)> md_mcp_f(0));delay(10);
        do{Motor(-20, -20);}while(mcp_f(0)> md_mcp_f(0));
        Motor(-30, -30); delay(50);
        Motor(1, 1); delay(500);sw();
      }
    num_place_center ++;
  }
