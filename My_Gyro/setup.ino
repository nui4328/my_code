void sw_st()
  {
    
    while(digitalRead(9) == 1)
      {
        Serial.print(gyro_angle('x')); Serial.print("  ");
        Serial.print(gyro_angle('y')); Serial.print("  ");
        Serial.print(gyro_angle('z')); Serial.print("  ");
        Serial.print(my_tcs('r')); Serial.println("  ");
        //spi_gyro();
      }

     bz(100);
  }
