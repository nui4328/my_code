void Pooparterb()
  {
    servo(23, 172);delay(500);
    co_xyz(75, -45, 20);delay(300);
    servo(29, 120);
    servo(1, 120);
    delay(500);
    co_xyz(45, 40, 20);
    bline_2sensor(25, 25, 0.5, 0, "5:6","26", 's', 30);
    T_right_sensor_F(30, 4);
    fline_2sensor(45, 45, 0.5, 0, "3:4","a1", 'p', 5);
    fline_2sensor(25, 25, 0.5, 0, "3:4","a1", 's', 20);
    T_left_sensor_F(30, 3);
    fline_2sensor(35, 45, 0.5, 35, "3:4","a1", 's', 20); ////------------>> วิ่งไปวางอัน 1
    co_xyz(100, -45, 20);delay(200);
    servo(29, 60);
    co_xyz(100, 35, 20);delay(200);
    fline_2sensor(25, 25, 0.5, 16, "4:5","a1", 's', 20);  ////------------>> วิ่งไปวางอัน 2
    co_xyz(105, -45, 20);delay(200);
    servo(1, 75);
    servo(29, 90);
    co_xyz(45, 40, 20);delay(200);
    servo(29, 75);
    servo(1, 75);
    bline_2sensor(35, 35, 0.5, 0, "3:4","b1", 's', 30);
    move_B_center();
    T_left_sensor_F(30, 3);       
  }

void Poonorom()
  {
    servo(23, 172);delay(500);
    co_xyz(70, -45, 20);delay(300);
    servo(29, 120);
    servo(1, 120);
    delay(500);
    co_xyz(45, 40, 20);
    fline_2sensor(25, 25, 0.5, 0, "1:2","26", 's', 30);
    T_right_sensor_F(30, 4);
    fline_2sensor(45, 45, 0.5, 0, "3:4","a1", 'p', 5);
    fline_2sensor(45, 45, 0.5, 0, "3:4","a1", 's', 5);
    fline_2sensor(45, 45, 0.5, 0, "3:4","26", 's', 20);
    T_left_sensor_B(20, 2);
    bline_2sensor(25, 25, 0.5, 28, "1:2","a1", 's', 20); //------>>เดินวาง 1
    co_xyz(100, -45, 20);delay(200);
    servo(1, 60);
    co_xyz(100, 35, 20);delay(100);
    bline_2sensor(25, 25, 0.5, 18, "1:2","a1", 's', 20);  //------>>เดินวาง 2
    co_xyz(100, -45, 20);delay(200);
    servo(1, 90);
    servo(29, 70);
    co_xyz(45, 40, 20);delay(100);
    servo(29, 75);
    servo(1, 75);
    fline_2sensor(35, 35, 0.5, 0, "5:6","a7", 's', 5);
    move_F_center();
    T_left_sensor_F(30, 3);       
  }

void Songnang()
  {
    servo(23, 172);delay(500);
    co_xyz(70, -45, 20);
    co_xyz(80, -30, 20);delay(100);
    servo(29, 120);
    servo(1, 120);
    delay(300);
    co_xyz(70, 15, 20);delay(100);
    co_xyz(35, 10, 20);
    bline_2sensor(25, 25, 0.5, 0, "5:6","26", 's', 40);
    co_xyz(75, 5, 20); delay(300);  //------------>> ยื่นแขนออกไปวางห่วง 1
    servo(1, 75);delay(100);
    co_xyz(35, 10, 20);delay(300);
    bline(20,20,0.0,12,'n','s',20, "a2", 20); 
    co_xyz(80, 5, 20);delay(300);//------------>> ยื่นแขนออกไปวางห่วง 1
    servo(29, 75);delay(100);
    co_xyz(50, 115, 20);delay(300);
    fline(20,20,0.0,15,'n','s',50, "a2", 20);
    if(mcp_f(6)<md_mcp_f(6)-50 && mcp_f(4)>md_mcp_f(4) )
      {
        do{ Motor(20, 5); }while( mcp_f(4)> md_mcp_f(4));
      }
    else if(mcp_f(1)<md_mcp_f(1)-50 && mcp_f(3)>md_mcp_f(3) )
      {
        do{ Motor(5, 20); }while( mcp_f(3)> md_mcp_f(3));
      }
    fline_2sensor(25, 25, 0.5, 40, "3:4","26", 's', 5);
    co_xyz(70, 115, 20);
    co_xyz(70, 95, 20);
    co_xyz(70, 35, 20);
    servo(29, 75);
    servo(1, 75);    
  }
void Moohan()
  {
    fline_2sensor(40, 40, 0.5, 0, "3:4","a1", 's', 1);
    fline_2sensor(15, 15, 0.0, 0, "3:4","26", 's', 30);
    T_right_sensor_F(20, 2);
    servo(29, 60);delay(100);
    servo(1, 120);delay(100);  // ----->> servoขวาคีบเข้า
    fline_2sensor(15, 15, 0.5, 17, "2:3","26", 's', 30);
    servo(23, 172);delay(500);
    co_xyz(70, -45, 20);delay(300);
    servo(29, 120);
    servo(1, 120);
    delay(500);
    co_xyz(45, 40, 20);   ////------------------>> หมูตัวที่ 1
    T_left_sensor_F(20, 3);
    servo(23, 80);
    co_xyz(76, -40, 20);
    fline_2sensor(20, 20, 0.5, 0, "2:3","a6", 's', 10);
    fline_2sensor(20, 20, 0.5, 0, "3:4","26", 's', 5);

    servo(29, 60);
    co_xyz(50, -25, 20);
    co_xyz(70, 35, 20);delay(100);
    servo(1, 75);
    bline_2sensor(25, 25, 0.5, 5, "3:4","a1", 'p', 25);
    T_right_sensor_F(30, 3);
    
    fline_2sensor(20, 20, 0.5, 32, "2:3","26", 's', 30); ////------------------>> เดินหาหมูตัวที่ 2
    servo(29, 60);delay(100);
    servo(1, 120);delay(100);  // ----->> servoขวาคีบเข้า
    servo(23, 172);delay(500);
    co_xyz(70, -45, 20);delay(300);
    servo(29, 120);
    servo(1, 120);
    delay(500);
    servo(23, 105);delay(100);
    
    fline_2sensor(15, 15, 0.5, 0, "3:4","a1", 's', 25);   ///----->> เดินเข้ากรอบ
    servo(29, 75);
    servo(1, 75);
    co_xyz(45, 40, 20);delay(100);
    
       
  }
  
void Sparn_pra()
  {    
    servo(23, 80);delay(200);
    co_xyz(70, -45, 20);delay(100);
    fline_2sensor(10, 10, 0.5, 0, "3:4","a1", 's', 20);
    servo(29, 120);
    servo(1, 120);
    delay(300);
    co_xyz(45, 40, 20);

    encoder.resetEncoders();
    while(encoder.Poss_L() < 600)
      {
        Motor(20, -20);  delayMicroseconds(50);  
      }
    do{ Motor(20, -20); }while( mcp_f(4) > min_mcp_f(4)+100);
    Motor(-20, 20); delay(30);
    Motor(-1, -1); delay(100);
    
    
    fline_2sensor(30, 30, 0.35, 0, "3:4","a1", 'p', 15);
    fline_2sensor(10, 10, 0.35, 0, "3:4","a1", 's', 15);delay(100);
    servo(23, 105);    //--------------->> หมุนวาง 1
    co_xyz(80, -45, 20);delay(400);
    servo(29, 30);
    co_xyz(60, -25, 20);
    co_xyz(60, 35, 20);delay(100);
    servo(29, 100);delay(200);
    servo(23, 71);//--------------->> หมุนวาง 1
    co_xyz(75, -45, 20);delay(400);    
    servo(29, 100);
    servo(1, 50);
    co_xyz(50, -25, 20);
    co_xyz(45, 40, 20);delay(100);
    servo(29, 75);
    servo(1, 75);
    bline_2sensor(35, 35, 0.5, 45, "3:4","a7", 's', 25);
    
    T_left_sensor_F(30, 3);       
  }

void Market_home()
  {
    servo(23, 172);delay(500);
    co_xyz(70, -45, 20);delay(300);
    servo(29, 120);
    servo(1, 120);
    delay(200);
    co_xyz(45, 40, 20);
    fline_2sensor(40, 40, 0.5, 0, "1:2","a0", 's', 1);
    fline_2sensor(20, 20, 0.5, 0, "2:3","26", 's', 30);
    T_right_sensor_F(20, 2);
    //move_bed(80);
    fline_2sensor(40, 40, 0.5, 0, "2:3","a0", 's', 5);
    encoder.resetEncoders();
    while(encoder.Poss_R() < 710)
      {
        Motor(20, 20);  delayMicroseconds(50);  
      }
    Motor(-20, -20); delay(30);
    Motor(-1, -1); delay(100);
    co_xyz(70, -20, 20);delay(300); 
    servo(29, 100);
    servo(1, 100);
         
  }
