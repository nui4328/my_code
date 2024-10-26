
void co_xyz(float co_y, float co_z, int sp) 
  {  
    float co_x = 0;
    const float L1sq = sq(ROBOT_ARM_LOW);
    const float L2sq = sq(ROBOT_ARM_HIGH);
    float rrot_ee = hypot(co_x, co_y);
    float rrot =  rrot_ee - ROBOT_ARM_EE_OFFSET;
    float rside = hypot(rrot, co_z);
    float RSsq = sq(rside);
  
    rot = acos(co_x/ rrot_ee);  
    high = PI - acos((L1sq + L2sq - RSsq) / (2 * ROBOT_ARM_LOW * ROBOT_ARM_HIGH));    
    if (co_z > 0) 
      {
        low =  acos(co_z / rside) - acos((L1sq - L2sq + RSsq) / (2 * ROBOT_ARM_LOW * rside));
      } 
    else 
      {
        low = PI - asin(rrot / rside) - acos((L1sq - L2sq + RSsq) / (2 * ROBOT_ARM_LOW * rside));
      }
  
    high = high + low;
   // Serial.print(degrees(rot));
   // Serial.print(" ");
    //Serial.print(90+degrees(low));
    //Serial.print(" ");
   //Serial.println(180-degrees(high));
    theta1 = degrees(rot);
    theta2 = (90+degrees(low));
    theta3 = (180-degrees(high))+18;

    Serial.print(degrees(rot));
    Serial.print(" ");
    Serial.print(theta2);
    Serial.print(" ");
    Serial.println(theta3);
    //servo(8, theta2);
    //servo(23, theta3);
    
     float servo8_step = (theta1 - s8_before_deg) / num_steps;
     float servo0_step = (theta2 - s0_before_deg) / num_steps;
     float servo1_step = (theta3 - s1_before_deg) / num_steps;

      for (int i = 0; i < num_steps; i++) 
        {
          float servo8_pos = s8_before_deg + (i * servo8_step);
          float servo0_pos = s0_before_deg + (i * servo0_step);
          float servo1_pos = s1_before_deg + (i * servo1_step);
          servo(8, servo8_pos);
          servo(0, servo0_pos);
          servo(1, servo1_pos);
          
          delay(sp);
        }
     s8_before_deg = theta1;
     s0_before_deg = theta2;
     s1_before_deg = theta3;
  }
