void Pooparterb()
  {
    servo(1, 65); servo(29, 65); 
    servo(23, 165);delay(200);
    co_xyz(75, -45, 20);delay(200);
    servo(29, 110);
    servo(1, 110);
    delay(300);
    co_xyz(45, 40, 10);
    bline_2sensor(25, 25, 0.5, 0, "4:5","26", 's', 30);
    T_right_sensor_F(30, 4);
    fline_2sensor(50, 50, 0.35, 40, "3:4","a1", 's', 1);
    fline_2sensor(25, 25, 0.35, 0, "3:4","a1", 's', 5);
    move_F_center(220);
    T_left_sensor_F(30, 4);
    
    fline_2sensor(35, 35, 0.35, 38, "5:6","a1", 's', 25); ////------------>> วิ่งไปวางอัน 1
    co_xyz(100, -35, 20);delay(100);
    servo(29, 60);
    co_xyz(100, 35, 10);
    fline_2sensor(25, 25, 0.4, 13, "5:6","a1", 's', 20);  ////------------>> วิ่งไปวางอัน 2
    co_xyz(110, -35, 20);delay(100);
    servo(1, 65);
    servo(29, 90);
    co_xyz(45, 40, 10);
    servo(29, 65);
    servo(1, 65);
    bline_2sensor(50, 50, 0.35, 35, "1:2","b0", 's', 1);
    bline_2sensor(30, 30, 0.35, 0, "1:2","b0", 's', 10);
    move_B_center();
    T_left_sensor_F(30, 4);     
  }

void Poonorom()
  {
    servo(1, 65); servo(29, 65); 
    servo(23, 165);delay(200);
    co_xyz(70, -45, 20);
    co_xyz(80, -45, 10);delay(200);
    servo(29, 110);
    servo(1, 110);
    delay(300);
    co_xyz(45, 40, 10);
    
    fline_2sensor(25, 25, 0.25, 0, "3:4","a1", 's', 10);
    move_F_center(220);
    T_right_sensor_F(30, 4);
    
    fline_2sensor(45, 45, 0.35, 0, "3:4","a1", 's', 5);
    move_F_center(220);
    //fline_2sensor(20, 20, 0.35, 0, "3:4","26", 's', 30);
    T_left_sensor_B(20, 3);
    bline_2sensor(25, 25, 0.35, 29, "1:2","a1", 's', 20); //------>>เดินวาง 1
    co_xyz(110, -35, 20);delay(100);
    servo(1, 60);
    co_xyz(105, 35, 10);
    bline_2sensor(25, 25, 0.35, 18, "1:2","a1", 's', 30);  //------>>เดินวาง 2
    co_xyz(110, -35, 10);delay(100);
    servo(1, 90);
    servo(29, 70);
    co_xyz(45, 40, 20);delay(100);
    servo(29, 65);
    servo(1, 65);
    fline_2sensor(45, 45, 0.5, 25, "5:6","a7", 's', 1);
    fline_2sensor(20, 20, 0.5, 0, "5:6","a7", 's', 5);
    move_F_center(220);
    T_left_sensor_F(30, 3);       
  }

void Songnang()
  {
    servo(1, 65); servo(29, 65);
    servo(23, 165);delay(100);
    co_xyz(72, -35, 30);
    co_xyz(90, -30, 10);delay(300);
    servo(29, 110);
    servo(1, 110);
    delay(300);
    co_xyz(70, 15, 10);
    co_xyz(35, 10, 10);
    do{Motor(-15,5);}while(mcp_f(7)>md_mcp_f(7));
    bw67(20, 20, 0.15,4, 1);   
    bw_encoder67(20, 20, 0.15, 185, 1);
    co_xyz(95, 15, 20); delay(200);  //------------>> ยื่นแขนออกไปวางห่วง 1

    for(int i=110; i>65; i--)
      {
        servo(1, i);//--------------->> หมุนวาง 2
        delay(10); 
      }
    co_xyz(35, 10, 30);
    
    bw67(20, 20, 0.25,27, 1);
    bw67(20, 20, 0.15,3, 1);
    co_xyz(95, 10, 20);delay(200);//------------>> ยื่นแขนออกไปวางห่วง 2 
    for(int i=110; i>65; i--)
      {
        servo(29, i);//--------------->> หมุนวาง 2
        delay(10); 
      }
    co_xyz(50, 10, 10);
    co_xyz(50, 95, 10);delay(300);
    Motor(-30, 30);
    delay(50);
    Motor(1, 1);
    fline(20,20,0.0,13,'n','s',50, "a2", 20);
    if(mcp_f(6)<md_mcp_f(6)-50 && mcp_f(4)>md_mcp_f(4) )
      {
        do{ Motor(20, 5); }while( mcp_f(4)> md_mcp_f(4));
      }
    else if(mcp_f(1)<md_mcp_f(1)-50 && mcp_f(3)>md_mcp_f(3) )
      {
        do{ Motor(5, 20); }while( mcp_f(3)> md_mcp_f(3));
      }
    fline_2sensor(25, 25, 0.5, 30, "3:4","26", 's', 5);
    //co_xyz(70, 85, 10);
    co_xyz(70, 45, 10);
    servo(29, 65);
    servo(1, 65);    
  }

void Moohan()
  {
    fline_2sensor(55, 55, 0.5, 60, "3:4","a1", 's', 1);
    fline_2sensor(30, 30, 0.5, 0, "3:4","a1", 's', 20);
    move_F_center(220);
    T_right_sensor_F(30, 3);
    servo(29, 40);delay(100);
    servo(1, 110);delay(100);  // ----->> servoขวาคีบเข้า
    fline_2sensor(15, 15, 0.5, 16, "2:3","26", 's', 30);
    servo(23, 165);delay(300);
    co_xyz(70, -35, 10);delay(100);
    servo(29, 110);
    servo(1, 110);
    delay(500);
    co_xyz(45, 40, 20);   ////------------------>> หมูตัวที่ 1
    T_left_sensor_F(20, 3);
    for(int i = 165; i > 80; i--)
      { 
        servo(23, i);
        delay(7);
      }
    co_xyz(76, -40, 20);
    fline_2sensor(20, 20, 0.35, 0, "2:3","a0", 'p', 0);
    fline_2sensor(20, 20, 0.35, 0, "2:3","a0", 's', 5);
    fline_2sensor(20, 20, 0.35, 0, "2:3","26", 's', 2);
    delay(200);
    servo(29, 60);
    co_xyz(50, -25, 20);
    co_xyz(70, 35, 20);delay(100);
    servo(1, 65);
    bline_2sensor(25, 25, 0.5, 5, "3:4","a1", 'p', 25);
    T_right_sensor_F(20, 3);
    
    fline_2sensor(20, 20, 0.5, 29, "2:3","26", 's', 30); ////------------------>> เดินหาหมูตัวที่ 2
    servo(29, 60);delay(100);
    servo(1, 110);delay(100);  // ----->> servoขวาคีบเข้า
    servo(23, 165);delay(500);
    co_xyz(70, -35, 20);delay(300);
    servo(29, 110);
    servo(1, 110);
    delay(500);
    servo(23, 118);delay(105);
    
    fline_2sensor(15, 15, 0.5, 0, "3:4","a1", 'p', 25);   ///----->> เดินเข้ากรอบ
    servo(29, 65);
    servo(1, 65);
    co_xyz(45, 40, 20);delay(100);
    
       
  }
  
void Sparn_pra()
  { 
    servo(1, 65); servo(29, 65);     
    servo(23, 80);delay(100);
    co_xyz(65, -45, 10);
    fline_2sensor(20, 20, 0.5, 0, "3:4","a1", 'p', 20);
    fline_2sensor(10, 10, 0.5, 0, "3:4","a1", 's', 20);
    servo(29, 110);
    servo(1, 110);
    delay(200);
    co_xyz(45, 40, 20);
    encoder.resetEncoders();
    while(encoder.Poss_L() < 500)
      {
        Motor(20, -25);  delayMicroseconds(50);  
      }
    do{ Motor(20, -25); }while( mcp_f(4) > min_mcp_f(4)+100);
    Motor(-30, 30); delay(50);
    Motor(-1, -1); delay(100);
    
    fline_2sensor(50, 50, 0.35, 40, "3:4","a1", 's', 1);
    fline_2sensor(20, 20, 0.35, 0, "3:4","a1", 'p', 15);
    fline_2sensor(20, 20, 0.35, 0, "3:4","a1", 's', 30);
    servo(23, 105);    //--------------->> หมุนวาง 1
    co_xyz(90, -45, 30);
    servo(29, 30);
    co_xyz(60, -25, 10);
    co_xyz(60, 35, 10);
    servo(29, 100);

    for(int i=105; i>63; i--)
      {
        servo(23, i);//--------------->> หมุนวาง 2
        delay(7); 
      }
    
    co_xyz(75, -45, 30);   
    servo(29, 100);
    servo(1, 50);
    bline_2sensor(20, 20, 0.35, 5, "3:4","a1", 's', 15);
    co_xyz(45, 40, 10);
    servo(29, 65);
    servo(1, 65);
    bline_2sensor(45, 45, 0.5, 30, "3:4","a7", 's', 25);
    
    T_left_sensor_F(30, 2);       
  }

void Market_home()
  {
    servo(23, 165);
    delay(500);
    co_xyz(80, -45, 20);delay(300);
    servo(29, 110);
    servo(1, 110);
    delay(200);
    co_xyz(45, 40, 20);
    fline_2sensor(40, 40, 0.5, 0, "1:2","a0", 's', 30);
    move_F_center(220);
    T_right_sensor_F(20, 2);
    //move_bed(80);
    fline_2sensor(40, 40, 0.5, 0, "2:3","a0", 's', 5);
    encoder.resetEncoders();
    while(encoder.Poss_L() < 660)
      {
        Motor(20, 23);  delayMicroseconds(50);  
      }
    Motor(-20, -20); delay(30);
    Motor(-1, -1); delay(100);
    co_xyz(70, -20, 20);delay(300); 
    servo(29, 80);
    servo(1, 80);
         
  }
