//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Copyright © 2022 Vivartan Technologies., All rights reserved/////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//All works published under Zilla_Gen_0 by Vivartan Technologies is copyrighted by the Association and ownership// 
//of all right, title and interest in and to the works remains with Vivartan Technologies. No works or documents//
//published under Zilla_Gen_0 by Vivartan Technologies may be reproduced,transmitted or copied without the expre//
//-ss written permission of Vivartan Technologies will be considered as a violations of Copyright Act and it may//
//lead to legal action.                                                                                         //
//                                                                                                              //
//**************************************************************************************************************//                                                                                                              //
//                                                                                                              //
//FILE NAME:                                                                                                    //
//DESCRIPTION:                                                                                                  //   
//AUTHOR:                                                                                                       //               
//DATE:                                                                                                         //
//LAST MODIFIED BY:                                                                                             //
//LAST MODIFIED ON:                                                                                             //
//                                                                                                              //      
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class mailbox_env extends uvm_env;

  `uvm_component_utils(mailbox_env)

      addition  add_mbx;
    factorial factorial_mbx; 
    test test_mbx;
    print_mailbox p_mbx;
    mailbox_test  mailbox_test_mbx;
     extern function new(string name="mailbox_env",uvm_component parent=null);
  extern function void build_phase(uvm_phase phase);
  endclass

function mailbox_env::new(string name="mailbox_env",uvm_component parent=null);
  super.new(name,parent);
endfunction : new

function void mailbox_env:: build_phase(uvm_phase phase);
  super.build_phase(phase);	
  if($test$plusargs("print_mailbox"))
    p_mbx = print_mailbox::type_id::create("p_mbx",this);
     if($test$plusargs("test"))
    test_mbx = test::type_id::create("test_mbx",this);
  if($test$plusargs("mailbox_test"))
    mailbox_test_mbx = mailbox_test::type_id::create("mailbox_test_mbx",this);
     if($test$plusargs("addition"))
    add_mbx = addition::type_id::create("add_mbx",this);
    if($test$plusargs("factorial"))
    factorial_mbx = factorial::type_id::create("factorial_mbx",this);   


endfunction : build_phase


/*//Connect phase
  virtual function void connect_phase(uvm_phase phase);
    super.connect_phase(phase);
    //agent_inst.monitor_inst.port_mon.connect(mailbox_agent.mb_port); //Need to change names
  endfunction
*/









































