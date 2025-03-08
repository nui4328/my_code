void move_tl()
  {
    angleZ = 0;
    while(1)
      {
        Serial.print("Z: "); Serial.println(spi_gyro('z')); Serial.print(" ");
        delay(10);
        if(spi_gyro('z') > 84)
          {
            Motor(-1, -1);delay(40);
            bz(300);
            break;
          }
        else
          {
            Motor(-30, 30);
          }
      }
  }

void move_fw()
  {    
    angleZ = 0;
    angleX = 0;
    while(1)
      {        
        Serial.print("Y: "); Serial.println(spi_gyro('x')); Serial.print(" ");
        
        if(spi_gyro('x') > 5.0)
          {
            //bz(50);
            break;
          }
        else
          {
            Motor(30, 30);
          }
      }
    
    
    unsigned long currentTime = millis();
    for(int i=0; i<5; i++)
      {
         Motor(20, 20);
         input_gyroY[i] = spi_gyro('x');
         if(millis() - currentTime > 300)
          {
            break;
          }
      }

   int maxValgyroY = input_gyroY[0];
   int minValgyroY = input_gyroY[0];
      for (int i = 0; i < (sizeof(input_gyroY) / sizeof(input_gyroY[0])); i++) 
         {
            maxValgyroY = max(input_gyroY[i],maxValgyroY);
            minValgyroY = min(input_gyroY[i],minValgyroY);
            min_gyroY = minValgyroY;
            max_gyroY = maxValgyroY;         
         }
  // Serial.print(min_gyroY);Serial.print(" ");Serial.print(max_gyroY);Serial.println(" ");
   
   if(input_gyroY[0] > input_gyroY[4] )
    {
      bz(50);
      Motor(-2, -2);delay(200); 
      Motor(0, 0);delay(200); 
      angleZ = 0;
      Forward_PID(20, 39);      
    }
  else
    {
      bz(50);bz(50);
      Forward_PID(20, 35);   
    }
   Motor(-1, -1);delay(300); 
  }
