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
* File Name : riscv_sequence.sv

* Purpose : sequencer for special counter

* Creation Date : 30-03-2023

* Last Modified : Fri 05 May 2023 12:26:24 PM IST

* Created By :  sharon
*/


class riscv_sequence extends uvm_sequence; // # (im_seq_item, riscv_seq_item);

// factory registration

    `uvm_object_utils(riscv_sequence)

//parametrized class riscv_seq_item handle creation

     riscv_seq_item         sq_i;
     im_seq_item            sq_im;

//Local variable declaration to make the tb controllable from class test
//initializing value is important
    bit [2:0]           test_scenario;
    bit                 seq_risc_rst;
    int                 seq_repeat_count;
     
    
    bit                 mode;
    int                 inst_count;

    int                 sb_lower;
    int                 sb_upper;


    logic [1:0] seq_mode;

// Constructor

    function new (string name = "riscv_sequence");
        super.new(name);
    endfunction


    INSTRUCTION_TYPE inst_type;



// task body    

    virtual task  body;
    set_response_queue_depth(200000);
    `uvm_info(get_name(),$sformatf("=====>>>>>step 3 :Inside Sequence"), UVM_MEDIUM)

//seq_item instantiation
        sq_i    = riscv_seq_item::type_id::create("sq_i");
        sq_im   = im_seq_item::type_id::create("sq_im");


        case (mode)
            0  :   begin
                        `uvm_info(get_name(),$sformatf("<<<<>>>>INSTRUCTION GENERATION<<<<SEQUENCE>>>>"), UVM_MEDIUM)
                        repeat(inst_count)
                            begin
                                
                                
                            sq_im = im_seq_item::type_id::create("sq_im");                    //create the req (seq item)
                            wait_for_grant();                                                //wait for grant
                            sq_im.modes         = inst_type;
                            assert(sq_im.randomize() with { sq_im.instruction   == inst_type;
                                                            sq_im.lower_limit   == sb_lower;
                                                            sq_im.upper_limit   == sb_upper;
                                                                                            
                                                                                            });  //randomize the req                    
                            send_request(sq_im);                                            //send req to driver
                            wait_for_item_done();                                           //wait for item done from driver
                            get_response(rsp);                                              //get response from driver
                            
                            //$display("inside sequence=%8h",sq_im.sample);
                          
                            end

                    end



            1   :   begin
                        case (test_scenario)

//Scenarion 0 : Reset Test
                            3'b000: begin

                                    `uvm_info(get_name(),$sformatf("<<<<>>>>RESET TEST<<<<SEQUENCE>>>>"), UVM_MEDIUM)
                                    repeat(seq_repeat_count)
                                        begin
                                            `uvm_do_with(sq_i, {risc_rst            == seq_risc_rst;})
                                        end
                                    end
    
                        endcase // case (test_scenario)

                    end
        endcase //end case mode

    endtask

endclass

