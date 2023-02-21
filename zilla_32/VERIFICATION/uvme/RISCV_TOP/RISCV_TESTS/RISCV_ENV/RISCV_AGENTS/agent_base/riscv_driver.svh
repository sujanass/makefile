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
* File Name : riscv_driver.sv

* Purpose : Drive sequencer op to DUT

* Creation Date : 30-03-2023

* Last Modified : Fri 05 May 2023 02:30:57 PM IST

* Created By :  Sharon
*/


class riscv_driver extends uvm_driver #(riscv_seq_item);

//Local variable to make control from TEST
    int drv_repeat_count = 1;

//Factory registration
    `uvm_component_utils(riscv_driver)

//Virtual interface instantiation
    virtual riscv_intf vif;

//Sequence_item instantiation  
    riscv_seq_item sq_i;

//Constructor

    function new( string name = "riscv_driver", uvm_component parent);
        super.new(name, parent);
    endfunction

//Build phase

    function void build_phase (uvm_phase phase);
        super.build_phase(phase);

//If virtual interface not connected via config db, drop the entire process

        if (!uvm_config_db#( virtual riscv_intf)::get(this, "*", "riscv_intf", vif))
            `uvm_fatal(get_full_name(),{"Virtual Interface must be set for:",".riscv_intf"});

    endfunction

int i;


//Run phase

    task run_phase (uvm_phase phase);
        super.run_phase(phase);

// Reset logic
                vif.risc_rst                <= 0;
                vif.ext_int0_i	            <= 0;
                vif.ext_int1_i	            <= 0;
                vif.ext_int2_i	            <= 0;
                vif.ext_int3_i	            <= 0;
                vif.ext_int4_i	            <= 0;
                vif.ext_int5_i              <= 0;
                vif.ext_int6_i	            <= 0;
                vif.ext_int7_i	            <= 0;
                vif.ext_int8_i	            <= 0;
                vif.ext_int9_i	            <= 0;
                vif.ext_int10_i	            <= 0;
                vif.ext_int11_i	            <= 0;
                vif.ext_int12_i	            <= 0;
                vif.ext_int13_i	            <= 0;
                vif.ext_int14_i	            <= 0;
                vif.ext_int15_i	            <= 0;
                vif.ext_int16_i	            <= 0;
                vif.ext_int17_i	            <= 0;
                vif.ext_int18_i	            <= 0;
                vif.ext_int19_i	            <= 0;
                vif.ext_int20_i	            <= 0;
                vif.ext_int21_i	            <= 0;
                vif.ext_int22_i	            <= 0;
                vif.ext_int23_i	            <= 0;
                vif.ext_int24_i	            <= 0;
                vif.ext_int25_i	            <= 0;
                vif.ext_int26_i	            <= 0;
                vif.ext_int27_i	            <= 0;
                vif.ext_int28_i	            <= 0;
                vif.ext_int29_i	            <= 0;
                vif.ext_int30_i	            <= 0;
                vif.ext_int31_i	            <= 0;
                vif.ext_int32_i	            <= 0;
                vif.ext_int33_i	            <= 0;
                vif.ext_int34_i	            <= 0;
                vif.ext_int35_i	            <= 0;
                vif.ext_int36_i	            <= 0;
                vif.ext_int37_i	            <= 0;
                vif.ext_int38_i	            <= 0;
                vif.ext_int39_i	            <= 0;
                vif.ext_int40_i	            <= 0;
                vif.ext_int41_i	            <= 0;
                vif.ext_int42_i	            <= 0;
                vif.ext_int43_i	            <= 0;
                vif.ext_int44_i	            <= 0;
                vif.ext_int45_i	            <= 0;
                vif.ext_int46_i	            <= 0;
                vif.TRST                    <= 0;
                vif.TMS                     <= 0;
                vif.TDI                     <= 0;

                repeat(3) @ (negedge vif.risc_clk);
                //vif.risc_rst                <= 1;
                //repeat(100) @ (negedge vif.risc_clk);

        forever begin

//handshaking between driver and sequencer

        seq_item_port.get_next_item(sq_i);
        `uvm_info("=====>>>>> Step4:", "Inside driver Run Phase_ Start", UVM_MEDIUM)
       // sq_i.print;


//Assigning all inputs
                        repeat(drv_repeat_count) @ (negedge vif.risc_clk) 
                        begin
                        vif.risc_rst            <= sq_i.risc_rst            ; 
                        vif.ext_int0_i	        <= sq_i.ext_int0_i	        ; 
                        vif.ext_int1_i	        <= sq_i.ext_int1_i	        ; 
                        vif.ext_int2_i	        <= sq_i.ext_int2_i	        ; 
                        vif.ext_int3_i	        <= sq_i.ext_int3_i	        ; 
                        vif.ext_int4_i	        <= sq_i.ext_int4_i	        ; 
                        vif.ext_int5_i          <= sq_i.ext_int5_i          ; 
                        vif.ext_int6_i	        <= sq_i.ext_int6_i	        ; 
                        vif.ext_int7_i	        <= sq_i.ext_int7_i	        ; 
                        vif.ext_int8_i	        <= sq_i.ext_int8_i	        ; 
                        vif.ext_int9_i	        <= sq_i.ext_int9_i	        ; 
                        vif.ext_int10_i	        <= sq_i.ext_int10_i	        ; 
                        vif.ext_int11_i	        <= sq_i.ext_int11_i	        ; 
                        vif.ext_int12_i	        <= sq_i.ext_int12_i	        ; 
                        vif.ext_int13_i	        <= sq_i.ext_int13_i	        ; 
                        vif.ext_int14_i	        <= sq_i.ext_int14_i	        ; 
                        vif.ext_int15_i	        <= sq_i.ext_int15_i	        ; 
                        vif.ext_int16_i	        <= sq_i.ext_int16_i	        ; 
                        vif.ext_int17_i	        <= sq_i.ext_int17_i	        ; 
                        vif.ext_int18_i	        <= sq_i.ext_int18_i	        ; 
                        vif.ext_int19_i	        <= sq_i.ext_int19_i	        ; 
                        vif.ext_int20_i	        <= sq_i.ext_int20_i	        ; 
                        vif.ext_int21_i	        <= sq_i.ext_int21_i	        ; 
                        vif.ext_int22_i	        <= sq_i.ext_int22_i	        ; 
                        vif.ext_int23_i	        <= sq_i.ext_int23_i	        ; 
                        vif.ext_int24_i	        <= sq_i.ext_int24_i	        ; 
                        vif.ext_int25_i	        <= sq_i.ext_int25_i	        ; 
                        vif.ext_int26_i	        <= sq_i.ext_int26_i	        ; 
                        vif.ext_int27_i	        <= sq_i.ext_int27_i	        ; 
                        vif.ext_int28_i	        <= sq_i.ext_int28_i	        ; 
                        vif.ext_int29_i	        <= sq_i.ext_int29_i	        ; 
                        vif.ext_int30_i	        <= sq_i.ext_int30_i	        ; 
                        vif.ext_int31_i	        <= sq_i.ext_int31_i	        ; 
                        vif.ext_int32_i	        <= sq_i.ext_int32_i	        ; 
                        vif.ext_int33_i	        <= sq_i.ext_int33_i	        ; 
                        vif.ext_int34_i	        <= sq_i.ext_int34_i	        ; 
                        vif.ext_int35_i	        <= sq_i.ext_int35_i	        ; 
                        vif.ext_int36_i	        <= sq_i.ext_int36_i	        ; 
                        vif.ext_int37_i	        <= sq_i.ext_int37_i	        ; 
                        vif.ext_int38_i	        <= sq_i.ext_int38_i	        ; 
                        vif.ext_int39_i	        <= sq_i.ext_int39_i	        ; 
                        vif.ext_int40_i	        <= sq_i.ext_int40_i	        ; 
                        vif.ext_int41_i	        <= sq_i.ext_int41_i	        ; 
                        vif.ext_int42_i	        <= sq_i.ext_int42_i	        ; 
                        vif.ext_int43_i	        <= sq_i.ext_int43_i	        ; 
                        vif.ext_int44_i	        <= sq_i.ext_int44_i	        ; 
                        vif.ext_int45_i	        <= sq_i.ext_int45_i	        ; 
                        vif.ext_int46_i	        <= sq_i.ext_int46_i	        ; 
                        vif.TRST                <= sq_i.TRST                ; 
                        vif.TMS                 <= sq_i.TMS                 ; 
                        vif.TDI                 <= sq_i.TDI                 ;

                        end

        `uvm_info("=====>>>>> Step5:", "Inside driver Run Phase- Done", UVM_MEDIUM)
            
        seq_item_port.item_done(sq_i);
            
        end

    endtask

endclass

      
