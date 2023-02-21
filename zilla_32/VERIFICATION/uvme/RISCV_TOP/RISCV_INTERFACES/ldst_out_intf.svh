`timescale 1ns/1ps

interface ldst_out_intf(input logic risc_clk);
    logic               z_im_read_en_o;
    logic [31-1:0]   z_im_read_data_i;
    logic [19:0] PC;
    logic [31:0] reg_data[31:0];//array to load an gpr 
     logic        [31:0]          z_instruction_o             ;
 logic        [31:0]          de_ld_sd_addr_o             ;
    logic load_valid_out;
    logic store_valid_out;
    logic reg_wr_en;
    logic [4:0] reg_wr_addr;
    logic [31:0] reg_wr_data;
    logic stall_en;
    logic stall_pipeline;
    logic [31:0] base_addr;


    logic sign_bit;
    logic [1:0] byte_sel_o;
    logic data_mem_write_en_to_stall;
    logic [11:0] alu_ctrl;
    logic [1:0] forward_a;
    logic [3:0] byte_en;


    //Data memory signals
   /* logic                       data_mem_read_en_o    ;  
    logic [WIDTH-1:0]           data_mem_read_data_i  ;
    logic [WIDTH-1:0]           data_mem_read_addr_o  ;   
    logic                       data_mem_write_en_o   ;
    logic [WIDTH-1:0]           data_mem_write_data_o ;
    logic [WIDTH-1:0]           data_mem_write_addr_o ;
    logic [(WIDTH>>3)-1:0]      data_mem_strobe_o     ;*/
endinterface 
