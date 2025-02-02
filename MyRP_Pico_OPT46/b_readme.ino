void read_me()
  {   
      sw();                           //--------->>> คำสั่งรอปุ่มกด
      bz(100);                        //--------->>> คำสั่งเปิดเสียง       
      Motor(30, 50);                  //--------->>> คำสั่งควบคุมการทำงานของมอเตอร์
      Motor(-30, -50); 
      
      mcp_f(0);                       //--------->>> คำสั่งแสดงค่าของ sensor แผงหน้าที่อ่านได้ ขณะนั้น mcp_f(0 - 7);
      md_mcp_f(0);                    //--------->>> คำสั่งแสดงค่ากลางของ sensor  md_mcp_f(0 - 7);
      max_mcp_f(0);                   //--------->>> คำสั่งแสดงค่าสูงสุดของ sensor  max_mcp_f(0 - 7);
      min_mcp_f(0);                   //--------->>> คำสั่งแสดงค่าต่ำสุดของ sensor  min_mcp_f(0 - 7);

      mcp_b(0);                       //--------->>> คำสั่งแสดงค่าของ sensor แผงหลังที่อ่านได้ ขณะนั้น mcp_f(0 - 7);
      md_mcp_b(0);                    //--------->>> คำสั่งแสดงค่ากลางของ sensor  md_mcp_b(0 - 7); 
      max_mcp_b(0);                   //--------->>> คำสั่งแสดงค่าสูงสุดของ sensor  max_mcp_b(0 - 7);
      min_mcp_b(0);                   //--------->>> คำสั่งแสดงค่าต่ำสุดของ sensor  min_mcp_b(0 - 7);

      analogRead(26);                 //--------->>> คำสั่งแสดงค่าของ sensor ใต้ท้อง  analogRead(26 - 27);
      md_adc(26);                     //--------->>> คำสั่งแสดงค่ากลางของ sensor ใต้ท้อง  md_adc(26 - 27); 

      servo(0,90);                   //--------->>> คำสั่งควบคุมการทำงาน servo servo(8,90);  พารามิเตอร์ ตัวที่ 1 ประกอบด้วย 0, 1, 8, 28 
                                      //--------->>>  พารามิเตอร์ ตัวที่ 2 ใส่ค่าตั้งแต่  0 -180

      fline(50,50,0.25,0,'c','l',50, "a2", 50);  //--------->>> คำสั่ง หุ่นยนต์เดินตามเส้นไปข้างหน้า
      bline(40,40,0.25,0,'c','p',50, "a5", 50);  //--------->>> คำสั่ง หุ่นยนต์เดินตามเส้นเดินถอยหลัง

      
      fline(20,20,0.28,0,'f','l',80, "a2", 0);
      fline(20,20,0.28,0,'f','r',80, "a5", 0);
      
      fline_white(40,40,0.4,0,'c','l',50, "a2", 50);  //--------->>> คำสั่ง หุ่นยนต์เดินตามเส้นไปข้างหน้า เส้นขาวพื้นดำ
      bline_white(40,40,0.4,0,'c','l',50, "a2", 50);

      fline_setpoint(40,40,0.4, 50,"26", 50);   //  ----->> 50 คือ ตำแหน่งที่ต้องการเซต 0-100 / 50 อยู่ตรงกลาง
                                                //  ----->> a7 คือ เลือกเซนเซอร์ สำหรับเช็คเส้น  มี a0, a7, 26, 27, b0 และ b7
                                                //  ----->> 30 คือ ค่าสำหรับเบรค ถ้าเป็น 0 จะไม่เบรค
      bline_setpoint(40,40,0.4, 50,"a7", 50);   
      fline_setpoint(30, 30, 0.45, 50, "a0", 40); sw();
      fline_setpoint(30, 30, 0.45, 20, "a7", 40); sw();
      fline_setpoint(30, 30, 0.45, 70, "a0", 40); sw();
           
           
      fline_2sensor(35, 35, 0.5, 0, "3:4","a7", 'p', 0);  // คำสั่งเลือกเดินตามเส้น แค่ 2 เซนเซอร์ เลือกเซนเซอร์ในการเช็คเส้น เหมือน fline_setpoint
                                                           // แต่สามารถเลือกหยุดหรือข้าม โดยใช้ 's' คือ หยุด  'p' คือข้าม
      //  #include <my_TCS34725.h>     
       // my_tcs('r'),   อ่านค่า r
       // my_tcs('g'),   อ่านค่า g
       // my_tcs('b')    อ่านค่า b                                                     // 30 คือ ค่าสำหรับเบรค ถ้าเป็น 0 จะไม่เบรค

       error_4sensor();

  }
