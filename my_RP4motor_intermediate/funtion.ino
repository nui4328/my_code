void pid_F(int sl, int sr, float kp, int tm,  int ofset)
  {
     lasts_time = millis();
     //while(millis() - lasts_time < tm)  
     while(encoderPos_R < tm)      
        {
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (kp * P) + (0.00015 * I) + (kp* D); 
          
          Motor(sl - PID_output, sr + PID_output,sl - PID_output, sr + PID_output); 
                
       }
    if(ofset > 0)
       {
          Motor(-sl,-sr,-sl,-sr);delay(ofset);
          Motor(0,0,0,0);delay(200);
       }
     else
       {
        delay(50);
       }           
  }

void pid_B(int sl, int sr, float kp, int tm,  int ofset)
  {
     lasts_time = millis();
     while(encoderPos_R > tm)     
        {
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (kp * P) + (0.00015 * I) + (kp* D); 
          
          Motor(-(sl + PID_output), -(sr - PID_output), -(sl + PID_output), -(sr - PID_output));
                 
       }
    if(ofset > 0)
       {
          Motor(sl,sr,sl,sr);delay(ofset);
          Motor(0,0,0,0);delay(200);
       }
     else
       {
       }           
  }
void pid_R(int sl, int sr, float kp, int tm,  int ofset)
  {
     lasts_time = millis();
     while(millis() - lasts_time < tm)        
        {
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (kp * P) + (0.00015 * I) + (kp* D); 
          
          Motor(sl-PID_output, -(sr - PID_output),-(sl + PID_output), sr + PID_output);        
       }
    if(ofset > 0)
       {
          Motor(-sl,sr,sl,-sr);delay(ofset);
          Motor(0,0,0,0);delay(200);
       }
     else
       {
       }           
  }

void pid_L(int sl, int sr, float kp, int tm,  int ofset)
  {
     lasts_time = millis();
     while(millis() - lasts_time < tm)    
     //while(1)  
        {
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (kp * P) + (0.00015 * I) + (kp* D); 
          Motor(-(sl + PID_output), sr+PID_output, sl - PID_output, -(sr - PID_output));
               
       }
    if(ofset > 0)
       {
          Motor(sl,-sr,-sl,sr);delay(ofset);
          Motor(0,0,0,0);delay(200);
       }
     else
       {
       }           
  }

void encoder_cout()
  {
    String sen_en = String (encoderPos_R);  
    mydisplay_background(black);
    mydisplay(sen_en, 20, 30, 2, white);
  }
void display_error()
  {
         String sen_mpu = String (error_Yaw());
         String sen_en = String (encoderPos_R);    
         mydisplay_background(black);
         mydisplay("mpu "+ sen_mpu, 20, 10, 2, white);
         mydisplay("en "+ sen_en, 20, 40, 2, white);
  }
void sw_start()
  {
    bz(100);
    bz(100);
     while(digitalRead(9)==1)
        {

          //Serial.println(my_tcs('r'));
 
          String sen_0 = String (mcp_f(0));
          String sen_1 = String (mcp_f(1));
          String sen_2 = String (mcp_f(2));
          String sen_3 = String (mcp_f(3));
          String sen_4 = String (mcp_f(4));
          String sen_5 = String (mcp_f(5));
          String sen_6 = String (mcp_f(6));
          String sen_7 = String (mcp_f(7));  
          String en_R = String (encoderPos_R);  
          String en_L = String (encoderPos_L);
          mydisplay_background(black);
          mydisplay(sen_0 +" "+ sen_1+" "+"MPU", 10, 5, 2, white);
          mydisplay(sen_2 +" "+ sen_3+" "+ en_R, 10, 30, 2, white);
          mydisplay(sen_4 +" "+ sen_5+" "+ en_L, 10, 60, 2, white);
          Serial.print(mcp_f(6));
          Serial.print("  ");
          Serial.println(md_mcp_f(6));
         
            
        } 
     bz(300);
  }

void sw_start_n()
  {
    bz(100);
    bz(100);
     while(digitalRead(9)==1)
        {

          //Serial.println(my_tcs('r'));
           float red, green, blue;
           uint16_t r, g, b, c;
           tcss.getRawData(&r, &g, &b, &c);     
           float averag = (r+g+b)/3;
           red = r/averag; ;
           green = g/averag; 
           blue = b/averag;
 
          String sen_0 = String (mcp_f(0));
          String sen_1 = String (mcp_f(1));
          String sen_2 = String (mcp_f(2));
          String sen_3 = String (mcp_f(3));
          String sen_4 = String (mcp_f(4));
          String sen_5 = String (mcp_f(5));
          String sen_6 = String (mcp_f(6));
          String sen_7 = String (mcp_f(7));  
          String mpu = String (error_Yaw());  
          String sen_en = String (encoderPos_R);
          String reds = String (red);
          String greens = String (green);
          String blues = String (blue);
          mydisplay_background(black);
          mydisplay(sen_0 +" "+ sen_1+" "+"MPU", 10, 5, 2, white);
          mydisplay(sen_2 +" "+ sen_3+" "+ mpu, 10, 30, 2, white);
          mydisplay(reds +" "+ greens +" "+ blues, 10, 60, 1, white);
          Serial.print(mcp_f(6));
          Serial.print("  ");
          Serial.println(md_mcp_f(6));
         
            
        } 
     bz(300);
  }
void test_line_r()
  {
    encoderPos_R=0;
    while(encoderPos_R < 350)        
        {          
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (5 * P) + (0.00015 * I) + (5* D); 
          
          Motor(45-PID_output, -(45 - PID_output),-(45 + PID_output), 45 + PID_output); 
          
          if(mcp_f(6)<md_mcp_f(6))
            {
              Motor(-40,40,40,-40);delay(30);
              Motor(0,0,0,0);delay(200);  
              break;           
            }
        }
     while(digitalRead(9)==1)
        {

          //Serial.println(my_tcs('r'));
 
          String sen_mpu = String (error_Yaw());
          String sen_en = String (encoderPos_R);    
          mydisplay_background(black);
          mydisplay("mpu "+ sen_mpu, 20, 10, 2, white);
          mydisplay("en "+ sen_en, 20, 40, 2, white);
          Serial.print(mcp_f(6));
          Serial.print("  ");
          Serial.println(md_mcp_f(6));
         
            
        } 
     bz(300);
  }
