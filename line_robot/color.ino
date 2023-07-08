void setup_tcs() 
  {
      Serial.begin(9600);
      Wire.begin();
      if (!tcs.begin()) 
        {
          Serial.println("Failed to initialize TCS34725 sensor!");
          while (1);
        }
  }
void loop_tcs() 
  {
     
      uint16_t r, g, b, c;
      tcs.getRawData(&r, &g, &b, &c);
      float averag = (r+g+b)/3;
      red = r/averag; ;
      green = g/averag; ;
      blue = b/averag;;
    
      Serial.print("Red: ");
      Serial.print(red);
      Serial.print(" Green: ");
      Serial.print(green);
      Serial.print(" Blue: ");
      Serial.println(blue);  
  }
