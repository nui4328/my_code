String check_color()    //------------->> ตวจสอบสี
  {
    uint16_t r, g, b, c;  
    // อ่านค่าจากเซ็นเซอร์
    tcss.getRawData(&r, &g, &b, &c);
  
    // เรียกใช้ฟังก์ชันตรวจสอบสี
    float R_ratio = (float)r / c;
    float G_ratio = (float)g / c;
    float B_ratio = (float)b / c;
  
    // เรียกใช้ฟังก์ชันตรวจสอบสี
  
    //String color = identifyColors(R_ratio, G_ratio, B_ratio);
    Serial.print("R_ratio: "); Serial.print(R_ratio);
    Serial.print(" G_ratio: "); Serial.print(G_ratio);
    Serial.print(" B_ratio: "); Serial.print(B_ratio);
   
     if (R_ratio > G_ratio && R_ratio > B_ratio && R_ratio - G_ratio > 0.25) 
        {
          Serial.println("red");
          //bz(50);
          return "red";          
        }
        // เปรียบเทียบเพื่อระบุสีเขียว
    else if (G_ratio > R_ratio && G_ratio > B_ratio && G_ratio - R_ratio > 0.05) 
        {
          Serial.println("green");
          //bz(50);bz(50);
          return "green";
        }
        // เปรียบเทียบเพื่อระบุสีน้ำเงิน
    else if (B_ratio > R_ratio && B_ratio > G_ratio, B_ratio - R_ratio > 0.2) 
        {
          Serial.println("blue");
          return "blue";
        }
        // เปรียบเทียบเพื่อระบุสีเหลือง
    else if (R_ratio > B_ratio && G_ratio > B_ratio &&  G_ratio - B_ratio > 0.12) 
       {
          Serial.println("yellow");
          //bz(50);bz(50); bz(50);
          return "yellow";
        }
    else {
          Serial.println("Unknown");
          return "Unknown";
        }
  }
