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

class debug_test extends mailbox;

  `uvm_component_utils(debug_test)


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
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE ));
   `endif

/////////////////////////////////////////////////////////////////////////////////////////////////
//     Test case:   Halting the Hart and Resuming the Hart
//     Checked  : dmstatus , fsm state switching , pc stalling and pc resuming
////////////////////////////////////////////////////////////////////////////////////////////////
        //HART REQUEST - Halting the Hart
        $display("HALT REQUEST asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DM_STATUS ) , `GEN_PRINT);

        //RESUME REQUEST - Resuming the Hart
        $display("RESUME REQUEST asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `RESUMEREQ | `DM_ACTIVE )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DM_STATUS ) , `GEN_PRINT);

/////////////////////////////////////////////////////////////////////////////////////////////////
///    Test Case : Random FSM switching    
//     verified  : state transition , dmstatus for different dmcontrol, dpc , pc
///////////////////////////////////////////////////////////////////////////////////////////////

       repeat($urandom_range(50, 100))debug_random_drive() ;
       DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  | `CLRRESETHALTREQ )); //disbling haltonreset feauture 

////////////////////////////////////////////////////////////////////////////////////////////
//      Test Case: hart to reset state and resumereq after in reset state
//      checked  : dmstatus , resumereq shouldnot be acknowledged  
///////////////////////////////////////////////////////////////////////////////////////////

      //test case: resumereq when hart is in reset state, this request shouldn't be acknowledged and all/anyresumeack should be set low
       //HART RESET - resetting the Hart 
        $display("\nHART RESET asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HARTRESET )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_CONTROL ));
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DM_CONTROL ) , `GEN_PRINT);
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DM_STATUS ) , `GEN_PRINT);
        
        //RESUME REQUEST - Resuming the Hart
        $display("RESUME REQUEST asserted with hartreset=1");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HARTRESET |`RESUMEREQ )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DM_STATUS ) , `GEN_PRINT);

        $display("FSM Move to Normal Running state"); 
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DM_STATUS ) , `GEN_PRINT);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//      Test Case: NDMRESET 
//      Checked  :dmstatus , should reset core, pc should reset , ndmresetpending should go high 
//                all/anyhavereset should set to 1 
////////////////////////////////////////////////////////////////////////////////////////////////////////
     //ndmreset without dmactive
        //NDMRESET - 
        $display("NDM RESET asserted W/O Dmactive");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL   | `NDMRESET ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_CONTROL ));
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DM_CONTROL ) , `GEN_PRINT);
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ) );
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DM_STATUS ) , `GEN_PRINT);
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_CONTROL ));
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DM_CONTROL ) , `GEN_PRINT);

        $display("ACKNOWLEDGE HAVE RESET asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  | `ACKHAVERESET )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ) , `GEN_PRINT);
        
        $display("SETRESETHALTREQ asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE |`SETRESETHALTREQ ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE ));

       //ndmreset with dmactive
        $display("NDM RESET asserted with DMACTIVE");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL |`DM_ACTIVE  | `NDMRESET )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DM_STATUS ) , `GEN_PRINT);

        $display("ACKNOWLEDGE HAVE RESET asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  | `ACKHAVERESET )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ) , `GEN_PRINT);

//////////////////////////////////////////////////////////////////////////////////////////////////////
//             Test Case: Making DMACTIVE low and requesting haltreq, 
//             Checked  : dmstatus ,DM should reset , fsm state switching shoudn't happend to halt state , version shouldn't be read
//////////////////////////////////////////////////////////////////////////////////////////////////////

        //HALT REQUEST without enabling DMACTIVE, when dmactive is low -> Hart should not be halted and version should not be read
        $display("\nHALT REQUEST asserted without enabling DMACTIVE");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `HALTREQ )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DM_STATUS ), `GEN_PRINT);


//////////////////////////////////////////////////////////////////////////////////////////////////////
//             Test Case: Making DMACTIVE low and requesting setresethaltreq, 
//             Checked  : dmstatus ,DM should reset , fsm state switching shoudn't happend to halt state , version shouldn't be read
//////////////////////////////////////////////////////////////////////////////////////////////////////


        $display("\nHARTRESET Asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HARTRESET  | `SETRESETHALTREQ )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ) , `GEN_PRINT);

        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DM_STATUS ) , `GEN_PRINT);


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Test Case: fsm moved to hart reset,acknowledged using ackhavereset and again fsm back to normal state
//          Checked  : dmstatus , fsm switching , pc
//////////////////////////////////////////////////////////////////////////////////////////////////////////

        //HARTRESET - DMSTATUS all/anyhavereset should be set till ackhaveset = 1 
        $display("\nHART RESET asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HARTRESET  )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ), `GEN_PRINT);
        
        //ACKNOWLEDGE HAVE RESET - DMSTATUS all/anyhavereset should be cleared fsm will moved to normal state
        $display("ACKNOWLEDGE HAVE RESET asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `ACKHAVERESET  )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ) , `GEN_PRINT);

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Test Case: fsm moved to hart reset ,at this time resethaltreq=1 and again fsm back to normal state at this time resethaltreq=0
//          Checked  : dmstatus , fsm switching , pc
//////////////////////////////////////////////////////////////////////////////////////////////////////////

        //HARTRESET - DMSTATUS all/anyhavereset should be set till ackhaveset = 1 
        $display("\nHART RESET asserted with SETRESETHALTREQ=1");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HARTRESET | `SETRESETHALTREQ )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ) , `GEN_PRINT);
        
        //ACKNOWLEDGE HAVE RESET - DMSTATUS all/anyhavereset should be cleared fsm will moved to normal state
        $display("CLRRESETHALTREQ asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  | `CLRRESETHALTREQ )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ) , `GEN_PRINT);

        $display("ACKNOWLEDGE HAVE RESET asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  | `ACKHAVERESET )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ) , `GEN_PRINT);

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//      Test Case: FSM switcing from normal state to reset state after switching only serresethaltreq made high 
//      so upon deassertion of hartreset , fsm will be moved to halted state
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////
     
        $display("\nHART RESET asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HARTRESET  )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ) , `GEN_PRINT);
 
        
        $display("SETRESETHALTREQ asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE |`SETRESETHALTREQ ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ) , `GEN_PRINT);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//     Test Case: Moving from halted state to reset state, at tis clrresethaltreq = 1 , so resethaltreq = 0 
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        $display("\nHART RESET asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HARTRESET  )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ), `GEN_PRINT);

      
        $display("CLRRESETHALTREQ asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE |`CLRRESETHALTREQ )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DM_STATUS ), `GEN_PRINT );

        $display("FSM should move back to normal state");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE   )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DM_STATUS ), `GEN_PRINT );  
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Test Case : FSM moved from running state to hatled state then to reset state and again running state
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        $display("\nHALTREQ asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ  )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ), `GEN_PRINT);
      
        $display("HARTRESET asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE |`HARTRESET )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ), `GEN_PRINT );

        $display("FSM Move Back to Normal State");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE   )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ), `GEN_PRINT );  

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Test Case : FSM moved from running state to reset state then to halted state (through haltreq) then to running state
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
     
        $display("\nHARTRESET Asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HARTRESET  )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ), `GEN_PRINT);

        $display("HALTREQ Asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ), `GEN_PRINT );

        $display("RESUMEREQ Asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  | `RESUMEREQ )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ), `GEN_PRINT ); 

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Test Case : FSM moved from running state to reset state then to halted state (through setresethaltreq)
//              then to running state
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
     
        $display("\nHARTRESET Asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HARTRESET  )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ), `GEN_PRINT);
      
        $display("SETRESETHALTREQ Asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `SETRESETHALTREQ )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ), `GEN_PRINT );
       
        $display("RESUMEREQ Asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  | `RESUMEREQ )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ), `GEN_PRINT );         

        $display("CLRRESETHALTREQ Asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  | `CLRRESETHALTREQ ));

        $display("ACKNOWLEDGE HAVE RESET asserted");
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  | `ACKHAVERESET )); 
        DR_Scan(DMI_ACCESS,(`OP_READ | `DM_STATUS ));
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DM_STATUS ) , `GEN_PRINT);

////////////////////////////////////////////////////////////////////////////////
//  Test Case : halt and resumereq in multicycle instruction
////////////////////////////////////////////////////////////////////////////////
 `ifdef ZILLA_64_BIT
       $display("\nHART RESET asserted");
       IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HARTRESET  ));
       repeat(10) @(posedge vif.riscv_clk) ; 
       load_data_memory();
       IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE));
    
       wait(vif.OUT_instruction== 'h00078703 ) ;
       repeat($urandom_range(10 , 20 ))begin
       IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
       IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ ));
       IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  ));
       end
  `endif

/////////////////////////////////////////////////////////////////////////////////////
///     irq cases:   debug request in ISR       
/////////////////////////////////////////////////////////////////////////////////////
      
       // asseting interrupt  after debug mode
       $display("\nHART RESET asserted");
       IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `NDMRESET  ));
       repeat(10) @(posedge vif.riscv_clk) ; 
       load_data_memory(); 
       IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE));
    
       wait(vif.OUT_instruction== 'h00078703 ) ;
       IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
       IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ ));
       intr_no = $urandom_range(0,46) ;
       int_generator(intr_no) ; 
       IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  ));

       //debug mode while executing ISR
       wait(vif.OUT_instruction == 'h00078703 ) ;
       intr_no = $urandom_range(0,46) ;
       int_generator(intr_no) ; 
       IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
       IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ ));
       IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  ));
      
       //debug mode in random interrupt with nesting  
       wait(vif.OUT_instruction == 'h00078703 );
       repeat($urandom_range(5,10))
             begin
              rand_delay = $urandom_range(0,10) ;
              count_cycle = $urandom_range(0, 500) ;
              repeat(count_cycle) @(posedge vif.riscv_clk);
              #(rand_delay * 1ns);
              intr_no = $urandom_range(0,46);
              int_generator(intr_no);
              IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
              IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ ));
              IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE  ));
         end
   
       wait(vif.OUT_instruction == 'h00078703 );

//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
//      Writing  random data And Reading from data0 and data1 register
///////////////////////////////////////////////////////////////////////////////////////////////
            $display("\nWriting Random Data and Reading written Data from data0&1 reg") ; 
            IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ )); 
            repeat($urandom_range(6, 10)) begin
              DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , "Write:Data_0_reg");
              DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , "Write:Data_1_reg");
              DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , "Write:Data_2_reg");
              DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , "Write:Data_3_reg");
              DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR  | `RANDOM_DATA) , );
              DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_0_reg");
              DR_Scan(DMI_ACCESS,(`OP_READ | `DATA2_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_1_reg");
              DR_Scan(DMI_ACCESS,(`OP_READ | `DATA3_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_2_reg");
              DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA3_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_3_reg");
              $display("\n") ; 
            end

///////////////////////////////////////////////////////////////////////////////////////////
//      Test Case: Writing and Reading HART INFO Register
//
///////////////////////////////////////////////////////////////////////////////////////////

        $display("\nWriting And Reading HARTINFO Register ") ; 
            IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ )); 
            repeat($urandom_range(2,5)) begin
              DR_Scan(DMI_ACCESS,(`OP_WRITE | `HART_INFO  | `RANDOM_DATA) , `INPUT_DATA_PRINT , "Write:HART_INFO_REG:");
              DR_Scan(DMI_ACCESS,(`OP_READ | `HART_INFO  ) , );
              DR_Scan(DMI_ACCESS,(`OP_NOP | `HART_INFO   ) , `REG_PRINT , "Read:HART_INFO_REG");
              $display("\n") ; 
            end
//////////////////////////////////////////////////////////////////////////////////
//      Step Excecution : 
//////////////////////////////////////////////////////////////////////////////////
           
            IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ )); 
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `STEP) , `INPUT_DATA_PRINT , $sformatf("DCSR Register Write") );
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_32 |`TRANSFER_REG | `WRITE_R_A | `CSR_REG(16'h7b0) ));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR ));
            DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA0_ADDR ) , `REG_PRINT , $sformatf("DCSR Register Read") );
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ )); 

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Test Case: Writing and Reading from GPR                                                    //
/////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////Writing and reading from gpr with aarsize = 64 /////////////////////////////////////////////////////

`ifdef ZILLA_64_BIT
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ )); 
        $display("\nHALT REQUEST asserted");
        $display("\nTest Case:\t Reading from GPR , aarsize = 64") ; 
        
        
        //////////////////////////////Reading from GPR With aarsize = 64    ///////////////////////
        for(int i = 0 ; i < 32 ; i++) begin
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_64 |`TRANSFER_REG | `WRITE_R_A | `REG_NO(i)));
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_64  | `WRITE_R_A | `REG_NO(i)));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR ));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR ) , `REG_PRINT , $sformatf("Read:\tRegister[%0d]" , i) );
            DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR ) , `REG_PRINT , $sformatf("Read:\tRegister[%0d]" , i) );
            $display("\n") ; 
        end
        
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ )); 
        $display("RESUME REQUEST asserted");

/////////////////////Writing and reading from gpr with aarsize = 64 /////////////////////////////////////////////////////

        $display("\nTest Case:\t Writing and Reading from GPR , aarsize = 64") ; 
        $display("HALT REQUEST asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ )); 
        
        /////////////////writing value to 32 gpr with aarsize as 64bit       ////////////////////////
        for(int i = 0 ; i < 32 ; i++) begin
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tRegister[%0d]" , i ));
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | `RANDOM_DATA) ,`INPUT_DATA_PRINT ,  $sformatf("Write:\tRegister[%0d]" , i ));
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_64 |`TRANSFER_REG| `WRITE_A_R | `REG_NO(i)  ));
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_64 | `WRITE_A_R | `REG_NO(i)  ));
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA)  );
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | `RANDOM_DATA)  );
           
         //////////////////////////////Reading from GPR With aarsize = 64    ///////////////////////
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_64 |`TRANSFER_REG | `WRITE_R_A | `REG_NO(i)));
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_64  | `WRITE_R_A | `REG_NO(i)));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR ));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR ) , `REG_PRINT , $sformatf("Read:\tRegister[%0d]" , i) );
            DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR ) , `REG_PRINT , $sformatf("Read:\tRegister[%0d]" , i) );
            $display("\n") ; 
        end

`endif

//////////////////////////////Reading from GPR With aarsize = 32    ///////////////////////

        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ )); 
        $display("\nHALT REQUEST asserted");
        $display("\nTest Case:\t Reading from GPR , aarsize = 32") ; 
        
        
        for(int i = 0 ; i < 32 ; i++) begin
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_32 |`TRANSFER_REG | `WRITE_R_A | `REG_NO(i)));
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_32  | `WRITE_R_A | `REG_NO(i)));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR ));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR ) , `REG_PRINT , $sformatf("Read:\tRegister[%0d]" , i) );
            DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR ) , `REG_PRINT , $sformatf("Read:\tRegister[%0d]" , i) );
            $display("\n") ; 
        end
        
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ )); 
        $display("\nRESUME REQUEST asserted");


//////////////////////////////Writing And Reading from  GPR with aarsize = 32      ////////////////////////////////////////////////////
       

        $display("\nTest Case:\t Writing and Reading from GPR , aarsize = 32") ; 
        $display("HALT REQUEST asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ )); 
      
       //////////////////////   writing value to 32 gpr with aarsize as 32bit     /////////////////////////////////////////
       for(int i = 0 ; i < 32 ; i++) begin
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tRegister[%0d]" , i ));
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | `RANDOM_DATA) ,`INPUT_DATA_PRINT ,  $sformatf("Write:\tRegister[%0d]" , i ));
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_32 |`TRANSFER_REG| `WRITE_A_R | `REG_NO(i)  ));
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_32 | `WRITE_A_R | `REG_NO(i)  ));
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA)  );
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | `RANDOM_DATA)  ); 
         //////////////////////////////Reading from GPR With aarsize = 32    ///////////////////////
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_32 |`TRANSFER_REG | `WRITE_R_A | `REG_NO(i)));
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_32  | `WRITE_R_A | `REG_NO(i)));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR ));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR ) , `REG_PRINT , $sformatf("Read:\tRegister[%0d]" , i) );
            DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR ) , `REG_PRINT , $sformatf("Read:\tRegister[%0d]" , i) );
            $display("\n") ; 
        end

        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ )); 
        $display("\nRESUME REQUEST asserted");


 /////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                       Test Case: Writing and Reading from CSR                                       //
 /////////////////////////////////////////////////////////////////////////////////////////////////////////

`ifdef ZILLA_64_BIT 
    /////////////////////Reading from csr with aarsize = 64 /////////////////////////////////

        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ )); 
        $display("\nTest Case:\t Reading from CSR , aarsize = 64") ; 
        for(int i = 0 ; i < csr_addrs_array.size() ; i++) begin
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_64 |`TRANSFER_REG | `WRITE_R_A | `CSR_REG(csr_addrs_array[i])));
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_64  | `WRITE_R_A | `CSR_REG(csr_addrs_array[i])));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR ));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR ) , `REG_PRINT , $sformatf("CSR Register %0h Read" , csr_addrs_array[i]) );
            DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR ) , `REG_PRINT , $sformatf("CSR Register %0h Read" , csr_addrs_array[i]) );
            $display("\n") ; 
       end


    /////////////////////Writing reading from csr with aarsize = 64 /////////////////////////////////

        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ )); 
        $display("\nTest Case:\t Writing and Reading from CSR , aarsize = 64") ; 
       
        /////////////////writing value to  CSR with aarsize as 64bit       ////////////////////////
          for(int i = 0 ; i < csr_addrs_array.size() ; i++) begin
           DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("CSR Register %0h write" , csr_addrs_array[i]) );
           DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | `RANDOM_DATA) ,`INPUT_DATA_PRINT ,  $sformatf("CSR Register %0h write" , csr_addrs_array[i]) );
           DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_64 |`TRANSFER_REG| `WRITE_A_R | `CSR_REG(csr_addrs_array[i])  ));
           DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_64 | `WRITE_A_R | `CSR_REG(csr_addrs_array[i])  ));
          //end
      
         //////////////////////////////Reading from CSR With aarsize = 64    ///////////////////////
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_64 |`TRANSFER_REG | `WRITE_R_A | `CSR_REG(csr_addrs_array[i])));
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_64  | `WRITE_R_A | `CSR_REG(csr_addrs_array[i])));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR ));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR ) , `REG_PRINT , $sformatf("CSR Register %0h Read" , csr_addrs_array[i]) );
            DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR ) , `REG_PRINT , $sformatf("CSR Register %0h Read" , csr_addrs_array[i]) );
            $display("\n") ; 
        end

`endif
    //////////////////////////////Writing And Reading from  CSR with aarsize = 32      ////////////////////////////////////////////////////
      
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ )); 
        $display("\nTest Case:\t Reading from CSR , aarsize = 32") ; 
        for(int i = 0 ; i < csr_addrs_array.size() ; i++) begin
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_32 |`TRANSFER_REG | `WRITE_R_A | `CSR_REG(csr_addrs_array[i])));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR ));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR ) , `REG_PRINT , $sformatf("CSR Register %0h Read" , csr_addrs_array[i]) );
            DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR ) , `REG_PRINT , $sformatf("CSR Register %0h Read" , csr_addrs_array[i]) );
            $display("\n") ; 
       end
      
      
      $display("\nTest Case:\t Writing and Reading from CSR , aarsize = 32") ; 
       //////////////////////   writing value to CSR with aarsize as 32bit     /////////////////////////////////////////
          for(int i = 0 ; i < csr_addrs_array.size() ; i++) begin
           DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("CSR Register %0h write" , csr_addrs_array[i]) );
           DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | `RANDOM_DATA) ,`INPUT_DATA_PRINT ,  $sformatf("CSR Register %0h write" , csr_addrs_array[i]) );
           DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_32 |`TRANSFER_REG| `WRITE_A_R | `CSR_REG(csr_addrs_array[i])  ));
           DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_32 | `WRITE_A_R | `CSR_REG(csr_addrs_array[i])  ));
          //end
      
         //////////////////////////////Reading from CSR With aarsize = 32    ///////////////////////
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_32 |`TRANSFER_REG | `WRITE_R_A | `CSR_REG(csr_addrs_array[i])));
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_32 | `WRITE_R_A | `CSR_REG(csr_addrs_array[i])));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR ));
            DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR ) , `REG_PRINT , $sformatf("CSR Register %0h Read" , csr_addrs_array[i]) );
            DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR ) , `REG_PRINT , $sformatf("CSR Register %0h Read" , csr_addrs_array[i]) );
            $display("\n") ; 
        end

 //////////////////////////////////////////////////////////////////////////////////////////////////
 //                 Test Case: Abstracts Control and Status register cmderr field               //
 /////////////////////////////////////////////////////////////////////////////////////////////////

 //Case 1: reseting the hart and trying to excecute abstracts command , 
 //expected result: cmderr = 4 , because hart wasn't in required state
        //HART REQUEST - resetting the Hart 
        $display("HART RESET asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HARTRESET ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA) , `GEN_PRINT);
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | `RANDOM_DATA) , `GEN_PRINT);
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_64 |`TRANSFER_REG | `WRITE_A_R | `REG_NO(3)  ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `ABSTRACTCS_ADDR ) );
        DR_Scan(DMI_ACCESS,(`OP_NOP | `ABSTRACTCS_ADDR ) , `GEN_PRINT);

//////////////////////////////clearing cmderr field ////////////////////////////
        $display("Clearing cmderr field") ; 
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `ABSTRACTCS_ADDR | `CMDERR_CLR ) );
        DR_Scan(DMI_ACCESS,(`OP_READ | `ABSTRACTCS_ADDR ) );
        DR_Scan(DMI_ACCESS,(`OP_NOP | `ABSTRACTCS_ADDR ) , `GEN_PRINT);


 //Case 2: halting the hart and trying to excecute unsupported abstracts command , 
 //expected result: cmderr = 2 , because addres is not supported ( addres = 0x1032)
        //HALT REQUEST - halting the Hart 
        $display("\nHALTREQ asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | `RANDOM_DATA));
        $display("CMDERR=2 Asserted") ; 
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_32 |`TRANSFER_REG | `WRITE_A_R | `REG_NO($urandom_range(32 , 16'hEFDE))  ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `ABSTRACTCS_ADDR ) );
        DR_Scan(DMI_ACCESS,(`OP_NOP | `ABSTRACTCS_ADDR ) , `GEN_PRINT);

        ////////////////////////clearing cmderr field /////////////////////////////////////////
        $display("Clearing cmderr field") ; 
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `ABSTRACTCS_ADDR | `CMDERR_CLR ) );
        DR_Scan(DMI_ACCESS,(`OP_READ | `ABSTRACTCS_ADDR ) );
        DR_Scan(DMI_ACCESS,(`OP_NOP | `ABSTRACTCS_ADDR ) , `GEN_PRINT);
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ ));

 //////////////////////////////////////////////////////////////////////////////////////////////
 // Case 3 : Unsupported aarsize, will result in cmderr = 2
 // random aarsize with random read or write operation on random register field
       IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ )); 
       $display("\nHALT REQUEST asserted");

       repeat($urandom_range(10,20)) begin
            flag = $urandom_range(0,1) ;
         `ifdef ZILLA_64_BIT
            aamsize = $urandom_range(0,1) ? $urandom_range(0,1) : $urandom_range(4,7) ; 
         `else
            aamsize = $urandom_range(0,1) ? $urandom_range(0,1) : $urandom_range(3,7) ;
         `endif
            reg_no = $urandom_range(0,31) ; 
            if(flag)
                $display("Write : Register[%0d] With aarsize = %0d" , reg_no , aamsize) ;
            else
                $display("Read : Register[%0d] With aarsize = %0d" , reg_no , aamsize) ;
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | ( aamsize << 22 ) |`TRANSFER_REG | ( flag <<18 ) | `REG_NO(reg_no)));
            DR_Scan(DMI_ACCESS,(`OP_READ | `ABSTRACTCS_ADDR ) );
            DR_Scan(DMI_ACCESS,(`OP_NOP | `ABSTRACTCS_ADDR ) , `GEN_PRINT);

         ////////////////////////clearing cmderr field /////////////////////////////////////////
           $display("Clearing cmderr field") ; 
            DR_Scan(DMI_ACCESS,(`OP_WRITE | `ABSTRACTCS_ADDR | `CMDERR_CLR ) );
            DR_Scan(DMI_ACCESS,(`OP_READ | `ABSTRACTCS_ADDR ) );
            DR_Scan(DMI_ACCESS,(`OP_NOP | `ABSTRACTCS_ADDR ) , `GEN_PRINT);
            $display("\n") ; 
        end
        
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ )); 
        $display("RESUME REQUEST asserted");


 //Case 4: halting the hart and trying to excecute unsupported memory acces type aamsize > 3, 
 //expected result: cmderr = 2 , because aamsize > 3 
        //HALT REQUEST - halting the Hart 
     repeat($urandom_range(5, 8))begin
        $display("\nHALTREQ asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
        $display("CMDERR=2 Asserted") ;
        `ifdef ZILLA_32_BIT
             aamsize = $urandom_range(3,7) ;
         `else
             aamsize = $urandom_range(4,7) ; 
        `endif
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | ( aamsize << 22) | `WRITE_A_R ) );
        DR_Scan(DMI_ACCESS,(`OP_READ | `ABSTRACTCS_ADDR ) );
        DR_Scan(DMI_ACCESS,(`OP_NOP | `ABSTRACTCS_ADDR ) , `GEN_PRINT);

        ////////////////////////clearing cmderr field /////////////////////////////////////////
        $display("Clearing cmderr field") ; 
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `ABSTRACTCS_ADDR | `CMDERR_CLR ) );
        DR_Scan(DMI_ACCESS,(`OP_READ | `ABSTRACTCS_ADDR ) );
        DR_Scan(DMI_ACCESS,(`OP_NOP | `ABSTRACTCS_ADDR ) , `GEN_PRINT);
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ ));
        

        ////////////////// cmderr 2 for aamsize > 4 with(for 64bit parameter) aamsize > 3 (for 32bit parameter) reading from the memory
        $display("\nHALTREQ asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
        $display("CMDERR=2 Asserted") ; 
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | (aamsize << 22) | `WRITE_R_A ) );
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `ABSTRACTCS_ADDR ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_32 | `WRITE_R_A ) );
        DR_Scan(DMI_ACCESS,(`OP_READ | `ABSTRACTCS_ADDR ) );
        DR_Scan(DMI_ACCESS,(`OP_NOP | `ABSTRACTCS_ADDR ) , `GEN_PRINT);
        ////////////////////////clearing cmderr field /////////////////////////////////////////
        $display("Clearing cmderr field") ; 
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `ABSTRACTCS_ADDR | `CMDERR_CLR ) );
        DR_Scan(DMI_ACCESS,(`OP_READ | `ABSTRACTCS_ADDR ) );
        DR_Scan(DMI_ACCESS,(`OP_NOP | `ABSTRACTCS_ADDR ) , `GEN_PRINT);
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ ));
     end

///////////////////////////////////////////////////////////////////////////////////////
//          Test Case: Executing Improper cmdtype
//////////////////////////////////////////////////////////////////////////////////////

        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_WRNG | `AARSIZE_64 |`TRANSFER_REG | `WRITE_R_A | `REG_NO(3)) );

 //////////////////////////////////////////////////////////////////////////////////////////////////
 //                 Test Case: DTM Control and Status register                                //
 /////////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////// dmi hard reset    ///////////////////////////////////////////////////
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_ARC | `AARSIZE_64 |`TRANSFER_REG | `WRITE_R_A | `REG_NO(3)) , `GEN_PRINT);
        IR_DR_JTAG_Scan(DTM_CSR , `DMI_HARDRESET );
        IR_DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR  | `RANDOM_DATA) , );
        DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_0_reg");
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_1_reg");
        IR_DR_JTAG_Scan(DTM_CSR , 0  );

        ///////////////////////// dmireset //////////////////////////////////////////
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `WRONG_ADDR | `CMDTYPE_ARC | `AARSIZE_64 |`TRANSFER_REG | `WRITE_R_A | `REG_NO(3)) , `GEN_PRINT);
        IR_DR_JTAG_Scan(DTM_CSR , `DMI_RESET );
        IR_DR_JTAG_Scan(DTM_CSR , 0  );
        IR_DR_JTAG_Scan(DTM_CSR , 0  );


//////////////////////////////////////////////////////////////////////////////////////////////////
//              Test Case: Acces memory Command with aarpostincreament                                /////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

repeat(2) begin
        if(data_mem_op)begin
             $display("/////////////////////////////////////////////////////");
             $display("//       Data Memory Operation                     //");
             $display("/////////////////////////////////////////////////////");
        end
        else
            begin
             $display("/////////////////////////////////////////////////////");
             $display("//       Instruction Memory Operation              //");
             $display("/////////////////////////////////////////////////////");
            end
        $display("\n AMC Test Cases") ;  
        $display("HALTREQ asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
 `ifdef ZILLA_64_BIT
        ///// accesing memory = 64 bit ////////////
        $display("\nAccesing 64 bit: memory Write ");
        if(data_mem_op)
            addrs = $urandom_range(`DATA_MEM_BASE_ADDR/4'd8 , `DATA_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        else
            addrs = $urandom_range(`INSTR_MEM_BASE_ADDR/4'd8 , `INSTR_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        $display("Base Addres = %0h" , addrs) ; 
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | (addrs << 2) ) );
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (0 << 2)  ));

        repeat(10)begin
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_0_reg"  ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_1_reg"  ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_64 | `WRITE_A_R ) );
        end

        $display("Accesing 64 bit: memory Read ");
        //reading from same addres
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | (addrs << 2) ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (0 << 2)  ));
        repeat(10)begin
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_64 | `WRITE_R_A ) );
        DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR | `RANDOM_DATA   ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_0_reg");
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_1_reg");
        end

        ////////  accesing memeory = 32 bit     //////////////////////////////////////
        $display("\nAccesing 32 bit: memory Write ");
        if(data_mem_op)
            addrs = $urandom_range(`DATA_MEM_BASE_ADDR/4'd8 , `DATA_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        else
            addrs = $urandom_range(`INSTR_MEM_BASE_ADDR/4'd8 , `INSTR_MEM_END_ADDR/4'd8 ) * 32'd8  ;
       $display("Base Addres = %0h" , addrs) ; 
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | (addrs << 2) ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (0 << 2)  ));

        repeat(10)begin
          DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_0_reg"  ));
          DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_1_reg"  ));
          DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_32 | `WRITE_A_R ) );
        end

        $display("Accesing 32 bit memory Read ");
        //reading from same addres
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | ( addrs << 2) ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (0 << 2)  ));
        repeat(10)begin
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_32 | `WRITE_R_A ) );
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR | `RANDOM_DATA   ));
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_0_reg");
         DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_1_reg");
        end


        ////////  accesing memeory = 16 bit     //////////////////////////////////////
        $display("\nAccesing 16 bit: memory Write ");
        if(data_mem_op)
            addrs = $urandom_range(`DATA_MEM_BASE_ADDR/4'd8 , `DATA_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        else
            addrs = $urandom_range(`INSTR_MEM_BASE_ADDR/4'd8 , `INSTR_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        $display("Base Addres = %0h" , addrs) ; 
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | (addrs << 2) ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (0 << 2)  ));

        repeat(10)begin
          DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_0_reg"  ));
          DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_1_reg"  ));
          DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_16 | `WRITE_A_R ) );
        end

        $display("Accesing 16 bit: memory Read ");
        //reading from same addres
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | ( addrs << 2) ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (0 << 2)  ));
        repeat(10)begin
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_16 | `WRITE_R_A ) );
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR | `RANDOM_DATA   ));
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_0_reg");
         DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_1_reg");
        end


        ////////  accesing memeory = 8 bit     //////////////////////////////////////
        $display("\nAccesing 8 bit: memory Write ");
       if(data_mem_op)
            addrs = $urandom_range(`DATA_MEM_BASE_ADDR/4'd8 , `DATA_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        else
            addrs = $urandom_range(`INSTR_MEM_BASE_ADDR/4'd8 , `INSTR_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | (addrs << 2) ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (0 << 2)  ));

        repeat(10)begin
          DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_0_reg"  ));
          DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_1_reg"  ));
          DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_8 | `WRITE_A_R ) );
        end

        $display("Accesing 8 bit: memory Read ");
        //reading from same addres
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | ( addrs << 2) ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (0 << 2)  ));
        repeat(10)begin
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_8 | `WRITE_R_A ) );
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR | `RANDOM_DATA   ));
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_0_reg");
         DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_1_reg");
        end
 `else
       
        ////////  accesing memeory = 32 bit     //////////////////////////////////////
        $display("\nAccesing 32 bit: memory Write ");
        if(data_mem_op)
            addrs = $urandom_range(`DATA_MEM_BASE_ADDR/4'd8 , `DATA_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        else
            addrs = $urandom_range(`INSTR_MEM_BASE_ADDR/4'd8 , `INSTR_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        $display("Base Addres = %0h" , addrs) ; 
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | (addrs << 2) ));

        repeat(10)begin
          DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_0_reg"  ));
          DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_32 | `WRITE_A_R ) );
        end
        $display("Accesing 32 bit memory Read ");
        //reading from same addres
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | ( addrs << 2) ));
        repeat(10)begin
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_32 | `WRITE_R_A ) );
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR | `RANDOM_DATA   ));
         DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA0_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_0_reg");
        end


        ////////  accesing memeory = 16 bit     //////////////////////////////////////
        $display("\nAccesing 16 bit: memory Write ");
        if(data_mem_op)
            addrs = $urandom_range(`DATA_MEM_BASE_ADDR/4'd8 , `DATA_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        else
            addrs = $urandom_range(`INSTR_MEM_BASE_ADDR/4'd8 , `INSTR_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        $display("Base Addres = %0h" , addrs) ; 
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | (addrs << 2) ));

        repeat(10)begin
          DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_0_reg"  ));
          DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_16 | `WRITE_A_R ) );
        end

        $display("Accesing 16 bit: memory Read ");
        //reading from same addres
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | ( addrs << 2) ));
        repeat(10)begin
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_16 | `WRITE_R_A ) );
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR | `RANDOM_DATA   ));
         DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA0_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_0_reg");
        end


        ////////  accesing memeory = 8 bit     //////////////////////////////////////
        $display("\nAccesing 8 bit: memory Write ");
        if(data_mem_op)
            addrs = $urandom_range(`DATA_MEM_BASE_ADDR/4'd8 , `DATA_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        else
            addrs = $urandom_range(`INSTR_MEM_BASE_ADDR/4'd8 , `INSTR_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | (addrs << 2) ));

        repeat(10)begin
          DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_0_reg"  ));
          DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_8 | `WRITE_A_R ) );
        end

        $display("Accesing 8 bit: memory Read ");
        //reading from same addres
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | ( addrs << 2) ));
        repeat(10)begin
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_8 | `WRITE_R_A ) );
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR | `RANDOM_DATA   ));
         DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA0_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_0_reg");
        end

  `endif

////////////////////////////////////////////////////////////////////////////////////
///             random addrs read and write with random aaamsize  w/o aampostincreament    //
///////////////////////////////////////////////////////////////////////////////////
  `ifdef ZILLA_64_BIT
        repeat($urandom_range(40,50))begin
        if(data_mem_op)
            addrs = $urandom_range(`DATA_MEM_BASE_ADDR/4'd8 , `DATA_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        else
            addrs = $urandom_range(`INSTR_MEM_BASE_ADDR/4'd8 , `INSTR_MEM_END_ADDR/4'd8 ) * 32'd8  ;
         aamsize = $urandom_range(0,3) ;
         $display("\nAddres = %0h" , addrs) ; 
         $display("aamsize = %0d: memory Write " , aamsize);
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | (addrs << 2) ) );
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (0 << 2)  ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_0_reg"  ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_1_reg"  ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR  |`CMDTYPE_AMC  | (aamsize << 22) | `WRITE_A_R ) );
        
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA)   );
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | `RANDOM_DATA)   );
          
         aamsize = $urandom_range(0,3) ;
         $display("aamsize = %0d: memory Read " , aamsize);
         //reading from same addres
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | (addrs << 2) ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (0 << 2)  ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_AMC  | (aamsize << 22) | `WRITE_R_A ) );
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR | `RANDOM_DATA   ));
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:\tData_0_reg");
         DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:\tData_1_reg");
        end
  `else
         repeat($urandom_range(40,50))begin
        if(data_mem_op)
            addrs = $urandom_range(`DATA_MEM_BASE_ADDR/4'd8 , `DATA_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        else
            addrs = $urandom_range(`INSTR_MEM_BASE_ADDR/4'd8 , `INSTR_MEM_END_ADDR/4'd8 ) * 32'd8  ;
         aamsize = $urandom_range(0,2) ;
         $display("\nAddres = %0h" , addrs) ; 
         $display("aamsize = %0d: memory Write " , aamsize);
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | (addrs << 2) ) );
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA) , `INPUT_DATA_PRINT , $sformatf("Write:\tData_0_reg"  ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR  |`CMDTYPE_AMC  | (aamsize << 22) | `WRITE_A_R ) );
        
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | `RANDOM_DATA)   );
          
         aamsize = $urandom_range(0,2) ;
         $display("aamsize = %0d: memory Read " , aamsize);
         //reading from same addres
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | (addrs << 2) ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `CMDTYPE_AMC  | (aamsize << 22) | `WRITE_R_A ) );
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR | `RANDOM_DATA   ));
         DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA0_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:\tData_0_reg");
        end

  `endif

////////////////////////////////////////////////////////////////////////////////////
//              Write/Read Missalligned Addres  addres should result in cmderr=3  //
///////////////////////////////////////////////////////////////////////////////////
   
        $display("/n/nHALTREQ asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
        
        $display("================================") ; 
        $display("Missalligned Addres Cases") ; 
        $display("================================") ; 
        repeat($urandom_range(40, 60)) begin
        if(data_mem_op)
            addrs = $urandom_range(`DATA_MEM_BASE_ADDR, `DATA_MEM_END_ADDR )   ;
        else
            addrs = $urandom_range(`INSTR_MEM_BASE_ADDR, `INSTR_MEM_END_ADDR )  ;
         aamsize = $urandom_range(0,7) ;
         flag = $urandom_range(0,1) ;
         if(flag)
             $display("\nWrite Memory: Addrs =%0h\taamsize=%0d" , addrs , aamsize) ;
         else
             $display("\nRead Memory: Addrs =%0h\taamsize=%0d" , addrs , aamsize) ;
       `ifdef ZILLA_64_BIT      
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | (addrs << 2) ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (0 << 2)  ));
       `else
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | (addrs << 2) ));
       `endif
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | ($urandom_range(0, 1) << 21 ) |`CMDTYPE_AMC  | (aamsize << 22) | (flag << 18) ) );

         DR_Scan(DMI_ACCESS,(`OP_READ | `ABSTRACTCS_ADDR ) );
         DR_Scan(DMI_ACCESS,(`OP_NOP | `ABSTRACTCS_ADDR ) , `GEN_PRINT);

         ////////////////////////clearing cmderr field /////////////////////////////////////////
         $display("Clearing cmderr field") ; 
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `ABSTRACTCS_ADDR | `CMDERR_CLR ) );
         DR_Scan(DMI_ACCESS,(`OP_READ | `ABSTRACTCS_ADDR ) );
         DR_Scan(DMI_ACCESS,(`OP_NOP | `ABSTRACTCS_ADDR ) , `GEN_PRINT);
        end
        data_mem_op = ~data_mem_op ; 
      end

    /////////////////////////////////////////////////////////////////////////////
    //      Test Case : Accesing Out Of Bound Memory 
    ////////////////////////////////////////////////////////////////////////////
     `ifdef ZILLA_64_BIT
        $display("HALTREQ asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
        repeat($urandom_range(20,40))begin
        addrs_64 = { $urandom()  , $urandom_range(`DATA_MEM_END_ADDR, 32'hFFFF_FFFF ) }  ;
        aamsize = $urandom_range(0,3) ;
        memory_content = {$urandom() , $urandom()} ;
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | (memory_content[31:0] << 2) ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR | (memory_content[63:32] << 2)  ));
      
         $display("\nWrite Memory: Addrs =%0h\taamsize=%0d\t data = %0h" , addrs_64 , aamsize, memory_content) ;
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | (addrs_64[31:0] << 2) ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (addrs_64[63:32] << 2)  ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | ($urandom_range(0, 1) << 21 ) |`CMDTYPE_AMC  | (aamsize << 22) | `WRITE_A_R ) );
       
         DR_Scan(DMI_ACCESS,(`OP_READ | `ABSTRACTCS_ADDR ) );
         DR_Scan(DMI_ACCESS,(`OP_NOP | `ABSTRACTCS_ADDR ) , `GEN_PRINT);

         ////////////////////////clearing cmderr field /////////////////////////////////////////
         $display("Clearing cmderr field") ; 
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `ABSTRACTCS_ADDR | `CMDERR_CLR ) );
         DR_Scan(DMI_ACCESS,(`OP_READ | `ABSTRACTCS_ADDR ) );
         DR_Scan(DMI_ACCESS,(`OP_NOP | `ABSTRACTCS_ADDR ) , `GEN_PRINT);
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR    ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR    ));
         
         $display("\nRead Memory: Addrs =%0h\taamsize=%0d" , addrs_64 , aamsize) ;
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | ($urandom_range(0, 1) << 21 ) |`CMDTYPE_AMC  | (aamsize << 22) | `WRITE_R_A ) );
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `ABSTRACTCS_ADDR | `CMDERR_CLR ) );
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR | `RANDOM_DATA   ));
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_0_reg");
         DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_1_reg");
        end
       `endif
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `RESUMEREQ ));

////////////////////////////////////////////////////////////////////////////////
//      Test case : Reading and Writing to Addres zero                       //
///////////////////////////////////////////////////////////////////////////////
`ifdef ZILLA_64_BIT
        $display("HALTREQ asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
        repeat($urandom_range(5,10))begin
        aamsize = $urandom_range(0,3) ;
        memory_content = {$urandom() , $urandom()} ;
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | (memory_content[31:0] << 2) ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR | (memory_content[63:32] << 2)  ));
      
         $display("\nWrite Memory: Addrs = 0h\taamsize=%0d\t data = %0h" , aamsize, memory_content) ;
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR  ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | ($urandom_range(0, 1) << 21 ) |`CMDTYPE_AMC  | (aamsize << 22) | `WRITE_A_R ) );
       
         $display("\nRead Memory: Addrs = 0h\taamsize=%0d" , aamsize) ;
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | ($urandom_range(0, 1) << 21 ) |`CMDTYPE_AMC  | (aamsize << 22) | `WRITE_R_A ) );
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR | `RANDOM_DATA   ));
         DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_0_reg");
         DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_1_reg");
        end
       `endif

/////////////////////////////////////////////////////////////////////////////////////
//      Test Case:   Loading Data Memory                                 //
/////////////////////////////////////////////////////////////////////////////////////
    //reading instruction and data.hex into array
    //    $readmemh("debug_instr_mem.hex", instr_array);
		$readmemh("../OpenOCD/debug_data_mem.hex", data_array);

    //////////////////////// flashing data memory            ///////////////////
        $display("HALTREQ asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
    `ifdef ZILLA_64_BIT
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  |  (`DATA_MEM_BASE_ADDR << 2 )  ));
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (0 << 2)  ));

        foreach(data_array[i])begin
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | (data_array[i][31:0] << 2)  ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | (data_array[i][63:32] << 2)  ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_64 | `WRITE_A_R ) );
        end
    `else
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  |  (`DATA_MEM_BASE_ADDR << 2 )  ));
        foreach(data_array[i])begin
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | (data_array[i][31:0] << 2)  ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_32 | `WRITE_A_R ) );

         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | (data_array[i][63:32] << 2)  ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | `AAMSIZE_32 | `WRITE_A_R ) );
        end
    `endif

///////////////////////////////////////////////////////////////////////////
//  Back Door Accesing of Data Memory :Write
//  Description : Writing to Data Memory addres through Test Bench ,
//                and reading same addres from Debug Module AMC with random aamsize
//                repeated random times b/w 10 to 20
///////////////////////////////////////////////////////////////////////////
        $display("HALTREQ asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
      
      repeat($urandom_range(10,20)) begin
      `ifdef ZILLA_64_BIT
          aamsize = $urandom_range(0,3) ;  
      `else
          aamsize = $urandom_range(0,2) ; 
      `endif

        addrs = $urandom_range(`DATA_MEM_BASE_ADDR/4'd8 , `DATA_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        random_data = {$urandom() , $urandom()} ;

   {   r_config.data_memory[(addrs + 7)],
       r_config.data_memory[(addrs + 6)],
       r_config.data_memory[(addrs + 5)],
       r_config.data_memory[(addrs + 4)],
       r_config.data_memory[(addrs + 3)],
       r_config.data_memory[(addrs + 2)],
       r_config.data_memory[(addrs + 1)],
       r_config.data_memory[addrs]} ={random_data} ;  
        
      `ifdef ZILLA_64_BIT      
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | (addrs << 2) ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (0 << 2)  ));
      `else
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | (addrs << 2) ));
      `endif
        
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR | `AARPOSTINCREMENT |`CMDTYPE_AMC  | (aamsize << 22 ) | `WRITE_R_A ) );
        $display("\nWrite:TB : Data_Memory[%0h] = %0h" , addrs , random_data ) ;
        $display("Read :DM : Data_Memory[%0h] : With Aamsize = %0d" , addrs ,aamsize ) ; 
        
        DR_Scan(DMI_ACCESS,(`OP_READ | `DATA0_ADDR | `RANDOM_DATA   ));
        DR_Scan(DMI_ACCESS,(`OP_READ | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_0_reg");
      `ifdef ZILLA_64_BIT 
        DR_Scan(DMI_ACCESS,(`OP_NOP | `DATA1_ADDR  | `RANDOM_DATA) , `REG_PRINT , "Read:Data_1_reg");
      `endif
   end
///////////////////////////////////////////////////////////////////////////
//  Back Door Accesing of Data Memory :Read
//  Description : Writing to Data Memory addres through Test Bench ,
//                and reading same addres from Debug Module AMC with random aamsize
//                repeated random times b/w 10 to 20
///////////////////////////////////////////////////////////////////////////
        $display("HALTREQ asserted");
        IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
      
      repeat($urandom_range(10,20)) begin
      `ifdef ZILLA_64_BIT
          aamsize = $urandom_range(0,3) ;  
      `else
          aamsize = $urandom_range(0,2) ; 
      `endif
        addrs = $urandom_range(`DATA_MEM_BASE_ADDR/4'd8 , `DATA_MEM_END_ADDR/4'd8 ) * 32'd8  ;
        random_data = {$urandom() , $urandom()} ; 
        {   r_config.data_memory[(addrs + 7)],
       r_config.data_memory[(addrs + 6)],
       r_config.data_memory[(addrs + 5)],
       r_config.data_memory[(addrs + 4)],
       r_config.data_memory[(addrs + 3)],
       r_config.data_memory[(addrs + 2)],
       r_config.data_memory[(addrs + 1)],
       r_config.data_memory[addrs]} ={$urandom() , $urandom()} ;  
 
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA0_ADDR  | (random_data[31:0] << 2)  ));
      `ifdef ZILLA_64_BIT     
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | (random_data[63:32] << 2) ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA2_ADDR  | (addrs << 2) ));
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA3_ADDR | (0 << 2)  ));
      `else
         DR_Scan(DMI_ACCESS,(`OP_WRITE | `DATA1_ADDR  | (addrs << 2) ));
      `endif
        
        DR_Scan(DMI_ACCESS,(`OP_WRITE | `COMMAND_ADDR |`CMDTYPE_AMC  | (aamsize << 22 ) | `WRITE_A_R ) );
        DR_Scan(DMI_ACCESS,(`OP_READ | `COMMAND_ADDR |`CMDTYPE_AMC  | (aamsize << 22 ) | `WRITE_A_R ) );
        
        memory_content = 
           {  r_config.data_memory[(addrs + 7)],
              r_config.data_memory[(addrs + 6)],
              r_config.data_memory[(addrs + 5)],
              r_config.data_memory[(addrs + 4)],
              r_config.data_memory[(addrs + 3)],
              r_config.data_memory[(addrs + 2)],
              r_config.data_memory[(addrs + 1)],
              r_config.data_memory[addrs]}   ;

         $display("\nWrite:DM : Data_Memory[%0h] = %0h: With aamsize = %0d" , addrs ,
        `ifdef ZILLA_64_BIT 
            random_data,
        `else
            random_data[31:0] ,
        `endif aamsize  ) ;

        $display("Read :TB : Data_Memory[%0h] =%0h : With Aamsize = %0d" , addrs ,
      `ifdef ZILLA_64_BIT  
        memory_content 
      `else
        memory_content[31:0] 
      `endif
        , aamsize ) ; 
        
   end

/////////////////////////////////////////////////////////////////////////////////
//              JTAG Register Cases: Bypass Register                            //
//////////////////////////////////////////////////////////////////////////////////

       IR_DR_JTAG_Scan(BYPASS , $urandom());
       IR_DR_JTAG_Scan(BYPASS , 'd10 );
 
//////////////////////////////////////////////////////////////////////////////////
//              JTAG Register Cases: IDCODE Register                            //
//////////////////////////////////////////////////////////////////////////////////   
 
       IR_DR_JTAG_Scan(IDCODE , $urandom() );
///////////////////////////////////////////////////////////////////////////////
//      Case ; Accesing Wrong JTAG Register                                                                    
//////////////////////////////////////////////////////////////////////////////
       IR_DR_JTAG_Scan(5'h18 ,$urandom() );

////////////////////////////////////////////////////////////////////////////////
//      Case: JTAG TAP state                                                ///
/////////////////////////////////////////////////////////////////////////////
       
       TAP_STATE = 1'b1 ; 
       IR_DR_JTAG_Scan();
       TAP_STATE = 1'b0 ;

////////////////////////////////////////////////////////////////////////////////
//    Accesing Wrong Register will result in pslverr = 1 
////////////////////////////////////////////////////////////////////////////////
  
   IR_DR_Scan(DMI_ACCESS,(`OP_WRITE | `DM_CONTROL  | `DM_ACTIVE | `HALTREQ ));
    repeat($urandom_range(3,5)) begin 
       DR_Scan(DMI_ACCESS,(`OP_WRITE | ($urandom_range(0,3) << 34) | `RANDOM_DATA ) );
       DR_Scan(DMI_ACCESS,(`OP_WRITE | ($urandom_range(48,7'b111_11111) << 34) | `RANDOM_DATA ) );
       DR_Scan(DMI_ACCESS,(`OP_WRITE | ($urandom_range(13,15) << 34) | `RANDOM_DATA ) );
       DR_Scan(DMI_ACCESS,(`OP_WRITE | ($urandom_range(18,19) << 34) | `RANDOM_DATA ) );
    end
//////////////////////// ending simulation /////////////////////////////////////
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

