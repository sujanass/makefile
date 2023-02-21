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
* File Name : riscv_agent.sv

* Purpose : Agent for special counter

* Creation Date : 30-03-2023

* Last Modified : Fri 05 May 2023 12:24:11 PM IST

* Created By :  Sharon

*/


class riscv_agent extends uvm_agent;

//Factory registration
    `uvm_component_utils(riscv_agent)

//riscv_sequencer instantiation
    riscv_sequencer seqr_i;

//riscv_driver instantiation
    riscv_driver drv_i;

//riscv_monitor instantiation
    //riscv_monitor mon_i;

//Constructor
    function new(string name ="riscv_agent" , uvm_component parent);
        super.new(name, parent);
    endfunction

//Build phase
    function void build_phase(uvm_phase phase);
        super.build_phase(phase);

        seqr_i  = riscv_sequencer::type_id::create("seqr_i" , this);
        drv_i   = riscv_driver::type_id::create("drv_i", this);
        //mon_i   = riscv_monitor::type_id::create("mon_i", this);
    endfunction

//Connect phase
    function void connect_phase( uvm_phase phase);
        super.connect_phase(phase);

        drv_i.seq_item_port.connect(seqr_i.seq_item_export);

    endfunction

endclass
