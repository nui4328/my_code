void start_robot()
  {
    arm_down_open();
    fline(20,20,0.25,0,'f','p',50, "a5", 5);
    
    fline(40,40,0.25,32,'n','s',50, "a5", 20);
    if(analogRead(28)<ch_dis_can)
      {
        delay(100);  
        bline(20,20,0.25,0,'f','s',50, "a5", 10);
        bw_x_left(180, -45, 45, 87, 50);        
        fw_x_left(300, -45, 45, 90, 40);        
        fw_x_right(290, 40, -40, 89, 50);       
        read_eep(); //------->> เอาค่าใน eep ขณะนี้ออกมาเก็บไว้ที่ readEEP_cans
        get_can();
        goto can_none;
      }
    fline(20,20,0.25,10,'n','s',50, "a5", 20);
    arm_close_up();  
    readEEP_cans = 0;
    get_can();    //------->> เอาค่าใน readEEP_cans เริ่มต้นไปเก็บไว้ใน eep 
    strat_robot_left(); 
    can_none:delay(50);  
    
    for(int i = readEEP_cans; i<14; i++)
      {
        run_games(i);
        check_can_to_floor();
        count_cans ++;
        get_can();
      }  
  }
