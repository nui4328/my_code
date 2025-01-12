void get_can()
  {     
     EEPROM.put(1100, readEEP_cans + 1 ); // บันทึก
     EEPROM.commit(); // ยืนยันการบันทึก
     delay(10);

    uint16_t readEEP_count_cans; // ประกาศ
    EEPROM.get(1100, readEEP_count_cans); // อ่านข้อมูลจาก EEPROM 
    delay(10);
    Serial.println(readEEP_count_cans);

    readEEP_cans = readEEP_count_cans;
  }
  
void read_eep()
  {
    uint16_t readEEP_count_cans; // ประกาศ
    EEPROM.get(1100, readEEP_count_cans); // อ่านข้อมูลจาก EEPROM 
    delay(10);
    Serial.println(readEEP_count_cans);

    readEEP_cans = readEEP_count_cans;
  }
  
void get_can_ree()
  {     
     EEPROM.put(1101, count_cans_ree); // บันทึก
     EEPROM.commit(); // ยืนยันการบันทึก
     delay(10);

    uint16_t readEEP_count_cansR; // ประกาศ
    EEPROM.get(1101, readEEP_count_cansR); // อ่านข้อมูลจาก EEPROM 
    delay(10);
    Serial.println(readEEP_count_cansR);

    readEEP_cans_ree = readEEP_count_cansR;
  }
