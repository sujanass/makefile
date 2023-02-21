//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Copyright © 2022 Vivartan Technologies., All rights reserved/////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//All works published under Zilla_Gen_0 by Vivartan Technologies is copyrighted by the Association and ownership// 
//of all right, title and interest in and to the works remains with Vivartan Technologies. No works or documents//
//published under Zilla_Gen_0 by Vivartan Technologies may be reproduced,transmitted or copied without the expre//
//-ss written permission of Vivartan Technologies will be considered as a violations of Copyright Act and it may//
//lead to legal action.                                                                                         //
//                                                                                                              //
//**************************************************************************************************************//                                                                                                              //
//                                                                                                              //
//FILE NAME:                                                                                                    //
//DESCRIPTION:                                                                                                  //   
//AUTHOR:                                                                                                       //               
//DATE:                                                                                                         //
//LAST MODIFIED BY:                                                                                             //
//LAST MODIFIED ON:                                                                                             //
//                                                                                                              //      
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class wdt extends mailbox;

  `uvm_component_utils(wdt)

  function new(string name="wdt",uvm_component parent=null);
     super.new(name,parent);
  endfunction
 
 task main_phase(uvm_phase phase);  
    fork
     mailbox_print();
      //IRQ related
      init_irq(); 
      mailbox_11();
           
      deassert_irq();
      mailbox_22();


      //Random number generation

      mailbox_1();
      mailbox_1_flag_clear();
      mailbox_2();
      mailbox_2_flag_clear();
      end_sim();
    join_none
  endtask


  
 //----------------------`MAILBOX_PRINT----------------------------------------------//

  // Monitor for `MAILBOX_PRINT
  task mailbox_print();
    fork   
      forever 
      begin
        @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_PRINT))
        begin
           mailbox_print_addr = 20'h20011;
          $write("\n");
          $write("%c",vif.mem_wr_data);
        end
      end

      // Sampling data if `MAILBOX_PRINT
      forever
      begin
        @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == mailbox_print_addr))
        begin
          $write("%c",vif.mem_wr_data);
         // $display($stime,"\t `MAILBOX_PRINT :address %h data %c byte = %h ",vif.mem_wr_addr,vif.mem_wr_data,vif.mem_byte_en);
          mailbox_print_addr = mailbox_print_addr +1;
        end
      end
    join_none
  endtask
    
  task init_irq();
      forever 
        @(negedge vif.riscv_rst)
        begin
	      
          vif.ext_int47_i = 0 ; 


          end
          endtask
 
  //-----------------------------`MAILBOX_1 : Generate IRQ --------------------------------//
  task mailbox_11();
  forever 
        @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_1))
        begin

          mailbox_1_data  = vif.mem_wr_data;
	
          if(mailbox_1_data == 'h00AA002F) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 47 0x%0h ",vif.ext_int47_i);
             vif.ext_int47_i = 1;
             $display("Generate IRQ 47 0x%0h ",vif.ext_int47_i);
          end
              
                     
      end
 endtask


 task deassert_irq();
   forever 
           @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_2))
          begin
			 
             IRQ_de_assert = vif.mem_wr_data;

              
           if (IRQ_de_assert == 'h00DD0047 ) 
              begin 
              vif.ext_int47_i = 0;
              $display(" De-asserted IRQ  47 ");
             end


             
     end
   endtask

      

       
  task mailbox_22();
      forever 
        @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_1))
        begin
          mailbox_1_data  = vif.mem_wr_data;

        if(mailbox_1_data == 'h00AA0035)
        begin
        repeat(1) @(posedge vif.riscv_clk);
        random_number = {$urandom_range(32'h0000_0000,32'h0000_0010)};
        for(int i = 0; i<8; i++)
             begin
               r_config.data_memory[`MAILBOX_1+i] = random_number[(i*8)+:8]; 
               ref_model.memory[`MAILBOX_1+i] = random_number[(i*8)+:8];
             end 
        end

        else if (mailbox_1_data == 'h00AA0036)
            begin
        repeat(1) @(posedge vif.riscv_clk);
        random_number = {$urandom_range(32'h0000_0011,32'h0000_0020)};
        for(int i = 0; i<8; i++)
             begin
               r_config.data_memory[`MAILBOX_1+i] = random_number[(i*8)+:8]; 
               ref_model.memory[`MAILBOX_1+i] = random_number[(i*8)+:8];
             end 
        end

        else if (mailbox_1_data == 'h00AA0037)
            begin
        repeat(1) @(posedge vif.riscv_clk);
        random_number = {$urandom_range(32'h0000_0021,32'h0000_0040)};
        for(int i = 0; i<8; i++)
             begin
               r_config.data_memory[`MAILBOX_1+i] = random_number[(i*8)+:8]; 
               ref_model.memory[`MAILBOX_1+i] = random_number[(i*8)+:8];
             end 
        end

        end
 endtask
       


   
 //---------------------------------------`MAILBOX_1 ---------------------------------//
  task mailbox_1();
      forever 
        @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_1))
        begin
          mailbox_1_data  = vif.mem_wr_data;
	       
          // RAND_REQ
           if(mailbox_1_data == 'hEEAAEEAA)
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             random_number = {$urandom_range(32'h8000_0000,32'hffff_ffff),$urandom_range(32'h0000_0000,32'hffff_ffff)};
	         //$display("time = %dns  zilla_core - `MAILBOX_1_REQ_RAND = 0x%0h random number = 0x%0h",$stime,mailbox_1_data,random_number); 
             for(int i = 0; i<8; i++)
             begin
               r_config.data_memory[`MAILBOX_1+i] = random_number[(i*8)+:8]; 
               ref_model.memory[`MAILBOX_1+i] = random_number[(i*8)+:8];
             end 
           end 
              
              
         end
 endtask
       

     // FLAG_CLEAR
  task mailbox_1_flag_clear();
    forever
      @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_1_FLAG))
      begin
        mailbox_1_flag_addr =  `MAILBOX_1_FLAG;
       // $display("time = %dns  zilla_core - `MAILBOX_1_FLAG_SET = 0x%0h",$stime,vif.mem_wr_data);
        repeat(1) @(posedge vif.riscv_clk);
       // $display("time = %dns  zilla_core - `MAILBOX_1_FLAG_CLEAR = 0x%0h",$stime,clear_flag); 
        for(int i = 0; i<8; i++)
        begin
          r_config.data_memory[mailbox_1_flag_addr+i] = clear_flag[(i*8)+:8]; 
          ref_model.memory[mailbox_1_flag_addr+i] = clear_flag[(i*8)+:8];
        end 
      end
  endtask


      //------------------------------`MAILBOX_2------------------------------------//      
   
  task mailbox_2();
      forever 
        @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_2))
        begin
          mailbox_2_data  = vif.mem_wr_data;
	      
          // REQ_RAND
          if(mailbox_2_data == 'hEEAAEEAA)
          begin 
             repeat(1) @(posedge vif.riscv_clk);
             random_number = {$urandom_range(32'h8000_0000,32'hffff_ffff),$urandom_range(32'h0000_0000,32'hffff_ffff)};
	         //$display("time = %dns  zilla_core - `MAILBOX_2_REQ_RAND = 0x%0h random_number = 0x%0h",$stime,mailbox_2_data,random_number); 
             for(int i = 0; i<8; i++)
             begin
               r_config.data_memory[`MAILBOX_2+i] = random_number[(i*8)+:8]; 
               ref_model.memory[`MAILBOX_2+i] = random_number[(i*8)+:8];
             end 
          end

        end
   endtask

   // FLAG CLEAR
   task mailbox_2_flag_clear();
     forever
     @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_2_FLAG))
     begin
       mailbox_2_flag_addr =  `MAILBOX_2_FLAG;
      // $display("time = %dns  zilla_core - `MAILBOX_2_FLAG_SET = 0x%0h",$stime,vif.mem_wr_data);
       repeat(1) @(posedge vif.riscv_clk);
     //  $display("time = %dns  zilla_core - `MAILBOX_2_FLAG_CLEAR = 0x%0h",$stime,clear_flag); 
       for(int i = 0; i<8; i++)
       begin
         r_config.data_memory[mailbox_2_flag_addr+i] = clear_flag[(i*8)+:8]; 
         ref_model.memory[mailbox_2_flag_addr+i] = clear_flag[(i*8)+:8];
       end 
     end
   endtask
     //--------------------------------------------------------------------------------//

  // --------------------END_SIM -------------------------
  task end_sim();
    logic exit = 0;
    fork
       forever
       @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_1))
       begin
       mailbox_1_data  = vif.mem_wr_data;
       if(mailbox_1_data == 'hEEAAAAEE)
             begin
              exit =  1'b1;
              $display("time = %dns  zilla_core - `MAILBOX_1_END_SIM = 0x%0h",$stime,mailbox_1_data);
            //  r_config.instructions_executed_count=r_config.no_of_instructions;
             end

       end 
     forever
       @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_2 && exit == 1'b1))
       begin
         mailbox_2_data  = vif.mem_wr_data;
         exit = 1'b0;
         $display("time = %dns  zilla_core - `MAILBOX_2_ERROR_COUNT = %0d",$stime,mailbox_2_data);
         result_check();
	       if(mailbox_2_data > 0)
            r_config.instructions_executed_count=r_config.no_of_instructions;
         else
            r_config.instructions_executed_count=r_config.no_of_instructions;

       end 
    join_none
   endtask


       //--------------------------------------------------------------------------------//
  task result_check();
      logic [63:0] data_q[$];
      int unsigned k = 0;
	int fin;
       fin=$fopen("mem_dump.txt","w");
       for(int i = 0; i<1396; i++)
       begin
         for(int j = 0;j<8;j++)
           data_q[i][(8*j) +:8] = r_config.data_memory[(20'h20120+k+j)];
	$fdisplay(fin,"%0d",$signed(data_q[i]));
           k = k+8;
       end
	  $fclose(fin);
          $display("\n");
      // for(int i = 0;i<data_q.size;i=i+3)
         // $display("\tmemory_check - OPERAND1 = 0x%0h OPERAND2 = 0x%0h RESULT = 0x%0h",data_q[i],data_q[i+1],data_q[i+2]);

   endtask

endclass
