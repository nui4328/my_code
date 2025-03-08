void rotate(float sp, int center, float setpoint)
  {  
    float P, I, D, previous_I, previous_error,errors, 
    PID_output, present_position, previous_integral;  
    float kp = sp/100;
    if(center > 10 )
      {
        if(setpoint < 0)
          {
            setpoint = setpoint+10;
          }
        else
          {
            setpoint = setpoint-10;
          }        
      }
    my.resetAngles();
    Serial.println(my.gyro('z'));  // แสดงค่าจาก Gyro
    while(1)
      {
        errors = setpoint - my.gyro('z');
        P = errors;
        I = I + errors;
        D = errors - previous_error;  
        PID_output = kp * P + 0.01 * I + 0.2 * D;                   
        previous_error = errors;

        // ควบคุมมอเตอร์ให้เคลื่อนที่และหมุน
        int leftSpeed = center + PID_output;   // ความเร็วมอเตอร์ซ้าย
        int rightSpeed = center - PID_output;  // ความเร็วมอเตอร์ขวา
    
        // จำกัดความเร็วให้อยู่ในช่วง -100 ถึง 100
        leftSpeed = constrain(leftSpeed, -100, 100);
        rightSpeed = constrain(rightSpeed, -100, 100);
    
        // ควบคุมมอเตอร์
        Motor(leftSpeed, rightSpeed);
        // ตรวจสอบว่าหมุนถึงมุมที่ต้องการหรือไม่
        if (abs(errors) < 5.0) {  // ถ้าความผิดพลาดน้อยกว่า 2 องศา
          if(setpoint > 0)
            {
              if(center < 10 )
                {
                  Motor(-10, 10); 
                  delay(20);
                  Motor(-1, -1); 
                }
              else
                {
                  Motor(-5, 5); 
                  delay(5);
                  Motor(-1, -1); 
                }
              
            }
          else
            {
              if(center < 10 )
                {
                  Motor(10, -10);
                  delay(20);
                  Motor(-1, -1);
                }
              else
                {
                  Motor(5, -5);
                  delay(5);
                  Motor(-1, -1); 
                }
              
            }
          break;                 // ออกจากลูป
        }
       delay(20);
      }
    
    
  }

void sw_st()
  {
    bz(100);bz(100);
    while(digitalRead(9) == 1)
      {
        Serial.print(my_tcs('r'));  // แสดงค่าจาก Gyro
        Serial.print("   "); 
        Serial.println(my.gyro('z'));  // แสดงค่าจาก Gyro
        delay(10);
        
      }

     bz(300);
  }
