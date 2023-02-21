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
* File Name : inst_gendriver.sv

* Purpose : Drive sequencer op to DUT

* Creation Date : 30-03-2023

* Last Modified : Fri 05 May 2023 02:30:57 PM IST

* Created By :  Sharon
*/


class im_driver extends uvm_driver #(im_seq_item);

//Local variable to make control from TEST
    int drv_repeat_count = 1;

//varible for file handling operations
    int file_handle;


//Factory registration
    `uvm_component_utils(im_driver)

//Sequence_item instantiation  
    im_seq_item sq_im;

//Constructor

    function new( string name = "im_driver", uvm_component parent);
        super.new(name, parent);
    endfunction


//Run phase

    task pre_reset_phase (uvm_phase phase);

        phase.raise_objection(this);


        `uvm_info("=====>>>>> Step4:", "Inside im_driver pre_reset Phase_ Start", UVM_MEDIUM)
        
        file_handle = $fopen("$tb_dir/uvme/RISCV_TOP/inst.hex", "w");

        $display("file_handle = %0d", file_handle);

//to write generated instructions to .hex file
                        repeat(drv_repeat_count)
                        begin
                        
//handshaking between driver and sequencer
                            seq_item_port.get_next_item(sq_im);

//instruction sare writing into inst.hex file
                            $fdisplay(file_handle, $sformatf("%8h", sq_im.sample));
                        
                        
                        
                        
                            seq_item_port.item_done(sq_im);
                        end
        $fclose(file_handle);

        `uvm_info("=====>>>>> Step5:", "Inside driver pre_reset Phase- Done", UVM_MEDIUM)
            
      phase.drop_objection(this);
      

    endtask

endclass

      
