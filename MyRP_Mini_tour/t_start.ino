void start_game()
  {
    fline_2sensor(10, 10, 0.0, 0, "6:7","a7", 's', 5);
    fline_2sensor(10, 10, 0.5, 23, "5:6","a7", 's', 10);
    fline_2sensor(10, 10, 0.5, 10, "5:6","a7", 's', 10);delay(1000);
    fline_2sensor(10, 10, 0.5, 9, "5:6","a7", 's', 10);delay(1000);

    do{Motor(20, 10);}while(mcp_f(5) > md_mcp_f(5));
    fline_2sensor(30, 30, 0.75, 0, "4:5","a7", 's', 10);
    fline_2sensor(30, 30, 0.5, 0, "4:5","26", 's', 10);
    T_right_sensor_F(30, 4);
  }
