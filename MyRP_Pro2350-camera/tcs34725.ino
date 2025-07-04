

void writeEEPROM(uint16_t address, uint16_t data) {
  Wire.beginTransmission(EEPROM_ADDR);
  Wire.write((uint8_t)(address >> 8));   // MSB
  Wire.write((uint8_t)(address & 0xFF)); // LSB
  Wire.write((uint8_t)(data >> 8));      // MSB of data
  Wire.write((uint8_t)(data & 0xFF));   // LSB of data
  Wire.endTransmission();
  delay(5); // รอการเขียนข้อมูล
}

// ฟังก์ชันสำหรับอ่านข้อมูล 16 บิตจาก CAT24C128
uint16_t readEEPROM(uint16_t address) {
  Wire.beginTransmission(EEPROM_ADDR);
  Wire.write((uint8_t)(address >> 8));   // MSB
  Wire.write((uint8_t)(address & 0xFF)); // LSB
  Wire.endTransmission();
  Wire.requestFrom(EEPROM_ADDR, 2);
  uint16_t data = (Wire.read() << 8) | Wire.read();
  return data;
}

// ฟังก์ชันสำหรับเก็บชุดค่าสีแดง (R, G, B)
void saveRed() {
  uint16_t r = my_tcs('r');
  uint16_t g = my_tcs('g');
  uint16_t b = my_tcs('b');
  writeEEPROM(RED_SET_ADDR, r);
  writeEEPROM(RED_SET_ADDR + 2, g);
  writeEEPROM(RED_SET_ADDR + 4, b);
  Serial.println("Stored Red Color Set (R, G, B): " + String(r) + ", " + String(g) + ", " + String(b));
}

// ฟังก์ชันสำหรับเก็บชุดค่าสีเขียว (R, G, B)
void saveGreen() {
  uint16_t r = my_tcs('r');
  uint16_t g = my_tcs('g');
  uint16_t b = my_tcs('b');
  writeEEPROM(GREEN_SET_ADDR, r);
  writeEEPROM(GREEN_SET_ADDR + 2, g);
  writeEEPROM(GREEN_SET_ADDR + 4, b);
  Serial.println("Stored Green Color Set (R, G, B): " + String(r) + ", " + String(g) + ", " + String(b));
}

// ฟังก์ชันสำหรับเก็บชุดค่าสีน้ำเงิน (R, G, B)
void saveBlue() {
  uint16_t r = my_tcs('r');
  uint16_t g = my_tcs('g');
  uint16_t b = my_tcs('b');
  writeEEPROM(BLUE_SET_ADDR, r);
  writeEEPROM(BLUE_SET_ADDR + 2, g);
  writeEEPROM(BLUE_SET_ADDR + 4, b);
  Serial.println("Stored Blue Color Set (R, G, B): " + String(r) + ", " + String(g) + ", " + String(b));
}

// ฟังก์ชันสำหรับเก็บชุดค่าสีเหลือง (R, G, B)
void saveYellow() {
  uint16_t r = my_tcs('r');
  uint16_t g = my_tcs('g');
  uint16_t b = my_tcs('b');
  writeEEPROM(YELLOW_SET_ADDR, r);
  writeEEPROM(YELLOW_SET_ADDR + 2, g);
  writeEEPROM(YELLOW_SET_ADDR + 4, b);
  Serial.println("Stored Yellow Color Set (R, G, B): " + String(r) + ", " + String(g) + ", " + String(b));
}

// ฟังก์ชันสำหรับเก็บค่าสีทั้งสี่สีโดยใช้ปุ่ม
void storeColors() {

  currentState = RED; // เริ่มที่ RED
  while(digitalRead(33) == 1)
    {
       Serial.println("Mode: Store Red color. Press button to capture.");
       digitalWrite(rgb[0],0);
      digitalWrite(rgb[1],0);
      digitalWrite(rgb[2],1);
    }  
  
  while (currentState != SEARCH) {
    static int lastButtonState = HIGH;
    int buttonState = digitalRead(33);
    
    if (lastButtonState == HIGH && buttonState == LOW) {
      delay(50); // Debounce
      if (digitalRead(33) == LOW) {
        switch (currentState) {
          case RED:
            saveRed();
            currentState = GREEN;
            Serial.println("Mode: Store Green color. Press button to capture.");
            digitalWrite(rgb[0],0);
                                digitalWrite(rgb[1],1);
                                digitalWrite(rgb[2],0);
            break;
          case GREEN:
            saveGreen();
            currentState = BLUE;
            Serial.println("Mode: Store Blue color. Press button to capture.");
            digitalWrite(rgb[0],1);
                                digitalWrite(rgb[1],0);
                                digitalWrite(rgb[2],0);
            break;
          case BLUE:
            saveBlue();
            currentState = YELLOW;
            Serial.println("Mode: Store Yellow color. Press button to capture.");
            digitalWrite(rgb[0],0);
                                digitalWrite(rgb[1],1);
                                digitalWrite(rgb[2],1);
            break;
          case YELLOW:
            saveYellow();
            currentState = SEARCH;
            colorsStored = true;
            Serial.println("All colors stored. Starting color search.");
            for(int i = 0; i<2; i++)
    {
      for(int i = 0; i<3; i++)
        {
          digitalWrite(rgb[i],1);
          delay(150);
          digitalWrite(rgb[i],0);
          delay(150);
        }
    }
  digitalWrite(rgb[2],1);
            break;
        }
      }
    }
    lastButtonState = buttonState;
    
    // แสดงค่าสีที่ตรวจจับได้แบบเรียลไทม์
    uint16_t r = my_tcs('r');
    uint16_t g = my_tcs('g');
    uint16_t b = my_tcs('b');
  }
}

// ฟังก์ชันสำหรับคำนวณระยะห่าง Euclidean ใน RGB space
float compareColors(uint16_t r1, uint16_t g1, uint16_t b1, uint16_t r2, uint16_t g2, uint16_t b2) {
  return sqrt(pow((int32_t)r1 - r2, 2) + pow((int32_t)g1 - g2, 2) + pow((int32_t)b1 - b2, 2));
}

// ฟังก์ชันสำหรับค้นหาและแสดงผลสีที่ใกล้เคียงที่สุด (เฉพาะชื่อสี)
void searchColor() {
  uint16_t r = my_tcs('r');
  uint16_t g = my_tcs('g');
  uint16_t b = my_tcs('b');
  
  // อ่านค่าสีจาก EEPROM
  uint16_t red_r = readEEPROM(RED_SET_ADDR);
  uint16_t red_g = readEEPROM(RED_SET_ADDR + 2);
  uint16_t red_b = readEEPROM(RED_SET_ADDR + 4);
  
  uint16_t green_r = readEEPROM(GREEN_SET_ADDR);
  uint16_t green_g = readEEPROM(GREEN_SET_ADDR + 2);
  uint16_t green_b = readEEPROM(GREEN_SET_ADDR + 4);
  
  uint16_t blue_r = readEEPROM(BLUE_SET_ADDR);
  uint16_t blue_g = readEEPROM(BLUE_SET_ADDR + 2);
  uint16_t blue_b = readEEPROM(BLUE_SET_ADDR + 4);
  
  uint16_t yellow_r = readEEPROM(YELLOW_SET_ADDR);
  uint16_t yellow_g = readEEPROM(YELLOW_SET_ADDR + 2);
  uint16_t yellow_b = readEEPROM(YELLOW_SET_ADDR + 4);
  
  // ตรวจสอบว่าค่าสีใน EEPROM มีความสมเหตุสมผล
  bool validRed = (red_r != 0 || red_g != 0 || red_b != 0);
  bool validGreen = (green_r != 0 || green_g != 0 || green_b != 0);
  bool validBlue = (blue_r != 0 || blue_g != 0 || blue_b != 0);
  bool validYellow = (yellow_r != 0 || yellow_g != 0 || yellow_b != 0);
  
  if (!validRed || !validGreen || !validBlue || !validYellow) {
    Serial.println("Error: Some colors not stored properly in EEPROM!");
    return;
  }
  
  // คำนวณระยะห่าง
  float distRed = compareColors(r, g, b, red_r, red_g, red_b);
  float distGreen = compareColors(r, g, b, green_r, green_g, green_b);
  float distBlue = compareColors(r, g, b, blue_r, blue_g, blue_b);
  float distYellow = compareColors(r, g, b, yellow_r, yellow_g, yellow_b);
  
  // แสดงเฉพาะชื่อสีที่ใกล้เคียงที่สุด
  if (distRed <= distGreen && distRed <= distBlue && distRed <= distYellow) {
    Serial.println("Red");
    tcs_color = "Red";
    digitalWrite(rgb[0],0);
    digitalWrite(rgb[1],0);
    digitalWrite(rgb[2],1);
  } else if (distGreen <= distRed && distGreen <= distBlue && distGreen <= distYellow) {
    Serial.println("Green");
    tcs_color = "Green";
    digitalWrite(rgb[0],0);
    digitalWrite(rgb[1],1);
    digitalWrite(rgb[2],0);
  } else if (distBlue <= distRed && distBlue <= distGreen && distBlue <= distYellow) {
    Serial.println("Blue");
    tcs_color = "Blue";
    digitalWrite(rgb[0],1);
    digitalWrite(rgb[1],0);
    digitalWrite(rgb[2],0);
  } else {
    Serial.println("Yellow");
    tcs_color = "Yellow";
    digitalWrite(rgb[0],0);
    digitalWrite(rgb[1],1);
    digitalWrite(rgb[2],1);
  }
}
void get_color_tcs() {
  uint16_t r = my_tcs('r');
  uint16_t g = my_tcs('g');
  uint16_t b = my_tcs('b');
  
  // อ่านค่าสีจาก EEPROM
  uint16_t red_r = readEEPROM(RED_SET_ADDR);
  uint16_t red_g = readEEPROM(RED_SET_ADDR + 2);
  uint16_t red_b = readEEPROM(RED_SET_ADDR + 4);
  
  uint16_t green_r = readEEPROM(GREEN_SET_ADDR);
  uint16_t green_g = readEEPROM(GREEN_SET_ADDR + 2);
  uint16_t green_b = readEEPROM(GREEN_SET_ADDR + 4);
  
  uint16_t blue_r = readEEPROM(BLUE_SET_ADDR);
  uint16_t blue_g = readEEPROM(BLUE_SET_ADDR + 2);
  uint16_t blue_b = readEEPROM(BLUE_SET_ADDR + 4);
  
  uint16_t yellow_r = readEEPROM(YELLOW_SET_ADDR);
  uint16_t yellow_g = readEEPROM(YELLOW_SET_ADDR + 2);
  uint16_t yellow_b = readEEPROM(YELLOW_SET_ADDR + 4);
  
  // ตรวจสอบว่าค่าสีใน EEPROM มีความสมเหตุสมผล
  bool validRed = (red_r != 0 || red_g != 0 || red_b != 0);
  bool validGreen = (green_r != 0 || green_g != 0 || green_b != 0);
  bool validBlue = (blue_r != 0 || blue_g != 0 || blue_b != 0);
  bool validYellow = (yellow_r != 0 || yellow_g != 0 || yellow_b != 0);
  
  if (!validRed || !validGreen || !validBlue || !validYellow) {
    Serial.println("Error: Some colors not stored properly in EEPROM!");
    return;
  }
  
  // คำนวณระยะห่าง
  float distRed = compareColors(r, g, b, red_r, red_g, red_b);
  float distGreen = compareColors(r, g, b, green_r, green_g, green_b);
  float distBlue = compareColors(r, g, b, blue_r, blue_g, blue_b);
  float distYellow = compareColors(r, g, b, yellow_r, yellow_g, yellow_b);
  
  // แสดงเฉพาะชื่อสีที่ใกล้เคียงที่สุด
  if (distRed <= distGreen && distRed <= distBlue && distRed <= distYellow) {
    Serial.println("Red");
    tcs_color = "red";
    digitalWrite(rgb[0],0);
    digitalWrite(rgb[1],0);
    digitalWrite(rgb[2],1);
  } else if (distGreen <= distRed && distGreen <= distBlue && distGreen <= distYellow) {
    Serial.println("Green");
    tcs_color = "green";
    digitalWrite(rgb[0],0);
    digitalWrite(rgb[1],1);
    digitalWrite(rgb[2],0);
  } else if (distBlue <= distRed && distBlue <= distGreen && distBlue <= distYellow) {
    Serial.println("Blue");
    tcs_color = "blue";
    digitalWrite(rgb[0],1);
    digitalWrite(rgb[1],0);
    digitalWrite(rgb[2],0);
  } else {
    Serial.println("Yellow");
    tcs_color = "yellow";
    digitalWrite(rgb[0],0);
    digitalWrite(rgb[1],1);
    digitalWrite(rgb[2],1);
  }
}

void get_color() {
  uint16_t r = my_tcs('r');
  uint16_t g = my_tcs('g');
  uint16_t b = my_tcs('b');
  
  // อ่านค่าสีจาก EEPROM
  uint16_t red_r = readEEPROM(RED_SET_ADDR);
  uint16_t red_g = readEEPROM(RED_SET_ADDR + 2);
  uint16_t red_b = readEEPROM(RED_SET_ADDR + 4);
  
  uint16_t green_r = readEEPROM(GREEN_SET_ADDR);
  uint16_t green_g = readEEPROM(GREEN_SET_ADDR + 2);
  uint16_t green_b = readEEPROM(GREEN_SET_ADDR + 4);
  
  uint16_t blue_r = readEEPROM(BLUE_SET_ADDR);
  uint16_t blue_g = readEEPROM(BLUE_SET_ADDR + 2);
  uint16_t blue_b = readEEPROM(BLUE_SET_ADDR + 4);
  
  uint16_t yellow_r = readEEPROM(YELLOW_SET_ADDR);
  uint16_t yellow_g = readEEPROM(YELLOW_SET_ADDR + 2);
  uint16_t yellow_b = readEEPROM(YELLOW_SET_ADDR + 4);
  
  // ตรวจสอบว่าค่าสีใน EEPROM มีความสมเหตุสมผล
  bool validRed = (red_r != 0 || red_g != 0 || red_b != 0);
  bool validGreen = (green_r != 0 || green_g != 0 || green_b != 0);
  bool validBlue = (blue_r != 0 || blue_g != 0 || blue_b != 0);
  bool validYellow = (yellow_r != 0 || yellow_g != 0 || yellow_b != 0);
  
  if (!validRed || !validGreen || !validBlue || !validYellow) {
    Serial.println("Error: Some colors not stored properly in EEPROM!");
    return;
  }
  
  // คำนวณระยะห่าง
  float distRed = compareColors(r, g, b, red_r, red_g, red_b);
  float distGreen = compareColors(r, g, b, green_r, green_g, green_b);
  float distBlue = compareColors(r, g, b, blue_r, blue_g, blue_b);
  float distYellow = compareColors(r, g, b, yellow_r, yellow_g, yellow_b);
  
  // แสดงเฉพาะชื่อสีที่ใกล้เคียงที่สุด
  if (distRed <= distGreen && distRed <= distBlue && distRed <= distYellow) {
    tone(32, 950, 100);
    delay(200); // รอ 1 วินาที
    Serial.println("Red");
    color_tcs = "Red";
  } else if (distGreen <= distRed && distGreen <= distBlue && distGreen <= distYellow) {
    Serial.println("Green");
    tone(32, 950, 100);
    delay(200); // รอ 1 วินาที
    color_tcs = "Green";
  } else if (distBlue <= distRed && distBlue <= distGreen && distBlue <= distYellow) {
    Serial.println("Blue");
    tone(32, 950, 100);
    delay(200); // รอ 1 วินาที
    color_tcs = "Blue";
  } else {
    Serial.println("Yellow");
    color_tcs = "Yellow";
  }
}

void setup_tcs() {
  pinMode(33, INPUT_PULLUP); // ตั้งค่า GP9 เป็น input พร้อม pull-up resistor
  //storeColors(); // เรียกฟังก์ชันเก็บค่าสี
}

void loop_tcs() {
  //Serial.println(my_tcs('r'));
  searchColor();
  delay(10); // ค้นหาสีทุก 0.5 วินาที
}