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
`include "define_lib.svh"

class print_mailbox extends mailbox;

  `uvm_component_utils(print_mailbox)

  function new(string name="print_mailbox",uvm_component parent=null);
     super.new(name,parent);
  endfunction
 
 task main_phase(uvm_phase phase);  
    fork
      mailbox_print();
//      mailbox_print_sample();
      mailbox_1();
      mailbox_1_flag_clear();
      mailbox_2();
      mailbox_2_flag_clear();
      end_sim();
    join_none
  endtask

  //----------------------`MAILBOX_PRINT----------------------------------------------//

//  // Monitor for `MAILBOX_PRINT
//  task mailbox_print();
//    fork   
//      forever 
//      begin
//        @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_PRINT))
//        begin
//           mailbox_print_addr = 20'h20011;
//		$write("time = %0d ns zilla_core - `MAILBOX_PRINT : %c",$stime,vif.mem_wr_data);
//          $display($stime,"\tDheeru bhai `MAILBOX_PRINT :address %h data %c byte = %h ",vif.mem_wr_addr,vif.mem_wr_data,vif.mem_byte_en);
//        end
//      end
//
//      // Sampling data if `MAILBOX_PRINT
//      forever
//      begin
//        @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == mailbox_print_addr))
//        begin
//          $write("%c",vif.mem_wr_data);
//          $display($stime,"\tDheeru bhai 123 `MAILBOX_PRINT :address %h data %c byte = %h ",vif.mem_wr_addr,vif.mem_wr_data,vif.mem_byte_en);
//          mailbox_print_addr = mailbox_print_addr +1;
//        end
//      end
//    join_none
//  endtask
//

  //---------------------------------------`MAILBOX_1 ---------------------------------//
//  task mailbox_1();
//      forever 
//        @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_1))
//        begin
//          mailbox_1_data  = vif.mem_wr_data;
//		$display("\ntime = %0d ns zilla_core - `MAILBOX_1 = 0x%0h",$stime,vif.mem_wr_data);
//         
//	       // RAND_REQ
//           if(mailbox_1_data == 'hEEAAEEAA)
//           begin 
//             random_number = $random;
//		   repeat(1) @(posedge vif.riscv_clk);
//	         $display("time = %0d ns zilla_core - `MAILBOX_1_REQ_RAND = 0x%0h",$stime,mailbox_1_data); 
//             for(int i = 0; i<8; i++)
//             begin
//               r_config.data_memory[`MAILBOX_1+i] = random_number[(i*8)+:8]; 
//               ref_model.memory[`MAILBOX_1+i] = random_number[(i*8)+:8];
//             end 
//           end
//       
//           // END_SIM 
//           if(mailbox_1_data == 'hEEAAAAEE)
//           begin
//		   $display("time = %0d ns zilla_core - END_SIM = 0x%0h",$stime,mailbox_1_data);
//            // $finish; 
//            r_config.instructions_executed_count=r_config.no_of_instructions;
//           end
//        end
// endtask
//       
//   // FLAG_CLEAR
//  task mailbox_1_flag_clear();
//    forever
//      @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_1_FLAG))
//      begin
//        mailbox_1_flag_addr =  `MAILBOX_1_FLAG;
//	      $display("time = %0d ns zilla_core - `MAILBOX_1_FLAG_SET = 0x%0h",$stime,vif.mem_wr_data);
//        repeat(1) @(posedge vif.riscv_clk);
//	      $display("time = %0d ns zilla_core - `MAILBOX_1_FLAG_CLEAR = 0x%0h",$stime,clear_flag); 
//        for(int i = 0; i<8; i++)
//        begin
//          r_config.data_memory[mailbox_1_flag_addr+i] = clear_flag[(i*8)+:8]; 
//          ref_model.memory[mailbox_1_flag_addr+i] = clear_flag[(i*8)+:8];
//        end 
//      end
//  endtask
//
//
//      //------------------------------`MAILBOX_2------------------------------------//      
//   
//  task mailbox_2();
//      forever 
//        @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_2))
//        begin
//          mailbox_2_data  = vif.mem_wr_data;
//		$display("\ntime = %0d ns zilla_core - `MAILBOX_2 = 0x%0h",$stime,vif.mem_wr_data);
//	      
//          // REQ_RAND
//          if(mailbox_2_data == 'hEEAAEEAA)
//          begin 
//             random_number = $random;
//		  repeat(1) @(posedge vif.riscv_clk);
//		  $display("time = %0d ns zilla_core - `MAILBOX_2_REQ_RAND = 0x%0h",$stime,mailbox_2_data); 
//             for(int i = 0; i<8; i++)
//             begin
//               r_config.data_memory[`MAILBOX_2+i] = random_number[(i*8)+:8]; 
//               ref_model.memory[`MAILBOX_2+i] = random_number[(i*8)+:8];
//             end 
//          end
//        end
//   endtask
//
//   // FLAG CLEAR
//   task mailbox_2_flag_clear();
//     forever
//     @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_2_FLAG))
//     begin
//       mailbox_2_flag_addr =  `MAILBOX_2_FLAG;
//	     $display("time = %0d ns zilla_core - `MAILBOX_2_FLAG_SET = 0x%0h",$stime,vif.mem_wr_data);
//       repeat(1) @(posedge vif.riscv_clk);
//       $display("time = %0d ns zilla_core - `MAILBOX_2_FLAG_CLEAR = 0x%0h",$stime,clear_flag); 
//       for(int i = 0; i<8; i++)
//       begin
//         r_config.data_memory[mailbox_2_flag_addr+i] = clear_flag[(i*8)+:8]; 
//         ref_model.memory[mailbox_2_flag_addr+i] = clear_flag[(i*8)+:8];
//       end 
//     end
//   endtask
//     //--------------------------------------------------------------------------------//
endclass
//
//
//
