void add__pitch(int num) {
    Motor(30, 30);delay(100); bz(50);
    // เก็บค่ามุม Pitch 200 ครั้ง
    for (int i = 0; i < num; i++) {
        Motor(30, 30);
        _pitch[i] = readPitch(); 
        delayMicroseconds(50); 
    }
    Motor(-1, -1);
    delay(100);

    // คำนวณค่า Max และ Min
    uint16_t maxPitch = _pitch[0];
    uint16_t minPitch = _pitch[0];
    for (int i = 0; i < num; i++) {
        maxPitch = max(_pitch[i], maxPitch);
        minPitch = min(_pitch[i], minPitch);
    }
    max_Pitch = maxPitch;
    min_Pitch = minPitch;

    Serial.print("Val0 --> ");
    Serial.print(maxPitch);
    Serial.print(" ");
    Serial.println(minPitch);

    // บันทึกค่า Max ลงใน EEPROM
    EEPROM.put(401, max_Pitch);
    EEPROM.commit();
    delay(10);

    // อ่านค่าจาก EEPROM เพื่อตรวจสอบ
    int data_max_Pitch;
    EEPROM.get(401, data_max_Pitch);
    delay(1);

    // แสดงข้อมูลบนหน้าจอ
    char buffer[16];
    mydisplay_background(black);
    sprintf(buffer, "min  %d", min_Pitch);
    mydisplay(buffer, 25, 5, 2, white);
    sprintf(buffer, "max  %d", max_Pitch);
    mydisplay(buffer, 25, 25, 2, white);
    sprintf(buffer, "data %d", data_max_Pitch);
    mydisplay(buffer, 25, 45, 2, white);
}


void get_eepPitch()
  {
      int data_max_Pitch;
      EEPROM.get(401, data_max_Pitch); // read data from EEPROM address 0    
      delay(1);
      eep_pitch = data_max_Pitch;
      String Pitch = (String) max_Pitch;
      String Pitch_L = (String) min_Pitch;
      String data_max = (String) data_max_Pitch;
      
      mydisplay_background(black);
      mydisplay("min  "+Pitch_L, 25, 5, 2, white);
      mydisplay("max  "+Pitch, 25, 25, 2, white);
      mydisplay("data "+data_max, 25, 45, 2, white);
  }
