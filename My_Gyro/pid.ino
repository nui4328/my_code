void Forward_PID(float baseSpeed, float targetDistanceCm) {
    // คำนวณจำนวนพัลส์เป้าหมายจากระยะทาง
    float targetPulses = targetDistanceCm * pulsesPerCm;

    // รีเซ็ต Encoder
    encoder.resetEncoders();

    // เริ่มจับเวลา
    unsigned long lastTime = millis();
    
    while (true) {
        unsigned long currentTime = millis();
        float dt = (currentTime - lastTime) / 1000.0; // แปลงเวลาที่ผ่านไปเป็นวินาที
        lastTime = currentTime;  // อัปเดตเวลา

        // อ่านค่าจาก Encoder
        float leftPulses = encoder.Poss_L();
        float rightPulses = encoder.Poss_R();

        // คำนวณระยะทางที่เคลื่อนที่แล้ว (เฉลี่ยจากล้อซ้ายและขวา)
        float currentPulses = (leftPulses + rightPulses) / 2;

        // ตรวจสอบว่าถึงเป้าหมายหรือยัง
        Serial.print(currentPulses);Serial.print(" ");
        Serial.print(targetPulses);Serial.println(" ");
        if (currentPulses >= targetPulses) {
            Motor(0, 0); // หยุดมอเตอร์
            break;       // ออกจากลูป
        }

        // อ่านค่าปัจจุบันและคำนวณ PID
        float currentYaw = spi_gyro('z');             // อ่านค่ามุม Yaw ปัจจุบัน
        float error = targetYaw - currentYaw;     // คำนวณข้อผิดพลาด
        errorSum += error * dt;                   // คำนวณค่า error สะสม
        float dError = (error - lastError) / dt;  // คำนวณค่า error ที่เปลี่ยนแปลง

        // คำนวณค่าการแก้ไขจาก PID
        float correction = (Kp * error) + (Ki * errorSum) + (Kd * dError);

        // ปรับค่าความเร็วมอเตอร์
        float leftMotorSpeed = baseSpeed - correction;
        float rightMotorSpeed = baseSpeed + correction;

        // จำกัดความเร็วมอเตอร์ให้อยู่ในช่วงที่กำหนด
        leftMotorSpeed = constrain(leftMotorSpeed, 0, 100);
        rightMotorSpeed = constrain(rightMotorSpeed, 0, 100);

        // ส่งค่าความเร็วไปยังมอเตอร์
        Motor(leftMotorSpeed, rightMotorSpeed);

        // อัปเดตค่า error ล่าสุด
        lastError = error;

        delay(10); // เพิ่มความเสถียรของลูป
    }
  Motor(-1, -1);delay(10);
}
