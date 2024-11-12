void tour_2()
  {  
    co_xyz(50, 60, 10);
    servo(29, 60);
    servo(1, 60);
    fline_2sensor(30, 30, 0.25, 0, "3:4","a6", 'p', 1);
    Moohan(); //---->>จบเอาหมู 2 เดินเข้าไปวางในกรอบ 

    bline_2sensor(45, 45, 0.5, 35, "3:4","b6", 's', 1);  
    bline_2sensor(20, 20, 0.5, 0, "3:4","b6", 's', 40);  
    T_right_sensor_F(20, 4);    
    fline_2sensor(70, 70, 0.5, 65, "3:4","a1", 's', 5);
    fline_2sensor(20, 20, 0.5, 0, "3:4","a1", 's', 5);
    move_F_center(210);
    T_left_sensor_F(20, 3);
    servo(23, 80);delay(200);         
    fline_2sensor(20, 20, 0.35, 15, "3:4","a1", 's', 40);  //----->> เดินหน้าลงมาแล้วกลับตัว
    T_left_sensor_F(20, 3); 
    co_xyz(65, -45, 20);delay(100);    
    Sparn_pra(); //------>> หลังจากวางแล้วเดินถอยหลังขึ้นมา แล้วกลับหลังหัน

 
    fline_2sensor(20, 20, 0.35, 0, "3:4","a1", 's', 10);
    move_F_center(210);
    T_right_sensor_B(20, 6);
    bline_2sensor(20, 20, 0.35, 50, "5:6","27", 's', 20);
    Songnang(); //------>> หลังจากวางแล้วเดินออกมาหยุดตรงรถสามล้อ

    fline_2sensor(30, 30, 0.35, 0, "3:4","a1", 's', 5);
    move_F_center(220);
    do{Motor(-20,1);}while(mcp_b(5)>md_mcp_b(5));
    bline_2sensor(20, 20, 0.35, 25, "4:5","27", 's', 20);     
    Poonorom(); //------>> หลังจากงาวแล้วเดินออกมาเจอแยก แล้วหมุนซ้ายหันหน้าขึ้นมา
    
    fline_2sensor(40, 40, 0.35, 0, "3:4","a6", 's', 10);
    move_F_center(200);
    T_right_sensor_F(25, 3);
    fline_2sensor(20, 20, 0.35, 16, "2:3","a6", 's', 30);      
    Pooparterb();
       
    fline_2sensor(50, 50, 0.35, 30, "3:4","a1", 's', 1);
    fline_2sensor(20, 20, 0.35, 0, "3:4","a1", 's', 10);
    move_F_center(200);
    T_right_sensor_F(20, 3);
    fline_2sensor(20, 20, 0.35, 39, "2:3","a6", 's', 30);
    Market_home();
    
  }
