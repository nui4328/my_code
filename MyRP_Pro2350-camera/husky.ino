

void setup_husky() {
    Serial.begin(115200);
    Wire.begin();
    while (!huskylens.begin(Wire))
    {
        Serial.println(F("Begin failed!"));
        Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>I2C)"));
        Serial.println(F("2.Please recheck the connection."));
        delay(100);
    }
}

void loop_husky() {
    if (!huskylens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
    else if(!huskylens.isLearned()) Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
    else if(!huskylens.available()) Serial.println(F("No block or arrow appears on the screen!"));
    else
    {
        Serial.println(F("###########"));
        while (huskylens.available())
        {
            HUSKYLENSResult result = huskylens.read();
            printResult(result);
        }    
    }
}

void printResult(HUSKYLENSResult result){
    if (result.command == COMMAND_RETURN_BLOCK){
        Serial.println(String()+F("Block:xCenter=")+result.xCenter+F(",yCenter=")+result.yCenter+F(",width=")+result.width+F(",height=")+result.height+F(",ID=")+result.ID);
    }
    else if (result.command == COMMAND_RETURN_ARROW){
        Serial.println(String()+F("Arrow:xOrigin=")+result.xOrigin+F(",yOrigin=")+result.yOrigin+F(",xTarget=")+result.xTarget+F(",yTarget=")+result.yTarget+F(",ID=")+result.ID);
    }
    else{
        Serial.println("Object unknown!");
    }
}


void get_color_husky()
    {
        delay(300);
        if (!huskylens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
        else if(!huskylens.isLearned()) Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
        else if(!huskylens.available()) Serial.println(F("No block or arrow appears on the screen!"));
        else
            {
                while (huskylens.available())
                  {
                    HUSKYLENSResult result = huskylens.read();
                    int area = result.xCenter * result.yCenter;
                    //printResult(result);
                    if(area > 10000)
                     {
                        Serial.print(result.ID);
                        Serial.print("    ");
                        Serial.println(husky_color);
                        if(result.ID == 1)
                            {
                                husky_color = "red";
                                digitalWrite(rgb[0],0);
                                digitalWrite(rgb[1],0);
                                digitalWrite(rgb[2],1);
                                break;
                            }
                        else if(result.ID == 2)
                            {
                                husky_color = "green";
                                digitalWrite(rgb[0],0);
                                digitalWrite(rgb[1],1);
                                digitalWrite(rgb[2],0);
                                break;
                            }
                        else if(result.ID == 3)
                            {
                                husky_color = "blue";
                                digitalWrite(rgb[0],1);
                                digitalWrite(rgb[1],0);
                                digitalWrite(rgb[2],0);
                                break;
                            }
                        else if(result.ID == 4)
                            {
                                husky_color = "yellow";
                                digitalWrite(rgb[0],0);
                                digitalWrite(rgb[1],1);
                                digitalWrite(rgb[2],1);
                                break;
                            }
                     }
                      
                  }
                    
               
            }
    }
