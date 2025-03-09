void rotateRobotPID(int targetAngle, float Kp, float Ki, float Kd) 
{
    reset_Yaw();
    int currentYaw = 0;
    float error = 0, previousError = 0, integral = 0, derivative = 0;
    float output = 0;

    unsigned long lastTime = millis();
    const float maxSpeed = 80;
    const float minSpeed = 50;
    const float tolerance = 2;

    while (true) 
    {
        currentYaw = readYaw();
        error = targetAngle - currentYaw;

        // ออกจากลูปเมื่อถึงเป้าหมาย
        if (abs(error) <= tolerance) {
            if (output > 0) 
              { 
                Motor(-1, 1); // หมุนตามเข็มนาฬิกา
              } 
            else 
              {
                Motor(1, -1); // หมุนทวนเข็มนาฬิกา
              }
              delay(5); 
                break;
            }

        // คำนวณ PID
        unsigned long currentTime = millis();
        float deltaTime = (currentTime - lastTime) / 1000.0;
        integral += error * deltaTime;
        integral = constrain(integral, -50, 50); // จำกัดค่า Integral Term
        derivative = (error - previousError) / deltaTime;
        output = (Kp * error) + (Ki * integral) + (Kd * derivative);

        // จำกัดค่าเอาต์พุต
        output = constrain(output, -maxSpeed, maxSpeed);
        float motorSpeed = max(abs(output), minSpeed);

        // หมุนรอบตัว
        if (output > 0) { 
            Motor(motorSpeed, -1); // หมุนตามเข็มนาฬิกา
        } else {
            Motor(-1, motorSpeed); // หมุนทวนเข็มนาฬิกา
        }

        previousError = error;
        lastTime = currentTime;
    }

    // หยุดมอเตอร์
    if (output > 0) 
              { 
                Motor(-1, 1); // หมุนตามเข็มนาฬิกา
              } 
            else 
              {
                Motor(1, -1); // หมุนทวนเข็มนาฬิกา
              }
}
