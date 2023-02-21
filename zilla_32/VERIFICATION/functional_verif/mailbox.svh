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
class mailbox extends uvm_component;

  `uvm_component_utils(mailbox)

  virtual riscv_interface  vif;
  riscv_ref_alu ref_model;
  riscv_config r_config;
  
  logic [31:0] mailbox_1_data;
  logic [31:0] mailbox_2_data;
  logic [31:0] IRQ_de_assert;
  logic [31:0] random_number;
  logic [31:0] clear_flag = 32'h11223344;
  logic [19:0] mailbox_print_addr = 0;
  logic [19:0] mailbox_1_flag_addr;
  logic [19:0] mailbox_2_flag_addr;
  int unsigned fin;
  
  function new(string name="mailbox",uvm_component parent=null);
     super.new(name,parent);
  endfunction
function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    ref_model = riscv_ref_alu::type_id::create("ref_model") ;
    if(!uvm_config_db#(virtual riscv_interface)::get(this,"","riscv_intf",vif))
      `uvm_fatal("NO VIRTUAL INTERFACE",{"VIRTUAL INTERFACE MUST BE SET FOR :",get_full_name,".vif"});
  
    if(!uvm_config_db#(riscv_config)::get(null,"uvm_test_top.env","CONFIGURATION",r_config))
      `uvm_fatal("NO CONFIGURATION",{"configuration instance must be set for: ",get_full_name(),".r_config"});

  endfunction : build_phase
 
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

  task mailbox_print();
    fork   
      forever 
      begin
        @(posedge vif.riscv_clk iff (vif.mem_wr_en_1 && vif.mem_wr_addr_1 == `MAILBOX_PRINT))
        begin
           mailbox_print_addr = 20'h48009;
           $write("time = %dns  zilla_core - MAILBOX_PRINT : %c",$stime,vif.mem_wr_data_1);
        end
      end

      // Sampling data if `MAILBOX_PRINT
      forever
      begin
        @(posedge vif.riscv_clk iff (vif.mem_wr_en_1 && vif.mem_wr_addr_1 == mailbox_print_addr))
        begin
          $write("%c",vif.mem_wr_data_1);
         // $display($stime,"\t MAILBOX_PRINT :address %h data %c byte = %h ",vif.mem_wr_addr,vif.mem_wr_data,vif.mem_byte_en);
          mailbox_print_addr = mailbox_print_addr +1;
        end
      end
    join_none
  endtask
//---------------------------------------`MAILBOX_1 ---------------------------------//
  task mailbox_1();
      forever 
        @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_1))
        begin
          mailbox_1_data  = vif.mem_wr_data;
          // RAND_REQ
           if(mailbox_1_data == 'hEEAAEEAA) begin
           random_number = $urandom_range(32'h8000_0000,32'hffff_ffff);
           fork
             begin 
               repeat(1) @(posedge vif.riscv_clk);
	           $display("time = %dns  zilla_core - MAILBOX_1_REQ_RAND = 0x%0h random number = 0x%0h",$stime,mailbox_1_data,random_number); 
               for(int i = 0; i<4; i++)
               begin
                 r_config.data_memory[`MAILBOX_1+i] = random_number[(i*8)+:8]; 
               //  ref_model.memory[MAILBOX_1+i] = random_number[(i*8)+:8];
               end  
             end
             begin 
               repeat(5) @(posedge vif.riscv_clk);
               for(int i = 0; i<4; i++)
               begin
               //  r_config.data_memory[MAILBOX_1+i] = random_number[(i*8)+:8]; 
                 ref_model.memory[`MAILBOX_1+i] = random_number[(i*8)+:8];
               end
             end
           join_any
           end
        end
 endtask


 // FLAG_CLEAR
  task mailbox_1_flag_clear();
    forever
      @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_1_FLAG))
      fork
        begin
          mailbox_1_flag_addr =  `MAILBOX_1_FLAG;
          $display("time = %dns  zilla_core - MAILBOX_1_FLAG_SET = 0x%0h",$stime,vif.mem_wr_data);
          repeat(1) @(posedge vif.riscv_clk);
          $display("time = %dns  zilla_core - MAILBOX_1_FLAG_CLEAR = 0x%0h",$stime,clear_flag); 
          for(int i = 0; i<4; i++)
           begin
            r_config.data_memory[mailbox_1_flag_addr+i] = clear_flag[(i*8)+:8];
            $display("FLAG1");
        //    ref_model.memory[mailbox_1_flag_addr+i] = clear_flag[(i*8)+:8];
           end 
        end
        begin
          mailbox_1_flag_addr =  `MAILBOX_1_FLAG;
          repeat(5) @(posedge vif.riscv_clk);
          for(int i = 0; i<4; i++)
           begin
            ref_model.memory[mailbox_1_flag_addr+i] = clear_flag[(i*8)+:8];
           end 
        end
      join_any
  endtask


      //------------------------------`MAILBOX_2------------------------------------//      
   
  task mailbox_2();
      forever 
        @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_2))
        begin
          mailbox_2_data  = vif.mem_wr_data;
	      
          // REQ_RAND
          if(mailbox_2_data == 'hEEAAEEAA)
          begin
           random_number = $urandom_range(32'h8000_0000,32'hffff_ffff);
          fork
            begin
              repeat(1) @(posedge vif.riscv_clk);
	          $display("time = %dns  zilla_core - MAILBOX_2_REQ_RAND = 0x%0h random_number = 0x%0h",$stime,mailbox_2_data,random_number); 
              for(int i = 0; i<4; i++)
              begin
                r_config.data_memory[`MAILBOX_2+i] = random_number[(i*8)+:8]; 
               // ref_model.memory[MAILBOX_2+i] = random_number[(i*8)+:8];
              end 
            end
            begin
              repeat(5) @(posedge vif.riscv_clk);
              for(int i = 0; i<4; i++)
              begin
              //  r_config.data_memory[MAILBOX_2+i] = random_number[(i*8)+:8]; 
                ref_model.memory[`MAILBOX_2+i] = random_number[(i*8)+:8];
              end 
            end
          join_any  
          end
        end
   endtask

   // FLAG CLEAR
   task mailbox_2_flag_clear();
     forever
     @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_2_FLAG))
     fork
     begin
       mailbox_2_flag_addr =  `MAILBOX_2_FLAG;
       $display("time = %dns  zilla_core - MAILBOX_2_FLAG_SET = 0x%0h",$stime,vif.mem_wr_data);
       repeat(1) @(posedge vif.riscv_clk);
       $display("time = %dns  zilla_core - MAILBOX_2_FLAG_CLEAR = 0x%0h",$stime,clear_flag); 
       for(int i = 0; i<4; i++)
       begin
         r_config.data_memory[mailbox_2_flag_addr+i] = clear_flag[(i*8)+:8]; 
            $display("FLAG2");
        // ref_model.memory[mailbox_2_flag_addr+i] = clear_flag[(i*8)+:8];
       end 
     end
     begin
       mailbox_2_flag_addr =  `MAILBOX_2_FLAG;
       repeat(5) @(posedge vif.riscv_clk);
       for(int i = 0; i<4; i++)
       begin
         ref_model.memory[mailbox_2_flag_addr+i] = clear_flag[(i*8)+:8];
       end 
     end
    join_any
   endtask
     //--------------------------------------------------------------------------------//

  // --------------------END_SIM -------------------------
  task end_sim();
    logic exit = 0;
    fork
       forever
       @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_1))
       begin
       mailbox_1_data  = vif.mem_wr_data;
       if(mailbox_1_data == 'hEEAAAAEE)
             begin
              exit =  1'b1;
              $display("time = %dns  zilla_core - MAILBOX_1_END_SIM = 0x%0h",$stime,mailbox_1_data);
            //  r_config.instructions_executed_count=r_config.no_of_instructions;
             end

       end
       	 //$display("time = %dns  zilla_core - end  for loop",$stime); 
     forever
       @(posedge vif.riscv_clk iff (vif.mem_wr_en && vif.mem_wr_addr == `MAILBOX_2 && exit == 1'b1))
       begin
         mailbox_2_data  = vif.mem_wr_data;
         exit = 1'b0;
         $display("time = %dns  zilla_core - MAILBOX_2_ERROR_COUNT = %0d",$stime,mailbox_2_data);
         result_check();
	       if(mailbox_2_data > 0)
            r_config.instructions_executed_count=r_config.no_of_instructions;
         else
            r_config.instructions_executed_count=r_config.no_of_instructions;

       end 

    join_none
   endtask

     //--------------------------------------------------------------------------------//
 // Monitor for MAILBOX_PRINT
 
    task result_check();
      logic [31:0] data_q[$];
      int unsigned k = 0;
	int fin;
       fin=$fopen("mem_dump.txt","w");
       for(int i = 0; i<1396; i++)
       begin
         for(int j = 0;j<4;j++)
           data_q[i][(8*j) +:8] = r_config.data_memory[(20'h48120+k+j)];
	$fdisplay(fin,"%0d",$signed(data_q[i]));
           k = k+4;
       end
	  $fclose(fin);
          $display("\n");
      // for(int i = 0;i<data_q.size;i=i+3)
         // $display("\tmemory_check - OPERAND1 = 0x%0h OPERAND2 = 0x%0h RESULT = 0x%0h",data_q[i],data_q[i+1],data_q[i+2]);

   endtask

   //PC mointor//

   task mailbox_pc(); // task to get pc value
      forever 
        @(posedge vif.riscv_clk )
        begin
         	 if(vif.PC)
              begin
               for(int i = 0; i<20; i++)
                begin
               r_config.data_memory[`MAILBOX_1+i] = vif.PC;
               ref_model.memory[`MAILBOX_1+i] = vif.PC;
                end 
              end
        end
 endtask

endclass

