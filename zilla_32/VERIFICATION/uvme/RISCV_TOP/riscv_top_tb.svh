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
* File Name : riscv_top.sv

* Purpose : top tb

* Creation Date : 30-03-2023

* Last Modified : Fri 05 May 2023 05:11:50 PM IST

* Created By :  sharon
*/

parameter DWIDTH = 32;

`timescale 1ns/1ps
class random_value;
    rand bit [31:0] gpr_value;
    constraint c1{ gpr_value % 4 == 0;
                   gpr_value inside {[294912:557055]};
                   gpr_value dist {[294912:295680]:=30,[295680:556755]:=40,[556755:557055]:=30};
                   //294912 < gpr_value < 557055;
                   }
endclass


module riscv_top_tb;

    import riscv_package::*;
    import uvm_pkg::*;

    `include "uvm_macros.svh"

     string testname;

//registers for clock
    bit TCK;
    bit risc_clk = 0;

//input clock generation 100MHZ
        always #5 risc_clk = ~risc_clk;    


//DM interface
    riscv_intf intf_dm (intf_i.risc_clk);




//interface instance
     riscv_intf intf_i( risc_clk,
                        TCK
                        );

    write_back_interface wb_intf(risc_clk);
    ldst_out_intf intf_ls(intf_i.risc_clk);

 //Decode interface
    decode_intf intf_dcd (intf_i.risc_clk);
       

// config db connection for agent (for test)
    initial begin
            
            uvm_config_db#(virtual riscv_intf)::set(uvm_root::get(),"*", "riscv_intf", intf_i);
            uvm_config_db#(virtual decode_intf)::set(uvm_root::get(),"*", "decode_intf",intf_dcd);
            uvm_config_db#(virtual write_back_interface)::set(uvm_root::get(),"*", "write_back_interface", wb_intf);
	        uvm_config_db#(virtual ldst_out_intf)::set(uvm_root::get(),"*", "ldst_out_intf", intf_ls); //Load store interface 
            run_test(" ");
            //#100 $finish;

    
    
    end

initial
begin
    if (!$value$plusargs("UVM_TESTNAME=%s", testname)) begin
      $display("Default UVM test name not found.");
    end else begin
      $display("Default UVM test name: %s", testname);
    end
 end

//wave dump
        initial begin
        //$monitor("\n========>\nPc Value : in tb top: %5h\n<========\n",intf_i.dut_pc);
        $shm_open("wave.shm");
        $shm_probe("ACTMF");
        end

// RTL instance
        
    riscv_top DUT (
                                    
                                    .risc_clk                   (intf_i.risc_clk                        ),
                                    .TCK                        (intf_i.TCK                             ),
                                    .risc_rst                   (intf_i.risc_rst                        ),
                                    .ext_int0_i	                (1'b0                                   ),
                                    .ext_int1_i	                (1'b0                                   ),
                                    .ext_int2_i	                (1'b0                                   ),
                                    .ext_int3_i	                (1'b0                                   ),
                                    .ext_int4_i	                (1'b0                                   ),
                                    .ext_int5_i                 (1'b0                                   ),
                                    .ext_int6_i	                (1'b0                                   ),
                                    .ext_int7_i	                (1'b0                                   ),
                                    .ext_int8_i	                (1'b0                                   ),
                                    .ext_int9_i	                (1'b0                                   ),
                                    .ext_int10_i	            (1'b0                                   ),
                                    .ext_int11_i	            (1'b0                                   ),
                                    .ext_int12_i	            (1'b0                                   ),
                                    .ext_int13_i	            (1'b0                                   ),
                                    .ext_int14_i	            (1'b0                                   ),
                                    .ext_int15_i	            (1'b0                                   ),
                                    .ext_int16_i	            (1'b0                                   ),
                                    .ext_int17_i	            (1'b0                                   ),
                                    .ext_int18_i	            (1'b0                                   ),
                                    .ext_int19_i	            (1'b0                                   ),
                                    .ext_int20_i	            (1'b0                                   ),
                                    .ext_int21_i	            (1'b0                                   ),
                                    .ext_int22_i	            (1'b0                                   ),
                                    .ext_int23_i	            (1'b0                                   ),
                                    .ext_int24_i	            (1'b0                                   ),
                                    .ext_int25_i	            (1'b0                                   ),
                                    .ext_int26_i	            (1'b0                                   ),
                                    .ext_int27_i	            (1'b0                                   ),
                                    .ext_int28_i	            (1'b0                                   ),
                                    .ext_int29_i	            (1'b0                                   ),
                                    .ext_int30_i	            (1'b0                                   ),
                                    .ext_int31_i	            (1'b0                                   ),
                                    .ext_int32_i	            (1'b0                                   ),
                                    .ext_int33_i	            (1'b0                                   ),
                                    .ext_int34_i	            (1'b0                                   ),
                                    .ext_int35_i	            (1'b0                                   ),
                                    .ext_int36_i	            (1'b0                                   ),
                                    .ext_int37_i	            (1'b0                                   ),
                                    .ext_int38_i	            (1'b0                                   ),
                                    .ext_int39_i	            (1'b0                                   ),
                                    .ext_int40_i	            (1'b0                                   ),
                                    .ext_int41_i	            (1'b0                                   ),
                                    .ext_int42_i	            (1'b0                                   ),
                                    .ext_int43_i	            (1'b0                                   ),
                                    .ext_int44_i	            (1'b0                                   ),
                                    .ext_int45_i	            (1'b0                                   ),
                                    .ext_int46_i	            (1'b0                                   ),
                                    .TRST                       (intf_i.TRST                            ),
                                    .TMS                        (intf_i.TMS                             ),
                                    .TDI                        (intf_i.TDI                             ),
                                    .ilmb_ce                    (1'b1                                   ),
                                    .ilmb_ready                 (1'b1                                   ),
                                    .ilmb_rst                   (1'b1                                   ),
                                    .ilmb_ue                    (1'b1                                   ),
                                    .ilmb_wait                  (1'b1                                   ),
                                    .carry		                (intf_i.carry		                    ),
                                    .zero		                (intf_i.zero		                    ),
                                    .ret_func_valid             (intf_i.ret_func_valid                  ),
                                    .TDO                        (intf_i.TDO                             ),
                                    .tdo_en                     (intf_i.tdo_en                          ),
                                    .reset_uart_o               (intf_i.reset_uart_o                    ),
                                    .data_mem_read_data_i       (intf_i.data_mem_read_data_i            ),
                                    .data_mem_write_en_o        (intf_i.data_mem_write_en_o             ),
                                    .data_mem_write_data_o      (intf_i.data_mem_write_data_o           ),
                                    .data_mem_write_addr_o      (intf_i.data_mem_write_addr_o           ),
                                    .data_mem_strobe_o          (intf_i.data_mem_strobe_o               ),
                                    .data_mem_read_en_o         (intf_i.data_mem_read_en_o              ),
                                    .data_mem_read_addr_o       (intf_i.data_mem_read_addr_o            ),
                                    .z_im_read_data_i           (intf_i.z_im_read_data_i                ),
                                    .z_im_write_en_o            (intf_i.z_im_write_en_o                 ),
                                    .z_instruction_addr_o       (intf_i.z_instruction_addr_o            ),
                                    .z_im_write_data_o          (intf_i.z_im_write_data_o               ),
                                    .z_im_write_data_strobe_o   (intf_i.z_im_write_data_strobe_o        ),
                                    .z_im_read_en_o             (intf_i.z_im_read_en_o                  ),
                                    .im_addr_strobe             (intf_i.im_addr_strobe                  )
                                                                        
                                                                        );


    assign intf_i.dut_pc = DUT.pc;
/////--------------------------------------loading gpr value into an array-------------------------------///////
   
       
   always @(posedge risc_clk)
        begin
            foreach(intf_ls.reg_data[i])
                begin
                    intf_ls.reg_data[i] = DUT.reg_file_inst.dp_ram_inst.regfile[i];
                    //`uvm_info("INSIDE TOP",$sformatf("The value is %0h", intf_ls.reg_data[i]),UVM_NONE);
                end
        end

///------------------------------------Execution stage Input-----------------------------------------------//

  assign intf_ls.PC              =  DUT.zpc_top_inst.zilla_pc_update_inst.instr_read_addr_o[19:0]; 
 
  assign intf_i.PC                = DUT.instruction_memory_inst.z_im_read_addr_o;
  assign intf_i.branch_valid      = DUT.zpc_top_inst.zilla_pc_update_inst.branch_valid_i;

  //assign intf_ls.reg_wr_en       =  DUT.reg_file_inst.dp_ram_inst.wr_en;
  //assign intf_ls.reg_wr_addr     =  DUT.reg_file_inst.dp_ram_inst.wr_addr[4:0]; 
  //assign intf_ls.reg_wr_data     =  DUT.reg_file_inst.dp_ram_inst.datain[31:0]; 
  assign intf_ls.stall_en        =  DUT.load_hazard_ctrl_inst.stall_en; 
  assign intf_ls.stall_pipeline  =  DUT.load_hazard_ctrl_inst.stall_pipeline;
  assign intf_ls.base_addr       =  DUT.addr_gen_rs1_data[31:0];


  assign intf_ls.de_ld_sd_addr_o =  DUT.addr_gen_inst.de_ld_sd_addr_o;
  assign intf_ls.z_instruction_o      =  DUT.zpc_top_inst.z_instruction_o;
  assign intf_ls.load_valid_out   = DUT.addr_gen_inst.ld_valid_o;
  assign intf_ls.store_valid_out  = DUT.addr_gen_inst.sd_valid_o;
  assign intf_ls.reg_wr_en        = DUT.reg_wr_en;
  assign intf_ls.reg_wr_data      = DUT.reg_file_inst.wr_data[31:0];
  assign intf_ls.sign_bit         = DUT.addr_gen_inst.sign_bit;
  assign intf_ls.byte_sel_o       = DUT.addr_gen_inst.byte_sel_o[1:0];
  assign intf_ls.data_mem_write_en_to_stall = DUT.read_modify_write_inst.data_mem_write_en_to_stall;
  assign intf_ls.alu_ctrl         = DUT.addr_gen_inst.alu_ctrl[11:0];
  assign intf_ls.reg_wr_addr      = DUT.reg_file_inst.dp_ram_inst.wr_addr[4:0];
  assign intf_ls.forward_a        = DUT.forward_a[1:0];
  assign intf_ls.byte_en          = DUT.addr_gen_inst.byte_en[3:0];
//--------------------------Other stages------------------------------------//
  assign intf_i.pc               = DUT.instruction_memory_inst.z_im_read_addr_o;
  assign intf_i.instruction      =  DUT.instr_decode.instruction;
  assign intf_i.opcode           =  DUT.instr_decode.opcode;
  assign intf_i.func3            =  DUT.instr_decode.func3;
  assign intf_i.func7            =  DUT.instr_decode.func7;
  assign intf_i.imm              =  DUT.instr_decode.imm_r;
  assign intf_i.rs1              =  DUT.instr_decode.rs1;
  assign intf_i.rs2              =  DUT.instr_decode.rs2;
  assign intf_i.rd               =  DUT.instr_decode.rd;
  assign intf_i.reg_data[0]          =  DUT.reg_file_inst.dp_ram_inst.regfile[0] ;
  assign intf_i.reg_data[1]          =  DUT.reg_file_inst.dp_ram_inst.regfile[1] ;
  assign intf_i.reg_data[2]          =  DUT.reg_file_inst.dp_ram_inst.regfile[2] ;
  assign intf_i.reg_data[3]          =  DUT.reg_file_inst.dp_ram_inst.regfile[3] ;
  assign intf_i.reg_data[4]          =  DUT.reg_file_inst.dp_ram_inst.regfile[4] ;
  assign intf_i.reg_data[5]          =  DUT.reg_file_inst.dp_ram_inst.regfile[5] ;
  assign intf_i.reg_data[6]          =  DUT.reg_file_inst.dp_ram_inst.regfile[6] ;
  assign intf_i.reg_data[7]          =  DUT.reg_file_inst.dp_ram_inst.regfile[7] ;
  assign intf_i.reg_data[8]          =  DUT.reg_file_inst.dp_ram_inst.regfile[8] ;
  assign intf_i.reg_data[9]          =  DUT.reg_file_inst.dp_ram_inst.regfile[9] ;
  assign intf_i.reg_data[10]         =  DUT.reg_file_inst.dp_ram_inst.regfile[10];
  assign intf_i.reg_data[11]         =  DUT.reg_file_inst.dp_ram_inst.regfile[11];
  assign intf_i.reg_data[12]         =  DUT.reg_file_inst.dp_ram_inst.regfile[12];
  assign intf_i.reg_data[13]         =  DUT.reg_file_inst.dp_ram_inst.regfile[13];
  assign intf_i.reg_data[14]         =  DUT.reg_file_inst.dp_ram_inst.regfile[14];
  assign intf_i.reg_data[15]         =  DUT.reg_file_inst.dp_ram_inst.regfile[15];
  assign intf_i.reg_data[16]         =  DUT.reg_file_inst.dp_ram_inst.regfile[16];
  assign intf_i.reg_data[17]         =  DUT.reg_file_inst.dp_ram_inst.regfile[17];
  assign intf_i.reg_data[18]         =  DUT.reg_file_inst.dp_ram_inst.regfile[18];
  assign intf_i.reg_data[19]         =  DUT.reg_file_inst.dp_ram_inst.regfile[19];
  assign intf_i.reg_data[20]         =  DUT.reg_file_inst.dp_ram_inst.regfile[20];
  assign intf_i.reg_data[21]         =  DUT.reg_file_inst.dp_ram_inst.regfile[21];
  assign intf_i.reg_data[22]         =  DUT.reg_file_inst.dp_ram_inst.regfile[22];
  assign intf_i.reg_data[23]         =  DUT.reg_file_inst.dp_ram_inst.regfile[23];
  assign intf_i.reg_data[24]         =  DUT.reg_file_inst.dp_ram_inst.regfile[24];
  assign intf_i.reg_data[25]         =  DUT.reg_file_inst.dp_ram_inst.regfile[25];
  assign intf_i.reg_data[26]         =  DUT.reg_file_inst.dp_ram_inst.regfile[26];
  assign intf_i.reg_data[27]         =  DUT.reg_file_inst.dp_ram_inst.regfile[27];
  assign intf_i.reg_data[28]         =  DUT.reg_file_inst.dp_ram_inst.regfile[28];
  assign intf_i.reg_data[29]         =  DUT.reg_file_inst.dp_ram_inst.regfile[29];
  assign intf_i.reg_data[30]         =  DUT.reg_file_inst.dp_ram_inst.regfile[30];
  assign intf_i.reg_data[31]         =  DUT.reg_file_inst.dp_ram_inst.regfile[31];

  assign intf_i.z_rst            = DUT.zpc_top_inst.zilla_pc_update_inst.z_rst;
  assign intf_i.z_instruction_read_enable_o = DUT.zpc_top_inst.zilla_pc_update_inst.z_instruction_read_enable_o;
   assign intf_i.instr_read_addr_o            =  DUT.zpc_top_inst.instr_read_addr_o; 
   assign intf_i.z_instruction_o              =  DUT.zpc_top_inst.z_instruction_o;
   assign intf_i.exception_valid_o            =  DUT.zpc_top_inst.exception_valid_o	;
   assign intf_i.exception_id_o               =  DUT.zpc_top_inst.exception_id_o	;
   assign intf_i.interrupt_valid_o            =  DUT.zpc_top_inst.interrupt_valid_o;
   assign intf_i.exception_id_write_valid_o   =  DUT.zpc_top_inst.exception_id_write_valid_o;
   assign intf_i.interrupt_id_write_valid_o   =  DUT.zpc_top_inst.interrupt_id_write_valid_o;
   assign intf_i.ld_sd_misalign_valid_o       =  DUT.zpc_top_inst.ld_sd_misalign_valid_o;
   assign intf_i.ld_sd_misalign_addr_o        =  DUT.zpc_top_inst.ld_sd_misalign_addr_o;
   assign intf_i.instr_misalign_valid_o       =  DUT.zpc_top_inst.instr_misalign_valid_o;
   assign intf_i.instr_misalign_addr_o        =  DUT.zpc_top_inst.instr_misalign_addr_o;
   assign intf_i.invalid_instr_valid_o        =  DUT.zpc_top_inst.invalid_instr_valid_o;
   assign intf_i.decode_instruction_valid_o   =  DUT.zpc_top_inst.decode_instruction_valid_o;
   assign intf_i.trap_valid_o                 =  DUT.zpc_top_inst.trap_valid_o;
   assign intf_i.z_instruction_valid_i        =  DUT.zpc_top_inst.zilla_instruction_buffer_inst.z_instruction_valid_i;
   assign intf_i.stall_valid_i                =  DUT.zpc_top_inst.zilla_instruction_buffer_inst.stall_valid_i;
   assign intf_i.branch_valid_i               =  DUT.zpc_top_inst.zilla_instruction_buffer_inst.branch_valid_i;
   //assign intf_i.instr_read_addr_o            =  DUT.zpc_top_inst.zilla_pc_update_inst.instr_read_addr_o;
  // assign intf_i.z_instruction_read_enable_o               =  DUT.z_instruction_read_enable_o;
   assign intf_i.read_write_ptr_valid         =  DUT.zpc_top_inst.zilla_pc_update_inst.read_write_ptr_valid;
   assign intf_i.pc_r                         =  DUT.zpc_top_inst.zilla_pc_update_inst.pc_r;
   assign intf_i.next_pc_r                    =  DUT.zpc_top_inst.zilla_pc_update_inst.next_pc_r; 





  assign wb_intf.out               =  DUT.mem_reg_mux.out;
  assign intf_dcd.func7            =  DUT.instr_decode.func7;
  assign intf_dcd.instruction      =  DUT.instr_decode.instruction_r;
  assign intf_dcd.opcode           =  DUT.instr_decode.opcode;
  assign intf_dcd.func3            =  DUT.instr_decode.func3;
  assign intf_dcd.imm              =  DUT.instr_decode.imm_r;
  assign intf_dcd.rs1              =  DUT.instr_decode.rs1;
  assign intf_dcd.rs2              =  DUT.instr_decode.rs2;
  assign intf_dcd.rd               =  DUT.instr_decode.rd;
  assign intf_dcd.valid            =  DUT.instr_decode.decode_instruction_valid_i;


assign wb_intf.forward_a             =  DUT.fwd_inst.forward_a;
assign wb_intf.forward_b             =  DUT.fwd_inst.forward_b;
assign wb_intf.alu_out             =  DUT.fwd_inst.alu_out;



// alu inst - write back stage
assign wb_intf.data_in_1 = DUT.alu_inst.data_in_1                             ;
assign wb_intf.data_in_2 = DUT.alu_inst.data_in_2                             ; 
assign wb_intf.data_out  = DUT.alu_inst.data_out                              ;            
//R and I type enable signals for writeback stage           
assign wb_intf.sub_en    = DUT.alu_inst.sub_en                                ;
assign wb_intf.add_en    = DUT.alu_inst.add_en                                ;
assign wb_intf.sll_en    = DUT.alu_inst.sll_en                                ;
assign wb_intf.slt_en    = DUT.alu_inst.slt_en                                ;
assign wb_intf.xor_en    = DUT.alu_inst.xor_en                                ;
assign wb_intf.srl_en    = DUT.alu_inst.srl_en                                ;
assign wb_intf.sra_en    = DUT.alu_inst.sra_en                                ;
assign wb_intf.or_en     = DUT.alu_inst.or_en                                 ;
assign wb_intf.and_en    = DUT.alu_inst.and_en                                ;
//I type - writeback stage                                  
assign wb_intf.jalr_en   = DUT.alu_inst.jalr_en                               ;
// uj type enable signal for writeback                      
assign wb_intf.jal_en    = DUT.alu_inst.jal_en                                ;
// u type enable signal for writeback                      
assign wb_intf.lui_en    = DUT.alu_inst.lui_en                                ;
//gpr - regfileinst - write_en for writeback stage          
assign wb_intf.wr_data_en = DUT.reg_file_inst.wr_data_en                      ;
                                                            
assign wb_intf.in1      = DUT.mem_reg_mux.in1                                ;
assign wb_intf.in2      = DUT.mem_reg_mux.in2                                ;
assign wb_intf.sel      = DUT.mem_reg_mux.sel                                ;
                                                            

  assign intf_dcd.reg_wr_en_r                 =  DUT.instr_decode.reg_wr_en_r;
  assign intf_dcd.mem_rd_en_r                 =  DUT.instr_decode.mem_rd_en_r;
  assign intf_dcd.mem_wr_en_r	              =  DUT.instr_decode.mem_wr_en_r;
  assign intf_dcd.reg_wr_en_r1                =  DUT.instr_decode.reg_wr_en_r1;
  assign intf_dcd.alu_ctrl_r	              =  DUT.instr_decode.alu_ctrl_r;
  assign intf_dcd.mem_to_reg_en_r	          =  DUT.instr_decode.mem_to_reg_en_r;
  assign intf_dcd.invalid_instruction_valid_o =  DUT.instr_decode.invalid_instruction_valid_o	;
 


initial
//always@(negedge risc_clk)
begin
                    random_value obj1;
                obj1 = new();
                obj1.randomize();
    for (int i =0 ; i< 32; i++)
        begin
            if(i == 0)
            DUT.reg_file_inst.dp_ram_inst.regfile[i] = 'h0;

            else
                begin
                if(testname=="riscv_r_type_arith" || testname== "riscv_r_type_shift" || testname=="riscv_i_type_arith" || testname=="riscv_i_type_shift")
                    begin
                        DUT.reg_file_inst.dp_ram_inst.regfile[i] = {2{$urandom}};     // For R - Type Test
                    end
                else if(testname=="riscv_i_type_jalr" || testname== "riscv_u_type" || testname=="riscv_uj_type" )
                    begin
                        DUT.reg_file_inst.dp_ram_inst.regfile[i] = 'h8100;         // For Branch and Jump Tests
                    end
                else
                                DUT.reg_file_inst.dp_ram_inst.regfile[i] = obj1.gpr_value;   
                    //   DUT.reg_file_inst.dp_ram_inst.regfile[i] = 'h48120;        // For Load and Store Tests
                    // DUT.reg_file_inst.dp_ram_inst.regfile[i] = 'h8100;         // For Branch and Jump Tests
                end

               // $display("reg data[%0d]=%0h",i,DUT.reg_file_inst.dp_ram_inst.regfile[i]);
         end



end





endmodule
