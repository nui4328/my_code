void box1()
  {
    fw_encoder(50, 50, 700);     //--------->> เดินหน้าตัวเลขข้างหลัง
    fw_encoder(60, 60, 2, "line",'r'); 
    set_bl_bw(1);
    fw_encoder(60, 60, 2, "none",'r');
    set_bl_bw(1);
    fw_encoder(40, 40, 1, "none",'r');
    set_bl_bw(1);
    fw_encoder(50, 50, 1, "line",'l');
    set_bl_bw(1);
    fw_encoder(40, 40, 2, "none",'s');delay(200);
  }
void box2()
  {
    bw_encoder(40, 40, 600); 
    fw_encoder(0, 0, 0, "none",'l'); 
    set_bl_bw(1); 
    fw_encoder(60, 60, 2, "none",'r');
    set_bl_bw(1);
    fw_encoder(30, 30, 1, "line",'r');
    fw_encoder(30, 30, 1, "none",'s');delay(200);
  }
void box3()
  {
    set_bl_fw(2);
    bw_encoder(55, 50, 2, "line",'r');
    set_bl_bw(1);
    fw_encoder(50, 50, 2, "none",'r');
    set_bl_bw(1);
    fw_encoder(40, 40, 2, "line",'l');
    fw_encoder(50, 50, 1, "line",'l');
    set_bl_bw(1);
    fw_encoder(20, 20, 1, "none",'s');delay(200);
  }
void box4()
  {
    set_bl_fw(2);
    bw_encoder(30, 30, 0, "line",'l');
    fw_encoder(50, 50, 1, "none",'r');
    set_bl_bw(1);
    fw_encoder(50, 50, 2, "line",'l');

    fw_encoder(50, 50, 1, "none",'r');
    set_bl_bw(1);

    fw_encoder(60, 60, 4, "line",'r');
    fw_encoder(30, 30, 1, "line",'r');
    set_bl_bw(1);
    fw_encoder(50, 50, 1, "none",'l');
    set_bl_bw(1);
    fw_encoder(50, 50, 1, "none",'l');
    set_bl_bw(1);
    fw_encoder(50, 50, 2, "line",'l');
    set_bl_bw(1);
    fw_encoder(60, 60, 2, "none",'s');
    fw_encoder(50, 50, 700);  
    
    
    
  }
