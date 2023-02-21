/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
* File Name : inst_gensequencer.sv

* Purpose : sequencer for riscv 

* Creation Date : 23-03-2023

* Last Modified : Fri 05 May 2023 11:53:27 AM IST

* Created By :  Sharon
*/


class im_sequencer extends uvm_sequencer #(im_seq_item);

//factory registration

    `uvm_component_utils(im_sequencer)

//Constructor

    function new( string name = "im_sequencer" , uvm_component parent);
        super.new(name, parent);
        `uvm_info(get_name(),$sformatf("=====>>>>>step 1 : inside IM_sequencer"),UVM_MEDIUM)
    endfunction

endclass
