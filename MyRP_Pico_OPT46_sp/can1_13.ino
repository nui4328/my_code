void can_1()
  {
    arm_down_open();
    fline(30, 30, 0.25, 0, 'c', 'l', 40, "a2", 40);
    fline(52, 52, 0.25, 26,'n','s',50, "a2", 10);  //------>> เดินเข้ากล่องที่ 1
    fline(20, 20, 0.05, 14,'n','s',50, "a2", 10);delay(200);
    
    arm_close_up();
    
    bline(71, 71, 0.35, 27, 'c', 'l', 40, "a3", 40);   
  }

void can_2()
  {
    arm_down_open();
    fline(30, 30, 0.25, 0, 'c', 'r', 40, "a5", 40);
    fline(52, 52, 0.25, 26,'n','s',50, "a2", 10);  //------>> เดินเข้ากล่องที่ 1
    fline(20, 20, 0.05, 14,'n','s',50, "a2", 10);delay(200);
    
    arm_close_up();
    
    bline(71, 71, 0.35, 27, 'c', 'r', 40, "a4", 40);   
  }

void can_3()
  {
    arm_down_open();
    fline(30, 30, 0.25, 0, 'f', 'p', 40, "a2", 0);
    fline(61, 61,0.25,15,'f','s',50, "a2", 1);
    fw_x_left(300, -40, 40, 86, 30);
    fline(52, 52, 0.25, 26,'n','s',50, "a2", 10);  //------>> เดินเข้ากล่องที่ 1
    fline(20, 20, 0.05, 14,'n','s',50, "a2", 10);delay(200);
    
    arm_close_up();
    
    bline(61, 61,0.25,30,'f','s',50, "a2", 1);
    bw_x_left(330, -40, 40, 90, 40); 
    fline(61, 61,0.25,15,'f','p',50, "a2", 0); 
  }

void can_4()
  {
    arm_down_open();
    fline(30, 30, 0.25, 0, 'f', 'p', 40, "a2", 0);
    fline(61, 61,0.25,15,'f','s',50, "a2", 1);
    fw_x_right(300, 40, -40, 85, 30);
    fline(52, 52, 0.25, 26,'n','s',50, "a2", 10);  //------>> เดินเข้ากล่องที่ 1
    fline(20, 20, 0.05, 16,'n','s',50, "a2", 10);delay(200);
    
    arm_close_up();
    
    bline(61, 61,0.25,30,'f','s',50, "a2", 1);
    bw_x_right(330, 40, -40, 90, 40);  
    fline(61, 61,0.25,15,'f','p',50, "a2", 0); 
  }

void can_5()
  {
    arm_down_open();
    fline(30, 30, 0.25, 0, 'f', 'p', 40, "a2", 0);
    fline(61, 61,0.25,20,'f','s',50, "a2", 1);
    fw_x_left(320, -40, 40, 10, 1);
    fline(0,0,0.0,0,'n','l',50, "a2", 30);
    
    fline(52,52,0.25,34,'n','s',50, "a2", 10);
    fline(20,20,0.25,19,'n','s',50, "a2", 10);delay(200);  
      
    arm_close_up();    
    bline(61, 61,0.25,40,'f','s',50, "a2", 1);
    bw_x_left(320, -40, 40, 120, 30);
    fline(61, 61,0.25,0,'f','p',50, "a2", 0);
  }

void can_6()
  {
    arm_down_open();
    fline(61, 61,0.25,0,'f','p',50, "a2", 0);
    fline(61, 61,0.25,20,'f','s',50, "a2", 1);
    fw_x_right(320, 40, -40, 10, 1);
    fline(0,0,0.0,0,'n','r',50, "a5", 30);
    
    fline(52,52,0.25,36,'n','s',50, "a2", 5); 
    fline(20,20,0.25,15,'n','s',50, "a2", 10);delay(200);    
    arm_close_up();
    
    bline(61, 61,0.25,40,'f','s',50, "a2", 1);
    bw_x_right(320, 40, -40, 120, 30);
    fline(61, 61,0.25,0,'f','p',50, "a2",0);
      
  }

void can_7()
  {
    arm_down_open();
    fline(61, 61, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(61, 61, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(30, 30, 0.25, 0, 'f', 'p', 40, "a5", 30);
    do{Motor(-10, 20);}while(mcp_f(4) > md_mcp_f(4));
    
    fw_4sensor(40, 35, 0.75, 400, "a0", 0);
    fw_4sensor(40, 35, 0.75, 0, "27", 30);

    Motor(-20, 30);delay(100);
    do{Motor(-20, 30);}while(mcp_f(0) > md_mcp_f(0));
    do{Motor(-20, 30);}while(mcp_f(3) > md_mcp_f(3));
    Motor(20, -30); delay(30);
    Motor(-1, -1); delay(50);
    
    fline_2sensor(30, 30, 0.75, 0, "2:5","a0", 'p', 20);

    do{Motor(-15, 30);}while(mcp_f(0) > md_mcp_f(0));
    do{Motor(-15, 30);}while(mcp_f(3) > md_mcp_f(3));
    Motor(-10, 30); delay(20);
    Motor(-1, 1); delay(30);

    fline(40, 40, 0.25, 10,'n','s',50, "a2", 10); 
    fline(20,20,0.05,19,'n','s',50, "a2", 20);delay(200);    
    arm_close_up();

    bline(40, 40, 0.25, 0,'c','l',30, "a2", 20);
    fline_2sensor(35, 35, 0.65, 0, "2:5","a7", 's', 10);
    fline_2sensor(35, 35, 0.65, 0, "2:5","26", 's', 20);
    delay(30);
    do{Motor(30, -30);}while(mcp_f(7) > md_mcp_f(7));
    do{Motor(30, -30);}while(mcp_f(3) > md_mcp_f(3));
    Motor(-30, 30); delay(20);
    Motor(1, 1); delay(30);
    
     fw_4sensor(35, 40, 0.75, 750, "a7", 30);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(20, 20); }while( encoder.Poss_L() < 90);
    Motor(-20, -20);delay(50);
    Motor(-1, -1); delay(100);  
    //encoder.resetEncoders();   //----->> encoder = 0
    Motor(30, -10);
    delay(100); 
    do{ Motor(30, -10); }while( mcp_f(4) > md_mcp_f(4));
    Motor(-30, 10); delay(30);
    Motor(1, -1); delay(40);  
    
    fline_2sensor(35, 35, 0.35, 16, "2:5","a6", 's', 0);
    fline(62, 62, 0.35, 0,'f','p',50, "a2", 0);          
  }

void can_8()
  {
    arm_down_open();
    fline(61, 61, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(61, 61, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(30, 30, 0.25, 0, 'f', 'p', 40, "a5", 30);
    do{Motor(20, -10);}while(mcp_f(4) > md_mcp_f(4));
    fw_4sensor(35, 40, 0.75, 600, "a7",0);      
    fw_4sensor(35, 40, 0.75, 0, "26", 30);

    Motor(30, -15);delay(100);
    do{Motor(30, -20);}while(mcp_f(7) > md_mcp_f(7));
    do{Motor(30, -20);}while(mcp_f(3) > md_mcp_f(3));
    Motor(-30, 15); delay(20);
    Motor(1, 1); delay(30);

    fline_2sensor(30, 30, 0.75, 0, "2:5","a7", 'p', 20);

    Motor(30, -15);delay(100);
    do{Motor(30, -15);}while(mcp_f(7) > md_mcp_f(7));
    do{Motor(30, -15);}while(mcp_f(4) > md_mcp_f(4));
    Motor(-30, 15); delay(20);
    Motor(1, 1); delay(30);

    fline(40, 40, 0.25, 10,'n','s',50, "a2", 10); 
    fline(20,20,0.05,20,'n','s',50, "a2", 10);delay(200);    
    arm_close_up();

    bline(40, 40, 0.25, 0,'c','r',30, "a5", 20);
    fline_2sensor(30, 30, 0.75, 0, "2:5","a0", 's', 10);
    fline_2sensor(30, 30, 0.35, 0, "2:5","27", 's', 30);
    delay(30);
    
    do{Motor(-30, 30);}while(mcp_f(0) > md_mcp_f(0));
    do{Motor(-30, 30);}while(mcp_f(4) > md_mcp_f(4));
    Motor(30, -30);delay(20);
    Motor(-1, 1); delay(50);
    
    fw_4sensor(40, 35, 0.75, 500, "a0", 30);
    
    encoder.resetEncoders();   //----->> encoder = 0
    do{Motor(20, 20);}while( encoder.Poss_R() < 100);
    Motor(-20, -20);delay(40);
    Motor(-1, -1); delay(100);  
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(-10, 30); }while( encoder.Poss_R() < 330);
    Motor(10, -30); delay(30);
    Motor(-1, -1); delay(100);  
    
    fline_2sensor(35, 35, 0.35, 16, "2:5","a6", 's', 0);
    fline(62, 62, 0.35, 0,'f','p',50, "a2", 0);     
  }

void can_9()
  {
    arm_down_open();
    fline(61, 61, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(61, 61, 0.25, 0, 'f', 'p', 40, "a5", 0);

    circle();

    fline(20,20,0.25,0,'f','s',50, "a2", 1);
    fw_x_left(300, -40, 40, 86, 30);
    fline(52, 52, 0.25, 26,'n','s',50, "a2", 10);  //------>> เดินเข้ากล่องที่ 1
    fline(20, 20, 0.05, 14,'n','s',50, "a2", 15);delay(200);
    
    arm_close_up();
    
    bline(61, 61,0.25,30,'f','s',50, "a2", 1);
    bw_x_left(350, -40, 40, 89, 40); 

    circle();
    
    fline_2sensor(35, 35, 0.35, 16, "2:5","a6", 's', 0);
    fline(62, 62, 0.35, 0,'f','p',50, "a2", 0);   
    
  }

void can_10()
  {
    arm_down_open();
    fline(61, 61, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(61, 61, 0.25, 0, 'f', 'p', 40, "a5", 0);

    circle();

    fline(20,20,0.25,0,'f','s',50, "a2", 1);
    fw_x_right(300, 40, -40, 85, 30);
    fline(52, 52, 0.25, 26,'n','s',50, "a2", 10);  //------>> เดินเข้ากล่องที่ 1
    fline(20, 20, 0.05, 15,'n','s',50, "a2", 10);delay(200);
    
    arm_close_up();
    
    bline(61, 61,0.25,30,'f','s',50, "a2", 1);
    bw_x_right(330, 40, -40, 95, 40);   
    
    circle();
    
    fline_2sensor(35, 35, 0.35, 16, "2:5","a6", 's', 0);
    fline(62, 62, 0.35, 0,'f','p',50, "a2", 0);    
  }


void can_11()
  {
    arm_down_open();
    fline(61, 61, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(61, 61, 0.25, 0, 'f', 'p', 40, "a5", 0);

    circle();

    fline(20,20,0.25,0,'f','s',50, "a2", 1);
    fw_x_left(320, -40, 40, 47, 30);
    fline(52,52,0.25,34,'n','s',50, "a2", 10);
    fline(20,20,0.25,16,'n','s',50, "a2", 10);delay(200);    
    arm_close_up();    
    bline(61, 61,0.25,40,'f','s',50, "a2", 1);
    bw_x_left(320, -40, 40, 118, 30); 

    circle();
    
    fline_2sensor(35, 35, 0.35, 16, "2:5","a6", 's', 0);
    fline(62, 62, 0.35, 0,'f','p',50, "a2", 0);     
    
  }

void can_12()
  {
    arm_down_open();
    fline(61, 61, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(61, 61, 0.25, 0, 'f', 'p', 40, "a5", 0);

    circle();

    fline(20,20,0.25,0,'f','s',50, "a2", 1);
    fw_x_right(320, 40, -40, 47, 30);
    
    fline(52,52,0.25,36,'n','s',50, "a2", 10); 
    fline(20,20,0.25,16,'n','s',50, "a2", 10);delay(200);    
    arm_close_up();
    
    bline(61, 61,0.25,40,'f','s',50, "a2", 5);
    bw_x_right(320, 40, -40, 123, 30);   
    
    circle();
    
    fline_2sensor(35, 35, 0.35, 16, "2:5","a6", 's', 0);
    fline(62, 62, 0.35, 0,'f','p',50, "a2", 0);    
  }

void can_13()
  {
    arm_down_open();
    fline(61, 61, 0.25, 0, 'f', 'p', 40, "a5", 0);
    fline(61, 61, 0.25, 0, 'f', 'p', 40, "a5", 0);

    circle();
    
    fline(52,52,0.25,20,'n','s',50, "a2", 10); 
    fline(20,20,0.25,18,'n','s',50, "a2", 20);delay(200);    
    arm_close_up();  
    fline(0,0,0.0,0,'n','l',40, "a2", 40);delay(200);
    fline(30,30,0.25,0,'c','s',50, "a2", 1); 
    
    circle();
    
    fline_2sensor(35, 35, 0.35, 16, "2:5","a6", 's', 0);
    fline(62, 62, 0.35, 0,'f','p',50, "a2", 0);    
    num_place_total = 15;
  }

void circle()
  {
    fline_2sensor(30, 35, 0.75, 0, "2:5","a7", 'p', 30);
    do{Motor(20, -10);}while(mcp_f(4) > md_mcp_f(4));
    fw_4sensor(35, 40, 0.75, 600, "a7",0);      
    fw_4sensor(35, 40, 0.75, 0, "26", 30);

    Motor(30, -15);delay(100);
    do{Motor(30, -30);}while(mcp_f(7) > md_mcp_f(7));
    do{Motor(30, -30);}while(mcp_f(3) > md_mcp_f(3));
    Motor(-30, 15); delay(20);
    Motor(1, 1); delay(30);
    
    fw_4sensor(35, 40, 0.75, 750, "a7", 30);
    encoder.resetEncoders();   //----->> encoder = 0
    do{ Motor(20, 20); }while( encoder.Poss_L() < 80);
    Motor(-20, -20);delay(50);
    Motor(-1, -1); delay(100);  

    Motor(30, -20);
    delay(100); 
    do{ Motor(30, -20); }while( mcp_f(4) > md_mcp_f(4));
    Motor(-30, 20); delay(30);
    Motor(1, -1); delay(40);  
    
    
  }
void ut()
  {
    fline(30,30,0.25,0,'c','l',40, "a3", 1);
    fline(0,0,0.0,0,'n','l',40, "a3", 40);
  }
  
