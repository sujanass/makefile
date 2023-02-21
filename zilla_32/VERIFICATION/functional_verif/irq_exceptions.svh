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
//module Reg_JTAG(
`define clk_period 100                       //  100 MHz, unit: nano seconds
`define DM_CONTROL        (7'h10 << 34)     //  Enable DM_CONTROL Register with address 7'h10
`define DM_STATUS         (7'h11 << 34)     //  Enable DM_STATUS Register with address 7'h11
`define HART_INFO         (7'h12 << 34)     //  Enable HART_INFO Register with address 7'h12
`define ABSTRACTCS_ADDR   (7'h16 << 34)	    //  Definition for Abstractcs register address
`define COMMAND_ADDR      (7'h17 << 34)		//  Definition for Command register address
`define	PROGBUFF0_ADDR    (7'h20 << 34)		//  Definition for Program buffer 0 register address
`define	PROGBUFF1_ADDR    (7'h21 << 34)		//  Definition for Program buffer 1 register address
`define	PROGBUFF2_ADDR    (7'h22 << 34)		//  Definition for Program buffer 2 register address
`define	PROGBUFF3_ADDR    (7'h23 << 34)		//  Definition for Program buffer 3 register address
`define	PROGBUFF4_ADDR    (7'h24 << 34)		//  Definition for Program buffer 4 register address
`define	PROGBUFF5_ADDR    (7'h25 << 34)		//  Definition for Program buffer 5 register address
`define	PROGBUFF6_ADDR    (7'h26 << 34)		//  Definition for Program buffer 6 register address
`define	PROGBUFF7_ADDR    (7'h27 << 34)		//  Definition for Program buffer 7 register address
`define	PROGBUFF8_ADDR    (7'h28 << 34)		//  Definition for Program buffer 8 register address
`define	PROGBUFF9_ADDR    (7'h29 << 34)		//  Definition for Program buffer 9 register address
`define	PROGBUFF10_ADDR   (7'h2A << 34)		//  Definition for Program buffer 10 register address
`define	PROGBUFF11_ADDR   (7'h2B << 34)		//  Definition for Program buffer 11 register address
`define	PROGBUFF12_ADDR   (7'h2C << 34)		//  Definition for Program buffer 12 register address
`define	PROGBUFF13_ADDR   (7'h2D << 34)		//  Definition for Program buffer 13 register address
`define	PROGBUFF14_ADDR   (7'h2E << 34)		//  Definition for Program buffer 14 register address
`define	PROGBUFF15_ADDR   (7'h2F << 34)		//  Definition for Program buffer 15 register address
`define	DATA0_ADDR 	      (7'h04 << 34)		//  Definition for Data0 register address
`define	DATA1_ADDR        (7'h05 << 34)		//  Definition for Data1 register address
`define	DATA2_ADDR        (7'h06 << 34)		//  Definition for Data2 register address
`define DATA3_ADDR        (7'h07 << 34)		//  Definition for Data3 register address
`define	DATA4_ADDR        (7'h08 << 34)		//  Definition for Data4 register address
`define	DATA5_ADDR        (7'h09 << 34)		//  Definition for Data5 register address
`define	DATA6_ADDR        (7'h0A << 34)		//  Definition for Data6 register address
`define	DATA7_ADDR        (7'h0B << 34)		//  Definition for Data7 register address
`define	DATA8_ADDR        (7'h0C << 34)		//  Definition for Data8 register address
`define	DATA9_ADDR        (7'h0D << 34)		//  Definition for Data9 register address
`define	DATA10_ADDR       (7'h0E << 34)		//  Definition for Data10 register address
`define	DATA11_ADDR       (7'h0F << 34)		//  Definition for Data11 register address
`define OP_READ           (1 << 0)          //  Perform READ operation (OP = 1)
`define OP_WRITE          (2 << 0)          //  Perform WRITE operation (OP = 2)
`define OP_NOP            (0 << 0)          //  No operaton
`define DM_ACTIVE         (1 << 2)          //  Make DM_ACTIVE bit high in DM_CONTROL register
`define NDMRESET          (1 << 3)          //  Make NDMRESET bit high in DM_CONTROL register 
`define CLRRESETHALTREQ   (1 << 4)          //  Make CLRRESETHALTREQ bit high in DM_CONTROL register
`define SETRESETHALTREQ   (1 << 5)          //  Make SETRESETHALTREQ bit high in DM_CONTROL register
`define CLRKEEPALIVE      (1 << 6)          //  Make CLRKEEPALIVE  bit high in DM_CONTROL register
`define SETKEEPALIVE      (1 << 7)          //  Make SETKEEPALIVE bit high in DM_CONTROL register
//`define HARTSELHI         (10'h << 8)      //  Higher 10 bits of HARTSEL in DM_CONTROL register
//`define HARTSELLO         (10'h << 18)     //  Lower 10 bits of HARTSEL in DM_CONTROL register
`define HASEL             (1 << 28)         //  Make HASEL bit high in DM_CONTROL register
`define ACKUNAVAIL        (1 << 29)         //  Make ACKUNAVAIL bit high in DM_CONTROL register
`define ACKHAVERESET      (1 << 30)         //  Make ACKHAVERESET bit high in DM_CONTROL register
`define HARTRESET         (1 << 31)         //  Make HARTRESET bit high in DM_CONTROL register
`define RESUMEREQ         (1 << 32)         //  Make RESUMEREQ bit high in DM_CONTROL register
`define HALTREQ           (1 << 33)         //  Make HALTREQ bit high in DM_CONTROL register
`define WRITE_R_A         (0 << 18)         //  When transfer is set, copy data from Reg into ARG0 in ABSTRACT_COMMAND_REGISTER
`define WRITE_A_R         (1 << 18)         //  When transfer is set, copy data from ARG0 into Reg in ABSTRACT_COMMAND_REGISTER
`define TRANSFER_REG      (1 << 19)         //  Do the specified operation by write in ABSTRACT_COMMAND_REGISTER
`define POSTEXEC          (1 << 20)         //  Execute the program in the Program Buffer exactly once after performing the transfer(if any) in ABSTRACT_COMMAND_REGISTER
`define AARPOSTINCREMENT  (1 << 21)         //  in ABSTRACT_COMMAND_REGISTER
`define AARSIZE_32        (3'h2 << 22)      //  Access the lowest 32 bits of register in ABSTRACT_COMMAND_REGISTER
`define AARSIZE_64        (3'h3 << 22)      //  Access the lowest 64 bits of register in ABSTRACT_COMMAND_REGISTER
`define AARSIZE_128       (3'h4 << 22)      //  Access the lowest 128 bits of register in ABSTRACT_COMMAND_REGISTER
`define CMDTYPE_ARC       (8'h0 << 26)      //  ABSTRACTS command type = acces register command
`define CMDTYPE_QA        (8'h1 << 26)      //  ABSTRACTS command type = Quick Access
`define CMDTYPE_AMC       (8'h2 << 26)      //  ABSTRACTS command type = Acess Memory Command
`define REG_NO(reg_no)    ((16'h1000 + reg_no) << 2)   // Addres for GPR base register
//`define CMDERR            (3'h << 8)       //  in ABSTRACT_CONTROL_AND_STATUS register
`define RELAXEDPRIV       (1 << 13)         //  Relaxed permissions applicable in ABSTRACT_CONTROL_AND_STATUS register
`define RANDOM_DATA       ($urandom() << 2 )
`define CSR_REG(csr_reg)  ((16'h0000 + csr_reg) << 2 )
`define GEN_PRINT         (1)
`define REG_PRINT         (2)
`define INPUT_DATA_PRINT  (3)
`define DMI_HARDRESET     (1<<17)
`define DMI_RESET         (1 << 16 )
`define DM                (10)
`define JTAG              (11)
`define CMDERR_CLR        ($urandom_range(1,7) << 10 )



class irq_exceptions extends mailbox;
   
    // Parameters for instructions
    localparam IDCODE     = 5'h01; // IDCODE Instruction
    localparam BYPASS     = 5'h1F; // BYPASS Instruction
    localparam DTM_CSR    = 5'h10; // DTM Control & Status Instruction
    localparam DMI_ACCESS = 5'h11; // DMI_ACCESS Instruction
    localparam COMMAND    = 5'h17; // COMMAND Instruction
    bit          IR_DR_Scan_Array[] = {0,1,1,0 , 
                                       0,0,0,0,0,
                                       1,1,1,0,
                                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                       1,1,0};  

  `uvm_component_utils(irq_exceptions)

  function new(string name="irq_exceptions",uvm_component parent=null);
     super.new(name,parent);
  endfunction
 
 task main_phase(uvm_phase phase);  
    fork
      //IRQ related
      mailbox_print();
      init_irq(); 
      mailbox_11();
      deassert_irq();
      mailbox_exp();
      //Random number generation
      mailbox_1();
      mailbox_1_flag_clear();
      mailbox_2();
      mailbox_2_flag_clear();
      end_sim();
      jtag_initialisation();
      ebreak_exit_handler(); 
    join_none
  endtask
  

  task jtag_initialisation();
       vif.jtag_TCK = 0;  
       vif.jtag_TMS = 0; 
       vif.jtag_TDI = 0; 
       vif.jtag_TRSTn = 0; 
        forever #(`clk_period/2) vif.jtag_TCK = ~vif.jtag_TCK;  //clock generation
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
             repeat(1) @(posedge vif.riscv_clk);
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
              rand_int.randomize();
              int_generator(rand_int.rand_int);
             end
          end 

           else if(mailbox_1_data == 'h00AA0032) //Random n Interrupt Generation 
             begin
             random_int_no rand_int = new() ;
             repeat(1) @(negedge vif.riscv_clk);
             count = $urandom_range(1,48) ;
             repeat(count)
             begin
              rand_int.randomize();
              int_generator(rand_int.rand_int);
             end
          end 

          else if(mailbox_1_data == 'h00AA0033) //Random n ( n=20) Interrupt Generation with Random Delay
             begin
            // random_int_no rand_int = new() ;
             repeat(1) @(posedge vif.riscv_clk);
             repeat(20)
             begin
              rand_delay = $urandom_range(0,10) ;
              count = $urandom_range(0, 500) ;
              repeat(count) @(posedge vif.riscv_clk);
              #(rand_delay * 1ns);
              int_no = $urandom_range(0,46);
             // rand_int.randomize();
              int_generator(int_no);
             end
          end

        
           else if(mailbox_1_data == 'h00AA0034) //Random n Interrupt Generation at a perticular time 
             begin
             random_int_no rand_int = new() ;
             repeat(1) @(posedge vif.riscv_clk);
             //count = $urandom_range(1,48) ;
             rand_delay = $urandom_range(0,10) ;
              #(rand_delay * 1ns);
             repeat(10)
             begin
              rand_int.randomize();
              int_generator(rand_int.rand_int);
             end
          end  

      
          //  Scenario 1 : Same Levels and Priority  - Different IDs
          // Scenario 2 : Different Level and priorties : Without nesting 

          else if(mailbox_1_data == 'h00BB0001) // TBD - De-assert through mailbox : before TRAP_EXIT 
            begin 
             repeat(1) @(posedge vif.riscv_clk);
             vif.ext_int1_i = 1;
             vif.ext_int2_i = 1;
             $display("Generate IRQ 1 and 2 :Enabled ");
             repeat(5) @(posedge vif.riscv_clk);
             vif.ext_int1_i = 0;
             vif.ext_int2_i = 0;
             $display(" De-asserted IRQ : 1 and 2 ");
          end
          else if(mailbox_1_data == 'h00BB0002) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             vif.ext_int1_i = 1;
             vif.ext_int2_i = 1;
             vif.ext_int3_i = 1;
             vif.ext_int4_i = 1;

             $display("Generate IRQ 1 and 2 ,3,4 :Enabled ");
             repeat(5) @(posedge vif.riscv_clk);
             vif.ext_int1_i = 0;
             vif.ext_int2_i = 0;
             vif.ext_int3_i = 0;
             vif.ext_int4_i = 0;

             $display(" De-asserted IRQ : 1 and 2 , 3, 4 ");
          end
          else if(mailbox_1_data == 'h00BB0003) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
         
             vif.ext_int2_i = 1;
             vif.ext_int3_i = 1;
             vif.ext_int6_i = 1;
             vif.ext_int7_i = 1;

             $display("Generate IRQ 2,3,6,7:Enabled ");
             repeat(5) @(posedge vif.riscv_clk);
             vif.ext_int2_i = 0;
             vif.ext_int3_i = 0;
             vif.ext_int6_i = 0;
             vif.ext_int7_i = 0;

             $display(" De-asserted IRQ :2,3,6,7");
          end
           

          else if(mailbox_1_data == 'h00BB0004) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             vif.ext_int5_i = 1;  // Base : 0x10 : 16 + IRQ_n : EOI_ID
             vif.ext_int15_i = 1;
             vif.ext_int35_i = 1;
             vif.ext_int45_i = 1;

             $display("Generate IRQ 5,15,35, 45:Enabled ");
             repeat(5) @(posedge vif.riscv_clk);
             vif.ext_int5_i = 0;
             vif.ext_int15_i = 0;
             vif.ext_int35_i = 0;
             vif.ext_int45_i = 0;
             $display(" De-asserted IRQ  5,15,35, 45");

            end


          //Scenario 3 : Nesting interrupts

          else if(mailbox_1_data == 'h00CC0001) //Nesting maximum  levels : 9 interrupts : 0-7 levels
            begin 
             repeat(1) @(posedge vif.riscv_clk);
             vif.ext_int10_i = 1; //L0 , P7
             repeat(15) @(posedge vif.riscv_clk);
             vif.ext_int5_i  = 1; //L1 , P6
             repeat(30) @(posedge vif.riscv_clk);
             vif.ext_int18_i = 1; //L2 , P3
             repeat(40) @(posedge vif.riscv_clk);
             vif.ext_int28_i = 1; //L3 , P6
             repeat(50) @(posedge vif.riscv_clk);
             vif.ext_int4_i  = 1; //L4 , P4
             repeat(57) @(posedge vif.riscv_clk);
             vif.ext_int35_i = 1; //L5 , P5
             repeat(79) @(posedge vif.riscv_clk);
             vif.ext_int6_i  = 1; //L7 , P1
             repeat(90) @(posedge vif.riscv_clk);
             vif.ext_int45_i = 1; //L7 , P7

             $display("Generate IRQ with all levels - Increasing - Nesting :Enabled ");
           end
          else if(mailbox_1_data == 'h00CC0002) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             vif.ext_int6_i  = 1; //L7 , P1
             vif.ext_int45_i = 1; //L7 , P7 
             vif.ext_int35_i = 1; //L5 , P5
             vif.ext_int4_i  = 1; //L4 , P4
             vif.ext_int28_i = 1; //L3 , P6
             vif.ext_int18_i = 1; //L2 , P3
             vif.ext_int5_i  = 1; //L1 , P6
             vif.ext_int10_i = 1; //L0 , P7                                                                              

             $display("Generate IRQ with all levels - Decreasing order : Enabled ");
             
          end
          else if(mailbox_1_data == 'h00CC0003) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             vif.ext_int1_i  = 1; //L4 , P1
             vif.ext_int5_i  = 1; //L1 , P6
             vif.ext_int18_i = 1; //L2 , P3
             vif.ext_int28_i = 1; //L3 , P6
             vif.ext_int35_i = 1; //L5 , P3
             vif.ext_int2_i  = 1; //L4 , P2
             vif.ext_int38_i = 1; //L4 , P7 
             vif.ext_int15_i = 1; //L5 , P3
             vif.ext_int45_i  = 1; //L7 , P7
             $display("Generate IRQ with random levels : Enabled ");
          end
           
          else if(mailbox_1_data == 'h00CC0004) //GEN_IRQ
           begin 
             repeat(1) @(posedge vif.riscv_clk);
             vif.ext_int5_i = 1;
             repeat(7) @(posedge vif.riscv_clk);
             vif.ext_int15_i = 1;
             repeat(49) @(posedge vif.riscv_clk);
             vif.ext_int35_i = 1;
             repeat(149) @(posedge vif.riscv_clk);
             vif.ext_int45_i = 1;

             $display("Generate IRQ 5,15,35, 45:Enabled ");
         
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

task mailbox_exp(); // task to get exception id
      forever 
        @(posedge vif.riscv_clk )
        begin
         	 if(vif.exception_valid)
              begin
               for(int i = 0; i<8; i++)
                begin
               r_config.data_memory[`MAILBOX_1+i] = vif.exception_id;
               ref_model.memory[`MAILBOX_1+i] = vif.exception_id;
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
       $display("time = %dns  zilla_core - `MAILBOX_2_FLAG_SET = 0x%0h",$stime,vif.mem_wr_data);
       repeat(1) @(posedge vif.riscv_clk);
       $display("time = %dns  zilla_core - `MAILBOX_2_FLAG_CLEAR = 0x%0h",$stime,clear_flag); 
       for(int i = 0; i<8; i++)
       begin
         r_config.data_memory[mailbox_2_flag_addr+i] = clear_flag[(i*8)+:8]; 
         ref_model.memory[mailbox_2_flag_addr+i] = clear_flag[(i*8)+:8];
       end 
     end
   endtask
     //--------------------------------------------------------------------------------//
//-----------------E BREAK SEQENCE ----------------------------------------//

task ebreak_exit_handler();
       //reset generation
        vif.jtag_TRSTn = 0;
        repeat($urandom_range(3,5)) @(posedge vif.jtag_TCK); 
        vif.jtag_TRSTn = 1;   

       forever
       @(posedge vif.riscv_clk iff (vif.exception_valid) && vif.exception_id == 8'd3 )
       begin
               $display("EBREAK Exception Came"); 
               vif.jtag_TMS = 1; 
               IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ )); 
               $display("RESUME REQUEST asserted");
       end 
    return; 

    endtask

             



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
        //  $display("\tmemory_check - OPERAND1 = 0x%0h OPERAND2 = 0x%0h RESULT = 0x%0h",data_q[i],data_q[i+1],data_q[i+2]);

   endtask


 task IR_DR_Scan(input bit [4:0]instruction_reg,input bit [40:0]TDI_Data  ); 

        bit [63:0] TDO_data = 0;
          foreach(IR_DR_Scan_Array[i])
          begin
            @(posedge vif.jtag_TCK); 
            vif.jtag_TMS = IR_DR_Scan_Array[i];
                if(i >= 5 && i <= 9)
                begin
                    vif.jtag_TDI = instruction_reg[i-5];  
                end

                else if(i >= 14 && i < (41+14))
                begin
                    vif.jtag_TDI = TDI_Data[i-14];  
                end

                else
                    vif.jtag_TDI = 0; 
       
                if(i >= 15 && i < (15+32))
                begin
                    @(negedge vif.jtag_TCK);
                    #0.1;    
                    TDO_data = TDO_data | (vif.jtag_TDO << (i-15)); 
                end 
          end 
        vif.jtag_TMS = 0; 
        $display("IR_DR_SCAN:\tJTAG Register = %0h\t DM Register = %0h, TDO value = 0x %04h_%04h",instruction_reg,TDI_Data[40:34],TDO_data[31:16],TDO_data[15:0]); 
    return; 

    endtask


endclass

