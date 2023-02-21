//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Copyright © 2022 Vivartan Technologies., All rights reserved////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//All works published under Zilla_Gen_0 by Vivartan Technologies is copyrighted by the Association and ownership// 
//of all right, title and interest in and to the works remains with Vivartan Technologies. No works or documents//
//published under Zilla_Gen_0 by Vivartan Technologies may be reproduced,transmitted or copied without the expre//
//-ss written permission of Vivartan Technologies will be considered as a violations of Copyright Act and it may//
//lead to legal action.                                                                                         //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
* File Name : spc_coverage.sv

* Purpose : Coverage for special counter

* Creation Date : 31-03-2023

* Last Modified : Tue 19 Sep 2023 04:33:07 PM IST

* Created By :  Sharon
*/

class riscv_wb_coverage extends uvm_subscriber #(seq_item_wb_out);

//Factory registration
    `uvm_component_utils(riscv_wb_coverage)

//seq_item instantiationv_i.
    seq_item_wb_out sq_i;

    bit [31:0] instruction;
    bit [6:0]  opcode;
    bit [2:0]  func3;
    bit [6:0]  func7;
    bit [31:0] imm;
    bit [4:0]  rs1;
    bit [4:0]  rs2;
    bit [4:0]  rd;
    bit [19:0] pc;
    //logic [31:0] instruction;

    bit [1:0] forward_a;
    bit [1:0] forward_b;
    bit [31:0]alu_out;

    // for reg data  mapping is like reg_data[0] => rd0
    bit [31:0] rd0;
    bit [31:0] rd1;
    bit [31:0] rd2;
    bit [31:0] rd3;
    bit [31:0] rd4;
    bit [31:0] rd5;
    bit [31:0] rd6;
    bit [31:0] rd7;
    bit [31:0] rd8;
    bit [31:0] rd9;
    bit [31:0] rd10;
    bit [31:0] rd11;
    bit [31:0] rd12;
    bit [31:0] rd13;
    bit [31:0] rd14;
    bit [31:0] rd15;
    bit [31:0] rd16;
    bit [31:0] rd17;
    bit [31:0] rd18;
    bit [31:0] rd19;
    bit [31:0] rd20;
    bit [31:0] rd21;
    bit [31:0] rd22;
    bit [31:0] rd23;
    bit [31:0] rd24;
    bit [31:0] rd25;
    bit [31:0] rd26;
    bit [31:0] rd27;
    bit [31:0] rd28;
    bit [31:0] rd29;
    bit [31:0] rd30;
    bit [31:0] rd31;

    bit [31:0] out;
    
    bit [31:0] data_in_1   ;
    bit [31:0] data_in_2   ;                    
    bit [31:0] data_out    ;                               
    bit sub_en            ;
    bit add_en            ;
    bit sll_en            ;
    bit slt_en            ;
    bit xor_en            ;
    bit srl_en            ;
    bit sra_en            ;
    bit or_en             ;
    bit and_en            ;
    bit jalr_en           ;
    bit jal_en            ;   
    bit lui_en             ;     
    bit wr_data_en        ;
    bit [31:0] in1        ;
    bit [31:0] in2        ;
    bit        sel        ;

//covergroup
    covergroup wb_covergroup;

    R_OPCODE                :   coverpoint opcode
                            {
                                //option.auto_bin_max = 32;
                                bins r_type         =   {7'h33};  // r type instructions
                            }
    I_OPCODE                :   coverpoint opcode
                            {
                                //option.auto_bin_max = 32;
                                bins i_type         =   {7'h13};  // r type instructions
                            }
                            
    I_JALR_OPCODE                :   coverpoint opcode
                            {
                                //option.auto_bin_max = 32;
                                bins i_jalr_type         =   {7'h67};  // r type instructions
                            }

    U_OPCODE                :   coverpoint opcode
                            {
                                //option.auto_bin_max = 32;
                                bins u_type         =   {7'h37};  // r type instructions
                            }

    UJ_OPCODE                :   coverpoint opcode
                            {
                                //option.auto_bin_max = 32;
                                bins uj_type         =   {7'h6F};  // r type instructions
                            }
    FUNC3_0                 : coverpoint func3
                          {
                              bins add_sub        =   {3'b000};
                          }


    FUNC3_1                 : coverpoint func3
                          {
                              bins sll            =   {3'b001};
                          }

    FUNC3_2                 : coverpoint func3
                          {
                              bins slt            =   {3'b010};
    

                          }
    FUNC3_3                 : coverpoint func3
                          {
                              bins sltu           =   {3'b011};
                          }

    FUNC3_4                 : coverpoint func3
                          {
                              bins Xor            =   {3'b100};
    

                          }

    FUNC3_5                 : coverpoint func3
                          {
                              bins srl_sra        =   {3'b101};
    

                          }

    FUNC3_6                 : coverpoint func3
                          {
                              bins Or             =   {3'b110};
    

                          }

    FUNC3_7                 : coverpoint func3
                          {
                              bins And            =   {3'b111};         

                          }
    FUNC7_00               :   coverpoint func7
                          {
                              bins Arith          =   {7'b0000000};
                          }

    FUNC7_20               :   coverpoint func7
                          {
                              bins Shift          =   {7'b0100000};
                          }
    RS1                   :   coverpoint rs1
                          {
                              bins rs1_bin[] ={[1:31]} ;
                              ignore_bins rs1_bin_0 = {0};
                          }
    RS2                   :   coverpoint rs2
                          {
                              bins rs2_bin[] ={[1:31]} ;
                              ignore_bins rs2_bin_0 = {0};
                          }

    RD                   :   coverpoint rd
                          {
                                bins rd_bin[] ={[1:31]} ;
                                ignore_bins rd_bin_0 = {0};
                            }
    OUT                   :   coverpoint out
                            {
                                bins out_low1 ={[32'h00000000:32'h01FFFFFF]} ;
                                bins out_medium1 ={[32'h02000000:32'h10FFFFFF]} ;
                                bins out_high1 ={[32'h11000000:32'hFFFFFFFF]} ;
                            }
    OUT_JUMP                   :   coverpoint out
                            {
                                bins out_low1 ={[20'h8100:20'h28100]} ;
                                bins out_high2 ={[20'h28101:20'h48000]} ;
                            }
    RD1                :   coverpoint rd1
                            {
                                option.auto_bin_max = 4;
                                 
                            }
    RD2                :   coverpoint rd2
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD3                :   coverpoint rd3
                           {
                               option.auto_bin_max = 4;
                                
                           }

    RD4                :   coverpoint rd4
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD5                :   coverpoint rd5
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD6                :   coverpoint rd6
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD7                :   coverpoint rd7
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD8                :   coverpoint rd8
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD9                :   coverpoint rd9
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD10                :   coverpoint rd10
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD11                :   coverpoint rd11
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD12                :   coverpoint rd12
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD13                :   coverpoint rd13
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD14                :   coverpoint rd14
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD15                :   coverpoint rd15
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD16                :   coverpoint rd16
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD17                :   coverpoint rd17
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD18                :   coverpoint rd18
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD19                :   coverpoint rd19
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD20                :   coverpoint rd20
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD21                :   coverpoint rd21
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD22                :   coverpoint rd22
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD23                :   coverpoint rd23
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD24                :   coverpoint rd24
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD25                :   coverpoint rd25
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD26                :   coverpoint rd26
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD27                :   coverpoint rd27
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD28                :   coverpoint rd28
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD29                :   coverpoint rd29
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD30                :   coverpoint rd30
                           {
                               option.auto_bin_max = 4;
                                
                           }
    RD31                :   coverpoint rd31
                           {
                               option.auto_bin_max = 4;
                                
                            }
    RD1_JUMP                :   coverpoint rd1
                            {
                                 bins range = {[20'h8100:20'h48000]};
                            }
    RD2_JUMP                :   coverpoint rd2
                           {
                            
                                 bins range = {[20'h8100:20'h48000]};
                                
                           }
    RD3_JUMP                :   coverpoint rd3
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }

    RD4_JUMP                :   coverpoint rd4
                           {                                  
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD5_JUMP                :   coverpoint rd5
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD6_JUMP                :   coverpoint rd6
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD7_JUMP                :   coverpoint rd7
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD8_JUMP                :   coverpoint rd8
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD9_JUMP                :   coverpoint rd9
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD10_JUMP                :   coverpoint rd10
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD11_JUMP                :   coverpoint rd11
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD12_JUMP                :   coverpoint rd12
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD13_JUMP                :   coverpoint rd13
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD14_JUMP                :   coverpoint rd14
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD15_JUMP                :   coverpoint rd15
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD16_JUMP                :   coverpoint rd16
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD17_JUMP                :   coverpoint rd17
                           {
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD18_JUMP                :   coverpoint rd18
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD19_JUMP                :   coverpoint rd19
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD20_JUMP                :   coverpoint rd20
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD21_JUMP                :   coverpoint rd21
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD22_JUMP                :   coverpoint rd22
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD23_JUMP                :   coverpoint rd23
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD24_JUMP                :   coverpoint rd24
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD25_JUMP                :   coverpoint rd25
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD26_JUMP                :   coverpoint rd26
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD27_JUMP                :   coverpoint rd27
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD28_JUMP                :   coverpoint rd28
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD29_JUMP                :   coverpoint rd29
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD30_JUMP                :   coverpoint rd30
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                           }
    RD31_JUMP                :   coverpoint rd31
                           {
                                
                                 bins range = {[20'h8100:20'h48000]};
                            }
    OPCODE                  :   coverpoint opcode
                            {
                                //option.auto_bin_max = 32;
                                bins r_type         =   {7'h33};  // r type instructions
                                bins i_type         =   {7'h13};  // i type instructions
                                bins i_type_jalr    =   {7'h67};  // i type jalar instruction 
                                bins uj_type        =   {7'h6f};  // uj type instructions
                                bins u_type         =   {7'h17};  // u type instructions
                            }

   ADD_EN                   : coverpoint add_en
                            {
                                bins add_enable   = {1};
                            }
   SUB_EN                   : coverpoint sub_en
                            {
                                bins sub_enable   = {1};
                            }

   SLL_EN                   : coverpoint sll_en
                            {
                                bins sll_enable   = {1};
                            }

   SLT_EN                   : coverpoint slt_en
                            {
                                bins slt_enable   = {1};
                            }
   XOR_EN                   : coverpoint xor_en
                            {
                                bins xor_enable   = {1};
                            }

   SRL_EN                   : coverpoint srl_en
                            {
                                bins srl_enable   = {1};
                            }
   SRA_EN                   : coverpoint sra_en
                            {
                                bins sra_enable   = {1};
                            }
   OR_EN                   : coverpoint or_en
                            {
                                bins or_enable   = {1};
                            }
   AND_EN                   : coverpoint and_en
                            {
                                bins and_enable   = {1};
                            }



   JALR_EN                   : coverpoint jalr_en
                            {
                                bins jalr_enable   = {0};
                            }
   JAL_EN                   : coverpoint jal_en
                            {
                                bins jal_enable   = {0};
                            }

   LUI_EN                   : coverpoint lui_en
                            {
                                bins lui_enable   = {1};
                            }

    DATA_IN_1                   :   coverpoint data_in_1
                            {
                                bins data_in_1_low     =   {[32'h00000000:32'h00FFFFFF]} ;
                                bins data_in_1_medium  =   {[32'h01000000:32'h1FFFFFFF]} ;
                                bins data_in_1_Extreme =   {[32'h20000000:32'hFFFFFFFF]} ;
                            }
    DATA_IN_2                   :   coverpoint data_in_2
                            {
                                bins data_in_1_low     =   {[32'h00000000:32'h00FFFFFF]} ;
                                bins data_in_1_medium  =   {[32'h01000000:32'h1FFFFFFF]} ;
                                bins data_in_1_Extreme =   {[32'h20000000:32'hFFFFFFFF]} ;
                            }
    DATA_OUT                   :   coverpoint data_out
                            {
                                bins data_in_1_low     =   {[32'h00000000:32'h00FFFFFF]} ;
                                bins data_in_1_medium  =   {[32'h01000000:32'h1FFFFFFF]} ;
                                bins data_in_1_Extreme =   {[32'h20000000:32'hFFFFFFFF]} ;
                            }


//--------------------------------------------------------------------//
//--------------------------R-TYPE -------Coverage--Begins------------//
//--------------------------------------------------------------------//


   R_TYPE_ADD_INST          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , OUT ;   
   R_TYPE_SUB_INST          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , OUT ;   
   R_TYPE_SLL_INST          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , OUT ;   
   R_TYPE_SLT_INST          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , OUT ;   
   R_TYPE_SLTU_INST         :   cross R_OPCODE , FUNC3_3 , FUNC7_00 , OUT ;   
   R_TYPE_XOR_INST          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , OUT ;   
   R_TYPE_SRL_INST          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , OUT ;   
   R_TYPE_SRA_INST          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , OUT ;   
   R_TYPE_OR_INST           :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , OUT ;   
   R_TYPE_AND_INST          :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , OUT ;

//----------------------R-Type Enable signals cov-----//
   R_TYPE_ADD_INST_ALU_EN          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , ADD_EN ;   
   R_TYPE_SUB_INST_ALU_EN          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , SUB_EN ;   
   R_TYPE_SLL_INST_ALU_EN          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , SLL_EN ;   
   R_TYPE_SLT_INST_ALU_EN          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , SLT_EN ;   
   R_TYPE_SLTU_INST_ALU_EN         :   cross R_OPCODE , FUNC3_3 , FUNC7_00 , SLT_EN ;   
   R_TYPE_XOR_INST_ALU_EN          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , XOR_EN ;   
   R_TYPE_SRL_INST_ALU_EN          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , SRL_EN ;   
   R_TYPE_SRA_INST_ALU_EN          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , SRA_EN ;   
   R_TYPE_OR_INST_ALU_EN           :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , OR_EN ;   
   R_TYPE_AND_INST_ALU_EN          :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , AND_EN ; 


// data in_1 , data_in2 and data_out//
   R_TYPE_ADD_INST_DATA_IN_1          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , DATA_IN_1 ;   
   R_TYPE_SUB_INST_DATA_IN_1          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , DATA_IN_1 ;   
   R_TYPE_SLL_INST_DATA_IN_1          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , DATA_IN_1 ;   
   R_TYPE_SLT_INST_DATA_IN_1          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , DATA_IN_1 ;   
   R_TYPE_SLTU_INST_DATA_IN_1         :   cross R_OPCODE , FUNC3_3 , FUNC7_00 , DATA_IN_1 ;   
   R_TYPE_XOR_INST_DATA_IN_1          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , DATA_IN_1 ;   
   R_TYPE_SRL_INST_DATA_IN_1          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , DATA_IN_1 ;   
   R_TYPE_SRA_INST_DATA_IN_1          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , DATA_IN_1 ;   
   R_TYPE_OR_INST_DATA_IN_1           :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , DATA_IN_1;   
   R_TYPE_AND_INST_DATA_IN_1          :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , DATA_IN_1 ; 

   R_TYPE_ADD_INST_DATA_IN_2          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , DATA_IN_2 ;   
   R_TYPE_SUB_INST_DATA_IN_2          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , DATA_IN_2 ;   
   R_TYPE_SLL_INST_DATA_IN_2          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , DATA_IN_2 ;   
   R_TYPE_SLT_INST_DATA_IN_2          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , DATA_IN_2 ;   
   R_TYPE_SLTU_INST_DATA_IN_2         :   cross R_OPCODE , FUNC3_3 , FUNC7_00 , DATA_IN_2 ;   
   R_TYPE_XOR_INST_DATA_IN_2          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , DATA_IN_2 ;   
   R_TYPE_SRL_INST_DATA_IN_2          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , DATA_IN_2 ;   
   R_TYPE_SRA_INST_DATA_IN_2          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , DATA_IN_2 ;   
   R_TYPE_OR_INST_DATA_IN_2           :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , DATA_IN_2 ;   
   R_TYPE_AND_INST_DATA_IN_2          :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , DATA_IN_2 ; 

   R_TYPE_ADD_INST_DATA_OUT          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , DATA_OUT ;   
   R_TYPE_SUB_INST_DATA_OUT          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , DATA_OUT ;   
   R_TYPE_SLL_INST_DATA_OUT          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , DATA_OUT ;   
   R_TYPE_SLT_INST_DATA_OUT          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , DATA_OUT ;   
   R_TYPE_SLTU_INST_DATA_OUT         :   cross R_OPCODE , FUNC3_3 , FUNC7_00 , DATA_OUT ;   
   R_TYPE_XOR_INST_DATA_OUT          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , DATA_OUT ;   
   R_TYPE_SRL_INST_DATA_OUT          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , DATA_OUT ;   
   R_TYPE_SRA_INST_DATA_OUT          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , DATA_OUT ;   
   R_TYPE_OR_INST_DATA_OUT           :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , DATA_OUT;   
   R_TYPE_AND_INST_DATA_OUT          :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , DATA_OUT ; 


//-------------------------------------//
//---------------ADD-------------------//
//-------------------------------------//
   R_TYPE_ADD_INST_RD1           :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD1  ;   
   R_TYPE_ADD_INST_RD2           :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD2  ;   
   R_TYPE_ADD_INST_RD3           :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD3  ;   
   R_TYPE_ADD_INST_RD4           :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD4  ;   
   R_TYPE_ADD_INST_RD5           :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD5  ;   
   R_TYPE_ADD_INST_RD6           :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD6  ;   
   R_TYPE_ADD_INST_RD7           :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD7  ;   
   R_TYPE_ADD_INST_RD8           :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD8  ;   
   R_TYPE_ADD_INST_RD9           :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD9  ;   
   R_TYPE_ADD_INST_RD10          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD10  ;   
   R_TYPE_ADD_INST_RD11          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD11  ;   
   R_TYPE_ADD_INST_RD12          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD12  ;   
   R_TYPE_ADD_INST_RD13          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD13  ;   
   R_TYPE_ADD_INST_RD14          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD14  ;   
   R_TYPE_ADD_INST_RD15          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD15  ;   
   R_TYPE_ADD_INST_RD16          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD16  ;   
   R_TYPE_ADD_INST_RD17          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD17  ;   
   R_TYPE_ADD_INST_RD18          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD18  ;   
   R_TYPE_ADD_INST_RD19          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD19  ;   
   R_TYPE_ADD_INST_RD20          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD20  ;   
   R_TYPE_ADD_INST_RD21          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD21  ;   
   R_TYPE_ADD_INST_RD22          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD22  ;   
   R_TYPE_ADD_INST_RD23          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD23  ;   
   R_TYPE_ADD_INST_RD24          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD24  ;   
   R_TYPE_ADD_INST_RD25          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD25  ;   
   R_TYPE_ADD_INST_RD26          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD26  ;   
   R_TYPE_ADD_INST_RD27          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD27  ;   
   R_TYPE_ADD_INST_RD28          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD28  ;   
   R_TYPE_ADD_INST_RD29          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD29  ;   
   R_TYPE_ADD_INST_RD30          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD30  ;   
   R_TYPE_ADD_INST_RD31          :   cross R_OPCODE , FUNC3_0 , FUNC7_00 , RD31  ;

//-------------------------------------//
//---------------SUB-------------------//
//-------------------------------------//
   R_TYPE_SUB_INST_RD1           :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD1  ;   
   R_TYPE_SUB_INST_RD2           :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD2  ;   
   R_TYPE_SUB_INST_RD3           :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD3  ;   
   R_TYPE_SUB_INST_RD4           :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD4  ;   
   R_TYPE_SUB_INST_RD5           :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD5  ;   
   R_TYPE_SUB_INST_RD6           :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD6  ;   
   R_TYPE_SUB_INST_RD7           :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD7  ;   
   R_TYPE_SUB_INST_RD8           :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD8  ;   
   R_TYPE_SUB_INST_RD9           :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD9  ;   
   R_TYPE_SUB_INST_RD10          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD10  ;   
   R_TYPE_SUB_INST_RD11          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD11  ;   
   R_TYPE_SUB_INST_RD12          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD12  ;   
   R_TYPE_SUB_INST_RD13          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD13  ;   
   R_TYPE_SUB_INST_RD14          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD14  ;   
   R_TYPE_SUB_INST_RD15          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD15  ;   
   R_TYPE_SUB_INST_RD16          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD16  ;   
   R_TYPE_SUB_INST_RD17          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD17  ;   
   R_TYPE_SUB_INST_RD18          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD18  ;   
   R_TYPE_SUB_INST_RD19          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD19  ;   
   R_TYPE_SUB_INST_RD20          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD20  ;   
   R_TYPE_SUB_INST_RD21          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD21  ;   
   R_TYPE_SUB_INST_RD22          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD22  ;   
   R_TYPE_SUB_INST_RD23          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD23  ;   
   R_TYPE_SUB_INST_RD24          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD24  ;   
   R_TYPE_SUB_INST_RD25          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD25  ;   
   R_TYPE_SUB_INST_RD26          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD26  ;   
   R_TYPE_SUB_INST_RD27          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD27  ;   
   R_TYPE_SUB_INST_RD28          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD28  ;   
   R_TYPE_SUB_INST_RD29          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD29  ;   
   R_TYPE_SUB_INST_RD30          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD30  ;   
   R_TYPE_SUB_INST_RD31          :   cross R_OPCODE , FUNC3_0 , FUNC7_20 , RD31  ;

//-------------------------------------//
//---------------SLL-------------------//
//-------------------------------------//
   R_TYPE_SLL_INST_RD1           :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD1  ;   
   R_TYPE_SLL_INST_RD2           :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD2  ;   
   R_TYPE_SLL_INST_RD3           :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD3  ;   
   R_TYPE_SLL_INST_RD4           :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD4  ;   
   R_TYPE_SLL_INST_RD5           :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD5  ;   
   R_TYPE_SLL_INST_RD6           :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD6  ;   
   R_TYPE_SLL_INST_RD7           :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD7  ;   
   R_TYPE_SLL_INST_RD8           :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD8  ;   
   R_TYPE_SLL_INST_RD9           :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD9  ;   
   R_TYPE_SLL_INST_RD10          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD10  ;   
   R_TYPE_SLL_INST_RD11          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD11  ;   
   R_TYPE_SLL_INST_RD12          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD12  ;   
   R_TYPE_SLL_INST_RD13          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD13  ;   
   R_TYPE_SLL_INST_RD14          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD14  ;   
   R_TYPE_SLL_INST_RD15          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD15  ;   
   R_TYPE_SLL_INST_RD16          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD16  ;   
   R_TYPE_SLL_INST_RD17          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD17  ;   
   R_TYPE_SLL_INST_RD18          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD18  ;   
   R_TYPE_SLL_INST_RD19          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD19  ;   
   R_TYPE_SLL_INST_RD20          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD20  ;   
   R_TYPE_SLL_INST_RD21          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD21  ;   
   R_TYPE_SLL_INST_RD22          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD22  ;   
   R_TYPE_SLL_INST_RD23          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD23  ;   
   R_TYPE_SLL_INST_RD24          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD24  ;   
   R_TYPE_SLL_INST_RD25          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD25  ;   
   R_TYPE_SLL_INST_RD26          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD26  ;   
   R_TYPE_SLL_INST_RD27          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD27  ;   
   R_TYPE_SLL_INST_RD28          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD28  ;   
   R_TYPE_SLL_INST_RD29          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD29  ;   
   R_TYPE_SLL_INST_RD30          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD30  ;   
   R_TYPE_SLL_INST_RD31          :   cross R_OPCODE , FUNC3_1 , FUNC7_00 , RD31  ;


//-------------------------------------//
//---------------SLT-------------------//
//-------------------------------------//
   R_TYPE_SLT_INST_RD1           :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD1  ;   
   R_TYPE_SLT_INST_RD2           :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD2  ;   
   R_TYPE_SLT_INST_RD3           :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD3  ;   
   R_TYPE_SLT_INST_RD4           :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD4  ;   
   R_TYPE_SLT_INST_RD5           :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD5  ;   
   R_TYPE_SLT_INST_RD6           :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD6  ;   
   R_TYPE_SLT_INST_RD7           :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD7  ;   
   R_TYPE_SLT_INST_RD8           :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD8  ;   
   R_TYPE_SLT_INST_RD9           :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD9  ;   
   R_TYPE_SLT_INST_RD10          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD10  ;   
   R_TYPE_SLT_INST_RD11          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD11  ;   
   R_TYPE_SLT_INST_RD12          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD12  ;   
   R_TYPE_SLT_INST_RD13          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD13  ;   
   R_TYPE_SLT_INST_RD14          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD14  ;   
   R_TYPE_SLT_INST_RD15          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD15  ;   
   R_TYPE_SLT_INST_RD16          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD16  ;   
   R_TYPE_SLT_INST_RD17          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD17  ;   
   R_TYPE_SLT_INST_RD18          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD18  ;   
   R_TYPE_SLT_INST_RD19          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD19  ;   
   R_TYPE_SLT_INST_RD20          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD20  ;   
   R_TYPE_SLT_INST_RD21          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD21  ;   
   R_TYPE_SLT_INST_RD22          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD22  ;   
   R_TYPE_SLT_INST_RD23          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD23  ;   
   R_TYPE_SLT_INST_RD24          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD24  ;   
   R_TYPE_SLT_INST_RD25          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD25  ;   
   R_TYPE_SLT_INST_RD26          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD26  ;   
   R_TYPE_SLT_INST_RD27          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD27  ;   
   R_TYPE_SLT_INST_RD28          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD28  ;   
   R_TYPE_SLT_INST_RD29          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD29  ;   
   R_TYPE_SLT_INST_RD30          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD30  ;   
   R_TYPE_SLT_INST_RD31          :   cross R_OPCODE , FUNC3_2 , FUNC7_00 , RD31  ;


//-------------------------------------//
//---------------SLTU-------------------//
//-------------------------------------//
   R_TYPE_SLTU_INST_RD1           :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD1  ;   
   R_TYPE_SLTU_INST_RD2           :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD2  ;   
   R_TYPE_SLTU_INST_RD3           :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD3  ;   
   R_TYPE_SLTU_INST_RD4           :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD4  ;   
   R_TYPE_SLTU_INST_RD5           :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD5  ;   
   R_TYPE_SLTU_INST_RD6           :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD6  ;   
   R_TYPE_SLTU_INST_RD7           :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD7  ;   
   R_TYPE_SLTU_INST_RD8           :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD8  ;   
   R_TYPE_SLTU_INST_RD9           :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD9  ;   
   R_TYPE_SLTU_INST_RD10          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD10  ;   
   R_TYPE_SLTU_INST_RD11          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD11  ;   
   R_TYPE_SLTU_INST_RD12          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD12  ;   
   R_TYPE_SLTU_INST_RD13          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD13  ;   
   R_TYPE_SLTU_INST_RD14          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD14  ;   
   R_TYPE_SLTU_INST_RD15          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD15  ;   
   R_TYPE_SLTU_INST_RD16          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD16  ;   
   R_TYPE_SLTU_INST_RD17          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD17  ;   
   R_TYPE_SLTU_INST_RD18          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD18  ;   
   R_TYPE_SLTU_INST_RD19          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD19  ;   
   R_TYPE_SLTU_INST_RD20          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD20  ;   
   R_TYPE_SLTU_INST_RD21          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD21  ;   
   R_TYPE_SLTU_INST_RD22          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD22  ;   
   R_TYPE_SLTU_INST_RD23          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD23  ;   
   R_TYPE_SLTU_INST_RD24          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD24  ;   
   R_TYPE_SLTU_INST_RD25          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD25  ;   
   R_TYPE_SLTU_INST_RD26          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD26  ;   
   R_TYPE_SLTU_INST_RD27          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD27  ;   
   R_TYPE_SLTU_INST_RD28          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD28  ;   
   R_TYPE_SLTU_INST_RD29          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD29  ;   
   R_TYPE_SLTU_INST_RD30          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD30  ;   
   R_TYPE_SLTU_INST_RD31          :   cross R_OPCODE ,FUNC3_3 , FUNC7_00 , RD31  ;


//-------------------------------------//
//---------------XOR-------------------//
//-------------------------------------//
   R_TYPE_XOR_INST_RD1           :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD1  ;   
   R_TYPE_XOR_INST_RD2           :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD2  ;   
   R_TYPE_XOR_INST_RD3           :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD3  ;   
   R_TYPE_XOR_INST_RD4           :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD4  ;   
   R_TYPE_XOR_INST_RD5           :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD5  ;   
   R_TYPE_XOR_INST_RD6           :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD6  ;   
   R_TYPE_XOR_INST_RD7           :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD7  ;   
   R_TYPE_XOR_INST_RD8           :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD8  ;   
   R_TYPE_XOR_INST_RD9           :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD9  ;   
   R_TYPE_XOR_INST_RD10          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD10  ;   
   R_TYPE_XOR_INST_RD11          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD11  ;   
   R_TYPE_XOR_INST_RD12          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD12  ;   
   R_TYPE_XOR_INST_RD13          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD13  ;   
   R_TYPE_XOR_INST_RD14          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD14  ;   
   R_TYPE_XOR_INST_RD15          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD15  ;   
   R_TYPE_XOR_INST_RD16          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD16  ;   
   R_TYPE_XOR_INST_RD17          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD17  ;   
   R_TYPE_XOR_INST_RD18          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD18  ;   
   R_TYPE_XOR_INST_RD19          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD19  ;   
   R_TYPE_XOR_INST_RD20          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD20  ;   
   R_TYPE_XOR_INST_RD21          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD21  ;   
   R_TYPE_XOR_INST_RD22          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD22  ;   
   R_TYPE_XOR_INST_RD23          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD23  ;   
   R_TYPE_XOR_INST_RD24          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD24  ;   
   R_TYPE_XOR_INST_RD25          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD25  ;   
   R_TYPE_XOR_INST_RD26          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD26  ;   
   R_TYPE_XOR_INST_RD27          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD27  ;   
   R_TYPE_XOR_INST_RD28          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD28  ;   
   R_TYPE_XOR_INST_RD29          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD29  ;   
   R_TYPE_XOR_INST_RD30          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD30  ;   
   R_TYPE_XOR_INST_RD31          :   cross R_OPCODE , FUNC3_4 , FUNC7_00 , RD31  ;

//-------------------------------------//
//---------------SRL-------------------//
//-------------------------------------//
   R_TYPE_SRL_INST_RD1           :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD1  ;   
   R_TYPE_SRL_INST_RD2           :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD2  ;   
   R_TYPE_SRL_INST_RD3           :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD3  ;   
   R_TYPE_SRL_INST_RD4           :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD4  ;   
   R_TYPE_SRL_INST_RD5           :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD5  ;   
   R_TYPE_SRL_INST_RD6           :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD6  ;   
   R_TYPE_SRL_INST_RD7           :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD7  ;   
   R_TYPE_SRL_INST_RD8           :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD8  ;   
   R_TYPE_SRL_INST_RD9           :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD9  ;   
   R_TYPE_SRL_INST_RD10          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD10  ;   
   R_TYPE_SRL_INST_RD11          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD11  ;   
   R_TYPE_SRL_INST_RD12          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD12  ;   
   R_TYPE_SRL_INST_RD13          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD13  ;   
   R_TYPE_SRL_INST_RD14          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD14  ;   
   R_TYPE_SRL_INST_RD15          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD15  ;   
   R_TYPE_SRL_INST_RD16          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD16  ;   
   R_TYPE_SRL_INST_RD17          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD17  ;   
   R_TYPE_SRL_INST_RD18          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD18  ;   
   R_TYPE_SRL_INST_RD19          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD19  ;   
   R_TYPE_SRL_INST_RD20          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD20  ;   
   R_TYPE_SRL_INST_RD21          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD21  ;   
   R_TYPE_SRL_INST_RD22          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD22  ;   
   R_TYPE_SRL_INST_RD23          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD23  ;   
   R_TYPE_SRL_INST_RD24          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD24  ;   
   R_TYPE_SRL_INST_RD25          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD25  ;   
   R_TYPE_SRL_INST_RD26          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD26  ;   
   R_TYPE_SRL_INST_RD27          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD27  ;   
   R_TYPE_SRL_INST_RD28          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD28  ;   
   R_TYPE_SRL_INST_RD29          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD29  ;   
   R_TYPE_SRL_INST_RD30          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD30  ;   
   R_TYPE_SRL_INST_RD31          :   cross R_OPCODE , FUNC3_5 , FUNC7_00 , RD31  ;

//-------------------------------------//
//---------------SRA-------------------//
//-------------------------------------//
   R_TYPE_SRA_INST_RD1           :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD1  ;   
   R_TYPE_SRA_INST_RD2           :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD2  ;   
   R_TYPE_SRA_INST_RD3           :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD3  ;   
   R_TYPE_SRA_INST_RD4           :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD4  ;   
   R_TYPE_SRA_INST_RD5           :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD5  ;   
   R_TYPE_SRA_INST_RD6           :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD6  ;   
   R_TYPE_SRA_INST_RD7           :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD7  ;   
   R_TYPE_SRA_INST_RD8           :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD8  ;   
   R_TYPE_SRA_INST_RD9           :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD9  ;   
   R_TYPE_SRA_INST_RD10          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD10  ;   
   R_TYPE_SRA_INST_RD11          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD11  ;   
   R_TYPE_SRA_INST_RD12          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD12  ;   
   R_TYPE_SRA_INST_RD13          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD13  ;   
   R_TYPE_SRA_INST_RD14          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD14  ;   
   R_TYPE_SRA_INST_RD15          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD15  ;   
   R_TYPE_SRA_INST_RD16          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD16  ;   
   R_TYPE_SRA_INST_RD17          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD17  ;   
   R_TYPE_SRA_INST_RD18          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD18  ;   
   R_TYPE_SRA_INST_RD19          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD19  ;   
   R_TYPE_SRA_INST_RD20          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD20  ;   
   R_TYPE_SRA_INST_RD21          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD21  ;   
   R_TYPE_SRA_INST_RD22          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD22  ;   
   R_TYPE_SRA_INST_RD23          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD23  ;   
   R_TYPE_SRA_INST_RD24          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD24  ;   
   R_TYPE_SRA_INST_RD25          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD25  ;   
   R_TYPE_SRA_INST_RD26          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD26  ;   
   R_TYPE_SRA_INST_RD27          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD27  ;   
   R_TYPE_SRA_INST_RD28          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD28  ;   
   R_TYPE_SRA_INST_RD29          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD29  ;   
   R_TYPE_SRA_INST_RD30          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD30  ;   
   R_TYPE_SRA_INST_RD31          :   cross R_OPCODE , FUNC3_5 , FUNC7_20 , RD31  ;

//-------------------------------------//
//---------------OR--------------------//
//-------------------------------------//
   R_TYPE_OR_INST_RD1           :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD1  ;   
   R_TYPE_OR_INST_RD2           :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD2  ;   
   R_TYPE_OR_INST_RD3           :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD3  ;   
   R_TYPE_OR_INST_RD4           :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD4  ;   
   R_TYPE_OR_INST_RD5           :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD5  ;   
   R_TYPE_OR_INST_RD6           :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD6  ;   
   R_TYPE_OR_INST_RD7           :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD7  ;   
   R_TYPE_OR_INST_RD8           :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD8  ;   
   R_TYPE_OR_INST_RD9           :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD9  ;   
   R_TYPE_OR_INST_RD10          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD10  ;   
   R_TYPE_OR_INST_RD11          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD11  ;   
   R_TYPE_OR_INST_RD12          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD12  ;   
   R_TYPE_OR_INST_RD13          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD13  ;   
   R_TYPE_OR_INST_RD14          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD14  ;   
   R_TYPE_OR_INST_RD15          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD15  ;   
   R_TYPE_OR_INST_RD16          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD16  ;   
   R_TYPE_OR_INST_RD17          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD17  ;   
   R_TYPE_OR_INST_RD18          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD18  ;   
   R_TYPE_OR_INST_RD19          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD19  ;   
   R_TYPE_OR_INST_RD20          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD20  ;   
   R_TYPE_OR_INST_RD21          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD21  ;   
   R_TYPE_OR_INST_RD22          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD22  ;   
   R_TYPE_OR_INST_RD23          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD23  ;   
   R_TYPE_OR_INST_RD24          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD24  ;   
   R_TYPE_OR_INST_RD25          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD25  ;   
   R_TYPE_OR_INST_RD26          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD26  ;   
   R_TYPE_OR_INST_RD27          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD27  ;   
   R_TYPE_OR_INST_RD28          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD28  ;   
   R_TYPE_OR_INST_RD29          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD29  ;   
   R_TYPE_OR_INST_RD30          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD30  ;   
   R_TYPE_OR_INST_RD31          :   cross R_OPCODE , FUNC3_6 , FUNC7_00 , RD31  ;
//-------------------------------------//
//---------------AND-------------------//
//-------------------------------------//
   R_TYPE_AND_INST_RD1          :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD1  ;   
   R_TYPE_AND_INST_RD2          :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD2  ;   
   R_TYPE_AND_INST_RD3          :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD3  ;   
   R_TYPE_AND_INST_RD4          :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD4  ;   
   R_TYPE_AND_INST_RD5          :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD5  ;   
   R_TYPE_AND_INST_RD6          :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD6  ;   
   R_TYPE_AND_INST_RD7          :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD7  ;   
   R_TYPE_AND_INST_RD8          :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD8  ;   
   R_TYPE_AND_INST_RD9          :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD9  ;   
   R_TYPE_AND_INST_RD10         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD10  ;   
   R_TYPE_AND_INST_RD11         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD11  ;   
   R_TYPE_AND_INST_RD12         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD12  ;   
   R_TYPE_AND_INST_RD13         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD13  ;   
   R_TYPE_AND_INST_RD14         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD14  ;   
   R_TYPE_AND_INST_RD15         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD15  ;   
   R_TYPE_AND_INST_RD16         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD16  ;   
   R_TYPE_AND_INST_RD17         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD17  ;   
   R_TYPE_AND_INST_RD18         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD18  ;   
   R_TYPE_AND_INST_RD19         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD19  ;   
   R_TYPE_AND_INST_RD20         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD20  ;   
   R_TYPE_AND_INST_RD21         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD21  ;   
   R_TYPE_AND_INST_RD22         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD22  ;   
   R_TYPE_AND_INST_RD23         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD23  ;   
   R_TYPE_AND_INST_RD24         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD24  ;   
   R_TYPE_AND_INST_RD25         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD25  ;   
   R_TYPE_AND_INST_RD26         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD26  ;   
   R_TYPE_AND_INST_RD27         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD27  ;   
   R_TYPE_AND_INST_RD28         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD28  ;   
   R_TYPE_AND_INST_RD29         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD29  ;   
   R_TYPE_AND_INST_RD30         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD30  ;   
   R_TYPE_AND_INST_RD31         :   cross R_OPCODE , FUNC3_7 , FUNC7_00 , RD31  ;

//--------------------------------------------------------------------//
//--------------------------R-TYPE -------Coverage--Ends--------------//
//--------------------------------------------------------------------//


//--------------------------------------------------------------------//
//--------------------------I-TYPE -------Coverage--begins------------//
//--------------------------------------------------------------------//
   I_TYPE_ADDI_INST          :   cross I_OPCODE , FUNC3_0 , FUNC7_00 , OUT ;   
   I_TYPE_SLLI_INST          :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , OUT ;   
   I_TYPE_SLTI_INST          :   cross I_OPCODE , FUNC3_2 , FUNC7_00 , OUT ;   
   I_TYPE_SLTIU_INST         :   cross I_OPCODE , FUNC3_3 , FUNC7_00 , OUT ;   
   I_TYPE_XORI_INST          :   cross I_OPCODE , FUNC3_4 , FUNC7_00 , OUT ;   
   I_TYPE_SRLI_INST          :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , OUT ;   
   I_TYPE_SRAI_INST          :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , OUT ;   
   I_TYPE_ORI_INST           :   cross I_OPCODE , FUNC3_6 , FUNC7_00 , OUT ;   
   I_TYPE_ANDI_INST          :   cross I_OPCODE , FUNC3_7 , FUNC7_00 , OUT ;   

//---------------------I-Type ALU signals---------//
   I_TYPE_ADDI_INST_ALU_EN          :   cross I_OPCODE , FUNC3_0 , FUNC7_00 , ADD_EN ;   
   I_TYPE_SLLI_INST_ALU_EN          :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , SLL_EN ;   
   I_TYPE_SLTI_INST_ALU_EN          :   cross I_OPCODE , FUNC3_2 , FUNC7_00 , SLT_EN ;   
   I_TYPE_SLTIU_INST_ALU_EN         :   cross I_OPCODE , FUNC3_3 , FUNC7_00 , SLT_EN ;   
   I_TYPE_XORI_INST_ALU_EN          :   cross I_OPCODE , FUNC3_4 , FUNC7_00 , XOR_EN ;   
   I_TYPE_SRLI_INST_ALU_EN          :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , SRL_EN ;   
   I_TYPE_SRAI_INST_ALU_EN          :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , SRA_EN ;   
   I_TYPE_ORI_INST_ALU_EN           :   cross I_OPCODE , FUNC3_6 , FUNC7_00 , OR_EN  ;   
   I_TYPE_ANDI_INST_ALU_EN          :   cross I_OPCODE , FUNC3_7 , FUNC7_00 , AND_EN ;

// data_in_1 , data_in_2 and data_out//
   I_TYPE_ADDI_INST_DATA_IN_1          :   cross I_OPCODE , FUNC3_0 , FUNC7_00 , DATA_IN_1 ;   
   I_TYPE_SLLI_INST_DATA_IN_1          :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , DATA_IN_1 ;   
   I_TYPE_SLTI_INST_DATA_IN_1          :   cross I_OPCODE , FUNC3_2 , FUNC7_00 , DATA_IN_1 ;   
   I_TYPE_SLTIU_INST_DATA_IN_1         :   cross I_OPCODE , FUNC3_3 , FUNC7_00 , DATA_IN_1 ;   
   I_TYPE_XORI_INST_DATA_IN_1          :   cross I_OPCODE , FUNC3_4 , FUNC7_00 , DATA_IN_1 ;   
   I_TYPE_SRLI_INST_DATA_IN_1          :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , DATA_IN_1 ;   
   I_TYPE_SRAI_INST_DATA_IN_1          :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , DATA_IN_1 ;   
   I_TYPE_ORI_INST_DATA_IN_1           :   cross I_OPCODE , FUNC3_6 , FUNC7_00 , DATA_IN_1 ;   
   I_TYPE_ANDI_INST_DATA_IN_1          :   cross I_OPCODE , FUNC3_7 , FUNC7_00 , DATA_IN_1 ;   

   I_TYPE_ADDI_INST_DATA_IN_2          :   cross I_OPCODE , FUNC3_0 , FUNC7_00 , DATA_IN_2 ;   
   I_TYPE_SLLI_INST_DATA_IN_2          :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , DATA_IN_2 ;   
   I_TYPE_SLTI_INST_DATA_IN_2          :   cross I_OPCODE , FUNC3_2 , FUNC7_00 , DATA_IN_2 ;   
   I_TYPE_SLTIU_INST_DATA_IN_2         :   cross I_OPCODE , FUNC3_3 , FUNC7_00 , DATA_IN_2 ;   
   I_TYPE_XORI_INST_DATA_IN_2          :   cross I_OPCODE , FUNC3_4 , FUNC7_00 , DATA_IN_2 ;   
   I_TYPE_SRLI_INST_DATA_IN_2          :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , DATA_IN_2 ;   
   I_TYPE_SRAI_INST_DATA_IN_2          :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , DATA_IN_2 ;   
   I_TYPE_ORI_INST_DATA_IN_2           :   cross I_OPCODE , FUNC3_6 , FUNC7_00 , DATA_IN_2 ;   
   I_TYPE_ANDI_INST_DATA_IN_2          :   cross I_OPCODE , FUNC3_7 , FUNC7_00 , DATA_IN_2 ;   


   I_TYPE_ADDI_INST_DATA_OUT          :   cross I_OPCODE , FUNC3_0 , FUNC7_00 , DATA_OUT ;   
   I_TYPE_SLLI_INST_DATA_OUT          :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , DATA_OUT ;   
   I_TYPE_SLTI_INST_DATA_OUT          :   cross I_OPCODE , FUNC3_2 , FUNC7_00 , DATA_OUT ;   
   I_TYPE_SLTIU_INST_DATA_OUT         :   cross I_OPCODE , FUNC3_3 , FUNC7_00 , DATA_OUT ;   
   I_TYPE_XORI_INST_DATA_OUT          :   cross I_OPCODE , FUNC3_4 , FUNC7_00 , DATA_OUT ;   
   I_TYPE_SRLI_INST_DATA_OUT          :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , DATA_OUT ;   
   I_TYPE_SRAI_INST_DATA_OUT          :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , DATA_OUT ;   
   I_TYPE_ORI_INST_DATA_OUT           :   cross I_OPCODE , FUNC3_6 , FUNC7_00 , DATA_OUT ;   
   I_TYPE_ANDI_INST_DATA_OUT          :   cross I_OPCODE , FUNC3_7 , FUNC7_00 , DATA_OUT ;   

//-------------------------------------//                              
//---------------ANDI-------------------//
//-------------------------------------//
   I_TYPE_ADDI_INST_RD1          :   cross I_OPCODE , FUNC3_0 ,  RD1  ;   
   I_TYPE_ADDI_INST_RD2          :   cross I_OPCODE , FUNC3_0 ,  RD2  ;   
   I_TYPE_ADDI_INST_RD3          :   cross I_OPCODE , FUNC3_0 ,  RD3  ;   
   I_TYPE_ADDI_INST_RD4          :   cross I_OPCODE , FUNC3_0 ,  RD4  ;   
   I_TYPE_ADDI_INST_RD5          :   cross I_OPCODE , FUNC3_0 ,  RD5  ;   
   I_TYPE_ADDI_INST_RD6          :   cross I_OPCODE , FUNC3_0 ,  RD6  ;   
   I_TYPE_ADDI_INST_RD7          :   cross I_OPCODE , FUNC3_0 ,  RD7  ;   
   I_TYPE_ADDI_INST_RD8          :   cross I_OPCODE , FUNC3_0 ,  RD8  ;   
   I_TYPE_ADDI_INST_RD9          :   cross I_OPCODE , FUNC3_0 ,  RD9  ;   
   I_TYPE_ADDI_INST_RD10         :   cross I_OPCODE , FUNC3_0 ,  RD10  ;   
   I_TYPE_ADDI_INST_RD11         :   cross I_OPCODE , FUNC3_0 ,  RD11  ;   
   I_TYPE_ADDI_INST_RD12         :   cross I_OPCODE , FUNC3_0 ,  RD12  ;   
   I_TYPE_ADDI_INST_RD13         :   cross I_OPCODE , FUNC3_0 ,  RD13  ;   
   I_TYPE_ADDI_INST_RD14         :   cross I_OPCODE , FUNC3_0 ,  RD14  ;   
   I_TYPE_ADDI_INST_RD15         :   cross I_OPCODE , FUNC3_0 ,  RD15  ;   
   I_TYPE_ADDI_INST_RD16         :   cross I_OPCODE , FUNC3_0 ,  RD16  ;   
   I_TYPE_ADDI_INST_RD17         :   cross I_OPCODE , FUNC3_0 ,  RD17  ;   
   I_TYPE_ADDI_INST_RD18         :   cross I_OPCODE , FUNC3_0 ,  RD18  ;   
   I_TYPE_ADDI_INST_RD19         :   cross I_OPCODE , FUNC3_0 ,  RD19  ;   
   I_TYPE_ADDI_INST_RD20         :   cross I_OPCODE , FUNC3_0 ,  RD20  ;   
   I_TYPE_ADDI_INST_RD21         :   cross I_OPCODE , FUNC3_0 ,  RD21  ;   
   I_TYPE_ADDI_INST_RD22         :   cross I_OPCODE , FUNC3_0 ,  RD22  ;   
   I_TYPE_ADDI_INST_RD23         :   cross I_OPCODE , FUNC3_0 ,  RD23  ;   
   I_TYPE_ADDI_INST_RD24         :   cross I_OPCODE , FUNC3_0 ,  RD24  ;   
   I_TYPE_ADDI_INST_RD25         :   cross I_OPCODE , FUNC3_0 ,  RD25  ;   
   I_TYPE_ADDI_INST_RD26         :   cross I_OPCODE , FUNC3_0 ,  RD26  ;   
   I_TYPE_ADDI_INST_RD27         :   cross I_OPCODE , FUNC3_0 ,  RD27  ;   
   I_TYPE_ADDI_INST_RD28         :   cross I_OPCODE , FUNC3_0 ,  RD28  ;   
   I_TYPE_ADDI_INST_RD29         :   cross I_OPCODE , FUNC3_0 ,  RD29  ;   
   I_TYPE_ADDI_INST_RD30         :   cross I_OPCODE , FUNC3_0 ,  RD30  ;   
   I_TYPE_ADDI_INST_RD31         :   cross I_OPCODE , FUNC3_0 ,  RD31  ;  
//-------------------------------------//
//---------------SLLI-------------------//
//-------------------------------------//
   I_TYPE_SLLI_INST_RD1          :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD1  ;   
   I_TYPE_SLLI_INST_RD2          :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD2  ;   
   I_TYPE_SLLI_INST_RD3          :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD3  ;   
   I_TYPE_SLLI_INST_RD4          :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD4  ;   
   I_TYPE_SLLI_INST_RD5          :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD5  ;   
   I_TYPE_SLLI_INST_RD6          :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD6  ;   
   I_TYPE_SLLI_INST_RD7          :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD7  ;   
   I_TYPE_SLLI_INST_RD8          :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD8  ;   
   I_TYPE_SLLI_INST_RD9          :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD9  ;   
   I_TYPE_SLLI_INST_RD10         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD10  ;   
   I_TYPE_SLLI_INST_RD11         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD11  ;   
   I_TYPE_SLLI_INST_RD12         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD12  ;   
   I_TYPE_SLLI_INST_RD13         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD13  ;   
   I_TYPE_SLLI_INST_RD14         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD14  ;   
   I_TYPE_SLLI_INST_RD15         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD15  ;   
   I_TYPE_SLLI_INST_RD16         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD16  ;   
   I_TYPE_SLLI_INST_RD17         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD17  ;   
   I_TYPE_SLLI_INST_RD18         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD18  ;   
   I_TYPE_SLLI_INST_RD19         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD19  ;   
   I_TYPE_SLLI_INST_RD20         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD20  ;   
   I_TYPE_SLLI_INST_RD21         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD21  ;   
   I_TYPE_SLLI_INST_RD22         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD22  ;   
   I_TYPE_SLLI_INST_RD23         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD23  ;   
   I_TYPE_SLLI_INST_RD24         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD24  ;   
   I_TYPE_SLLI_INST_RD25         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD25  ;   
   I_TYPE_SLLI_INST_RD26         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD26  ;   
   I_TYPE_SLLI_INST_RD27         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD27  ;   
   I_TYPE_SLLI_INST_RD28         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD28  ;   
   I_TYPE_SLLI_INST_RD29         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD29  ;   
   I_TYPE_SLLI_INST_RD30         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD30  ;   
   I_TYPE_SLLI_INST_RD31         :   cross I_OPCODE , FUNC3_1 , FUNC7_00 , RD31  ;  
//-------------------------------------//
//---------------SLTI-------------------//
//-------------------------------------//
   I_TYPE_SLTI_INST_RD1          :   cross I_OPCODE , FUNC3_2 ,  RD1  ;   
   I_TYPE_SLTI_INST_RD2          :   cross I_OPCODE , FUNC3_2 ,  RD2  ;   
   I_TYPE_SLTI_INST_RD3          :   cross I_OPCODE , FUNC3_2 ,  RD3  ;   
   I_TYPE_SLTI_INST_RD4          :   cross I_OPCODE , FUNC3_2 ,  RD4  ;   
   I_TYPE_SLTI_INST_RD5          :   cross I_OPCODE , FUNC3_2 ,  RD5  ;   
   I_TYPE_SLTI_INST_RD6          :   cross I_OPCODE , FUNC3_2 ,  RD6  ;   
   I_TYPE_SLTI_INST_RD7          :   cross I_OPCODE , FUNC3_2 ,  RD7  ;   
   I_TYPE_SLTI_INST_RD8          :   cross I_OPCODE , FUNC3_2 ,  RD8  ;   
   I_TYPE_SLTI_INST_RD9          :   cross I_OPCODE , FUNC3_2 ,  RD9  ;   
   I_TYPE_SLTI_INST_RD10         :   cross I_OPCODE , FUNC3_2 ,  RD10  ;   
   I_TYPE_SLTI_INST_RD11         :   cross I_OPCODE , FUNC3_2 ,  RD11  ;   
   I_TYPE_SLTI_INST_RD12         :   cross I_OPCODE , FUNC3_2 ,  RD12  ;   
   I_TYPE_SLTI_INST_RD13         :   cross I_OPCODE , FUNC3_2 ,  RD13  ;   
   I_TYPE_SLTI_INST_RD14         :   cross I_OPCODE , FUNC3_2 ,  RD14  ;   
   I_TYPE_SLTI_INST_RD15         :   cross I_OPCODE , FUNC3_2 ,  RD15  ;   
   I_TYPE_SLTI_INST_RD16         :   cross I_OPCODE , FUNC3_2 ,  RD16  ;   
   I_TYPE_SLTI_INST_RD17         :   cross I_OPCODE , FUNC3_2 ,  RD17  ;   
   I_TYPE_SLTI_INST_RD18         :   cross I_OPCODE , FUNC3_2 ,  RD18  ;   
   I_TYPE_SLTI_INST_RD19         :   cross I_OPCODE , FUNC3_2 ,  RD19  ;   
   I_TYPE_SLTI_INST_RD20         :   cross I_OPCODE , FUNC3_2 ,  RD20  ;   
   I_TYPE_SLTI_INST_RD21         :   cross I_OPCODE , FUNC3_2 ,  RD21  ;   
   I_TYPE_SLTI_INST_RD22         :   cross I_OPCODE , FUNC3_2 ,  RD22  ;   
   I_TYPE_SLTI_INST_RD23         :   cross I_OPCODE , FUNC3_2 ,  RD23  ;   
   I_TYPE_SLTI_INST_RD24         :   cross I_OPCODE , FUNC3_2 ,  RD24  ;   
   I_TYPE_SLTI_INST_RD25         :   cross I_OPCODE , FUNC3_2 ,  RD25  ;   
   I_TYPE_SLTI_INST_RD26         :   cross I_OPCODE , FUNC3_2 ,  RD26  ;   
   I_TYPE_SLTI_INST_RD27         :   cross I_OPCODE , FUNC3_2 ,  RD27  ;   
   I_TYPE_SLTI_INST_RD28         :   cross I_OPCODE , FUNC3_2 ,  RD28  ;   
   I_TYPE_SLTI_INST_RD29         :   cross I_OPCODE , FUNC3_2 ,  RD29  ;   
   I_TYPE_SLTI_INST_RD30         :   cross I_OPCODE , FUNC3_2 ,  RD30  ;   
   I_TYPE_SLTI_INST_RD31         :   cross I_OPCODE , FUNC3_2 ,  RD31  ;  
//-------------------------------------//
//---------------SLTIU-------------------//
//-------------------------------------//
   I_TYPE_SLTIU_INST_RD1          :   cross I_OPCODE , FUNC3_3 , RD1  ;   
   I_TYPE_SLTIU_INST_RD2          :   cross I_OPCODE , FUNC3_3 , RD2  ;   
   I_TYPE_SLTIU_INST_RD3          :   cross I_OPCODE , FUNC3_3 , RD3  ;   
   I_TYPE_SLTIU_INST_RD4          :   cross I_OPCODE , FUNC3_3 , RD4  ;   
   I_TYPE_SLTIU_INST_RD5          :   cross I_OPCODE , FUNC3_3 , RD5  ;   
   I_TYPE_SLTIU_INST_RD6          :   cross I_OPCODE , FUNC3_3 , RD6  ;   
   I_TYPE_SLTIU_INST_RD7          :   cross I_OPCODE , FUNC3_3 , RD7  ;   
   I_TYPE_SLTIU_INST_RD8          :   cross I_OPCODE , FUNC3_3 , RD8  ;   
   I_TYPE_SLTIU_INST_RD9          :   cross I_OPCODE , FUNC3_3 , RD9  ;   
   I_TYPE_SLTIU_INST_RD10         :   cross I_OPCODE , FUNC3_3 , RD10  ;   
   I_TYPE_SLTIU_INST_RD11         :   cross I_OPCODE , FUNC3_3 , RD11  ;   
   I_TYPE_SLTIU_INST_RD12         :   cross I_OPCODE , FUNC3_3 , RD12  ;   
   I_TYPE_SLTIU_INST_RD13         :   cross I_OPCODE , FUNC3_3 , RD13  ;   
   I_TYPE_SLTIU_INST_RD14         :   cross I_OPCODE , FUNC3_3 , RD14  ;   
   I_TYPE_SLTIU_INST_RD15         :   cross I_OPCODE , FUNC3_3 , RD15  ;   
   I_TYPE_SLTIU_INST_RD16         :   cross I_OPCODE , FUNC3_3 , RD16  ;   
   I_TYPE_SLTIU_INST_RD17         :   cross I_OPCODE , FUNC3_3 , RD17  ;   
   I_TYPE_SLTIU_INST_RD18         :   cross I_OPCODE , FUNC3_3 , RD18  ;   
   I_TYPE_SLTIU_INST_RD19         :   cross I_OPCODE , FUNC3_3 , RD19  ;   
   I_TYPE_SLTIU_INST_RD20         :   cross I_OPCODE , FUNC3_3 , RD20  ;   
   I_TYPE_SLTIU_INST_RD21         :   cross I_OPCODE , FUNC3_3 , RD21  ;   
   I_TYPE_SLTIU_INST_RD22         :   cross I_OPCODE , FUNC3_3 , RD22  ;   
   I_TYPE_SLTIU_INST_RD23         :   cross I_OPCODE , FUNC3_3 , RD23  ;   
   I_TYPE_SLTIU_INST_RD24         :   cross I_OPCODE , FUNC3_3 , RD24  ;   
   I_TYPE_SLTIU_INST_RD25         :   cross I_OPCODE , FUNC3_3 , RD25  ;   
   I_TYPE_SLTIU_INST_RD26         :   cross I_OPCODE , FUNC3_3 , RD26  ;   
   I_TYPE_SLTIU_INST_RD27         :   cross I_OPCODE , FUNC3_3 , RD27  ;   
   I_TYPE_SLTIU_INST_RD28         :   cross I_OPCODE , FUNC3_3 , RD28  ;   
   I_TYPE_SLTIU_INST_RD29         :   cross I_OPCODE , FUNC3_3 , RD29  ;   
   I_TYPE_SLTIU_INST_RD30         :   cross I_OPCODE , FUNC3_3 , RD30  ;   
   I_TYPE_SLTIU_INST_RD31         :   cross I_OPCODE , FUNC3_3 , RD31  ;  
//-------------------------------------//
//---------------XORI-------------------//
//-------------------------------------//
   I_TYPE_XORI_INST_RD1          :   cross I_OPCODE , FUNC3_4 , RD1  ;   
   I_TYPE_XORI_INST_RD2          :   cross I_OPCODE , FUNC3_4 , RD2  ;   
   I_TYPE_XORI_INST_RD3          :   cross I_OPCODE , FUNC3_4 , RD3  ;   
   I_TYPE_XORI_INST_RD4          :   cross I_OPCODE , FUNC3_4 , RD4  ;   
   I_TYPE_XORI_INST_RD5          :   cross I_OPCODE , FUNC3_4 , RD5  ;   
   I_TYPE_XORI_INST_RD6          :   cross I_OPCODE , FUNC3_4 , RD6  ;   
   I_TYPE_XORI_INST_RD7          :   cross I_OPCODE , FUNC3_4 , RD7  ;   
   I_TYPE_XORI_INST_RD8          :   cross I_OPCODE , FUNC3_4 , RD8  ;   
   I_TYPE_XORI_INST_RD9          :   cross I_OPCODE , FUNC3_4 , RD9  ;   
   I_TYPE_XORI_INST_RD10         :   cross I_OPCODE , FUNC3_4 , RD10  ;   
   I_TYPE_XORI_INST_RD11         :   cross I_OPCODE , FUNC3_4 , RD11  ;   
   I_TYPE_XORI_INST_RD12         :   cross I_OPCODE , FUNC3_4 , RD12  ;   
   I_TYPE_XORI_INST_RD13         :   cross I_OPCODE , FUNC3_4 , RD13  ;   
   I_TYPE_XORI_INST_RD14         :   cross I_OPCODE , FUNC3_4 , RD14  ;   
   I_TYPE_XORI_INST_RD15         :   cross I_OPCODE , FUNC3_4 , RD15  ;   
   I_TYPE_XORI_INST_RD16         :   cross I_OPCODE , FUNC3_4 , RD16  ;   
   I_TYPE_XORI_INST_RD17         :   cross I_OPCODE , FUNC3_4 , RD17  ;   
   I_TYPE_XORI_INST_RD18         :   cross I_OPCODE , FUNC3_4 , RD18  ;   
   I_TYPE_XORI_INST_RD19         :   cross I_OPCODE , FUNC3_4 , RD19  ;   
   I_TYPE_XORI_INST_RD20         :   cross I_OPCODE , FUNC3_4 , RD20  ;   
   I_TYPE_XORI_INST_RD21         :   cross I_OPCODE , FUNC3_4 , RD21  ;   
   I_TYPE_XORI_INST_RD22         :   cross I_OPCODE , FUNC3_4 , RD22  ;   
   I_TYPE_XORI_INST_RD23         :   cross I_OPCODE , FUNC3_4 , RD23  ;   
   I_TYPE_XORI_INST_RD24         :   cross I_OPCODE , FUNC3_4 , RD24  ;   
   I_TYPE_XORI_INST_RD25         :   cross I_OPCODE , FUNC3_4 , RD25  ;   
   I_TYPE_XORI_INST_RD26         :   cross I_OPCODE , FUNC3_4 , RD26  ;   
   I_TYPE_XORI_INST_RD27         :   cross I_OPCODE , FUNC3_4 , RD27  ;   
   I_TYPE_XORI_INST_RD28         :   cross I_OPCODE , FUNC3_4 , RD28  ;   
   I_TYPE_XORI_INST_RD29         :   cross I_OPCODE , FUNC3_4 , RD29  ;   
   I_TYPE_XORI_INST_RD30         :   cross I_OPCODE , FUNC3_4 , RD30  ;   
   I_TYPE_XORI_INST_RD31         :   cross I_OPCODE , FUNC3_4 , RD31  ;  

//-------------------------------------//
//---------------SRLI-------------------//
//-------------------------------------//
   I_TYPE_SRLI_INST_RD1          :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD1  ;   
   I_TYPE_SRLI_INST_RD2          :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD2  ;   
   I_TYPE_SRLI_INST_RD3          :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD3  ;   
   I_TYPE_SRLI_INST_RD4          :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD4  ;   
   I_TYPE_SRLI_INST_RD5          :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD5  ;   
   I_TYPE_SRLI_INST_RD6          :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD6  ;   
   I_TYPE_SRLI_INST_RD7          :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD7  ;   
   I_TYPE_SRLI_INST_RD8          :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD8  ;   
   I_TYPE_SRLI_INST_RD9          :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD9  ;   
   I_TYPE_SRLI_INST_RD10         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD10  ;   
   I_TYPE_SRLI_INST_RD11         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD11  ;   
   I_TYPE_SRLI_INST_RD12         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD12  ;   
   I_TYPE_SRLI_INST_RD13         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD13  ;   
   I_TYPE_SRLI_INST_RD14         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD14  ;   
   I_TYPE_SRLI_INST_RD15         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD15  ;   
   I_TYPE_SRLI_INST_RD16         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD16  ;   
   I_TYPE_SRLI_INST_RD17         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD17  ;   
   I_TYPE_SRLI_INST_RD18         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD18  ;   
   I_TYPE_SRLI_INST_RD19         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD19  ;   
   I_TYPE_SRLI_INST_RD20         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD20  ;   
   I_TYPE_SRLI_INST_RD21         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD21  ;   
   I_TYPE_SRLI_INST_RD22         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD22  ;   
   I_TYPE_SRLI_INST_RD23         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD23  ;   
   I_TYPE_SRLI_INST_RD24         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD24  ;   
   I_TYPE_SRLI_INST_RD25         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD25  ;   
   I_TYPE_SRLI_INST_RD26         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD26  ;   
   I_TYPE_SRLI_INST_RD27         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD27  ;   
   I_TYPE_SRLI_INST_RD28         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD28  ;   
   I_TYPE_SRLI_INST_RD29         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD29  ;   
   I_TYPE_SRLI_INST_RD30         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD30  ;   
   I_TYPE_SRLI_INST_RD31         :   cross I_OPCODE , FUNC3_5 , FUNC7_00 , RD31  ;  

//-------------------------------------//
//---------------SRAI-------------------//
//-------------------------------------//
   I_TYPE_SRAI_INST_RD1          :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD1  ;   
   I_TYPE_SRAI_INST_RD2          :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD2  ;   
   I_TYPE_SRAI_INST_RD3          :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD3  ;   
   I_TYPE_SRAI_INST_RD4          :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD4  ;   
   I_TYPE_SRAI_INST_RD5          :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD5  ;   
   I_TYPE_SRAI_INST_RD6          :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD6  ;   
   I_TYPE_SRAI_INST_RD7          :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD7  ;   
   I_TYPE_SRAI_INST_RD8          :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD8  ;   
   I_TYPE_SRAI_INST_RD9          :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD9  ;   
   I_TYPE_SRAI_INST_RD10         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD10  ;   
   I_TYPE_SRAI_INST_RD11         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD11  ;   
   I_TYPE_SRAI_INST_RD12         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD12  ;   
   I_TYPE_SRAI_INST_RD13         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD13  ;   
   I_TYPE_SRAI_INST_RD14         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD14  ;   
   I_TYPE_SRAI_INST_RD15         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD15  ;   
   I_TYPE_SRAI_INST_RD16         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD16  ;   
   I_TYPE_SRAI_INST_RD17         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD17  ;   
   I_TYPE_SRAI_INST_RD18         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD18  ;   
   I_TYPE_SRAI_INST_RD19         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD19  ;   
   I_TYPE_SRAI_INST_RD20         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD20  ;   
   I_TYPE_SRAI_INST_RD21         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD21  ;   
   I_TYPE_SRAI_INST_RD22         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD22  ;   
   I_TYPE_SRAI_INST_RD23         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD23  ;   
   I_TYPE_SRAI_INST_RD24         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD24  ;   
   I_TYPE_SRAI_INST_RD25         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD25  ;   
   I_TYPE_SRAI_INST_RD26         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD26  ;   
   I_TYPE_SRAI_INST_RD27         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD27  ;   
   I_TYPE_SRAI_INST_RD28         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD28  ;   
   I_TYPE_SRAI_INST_RD29         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD29  ;   
   I_TYPE_SRAI_INST_RD30         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD30  ;   
   I_TYPE_SRAI_INST_RD31         :   cross I_OPCODE , FUNC3_5 , FUNC7_20 , RD31  ;  

//-------------------------------------//
//---------------ORI-------------------//
//-------------------------------------//
   I_TYPE_ORI_INST_RD1          :   cross I_OPCODE , FUNC3_6 , RD1  ;   
   I_TYPE_ORI_INST_RD2          :   cross I_OPCODE , FUNC3_6 , RD2  ;   
   I_TYPE_ORI_INST_RD3          :   cross I_OPCODE , FUNC3_6 , RD3  ;   
   I_TYPE_ORI_INST_RD4          :   cross I_OPCODE , FUNC3_6 , RD4  ;   
   I_TYPE_ORI_INST_RD5          :   cross I_OPCODE , FUNC3_6 , RD5  ;   
   I_TYPE_ORI_INST_RD6          :   cross I_OPCODE , FUNC3_6 , RD6  ;   
   I_TYPE_ORI_INST_RD7          :   cross I_OPCODE , FUNC3_6 , RD7  ;   
   I_TYPE_ORI_INST_RD8          :   cross I_OPCODE , FUNC3_6 , RD8  ;   
   I_TYPE_ORI_INST_RD9          :   cross I_OPCODE , FUNC3_6 , RD9  ;   
   I_TYPE_ORI_INST_RD10         :   cross I_OPCODE , FUNC3_6 , RD10  ;   
   I_TYPE_ORI_INST_RD11         :   cross I_OPCODE , FUNC3_6 , RD11  ;   
   I_TYPE_ORI_INST_RD12         :   cross I_OPCODE , FUNC3_6 , RD12  ;   
   I_TYPE_ORI_INST_RD13         :   cross I_OPCODE , FUNC3_6 , RD13  ;   
   I_TYPE_ORI_INST_RD14         :   cross I_OPCODE , FUNC3_6 , RD14  ;   
   I_TYPE_ORI_INST_RD15         :   cross I_OPCODE , FUNC3_6 , RD15  ;   
   I_TYPE_ORI_INST_RD16         :   cross I_OPCODE , FUNC3_6 , RD16  ;   
   I_TYPE_ORI_INST_RD17         :   cross I_OPCODE , FUNC3_6 , RD17  ;   
   I_TYPE_ORI_INST_RD18         :   cross I_OPCODE , FUNC3_6 , RD18  ;   
   I_TYPE_ORI_INST_RD19         :   cross I_OPCODE , FUNC3_6 , RD19  ;   
   I_TYPE_ORI_INST_RD20         :   cross I_OPCODE , FUNC3_6 , RD20  ;   
   I_TYPE_ORI_INST_RD21         :   cross I_OPCODE , FUNC3_6 , RD21  ;   
   I_TYPE_ORI_INST_RD22         :   cross I_OPCODE , FUNC3_6 , RD22  ;   
   I_TYPE_ORI_INST_RD23         :   cross I_OPCODE , FUNC3_6 , RD23  ;   
   I_TYPE_ORI_INST_RD24         :   cross I_OPCODE , FUNC3_6 , RD24  ;   
   I_TYPE_ORI_INST_RD25         :   cross I_OPCODE , FUNC3_6 , RD25  ;   
   I_TYPE_ORI_INST_RD26         :   cross I_OPCODE , FUNC3_6 , RD26  ;   
   I_TYPE_ORI_INST_RD27         :   cross I_OPCODE , FUNC3_6 , RD27  ;   
   I_TYPE_ORI_INST_RD28         :   cross I_OPCODE , FUNC3_6 , RD28  ;   
   I_TYPE_ORI_INST_RD29         :   cross I_OPCODE , FUNC3_6 , RD29  ;   
   I_TYPE_ORI_INST_RD30         :   cross I_OPCODE , FUNC3_6 , RD30  ;   
   I_TYPE_ORI_INST_RD31         :   cross I_OPCODE , FUNC3_6 , RD31  ;  

//-------------------------------------//
//---------------ANDI-------------------//
//-------------------------------------//
   I_TYPE_ANDI_INST_RD1          :   cross I_OPCODE , FUNC3_7 , RD1  ;   
   I_TYPE_ANDI_INST_RD2          :   cross I_OPCODE , FUNC3_7 , RD2  ;   
   I_TYPE_ANDI_INST_RD3          :   cross I_OPCODE , FUNC3_7 , RD3  ;   
   I_TYPE_ANDI_INST_RD4          :   cross I_OPCODE , FUNC3_7 , RD4  ;   
   I_TYPE_ANDI_INST_RD5          :   cross I_OPCODE , FUNC3_7 , RD5  ;   
   I_TYPE_ANDI_INST_RD6          :   cross I_OPCODE , FUNC3_7 , RD6  ;   
   I_TYPE_ANDI_INST_RD7          :   cross I_OPCODE , FUNC3_7 , RD7  ;   
   I_TYPE_ANDI_INST_RD8          :   cross I_OPCODE , FUNC3_7 , RD8  ;   
   I_TYPE_ANDI_INST_RD9          :   cross I_OPCODE , FUNC3_7 , RD9  ;   
   I_TYPE_ANDI_INST_RD10         :   cross I_OPCODE , FUNC3_7 , RD10  ;   
   I_TYPE_ANDI_INST_RD11         :   cross I_OPCODE , FUNC3_7 , RD11  ;   
   I_TYPE_ANDI_INST_RD12         :   cross I_OPCODE , FUNC3_7 , RD12  ;   
   I_TYPE_ANDI_INST_RD13         :   cross I_OPCODE , FUNC3_7 , RD13  ;   
   I_TYPE_ANDI_INST_RD14         :   cross I_OPCODE , FUNC3_7 , RD14  ;   
   I_TYPE_ANDI_INST_RD15         :   cross I_OPCODE , FUNC3_7 , RD15  ;   
   I_TYPE_ANDI_INST_RD16         :   cross I_OPCODE , FUNC3_7 , RD16  ;   
   I_TYPE_ANDI_INST_RD17         :   cross I_OPCODE , FUNC3_7 , RD17  ;   
   I_TYPE_ANDI_INST_RD18         :   cross I_OPCODE , FUNC3_7 , RD18  ;   
   I_TYPE_ANDI_INST_RD19         :   cross I_OPCODE , FUNC3_7 , RD19  ;   
   I_TYPE_ANDI_INST_RD20         :   cross I_OPCODE , FUNC3_7 , RD20  ;   
   I_TYPE_ANDI_INST_RD21         :   cross I_OPCODE , FUNC3_7 , RD21  ;   
   I_TYPE_ANDI_INST_RD22         :   cross I_OPCODE , FUNC3_7 , RD22  ;   
   I_TYPE_ANDI_INST_RD23         :   cross I_OPCODE , FUNC3_7 , RD23  ;   
   I_TYPE_ANDI_INST_RD24         :   cross I_OPCODE , FUNC3_7 , RD24  ;   
   I_TYPE_ANDI_INST_RD25         :   cross I_OPCODE , FUNC3_7 , RD25  ;   
   I_TYPE_ANDI_INST_RD26         :   cross I_OPCODE , FUNC3_7 , RD26  ;   
   I_TYPE_ANDI_INST_RD27         :   cross I_OPCODE , FUNC3_7 , RD27  ;   
   I_TYPE_ANDI_INST_RD28         :   cross I_OPCODE , FUNC3_7 , RD28  ;   
   I_TYPE_ANDI_INST_RD29         :   cross I_OPCODE , FUNC3_7 , RD29  ;   
   I_TYPE_ANDI_INST_RD30         :   cross I_OPCODE , FUNC3_7 , RD30  ;   
   I_TYPE_ANDI_INST_RD31         :   cross I_OPCODE , FUNC3_7 , RD31  ;  


//--------------------------------------------------------------------//
//--------------------------I-TYPE -------Coverage--end---------------//
//--------------------------------------------------------------------//




//--------------------------------------------------------------------//
//--------------------------I-TYPE JALR-------Coverage--begin---------//
//--------------------------------------------------------------------//


   I_TYPE_JALR_INST          :   cross I_JALR_OPCODE , OUT_JUMP ;  

//------I-TYpe-JALR alu en signal ------------//
   I_TYPE_JALR_INST_ALU_EN          :   cross I_JALR_OPCODE , JALR_EN ;   


//-------------------------------------//
//---------------JALR-------------------//
//-------------------------------------//
   I_TYPE_JALR_INST_RD1          :   cross I_JALR_OPCODE , RD1_JUMP  ;   
   I_TYPE_JALR_INST_RD2          :   cross I_JALR_OPCODE , RD2_JUMP  ;   
   I_TYPE_JALR_INST_RD3          :   cross I_JALR_OPCODE , RD3_JUMP  ;   
   I_TYPE_JALR_INST_RD4          :   cross I_JALR_OPCODE , RD4_JUMP  ;   
   I_TYPE_JALR_INST_RD5          :   cross I_JALR_OPCODE , RD5_JUMP  ;   
   I_TYPE_JALR_INST_RD6          :   cross I_JALR_OPCODE , RD6_JUMP  ;   
   I_TYPE_JALR_INST_RD7          :   cross I_JALR_OPCODE , RD7_JUMP  ;   
   I_TYPE_JALR_INST_RD8          :   cross I_JALR_OPCODE , RD8_JUMP  ;   
   I_TYPE_JALR_INST_RD9          :   cross I_JALR_OPCODE , RD9_JUMP  ;   
   I_TYPE_JALR_INST_RD10         :   cross I_JALR_OPCODE , RD10_JUMP  ;   
   I_TYPE_JALR_INST_RD11         :   cross I_JALR_OPCODE , RD11_JUMP  ;   
   I_TYPE_JALR_INST_RD12         :   cross I_JALR_OPCODE , RD12_JUMP  ;   
   I_TYPE_JALR_INST_RD13         :   cross I_JALR_OPCODE , RD13_JUMP  ;   
   I_TYPE_JALR_INST_RD14         :   cross I_JALR_OPCODE , RD14_JUMP  ;   
   I_TYPE_JALR_INST_RD15         :   cross I_JALR_OPCODE , RD15_JUMP  ;   
   I_TYPE_JALR_INST_RD16         :   cross I_JALR_OPCODE , RD16_JUMP  ;   
   I_TYPE_JALR_INST_RD17         :   cross I_JALR_OPCODE , RD17_JUMP  ;   
   I_TYPE_JALR_INST_RD18         :   cross I_JALR_OPCODE , RD18_JUMP  ;   
   I_TYPE_JALR_INST_RD19         :   cross I_JALR_OPCODE , RD19_JUMP  ;   
   I_TYPE_JALR_INST_RD20         :   cross I_JALR_OPCODE , RD20_JUMP  ;   
   I_TYPE_JALR_INST_RD21         :   cross I_JALR_OPCODE , RD21_JUMP  ;   
   I_TYPE_JALR_INST_RD22         :   cross I_JALR_OPCODE , RD22_JUMP  ;   
   I_TYPE_JALR_INST_RD23         :   cross I_JALR_OPCODE , RD23_JUMP  ;   
   I_TYPE_JALR_INST_RD24         :   cross I_JALR_OPCODE , RD24_JUMP  ;   
   I_TYPE_JALR_INST_RD25         :   cross I_JALR_OPCODE , RD25_JUMP  ;   
   I_TYPE_JALR_INST_RD26         :   cross I_JALR_OPCODE , RD26_JUMP  ;   
   I_TYPE_JALR_INST_RD27         :   cross I_JALR_OPCODE , RD27_JUMP  ;   
   I_TYPE_JALR_INST_RD28         :   cross I_JALR_OPCODE , RD28_JUMP  ;   
   I_TYPE_JALR_INST_RD29         :   cross I_JALR_OPCODE , RD29_JUMP  ;   
   I_TYPE_JALR_INST_RD30         :   cross I_JALR_OPCODE , RD30_JUMP  ;   
   I_TYPE_JALR_INST_RD31         :   cross I_JALR_OPCODE , RD31_JUMP  ; 


//--------------------------------------------------------------------//
//--------------------------I-TYPE JALR-------Coverage--end---------//
//--------------------------------------------------------------------//

//--------------------------------------------------------------------//
//--------------------------U-TYPE -----------Coverage--begin---------//
//--------------------------------------------------------------------//

   U_TYPE_LUI_INST          :   cross U_OPCODE , OUT_JUMP ; 



//------U-TYpe-LUI alu en signal ------------//
   U_TYPE_LUI_INST_ALU_EN          :   cross U_OPCODE , LUI_EN ; 

//-------------------------------------//
//---------------JALR-------------------//
//-------------------------------------//
   U_TYPE_LUI_INST_RD1          :   cross U_OPCODE , RD1_JUMP  ;   
   U_TYPE_LUI_INST_RD2          :   cross U_OPCODE , RD2_JUMP  ;   
   U_TYPE_LUI_INST_RD3          :   cross U_OPCODE , RD3_JUMP  ;   
   U_TYPE_LUI_INST_RD4          :   cross U_OPCODE , RD4_JUMP  ;   
   U_TYPE_LUI_INST_RD5          :   cross U_OPCODE , RD5_JUMP  ;   
   U_TYPE_LUI_INST_RD6          :   cross U_OPCODE , RD6_JUMP  ;   
   U_TYPE_LUI_INST_RD7          :   cross U_OPCODE , RD7_JUMP  ;   
   U_TYPE_LUI_INST_RD8          :   cross U_OPCODE , RD8_JUMP  ;   
   U_TYPE_LUI_INST_RD9          :   cross U_OPCODE , RD9_JUMP  ;   
   U_TYPE_LUI_INST_RD10         :   cross U_OPCODE , RD10_JUMP  ;   
   U_TYPE_LUI_INST_RD11         :   cross U_OPCODE , RD11_JUMP  ;   
   U_TYPE_LUI_INST_RD12         :   cross U_OPCODE , RD12_JUMP  ;   
   U_TYPE_LUI_INST_RD13         :   cross U_OPCODE , RD13_JUMP  ;   
   U_TYPE_LUI_INST_RD14         :   cross U_OPCODE , RD14_JUMP  ;   
   U_TYPE_LUI_INST_RD15         :   cross U_OPCODE , RD15_JUMP  ;   
   U_TYPE_LUI_INST_RD16         :   cross U_OPCODE , RD16_JUMP  ;   
   U_TYPE_LUI_INST_RD17         :   cross U_OPCODE , RD17_JUMP  ;   
   U_TYPE_LUI_INST_RD18         :   cross U_OPCODE , RD18_JUMP  ;   
   U_TYPE_LUI_INST_RD19         :   cross U_OPCODE , RD19_JUMP  ;   
   U_TYPE_LUI_INST_RD20         :   cross U_OPCODE , RD20_JUMP  ;   
   U_TYPE_LUI_INST_RD21         :   cross U_OPCODE , RD21_JUMP  ;   
   U_TYPE_LUI_INST_RD22         :   cross U_OPCODE , RD22_JUMP  ;   
   U_TYPE_LUI_INST_RD23         :   cross U_OPCODE , RD23_JUMP  ;   
   U_TYPE_LUI_INST_RD24         :   cross U_OPCODE , RD24_JUMP  ;   
   U_TYPE_LUI_INST_RD25         :   cross U_OPCODE , RD25_JUMP  ;   
   U_TYPE_LUI_INST_RD26         :   cross U_OPCODE , RD26_JUMP  ;   
   U_TYPE_LUI_INST_RD27         :   cross U_OPCODE , RD27_JUMP  ;   
   U_TYPE_LUI_INST_RD28         :   cross U_OPCODE , RD28_JUMP  ;   
   U_TYPE_LUI_INST_RD29         :   cross U_OPCODE , RD29_JUMP  ;   
   U_TYPE_LUI_INST_RD30         :   cross U_OPCODE , RD30_JUMP  ;   
   U_TYPE_LUI_INST_RD31         :   cross U_OPCODE , RD31_JUMP  ; 

//--------------------------------------------------------------------//
//--------------------------U-TYPE -----------Coverage--end-----------//
//--------------------------------------------------------------------//


//--------------------------------------------------------------------//
//--------------------------UJ-TYPE -----------Coverage--begin---------//
//--------------------------------------------------------------------//

   UJ_TYPE_JAL_INST          :   cross UJ_OPCODE , OUT_JUMP ;   


//------U-TYpe-JAL alu en signal ------------//

   UJ_TYPE_JAL_INST_ALU_EN          :   cross UJ_OPCODE , JAL_EN ;   



//-------------------------------------//
//---------------JAL-------------------//
//-------------------------------------//
   UJ_TYPE_JAL_INST_RD1          :   cross UJ_OPCODE , RD1_JUMP  ;   
   UJ_TYPE_JAL_INST_RD2          :   cross UJ_OPCODE , RD2_JUMP  ;   
   UJ_TYPE_JAL_INST_RD3          :   cross UJ_OPCODE , RD3_JUMP  ;   
   UJ_TYPE_JAL_INST_RD4          :   cross UJ_OPCODE , RD4_JUMP  ;   
   UJ_TYPE_JAL_INST_RD5          :   cross UJ_OPCODE , RD5_JUMP  ;   
   UJ_TYPE_JAL_INST_RD6          :   cross UJ_OPCODE , RD6_JUMP  ;   
   UJ_TYPE_JAL_INST_RD7          :   cross UJ_OPCODE , RD7_JUMP  ;   
   UJ_TYPE_JAL_INST_RD8          :   cross UJ_OPCODE , RD8_JUMP  ;   
   UJ_TYPE_JAL_INST_RD9          :   cross UJ_OPCODE , RD9_JUMP  ;   
   UJ_TYPE_JAL_INST_RD10         :   cross UJ_OPCODE , RD10_JUMP  ;   
   UJ_TYPE_JAL_INST_RD11         :   cross UJ_OPCODE , RD11_JUMP  ;   
   UJ_TYPE_JAL_INST_RD12         :   cross UJ_OPCODE , RD12_JUMP  ;   
   UJ_TYPE_JAL_INST_RD13         :   cross UJ_OPCODE , RD13_JUMP  ;   
   UJ_TYPE_JAL_INST_RD14         :   cross UJ_OPCODE , RD14_JUMP  ;   
   UJ_TYPE_JAL_INST_RD15         :   cross UJ_OPCODE , RD15_JUMP  ;   
   UJ_TYPE_JAL_INST_RD16         :   cross UJ_OPCODE , RD16_JUMP  ;   
   UJ_TYPE_JAL_INST_RD17         :   cross UJ_OPCODE , RD17_JUMP  ;   
   UJ_TYPE_JAL_INST_RD18         :   cross UJ_OPCODE , RD18_JUMP  ;   
   UJ_TYPE_JAL_INST_RD19         :   cross UJ_OPCODE , RD19_JUMP  ;   
   UJ_TYPE_JAL_INST_RD20         :   cross UJ_OPCODE , RD20_JUMP  ;   
   UJ_TYPE_JAL_INST_RD21         :   cross UJ_OPCODE , RD21_JUMP  ;   
   UJ_TYPE_JAL_INST_RD22         :   cross UJ_OPCODE , RD22_JUMP  ;   
   UJ_TYPE_JAL_INST_RD23         :   cross UJ_OPCODE , RD23_JUMP  ;   
   UJ_TYPE_JAL_INST_RD24         :   cross UJ_OPCODE , RD24_JUMP  ;   
   UJ_TYPE_JAL_INST_RD25         :   cross UJ_OPCODE , RD25_JUMP  ;   
   UJ_TYPE_JAL_INST_RD26         :   cross UJ_OPCODE , RD26_JUMP  ;   
   UJ_TYPE_JAL_INST_RD27         :   cross UJ_OPCODE , RD27_JUMP  ;   
   UJ_TYPE_JAL_INST_RD28         :   cross UJ_OPCODE , RD28_JUMP  ;   
   UJ_TYPE_JAL_INST_RD29         :   cross UJ_OPCODE , RD29_JUMP  ;   
   UJ_TYPE_JAL_INST_RD30         :   cross UJ_OPCODE , RD30_JUMP  ;   
   UJ_TYPE_JAL_INST_RD31         :   cross UJ_OPCODE , RD31_JUMP  ; 

//--------------------------------------------------------------------//
//--------------------------UJ-TYPE -----------Coverage--end---------//
//--------------------------------------------------------------------//






    endgroup

//constructor new
        function new(string name ="riscv_wb_coverage", uvm_component parent);
            super.new(name, parent);
            wb_covergroup = new();
        endfunction



        function void write(input seq_item_wb_out t);
            sq_i = new();
            $cast(sq_i, t);
            this.instruction    = sq_i.instruction    ;
            this.opcode         = sq_i.opcode           ;      
            this.func3          = sq_i.func3          ;  
            this.func7          = sq_i.func7          ;      
            this.imm            = sq_i.imm            ;     
            this.rs1            = sq_i.rs1            ;     
            this.rs2            = sq_i.rs2            ;     
            this.rd             = sq_i.rd             ;     
            this.pc             = sq_i.pc             ;     
                                                       
            this.forward_a      = sq_i.forward_a      ;              
            this.forward_b      = sq_i.forward_b      ;              
            this.alu_out        = sq_i.alu_out        ;            
                                                      
            this.rd0            = sq_i.rd0            ;         
            this.rd1            = sq_i.rd1            ;     
            this.rd2            = sq_i.rd2            ;     
            this.rd3            = sq_i.rd3            ;     
            this.rd4            = sq_i.rd4            ;     
            this.rd5            = sq_i.rd5            ;     
            this.rd6            = sq_i.rd6            ;         
            this.rd7            = sq_i.rd7            ;         
            this.rd8            = sq_i.rd8            ;         
            this.rd9            = sq_i.rd9            ;             
            this.rd10           = sq_i.rd10           ;         
            this.rd11           = sq_i.rd11           ;         
            this.rd12           = sq_i.rd12           ;         
            this.rd13           = sq_i.rd13           ;         
            this.rd14           = sq_i.rd14           ;         
            this.rd15           = sq_i.rd15           ;         
            this.rd16           = sq_i.rd16           ;         
            this.rd17           = sq_i.rd17           ;         
            this.rd18           = sq_i.rd18           ;         
            this.rd19           = sq_i.rd19           ;         
            this.rd20           = sq_i.rd20           ;         
            this.rd21           = sq_i.rd21           ;         
            this.rd22           = sq_i.rd22           ;         
            this.rd23           = sq_i.rd23           ;         
            this.rd24           = sq_i.rd24           ;         
            this.rd25           = sq_i.rd25           ;         
            this.rd26           = sq_i.rd26           ;         
            this.rd27           = sq_i.rd27           ;         
            this.rd28           = sq_i.rd28           ;         
            this.rd29           = sq_i.rd29           ;         
            this.rd30           = sq_i.rd30           ;         
            this.rd31           = sq_i.rd31           ;         
                                                        
            this.out            = sq_i.out            ;                             
            
            this.data_in_1      =  sq_i.data_in_1      ;
            this.data_in_2      =  sq_i.data_in_2      ;                    
            this.data_out       =  sq_i.data_out       ;                               
            this.sub_en         =  sq_i.sub_en               ;
            this.add_en         =  sq_i.add_en               ;
            this.sll_en         =  sq_i.sll_en               ;
            this.slt_en         =  sq_i.slt_en               ;
            this.xor_en         =  sq_i.xor_en               ;
            this.srl_en         =  sq_i.srl_en               ;
            this.sra_en         =  sq_i.sra_en               ;
            this.or_en          =  sq_i.or_en                ;
            this.and_en         =  sq_i.and_en               ;
            this.jalr_en        =  sq_i.jalr_en              ;
            this.jal_en         =  sq_i.jal_en               ;   
            this.lui_en         =  sq_i.lui_en                ;     
            this.wr_data_en     =  sq_i.wr_data_en           ;
            this.in1            =  sq_i.in1           ;
            this.in2            =  sq_i.in2           ;
            this.sel            =  sq_i.sel           ;            
            wb_covergroup.sample();
        endfunction

endclass
