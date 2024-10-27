
void tour_1()
  {
    ///------------->>  ภูผาเทิบ
    fline_2sensor(50, 50, 0.35, 0, "3:4","a6", 'p', 10);
    fline_2sensor(30, 30, 0.35, 20, "3:4","a6", 's', 30);
    delay(1000);// --->> เก็บต้นข้าวน้าว 
    bline_2sensor(30, 30, 0.35, 0, "3:4","26", 's', 50);
    T_right_sensor_F(30, 4);
    fline_2sensor(50, 50, 0.35, 0, "3:4","a6", 's', 5);
    move_F_center();
    T_left_sensor_F(30, 3);

    fline_2sensor(30, 30, 0.35, 40, "3:4","a6", 's', 30); //----->> หยุดตรงจุดที่ 1
    
    delay(1000);// --->> วางต้นข้าวน้าว ต้นที่1

    fline_2sensor(30, 30, 0.35, 30, "3:4","a6", 's', 30); //----->> หยุดตรงจุดที่ 1
    
    delay(1000);// --->> วางต้นข้าวน้าว ต้นที่1
    bline_2sensor(40, 40, 0.35, 0, "3:4","b6", 's', 5);
    move_B_center();
    T_left_sensor_F(30, 3);
    ///------------------------------------------------- พระใหญ่ภูวโนรมย์
    
    

    fline_2sensor(50, 50, 0.35, 0, "3:4","a6", 's', 5);
    move_F_center();
    T_right_sensor_B(30, 3);

    bline_2sensor(20, 20, 0.35, 25, "3:4","27", 's', 20);
    
    delay(1000);// --->> เก็บธุป

    fline_2sensor(50, 50, 0.35, 0, "3:4","a6", 's', 5);
    move_F_center();
    T_right_sensor_F(30, 3);
    fline_2sensor(50, 50, 0.35, 0, "3:4","a6", 's', 5);
    move_F_center();
    T_left_sensor_F(30, 4);

    bline(40,40,0.85,20,'n','s',50, "a2", 10); //----->> เก็บ
    
    delay(1000);// --->> วางธูป ต้นที่1

    bline(40,40,0.85,30,'n','s',50, "a2", 10); //----->> เก็บ
    
    delay(1000);// --->> วางธูป ต้นที่2
    fline_2sensor(52, 52, 0.35, 0, "3:4","a6", 's', 5);
    move_F_center();
    T_left(30, 85);

    //////////////////------------------------ วัดศรีมงคลใต้เจ้าแม่สองนาง
    
    fline_2sensor(50, 50, 0.35, 0, "3:4","a6", 's', 5);
    move_F_center();
    
    T_right_sensor_B(30, 3);

    bline_2sensor(20, 20, 0.35, 50, "3:4","27", 's', 20);
    
    delay(1000);// --->> เก็บธุป
    bline(52, 52,0.85,15,'f','s',40, "a2", 10);
    delay(1000);// --->> วางธูป ต้นที่1

    bline(20,20,0.0,20,'n','s',50, "a2", 20); //----->> เก็บ
    
    delay(1000);// --->> วางธูป ต้นที่2
    fline(20,20,0.0,15,'n','s',50, "a2", 20);
    if(mcp_f(6)<md_mcp_f(6)-50 && mcp_f(4)>md_mcp_f(4) )
      {
        do{ Motor(20, 5); }while( mcp_f(4)> md_mcp_f(4));
      }
    else if(mcp_f(1)<md_mcp_f(1)-50 && mcp_f(3)>md_mcp_f(3) )
      {
        do{ Motor(5, 20); }while( mcp_f(3)> md_mcp_f(3));
      }

    ///-------------------------------ชมวิวแม่น้ำโขง
    fline_2sensor(50, 50, 0.35, 0, "3:4","a6", 's', 5);
    move_F_center();
    delay(1000);// --->> เก็บปลา
    T_right_sensor_F(30, 3);
    fline_2sensor(50, 50, 0.35, 0, "3:4","a6", 's', 5);
    move_F_center();
    

    delay(1000);// --->> วางปลา

    ///----------------------------หมูหัน
    bline_2sensor(50, 50, 0.35, 0, "3:4","b6", 's', 5);
    move_B_center();
    T_left_sensor_F(30, 4);
    fline_2sensor(50, 50, 0.35, 0, "3:4","a6", 's', 5);
    move_F_center();
    T_right_sensor_F(30, 3);
    fline_2sensor(40, 40, 0.35, 20, "3:4","26", 's', 30);
    servo(8, 178);
    delay(1000);// --->> เก็บหมู
    bline_2sensor(30, 30, 0.35, 0, "3:4","b1", 's', 5); //----->> เก็บ
    move_B_center();
    T_left_sensor_B(30, 4);
    delay(1000);// --->> วางหมูที่แก่งกะเบา

    //-----------------> เก็บหมูกลับบ้าน
    T_right_sensor_F(30, 4);
    fline_2sensor(40, 40, 0.35, 30, "3:4","26", 's', 30);
    delay(1000);// --->> เก็บหมู
    fline_2sensor(40, 40, 0.35, 0, "3:4","a6", 's', 30);
    delay(1000);// --->> เก็บหมู

    //-----------------------------ตลาดอินโดจีน

     bline_2sensor(40, 40, 0.35, 0, "3:4","b1", 's', 5); //----->> เก็บ
     move_B_center();
     T_right_sensor_F(30, 3);
     fline_2sensor(40, 40, 0.35, 70, "3:4","26", 's', 30);
     delay(1000);// --->> เก็บ
     bline_2sensor(40, 40, 0.25, 0, "3:4","b6", 's', 30);
     move_B_center();
     T_left_sensor_F(30, 4);
     fline_2sensor(50, 50, 0.35, 40, "3:4","a6", 's', 3);
     encoder.resetEncoders();
      while(encoder.Poss_R() < 600)
        {
          Motor(15, 20);  delayMicroseconds(50);  
        }
      Motor(-20, -20); delay(30);
      Motor(-1, -1); delay(100);
     
     
    
    
    
    
    
    
  }
