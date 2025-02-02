void place_left()
  {
    fline(20,20,0.25,0,'c','l',50, "b3", 30);
    do{Motor(45, 15);}while(mcp_f(0)> md_mcp_f(0));
    Motor(-55, -15),delay(40);
    Motor(0, 0),delay(40);

    Motor(-1, 45);delay(100);
    do{Motor(-1, 45);}while(mcp_f(4) > md_mcp_f(4));
    Motor(1, -45),delay(20);
    Motor(0, 0),delay(40);
    
    fline(50,50,0.25,20,'f','s',50, "a2", 2);
    fw_x_right(220, 50, -30, 110, 30);

    //----------------------------------------------------------->>> นับการเข้าวาง
    if(num_place_left==0)
      {        
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 60, "a0", 1);
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);
        
        bline_setpoint(40,40,0.25, 40,"b0", 1);
        bw_x_right(160, 50, -50, 92, 30);
      }
    else if(num_place_left==1)
      {
        slow_dopwn();
        fline_setpoint(30, 30, 0.35, 30, "a0", 1);
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);
        
        bline_setpoint(40,40,0.25, 70,"b0", 1);
        bw_x_right(160, 50, -50, 92, 30);
      }
    else if(num_place_left==2)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 50, "a0", 1);
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);
        bline_setpoint(40,40,0.25, 30,"b0", 1);
        bw_x_right(160, 50, -50, 92, 30);
      }
    else if(num_place_left==3)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 30, "a0", 1);
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);
        bline_setpoint(40,40,0.25, 70,"b0", 1);
        bw_x_right(160, 50, -50, 92, 30);
      }
    else if(num_place_left==4)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 60, "a0", 1);   
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);
        bline_setpoint(40,40,0.25, 50,"b0", 1);
        bw_x_right(160, 50, -50, 92, 30);
      }
    else 
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 60, "a0", 1);   
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);
        bline_setpoint(40,40,0.25, 50,"b0", 1);
        bw_x_right(160, 50, -50, 92, 30);
      }
     num_place_left++;    
    //----------------------------------------------------------->>> นับการเข้าวาง 
     fline(40,40,0.25,30,'f','s',50, "a5", 10);
     fw_x_right(220, 45, -45, 84, 50);
     fw_x_left(260, -45, 45, 87, 50);
     fw_x_right(250, 45, -45, 20, 0); 
     fline(0,0,0.0,0,'n','r',40, "a4", 40);

     
     set34();
    if(num_place_total == 15)   //------>>เช็คว่ากระป๋องหมดหรือยัง
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
    fline(20,20,0.25,0,'c','r',40, "b4", 30);
    
    do{Motor(15, 45);}while(mcp_f(7)> md_mcp_f(7));
    Motor(-15, -45),delay(40);
    Motor(0, 0),delay(40);

    Motor(45, -1);delay(100);
    do{Motor(45, -1);}while(mcp_f(3) > md_mcp_f(3));
    Motor(-45, 5),delay(40);
    Motor(0, 0),delay(40);
    fline(50,50,0.25,20,'f','s',50, "a2", 2);
    fw_x_left(200, -30, 50, 110, 50);
    if(num_place_right==0)
      {        
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 40, "a0", 1);  
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);
        bline_setpoint(40,40,0.25, 60,"b7", 1);
        bw_x_left(160, -50, 50, 92, 30);        
      }
    else if(num_place_right==1)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 30, "a0", 1); 
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);  
        
        bline_setpoint(40,40,0.25, 70,"b7", 1);
        bw_x_left(160, -50, 50, 92, 30);
      }
    else if(num_place_right==2)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 50, "a0", 1);
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);   
        
        bline_setpoint(40,40,0.25, 50,"b7", 1);
        bw_x_left(160, -50, 50, 92, 30);
      }
    else if(num_place_right==3)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 40, "a0", 1);
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);  
        
        bline_setpoint(40,40,0.25, 40,"b7", 1);
        bw_x_left(160, -50, 50, 92, 30);
      }
    else if(num_place_right==4)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 70, "a0", 1); 
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);  
           
        
        bline_setpoint(40,40,0.25, 30,"b7", 1);
        bw_x_left(160, -50, 50, 92, 30); 
      }
    else
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 60, "a0", 1);
        fline(15,15,0.0,5,'n','s',50, "a2", 20); 
        arm_place();delay(200);   
          
        
        bline_setpoint(40,40,0.25, 40,"b7", 1);
        bw_x_left(160, -50, 50, 92, 30);   
      }
    num_place_right++;
    fline(40,40,0.25,30,'f','s',50, "a5", 10);
    fw_x_left(220, -45, 45, 92, 50);
    fw_x_right(250, 50, -50, 80, 50);
    fw_x_left(240, -45, 45, 20, 0);
    fline(0,0,0.0,0,'n','l',40, "a3", 40);
    
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
    fline(40,40,0.25,0,'c','r',40, "b5", 30);
    
    move_pid4(40, 40, 0.3, 'p', "a0", 1); delay(30);
    do{Motor(-5, 65);}while(mcp_f(7) > md_mcp_f(7));  
    do{Motor(-5, 65);}while(mcp_f(7) < md_mcp_f(7));
    Motor(5, -65);delay(40);
    Motor(-1, -1);delay(30);  
    
    move_pid4(30, 30, 0.2, 'p', "a0", 20);
    do{Motor(-5, 65);}while(mcp_f(7) > md_mcp_f(7));  
    //do{Motor(-5, 65);}while(mcp_f(7) < md_mcp_f(7)); 
    Motor(5, -65);delay(10);
    Motor(-1, -1);delay(30);    
    
    fw35_x_right(140, 30, -30, 88, 40); 
    
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
        fline_setpoint(15, 15, 0.35, 45, "a0", 40);   
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
        fline_setpoint(15, 15, 0.35, 55, "a0", 40);  
        encoder.resetEncoders();
        do{Motor(15, 15);}while(encoder.Poss_R() < 100);      
        Motor(-1, -1); delay(100);
        arm_place();delay(200); 
        bline_setpoint(20,20,0.25, 40,"b7", 1);
      }
    else if(num_place_center==4)
      {
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 50, "a0", 40);   
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
    bw_x_left(150, -50, 50, 93, 40);
    
    move_pid4(35, 35, 0.15, 'p', "a0", 10);
    do{Motor(-5, 65);}while(mcp_f(7) > md_mcp_f(7));  
    do{Motor(-5, 65);}while(mcp_f(7) < md_mcp_f(7));
    Motor(5, -65);delay(30);
    Motor(-1, -1);delay(30);  
    
    move_pid4(30, 30, 0.2, 'p', "a0", 20);
    do{Motor(-5, 65);}while(mcp_f(7) > md_mcp_f(7));  
    //do{Motor(-5, 65);}while(mcp_f(7) < md_mcp_f(7)); 
    Motor(5, -65);delay(20);
    Motor(-1, -1);delay(30);    
    
    fw35_x_right(100, 30, -30, 84, 50);  
    
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
