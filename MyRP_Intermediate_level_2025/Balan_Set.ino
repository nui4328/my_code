void set_f(int _time)
  {
    for(int i = 0; i<_time; i++)
      {               
        while(1)
          {
            if(mcp_f(1) < md_mcp_f(1) && mcp_f(2) > md_mcp_f(2)) 
              {
                 Motor(-2, 20);        
              }
            else if(mcp_f(1) > md_mcp_f(1) && mcp_f(2) < md_mcp_f(2))
              {
                Motor(20, -2);           
              }
            else if(mcp_f(0) < md_mcp_f(0) && mcp_f(3) < md_mcp_f(3)
                  || mcp_f(1) < md_mcp_f(1) && mcp_f(2) < md_mcp_f(2))
              {   
                Motor(-30, -30);delay(20);
                Motor(1, 1);delay(10);
                Motor(0, 0); delay(10);
                break;            
              }
            else
              {
                Motor(20, 20); 
              }
          }
        if(i < _time-1)
          {
            Motor(-30, -30);delay(50);
          }
      }

      Motor(0, 0); delay(50);
  }
void set_b(int _time)
  {
    set_bb = "set_bb";
    for(int i = 0; i<_time; i++)
      {               
        while(1)
          {
            if(mcp_f(4) < md_mcp_f(7) && mcp_f(7) > md_mcp_f(7)) 
              {
                ch_lrs = 'l';
                 Motor(-30, 10);        
              }
            else if(mcp_f(4) > md_mcp_f(4) && mcp_f(7) < md_mcp_f(7))
              {
                ch_lrs = 'r';
                Motor(10, -30);           
              }
           else if(mcp_f(7) < md_mcp_f(7) && mcp_f(4) < md_mcp_f(4))
              {   
                if(ch_lrs == 'l')
                      {
                        Motor(20, 5);delay(20);
                      }
                else
                      {
                        Motor(5, 20);delay(20);
                      }
                Motor(0, 0); delay(10);
                break;            
              }
            else
              {
                Motor(-20, -20);
              }
          }
        if(i < _time-1)
          {
            while(1)
              {
                Motor(20, 20);
                if(mcp_f(7) > md_mcp_f(7) && mcp_f(4) > md_mcp_f(4))
                  {
                    break;
                  }
              }
            while(1)
              {
                Motor(20, 20);
                if(mcp_f(5) > md_mcp_f(5) && mcp_f(6) > md_mcp_f(6))
                  {
                    Motor(-10, -10); delay(10);
                    break;
                  }
              }
          }
      }

      
  }
