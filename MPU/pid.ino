
void moveForwardWithPID(float baseSpeed, float targetDistanceCm) {
    // คำนวณจำนวนพัลส์เป้าหมายจากระยะทาง
    float targetPulses = targetDistanceCm * pulsesPerCm;

    // รีเซ็ต Encoder
    encoder.resetEncoders();
    reset_Yaw();

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
        if (currentPulses >= targetPulses) {
            Motor(0, 0); // หยุดมอเตอร์
            break;       // ออกจากลูป
        }

        // อ่านค่าปัจจุบันและคำนวณ PID
        float currentYaw = readYaw();             // อ่านค่ามุม Yaw ปัจจุบัน
        float error = targetYaw - currentYaw;     // คำนวณข้อผิดพลาด
        errorSum += error * dt;                   // คำนวณค่า error สะสม
        float dError = (error - lastError) / dt;  // คำนวณค่า error ที่เปลี่ยนแปลง

        // คำนวณค่าการแก้ไขจาก PID
        float correction = (Kp * error) + (Ki * errorSum) + (Kd * dError);

        // ปรับค่าความเร็วมอเตอร์
        float leftMotorSpeed = baseSpeed + correction;
        float rightMotorSpeed = baseSpeed - correction;

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

void moveFW_chPitch(float baseSpeed, float targetDistanceCm) {
    float targetPulses = targetDistanceCm * pulsesPerCm;

    encoder.resetEncoders();
    reset_Yaw();
    setReferenceAxes();

    unsigned long lastTime = millis();
    

    float initialSpeed = 0; // เริ่มต้นความเร็วจาก 0
    float accelerationRate = 1.0; // อัตราเร่ง (หน่วย: speed per loop)
    

    while (true) {
        unsigned long currentTime = millis();
        float dt = (currentTime - lastTime) / 1000.0;
        lastTime = currentTime;

        float currentPitch = readPitch();
        float leftPulses = encoder.Poss_L();
        float rightPulses = encoder.Poss_R();
        float currentPulses = (leftPulses + rightPulses) / 2;

        if (currentPulses >= targetPulses) {
            Motor(0, 0);
            break;
        }

        // PID Control
        float currentYaw = readYaw();
        float error = targetYaw - currentYaw;
        errorSum += error * dt;
        float dError = (error - lastError) / dt;

        float correction = (Kp * error) + (Ki * errorSum) + (Kd * dError);
        float leftMotorSpeed = constrain(initialSpeed + correction, 0, 100);
        float rightMotorSpeed = constrain(initialSpeed - correction, 0, 100);

        Motor(leftMotorSpeed, rightMotorSpeed);
        lastError = error;

        // ค่อย ๆ เพิ่มความเร็ว
        if (initialSpeed < baseSpeed) {
            initialSpeed += accelerationRate;
        }

        // ตรวจสอบมุม Pitch เพื่อหยุดหุ่นยนต์เมื่อขึ้นตะเกียบ
        if (currentPitch > eep_pitch - 10) {  // กำหนดค่าความเอียงไว้ที่ 15 องศา
            //Motor(-10, -10);
            //bz(50);  // ส่งเสียงเตือน
            n_pitch = readPitch();
            Motor(30, 30); delay(300);
            Motor(-1, -1); delay(30);
            
            if(readPitch()< n_pitch) // สะพาน
              {
                bz(50);bz(50);bz(50);
              }
            else
              {
                bz(500);
              }
            break;
        }

        delayMicroseconds(50);
    }

    Motor(-1, -1);
    delay(10);

    // แสดงข้อมูลมุม Pitch
    char buffer[32];
    sprintf(buffer, "Last: %.2f", n_pitch);
    mydisplay_background(black);
    mydisplay(buffer, 15, 5, 2, white);
    sprintf(buffer, "Cur: %.2f", readPitch());
    mydisplay(buffer, 15, 35, 2, white);
}
