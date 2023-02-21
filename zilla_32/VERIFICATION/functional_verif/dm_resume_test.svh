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
`define clk_period 100                      //  10 MHz, unit: nano seconds
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
`define WRONG_ADDR        (7'h7F << 34)
`define OP_READ           (1 << 0)          //  Perform READ operation (OP = 1)
`define OP_WRITE          (2 << 0)          //  Perform WRITE operation (OP = 2)
`define OP_NOP            (0 << 0)          //  No operaton
`define DM_ACTIVE         (1 << 2)          //  Make DM_ACTIVE bit high in DM_CONTROL register
`define NDMRESET          (1 << 3)          //  Make NDMRESET bit high in DM_CONTROL register 
`define CLRRESETHALTREQ   (1 << 4)          //  Make CLRRESETHALTREQ bit high in DM_CONTROL register
`define SETRESETHALTREQ   (1 << 5)          //  Make SETRESETHALTREQ bit high in DM_CONTROL register
`define CLRKEEPALIVE      (1 << 6)          //  Make CLRKEEPALIVE  bit high in DM_CONTROL register
`define SETKEEPALIVE      (1 << 7)          //  Make SETKEEPALIVE bit high in DM_CONTROL register
`define HARTSELHI         (10'h << 8)       //  Higher 10 bits of HARTSEL in DM_CONTROL register
`define HARTSELLO         (10'h << 18)      //  Lower 10 bits of HARTSEL in DM_CONTROL register
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
`define STEP              (1 <<  4)         //  DCSR Step excecution field 
`define AARSIZE_32        (3'h2 << 22)      //  Access the lowest 32 bits of register in ABSTRACT_COMMAND_REGISTER
`define AARSIZE_64        (3'h3 << 22)      //  Access the lowest 64 bits of register in ABSTRACT_COMMAND_REGISTER
`define AARSIZE_128       (3'h4 << 22)      //  Access the lowest 128 bits of register in ABSTRACT_COMMAND_REGISTER
`define CMDTYPE_ARC       (8'h0 << 26)      //  ABSTRACTS command type = acces register command
`define CMDTYPE_QA        (8'h1 << 26)      //  ABSTRACTS command type = Quick Access
`define CMDTYPE_AMC       (8'h2 << 26)      //  ABSTRACTS command type = Acess Memory Command
`define CMDTYPE_WRNG      ($urandom_range(3,255) << 26)      // Wrong ABSTRACTS command type 
`define AAMSIZE_8         (3'h0 << 22)      //  Access the lowest 8 bits of the memory location.
`define AAMSIZE_16        (3'h1 << 22)      //  Access the lowest 16 bits of the memory location.
`define AAMSIZE_32        (3'h2 << 22)      //  Access the lowest 32 bits of the memory location.
`define AAMSIZE_64        (3'h3 << 22)      //  Access the lowest 64 bits of the memory location.
`define AAMSIZE_128       (3'h4 << 22)      //  Access the lowest 128 bits of the memory location.
`define AAMPOSTINCREMENT  (1 << 21) 
`define REG_NO(reg_no)    ((16'h1000 + reg_no) << 2)   // Addres for GPR base register
`define RELAXEDPRIV       (1 << 13)         //  Relaxed permissions applicable in ABSTRACT_CONTROL_AND_STATUS register
`define RANDOM_DATA       ($urandom() << 2 )
`define CSR_REG(csr_reg)  ((16'h0000 + csr_reg) << 2 )
`define GEN_PRINT         (1)
`define REG_PRINT         (2)
`define INPUT_DATA_PRINT  (3)
`define DMI_HARDRESET     (1 << 17 )
`define DMI_RESET         (1 << 16 )
`define DM                (10)
`define JTAG              (11)
`define CMDERR_CLR        ($urandom_range(1,7) << 10 )
`define DATA_MEM_BASE_ADDR      (32'h48120)
`define DATA_MEM_END_ADDR       (32'h87ff8)
`define INSTR_MEM_BASE_ADDR     (32'h8000)
`define INSTR_MEM_END_ADDR      (32'h47ff8)

class dm_resume_test extends mailbox;

  `uvm_component_utils(dm_resume_test)


    bit          DR_Scan_Array[] = {0,1,0,
                                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                    1,1,0};

    bit          IR_DR_Scan_Array[] = {0,1,1,0 , 
                                       0,0,0,0,0,
                                       1,1,1,0,
                                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                       1,1,0};

    bit          IR_DR_JTAG_Scan_Array[] = {0,1,1,0 , 
                                       0,0,0,0,0,
                                       1,1,1,0,
                                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                       1,1,0}; 

   bit          TMS_Array[] = { 1 ,1 , 1 , 1 , 1, //test logic reset state 
                                0 ,0, 0 , //run test idle state
                                1 , 1 ,1 , // moving back to test logic reset state
                                0 , 1, 1 , 0 ,
                                1 , 0 , 0 , 1 ,0 , 1 , 0 , 1 , 1 , 0,
                                1 , 0 ,1 , 0 , 0 , 1 ,0 , 1 , 0 , 1 , 1 , 1 , 1 , 1 ,
                                0 , 0 } ;
    
    bit [15:0]csr_addrs_array[]     ={  16'hF11, 16'hF12, 16'hF13, 16'hF14, 16'h300, 16'h301, //16'h302,
                                       /* 16'h303,*/ 16'h304, 16'h305, /*16'h306,*/ 16'h340, 16'h341, 16'h342,
                                        16'h343, 16'h344, 16'hB00, 16'hB02, 16'hB03, 16'hB04, 16'hB05,
                                        16'hB06, 16'hB07, 16'hB08, 16'hB09, 16'hB0A, 16'hB0B, 16'hB0C,
                                        16'hB0D, 16'hB0E, 16'hB0F, 16'hB10, 16'hB11, 16'hB12, 16'hB13,
                                        16'hB14, 16'hB15, 16'hB16, 16'hB17, 16'hB18, 16'hB19, 16'hB1A,
                                        16'hB1B, 16'hB1C, 16'hB1D, 16'hB1E, 16'hB1F, 16'h320, 16'h323,
                                        16'h324, 16'h325, 16'h326, 16'h327, 16'h328, 16'h329, 16'h32A,
                                        16'h32B, 16'h32C, 16'h32D, 16'h32E, 16'h32F, 16'h330, 16'h331,
                                        16'h332, 16'h333, 16'h334, 16'h335, 16'h336, 16'h337, 16'h338,
                                        16'h339, 16'h33A, 16'h33B, 16'h33C, 16'h33D, 16'h33E, 16'h33F,
                                        16'hBC0, 16'hFC0, 16'hFC1 , 16'h7B0 ,16'h7B1  } ; 

        // Parameters for instructions
    localparam IDCODE     = 5'h01; // IDCODE Instruction
    localparam BYPASS     = 5'h1F; // BYPASS Instruction
    localparam DTM_CSR    = 5'h10; // DTM Control & Status Instruction
    localparam DMI_ACCESS = 5'h11; // DMI_ACCESS Instruction
    localparam COMMAND    = 5'h17; // COMMAND Instruction

    bit [63:0] TDO_data = 0; 
    bit [4:0]  instr_reg = 0;
    bit flag ;
    logic [1:0] op ;

    logic [63:0]data_array [int];
    logic [31:0]instr_array [int] ;
    logic [31:0]addrs ;
    logic [63:0]addrs_64 ; 
    logic [2:0]aamsize ;
    int count ;
    logic [4:0]reg_no ;
    logic [63:0]random_data ;
    logic [63:0]memory_content ;
    logic [31:0]instr_content ; 
    logic data_mem_op = 1;
    logic TAP_STATE = 0 ;
    
    int count_data = 0 ; 
    int intr_no ; 
    int rand_delay , count_cycle ;
    logic aligned = 1'b0; 
  function new(string name="debug_test",uvm_component parent=null);
     super.new(name,parent);
  endfunction
 
 task main_phase(uvm_phase phase);  
    fork
    `ifndef OPEN_OCD
      JTAG_Clock_Generation();
      JTAG_Reset_Generation();
      debug_cases();

      mailbox_print();
      mailbox_1();
      mailbox_1_flag_clear();
      mailbox_2();
      mailbox_2_flag_clear();
      deassert_irq();
      init_irq(); 
    `endif
    join_none
  endtask


function void load_data_memory() ;

foreach(r_config.data_memory[i])
    begin
      r_config.data_memory[i] = '0;
      ref_model.memory[i] = '0; 
    end

foreach(r_config.data_array[i])
    begin
      {r_config.data_memory[((i*8)+`DATA_MEM_START_ADDR_H+7)],
       r_config.data_memory[((i*8)+`DATA_MEM_START_ADDR_H+6)],
       r_config.data_memory[((i*8)+`DATA_MEM_START_ADDR_H+5)],
       r_config.data_memory[((i*8)+`DATA_MEM_START_ADDR_H+4)],
       r_config.data_memory[((i*8)+`DATA_MEM_START_ADDR_H+3)],
       r_config.data_memory[((i*8)+`DATA_MEM_START_ADDR_H+2)],
       r_config.data_memory[((i*8)+`DATA_MEM_START_ADDR_H+1)],
       r_config.data_memory[(i*8)+`DATA_MEM_START_ADDR_H]} = r_config.data_array[i];
      
     end


   foreach(r_config.data_memory[i])
    begin
      ref_model.memory[i] = r_config.data_memory[i]; 
    end

endfunction


task JTAG_Clock_Generation();
        vif.jtag_TCK = 0;  
        vif.jtag_TMS = 0; 
        vif.jtag_TDI = 0; 
      //  vif.jtag_TRSTn = 0; 
        forever #(`clk_period/2) vif.jtag_TCK = ~ vif.jtag_TCK;  //clock generation
endtask

task JTAG_Reset_Generation();
        vif.jtag_TRSTn = 1;
        repeat($urandom_range(3,5)) @(posedge vif.jtag_TCK); 
        vif.jtag_TRSTn = 0;
        repeat($urandom_range(3,5)) @(posedge vif.jtag_TCK); 
        #2; 
        vif.jtag_TRSTn = 1; 

endtask

task IR_DR_JTAG_Scan(input bit [4:0]instruction_reg = 5'h01 ,input bit [31:0]TDI_Data = 32'h0  ); 
    if(!TAP_STATE) begin
        TDO_data = 0;
          foreach(IR_DR_JTAG_Scan_Array[i])
          begin
            @(posedge vif.jtag_TCK); 
            vif.jtag_TMS = IR_DR_JTAG_Scan_Array[i];
                if(i >= 5 && i <= 9)
                begin
                    vif.jtag_TDI = instruction_reg[i-5];  
                end

               else if(i>= 14 && i <(14 + 32))
                begin
                    vif.jtag_TDI = TDI_Data[i-14];  
                end
                else
                    vif.jtag_TDI = 0; 
             
                if(i >= 13 && i < (13+32))
                begin
                    @(negedge vif.jtag_TCK);
                    #0.1;    
                    TDO_data = TDO_data | (vif.jtag_TDO << (i-13)); 
                end 

          end 
        vif.jtag_TMS = 0; 
        $display("IR_DR_JTAG_SCAN:\tJTAG Register = %0h\t DM Register = %0h, TDO value = 0x %04h_%04h",instruction_reg,TDI_Data[40:34],TDO_data[31:16],TDO_data[15:0]); 
    return; 

   end
    else begin
        foreach(TMS_Array[i])
          begin
            @(posedge vif.jtag_TCK); 
            vif.jtag_TMS = TMS_Array[i];
          end

          return ; 
    end
endtask


    task IR_DR_Scan(input bit [4:0]instruction_reg,input bit [40:0]TDI_Data , input int module_name = `DM ); 

        TDO_data = 0;
          foreach(IR_DR_Scan_Array[i])
          begin
            @(posedge vif.jtag_TCK); 
            vif.jtag_TMS = IR_DR_Scan_Array[i];
                if(i >= 5 && i <= 9)
                begin
                    vif.jtag_TDI = instruction_reg[i-5];  
                end

                else if(module_name ==`DM &&i >= 14 && i < (41+14))
                begin
                    vif.jtag_TDI = TDI_Data[i-14];  
                end
               
                else
                    vif.jtag_TDI = 0; 
       
                if(module_name == `DM && i >= 15 && i < (15+32))
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


    task DR_Scan(input bit [4:0]instruction_reg,input bit [40:0]TDI_Data , input int __print=0 , input string __print_statement = "" ); 
        TDO_data = 0;
        op = 0 ; 
          foreach(DR_Scan_Array[i])
          begin
            @(posedge vif.jtag_TCK); 
            vif.jtag_TMS = DR_Scan_Array[i];
                if(i >= 4 && i < (41+4))
                begin
                    vif.jtag_TDI = TDI_Data[i-4];  
                end
                else
                    vif.jtag_TDI = 0; 

                if(i >= 3 && i < (3+2))
                begin
                    @(negedge vif.jtag_TCK);
                    #0.1;    
                    op = op | (vif.jtag_TDO << (i-3)); 
                end
 
                if(i >= 5 && i < (5+32))
                begin
                    @(negedge vif.jtag_TCK);
                    #0.1;    
                    TDO_data = TDO_data | (vif.jtag_TDO << (i-5)); 
                end

          end 
        vif.jtag_TMS = 0;

       if(__print == `GEN_PRINT)
           $display("DR_SCAN:\tJTAG Register = %0h\t DM Register = %0h, TDO value = 0x %04h_%04h\t OP=%0d",instruction_reg,TDI_Data[40:34],TDO_data[31:16],TDO_data[15:0] , op);
       else if(__print == `REG_PRINT)
           $display("DR_SCAN:\t%s = %0h\tOP=%0d " , __print_statement, TDO_data[31:0] , op );  
       else if(__print == `INPUT_DATA_PRINT)
           $display("DR_SCAN:\t%s = %0h\t" , __print_statement ,TDI_Data[33:2] ) ; 
    return   ;  
    endtask

task debug_random_drive() ;
   case ($urandom_range(0 , 16))
        0 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
        1 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ ));
        2 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HARTRESET ));
        3 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `SETRESETHALTREQ ));
        4 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `CLRRESETHALTREQ ));
        5 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `NDMRESET ));
        6 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `CLRRESETHALTREQ ));
        7 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `HALTREQ ));
        8 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `RESUMEREQ ));
        9 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `HARTRESET ));
       10 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `SETRESETHALTREQ ));
       11 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `CLRRESETHALTREQ ));
       12 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `NDMRESET ));
       13 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `CLRRESETHALTREQ ));
       14 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `ACKHAVERESET ));
       15 : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `ACKHAVERESET ));
      default : DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  ));
    endcase
endtask 

 task debug_cases() ;
    
        vif.jtag_TMS = 1 ;
        @(posedge vif.jtag_TRSTn);

        `ifdef ZILLA_64_BIT
            $display("/////////////////////////////////////////////////////////////////////////");
            $display("//            Runnning 64 Bit Parameter Cases                          //");
            $display("/////////////////////////////////////////////////////////////////////////");
         `else
            $display("/////////////////////////////////////////////////////////////////////////");
            $display("//            Runnning 32 Bit Parameter Cases                          //");
            $display("/////////////////////////////////////////////////////////////////////////");
         `endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Test Case : Wait Till EBREAK is Asserted , once asserted resume the hart
//              replacing ebreak instruction with nop operation             
////////////////////////////////////////////////////////////////////////////////////////////////////
 
 `ifdef ZILLA_64_BIT
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  )); 
        wait(vif.OUT_instruction == 'h00100073 ) ;
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  )); 
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_64 |`TRANSFER_REG | `WRITE_R_A | `CSR_REG(16'h7b1)));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR ));
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA0_ADDR ) , `REG_PRINT , $sformatf("Read:DPC:\t") );
        addrs = TDO_data[31:0]  ;
        $display("\n") ; 
        $display("Addres of Next Instruction = %0h" , addrs) ;
        if( (addrs % 8) != 0) begin
            aligned = 1'b1 ;        //ebreak instrution at aligned pc 
            addrs = addrs - 4 ;
            end
        else begin
            aligned = 1'b0 ;       //ebreak instruction is at non-aligned pc addres
            addrs = addrs - 8 ; 
            end
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | (addrs << 2) ) );
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (0 << 2)  )) ; 
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR |`CMDTYPE_AMC  | `AAMSIZE_64 | `WRITE_R_A ) );
        if(aligned == 1'b 0)
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | (32'h00000013<<2)) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_1_reg"  ));
        else
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | (32'h00000013<<2)) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_1_reg"  ));

        DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR |`CMDTYPE_AMC  | `AAMSIZE_64 | `WRITE_A_R ) );

        //reading from same addres
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR |`CMDTYPE_AMC  | `AAMSIZE_64 | `WRITE_R_A ) );
        DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR | `RANDOM_DATA   ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_0_reg");
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_1_reg");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ ));
   `endif
    repeat(5) begin
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ ));
    end

  
    repeat(20) 
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE ));

    r_config.instructions_executed_count=r_config.no_of_instructions;

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
 

endclass


