void tour_4()
  {
    fline_2sensor(30, 30, 0.35, 0, "3:4","a1", 's', 50);
    move_F_center();
    do{Motor(-20,1);}while(mcp_b(5)>md_mcp_b(5));
    bline_2sensor(20, 20, 0.35, 28, "5:6","27", 's', 20);
    Poonorom(); //------>> หลังจากงาวแล้วเดินออกมาเจอแยก แล้วหมุนซ้ายหันหน้าขึ้นมา

    fline_2sensor(40, 40, 0.35, 0, "3:4","a1", 's', 5);
    fline_2sensor(20, 20, 0.35, 0, "3:4","26", 's', 50);
    T_right_sensor_F(20, 3);
    Moohan();////---------------------------->>>

    bline_2sensor(35, 35, 0.5, 0, "3:4","b6", 's', 40);    
    T_left_sensor_B(20, 5);    
    bline_2sensor(35, 35, 0.5, 0, "5:6","26", 's', 35);
    fline_2sensor(20, 20, 0.35, 18, "1:2","a6", 's', 30);      
    Pooparterb();

    servo(23, 80);delay(200);
    co_xyz(70, -35, 20);delay(100);
    fline_2sensor(40, 40, 0.35, 0, "3:4","a1", 's', 50); 
    fline_2sensor(20, 20, 0.35, 0, "3:4","a1", 'p', 20);     
    Sparn_pra(); //------>> หลังจากวางแล้วเดินถอยหลังขึ้นมา แล้วกลับหลังหัน

    fline_2sensor(20, 20, 0.35, 0, "3:4","a6", 'p', 10);
    fline_2sensor(20, 20, 0.35, 0, "3:4","a6", 's', 30);
    T_right_sensor_B(20, 6);
    bline_2sensor(20, 20, 0.35, 52, "5:6","27", 's', 20); 
    Songnang(); //------>> หลังจากวางแล้วเดินออกมาหยุดตรงรถสามล้อ

    
    fline_2sensor(40, 40, 0.35, 0, "3:4","a6", 's', 10);
    move_F_center();
    do{Motor(20,1);}while(mcp_f(2)>md_mcp_f(2));
    fline_2sensor(20, 20, 0.35, 40, "2:3","a6", 's', 30);     
    Market_home();
  }
