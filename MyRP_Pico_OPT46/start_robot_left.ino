void strat_robot_left()
  {

    //----------------------------------------------------------------------------------------------****>>>>> คีบกระป๋องที่ 1
     delay(200);
     check_color();
     if(check_color() == collor_floor[2])    //-------------->> กระป๋องเท่ากับตัวแปรที่ 2 
        {
           fline(20,20,0.25,0,'f','s',50, "a2", 2);   //collor_floor[] = {"red", "yellow", "green"} ;
           fw_x_right(200, 40, -30, 90, 30);
           slow_dopwn();
           fline_setpoint(25, 25, 0.35, 60, "a0", 40); //--------->> วิ่งเข้าไปวางในกรอด้านซ้าย
           
           fline(15,15,0.0,7,'n','s',50, "a2", 20); 
           arm_place();delay(200);
                   
           bline_setpoint(40,40,0.25, 40,"b0", 1);
           bw_x_right(160, 40, -40, 92, 30);
      
           fline(40,40,0.25,25,'f','s',50, "a5", 10);
           fw_x_right(220, 45, -45, 85, 50);
           fw_x_left(300, -45, 45, 87, 50);
           fline_2sensor(45, 45, 0.35, 0, "3:4","a0", 's', 10);
           fw_x_left(220, -45, 45, 88, 50);
           fw_x_right(260, 40, -40, 82, 50);
        }
      else                                  //-------------->> กระป๋อง ไม่ เท่ากับตัวแปรที่ 2 
        {
          bline(20, 20, 0.35, 0, 'c','r', 40, "a5", 50);
          fw_x_right(300, 40, -40, 83, 50);
          fw24_x_left(230, -30, 30, 92, 30); 
          slow_dopwn();
          fline_setpoint(15, 15, 0.35, 40, "a0", 1);        
          encoder.resetEncoders();
          do{Motor(15, 15);}while(encoder.Poss_R() < 200);      
          Motor(-1, -1); delay(100);
          arm_place();delay(200); 
          bline_setpoint(20,20,0.25, 60,"b7", 1);
          bw_x_right(160, 40, -40, 92, 30);
          fw_x_right(250, 40, -40, 80, 50);
          fw24_x_left(220, -30, 45, 110, 40);

           
        }
    //----------------------------------------------------------------------------------------------****>>>>> จบคีบกระป๋องที่ 1 
    
    fline(20,20,0.25,dis_canst2,'n','s',50, "a5", 20);
    arm_close_up();
    delay(300);
    check_color();
    if(check_color() == collor_floor[0])   //---->>>  ถ้าสีตรงกับพื้นขวา  ให้เข้าไปวางขวา//collor_floor[] = {"red", "yellow", "green"} ;
      {
        fw_x_left(270, -30, 50, 92, 30);
        slow_dopwn();
        fline_setpoint(15, 15, 0.35, 40, "a0", 40);  
         
        arm_place();delay(200);  num_place_total++;
        
        bline_setpoint(40,40,0.25, 60,"b7", 1);
        bw_x_left(160, -40, 40, 92, 30);
        fline(40,40,0.25,30,'f','s',50, "a5", 10);
        fw_x_left(220, -45, 45, 90, 50);
        fw_x_right(290, 40, -40, 84, 50);
        fw24_x_left(290, -45, 45, 92, 40);  
        set34();
      }
    else if(check_color() == collor_floor[2])   //---->>>  ถ้าสีตรงกับพื้นซ้าน  ให้เดินกลับมาวางด้านซ้าย 
      {
        bline(40,40,0.25,20,'f','s',50, "a5", 10);
        bw_x_left(180, -45, 45, 87, 50);
        fw_x_left(300, -45, 45, 90, 40);
        fline_2sensor(45, 45, 0.35, 0, "3:4","a0", 's', 10);
        fw_x_left(220, -45, 45, 87, 50);
        fw_x_right(290, 40, -40, 82, 50);
    
        fline(40,40,0.25,30,'f','s',50, "a5", 10);
 
        fw_x_right(200, 40, -30, 90, 30);
        slow_dopwn();
        fline_setpoint(25, 25, 0.35, 60, "a0", 40); //--------->> วิ่งเข้าไปวางในกรอด้านซ้าย
        
        arm_place();delay(200);  num_place_total++;
                
        bline_setpoint(40,40,0.25, 40,"b0", 1);
        bw_x_right(160, 40, -40, 92, 30);
  
        fline(40,40,0.25,30,'f','s',50, "a5", 10);
        fw_x_right(220, 45, -45, 85, 50);
        fw_x_left(300, -45, 45, 87, 50);
        fw_x_right(270, 45, -45, 90, 50);
        set34();
      }
    else  ///--------------------------->>  วางกระป๋องตรงกลาง
      {
        bline(40,40,0.25,20,'f','s',50, "a5", 10);
        bw_x_left(180, -45, 45, 87, 50);        
        fw_x_left(300, -45, 45, 90, 40);
        fw_x_right(280, 45, -45, 90, 50);
        set34();
        slow_dopwn();
        fline_setpoint(15, 15, 0.0, 50, "a0", 40);  
        encoder.resetEncoders();
        do{Motor(15, 15);}while(encoder.Poss_R() < 100);      
        Motor(-1, -1); delay(100);
        arm_place();delay(200);
        bline_setpoint(20,20,0.25, 40,"b7", 1);
        num_place_total++;
         
        bw_x_left(150, -40, 40, 91, 40);
        fline_setpoint(20, 20, 0.0, 50, "27", 40);
        fw_x_left(0, -45, 45, 90, 40);
        fw24_x_left(650, -45, 45, 89, 50); //-------------------------->>
        fw_x_right(270, 40, -40, 84, 50); 
        set34();
      }

           
  }
