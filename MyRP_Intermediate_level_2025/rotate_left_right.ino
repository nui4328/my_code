
void rotate_left(int sp, int targetPulses)
  {
    if(line_r == false)
      {
        targetPulses -= 100;
      }
    if(line_l == false)
      {
        targetPulses += 100;
      }
    if(lines == true)
      {
        if(lines_fw == true)
          {
            encoder.resetEncoders();
            do{Motor(-30, -30);}while(encoder.Poss_L() > -fw_to_rotate);
            Motor(30, 30); delay(30);
            Motor(-1, -1);
            delay(10); 
          }
        else
          {
            encoder.resetEncoders();
            do{Motor(30, 30);}while(encoder.Poss_L() < fw_to_rotate);
            Motor(-30, -30); delay(30);
            Motor(1, 1);
            delay(10); 
          }
      }
     else
      {
        Motor(1, 1);
        delay(10); 
      }
    encoder.resetEncoders();
    while(1)
      {
        // อ่านค่าจาก Encoder
        float leftPulses = -encoder.Poss_L();
        float rightPulses = encoder.Poss_R();

        // คำนวณระยะทางที่เคลื่อนที่แล้ว (เฉลี่ยจากล้อซ้ายและขวา)
        float currentPulses = (leftPulses + rightPulses) / 2;

        // ตรวจสอบว่าถึงเป้าหมายหรือยัง
        Motor(-sp, sp);
        if (currentPulses >= targetPulses) 
          {
            Motor(sp, -sp); delay(30);
          
            Motor(-1, -1); // หยุดมอเตอร์
            delay(50);
            break;       // ออกจากลูป
          }
      }
    line_l = true;
    line_r = true;
  }

///------------------------------------------------------------->>>

void rotate_right(int sp, int targetPulses)
  {
    if(line_r == false)
      {
        targetPulses += 100;
      }
    if(line_l == false)
      {
        targetPulses -= 100;
      }
    if(lines == true)
      {
        if(lines_fw == true)
          {
            encoder.resetEncoders();
            do{Motor(-30, -30);}while(encoder.Poss_L() > -fw_to_rotate);
            Motor(30, 30); delay(30);
            Motor(-1, -1);
            delay(10); 
          }
        else
          {
            encoder.resetEncoders();
            do{Motor(30, 30);}while(encoder.Poss_L() < fw_to_rotate);
            Motor(-30, -30); delay(30);
            Motor(1, 1);
            delay(10); 
          }
      }
     else
      {
        Motor(1, 1);
        delay(10); 
      }
    encoder.resetEncoders();
    while(1)
      {
        // อ่านค่าจาก Encoder
        float leftPulses = encoder.Poss_L();
        float rightPulses = -encoder.Poss_R();

        // คำนวณระยะทางที่เคลื่อนที่แล้ว (เฉลี่ยจากล้อซ้ายและขวา)
        float currentPulses = (leftPulses + rightPulses) / 2;
        Motor(sp, -sp);
        if (currentPulses >= targetPulses) 
          {
            Motor(-sp, sp); delay(40);
          
            Motor(-1, -1); // หยุดมอเตอร์
            delay(50);
            break;       // ออกจากลูป
          }
      }
    line_l = true;
    line_r = true;
  }
