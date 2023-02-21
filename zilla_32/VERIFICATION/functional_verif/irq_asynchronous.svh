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

class irq_asynchronous extends mailbox;

  `uvm_component_utils(irq_asynchronous)

  function new(string name="irq_asynchronous",uvm_component parent=null);
     super.new(name,parent);
  endfunction
 
 task main_phase(uvm_phase phase);  
    fork
     mailbox_print();
      //IRQ related
      init_irq(); 
      mailbox_11();
      deassert_irq();

      //Random number generation

      mailbox_1();
      mailbox_1_flag_clear();
      mailbox_2();
      mailbox_2_flag_clear();
      end_sim();
    join_none
      result_check();
  endtask
  
 
    
  task int_generator(input bit[31:0] int_no );
             if(int_no == 0 )
              vif.ext_int0_i = 1;
             else if ( int_no == 1 ) 
              vif.ext_int1_i = 1;
             else if(int_no == 2 )
              vif.ext_int2_i = 1;
             else if(int_no == 3 )
              vif.ext_int3_i = 1;
             else if(int_no == 4 )
              vif.ext_int4_i = 1;
             else if(int_no == 5 )
              vif.ext_int5_i = 1;
             else if(int_no == 6 )
              vif.ext_int6_i = 1;
             else if(int_no == 7 )
              vif.ext_int7_i = 1;
             else if(int_no == 8)
              vif.ext_int8_i = 1;
             else if(int_no == 9 )
              vif.ext_int9_i = 1;   
             else if(int_no == 10 )
              vif.ext_int10_i = 1;
             else if(int_no == 11 )
              vif.ext_int11_i = 1;
             else if(int_no == 12 )
              vif.ext_int12_i = 1;
             else if(int_no == 13 )
              vif.ext_int13_i = 1;
             else if(int_no == 14 )
              vif.ext_int14_i = 1;
             else if(int_no == 15)
              vif.ext_int15_i = 1;
             else if(int_no == 16 )
              vif.ext_int16_i = 1;
             else if(int_no == 17 )
              vif.ext_int17_i = 1;
             else if(int_no == 18 )
              vif.ext_int18_i = 1;
             else if(int_no == 19 )
              vif.ext_int19_i = 1;
             else if(int_no == 20 )
              vif.ext_int20_i = 1;
             else if(int_no == 21)
              vif.ext_int21_i = 1;
             else if(int_no == 22)
              vif.ext_int22_i = 1;
             else if(int_no == 23 )
              vif.ext_int23_i = 1;
             else if(int_no == 24 )
              vif.ext_int24_i = 1 ;
              else if(int_no == 25 )
             vif.ext_int25_i = 1;
            else if(int_no == 26 )
             vif.ext_int26_i = 1;
            else if(int_no == 27 )
             vif.ext_int27_i = 1;
            else if(int_no == 28 )
             vif.ext_int28_i = 1;
            else if(int_no == 29 )
             vif.ext_int29_i = 1;
            else if(int_no == 30 )
             vif.ext_int30_i = 1;
            else if(int_no == 31 )
             vif.ext_int31_i = 1;
            else if(int_no == 32 )
             vif.ext_int32_i = 1;
            else if(int_no == 33 )
             vif.ext_int33_i = 1;
            else if(int_no == 34 )
             vif.ext_int34_i = 1;
            else if(int_no == 35 )
             vif.ext_int35_i = 1;
            else if(int_no == 36 )
             vif.ext_int36_i = 1;
            else if(int_no == 37 )
             vif.ext_int37_i = 1;
            else if(int_no == 38 )
             vif.ext_int38_i = 1;
            else if(int_no == 39 )
             vif.ext_int39_i = 1;
            else if(int_no == 40 )
             vif.ext_int40_i = 1;
            else if(int_no == 41 )
             vif.ext_int41_i = 1;
            else if(int_no == 42 )
             vif.ext_int42_i = 1;
            else if(int_no == 43 )
             vif.ext_int43_i = 1;
            else if(int_no == 44 )
             vif.ext_int44_i = 1;
            else if(int_no == 45 )
             vif.ext_int45_i = 1;
            else if(int_no == 46 )
             vif.ext_int46_i = 1;
  endtask   
  
  task init_irq();
      forever 
        @(negedge vif.riscv_rst)
        begin
	       vif.ext_int0_i = 0 ; 
	       vif.ext_int1_i = 0 ; 
	       vif.ext_int2_i = 0 ; 
	       vif.ext_int3_i = 0 ;
	       vif.ext_int4_i = 0 ; 
	       vif.ext_int5_i = 0 ; 
	       vif.ext_int6_i = 0 ; 
	       vif.ext_int7_i = 0 ;
	       vif.ext_int8_i = 0 ; 
	       vif.ext_int9_i = 0 ; 
	       vif.ext_int10_i = 0 ; 
	       vif.ext_int11_i = 0 ;
           vif.ext_int12_i = 0 ; 
	       vif.ext_int13_i = 0 ;
	       vif.ext_int14_i = 0 ; 
	       vif.ext_int15_i = 0 ; 
	       vif.ext_int16_i = 0 ; 
	       vif.ext_int17_i = 0 ;
	       vif.ext_int18_i = 0 ; 
	       vif.ext_int19_i = 0 ; 
	       vif.ext_int20_i = 0 ; 
	       vif.ext_int21_i = 0 ;
           vif.ext_int22_i = 0 ; 
	       vif.ext_int23_i = 0 ;
	       vif.ext_int24_i = 0 ; 
	       vif.ext_int25_i = 0 ; 
	       vif.ext_int26_i = 0 ; 
	       vif.ext_int27_i = 0 ;
	       vif.ext_int28_i = 0 ; 
	       vif.ext_int29_i = 0 ; 
	       vif.ext_int30_i = 0 ; 
	       vif.ext_int31_i = 0 ;
           vif.ext_int32_i = 0 ; 
	       vif.ext_int33_i = 0 ;
	       vif.ext_int34_i = 0 ; 
	       vif.ext_int35_i = 0 ; 
	       vif.ext_int36_i = 0 ; 
	       vif.ext_int37_i = 0 ;
	       vif.ext_int38_i = 0 ; 
	       vif.ext_int39_i = 0 ; 
	       vif.ext_int40_i = 0 ; 
	       vif.ext_int41_i = 0 ;
           vif.ext_int42_i = 0 ; 
	       vif.ext_int43_i = 0 ;
	       vif.ext_int44_i = 0 ; 
	       vif.ext_int45_i = 0 ; 
	       vif.ext_int46_i = 0 ; 

          end
          endtask
 
  //-----------------------------`MAILBOX_1 : Generate IRQ --------------------------------//
  task mailbox_11();
       bit[31:0] int_no ;
        bit[31:0] count ;
        int rand_delay;
      forever 
        @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_1))
        begin

          mailbox_1_data  = vif.mem_wr_data;
	
          // Generating one IRQ at a time
          if(mailbox_1_data == 'h00AA0000) // TBD - Global constant definition - `define IRQ_0 'h00AA0000
            begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 0 value 0x%0h ",vif.ext_int0_i);
             vif.ext_int0_i = 1;
             $display("Generate IRQ 0 value 0x%0h ",vif.ext_int0_i);
             end
          else if(mailbox_1_data == 'h00AA0001) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 1 0x%0h ",vif.ext_int1_i);
             vif.ext_int1_i = 1;
             $display("Generate IRQ 1 0x%0h ",vif.ext_int1_i);
           
          end
          else if(mailbox_1_data == 'h00AA0002) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 2 0x%0h ",vif.ext_int2_i);
             vif.ext_int2_i = 1;
             $display("Generate IRQ 2 0x%0h ",vif.ext_int2_i);

          end
          else if(mailbox_1_data == 'h00AA0003) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 3 0x%0h ",vif.ext_int3_i);
             vif.ext_int3_i = 1;
             $display("Generate IRQ 3 0x%0h ",vif.ext_int3_i);

          end

        else if(mailbox_1_data == 'h00AA0004) //GEN_IRQ
            begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 4 value 0x%0h ",vif.ext_int4_i);
             vif.ext_int4_i = 1;

          end
          else if(mailbox_1_data == 'h00AA0005) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 5 0x%0h ",vif.ext_int5_i);
             vif.ext_int5_i = 1;
             $display("Generate IRQ 5 0x%0h ",vif.ext_int5_i);
      
          end
          else if(mailbox_1_data == 'h00AA0006) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 6 0x%0h ",vif.ext_int6_i);
             vif.ext_int6_i = 1;
             $display("Generate IRQ 6 0x%0h ",vif.ext_int6_i);
           
          end
          else if(mailbox_1_data == 'h00AA0007) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 7 0x%0h ",vif.ext_int7_i);
             vif.ext_int7_i = 1;
             $display("Generate IRQ 7 0x%0h ",vif.ext_int7_i);
    
          end

       if(mailbox_1_data == 'h00AA0008) //GEN_IRQ
            begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 8 value 0x%0h ",vif.ext_int8_i);
             vif.ext_int8_i = 1;
             $display("Generate IRQ 8 value 0x%0h ",vif.ext_int8_i);
                     end
          else if(mailbox_1_data == 'h00AA0009) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 9 0x%0h ",vif.ext_int9_i);
             vif.ext_int9_i = 1;
             $display("Generate IRQ 9 0x%0h ",vif.ext_int9_i);
                      end
          else if(mailbox_1_data == 'h00AA000A) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 10 0x%0h ",vif.ext_int10_i);
             vif.ext_int10_i = 1;
             $display("Generate IRQ 10 0x%0h ",vif.ext_int10_i);
                     end
          else if(mailbox_1_data == 'h00AA000B) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 11 0x%0h ",vif.ext_int11_i);
             vif.ext_int11_i = 1;
             $display("Generate IRQ 11 0x%0h ",vif.ext_int11_i);
            end

        else if(mailbox_1_data == 'h00AA000C) //GEN_IRQ
            begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 12 value 0x%0h ",vif.ext_int12_i);
             vif.ext_int12_i = 1;
             $display("Generate IRQ 12 value 0x%0h ",vif.ext_int12_i);
          end
          else if(mailbox_1_data == 'h00AA000D) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 13 0x%0h ",vif.ext_int13_i);
             vif.ext_int13_i = 1;
             $display("Generate IRQ 13 0x%0h ",vif.ext_int13_i);
          end
          else if(mailbox_1_data == 'h00AA000E) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 14 0x%0h ",vif.ext_int14_i);
             vif.ext_int14_i = 1;
             $display("Generate IRQ 14 0x%0h ",vif.ext_int14_i);
          end
          else if(mailbox_1_data == 'h00AA000F) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 15 0x%0h ",vif.ext_int15_i);
             vif.ext_int15_i = 1;
             $display("Generate IRQ 15 0x%0h ",vif.ext_int15_i);
          end
          else if(mailbox_1_data == 'h00AA0010) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 16 0x%0h ",vif.ext_int16_i);
             vif.ext_int16_i = 1;
             $display("Generate IRQ 16 0x%0h ",vif.ext_int16_i);
          end

          else if(mailbox_1_data == 'h00AA0011) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 17 0x%0h ",vif.ext_int17_i);
             vif.ext_int17_i = 1;
             $display("Generate IRQ 17 0x%0h ",vif.ext_int17_i);
          end
          else if(mailbox_1_data == 'h00AA0012) //GEN_IRQ
           begin              repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 18 0x%0h ",vif.ext_int18_i);
             vif.ext_int18_i = 1;
             $display("Generate IRQ 18 0x%0h ",vif.ext_int18_i);
          end
        else if(mailbox_1_data == 'h00AA0013) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 19 0x%0h ",vif.ext_int19_i);
             vif.ext_int19_i = 1;
             $display("Generate IRQ 19 0x%0h ",vif.ext_int19_i);
          end
          else if(mailbox_1_data == 'h00AA0014) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 20 0x%0h ",vif.ext_int20_i);
             vif.ext_int20_i = 1;
             $display("Generate IRQ 20 0x%0h ",vif.ext_int20_i);
          end
         else if(mailbox_1_data == 'h00AA0015) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 21 0x%0h ",vif.ext_int21_i);
             vif.ext_int21_i = 1;
             $display("Generate IRQ 21 0x%0h ",vif.ext_int21_i);
          end
          else if(mailbox_1_data == 'h00AA0016) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 22 0x%0h ",vif.ext_int22_i);
             vif.ext_int22_i = 1;
             $display("Generate IRQ 22 0x%0h ",vif.ext_int22_i);
          end
         else if(mailbox_1_data == 'h00AA0017) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 23 0x%0h ",vif.ext_int23_i);
             vif.ext_int23_i = 1;
             $display("Generate IRQ 23 0x%0h ",vif.ext_int23_i);
          end
          else if(mailbox_1_data == 'h00AA0018) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 24 0x%0h ",vif.ext_int24_i);
             vif.ext_int24_i = 1;
             $display("Generate IRQ 24 0x%0h ",vif.ext_int24_i);
          end
          else if(mailbox_1_data == 'h00AA0019) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 25 0x%0h ",vif.ext_int25_i);
             vif.ext_int25_i = 1;
             $display("Generate IRQ 25 0x%0h ",vif.ext_int25_i);
          end
          else if(mailbox_1_data == 'h00AA001A) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 26 0x%0h ",vif.ext_int26_i);
             vif.ext_int26_i = 1;
             $display("Generate IRQ 26 0x%0h ",vif.ext_int26_i);
          end
         else if(mailbox_1_data == 'h00AA001B) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 27 0x%0h ",vif.ext_int27_i);
             vif.ext_int27_i = 1;
             $display("Generate IRQ 27 0x%0h ",vif.ext_int27_i);
          end
          else if(mailbox_1_data == 'h00AA001C) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 28 0x%0h ",vif.ext_int28_i);
             vif.ext_int28_i = 1;
             $display("Generate IRQ 28 0x%0h ",vif.ext_int28_i);
          end
          else if(mailbox_1_data == 'h00AA001D) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 29 0x%0h ",vif.ext_int29_i);
             vif.ext_int29_i = 1;
             $display("Generate IRQ 29 0x%0h ",vif.ext_int29_i);
          end
          else if(mailbox_1_data == 'h00AA001E) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 30 0x%0h ",vif.ext_int30_i);
             vif.ext_int30_i = 1;
             $display("Generate IRQ 30 0x%0h ",vif.ext_int30_i);
          end
         else if(mailbox_1_data == 'h00AA001F) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 31 0x%0h ",vif.ext_int31_i);
             vif.ext_int31_i = 1;
             $display("Generate IRQ 31 0x%0h ",vif.ext_int31_i);
          end
        else if(mailbox_1_data == 'h00AA0020) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 32 0x%0h ",vif.ext_int32_i);
             vif.ext_int32_i = 1;
             $display("Generate IRQ 32 0x%0h ",vif.ext_int32_i);
          end
        else if(mailbox_1_data == 'h00AA0021) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 33 0x%0h ",vif.ext_int33_i);
             vif.ext_int33_i = 1;
             $display("Generate IRQ 33 0x%0h ",vif.ext_int33_i);
          end
         else if(mailbox_1_data == 'h00AA0022) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 34 0x%0h ",vif.ext_int34_i);
             vif.ext_int34_i = 1;
             $display("Generate IRQ 34 0x%0h ",vif.ext_int34_i);
          end
 
         else if(mailbox_1_data == 'h00AA0023) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 35 0x%0h ",vif.ext_int35_i);
             vif.ext_int35_i = 1;
             $display("Generate IRQ 35 0x%0h ",vif.ext_int35_i);
          end
 
        else if(mailbox_1_data == 'h00AA0024) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 36 0x%0h ",vif.ext_int36_i);
             vif.ext_int36_i = 1;
             $display("Generate IRQ 36 0x%0h ",vif.ext_int36_i);
          end
         else if(mailbox_1_data == 'h00AA0025) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 37 0x%0h ",vif.ext_int37_i);
             vif.ext_int37_i = 1;
             $display("Generate IRQ 37 0x%0h ",vif.ext_int37_i);
          end
          else if(mailbox_1_data == 'h00AA0026) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 38 0x%0h ",vif.ext_int38_i);
             vif.ext_int38_i = 1;
             $display("Generate IRQ 38 0x%0h ",vif.ext_int38_i);
          end
         else if(mailbox_1_data == 'h00AA0027) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 39 0x%0h ",vif.ext_int39_i);
             vif.ext_int39_i = 1;
             $display("Generate IRQ 39 0x%0h ",vif.ext_int39_i);
          end
 
         else if(mailbox_1_data == 'h00AA0028) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 40 0x%0h ",vif.ext_int40_i);
             vif.ext_int40_i = 1;
             $display("Generate IRQ 40 0x%0h ",vif.ext_int40_i);
          end
  
         else if(mailbox_1_data == 'h00AA0029) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 41 0x%0h ",vif.ext_int41_i);
             vif.ext_int41_i = 1;
             $display("Generate IRQ 41 0x%0h ",vif.ext_int41_i);
          end
  
         else if(mailbox_1_data == 'h00AA002A) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 42 0x%0h ",vif.ext_int42_i);
             vif.ext_int42_i = 1;
             $display("Generate IRQ 42 0x%0h ",vif.ext_int42_i);
          end
 
         else if(mailbox_1_data == 'h00AA002B) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 43 0x%0h ",vif.ext_int43_i);
             vif.ext_int43_i = 1;
             $display("Generate IRQ 43 0x%0h ",vif.ext_int43_i);
          end
  
         else if(mailbox_1_data == 'h00AA002C) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 44 0x%0h ",vif.ext_int44_i);
             vif.ext_int44_i = 1;
             $display("Generate IRQ 44 0x%0h ",vif.ext_int44_i);
          end
 
         else if(mailbox_1_data == 'h00AA002D) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 45 0x%0h ",vif.ext_int45_i);
             vif.ext_int45_i = 1;
             $display("Generate IRQ 45 0x%0h ",vif.ext_int45_i);
          end 
         else if(mailbox_1_data == 'h00AA002E) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             $display("Generate IRQ 46 0x%0h ",vif.ext_int46_i);
             vif.ext_int46_i = 1;
             $display("Generate IRQ 46 0x%0h ",vif.ext_int46_i);
          end

          else if(mailbox_1_data == 'h00AA0030) //Random One Interrupt Generation 
           begin
             rand_delay = $urandom_range(0,10) ;
             repeat(1) @(posedge vif.riscv_clk);
              #(rand_delay * 1ns);
             repeat(1)
             begin
              int_no = $urandom_range(0,46);
              int_generator(int_no);
             end
          end 

           else if(mailbox_1_data == 'h00AA0031) //Random n Interrupt Generation (n=10 here)
           begin
             random_int_no rand_int = new() ;
             repeat(1) @(negedge vif.riscv_clk);
             repeat(10)
             begin
             void'(rand_int.randomize());
              int_generator(rand_int.rand_int);
             end
          end 

           else if(mailbox_1_data == 'h00AA0032) //Random n Interrupt Generation 
             begin
             random_int_no rand_int = new() ;
             repeat(1) @(negedge vif.riscv_clk);
             count = $urandom_range(1,46) ;
             repeat(count)
             begin
              void'(rand_int.randomize());
              int_generator(rand_int.rand_int);
             end
          end 

          else if(mailbox_1_data == 'h00AA0033) //Random n Interrupt Generation with Random Delay
             begin
             random_int_no rand_int = new() ;
             repeat(1) @(posedge vif.riscv_clk);
             repeat(20)
             begin
              rand_delay = $urandom_range(0,10) ;
              count = $urandom_range(0, 500) ;
              repeat(count) @(posedge vif.riscv_clk);
              #(rand_delay * 1ns);
              int_no = $urandom_range(0,46);
             void'(rand_int.randomize());
              int_generator(int_no);
             end
          end

        
           else if(mailbox_1_data == 'h00AA0034) //Random n Interrupt Generation at a particular time 
             begin
             random_int_no rand_int = new() ;
             repeat(1) @(posedge vif.riscv_clk);
             //count = $urandom_range(1,48) ;
             rand_delay = $urandom_range(0,10) ;
              #(rand_delay * 1ns);
             repeat(10)
             begin
              void'(rand_int.randomize());
              int_generator(rand_int.rand_int);
             end
          end  

            end
 endtask


 task deassert_irq();
   forever 
           @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_2))
          begin
			 
               IRQ_de_assert = vif.mem_wr_data;

               if (IRQ_de_assert == 'h00DD0000 )
               begin
                 vif.ext_int0_i = 0;  
                 $display(" De-asserted IRQ  0");
               end
                           
             else if (IRQ_de_assert == 'h00DD0001 ) 
              begin 
              vif.ext_int1_i = 0;
              $display(" De-asserted IRQ  1 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0002 ) 
              begin 
              vif.ext_int2_i = 0;
              $display(" De-asserted IRQ  2 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0003 ) 
              begin 
              vif.ext_int3_i = 0;
              $display(" De-asserted IRQ  3 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0004 ) 
              begin 
              vif.ext_int4_i = 0;
              $display(" De-asserted IRQ  4 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0005 ) 
              begin 
              vif.ext_int5_i = 0;
              $display(" De-asserted IRQ  5 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0006 ) 
              begin 
              vif.ext_int6_i = 0;
              $display(" De-asserted IRQ  6 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0007 ) 
              begin 
              vif.ext_int7_i = 0;
              $display(" De-asserted IRQ  7 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0008 ) 
              begin 
              vif.ext_int8_i = 0;
              $display(" De-asserted IRQ  8 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0009 ) 
              begin 
              vif.ext_int9_i = 0;
              $display(" De-asserted IRQ  9 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0010 ) 
              begin 
              vif.ext_int10_i = 0;
              $display(" De-asserted IRQ  10 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0011 ) 
              begin 
              vif.ext_int11_i = 0;
              $display(" De-asserted IRQ  11 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0012 ) 
              begin 
              vif.ext_int12_i = 0;
              $display(" De-asserted IRQ  12 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0013 ) 
              begin 
              vif.ext_int13_i = 0;
              $display(" De-asserted IRQ  13 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0014 ) 
              begin 
              vif.ext_int14_i = 0;
              $display(" De-asserted IRQ  14 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0015 ) 
              begin 
              vif.ext_int15_i = 0;
              $display(" De-asserted IRQ  15 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0016 ) 
              begin 
              vif.ext_int16_i = 0;
              $display(" De-asserted IRQ  16 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0017 ) 
              begin 
              vif.ext_int17_i = 0;
              $display(" De-asserted IRQ  17 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0018 ) 
              begin 
              vif.ext_int18_i = 0;
              $display(" De-asserted IRQ  18 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0019 ) 
              begin 
              vif.ext_int19_i = 0;
              $display(" De-asserted IRQ  19 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0020 ) 
              begin 
              vif.ext_int20_i = 0;
              $display(" De-asserted IRQ  20 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0021 ) 
              begin 
              vif.ext_int21_i = 0;
              $display(" De-asserted IRQ  21 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0022 ) 
              begin 
              vif.ext_int22_i = 0;
              $display(" De-asserted IRQ  22 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0023 ) 
              begin 
              vif.ext_int23_i = 0;
              $display(" De-asserted IRQ  23 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0024 ) 
              begin 
              vif.ext_int24_i = 0;
              $display(" De-asserted IRQ  24 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0025 ) 
              begin 
              vif.ext_int25_i = 0;
              $display(" De-asserted IRQ  25 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0026 ) 
              begin 
              vif.ext_int26_i = 0;
              $display(" De-asserted IRQ  26 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0027 ) 
              begin 
              vif.ext_int27_i = 0;
              $display(" De-asserted IRQ  27 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0028 ) 
              begin 
              vif.ext_int28_i = 0;
              $display(" De-asserted IRQ  28 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0029 ) 
              begin 
              vif.ext_int29_i = 0;
              $display(" De-asserted IRQ  29 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0030 ) 
              begin 
              vif.ext_int30_i = 0;
              $display(" De-asserted IRQ  30 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0031 ) 
              begin 
              vif.ext_int31_i = 0;
              $display(" De-asserted IRQ  31 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0032 ) 
              begin 
              vif.ext_int32_i = 0;
              $display(" De-asserted IRQ  32 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0033 ) 
              begin 
              vif.ext_int33_i = 0;
              $display(" De-asserted IRQ  33 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0034 ) 
              begin 
              vif.ext_int34_i = 0;
              $display(" De-asserted IRQ  34 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0035 ) 
              begin 
              vif.ext_int35_i = 0;
              $display(" De-asserted IRQ  35 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0036 ) 
              begin 
              vif.ext_int36_i = 0;
              $display(" De-asserted IRQ  36 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0037 ) 
              begin 
              vif.ext_int37_i = 0;
              $display(" De-asserted IRQ  37 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0038 ) 
              begin 
              vif.ext_int38_i = 0;
              $display(" De-asserted IRQ  38 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0039 ) 
              begin 
              vif.ext_int39_i = 0;
              $display(" De-asserted IRQ  39 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0040 ) 
              begin 
              vif.ext_int40_i = 0;
              $display(" De-asserted IRQ  40 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0041 ) 
              begin 
              vif.ext_int41_i = 0;
              $display(" De-asserted IRQ  41 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0042 ) 
              begin 
              vif.ext_int42_i = 0;
              $display(" De-asserted IRQ  42 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0043 ) 
              begin 
              vif.ext_int43_i = 0;
              $display(" De-asserted IRQ  43 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0044 ) 
              begin 
              vif.ext_int44_i = 0;
              $display(" De-asserted IRQ  44 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0045 ) 
              begin 
              vif.ext_int45_i = 0;
              $display(" De-asserted IRQ  45 ");
             end 
             
             else if (IRQ_de_assert == 'h00DD0046 ) 
              begin 
              vif.ext_int46_i = 0;
              $display(" De-asserted IRQ  46 ");
             end
               
     end
   endtask
   
   

endclass





