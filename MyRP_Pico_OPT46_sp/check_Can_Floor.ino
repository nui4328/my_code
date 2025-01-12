
void check_can_to_floor()
  {
    delay(10);
    if(check_color() == collor_floor[2])
      {
        place_left();
      }
    else if(check_color() == collor_floor[1])
      {
        place_center();
      }
    else
      {
        place_right();
      }
  }
