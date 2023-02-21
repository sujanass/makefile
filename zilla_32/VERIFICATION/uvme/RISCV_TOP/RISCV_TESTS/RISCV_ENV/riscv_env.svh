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
* File Name : riscv_env.sv

* Purpose : enviornment for special counter uvm tb

* Creation Date : 30-03-2023

* Last Modified : Fri 05 May 2023 12:25:37 PM IST

* Created By :  Sharon
*/




class riscv_env extends uvm_env;

//factory registration
    `uvm_component_utils(riscv_env)

     //TLM FIFO IMPLEMENTATION LDST
     uvm_tlm_fifo #(seq_item_ldst) m_tlm_fifo; 
     int m_num_tx;

     //TLM FIFO IMPLEMENTATION
     uvm_tlm_fifo #(decode_seq_item) m_tlm_fifo_dcd; 
     int m_num_tx_dcd;

  //TLM FIFO IMPLEMENTATION
     uvm_tlm_fifo #(seq_item_wb_out) m_tlm_fifo_wb; 
     rand int m_num_tx_wb;

//inst_gen_agent instantiation
    im_agent            agent_im;

//data mem agent instantiation
    agent_dm            dm_agent;

//Class riscv_agent instantiation
    riscv_agent         agent_i;


//Debug agent
    agent_debug         agent_di;

//Interrupt agent
    agent_interrupt     agent_int_i;

//Decode output stage agent
    agent_decode_out    agent_decode_inst;

//Memory output stage agent
    agent_ldst_out      agent_ldst_inst;

//Writeback output stage agent
    agent_write_back_out     agent_wb_inst;

//decode_coverage instantiation
    decode_coverage decode_cov_i;
 
//instr_gen_coverage instantiation
    instr_gen_coverage instr_gen_cov_i;

 //ldst coverage 
 ldst_coverage cov_ldst;
 
 decode_scoreboard  dcd_sb; 

//PC monitor agent
    agent_pc     agent_pc_inst;



//riscv_sb instantiation
    ldst_out_sb  ldst_sb_i;

   scoreboard_wb_out   sb_wb_out_inst;

   riscv_wb_coverage cov_wb;
      

    pc_coverage cov_pc;
//Construction
    function new(string name = "riscv_env", uvm_component parent);
        super.new(name, parent);
    endfunction

//Build phase
    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        agent_im = im_agent::type_id::create("agent_im",this);
        dm_agent = agent_dm::type_id::create("dm_agent",this);
        agent_i = riscv_agent::type_id::create("agent_i",this);
        agent_di = agent_debug::type_id::create("agent_di",this);
        agent_int_i = agent_interrupt::type_id::create("agent_int_i",this);
        agent_decode_inst = agent_decode_out::type_id::create("agent_decode_inst",this);
        agent_ldst_inst = agent_ldst_out::type_id::create("agent_ldst_inst",this);
        agent_wb_inst = agent_write_back_out::type_id::create("agent_wb_inst",this);
	agent_pc_inst = agent_pc::type_id::create("agent_pc_inst",this);
        dcd_sb = decode_scoreboard::type_id::create("dcd_sb",this);
        //coverage 
       cov_ldst = ldst_coverage::type_id::create("cov_ldst",this);
       ldst_sb_i = ldst_out_sb::type_id::create("ldst_sb_i",this);
        std::randomize(m_num_tx) with {m_num_tx inside {[50:100]};};
        ldst_out_monitor::m_num_tx_mon = m_num_tx;
        //agent_ldst_inst.monitor_inst.m_num_tx_mon = m_num_tx; 
        ldst_sb_i.m_num_tx = m_num_tx;
        m_tlm_fifo = new("uvm_tlm_fifo", this,2);
        //sb_wb_out_inst = scoreboard_wb_out::type_id::create("sb_wb_out_inst",this);

	decode_mon::m_num_tx_mon = 65471; 
        dcd_sb.m_num_tx = 65471;
        m_tlm_fifo_dcd = new("m_tlm_fifo_dcd", this,2);
        sb_wb_out_inst = scoreboard_wb_out::type_id::create("sb_wb_out_inst",this);
          monitor_write_back_out::m_num_tx_mon = 1; 
          sb_wb_out_inst.m_num_tx = 1;
          m_tlm_fifo_wb = new("m_tlm_fifo_wb", this,5);
        
        cov_wb = riscv_wb_coverage::type_id::create("cov_wb",this);


 //coverage Decoder
        decode_cov_i               = decode_coverage::type_id::create("decode_cov_i",this);
        
//coverage Instruction Generator
        instr_gen_cov_i               = instr_gen_coverage::type_id::create("instr_gen_cov_i",this);


         cov_pc =pc_coverage::type_id::create("cov_pc",this);

    endfunction

//connect phase
    virtual function void connect_phase (uvm_phase phase);
        super.connect_phase(phase);
        
        //agent_i.mon_i.mon_ap.connect(cov_i.analysis_export);
        //agent_i.mon_i.mon_ap.connect(sb_i.sb_ap);
        //agent_wb_inst.wb_monitor_inst.mon_port.connect(sb_wb_out_inst.scb_port);
	    agent_ldst_inst.monitor_inst.mon_cont.connect(m_tlm_fifo.put_export);
        ldst_sb_i.ldst_out_sb_con1.connect(m_tlm_fifo.get_export);
         //coverage
        agent_ldst_inst.monitor_inst.item_collected_port.connect(cov_ldst.analysis_export);
        agent_wb_inst.wb_monitor_inst.mon_cont.connect(m_tlm_fifo_wb.put_export);
        sb_wb_out_inst.wb_out_sb.connect(m_tlm_fifo_wb.get_export);
    
        agent_wb_inst.wb_monitor_inst.port_cov_wb_sq.connect(cov_wb.analysis_export); // monitor to coverage
        

        agent_decode_inst.dcd_mon.mon_cont.connect(m_tlm_fifo_dcd.put_export);
        dcd_sb.dcd_out_sb.connect(m_tlm_fifo_dcd.get_export);
	
	agent_decode_inst.dcd_mon.port_mon.connect(decode_cov_i.analysis_export);

        //coverage connection- Instruction Generator     
        agent_decode_inst.dcd_mon.port_mon.connect(instr_gen_cov_i.analysis_export);
        
	agent_pc_inst.p_mon.mon_port.connect(cov_pc.analysis_export);
endfunction
/*
    //Display a message when the FIFO is full
    virtual task run_phase(uvm_phase phase);
        forever 
            begin
                #10;
                if(m_tlm_fifo.is_full())
                    `uvm_info("UVM_TLM_FIFO","Fifo is now full!",UVM_MEDIUM)
            end
    endtask
    */
endclass


