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
* File Name : decode_mon.sv

* Purpose :

* Creation Date : 21-07-2023

* Last Modified : Tue 05 Sep 2023 06:08:45 PM IST

* Created By :  

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/

class decode_mon extends uvm_monitor;
   `uvm_component_utils(decode_mon)

   virtual riscv_intf vif;
   
   virtual decode_intf dif;

   decode_seq_item dcd_seq_mon;

    uvm_analysis_port #(decode_seq_item) port_mon;


     static int m_num_tx_mon = 2;

//TLM FIFO sender class
    uvm_blocking_put_port #(decode_seq_item) mon_cont;
         


         logic [31:0] mon_instruction;
         logic [6:0]  mon_opcode;
         logic [2:0]  mon_func3;
         logic [6:0]  mon_func7;
         logic [31:0] mon_imm;
         logic [4:0]  mon_rs1;
         logic [4:0]  mon_rs2;
         logic [4:0]  mon_rd;

 
//Constructor
  function new (string name, uvm_component parent);
    super.new(name, parent);
  endfunction
 
//Build phase - uvm config db get method
  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    port_mon     = new("port_mon", this);
     mon_cont = new("mon_cont", this);

      //If virtual interface not connected via config db, drop the entire process
        if (!uvm_config_db#( virtual riscv_intf)::get(this, "*", "riscv_intf", vif))
            `uvm_fatal(get_full_name(),{"Virtual Interface must be set for:",".riscv_intf"});
      //If virtual interface not connected via config db, drop the entire process
        if (!uvm_config_db#( virtual decode_intf)::get(this, "*", "decode_intf", dif))
            `uvm_fatal(get_full_name(),{"Virtual Interface must be set for:",".decode_intf"});

  endfunction

 
//Run phase - sampling logic
  virtual task run_phase(uvm_phase phase);
    //forever
    // begin 
       repeat(m_num_tx_mon)
        begin
        dcd_seq_mon = decode_seq_item::type_id::create("dcd_seq_mon");
	
        @(posedge vif.risc_clk);
 
              dcd_seq_mon.instruction                     = dif.instruction                  ;
              dcd_seq_mon.opcode                          = dif.opcode                       ;
              dcd_seq_mon.func3                           = dif.func3                        ;
              dcd_seq_mon.func7                           = dif.func7                        ;
              dcd_seq_mon.imm                             = dif.imm                          ;
              dcd_seq_mon.rs1                             = dif.rs1                          ;
              dcd_seq_mon.rs2                             = dif.rs2                          ;
              dcd_seq_mon.rd                              = dif.rd                           ;
              dcd_seq_mon.valid                           = dif.valid                        ;
              dcd_seq_mon.reg_wr_en_r                     = dif.reg_wr_en_r                  ;
              dcd_seq_mon.mem_rd_en_r                     = dif.mem_rd_en_r                  ;
              dcd_seq_mon.mem_wr_en_r                     = dif.mem_wr_en_r                  ;
              dcd_seq_mon.reg_wr_en_r1                    = dif.reg_wr_en_r1                 ;
              dcd_seq_mon.alu_ctrl_r                      = dif.alu_ctrl_r                   ;
              dcd_seq_mon.mem_to_reg_en_r                 = dif.mem_to_reg_en_r              ;
              dcd_seq_mon.invalid_instruction_valid_o     = dif.invalid_instruction_valid_o  ;





            
            
             //begin  
            // dcd_seq_mon.print(); 
             // end
 
         port_mon.write(dcd_seq_mon);

         mon_cont.put(dcd_seq_mon); //writing

       end
    endtask
endclass


