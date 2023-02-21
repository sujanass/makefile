class test extends mailbox;

  `uvm_component_utils(test)

  function new(string name="test",uvm_component parent=null);
     super.new(name,parent);
  endfunction
 
 task main_phase(uvm_phase phase);  
    fork
      mailbox_print();
      mailbox_1();
      mailbox_1_flag_clear();
      mailbox_2();
      mailbox_2_flag_clear();
      end_sim();
    join_none
      result_check();
  endtask

  
 
endclass

