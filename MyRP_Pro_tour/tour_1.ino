void tour_1()
  {  
   
    fline_2sensor(40, 40, 0.35, 0, "2:3","a6", 'p', 10);
    fline_2sensor(20, 20, 0.35, 25, "1:2","a6", 's', 30);
    Pooparterb();
    
    fline_2sensor(40, 40, 0.35, 0, "3:4","a6", 'p', 10);
    fline_2sensor(20, 20, 0.35, 0, "3:4","a6", 's', 30);
    T_right_sensor_B(20, 6);
    bline_2sensor(20, 20, 0.35, 29, "5:6","27", 's', 20);
    Poonorom();

    fline_2sensor(40, 40, 0.35, 0, "3:4","a6", 'p', 10);
    fline_2sensor(20, 20, 0.35, 0, "3:4","a6", 's', 30);
    T_right_sensor_B(20, 6);
    bline_2sensor(20, 20, 0.35, 52, "5:6","27", 's', 20);
    Songnang();
   
    fline_2sensor(40, 40, 0.35, 0, "3:4","a1", 'p', 2);
    fline_2sensor(20, 20, 0.35, 0, "3:4","26", 's', 30);
    T_right_sensor_F(20, 4);
    fline_2sensor(20, 20, 0.35, 15, "3:4","a1", 's', 40);
    T_left_sensor_F(20, 3);
    fline_2sensor(20, 20, 0.35, 0, "3:4","a1", 'p', 20);      
    Sparn_pra();

    fline_2sensor(20, 20, 0.35, 0, "3:4","26", 's', 50);
    T_right_sensor_F(20, 3);
    Moohan();

    bline_2sensor(35, 35, 0.5, 0, "3:4","b6", 's', 40);    
    T_left_sensor_B(20, 5);    
    bline_2sensor(25, 25, 0.5, 74, "5:6","26", 's', 25);
    Market_home();
    
  }
