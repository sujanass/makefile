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

* Last Modified : Fri 05 May 2023 05:09:44 PM IST

* Created By :  
*/
`timescale 1ns/1ps


parameter WIDTH = 32;
parameter D_WIDTH = 32;
interface riscv_intf(   input logic                     risc_clk,
                        input logic                     TCK,
                        input logic                     mem_clk
                        );



       //Inputs
       logic                        risc_rst                    ;
       logic 		                ext_int0_i	                ; 
       logic 		                ext_int1_i	                ;
       logic 		                ext_int2_i	                ;
       logic 		                ext_int3_i	                ;
       logic 		                ext_int4_i	                ;
       logic 		                ext_int5_i         	        ;
       logic 		                ext_int6_i	                ;
       logic 		                ext_int7_i	                ;
       logic 		                ext_int8_i	                ;
       logic 		                ext_int9_i	                ;
       logic 		                ext_int10_i	                ;
       logic 		                ext_int11_i	                ;
       logic 		                ext_int12_i	                ; 
       logic 		                ext_int13_i	                ;
       logic 		                ext_int14_i	                ;
       logic 		                ext_int15_i	                ;
       logic 		                ext_int16_i	                ;
       logic 		                ext_int17_i	                ;
       logic 		                ext_int18_i	                ;
       logic 		                ext_int19_i	                ;
       logic 		                ext_int20_i	                ;
       logic 		                ext_int21_i	                ;
       logic 		                ext_int22_i	                ;
       logic 		                ext_int23_i	                ;
       logic 		                ext_int24_i	                ; 
       logic 		                ext_int25_i	                ;
       logic 		                ext_int26_i	                ;
       logic 		                ext_int27_i	                ;
       logic 		                ext_int28_i	                ;
       logic 		                ext_int29_i	                ;
       logic 		                ext_int30_i	                ;
       logic 		                ext_int31_i	                ;
       logic 		                ext_int32_i	                ;
       logic 		                ext_int33_i	                ;
       logic 		                ext_int34_i	                ;
       logic 		                ext_int35_i	                ;
       logic 		                ext_int36_i	                ; 
       logic 		                ext_int37_i	                ;
       logic 		                ext_int38_i	                ;
       logic 		                ext_int39_i	                ;
       logic 		                ext_int40_i	                ;
       logic 		                ext_int41_i	                ;
       logic 		                ext_int42_i	                ;
       logic 		                ext_int43_i	                ;
       logic 		                ext_int44_i	                ;
       logic 		                ext_int45_i	                ;
       logic 		                ext_int46_i	                ;
       logic                        TRST                        ; 
       logic                        TMS                         ;
       logic                        TDI                         ;
                                                                 
//Outputs

       logic		                carry		                ;
       logic		                zero		                ;
       logic 		                ret_func_valid              ;
       logic                        TDO                         ;
       logic                        tdo_en                      ;
       logic 			            im_addr_strobe              ;
       logic 				        reset_uart_o                ;
     

// IM variables______________________________________________________________

                logic [WIDTH-1:0]           z_im_read_data_i            ;
                logic                       z_im_write_en_o             ;
                logic [WIDTH-1:0]           z_instruction_addr_o        ;
                logic [WIDTH-1:0]           z_im_write_data_o           ;
                logic [(WIDTH>>3)-1:0]      z_im_write_data_strobe_o    ;
                logic                       z_im_read_en_o              ;
//DM variables
                logic [D_WIDTH-1:0]           data_mem_read_data_i        ;
                logic                       data_mem_write_en_o         ;
                logic [D_WIDTH-1:0]           data_mem_write_data_o       ;
                logic [D_WIDTH-1:0]           data_mem_write_addr_o       ;
                logic [(D_WIDTH>>3)-1:0]      data_mem_strobe_o           ;
                logic                       data_mem_read_en_o          ;  
                logic [D_WIDTH-1:0]           data_mem_read_addr_o        ; 


// Execute input variable
                
                logic [31:0] instruction;
                logic [6:0]  opcode;
                logic [2:0]  func3;
                logic [6:0]  func7;
                logic [31:0] imm;
                logic [4:0]  rs1;
                logic [4:0]  rs2;
                logic [4:0]  rd;
                logic [19:0]  PC;
                logic [31:0] reg_data [31:0];
                logic [19:0] pc;
		logic branch_valid;

                logic        z_rst;
                logic        z_instruction_read_enable_o;
               
               
                logic [19:0] instr_read_addr_o; 
                logic [31:0] z_instruction_o;
                logic 	     exception_valid_o;		    
                logic [7:0]  exception_id_o;			    
                logic	     interrupt_valid_o;		    
                logic	     exception_id_write_valid_o;	
                logic        interrupt_id_write_valid_o;	
                logic 		 ld_sd_misalign_valid_o;  	
                logic [31:0] ld_sd_misalign_addr_o;		
                logic 		 instr_misalign_valid_o;  	
                logic [19:0] instr_misalign_addr_o;		
                logic 	     invalid_instr_valid_o;		
                logic        decode_instruction_valid_o;  
                logic        trap_valid_o; 
                logic 		 z_instruction_valid_i;
                logic 		 stall_valid_i;
                logic 	 	 branch_valid_i;
               // logic [19:0] instr_read_addr_o; 
                //logic 	     z_instruction_read_enable_o;
                logic        read_write_ptr_valid;
                logic [19:0] pc_r ;
                logic [19:0] next_pc_r;



//dut signals - begin 
     logic [19:0] dut_pc;
//dut signal - end

        //clocking block for instruction mem
        
                        clocking im_cb  @ (posedge risc_clk);
                        default input #0 output #0;
                    
                    // all input signals to TOP_TB are inputs in CB and vise versa
                        output          z_im_read_data_i;
                    
                    //outputs
                        input           z_im_write_en_o              ;		
                        input           z_instruction_addr_o         ;	
                        input           z_im_write_data_o            ;	    
                        input           z_im_write_data_strobe_o     ;
                        input           z_im_read_en_o               ;
                   


                        endclocking
                    
                        modport im_mp (clocking im_cb);
                    
       //clocking block for data memory

    clocking dm_cb @ (posedge risc_clk);
    default input #0 output #0;

    output      data_mem_read_data_i;

    input       data_mem_write_en_o;
    input       data_mem_write_data_o;
    input       data_mem_write_addr_o;
    input       data_mem_strobe_o;
    input       data_mem_read_en_o;  
    input       data_mem_read_addr_o;

    endclocking

    modport dm_mp (clocking dm_cb);

endinterface 
