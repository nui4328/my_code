void can_1()
  {
    arm_down_open();
    fline(50, 50, 0.25, 0, 'c', 'l', 50, "a1", 40);
    fline(72, 72, 0.25, 24,'n','s',50, "a2", 10);  //------>> เดินเข้ากล่องที่ 1 เดินเป็นระยะทาง 26 cm
    //fline(20, 20, 0.05, 15,'n','s',50, "a2", 10);delay(100);
    
    arm_close_up();
    
    bline(78, 78, 0.35, 30, 'c', 'l', 40, "a3", 40);   
  }

void can_2()
  {
    arm_down_open();
    fline(30, 30, 0.25, 0, 'c', 'r', 40, "a5", 40);
    fline(52, 52, 0.25, 26,'n','s',50, "a2", 10);  //------>> เดินเข้ากล่องที่ 1
    fline(20, 20, 0.05, 14,'n','s',50, "a2", 10);delay(200);
    
    arm_close_up();
    
    bline(48, 48, 0.35, 30, 'c', 'r', 40, "a4", 40);   
  }

void can_3()
  {
    arm_down_open();
    fline(30, 30, 0.25, 0, 'f', 'p', 40, "a2", 0);
    move_pid4(30, 30, 0.35, 's', "a0", 0);
    fw_x_left(300, -40, 40, 88, 30);
    
    fline(52, 52, 0.25, 26,'n','s',50, "a2", 10);  //------>> เดินเข้ากล่องที่ 1
    fline(20, 20, 0.05, 16 ,'n','s',50, "a2", 10);delay(200);   //---------------->>  ถ้าชนหรือไม่ถึงกระป๋อง ให้ปรับ เลข ตัวแปรที่ 4
    
    arm_close_up();
    
    bline(41, 41,0.25, 30,'f','s',50, "a2", 1);  //------>> เลข 30 คือระยะทางที่ถอยออกมาแล้วความเร็วจะลดลง
    
    bw_x_left(350, -40, 40, 88, 50);     //------------>>  ถอยหลังให้ล้อเหยียบเส้นโดยปรับเลขตัวแปรที่ 1  หมุนให้ได้มุมตามที่ต้องการโดยปรับตัวแปรที่ 4 
    
    fline(41, 41,0.25,15,'f','p',50, "a2", 0); 
  }

void can_4()
  {
    arm_down_open();
    fline(30, 30, 0.25, 0, 'f', 'p', 40, "a2", 0);
    fline(41, 41,0.25,15,'f','s',50, "a2", 1);
    fw_x_right(300, 40, -40, 85, 30);
    fline(52, 52, 0.25, 26,'n','s',50, "a2", 10);  //------>> เดินเข้ากล่องที่ 1
    fline(20, 20, 0.05, 16,'n','s',50, "a2", 10);delay(200);
    
    arm_close_up();
    
    bline(41, 41,0.25,30,'f','s',50, "a2", 1);
    bw_x_right(350, 40, -40, 88, 50);  
    fline(41, 41,0.25,15,'f','p',50, "a2", 0); 
  }

void can_5()
  {
    arm_down_open();
    fline(30, 30, 0.25, 0, 'f', 'p', 40, "a2", 0);
    fline(41, 41,0.25,20,'f','s',50, "a2", 1);
    fw_x_left(320, -40, 40, 47, 30);
    
    fline(52,52,0.25,34,'n','s',50, "a2", 10);
    fline(20,20,0.25,19,'n','s',50, "a2", 10);delay(200);  
      
    arm_close_up();    
    bline(41, 41,0.25,40,'f','s',50, "a2", 1);
    bw_x_left(320, -40, 40, 120, 30);
    fline(41, 41,0.25,0,'c','p',50, "a2",0);
  }

void can_6()
  {
    arm_down_open();
    fline(41, 41,0.25,0,'c','p',50, "a2",0);
    fline(41, 41,0.25,20,'f','s',50, "a2", 1);
    fw_x_right(320, 40, -40, 47, 30);
    
    fline(52,52,0.25,36,'n','s',50, "a2", 5); 
    fline(20,20,0.25,15,'n','s',50, "a2", 10);delay(200);    
    arm_close_up();
    
    bline(41, 41,0.25,40,'f','s',50, "a2", 5);
    bw_x_right(320, 40, -40, 120, 30);
    fline(41, 41,0.25,0,'c','p',50, "a2",0);
      
  }

void can_7()
  {
    arm_down_open();
    fline(41, 41, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(41, 41, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(30, 30, 0.25, 0, 'f', 'p', 40, "a5", 30);
    do{Motor(-10, 20);}while(mcp_f(4) > md_mcp_f(4));

    move_pid4(35, 30, 0.65, 'p', "a0", 0);
    move_pid4(35, 30, 0.65, 'p', "a0", 20);
    //fline_2sensor(35,25, 0.75, 23, "2:5","a0", 's', 20);

    Motor(-20, 30);delay(100);
    do{Motor(-20, 30);}while(mcp_f(0) > md_mcp_f(0));
    do{Motor(-20, 30);}while(mcp_f(3) > md_mcp_f(3));
    Motor(20, -30); delay(30);
    Motor(-1, -1); delay(50);
    
    move_pid4(35, 30, 0.65, 'p', "a0", 20);

    do{Motor(-15, 30);}while(mcp_f(0) > md_mcp_f(0));
    do{Motor(-15, 30);}while(mcp_f(3) > md_mcp_f(3));
    Motor(-10, 30); delay(20);
    Motor(-1, 1); delay(30);

    fline(40, 40, 0.25, 12,'n','s',50, "a2", 10); 
    fline(20,20,0.05,19,'n','s',50, "a2", 20);delay(200);
        
    arm_close_up(); ///------------------------------->>

    bline(40, 40, 0.25, 0,'c','l',30, "a2", 20);
    move_pid4(30, 35, 0.65, 'p', "a7", 20);
    delay(30);
    do{Motor(25, -30);}while(mcp_f(7) > md_mcp_f(7));
    do{Motor(25, -30);}while(mcp_f(3) > md_mcp_f(3));
    Motor(-25, 30); delay(20);
    Motor(1, 1); delay(30);
    
    move_pid4(30, 35, 0.65, 'p', "a7", 0);
    move_pid4(30, 35, 0.65, 's', "a7", 20);
    
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(20, 20); }while( encoder.Poss_L() < 80);
    Motor(-20, -20);delay(50);
    Motor(-1, -1); delay(100);  
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(30, -20); }while( encoder.Poss_L() < 150);
    do{ Motor(30, -20); }while( mcp_f(3) > md_mcp_f(3)); 
    Motor(-30, 20); delay(30);
    Motor(1, -1); delay(40); 
    
    move_pid4(41, 41, 0.25, 'p', "a0", 0);  delay(50); 
    fline(41, 41,0.25,0,'c','p',50, "a2",0);       
  }

void can_8()
  {
    arm_down_open();
    fline(41, 41, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(41, 41, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(30, 30, 0.25, 0, 'f', 'p', 40, "a5", 30);
    do{Motor(20, -10);}while(mcp_f(4) > md_mcp_f(4));

    move_pid4(30, 35, 0.65, 'p', "a7", 0);
    move_pid4(30, 35, 0.65, 'p', "a7", 20);

    Motor(30, -20);delay(100);
    do{Motor(30, -20);}while(mcp_f(7) > md_mcp_f(7));
    do{Motor(30, -20);}while(mcp_f(4) > md_mcp_f(4));
    Motor(-30, 20); delay(30);
    Motor(-1, -1); delay(50);
    
    move_pid4(30, 35, 0.65, 'p', "a7", 20);

    do{Motor(30, -15);}while(mcp_f(7) > md_mcp_f(7));
    do{Motor(30, -15);}while(mcp_f(4) > md_mcp_f(4));
    Motor(-30, 15); delay(20);
    Motor(-1, 1); delay(30);

    fline(40, 40, 0.25, 10,'n','s',50, "a2", 10); 
    fline(20,20,0.05,19,'n','s',50, "a2", 20);delay(200);
        
    arm_close_up(); ///------------------------------->>

    bline(40, 40, 0.25, 0,'c','r',30, "a5", 20);
    move_pid4(30, 35, 0.65, 'p', "a0", 20);
    delay(30);
    do{Motor(-30, 25);}while(mcp_f(0) > md_mcp_f(0));
    do{Motor(-30, 25);}while(mcp_f(4) > md_mcp_f(4));
    Motor(30, -25); delay(20);
    Motor(1, 1); delay(30);
    
    move_pid4(30, 35, 0.65, 'p', "a0", 0);
    move_pid4(30, 35, 0.65, 's', "a0", 20);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(20, 20); }while( encoder.Poss_R() < 80);
    Motor(-20, -20);delay(50);
    Motor(-1, -1); delay(100);  
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(-20, 35); }while( encoder.Poss_R() < 150);
    do{ Motor(-20, 35);  }while( mcp_f(4) > md_mcp_f(4)); 
    Motor(20, -30);  delay(30);
    Motor(1, -1); delay(40); 
    
    move_pid4(41, 41, 0.25, 'p', "a0", 0);  delay(50); 
    fline(41, 41,0.25,0,'c','p',50, "a2",0);  
  }

void can_9()
  {
    arm_down_open();
    fline(41, 41, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(41, 41, 0.25, 0, 'f', 'p', 40, "a5", 0);

    circle();

    fline(20,20,0.25,0,'f','s',50, "a2", 1);
    fw_x_left(300, -40, 40, 86, 30);
    fline(52, 52, 0.25, 26,'n','s',50, "a2", 10);  //------>> เดินเข้ากล่องที่ 1
    fline(20, 20, 0.05, 14,'n','s',50, "a2", 15);delay(200);
    
    arm_close_up();
    
    bline(41, 41,0.25,30,'f','s',50, "a2", 1);
    bw_x_left(330, -40, 40, 88, 40); 

    circle();
    
    move_pid4(41, 41, 0.25, 'p', "a0", 0);  delay(50);
    fline(41, 41,0.25,0,'c','p',50, "a2",0); 
    
  }

void can_10()
  {
    arm_down_open();
    fline(41, 41, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(41, 41, 0.25, 0, 'f', 'p', 40, "a5", 0);

    circle();

    fline(20,20,0.25,0,'f','s',50, "a2", 1);
    fw_x_right(300, 40, -40, 85, 30);
    fline(52, 52, 0.25, 26,'n','s',50, "a2", 10);  //------>> เดินเข้ากล่องที่ 1
    fline(20, 20, 0.05, 15,'n','s',50, "a2", 10);delay(200);
    
    arm_close_up();
    
    bline(41, 41,0.25,30,'f','s',50, "a2", 1);
    bw_x_right(330, 40, -40, 95, 40);   
    
    circle();
    
    move_pid4(41, 41, 0.25, 'p', "a0", 0);  delay(50); 
    fline(41, 41,0.25,0,'c','p',50, "a2",0); 
  }


void can_11()
  {
    arm_down_open();
    fline(41, 41, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(41, 41, 0.25, 0, 'f', 'p', 40, "a5", 0);

    circle();

    fline(20,20,0.25,0,'f','s',50, "a2", 1);
    fw_x_left(320, -40, 40, 47, 30);
    fline(52,52,0.25,35,'n','s',50, "a2", 10);
    fline(20,20,0.25,16,'n','s',50, "a2", 10);delay(200);    
    arm_close_up();    
    bline(41, 41,0.25,40,'f','s',50, "a2", 1);
    bw_x_left(320, -40, 40, 118, 30); 

    circle();
    
    move_pid4(41, 41, 0.25, 'p', "a0", 0);  delay(50);
    fline(41, 41,0.25,0,'c','p',50, "a2",0); 
    
  }

void can_12()
  {
    arm_down_open();
    fline(41, 41, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(41, 41, 0.25, 0, 'f', 'p', 40, "a5", 0);

    circle();

    fline(20,20,0.25,0,'f','s',50, "a2", 1);
    fw_x_right(320, 40, -40, 47, 30);
    
    fline(52,52,0.25,36,'n','s',50, "a2", 10); 
    fline(20,20,0.25,16,'n','s',50, "a2", 10);delay(200);    
    arm_close_up();
    
    bline(41, 41,0.25,40,'f','s',50, "a2", 5);
    bw_x_right(320, 40, -40, 123, 30);   
    
    circle();
    
    move_pid4(41, 41, 0.25, 'p', "a0", 0);  delay(50);
    fline(41, 41,0.25,0,'c','p',50, "a2",0); 
  }

void can_13()
  {
    arm_down_open();
    fline(41, 41, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(41, 41, 0.25, 0, 'f', 'p', 40, "a5", 0);

    circle();
    
    fline(52,52,0.25,20,'n','s',50, "a2", 10); 
    fline(20,20,0.25,18,'n','s',50, "a2", 20);delay(200);    
    arm_close_up();  
    fline(0,0,0.0,0,'n','l',40, "a2", 40);delay(200);
    fline(30,30,0.25,0,'c','s',50, "a2", 1); 
    
    circle();
    
    move_pid4(41, 41, 0.25, 'p', "a0", 0);  delay(50); 
    fline(41, 41,0.25,0,'c','p',50, "a2",0); 
    num_place_total = 15;
  }

void circle()
  {
    fline(30, 30, 0.25, 0, 'f', 'p', 40, "a5", 30);
    do{Motor(20, -10);}while(mcp_f(4) > md_mcp_f(4));

    move_pid4(30, 35, 0.65, 'p', "a7", 0);
    move_pid4(30, 35, 0.65, 'p', "a7", 20);

    Motor(30, -20);delay(100);
    do{Motor(30, -20);}while(mcp_f(7) > md_mcp_f(7));
    do{Motor(30, -20);}while(mcp_f(4) > md_mcp_f(4));
    Motor(-30, 20); delay(30);
    Motor(-1, -1); delay(50);
        
    move_pid4(30, 35, 0.65, 'p', "a7", 0);
    move_pid4(30, 35, 0.65, 's', "a7", 20);
    
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(20, 20); }while( encoder.Poss_L() < 100);
    Motor(-20, -20);delay(50);
    Motor(-1, -1); delay(100);  
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(30, -20); }while( encoder.Poss_L() < 150);
    do{ Motor(30, -20); }while( mcp_f(3) > md_mcp_f(3)); 
    Motor(-30, 20); delay(30);
    Motor(1, -1); delay(40); 

    
  }
void ut()
  {
    fline(30,30,0.25,0,'c','l',40, "a3", 1);
    fline(0,0,0.0,0,'n','l',40, "a3", 40);
  }
  
