void tour_4()
  {
    co_xyz(50, 60, 10);
    servo(29, 60);
    servo(1, 60);
    fline_2sensor(50, 50, 0.35, 60, "3:4","a1", 's', 1);
    fline_2sensor(20, 20, 0.35, 0, "3:4","a1", 's', 20);
    move_F_center(220);
    do{Motor(-20,1);}while(mcp_b(5)>md_mcp_b(5));
    bline_2sensor(20, 20, 0.35, 25, "5:6","27", 's', 20);
    Poonorom(); //------>> หลังจากงาวแล้วเดินออกมาเจอแยก แล้วหมุนซ้ายหันหน้าขึ้นมา

    fline_2sensor(50, 50, 0.35, 30, "3:4","a1", 's', 1);
    fline_2sensor(20, 20, 0.35, 0, "3:4","a1", 's', 10);
    move_F_center(200);
    T_right_sensor_F(20, 3);
    Moohan();

    bline_2sensor(35, 35, 0.5, 0, "3:4","b6", 's', 35);    
    T_left_sensor_B(20, 3);    
    do{Motor(-20,20);}while(mcp_b(5)>md_mcp_b(5));
    Motor(20,-20);delay(30);
    bline_2sensor(35, 35, 0.5, 0, "5:6","26", 's', 25);
   
    fline_2sensor(20, 20, 0.35, 18, "2:3","a6", 's', 30);      
    Pooparterb();

    fline_2sensor(50, 50, 0.35, 40, "3:4","a1", 's', 50); 
    //fline_2sensor(20, 20, 0.35, 0, "3:4","a1", 'p', 20);     
    Sparn_pra(); //------>> หลังจากวางแล้วเดินถอยหลังขึ้นมา แล้วกลับหลังหัน

    fline_2sensor(20, 20, 0.35, 0, "3:4","a1", 's', 10);
    move_F_center(210);
    T_right_sensor_B(20, 6);
    bline_2sensor(20, 20, 0.35, 50, "5:6","27", 's', 20);
    Songnang(); //------>> หลังจากวางแล้วเดินออกมาหยุดตรงรถสามล้อ

    
    fline_2sensor(40, 40, 0.35, 0, "3:4","a6", 's', 10);
    move_F_center(220);
    do{Motor(20,1);}while(mcp_f(2)>md_mcp_f(2));
    fline_2sensor(20, 20, 0.35, 38, "2:3","a6", 's', 30);     
    Market_home();
  }
