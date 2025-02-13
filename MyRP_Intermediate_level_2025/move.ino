void move_fw(int spl, int spr, int targetDistanceCm, String _line) 
  {
    char lr ;
    lines_fw = true; 
    if(set_bb == "set_bb")
      {
        targetDistanceCm = targetDistanceCm + 10;
      }

    encoder.resetEncoders();
    if (spl > 60 && targetDistanceCm > 50) 
      {
        for (int speed = 10; speed <= spl; speed += 2) 
          {
              Motor(speed, spr * speed / spl);
              delay(10);
          }
      }

    // คำนวณจำนวนพัลส์เป้าหมายจากระยะทาง
    float targetPulses = targetDistanceCm * pulsesPerCm;
      
    while (true) 
      {
        // อ่านค่าจาก Encoder
        float leftPulses = encoder.Poss_L();
        float rightPulses = encoder.Poss_R();

        // คำนวณระยะทางที่เคลื่อนที่แล้ว (เฉลี่ยจากล้อซ้ายและขวา)
        float currentPulses = (leftPulses + rightPulses) / 2;
        float remainingPulses = targetPulses - currentPulses;

        // **ค่อยๆ ลดความเร็วเมื่อเหลือระยะ 20% ของเป้าหมาย**
        if (remainingPulses <= targetPulses * 0.2) {  
            int slowSpeed = map(remainingPulses, 0, targetPulses * 0.25, 20, spl);
            spl = slowSpeed;
            spr = slowSpeed;
        }

        // **หยุดเมื่อถึงเป้าหมาย**
        if (currentPulses >= targetPulses) {
            break;
        }

        Motor(spl, spr);
        if (mcp_f(0) < md_mcp_f(0) - 30 && mcp_f(3) > md_mcp_f(3)) 
          {
              line_l = false;
              Motor(spl, -20);
          } 
          else if (mcp_f(0) > md_mcp_f(0) && mcp_f(3) < md_mcp_f(3) - 30) 
          {
              line_r = false;
              Motor(-20, spr);
          } 
          else if (mcp_f(0) < md_mcp_f(0) && mcp_f(3) < md_mcp_f(3) - 30) 
          {     
              Motor(-40, -40);
              delay(30);
              Motor(-1, -1);
              delay(100);           
              break;
          }
     }

   if(_line == "line")
      {  
        while(1)      
           {    
              Motor(motor_slow, motor_slow);        
              if(mcp_f(0) < md_mcp_f(0)-30 && mcp_f(3) > md_mcp_f(3))
                  {                    
                    Motor(40, -10);
                  }
              else if(mcp_f(0) > md_mcp_f(0) && mcp_f(3) < md_mcp_f(3)-30)
                  {
                    Motor(-10, 40);
                  }
              else if(mcp_f(1) < md_mcp_f(1) || mcp_f(2) < md_mcp_f(2))
                  {
                    Motor(-40, -40); delay(20);  
                    Motor(-1, -1);delay(10);  
                    while(1)
                      {
                        if(mcp_f(1) < md_mcp_f(1) && mcp_f(2) > md_mcp_f(2)) 
                          {
                            lr = 'l';
                             Motor(-10, 30);        
                          }
                        else if(mcp_f(1) > md_mcp_f(1) && mcp_f(2) < md_mcp_f(2))
                          {
                            lr = 'r';
                            Motor(30, -10);           
                          }
                        else if(mcp_f(0) < md_mcp_f(0) && mcp_f(3) < md_mcp_f(3)
                              || mcp_f(1) < md_mcp_f(1) && mcp_f(2) < md_mcp_f(2))
                          {   
                            if(lr == 'l')
                              {
                                Motor(15, -15);delay(20);
                                Motor(1, -1);delay(10);
                                Motor(0, 0); delay(10);
                                break; 
                              }
                            if(lr == 'r')
                              {
                                Motor(-15, 15);delay(20);
                                Motor(-1, 1);delay(10);
                                Motor(0, 0); delay(10);
                                break; 
                              }
                             else
                              {
                                Motor(-15, -15);delay(20);
                                Motor(1, 1);delay(10);
                                Motor(0, 0); delay(10);
                                break;
                              }            
                          }
                         else
                          {
                            Motor(motor_slow, motor_slow);
                          }
                        }                  
                      break;                  
                      
                  }                  
          }
  
        lines = true;         
                           
      } 
    else
      {
        Motor(-1, -1);
        delay(50);
        lines = false;
      }   
}


void move_fw_none(int spl, int spr, int targetDistanceCm, String _line) 
  {
    char lr ;
    lines_fw = true; 
    if(set_bb == "set_bb")
      {
        targetDistanceCm = targetDistanceCm + 10;
      }

    encoder.resetEncoders();
    if (spl > 60 && targetDistanceCm > 50) 
      {
        for (int speed = 10; speed <= spl; speed += 2) 
          {
              Motor(speed, spr * speed / spl);
              delay(10);
          }
      }

    // คำนวณจำนวนพัลส์เป้าหมายจากระยะทาง
    float targetPulses = targetDistanceCm * pulsesPerCm;
      
    while (true) 
      {
        // อ่านค่าจาก Encoder
        float leftPulses = encoder.Poss_L();
        float rightPulses = encoder.Poss_R();

        // คำนวณระยะทางที่เคลื่อนที่แล้ว (เฉลี่ยจากล้อซ้ายและขวา)
        float currentPulses = (leftPulses + rightPulses) / 2;
        float remainingPulses = targetPulses - currentPulses;

        // **ค่อยๆ ลดความเร็วเมื่อเหลือระยะ 20% ของเป้าหมาย**
        if (remainingPulses <= targetPulses * 0.2) {  
            int slowSpeed = map(remainingPulses, 0, targetPulses * 0.25, 20, spl);
            spl = slowSpeed;
            spr = slowSpeed;
        }

        // **หยุดเมื่อถึงเป้าหมาย**
        if (currentPulses >= targetPulses) {
            break;
        }

        Motor(spl, spr);
        
     }

   if(_line == "line")
      {  
        while(1)      
           {    
              Motor(motor_slow, motor_slow);        
              if(mcp_f(0) < md_mcp_f(0)-30 && mcp_f(3) > md_mcp_f(3))
                  {                    
                    Motor(40, -10);
                  }
              else if(mcp_f(0) > md_mcp_f(0) && mcp_f(3) < md_mcp_f(3)-30)
                  {
                    Motor(-10, 40);
                  }
              else if(mcp_f(1) < md_mcp_f(1) || mcp_f(2) < md_mcp_f(2))
                  {
                    Motor(-40, -40); delay(20);  
                    Motor(-1, -1);delay(10);  
                    while(1)
                      {
                        if(mcp_f(1) < md_mcp_f(1) && mcp_f(2) > md_mcp_f(2)) 
                          {
                            lr = 'l';
                             Motor(-10, 30);        
                          }
                        else if(mcp_f(1) > md_mcp_f(1) && mcp_f(2) < md_mcp_f(2))
                          {
                            lr = 'r';
                            Motor(30, -10);           
                          }
                        else if(mcp_f(0) < md_mcp_f(0) && mcp_f(3) < md_mcp_f(3)
                              || mcp_f(1) < md_mcp_f(1) && mcp_f(2) < md_mcp_f(2))
                          {   
                            if(lr == 'l')
                              {
                                Motor(15, -15);delay(20);
                                Motor(1, -1);delay(10);
                                Motor(0, 0); delay(10);
                                break; 
                              }
                            if(lr == 'r')
                              {
                                Motor(-15, 15);delay(20);
                                Motor(-1, 1);delay(10);
                                Motor(0, 0); delay(10);
                                break; 
                              }
                             else
                              {
                                Motor(-15, -15);delay(20);
                                Motor(1, 1);delay(10);
                                Motor(0, 0); delay(10);
                                break;
                              }            
                          }
                         else
                          {
                            Motor(motor_slow, motor_slow);
                          }
                        }                  
                      break;                  
                      
                  }                  
          }
  
        lines = true;         
                           
      } 
    else
      {
        Motor(-1, -1);
        delay(50);
        lines = false;
      }   
}
void move_bw(int spl, int spr, int targetDistanceCm, String _line) 
  {
    char lr ;
    lines_fw = true; 
    encoder.resetEncoders();
    if (spl > 60 && targetDistanceCm > 50) 
      {
        for (int speed = 10; speed <= spl; speed += 2) 
          {
              Motor(-speed, -(spr * speed / spl));
              delay(10);
          }
      }

    // คำนวณจำนวนพัลส์เป้าหมายจากระยะทาง
    float targetPulses = targetDistanceCm * pulsesPerCm;
    while (true) 
      {
        // อ่านค่าจาก Encoder
        float leftPulses = encoder.Poss_L();
        float rightPulses = encoder.Poss_R();

        // คำนวณระยะทางที่เคลื่อนที่แล้ว (เฉลี่ยจากล้อซ้ายและขวา)
        float currentPulses = (leftPulses + rightPulses) / 2;
        float remainingPulses = targetPulses - currentPulses;

         if (remainingPulses <= targetPulses * 0.2) {  
            int slowSpeed = map(remainingPulses, 0, targetPulses * 0.25, 20, spl);
            spl = -slowSpeed;
            spr = -slowSpeed;
        }

        if (currentPulses <= -targetPulses) 
          {
            break;       // ออกจากลูป
          }
        
        Motor(-spl, -spr);
        if(mcp_f(7) < md_mcp_f(7) && mcp_f(4) > md_mcp_f(4))
              {
                Motor(-spl, 20);
              }
        else if(mcp_f(7) > md_mcp_f(7) && mcp_f(4) < md_mcp_f(4))
              {
                Motor(20, -spr);
              }
        
        else if( mcp_f(6) < md_mcp_f(6))
              {
                Motor(40, 40); delay(30);
                Motor(1, 1);
                delay(100);           
                break;
              }
     }

   if(_line == "line")
      {  
        while(1)      
           {    
                      
              if(mcp_f(4) < md_mcp_f(4)-30 && mcp_f(7) > md_mcp_f(7))
                  {
                    Motor(10, -40);
                  }
              else if(mcp_f(4) > md_mcp_f(4) && mcp_f(7) < md_mcp_f(7)-30)
                  {
                    Motor(-40, 10);
                  }
              else if( mcp_f(5) < md_mcp_f(5) || mcp_f(6) < md_mcp_f(6))
                  {
                    while(1)
                      {
                          if(mcp_f(5) < md_mcp_f(5) && mcp_f(6) > md_mcp_f(6))
                              {
                                Motor(-40, 10);
                              }
                          else if(mcp_f(5) > md_mcp_f(5) && mcp_f(6) < md_mcp_f(6))
                              {
                                Motor(10, -40);
                              }
                          else
                              {
                                Motor(20, 20); delay(10);  
                                Motor(-1, -1);delay(100);
                                Motor(0, 0);delay(10); 
                                break; 
                              }
                      }
                                       
                    break;                  
                  }  
              else
                 {
                   Motor(-motor_slow, -motor_slow);              
                 }
          }
        lines = true;
        delay(10);
        Motor(1, 1);
        delay(10);
      }  
    else
      {
        
        Motor(1, 1);
        delay(50);
        lines = false;
      }  
}
