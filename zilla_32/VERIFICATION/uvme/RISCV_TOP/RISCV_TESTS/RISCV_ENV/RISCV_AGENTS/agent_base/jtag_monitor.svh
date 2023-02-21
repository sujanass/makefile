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
* File Name : jtag_monitor.sv

* Purpose :Monitor for Special counter

* Creation Date : 31-03-2023

* Last Modified : Tue 02 May 2023 01:57:03 PM IST

* Created By :  Sharon
*/

class jtag_monitor extends uvm_monitor;


//Factory registration
    `uvm_component_utils(jtag_monitor)

//Virtual interface
    virtual jtag_intf vif;

//seq_item instantiation
    jtag_seq_item sq_i;

//Analysis port instantiation
    uvm_analysis_port #(jtag_seq_item) mon_ap;

//Constructor
    function new(string name ="jtag_monitor", uvm_component parent);
        super.new(name, parent);
    endfunction

//Build phase
    function void build_phase(uvm_phase phase);
        super.build_phase(phase);

//Analisis port construction
        mon_ap = new("mon_ap", this);

//uvm_config db 
        if(!uvm_config_db#(virtual jtag_intf)::get(this,"*","jtag_intf", vif))
            `uvm_fatal(get_name(), "Monitor: VIF NOT FOUND")

//sequence_item construction
        sq_i = jtag_seq_item::type_id::create("sq_i");

    endfunction

//Run phase
    virtual task run_phase(uvm_phase phase);
        super.run_phase(phase);
        
        forever begin
//Sampling at posedge of clock
                    @(vif.mon_cb);

//Assigning data from interface to sequence item - sw clock
//inputs
                    sq_i.trst                       <= vif.trst;           
                    sq_i.tms                        <= vif.tms;                                
                    sq_i.tdi                        <= vif.tdi;            
                    sq_i.dmi_data_in                <= vif.dmi_data_in;                  
                    sq_i.tdo                        <= vif.tdo;            
                    sq_i.tdo_en                     <= vif.tdo_en;             
                    sq_i.dr_scan                    <= vif.dr_scan;        
                    sq_i.dmi_data_out               <= vif.dmi_data_out;   
                    sq_i.dmi_address_out            <= vif.dmi_address_out;
                    sq_i.dmi_op_out                 <= vif.dmi_op_out;     
                    sq_i.dmi_transfer               <= vif.dmi_transfer;
                    

//Writing to analysis port from sequence_item
                    mon_ap.write(sq_i);


            end

    endtask

endclass

