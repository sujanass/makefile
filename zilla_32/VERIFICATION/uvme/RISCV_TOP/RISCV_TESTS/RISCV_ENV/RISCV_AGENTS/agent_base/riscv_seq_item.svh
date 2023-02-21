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
* File Name : riscv_interface.sv

* Purpose :

* Creation Date : 29-04-2023

* Last Modified : Fri 05 May 2023 02:23:48 PM IST

* Created By :  

////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
class riscv_seq_item extends uvm_sequence_item;

//Inputs
    rand    logic                       risc_rst                    ;
    rand    logic 		                ext_int0_i	                ; 
    rand    logic 		                ext_int1_i	                ;
    rand    logic 		                ext_int2_i	                ;
    rand    logic 		                ext_int3_i	                ;
    rand    logic 		                ext_int4_i	                ;
    rand    logic 		                ext_int5_i         	        ;
    rand    logic 		                ext_int6_i	                ;
    rand    logic 		                ext_int7_i	                ;
    rand    logic 		                ext_int8_i	                ;
    rand    logic 		                ext_int9_i	                ;
    rand    logic 		                ext_int10_i	                ;
    rand    logic 		                ext_int11_i	                ;
    rand    logic 		                ext_int12_i	                ; 
    rand    logic 		                ext_int13_i	                ;
    rand    logic 		                ext_int14_i	                ;
    rand    logic 		                ext_int15_i	                ;
    rand    logic 		                ext_int16_i	                ;
    rand    logic 		                ext_int17_i	                ;
    rand    logic 		                ext_int18_i	                ;
    rand    logic 		                ext_int19_i	                ;
    rand    logic 		                ext_int20_i	                ;
    rand    logic 		                ext_int21_i	                ;
    rand    logic 		                ext_int22_i	                ;
    rand    logic 		                ext_int23_i	                ;
    rand    logic 		                ext_int24_i	                ;
    rand    logic 		                ext_int25_i	                ;
    rand    logic 		                ext_int26_i	                ;
    rand    logic 		                ext_int27_i	                ;
    rand    logic 		                ext_int28_i	                ;
    rand    logic 		                ext_int29_i	                ;
    rand    logic 		                ext_int30_i	                ;
    rand    logic 		                ext_int31_i	                ;
    rand    logic 		                ext_int32_i	                ;
    rand    logic 		                ext_int33_i	                ;
    rand    logic 		                ext_int34_i	                ;
    rand    logic 		                ext_int35_i	                ;
    rand    logic 		                ext_int36_i	                ; 
    rand    logic 		                ext_int37_i	                ;
    rand    logic 		                ext_int38_i	                ;
    rand    logic 		                ext_int39_i	                ;
    rand    logic 		                ext_int40_i	                ;
    rand    logic 		                ext_int41_i	                ;
    rand    logic 		                ext_int42_i	                ;
    rand    logic 		                ext_int43_i	                ;
    rand    logic 		                ext_int44_i	                ;
    rand    logic 		                ext_int45_i	                ;
    rand    logic 		                ext_int46_i	                ;
    rand    logic                       TRST                        ; 
    rand    logic                       TMS                         ;
    rand    logic                       TDI                         ;
    rand    logic 			            ilmb_ce                     ;
    rand    logic 			            ilmb_ready                  ;
    rand    logic 			            ilmb_rst                    ;
    rand    logic 			            ilmb_ue                     ;
    rand    logic 			            ilmb_wait                   ;
                                                            
//special
    rand    logic [31:0]    sample;
            logic [19:0]    dut_pc; 

//Outputs

            logic		                carry		                ;
            logic		                zero		                ;
            logic 		                ret_func_valid              ;
            logic                       TDO                         ;
            logic                       tdo_en                      ;
            logic 			            im_addr_strobe              ;
            logic 				        reset_uart_o                ;
         // logic 	                    mstatus_mie_w               ;
     
//Constructor
  function new(string name = "riscv_seq_item");
    super.new(name);
  endfunction

//Utility and Field macros
  `uvm_object_utils_begin(riscv_seq_item)
          `uvm_field_int(risc_rst ,                      UVM_ALL_ON)
          `uvm_field_int(ext_int0_i ,                    UVM_ALL_ON)
          `uvm_field_int(ext_int1_i ,                    UVM_ALL_ON)
          `uvm_field_int(ext_int2_i ,                    UVM_ALL_ON)
          `uvm_field_int(ext_int3_i ,                    UVM_ALL_ON)
          `uvm_field_int(ext_int4_i ,                    UVM_ALL_ON)
          `uvm_field_int(ext_int5_i ,                    UVM_ALL_ON)
          `uvm_field_int(ext_int6_i ,                    UVM_ALL_ON)
          `uvm_field_int(ext_int7_i ,                    UVM_ALL_ON)
          `uvm_field_int(ext_int8_i ,                    UVM_ALL_ON)
          `uvm_field_int(ext_int9_i ,                    UVM_ALL_ON)
          `uvm_field_int(ext_int10_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int11_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int12_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int13_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int14_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int15_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int16_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int17_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int18_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int19_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int20_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int21_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int22_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int23_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int24_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int25_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int26_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int27_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int28_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int29_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int30_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int31_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int32_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int33_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int34_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int35_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int36_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int37_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int38_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int39_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int40_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int41_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int42_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int43_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int44_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int45_i ,                   UVM_ALL_ON)
          `uvm_field_int(ext_int46_i ,                   UVM_ALL_ON)
          `uvm_field_int(TRST ,                          UVM_ALL_ON)
          `uvm_field_int(TMS,                            UVM_ALL_ON)
          `uvm_field_int(TDI ,                           UVM_ALL_ON)
          `uvm_field_int(ilmb_ce ,                       UVM_ALL_ON)
          `uvm_field_int(ilmb_ready ,                    UVM_ALL_ON)
          `uvm_field_int(ilmb_rst,                       UVM_ALL_ON)
          `uvm_field_int(ilmb_ue ,                       UVM_ALL_ON)
          `uvm_field_int(ilmb_wait ,                     UVM_ALL_ON)
          `uvm_field_int(dut_pc ,                     UVM_ALL_ON)
          
          
          `uvm_field_int(carry,                          UVM_ALL_ON)
          `uvm_field_int(zero,                           UVM_ALL_ON)
          `uvm_field_int(ret_func_valid,                 UVM_ALL_ON)
          `uvm_field_int(TDO,                            UVM_ALL_ON)
          `uvm_field_int(tdo_en,                         UVM_ALL_ON)
          `uvm_field_int(im_addr_strobe,                 UVM_ALL_ON)
          `uvm_field_int(reset_uart_o,                   UVM_ALL_ON)
       // `uvm_field_int(mstatus_mie_w,                  UVM_ALL_ON)
  `uvm_object_utils_end

endclass
