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
class asm_irq extends mailbox;

  `uvm_component_utils(asm_irq)

  function new(string name="asm_irq",uvm_component parent=null);
     super.new(name,parent);
  endfunction

 
 task main_phase(uvm_phase phase);  
    fork
      mailbox_print();
      init_irq(); 
      mailbox_1();
      mailbox_11();
      deassert_irq();
      irq_generation();

      //Random Number generation
      mailbox_1_flag_clear();
      mailbox_2();
      mailbox_2_flag_clear();
      end_sim();
    join_none
     result_check();
  endtask
  
    task int_generator(bit [5:0]int_no);

    if(int_no == 0 )
        vif.ext_int0_i = 1;
    else if ( int_no == 1 )
        vif.ext_int1_i =1;
       
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
    
    /*else if(int_no == 47 )
        vif.ext_int47_i = 1;*/
        
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
	       //vif.ext_int47_i = 0 ;

          end
          endtask

 


 
  //-----------------------------`MAILBOX_1 : Generate IRQ --------------------------------//
  task mailbox_11();

      forever 
        @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_1))
        begin

          mailbox_1_data  = vif.mem_wr_data;     	
         
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
             
             /*else if (IRQ_de_assert == 'h00DD0047 ) 
              begin 
              vif.ext_int47_i = 0;
              $display(" De-asserted IRQ  47 ");
             end */
     end
   endtask

task irq_generation();

        bit[31:0] int_no ;
        bit[31:0] count ;
        int rand_delay;

    forever begin
        @(posedge vif.riscv_clk);
     
        /////////////////// Multiplication /////////////////
        if(vif.opcode == 51  && vif.func3 == 0 && vif.func7 == 1) begin
            @(posedge vif.riscv_clk);
            if(vif.op1 == 111 && vif.op2 == 222) begin
             repeat(1) @(negedge vif.riscv_clk);
             repeat(1)  begin
              int_no = $urandom_range(0,46);
              int_generator(int_no);        
             end
            end
         end
        /////////////////// Addition /////////////////
         if(vif.opcode == 51  && vif.func3 == 0 && vif.func7 == 0) begin
            @(posedge vif.riscv_clk);
            if(vif.op1 == 111 && vif.op2 == 222) begin
             repeat(1) @(negedge vif.riscv_clk);
             repeat(1)  begin
              int_no = $urandom_range(0,46);
              int_generator(int_no);        
             end
            end
         end
         /////////////////// Subtraction /////////////////
         if(vif.opcode == 51  && vif.func3 == 0 && vif.func7 == 32) begin
            @(posedge vif.riscv_clk);
            if(vif.op1 == 111 && vif.op2 == 222) begin
             repeat(1) @(negedge vif.riscv_clk);
             repeat(1)  begin
              int_no = $urandom_range(0,46);
              int_generator(int_no);        
             end
            end
         end
         //////////////////   SLL  ///////////////////////////////////////////
         if(vif.opcode == 51  && vif.func3 == 1 && vif.func7 == 0) begin
            @(posedge vif.riscv_clk);
            if(vif.op1 == 111 && vif.op2 == 30) begin //[4:0] of rs2=222 is 30
             repeat(1) @(negedge vif.riscv_clk);
             repeat(1)  begin
              int_no = $urandom_range(0,46);
              int_generator(int_no);        
             end
            end
         end
         //////////////////   ADDI  ///////////////////////////////////////////
         if(vif.opcode == 19  && vif.func3 == 0) begin
            @(posedge vif.riscv_clk);
            if(vif.op1 == 111 && vif.op2 == 222) begin
             repeat(1) @(negedge vif.riscv_clk);
             repeat(1)  begin
              int_no = $urandom_range(0,46);
              int_generator(int_no);        
             end
            end
         end
         //////////////////   XORI  ///////////////////////////////////////////
         if(vif.opcode == 19  && vif.func3 == 4) begin
            @(posedge vif.riscv_clk);
            if(vif.op1 == 111 && vif.op2 == 222) begin
             repeat(1) @(negedge vif.riscv_clk);
             repeat(1)  begin
              int_no = $urandom_range(0,46);
              int_generator(int_no);        
             end
            end
         end
         //////////////////   BEQ  ///////////////////////////////////////////
         if(vif.opcode == 99  && vif.func3 == 0 && vif.in1 == 222 && vif.in2 == 222) begin
           repeat(1) @(negedge vif.riscv_clk);
             repeat(1)  begin
              int_no = $urandom_range(0,46);
              int_generator(int_no);        
             end
         end
         //////////////////   BNE  ///////////////////////////////////////////
         if(vif.opcode == 99  && vif.func3 == 1 && vif.in1 == 111 && vif.in2 == 222) begin
           repeat(1) @(negedge vif.riscv_clk);
             repeat(1)  begin
              int_no = $urandom_range(0,46);
              int_generator(int_no);        
             end
         end
         //////////////////   JAL  ///////////////////////////////////////////
         if(vif.opcode == 111) begin 
          repeat(3)  @(posedge vif.riscv_clk);
         if(vif.opcode == 111) begin 
          repeat(3)  @(posedge vif.riscv_clk);
         if(vif.opcode == 111) begin 
          repeat(3)  @(posedge vif.riscv_clk);
          if(vif.opcode == 111) begin 
          repeat(3)  @(posedge vif.riscv_clk);
         if(vif.opcode == 111) begin 
          repeat(3)  @(posedge vif.riscv_clk);
         if(vif.opcode == 111) begin 
          repeat(1) @(negedge vif.riscv_clk);
             repeat(1)  begin
              int_no = $urandom_range(0,46);
              int_generator(int_no);  
             end
         end
         end
         end
         end 
         end
         end
         //////////////////   JALR  ///////////////////////////////////////////
         if(vif.opcode == 103 && vif.func3 == 0 ) begin 
          repeat(3)  @(posedge vif.riscv_clk);
         if(vif.opcode == 103 && vif.func3 == 0 ) begin 
          repeat(3)  @(posedge vif.riscv_clk); 
         if(vif.opcode == 103 && vif.func3 == 0 ) begin 
          repeat(3)  @(posedge vif.riscv_clk);          
          if(vif.opcode == 103 && vif.func3 == 0 ) begin 
          repeat(3)  @(posedge vif.riscv_clk);
         if(vif.opcode == 103 && vif.func3 == 0 ) begin 
          repeat(3)  @(posedge vif.riscv_clk);
         if(vif.opcode == 103 && vif.func3 == 0 ) begin 
          repeat(1) @(negedge vif.riscv_clk);
             repeat(1)  begin
              int_no = $urandom_range(0,46);
              int_generator(int_no);  
             end
         end
         end
         end
         end
         end
         end
   
    end
endtask



endclass

