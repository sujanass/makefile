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
* File Name : riscv_test1_reset.sv

* Purpose : Base test 

* Creation Date : 30-03-2023

* Last Modified : Fri 05 May 2023 12:27:13 PM IST

* Created By :  Sharon
*/

 class riscv_base_test extends uvm_test;

//factory registration
    `uvm_component_utils(riscv_base_test)

//class riscv_env instantiation
    riscv_env           env_i;

//Class riscv_sequence instantiation
    riscv_sequence      seq_i;
agent_dm dm_agent;

//Constructor

    function new(string name = "riscv_base_test", uvm_component parent);
        super.new(name, parent);

   endfunction

//Build phase
    function void build_phase(uvm_phase phase);
        super.build_phase(phase);

        env_i = riscv_env::type_id::create("env_i", this);
        seq_i = riscv_sequence::type_id::create("seq_i",this);
uvm_config_db#(agent_dm)::set(null,"uvm_test_top.env_i","DM_AGENT",dm_agent);
    endfunction



endclass


