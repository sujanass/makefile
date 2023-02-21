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
* File Name : spc_coverage.sv

* Purpose : Coverage for special counter

* Creation Date : 31-03-2023

* Last Modified : Tue 04 Apr 2023 03:27:15 PM IST

* Created By :  Sharon
*/

class spc_coverage extends uvm_subscriber #(spc_seq_item);

//Factory registration
    `uvm_component_utils(spc_coverage)

//seq_item instantiationv_i.
    spc_seq_item sq_i;


//covergroup
    covergroup spc_covergroup;

//Coverpoint for reset
    RESET               :   coverpoint sq_i.reset
                            {
                                bins bin_value_0   = {0};
                                bins bin_value_1   = {1};
                            }
    

//Coverpoint for updown
    UPDOWN              :   coverpoint sq_i.updown
                            {
                                bins bin_value_0   = {0};
                                bins bin_value_1   = {1};
                            }

//Coverpoint for count_start_enable
    COUNT_START_ENABLE  :   coverpoint sq_i.count_start_enable
                            {
                                bins bin_value_0   = {0};
                                bins bin_value_1   = {1};
                            }

//Coverpoint for count_start
    COUNT_START         :   coverpoint sq_i.count_start
                            {
                                option.auto_bin_max = 3;
                            }
    
//Coverpoint for destination count
    DESTINATION_COUNT   :   coverpoint sq_i.destination_count
                            {
                                option.auto_bin_max = 3;
                            }

//Coverpoint for reset_overflow
    RESET_OVERFLOW      :   coverpoint sq_i.reset_overflow
                            {
                                bins bin_value_0   = {0};
                                bins bin_value_1   = {1};
                            }

//Coverpoint for count
    COUNT               :   coverpoint sq_i.count
                            {
                                option.auto_bin_max = 5;
                            }

//Coverpoint for overflow
    OVERFLOW            :   coverpoint sq_i.overflow
                            {
                                bins bin_value_0   = {0};
                                bins bin_value_1   = {1};
                            }
//Coverpoint for reset
    INTERRUPT           :   coverpoint sq_i.interrupt
                            {
                                bins bin_value_0   = {0};
                                bins bin_value_1   = {1};
                            }
    endgroup

//constructor new
        function new(string name ="spc_coverage", uvm_component parent);
            super.new(name, parent);
            spc_covergroup = new();
        endfunction



        function void write(input spc_seq_item t);
            sq_i = new();
            $cast(sq_i, t);

            spc_covergroup.sample();
        endfunction

endclass
