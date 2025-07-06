void get_color_pixy()
  {        
    //pixy.setLamp(0x01, 0x00); // 1 means turn on the LED, 0 for turn off
    pixy.ccc.getBlocks();
    digitalWrite(rgb[0],0);
    digitalWrite(rgb[1],0);
    digitalWrite(rgb[2],0);
    if (pixy.ccc.numBlocks)
      {
        //Serial.print("Detected ");
        //Serial.println(pixy.ccc.numBlocks);
        for (int i=0; i<pixy.ccc.numBlocks; i++)
          {
            //Serial.print("  block ");
           // Serial.print(i);
           // Serial.print(": ");
            pixy.ccc.blocks[i].print();
            int sig = pixy.ccc.blocks[i].m_signature;
            int x = pixy.ccc.blocks[i].m_x;
            int y = pixy.ccc.blocks[i].m_y;
            long w = pixy.ccc.blocks[i].m_width;
            long h = pixy.ccc.blocks[i].m_height;
            long s = w*h;
            Serial.println(sig );
            if(sig == 1)
              {   
                pixy_color = "red";
                Serial.println("red");   
                digitalWrite(rgb[0],0);
                digitalWrite(rgb[1],0);
                digitalWrite(rgb[2],1);
              }
            else if(sig == 2)
              {      
                pixy_color = "green";                       
                Serial.println("green"); 
                digitalWrite(rgb[0],0);
                digitalWrite(rgb[1],1);
                digitalWrite(rgb[2],0);
              }
            else if(sig == 3)
              {     
                pixy_color = "blue";                        
                Serial.println("blue"); 
                digitalWrite(rgb[0],1);
                digitalWrite(rgb[1],0);
                digitalWrite(rgb[2],0);
              }
            else if(sig == 4)
              {   
                pixy_color = "yello";                          
                Serial.println("yello"); 
                digitalWrite(rgb[0],0);
                digitalWrite(rgb[1],1);
                digitalWrite(rgb[2],1);
              }
            else
              {     
                digitalWrite(rgb[0],0);
                digitalWrite(rgb[1],0);
                digitalWrite(rgb[2],0);
              }
          }
      }
  }

