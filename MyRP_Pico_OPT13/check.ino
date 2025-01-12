void check_can()
  {
    uint16_t r, g, b, c;  
    tcss.getRawData(&r, &g, &b, &c);
    if(c > ch_collor_can)
      {
        ch_can = 1;
        //bz(50);
      }
    else
      {
        ch_can = 0;
        //bz(50);bz(50);
      }
  }

void check_floor()
  {
    if(mcp_f(0)>md_mcp_f(0))
      {
        ch_floor = 1;
        bz(100);
      }
    else
      {
        ch_floor = 0;
        bz(100);bz(100);
      }
  }
void check_can_to_floor()
  {
    if(none_13 == 1)
      {
        fline(50,50,0.25,0,'c','p',50, "a2", 0);
        fline(30,30,0.25,50,'n','s',50, "a2", 30);
         servo(8, servo_down+80);delay(200);
        sw();
      }
    if(ch_can == ch_floor)
      {
        place_left();
      }
    else
      {
        place_right();
      }
  }

int color_can()   //----->> คำสั่งตรวจสอบความส่วาง ใช้แยกสีขาวและดำ
  {
    uint16_t r, g, b, c;  
    tcss.getRawData(&r, &g, &b, &c);
  
    return c;
  }
