//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Copyright © 2022 PravegaSemi PVT LTD., All rights reserved//////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//All works published under Zilla_Gen_0 by PravegaSemi PVT LTD is copyrighted by the Association and ownership  // 
//of all right, title and interest in and to the works remains with PravegaSemi PVT LTD. No works or documents  //
//published under Zilla_Gen_0 by PravegaSemi PVT LTD may be reproduced,transmitted or copied without the express//
//written permission of PravegaSemi PVT LTD will be considered as a violations of Copyright Act and it may lead //
//to legal action.                                                                                         //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
* File Name : pc_coverage.sv

* Purpose :

* Creation Date : 07-09-2023

* Last Modified : Wed 13 Sep 2023 04:29:34 PM IST

* Created By :  

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
class pc_coverage extends uvm_subscriber#(pc_seq_item); // uvm_subscriber is a standart uvm component to implemetn coverage : this will be anlysisi import 

//factory registration    
  `uvm_component_utils(pc_coverage)
   
//declaring seq item instance  
  pc_seq_item pc_xtn;


  bit [19:0] instr_read_addr_o; 
  bit [31:0] z_instruction_o;
  bit 	     exception_valid_o;		    
  bit [7:0]  exception_id_o;			    
  bit	     interrupt_valid_o;		    
  bit	     exception_id_write_valid_o;	
  bit        interrupt_id_write_valid_o;	
  bit 		 ld_sd_misalign_valid_o;  	
  bit [31:0] ld_sd_misalign_addr_o;		
  bit 		 instr_misalign_valid_o;  	
  bit [19:0] instr_misalign_addr_o;		
  bit 	     invalid_instr_valid_o;		
  bit        decode_instruction_valid_o;  
  bit        trap_valid_o; 
  bit 		 z_instruction_valid_i;
  bit 		 stall_valid_i;
  bit 	 	 branch_valid_i;
  // bit [19:0] instr_read_addr_o; 
  bit 	     z_instruction_read_enable_o;
  bit        read_write_ptr_valid;
  bit [19:0] pc_r ;
  bit [19:0] next_pc_r;



    //covergroup
    covergroup pc_covergroup;
    option.name         = "pc_covergroup";
    option.comment      = "to check coverage of ic";  


  INSTR_READ_ADDR_O    :  coverpoint instr_read_addr_o
                       {
                          bins bin_value_0 [] = {['h8100:'h87fff]}  with (item % 4 == 0);                           
                        }

  Z_INSTRUCTION_O      : coverpoint z_instruction_o
                       {
                         bins bin_value_0 = {[31:0]};
                       }
                      
 
  EXCEPTION_VALID_O   : coverpoint exception_valid_o
                       {
                         bins bin_value_0   = {0};
                         bins bin_value_1   = {1};
                       }
 
  EXCEPTION_ID_O       : coverpoint  exception_id_o
                       {
                         bins bin_value_0 = {[7:0]};                         
                       }

 INTERRUPT_VALID_O     : coverpoint  interrupt_valid_o
                       {
                         bins bin_value_0   = {0};
                         bins bin_value_1   = {1};
                       }

 EXCEPTION_ID_WRITE_VALID_O     : coverpoint  exception_id_write_valid_o
                       {
                         bins bin_value_0   = {0};
                         bins bin_value_1   = {1};
                       }

INTERRUPT_ID_WRITE_VALID_O    : coverpoint interrupt_id_write_valid_o
                       {
                         bins bin_value_0   = {0};
                         bins bin_value_1   = {1};
                       }

 LD_SD_MISALIGN_VALID_O  : coverpoint ld_sd_misalign_valid_o
                       {
                         bins bin_value_0   = {0};
                         bins bin_value_1   = {1};
                       }

 LD_SD_MISALIGN_ADDR_O    : coverpoint ld_sd_misalign_addr_o
                       {
                         bins bin_value_0 = {[31:0]};
                       }

 INSTR_MISALIGN_VALID_O    : coverpoint instr_misalign_valid_o
                       { 
                         bins bin_value_0   = {0};
                         bins bin_value_1   = {1};
                       }
  INSTR_MISALIGN_ADDR_O    : coverpoint instr_misalign_addr_o
                       {
                         option.auto_bin_max = 20;                         
                       }

 INVALID_INSTR_VALID_O    : coverpoint  invalid_instr_valid_o
                       {
                         bins bin_value_0   = {0};
                         bins bin_value_1   = {1};
                       }

DECODE_INSTRUCTION_VALID_O    : coverpoint decode_instruction_valid_o
                       {
                         bins bin_value_0   = {0};
                         bins bin_value_1   = {1};
                       }

TRAP_VALID_O           : coverpoint trap_valid_o
                       {
                         bins bin_value_0   = {0};
                         bins bin_value_1   = {1};   
                       }

Z_INSTRUCTION_VALID_I    : coverpoint z_instruction_valid_i
                       {
                         bins bin_value_0   = {0};
                         bins bin_value_1   = {1};
                       }

 STALL_VALID_I       : coverpoint  stall_valid_i
                       {
                         bins bin_value_0   = {0};
                         bins bin_value_1   = {1};
                       }

BRANCH_VALID_I    : coverpoint  branch_valid_i
                       {
                         bins bin_value_0   = {0};
                         bins bin_value_1   = {1};
                       }

Z_INSTRUCTION_READ_ENABLE_O    : coverpoint z_instruction_read_enable_o
                       {
                         bins bin_value_0   = {0};
                         bins bin_value_1   = {1};  
                       }

READ_WRITE_PTR_VALID   : coverpoint read_write_ptr_valid
                       {
                         bins bin_value_0   = {0};
                         bins bin_value_1   = {1};
                       }

PC_R                   : coverpoint pc_r
                       {
                          bins bin_value_0 [] = {['h8100:'h87fff]}  with (item % 4 == 0);
                        
                        }

 NEXT_PC_R             : coverpoint  next_pc_r
                       { 
                         
                        bins bin_value_0 [] = {['h8100:'h87fff]}  with (item % 4 == 0); 
                       }


  endgroup

//constructor new
        function new(string name ="pc_coverage", uvm_component parent);
            super.new(name, parent);
            pc_covergroup = new();
        endfunction



        function void write(input pc_seq_item t);
           pc_xtn = new();
           $cast(pc_xtn, t);
           // pc_xtn.print();
           this.instr_read_addr_o           =  pc_xtn.instr_read_addr_o           ; 
           this.z_instruction_o             =  pc_xtn.z_instruction_o             ;
           this.exception_valid_o           =  pc_xtn.exception_valid_o           ;		    
           this.exception_id_o              =  pc_xtn.exception_id_o              ;			    
           this.interrupt_valid_o           =  pc_xtn.interrupt_valid_o           ;		    
           this.exception_id_write_valid_o  =  pc_xtn.exception_id_write_valid_o  ;	
           this.interrupt_id_write_valid_o  =  pc_xtn.interrupt_id_write_valid_o  ;	
           this.ld_sd_misalign_valid_o      =  pc_xtn.ld_sd_misalign_valid_o      ;  	
           this.ld_sd_misalign_addr_o       =  pc_xtn.ld_sd_misalign_addr_o       ;		
           this.instr_misalign_valid_o      =  pc_xtn.instr_misalign_valid_o      ;  	
           this.instr_misalign_addr_o       =  pc_xtn.instr_misalign_addr_o       ;		
           this.invalid_instr_valid_o       =  pc_xtn.invalid_instr_valid_o       ;		
           this.decode_instruction_valid_o  =  pc_xtn.decode_instruction_valid_o  ;  
           this.trap_valid_o                =  pc_xtn.trap_valid_o                ; 
           this.z_instruction_valid_i       =  pc_xtn.z_instruction_valid_i       ;
           this.stall_valid_i               =  pc_xtn.stall_valid_i               ;
           this.branch_valid_i              =  pc_xtn.branch_valid_i              ; 
           this.z_instruction_read_enable_o =  pc_xtn.z_instruction_read_enable_o ;
           this.read_write_ptr_valid        =  pc_xtn.read_write_ptr_valid        ;
           this.pc_r                        =  pc_xtn.pc_r                        ;
           this.next_pc_r                   =  pc_xtn.next_pc_r                   ;
  		    
            pc_covergroup.sample();
        endfunction

endclass 
