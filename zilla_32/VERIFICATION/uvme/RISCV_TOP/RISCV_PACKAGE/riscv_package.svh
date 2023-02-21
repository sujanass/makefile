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
* File Name : riscv_package.svh

* Purpose : package for riscv

* Creation Date : 17-03-2023

* Last Modified : Thu 04 May 2023 01:13:17 PM IST

* Created By :  sharon
*/

package riscv_package;

    import uvm_pkg::*;

    `include "uvm_macros.svh"

    //Agent_debug
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_debug/agent_debug.svh"

    //Agent_interrupt
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_interrupt/agent_interrupt.svh"

    //Agents_dm
     `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_dm/agent_dm.svh"
 
    //Agents_im

    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_im/im_seq_item.svh"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_im/im_sequencer.svh"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_im/im_driver.svh"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_im/im_agent.svh"
    
    //Agent_decode_out
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_decode_out/decode_seq_item.svh"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_decode_out/decode_mon.sv"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_decode_out/agent_decode_out.svh"

    //Agent_PC
     `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_pc/pc_seq_item.svh"
     `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_pc/monitor_pc.svh"
     `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_pc/agent_pc.svh"
     `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_COVERAGE/pc_coverage.sv"
    


     //Agent_ldst_out
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_ldst_out/riscv_seq_item_ldst.svh"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_ldst_out/ldst_out_monitor.svh"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_ldst_out/agent_ldst_out.svh"

    //Agent_write_out
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_write_back_out/seq_item_wb_out.svh"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_write_back_out/monitor_write_back_out.svh"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_write_back_out/agent_write_back_out.svh"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_SCOREBOARD/scoreboard_wb_out.svh"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_COVERAGE/riscv_wb_coverage.sv"

    //agent_base

    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_base/riscv_seq_item.svh"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_base/riscv_sequencer.svh"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_base/riscv_driver.svh"
    //`include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_base/riscv_monitor.svh"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_AGENTS/agent_base/riscv_agent.svh"

   //ldst Coverage 
     `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_COVERAGE/ldst_coverage.svh"
 //Decode Coverage
   `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_COVERAGE/decode_coverage.svh"
  

   //instr gen Coverage

   `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_COVERAGE/instr_gen_coverage.svh"

   //Environment

    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_SCOREBOARD/ldst_out_sb.svh"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/RISCV_SCOREBOARD/decode_scoreboard.svh"
    `include "RISCV_TOP/RISCV_TESTS/RISCV_ENV/riscv_env.svh"
    
    
   //sequences 

    `include "RISCV_TOP/RISCV_TESTS/RISCV_SEQUENCES/riscv_sequence.svh"

    //test

    `include "RISCV_TOP/RISCV_TESTS/riscv_base_test.svh"
    `include "RISCV_TOP/RISCV_TESTS/riscv_r_type_arith.svh"
    `include "RISCV_TOP/RISCV_TESTS/riscv_r_type_shift.svh"
    `include "RISCV_TOP/RISCV_TESTS/riscv_i_type_arith.svh"
    `include "RISCV_TOP/RISCV_TESTS/riscv_i_type_shift.svh"
    `include "RISCV_TOP/RISCV_TESTS/riscv_i_type_load.svh"
    `include "RISCV_TOP/RISCV_TESTS/riscv_i_type_jalr.svh"
    `include "RISCV_TOP/RISCV_TESTS/riscv_s_type.svh"
    `include "RISCV_TOP/RISCV_TESTS/riscv_sb_type.svh"
    `include "RISCV_TOP/RISCV_TESTS/riscv_u_type.svh"
    `include "RISCV_TOP/RISCV_TESTS/riscv_uj_type.svh"


    //load and store test
    `include "RISCV_TOP/RISCV_TESTS/ld_lower_imm_sign_test.svh"
    `include "RISCV_TOP/RISCV_TESTS/ld_lower_imm_uns_test.svh"
    `include "RISCV_TOP/RISCV_TESTS/ld_random_imm_sign_test.svh"
    `include "RISCV_TOP/RISCV_TESTS/ld_random_imm_uns_test.svh"
    `include "RISCV_TOP/RISCV_TESTS/ld_upper_imm_sign_test.svh"
    `include "RISCV_TOP/RISCV_TESTS/ld_upper_imm_uns_test.svh"
    `include "RISCV_TOP/RISCV_TESTS/st_lower_imm_sign_test.svh"
    `include "RISCV_TOP/RISCV_TESTS/st_lower_imm_uns_test.svh"
    `include "RISCV_TOP/RISCV_TESTS/st_random_imm_sign_test.svh"
    `include "RISCV_TOP/RISCV_TESTS/st_random_imm_uns_test.svh"
    `include "RISCV_TOP/RISCV_TESTS/st_upper_imm_sign_test.svh"
    `include "RISCV_TOP/RISCV_TESTS/st_upper_imm_uns_test.svh"
    `include "RISCV_TOP/RISCV_TESTS/riscv_load_store.svh"
    `include "RISCV_TOP/RISCV_TESTS/ld_mailbox.svh"
    `include "RISCV_TOP/RISCV_TESTS/sd_mailbox.svh"
   
endpackage
    


