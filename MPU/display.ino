void diplay_mpu()
  {
    String pitch = (String) readPitch();
    String yaw = (String) readYaw();
    String roll = (String) readRoll();
    String eepPitch = (String) eep_pitch;
    mydisplay_background(black);
    mydisplay("pitch: "+pitch, 10, 5, 2, white);
    mydisplay("yaw  : "+yaw, 10, 25, 2, white);
    mydisplay("roll : "+roll, 10, 45, 2, white);
    mydisplay("eepP : "+eepPitch, 10, 64, 2, white);
    
  }

void diplay_pid()
  {
    String pitch = (String) readPitch();
    String yaw = (String) readYaw();
    String roll = (String) readRoll();
    String eepPitch = (String) eep_pitch;
    mydisplay_background(black);
    mydisplay("pitch: "+pitch, 10, 5, 2, white);
    mydisplay("yaw  : "+yaw, 10, 15, 2, white);
    mydisplay("roll : "+roll, 10, 35, 2, white);
    mydisplay("eepPitch : "+eepPitch, 10, 24, 2, white);
    
  }
