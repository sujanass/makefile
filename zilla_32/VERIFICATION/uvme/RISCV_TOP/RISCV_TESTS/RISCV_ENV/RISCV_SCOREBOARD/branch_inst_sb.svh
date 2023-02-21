/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
* File Name :

* Purpose :

* Creation Date :

* Last Modified :

* Created By :  

////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/




`uvm_analysis_imp_decl (_con1)
//`uvm_analysis_imp_decl (_con2)

class branch_inst_sb extends uvm_scoreboard;
  `uvm_component_utils(branch_inst_sb)
  
//Virtual interface
    virtual riscv_intf vif;

    logic [19:0] sb_pc_mon;


   uvm_analysis_imp_con1 #(riscv_seq_item_branch,branch_inst_sb) branch_inst_sb_con1; // con1 is connection 1: any name can be given. this is needed only if there are two analysisi port coming to scoreboard. If only one this extention is nto needed
  int count;

  riscv_seq_item_branch mon_branch_q[$];
  
  function new (string name = "branch_inst_sb", uvm_component parent=null);
    super.new (name, parent);
  endfunction
	
  function void build_phase (uvm_phase phase);
    branch_inst_sb_con1	 = new("branch_inst_sb_con1", this);

    //uvm_config db 
        if(!uvm_config_db#(virtual riscv_intf)::get(this,"*","riscv_intf", vif))
            `uvm_fatal(get_name(), "Monitor: VIF NOT FOUND")  endfunction

  virtual function void write_con1 (input riscv_seq_item_branch seq_item_inst);
    mon_branch_q.push_back(seq_item_inst);
  endfunction

  task run_phase(uvm_phase phase);
    
    riscv_seq_item_branch sb_seq_inst;
 
    forever 
    begin

    wait(mon_branch_q.size()>0);
        //$display("=================size - queue======%0d",mon_branch_q.size());
        
        
        sb_seq_inst = mon_branch_q.pop_front();
        
        //$display("===============ScoreBoard=============");
        //sb_seq_inst.print();
        sb_pc_mon = sb_seq_inst.dut_pc;
        
        //$display(sb_pc_mon);
        
        //$display("===============ScoreBoard=============\n\n");
        

 
    end


    
    
  endtask
  


  
endclass

