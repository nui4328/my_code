float velocity_L() 
  {
    delayMicroseconds(50);
    // อ่านค่าความเร็วที่ต้องการจาก potentiometer
    // sp = map(analogRead(29), 0, 4095, 0, 255);  // ปรับให้เหมาะกับช่วงมอเตอร์

    // คำนวณเวลาที่ผ่านไป
    unsigned long currentTime = millis();
    float dt = (currentTime - lastTime) / 1000.0;  // เวลาที่ผ่านไปในหน่วยวินาที
    lastTime = currentTime;

    if (dt <= 0) {
        dt = 0.001;  // ป้องกันหารด้วยศูนย์
    }

    // อ่านค่าตำแหน่ง encoder
    float currentEncoderPos = encoder.Poss_L();
    float deltaPos = currentEncoderPos - lastEncoderPos_L;

    // กรองค่า deltaPos ที่ไม่สมเหตุสมผล
    if (abs(deltaPos) > pulsesPerRevolution) {
        deltaPos = 0;
    }
    lastEncoderPos_L = currentEncoderPos;

    // คำนวณความเร็วเชิงมุม (radians per second)
    float angularVelocity = (deltaPos / pulsesPerRevolution) * (2 * 3.14159) / dt;

    // คำนวณความเร็วเชิงเส้น (meters per second)
    float linearVelocity = angularVelocity * (wheelDiameter / 2);

    // แสดงผล
   /*
    Serial.print("Angular Velocity (rad/s): ");
    Serial.print(angularVelocity, 2);  // แสดงทศนิยม 2 ตำแหน่ง
    Serial.print("\tLinear Velocity (m/s): ");
    Serial.println(linearVelocity);  // แสดงทศนิยม 2 ตำแหน่ง
    */
    // หน่วงเวลาเล็กน้อย
    //delay(50);  // 50ms ปรับได้ตามความเหมาะสม

    return linearVelocity;
  }

float velocity_R() 
  {
    delayMicroseconds(50);
    // อ่านค่าความเร็วที่ต้องการจาก potentiometer
    // sp = map(analogRead(29), 0, 4095, 0, 255);  // ปรับให้เหมาะกับช่วงมอเตอร์

    // คำนวณเวลาที่ผ่านไป
    unsigned long currentTime = millis();
    float dt = (currentTime - lastTime) / 1000.0;  // เวลาที่ผ่านไปในหน่วยวินาที
    lastTime = currentTime;

    if (dt <= 0) {
        dt = 0.001;  // ป้องกันหารด้วยศูนย์
    }

    // อ่านค่าตำแหน่ง encoder
    float currentEncoderPos = encoder.Poss_R();
    float deltaPos = currentEncoderPos - lastEncoderPos_R;

    // กรองค่า deltaPos ที่ไม่สมเหตุสมผล
    if (abs(deltaPos) > pulsesPerRevolution) {
        deltaPos = 0;
    }
    lastEncoderPos_R = currentEncoderPos;

    // คำนวณความเร็วเชิงมุม (radians per second)
    float angularVelocity = (deltaPos / pulsesPerRevolution) * (2 * 3.14159) / dt;

    // คำนวณความเร็วเชิงเส้น (meters per second)
    float linearVelocity = angularVelocity * (wheelDiameter / 2);

    // แสดงผล
   /*
    Serial.print("Angular Velocity (rad/s): ");
    Serial.print(angularVelocity, 2);  // แสดงทศนิยม 2 ตำแหน่ง
    Serial.print("\tLinear Velocity (m/s): ");
    Serial.println(linearVelocity);  // แสดงทศนิยม 2 ตำแหน่ง
    */
    // หน่วงเวลาเล็กน้อย
    //delay(50);  // 50ms ปรับได้ตามความเหมาะสม

    return linearVelocity;
  }
