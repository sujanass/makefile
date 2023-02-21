`timescale 1ns/1ps
//`include "define_lib.svh"


interface decode_intf(  input logic                    risc_clk
                        );


         logic [31:0] instruction;
         logic [6:0]  opcode;
         logic [2:0]  func3;
         logic [6:0]  func7;
         logic [31:0] imm;
         logic [4:0]  rs1;
         logic [4:0]  rs2;
         logic [4:0]  rd;
         logic        valid;
         logic        reg_wr_en_r;			    
         logic        mem_rd_en_r;			        
         logic        mem_wr_en_r;	
         logic   	  reg_wr_en_r1;	
         logic [11:0] alu_ctrl_r;
         logic 	      mem_to_reg_en_r; 
         logic   	  invalid_instruction_valid_o;	

 endinterface         

