void rotateRobot(int _speed, int targetAngle) 
{
    reset_Yaw();
    int last_yaw = readYaw();
    lastTime_yaw = millis();
    int last_targetAngle = targetAngle;
    int _offset;

    // ตั้งเวลาหยุดฉุกเฉิน
    unsigned long startTime = millis();
    const unsigned long timeout = 5000; // 5 วินาที

    while (millis() - startTime < timeout) // หยุดลูปหากเกินเวลา
    {
        delayMicroseconds(50);
        
        // คำนวณค่า offset
        if (velocity_L() >= 70 && velocity_L() <= 122) 
        {
            if (targetAngle > 100) 
            {
                _offset = map(velocity_L(), 70, 122, 0, 35);
            } 
            else 
            {
                _offset = map(velocity_L(), 70, 122, 0, 19);
            }
        } 
        else 
        {
            _offset = 0; // กรณีค่า velocity_L() ผิดปกติ
        }

        // ปรับเป้าหมายมุม
        last_targetAngle = targetAngle - _offset;

        // เช็คระยะใกล้เป้าหมาย
        if (abs(last_targetAngle - readYaw()) < 15) 
        {
            _speed = max(30, _speed / 2); // ลดความเร็วแบบนุ่มนวล
            break;
        }

        // หมุนตามเป้าหมาย
        if (targetAngle > 0) 
        {
            Motor(_speed, -_speed);
        } 
        else 
        {
            Motor(-_speed, _speed);
        }
    }

    // ปรับตำแหน่งละเอียด
    while (millis() - startTime < timeout && abs(readYaw() - last_targetAngle) > 2) 
    {
        delayMicroseconds(50);

        if (targetAngle > 0) 
        {
            Motor(_speed / 2, -_speed / 2); // ลดความเร็ว
        } 
        else 
        {
            Motor(-_speed / 2, _speed / 2);
        }
    }

    // หยุดและชดเชยการหมุนเลย
    if (targetAngle > 0) 
    {
        Motor(-_speed / 2, _speed / 2); // ถอยเล็กน้อย
    } 
    else 
    {
        Motor(_speed / 2, -_speed / 2);
    }

    delay(20);
    Motor(0, 0); // หยุดมอเตอร์
}
