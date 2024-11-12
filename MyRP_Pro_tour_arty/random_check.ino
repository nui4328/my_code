void out_box()
  {  
    fline_2sensor(15, 15, 0.0, 0, "6:7","a7", 's', 5);
    fw_encoder67(15 , 15, 0.15, 615, 30);
    co_xyz(85, -15, 10);delay(1000);
    if(analogRead(28) > 2000 )
      {
        random_tour[0] = 1 ;
      }
    else 
      {
        random_tour[0] = 0 ;
      }
    delay(100);
    fw_encoder67(15 , 15, 0.15, 240, 30);delay(200);
    if(analogRead(28) > 2000 )
      {
        random_tour[1] = 1 ;
      }
    else 
      {
        random_tour[1] = 0 ;
      }
    delay(100);
    fw_encoder67(15 , 15, 0.15, 230, 30);delay(200);
    if(analogRead(28) > 2000 )
      {
        random_tour[2] = 1 ;
      }
    else 
      {
        random_tour[2] = 0 ;
      }
    delay(100);
    servo(1, 80);
    servo(29, 75);
    co_xyz(50, 70, 10);
    fw_encoder67(20 , 20, 0.15, 360, 30);
    place_right_in(20, 100);
    if(mcp_f(3) > mcp_f(3) && mcp_f(4) < mcp_f(4))
      {
        do{Motor(15, -15);}while(mcp_f(3) > mcp_f(3));
        Motor(-15, 15); delay(20);
        Motor(-1, -1); delay(20);
      }
    else if(mcp_f(2) > mcp_f(2) && mcp_f(1) < mcp_f(1))
      {
        do{Motor(-15, 15);}while(mcp_f(2) > mcp_f(2));
        Motor(15, -15); delay(20);
        Motor(-1, -1); delay(20);
      }
    delay(100);
    
    if(random_tour[2] == 1 && random_tour[1] == 1 && random_tour[0] == 1)
      {
        tour_1();
      }
    else if(random_tour[2] == 1 && random_tour[1] == 1 && random_tour[0] == 0)
      {
        tour_2();
      }
    else if(random_tour[2] == 1 && random_tour[1] == 0 && random_tour[0] == 1)
      {
        tour_3();
      }
    else if(random_tour[2] == 1 && random_tour[1] == 0 && random_tour[0] == 0)
      {
        tour_4();
      }
    else if(random_tour[2] == 0 && random_tour[1] == 1 && random_tour[0] == 1)
      {
        tour_5();
      }
      
    servo(29, 65);
    servo(1, 65);
      
  }
