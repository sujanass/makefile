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
* File Name     :

* Purpose       : 

* Creation Date : 

* Last Modified : Fri 05 May 2023 06:51:07 PM IST

* Created By :  Sharon
*/


///////////////riscv_sb_type.svh//////////////////////////
// For conditional JUMP                                 //
// GPR load : Random value                              //
//          : max value 0x48000                         //
// JUMP     : control jump by using min & max value     //
//          : seq_i.sb_lower & seq_i.sb_upper           //
//          : 12 bits for jump                          //
//          : 0-2047 for forward jump (11 bits)         //
//          : 2048 - 4096 for backward (2s compliment)  //
//          : for certain jump provide min and max as   //
//            known multiple of 2                       //
//          : IMM = JUMP * 2                            //
//////////////////////////////////////////////////////////


class riscv_sb_type extends riscv_base_test;

//factory registration

    `uvm_component_utils(riscv_sb_type)

//event declaration
        event pre_reset;

//Constructor

    function new(string name = "riscv_sb_type", uvm_component parent);
        super.new(name, parent);

   endfunction

//pre_reset_phase
    task pre_reset_phase (uvm_phase phase);
        
//raise objection for all other phases        
        phase.raise_objection(this, "objection pre_reset");

            `uvm_info(get_type_name(),$sformatf(" TIME:%0t INSTRUCTION GENERATION STARTS : SB_TYPE",$time), UVM_MEDIUM)
            
//passing values to riscv_sequence            
            seq_i.mode                              = 0;
            seq_i.inst_type                         = SB_TYPE;
            seq_i.sb_lower                          = 2;
            seq_i.sb_upper                          = 4095;
            seq_i.inst_count                        = 65471;
            env_i.agent_im.drv_im.drv_repeat_count  = 65471;
            seq_i.start(env_i.agent_im.seqr_im);
            
            `uvm_info(get_type_name(),$sformatf(" TIME:%0t INSTRUCTION GENERATION DONE",$time), UVM_MEDIUM)


        phase.drop_objection(this, "dropped pre_objection");

//event 
       -> pre_reset;
    
    endtask


//Run phase
    task run_phase(uvm_phase phase);

//wait for event    
    @ (pre_reset)


//raising objection for all phases
        phase.raise_objection(this, "obj run phase");
        
            
            `uvm_info(get_type_name(),$sformatf("=====>>>>>step2: Inside test"), UVM_MEDIUM)

//R_TYPE instruction test
                seq_i.mode                              = 1;
                seq_i.test_scenario                     = 0;
                seq_i.seq_risc_rst                      = 1;
                seq_i.seq_repeat_count                  = 1;
                env_i.agent_i.drv_i.drv_repeat_count    = 100000;
                seq_i.start(env_i.agent_i.seqr_i);

            
            `uvm_info(get_type_name(),$sformatf("=====>>>>>step6: Inside test Done"), UVM_MEDIUM)

//dropping the objection
        phase.drop_objection(this, "drop run");

//seting time to finish test
        uvm_test_done.set_drain_time(this, 1000000);
    
    endtask

endclass


