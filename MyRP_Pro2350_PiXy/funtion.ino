/*
void sw()
  {
    tone(32, 950, 100);
    delay(200); // รอ 1 วินาที
    tone(32, 950, 200);
    delay(200); // รอ 1 วินาที

    int buttonState;
    unsigned long pressStartTime = 0;
    bool isPressed = false;   

    while(1)
      {       
        if(digitalRead(19) == 0)
            {
              tone(32, 950, 100);
              delay(200); // รอ 1 วินาที
              get_maxmin_A();
            }
        if(digitalRead(12) == 0)
            {
              tone(32, 950, 100);
              delay(200); // รอ 1 วินาที
              get_maxmin_B();
            }
        Serial.print("From A ");
          for (int i = 0; i < 8; i++) {
            Serial.print(read_sensorA(i));  // ใช้ read_sensorA
            Serial.print(" ");
          }
          Serial.print("   ");
          
          // แสดงค่าจาก Nano 0x09
          Serial.print("From B ");
          for (int i = 0; i < 8; i++) {
            Serial.print(read_sensorB(i));  // ใช้ read_sensorB
            Serial.print(" ");
          }
          Serial.println("  ");
        // Serial.println(my_tcs('r'));
          
          delay(10);  // อัปเดตทุก 100ms
        Serial.println(" "); 
        buttonState = digitalRead(33);
        if (buttonState == LOW) 
          {  // ปุ่มถูกกด (LOW เพราะใช้ PULLUP)
            digitalWrite(rgb[2],0);
            if (!isPressed) \
              {
                pressStartTime = millis();  // บันทึกเวลาที่กดปุ่มครั้งแรก
                isPressed = true;
              } 
            else 
              {
                unsigned long pressDuration = millis() - pressStartTime;    
                if (pressDuration >= 3000) 
                  {  // กดค้าง 3 วินาที
                    tone(32, 950, 100);
                    delay(200); // รอ 1 วินาที
                    tone(32, 950, 200);
                    delay(200); // รอ 1 วินาที
                    Serial.println("Entering Mode A");
                    get_maxmin_C();
                    while (digitalRead(33) == LOW);  // รอให้ปล่อยปุ่ม
                    delay(200);  // ป้องกันการเด้งของปุ่ม
                  }
              }
          } 
        else 
          {
            if (isPressed) 
              {
                unsigned long pressDuration = millis() - pressStartTime;
                
                if (pressDuration >= 50 && pressDuration < 3000) 
                  {  
                    Serial.println("Entering Mode B");
                    break;
                  }
                isPressed = false;
              }
          }
      }
    tone(32, 950, 400);
    delay(500);
  }
*/
  void sw()
  {
    tone(32, 950, 100);
    delay(200); // รอ 1 วินาที
    tone(32, 950, 200);
    delay(200); // รอ 1 วินาที

    int buttonState;
    unsigned long pressStartTime = 0;
    bool isPressed = false;   
    bool isPressed_12 = false;  

    while(1)
      {       
        if(digitalRead(19) == 0)
            {
              digitalWrite(rgb[0],0);
              digitalWrite(rgb[1],0);
              digitalWrite(rgb[2],0);
              tone(32, 950, 100);
              delay(200); // รอ 1 วินาที
              get_maxmin_A();
              digitalWrite(rgb[0],0);
              digitalWrite(rgb[1],0);
              digitalWrite(rgb[2],1);
            }
        /*
        if(digitalRead(12) == 0)
            {
              digitalWrite(rgb[0],0);
              digitalWrite(rgb[1],0);
              digitalWrite(rgb[2],0);
              tone(32, 950, 100);
              delay(200); // รอ 1 วินาที
              get_maxmin_B();
              digitalWrite(rgb[0],0);
              digitalWrite(rgb[1],0);
              digitalWrite(rgb[2],1);
            }
        */
        Serial.print("From A ");
          for (int i = 0; i < 8; i++) {
            Serial.print(read_sensorA(i));  // ใช้ read_sensorA
            Serial.print(" ");
          }
          Serial.print("   ");
          
          // แสดงค่าจาก Nano 0x09
          Serial.print("From B ");
          for (int i = 0; i < 8; i++) {
            Serial.print(read_sensorB(i));  // ใช้ read_sensorB
            Serial.print(" ");
          }
          Serial.println("  ");
        // Serial.println(my_tcs('r'));
          
          delay(10);  // อัปเดตทุก 100ms
        Serial.println(" "); 
        buttonState = digitalRead(33);
        if (buttonState == LOW) 
          {  // ปุ่มถูกกด (LOW เพราะใช้ PULLUP)
            digitalWrite(rgb[2],0);
            if (!isPressed) \
              {
                pressStartTime = millis();  // บันทึกเวลาที่กดปุ่มครั้งแรก
                isPressed = true;
              } 
            else 
              {
                unsigned long pressDuration = millis() - pressStartTime;    
                if (pressDuration >= 3000) 
                  {  // กดค้าง 3 วินาที
                    tone(32, 950, 100);
                    delay(200); // รอ 1 วินาที
                    tone(32, 950, 200);
                    delay(200); // รอ 1 วินาที
                    digitalWrite(rgb[0],0);
                    digitalWrite(rgb[1],0);
                    digitalWrite(rgb[2],0);
                    Serial.println("Entering Mode A");
                    get_maxmin_C();
                    digitalWrite(rgb[0],0);
                    digitalWrite(rgb[1],0);
                    digitalWrite(rgb[2],1);
                    while (digitalRead(33) == LOW);  // รอให้ปล่อยปุ่ม
                    delay(200);  // ป้องกันการเด้งของปุ่ม
                  }
              }
          } 
        else 
          {
            if (isPressed) 
              {
                unsigned long pressDuration = millis() - pressStartTime;
                
                if (pressDuration >= 50 && pressDuration < 3000) 
                  {  
                    Serial.println("Entering Mode B");
                    break;                    
                  }
                isPressed = false;
              }
          }

        if (digitalRead(12) == 0) 
          {  // ปุ่มถูกกด (LOW เพราะใช้ PULLUP)
            digitalWrite(rgb[2],0);
            if (!isPressed_12) \
              {
                pressStartTime = millis();  // บันทึกเวลาที่กดปุ่มครั้งแรก
                isPressed_12 = true;
              } 
            else 
              {
                unsigned long pressDuration = millis() - pressStartTime;    
                if (pressDuration >= 3000) 
                  {  // กดค้าง 3 วินาที
                  tone(32, 950, 100);
                  delay(200); // รอ 1 วินาที
                  tone(32, 950, 200);
                  delay(200); // รอ 1 วินาที
                    digitalWrite(rgb[0],0);
                    digitalWrite(rgb[1],0);
                    digitalWrite(rgb[2],0);
                    storeColors(); // เรียกฟังก์ชันเก็บค่าสี กดปุ่ม GP33 ครั้งแรก สีแดง  ครั้งที่ 2 สีเขียว ครั้งที่ น้ำเงิน สีเหลือง และครั้งที่ 3 สีเหลือง
                    digitalWrite(rgb[0],0);
                    digitalWrite(rgb[1],0);
                    digitalWrite(rgb[2],1);
                    while(digitalRead(33) == 1)
                      {
                        searchColor();Serial.print("  ");delay(10);
                      }
                      tone(32, 950, 400);
                      delay(500);
                    while (digitalRead(12) == LOW);  // รอให้ปล่อยปุ่ม
                    delay(200);  // ป้องกันการเด้งของปุ่ม
                  }
              }
          } 
        else 
          {
            if (isPressed_12) 
              {
                unsigned long pressDuration = millis() - pressStartTime;
                
                if (pressDuration >= 50 && pressDuration < 3000) 
                  {  
                    digitalWrite(rgb[0],0);
                    digitalWrite(rgb[1],0);
                    digitalWrite(rgb[2],0);
                    tone(32, 950, 100);
                    delay(200); // รอ 1 วินาที
                    get_maxmin_B();
                    digitalWrite(rgb[0],0);
                    digitalWrite(rgb[1],0);
                    digitalWrite(rgb[2],1);
                  }
                isPressed_12 = false;
              }
          }
      }
    tone(32, 950, 400);
    delay(500);
  }
void swt()
  {
    tone(32, 950, 100);
    delay(200); // รอ 1 วินาที
    tone(32, 950, 200);
    delay(200); // รอ 1 วินาที
    while(digitalRead(33) == 1)
      {
        Serial.print("From Master 0x08: ");
        
          // แสดงค่าจาก Nano 0x08
          Serial.print("From Master 0x08: ");
          for (int i = 0; i < 8; i++) {
            Serial.print(read_sensorA(i));  // ใช้ read_sensorA
            Serial.print(" ");
          }
          Serial.print("   ");
          
          // แสดงค่าจาก Nano 0x09
          Serial.print("From Master 0x09: ");
          for (int i = 0; i < 8; i++) {
            Serial.print(read_sensorB(i));  // ใช้ read_sensorB
            Serial.print(" ");
          }
          Serial.println("  ");
        // Serial.println(my_tcs('r'));
          
          delay(10);  // อัปเดตทุก 100ms
          if(digitalRead(19) == 0)
            {
              tone(32, 950, 100);
              delay(200); // รอ 1 วินาที
              get_maxmin_A();
            }
          
      }
    tone(32, 950, 400);
    delay(500);
  }

