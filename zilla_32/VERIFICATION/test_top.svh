/***********************************************************
File name   : test_top.svh
Description : top file 
***********************************************************/

`timescale 1ns/1ps
`define SYS_CLK_PRD 10          //  100 MHz, unit: nano second

`ifdef WAVE_EN
    `define WAVE_DUMP_EN 1
`else
    `define WAVE_DUMP_EN 0
`endif

module test_top;

  //  UVM package
  import uvm_pkg::*;
  `include "uvm_macros.svh"
//  `include "../jtag_vip_driver/jtag_if.svh"
    

  import riscv_pkg::*;          // enviroment import
  import riscv_test_pkg::*;     // test import
//  import jtag_tb_pkg::*;        // JTAG test import

  // clock generation
  logic riscv_clk = 1;
  always #(`SYS_CLK_PRD/2)  riscv_clk = ~riscv_clk;

  //jtag clock generation 
  logic tck = 1'b0;
  always #((`SYS_CLK_PRD * 10 ) / 2) tck = ~tck ; 
 
  //  interface instance
  riscv_interface riscv_intf(riscv_clk);
//  cov_interface cov_intf(riscv_clk);
//  jtag_if jtag_intf(tck);


   // JTAG interface configuration
   initial
     begin
//       uvm_config_db#(jtag_vif)::set(null,"uvm_test_top","jtag_virtual_if",jtag_intf);  
//       uvm_config_db#(jtag_if_proxy)::set(null,"uvm_test_top","jtag_if_proxy",jtag_intf.proxy);       
     end


  //  DUT instance
  riscv_top DUT (
                 .risc_clk              (riscv_intf.riscv_clk   ),
                 .risc_rst              (riscv_intf.riscv_rst   ),
                 .data_mem_write_en_o     (riscv_intf.mem_wr_en   ),
                 .data_mem_strobe_o       (riscv_intf.mem_byte_en ),
                 .data_mem_write_addr_o   (riscv_intf.mem_wr_addr ),
                 .data_mem_write_data_o   (riscv_intf.mem_wr_data ),
                 .data_mem_read_en_o      (riscv_intf.mem_rd_en   ),
                 .data_mem_read_addr_o    (riscv_intf.mem_rd_addr ),
                 .data_mem_read_data_i    (riscv_intf.mem_rd_data ),
                 .carry                 (riscv_intf.carry       ),
                 .zero                  (riscv_intf.zero        ),
                 .z_im_write_en_o		  (riscv_intf.inst_mem_wr_en), 
                 .z_instruction_addr_o	  (riscv_intf.inst_mem_addr),  
                 .z_im_write_data_o	      (riscv_intf.inst_mem_wr_data),    
                 .z_im_read_en_o		  (riscv_intf.inst_mem_rd_en),   
                 .z_im_read_data_i        (riscv_intf.inst_mem_rd_data),   
                 .z_im_write_data_strobe_o (riscv_intf.inst_mem_strobe), 
                 .ilmb_ce		          (1'b1),    
                 .ilmb_ready	          (1'b1), 
                 .ilmb_rst		          (1'b1), 
                 .ilmb_ue		          (1'b1), 
                 .ilmb_wait	              (1'b1),     

              `ifdef JTAG_VIP
                 .TCK            		(jtag_intf.tck          ), 
                 .TRST           		(jtag_intf.trst         ), 
                 .TMS          			(jtag_intf.tms          ), 
                 .TDI            		(jtag_intf.tdi          ), 
                 .TDO            		(jtag_intf.tdo          )      
              `else
                 .TCK            		(riscv_intf.jtag_TCK    ), 
                 .TRST           		(riscv_intf.riscv_rst  ), 
                 .TMS          			(riscv_intf.jtag_TMS    ), 
                 .TDI            		(riscv_intf.jtag_TDI    ), 
                 .TDO            		(riscv_intf.jtag_TDO    ) 
              `endif  
	        );


 `ifdef OPEN_OCD
     logic [31:0] sim_jtag_exit ;
     parameter int unsigned OPENOCD_PORT = 9999;
     
     SimJTAG #(
            .TICK_DELAY (1),
            .PORT(OPENOCD_PORT)
        ) i_sim_jtag (
            .clock                (riscv_intf.riscv_clk      ),
            .reset                ( ~riscv_intf.riscv_rst    ),
            .enable               ( 1'b1                     ),
            .init_done            ( riscv_intf.riscv_rst     ),
            .jtag_TCK             ( riscv_intf.jtag_TCK      ),
            .jtag_TMS             ( riscv_intf.jtag_TMS      ),
            .jtag_TDI             ( riscv_intf.jtag_TDI      ),
            .jtag_TRSTn           ( riscv_intf.jtag_TRSTn    ),
            .jtag_TDO_data        ( riscv_intf.jtag_TDO      ),
            .jtag_TDO_driven      ( 1'b1                     ),
            .exit                 ( sim_jtag_exit            )
         );
        
    always_comb begin : jtag_exit_handler
            if (sim_jtag_exit)
                $finish(2); // print stats too
    end
`endif
assign riscv_intf.alu_en = {
test_top.DUT.alu_inst.add_inst.en
,test_top.DUT.alu_inst.and_inst.en
,test_top.DUT.alu_inst.auipc_inst.en
,test_top.DUT.alu_inst.cmp_eq_inst.en
,test_top.DUT.alu_inst.cmp_gt_inst.en
,test_top.DUT.alu_inst.cmp_gte_inst.en
,test_top.DUT.alu_inst.cmp_gteu_inst.en
,test_top.DUT.alu_inst.cmp_gtu_inst.en
,test_top.DUT.alu_inst.cmp_lt_inst.en
,test_top.DUT.alu_inst.cmp_lte_inst.en
,test_top.DUT.alu_inst.cmp_lteu_inst.en
,test_top.DUT.alu_inst.cmp_ltu_inst.en
,test_top.DUT.alu_inst.cmp_ne_inst.en
,test_top.DUT.alu_inst.div_inst.en
,test_top.DUT.alu_inst.jal_inst.en
,test_top.DUT.alu_inst.jalr_inst.en
,test_top.DUT.alu_inst.lui_inst.en
,test_top.DUT.alu_inst.mult_inst.en
,test_top.DUT.alu_inst.mvi_inst.en
,test_top.DUT.alu_inst.or_inst.en
,test_top.DUT.alu_inst.rem_inst.en
,test_top.DUT.alu_inst.rotate_left_inst.en
,test_top.DUT.alu_inst.rotate_right_inst.en
,test_top.DUT.alu_inst.sll_inst.en
,test_top.DUT.alu_inst.slt_inst.en
,test_top.DUT.alu_inst.sra_inst.en
/*`ifdef ZILLA_64_BIT
,test_top.DUT.alu_inst.sraw_inst.en
`endif*/
,test_top.DUT.alu_inst.srl_inst.en
,test_top.DUT.alu_inst.sub_inst.en
,test_top.DUT.alu_inst.xor_inst.en};
   
   
  //For print mailbox:   // Env and FPGA-[LMB] create two 
  assign riscv_intf.mem_wr_en_1    =  DUT.data_mem_inst.data_mem_write_en;
  assign riscv_intf.mem_wr_addr_1  =  DUT.data_mem_inst.data_mem_write_addr[31:0];
  assign riscv_intf.mem_wr_data_1  =  DUT.data_mem_inst.data_mem_write_data[31:0];   
   
   //  DUT internal signals connection
  assign riscv_intf.OUT_instruction =  DUT.zpc_top_inst.z_instruction_o;        //  out instruction at instruction memory
  assign riscv_intf.decode_valid    =  DUT.zpc_top_inst.decode_instruction_valid_o;
  assign riscv_intf.inst_rd         =  DUT.zpc_top_inst.zilla_pc_update_inst.z_instruction_read_enable_w;
  assign riscv_intf.mul_en          =  DUT.alu_inst.mult_inst.en;
  assign riscv_intf.div_en          =  DUT.alu_inst.div_inst.en;
  assign riscv_intf.div_busy        =  DUT.alu_inst.div_inst.div_busy_o;
  assign riscv_intf.rem_en          =  DUT.alu_inst.rem_inst.en;
  assign riscv_intf.rem_busy        =  DUT.alu_inst.rem_inst.rem_busy_o;
  assign riscv_intf.inst_read_en    =  DUT.zpc_top_inst.z_instruction_read_enable_o; //
  assign riscv_intf.PC              =  DUT.zpc_top_inst.zilla_pc_update_inst.instr_read_addr_o[19:0];                     //  pc at instruction memory
  assign riscv_intf.alu_out         =  DUT.alu_inst.data_out;                                     //  alu output at 
  assign riscv_intf.stall_pipeline  =  DUT.load_hazard_ctrl_inst.stall_pipeline;           //  stall pipeline at load hazard control
  assign riscv_intf.stall_en        =  DUT.load_hazard_ctrl_inst.stall_en;           //  stall pipeline at load hazard control
  assign riscv_intf.reg_wr_en       =  DUT.reg_file_inst.dp_ram_inst.wr_en;                       //  register_file write enable
  assign riscv_intf.reg_wr_data     =  DUT.reg_file_inst.dp_ram_inst.datain[63:0];                          //  register_file write data
  assign riscv_intf.reg_wr_addr     =  DUT.reg_file_inst.dp_ram_inst.wr_addr[4:0];                               //  register_file write address

  assign riscv_intf.csr_addr         =  DUT.csr_top_inst.csr_addr_in;
  assign riscv_intf.csr_read_data    =  DUT.csr_top_inst.csr_read_data_o   ;
  assign riscv_intf.csr_write_data   =  DUT.csr_top_inst.csr_write_data_in   ;
  assign riscv_intf.csr_write_en     =  DUT.csr_top_inst.csr_write_en_in   ;
  assign riscv_intf.csr_set_en       =  DUT.csr_top_inst.csr_set_bit_in   ;
  assign riscv_intf.csr_clear_en     =  DUT.csr_top_inst.csr_clear_bit_in  ;
  assign riscv_intf.csr_read_en      =  DUT.csr_top_inst.csr_read_en_in  ;

 //Interrupt & Exception Handling
  assign riscv_intf.mret_valid_i      =  DUT.zpc_top_inst.mret_valid_i;                               
  assign riscv_intf.zic_mmr_eoi_id_o  =  DUT.zpc_top_inst.zic_mmr_eoi_id_o;                               
  assign riscv_intf.csr_mstatus_mie_i =  DUT.zpc_top_inst.csr_mstatus_mie_i   ; 
  assign riscv_intf.interrupt_valid   =  DUT.zpc_top_inst.interrupt_valid_o ;
  assign riscv_intf.mie_set           =  DUT.csr_top_inst.mie_set; 
  assign riscv_intf.mie_clear         =  DUT.csr_top_inst.mie_clear; 
  assign riscv_intf.zic_mmr_ack_id    =  DUT.zpc_top_inst.zic_mmr_ack_id_i; 
  assign riscv_intf.exception_valid   =  DUT.zpc_top_inst.exception_valid_o ;
  assign riscv_intf.exception_code    =  DUT.zpc_top_inst.exception_id_o ;
  assign riscv_intf.exception_id      =  DUT.zpc_top_inst.exception_id_o ;   
  assign riscv_intf.ld_sd_misalign_valid =  DUT.zpc_top_inst.ld_sd_misalign_valid_o ; 
  assign riscv_intf.ld_sd_misalign_addr  =  DUT.zpc_top_inst.ld_sd_misalign_addr_o ; 
  assign riscv_intf.instr_misalign_valid =  DUT.zpc_top_inst.instr_misalign_valid_o ; 
  assign riscv_intf.instr_misalign_addr  =  DUT.zpc_top_inst.instr_misalign_addr_o ; 
  assign riscv_intf.invalid_instr_valid  =  DUT.zpc_top_inst.invalid_instr_valid_o ; 
  assign riscv_intf.csr_mepc             =  DUT.zpc_top_inst.csr_mepc_i ; 
  assign riscv_intf.csr_mepc_write_valid =  DUT.zpc_top_inst.csr_mepc_write_valid_o ; 
  assign riscv_intf.interrupt_active_level_priority =  DUT.csr_top_inst.interrupt_active_level_priority_o ; 
  // assign riscv_intf. [19:0]csr_mepc_o; 
  assign riscv_intf.csr_mtvec            =  DUT.csr_top_inst.csr_mtvec_o ; 
  assign riscv_intf.csr_mcause           =  DUT.csr_top_inst.csr_mcause_o ; 
  
  //ZIC specific signals.
  assign riscv_intf.zic_mmr_write_en         = DUT.zilla_interrupt_control_inst.zic_mmr_write_en_i;  	        
  assign riscv_intf.zic_mmr_write_addr       = DUT.zilla_interrupt_control_inst.zic_mmr_write_addr_i;	      
  assign riscv_intf.zic_mmr_write_data       = DUT.zilla_interrupt_control_inst.zic_mmr_write_data_i;	     
  assign riscv_intf.zic_mmr_read_en          = DUT.zilla_interrupt_control_inst.zic_mmr_read_en_i;		       
  assign riscv_intf.zic_mmr_read_addr 	     = DUT.zilla_interrupt_control_inst.zic_mmr_read_addr_i; 	        
  assign riscv_intf.zic_ack_read_valid_en    = DUT.zilla_interrupt_control_inst.zic_ack_read_valid_en;	       
  assign riscv_intf.zic_eoi_valid            = DUT.zilla_interrupt_control_inst.zic_eoi_valid_i; 		                    
  assign riscv_intf.global_int_enable_bit    = DUT.zilla_interrupt_control_inst.global_int_enable_bit_i;            
  assign riscv_intf.global_int_enable_valid  = DUT.zilla_interrupt_control_inst.global_int_enable_valid_i;   
  assign riscv_intf.zic_mmr_read_data        = DUT.zilla_interrupt_control_inst.zic_mmr_read_data_o;
  assign riscv_intf.highest_pending_lvl_pr   = DUT.zilla_interrupt_control_inst.highest_pending_lvl_pr_o;


   // Functional coverage env connections
`ifdef GLS_SIM
  assign cov_intf.data_out          = DUT.alu_inst.data_out;
  assign cov_intf.carry_o           = DUT.alu_inst.carry_o;
  assign cov_intf.zero_o            = DUT.alu_inst.zero_o;
  assign cov_intf.riscv_rst         = riscv_intf.riscv_rst; 

  assign cov_intf.add_en            = DUT.alu_inst.add_en;
  assign cov_intf.sub_en            = DUT.alu_inst.sub_en;
  assign cov_intf.sll_en            = DUT.alu_inst.sll_en;
  assign cov_intf.slt_en            = DUT.alu_inst.slt_en;

  assign cov_intf.instruction =  DUT.instruction_memory_inst.instruction_o;        //  out instruction at instruction memory


  assign cov_intf.alu_imm_val        = DUT.addr_gen_inst.imm_val;
  assign cov_intf.alu_rs1_val        = DUT.addr_gen_inst.rs1_data;

  assign cov_intf.addr               = DUT.addr_gen_inst.addr;
  assign cov_intf.byte_en            = DUT.addr_gen_inst.byte_en;
 
  assign cov_intf.branch_pc          = DUT.branch_condition_check_inst.branch_pc;

  assign cov_intf.id_ex_rd           = DUT.load_hazard_ctrl_inst.id_ex_rd;
  assign cov_intf.forward_a      = DUT.forwarding_inst.forward_a;
  assign cov_intf.forward_b     = DUT.forwarding_inst.forward_b;

//debug Functional coverage Conneciton
  assign cov_intf.dmcontrol_reg     = DUT.dtm_to_dm_inst.apb_slave_dmreg_top_instnc.dm_register_file_instnc.dmcontrol_reg[31:0];
  assign cov_intf.dmstatus_reg      = DUT.dtm_to_dm_inst.apb_slave_dmreg_top_instnc.dm_register_file_instnc.dmstatus_reg[31:0] ;
  assign cov_intf.abstractcs_reg    = DUT.dtm_to_dm_inst.apb_slave_dmreg_top_instnc.dm_register_file_instnc.abstractcs_reg[31:0];
  assign cov_intf.command_reg       = DUT.dtm_to_dm_inst.apb_slave_dmreg_top_instnc.dm_register_file_instnc.command_reg[31:0];
  assign cov_intf.data0_reg         = DUT.dtm_to_dm_inst.apb_slave_dmreg_top_instnc.dm_register_file_instnc.data0_reg[31:0] ;
  assign cov_intf.data1_reg         = DUT.dtm_to_dm_inst.apb_slave_dmreg_top_instnc.dm_register_file_instnc.data1_reg[31:0];
  assign cov_intf.data2_reg         = DUT.dtm_to_dm_inst.apb_slave_dmreg_top_instnc.dm_register_file_instnc.data2_reg[31:0];
  assign cov_intf.data3_reg         = DUT.dtm_to_dm_inst.apb_slave_dmreg_top_instnc.dm_register_file_instnc.data3_reg[31:0];
  assign cov_intf.exception         = DUT.dtm_to_dm_inst.exception ;
  assign cov_intf.ebreak            = DUT.dtm_to_dm_inst.ebreak ;
  assign cov_intf.step              = DUT.dtm_to_dm_inst.step ;

 //IRQ GENERATION SIGANLS IN ASSEMBLY DELCARATION

  assign riscv_intf.opcode = DUT.alu_inst.opcode_r;
  assign riscv_intf.op1   = DUT.alu_inst.oper1;
  assign riscv_intf.op2   = DUT.alu_inst.oper2;

  assign riscv_intf.func3 = DUT.instr_decode.func3;
  assign riscv_intf.func7 = DUT.instr_decode.func7;

  assign riscv_intf.in1   = DUT.branch_condition_check_inst.beq_inst.in1[63:0];
  assign riscv_intf.in2   = DUT.branch_condition_check_inst.beq_inst.in2[63:0];

`endif
  
  // IRQ 

  assign DUT.ext_int0_i  =  riscv_intf.ext_int0_i;
  assign DUT.ext_int1_i  =  riscv_intf.ext_int1_i;
  assign DUT.ext_int2_i  =  riscv_intf.ext_int2_i;
  assign DUT.ext_int3_i  =  riscv_intf.ext_int3_i;
  assign DUT.ext_int4_i  =  riscv_intf.ext_int4_i;
  assign DUT.ext_int5_i  =  riscv_intf.ext_int5_i;
  assign DUT.ext_int6_i  =  riscv_intf.ext_int6_i;
  assign DUT.ext_int7_i  =  riscv_intf.ext_int7_i;
  assign DUT.ext_int8_i  =  riscv_intf.ext_int8_i;
  assign DUT.ext_int9_i  =  riscv_intf.ext_int9_i;
  assign DUT.ext_int10_i  = riscv_intf.ext_int10_i;
  assign DUT.ext_int11_i  = riscv_intf.ext_int11_i;
  assign DUT.ext_int12_i  = riscv_intf.ext_int12_i;
  assign DUT.ext_int13_i  = riscv_intf.ext_int13_i;
  assign DUT.ext_int14_i  = riscv_intf.ext_int14_i;
  assign DUT.ext_int15_i  = riscv_intf.ext_int15_i;
  assign DUT.ext_int16_i  = riscv_intf.ext_int16_i;
  assign DUT.ext_int17_i  = riscv_intf.ext_int17_i;
  assign DUT.ext_int18_i  = riscv_intf.ext_int18_i;
  assign DUT.ext_int19_i  = riscv_intf.ext_int19_i;
  assign DUT.ext_int20_i  = riscv_intf.ext_int20_i;
  assign DUT.ext_int21_i  = riscv_intf.ext_int21_i;
  assign DUT.ext_int22_i  = riscv_intf.ext_int22_i;
  assign DUT.ext_int23_i  = riscv_intf.ext_int23_i;
  assign DUT.ext_int24_i  = riscv_intf.ext_int24_i;
  assign DUT.ext_int25_i  = riscv_intf.ext_int25_i;
  assign DUT.ext_int26_i  = riscv_intf.ext_int26_i;
  assign DUT.ext_int27_i  = riscv_intf.ext_int27_i;
  assign DUT.ext_int28_i  = riscv_intf.ext_int28_i;
  assign DUT.ext_int29_i  = riscv_intf.ext_int29_i;
  assign DUT.ext_int30_i  = riscv_intf.ext_int30_i;
  assign DUT.ext_int31_i  = riscv_intf.ext_int31_i;
  assign DUT.ext_int32_i  = riscv_intf.ext_int32_i;
  assign DUT.ext_int33_i  = riscv_intf.ext_int33_i;
  assign DUT.ext_int34_i  = riscv_intf.ext_int34_i;
  assign DUT.ext_int35_i  = riscv_intf.ext_int35_i;
  assign DUT.ext_int36_i  = riscv_intf.ext_int36_i;
  assign DUT.ext_int37_i  = riscv_intf.ext_int37_i;
  assign DUT.ext_int38_i  = riscv_intf.ext_int38_i;
  assign DUT.ext_int39_i  = riscv_intf.ext_int39_i;
  assign DUT.ext_int40_i  = riscv_intf.ext_int40_i;
  assign DUT.ext_int41_i  = riscv_intf.ext_int41_i;
  assign DUT.ext_int42_i  = riscv_intf.ext_int42_i;
  assign DUT.ext_int43_i  = riscv_intf.ext_int43_i;
  assign DUT.ext_int44_i  = riscv_intf.ext_int44_i;
  assign DUT.ext_int45_i  = riscv_intf.ext_int45_i;
  assign DUT.ext_int46_i  = riscv_intf.ext_int46_i;


    initial
        begin
          riscv_intf.ext_int0_i = 0;  
          riscv_intf.ext_int1_i = 0;
          riscv_intf.ext_int2_i = 0;
          riscv_intf.ext_int3_i = 0;
          riscv_intf.ext_int4_i = 0;
          riscv_intf.ext_int5_i = 0;
          riscv_intf.ext_int6_i = 0;
          riscv_intf.ext_int7_i = 0;
          riscv_intf.ext_int8_i = 0;
          riscv_intf.ext_int9_i = 0;
          riscv_intf.ext_int10_i = 0;
          riscv_intf.ext_int11_i = 0;
          riscv_intf.ext_int12_i = 0;
          riscv_intf.ext_int13_i = 0;
          riscv_intf.ext_int14_i = 0;
          riscv_intf.ext_int15_i = 0;
          riscv_intf.ext_int16_i = 0;
          riscv_intf.ext_int17_i = 0;
          riscv_intf.ext_int18_i = 0;
          riscv_intf.ext_int19_i = 0;
          riscv_intf.ext_int20_i = 0;
          riscv_intf.ext_int21_i = 0;
          riscv_intf.ext_int22_i = 0;
          riscv_intf.ext_int23_i = 0;
          riscv_intf.ext_int24_i = 0;
          riscv_intf.ext_int25_i = 0;
          riscv_intf.ext_int26_i = 0;
          riscv_intf.ext_int27_i = 0;
          riscv_intf.ext_int28_i = 0;
          riscv_intf.ext_int29_i = 0;
          riscv_intf.ext_int30_i = 0;
          riscv_intf.ext_int31_i = 0;
          riscv_intf.ext_int32_i = 0;
          riscv_intf.ext_int33_i = 0;
          riscv_intf.ext_int34_i = 0;
          riscv_intf.ext_int35_i = 0;
          riscv_intf.ext_int36_i = 0;
          riscv_intf.ext_int37_i = 0;
          riscv_intf.ext_int38_i = 0;
          riscv_intf.ext_int39_i = 0;
          riscv_intf.ext_int40_i = 0;
          riscv_intf.ext_int41_i = 0;
          riscv_intf.ext_int42_i = 0;
          riscv_intf.ext_int43_i = 0;
          riscv_intf.ext_int44_i = 0;
          riscv_intf.ext_int45_i = 0;
          riscv_intf.ext_int46_i = 0;
        end
  //assign riscv_int46f.zic_int_req_i = DUT.zpc_top_inst.zic_int_req_i;
 
  //  backdoor register_file write ----------------------------------------
 
`ifndef GLS_SIM
 initial
  begin
    force_reg_mem();
    @(negedge riscv_intf.riscv_rst);  
    @(posedge riscv_intf.riscv_clk);  
    release_reg_mem();
  end

  task force_reg_mem();
    force DUT.reg_file_inst.dp_ram_inst.regfile =  riscv_intf.regfile;
  //Dheeru  force DUT.instruction_memory_inst.instr_mem_inst.INST_MEM =  riscv_intf.instr_mem;
  endtask : force_reg_mem
  
  task release_reg_mem();
    release DUT.reg_file_inst.dp_ram_inst.regfile;
   // release DUT.instruction_memory_inst.instr_mem_inst.INST_MEM;
  endtask : release_reg_mem
  //------------------------------------------------------------------------
`endif
  //  run_test
  initial
  begin
    
    if(`WAVE_DUMP_EN)
    begin
      $shm_open("wave.shm");    //  wave dump
      $shm_probe("ACTMF");  
    end
    uvm_config_db#(virtual riscv_interface)::set(null,"*","riscv_intf",riscv_intf);       //  place interface into database
 //   uvm_config_db#(virtual cov_interface)::set(null,"*","cov_intf",cov_intf);       //  place interface into database
    run_test();                //  start_test
  end
  /*initial begin
    #50000; 
    `uvm_info("Test_top.svh",$sformatf("Exited at Time: %0t\n====================>>>>Execution Time out<<<<<============================",$time),UVM_MEDIUM)
     #1;   
    $finish;
  end
  */
endmodule : test_top

 
