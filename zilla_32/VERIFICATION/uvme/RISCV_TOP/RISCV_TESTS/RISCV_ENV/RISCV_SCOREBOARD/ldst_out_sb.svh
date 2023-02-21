class ldst_out_sb extends uvm_scoreboard;
  `uvm_component_utils(ldst_out_sb)
  
  //Virtual interface Instantion
  virtual riscv_intf vif;    //riscv interface
  virtual ldst_out_intf lvif;  //load interface 

  uvm_blocking_get_port #(seq_item_ldst) ldst_out_sb_con1; //tlm fifo

  //=========================Variable declaration===========================//
  int m_num_tx = 2;
  logic sb_read_en;
  logic [31:0] sb_mem_read_addr_rtl;
  logic [31:0] sb_mem_read_addr;
  logic [31:0] sb_mem_read_data;
  logic        sb_write_en;
  logic [31:0] sb_mem_write_addr_rtl;
  logic [31:0] sb_mem_write_addr;
  logic [31:0] sb_mem_write_data;
  logic [31:0] sb_immediate;
  logic [31:0] sb_reg_data[31:0];
  logic [31:0] sb_base_addr;
  logic [4:0]  sb_rd;
  logic [31:0] sb_gpr_data;
  logic sb_stall;
  logic [31:0] sb_mem_write_addr_o;
  
  
 // seq_item_ldst ldst_out_queue[$];

  //======================Constructor======================================//
  function new(string name = "ldst_out_sb", uvm_component parent=null);
    super.new(name, parent);
  endfunction

  //=====================Build Phase============================================//
  function void build_phase (uvm_phase phase);
    super.build_phase(phase);
    ldst_out_sb_con1	 = new("ldst_out_sb_con1", this);
  endfunction

    //Write function - To receive seq_item from monitor
  /*virtual function void write (input seq_item_ldst pkt);
   ldst_out_queue.push_back(pkt);             //stores the received sequence item
  endfunction*/


  //=====================Run phase===============================================//

  virtual task run_phase(uvm_phase phase);
    
    seq_item_ldst sb_seq_inst; // seq item instantiation
    phase.raise_objection(this);
    repeat (m_num_tx) 
     begin
      // @(vif.risc_clk)
            //TLM 
                ldst_out_sb_con1.get(sb_seq_inst);
          begin
            fork

           // `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("TLM Fifo is working"),UVM_NONE);
        

//==========================VARIABLES OF SCOREBOARD==================================//
          // begin
                /*sb_read_en  = sb_seq_inst.data_mem_read_en_o;
                sb_mem_read_addr_rtl = sb_seq_inst.data_mem_read_addr_o;
                sb_immediate    = sb_seq_inst.imm;
               // $display("IMMM=%h",sb_seq_inst.imm);
                sb_mem_read_data = sb_seq_inst.data_mem_read_data_i;
                sb_rd     = sb_seq_inst.rd;
                sb_gpr_data = sb_seq_inst.reg_wr_data;
               // $display("opcode is %0h and immediate is %0h and the PC is %0h",sb_seq_inst.opcode,sb_immediate,sb_seq_inst.PC);
               //~~~~~~~~~~~~~~~~data memory signals for write~~~~~~~~~~~~~~~~~~~~~~~~//
                sb_write_en = sb_seq_inst.data_mem_write_en_o;
                sb_mem_write_addr_rtl = sb_seq_inst.data_mem_write_addr_o;
                sb_mem_write_data = sb_seq_inst.data_mem_write_data_o;
                sb_stall = sb_seq_inst.stall_en;
                sb_base_addr = sb_seq_inst.base_addr;
              //  $display("BA = %h",sb_seq_inst.base_addr);
                //$display("The PC  = %0h and base address is %0h",sb_seq_inst.PC,sb_base_addr);



             
             //$display("The read data in scoreboard is %0h",sb_mem_read_data);
             //$display("The dest in scoreboard is %0d",sb_rd);
                //================================REGISTER LOAD==========================================//
             foreach(sb_reg_data[i])
                begin
                    sb_reg_data[i]  =  sb_seq_inst.reg_data[i];
                   // `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("The register data[%0d] in scoreboard is %0h",i,sb_reg_data[i]),UVM_NONE);
                end
                
            end


 //===================================================OPCODE CHECKING FOR LOAD===============================================//
    //Process 1      
          begin
             if(sb_seq_inst.opcode == 'h3)
                 begin 
                 //      `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("Time = %0t ,It is Load Instruction opcode = %0h", $time,sb_seq_inst.opcode),UVM_NONE);
                 end
             else 
                 begin
                  //    `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("Time = %0t ,It is not Load Instruction opcode = %0h", $time,sb_seq_inst.opcode),UVM_NONE);
                 end
          end


  ///==================================================READ ENABLE CHECKING=================================================//
       //Process 2 

           begin
                if(sb_seq_inst.opcode == 'h3 && sb_stall == 0)
                    begin
                         if(sb_read_en == 1)
                            begin
                             //   `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("Time = %0t ,The Read data is enabled = %0h", $time,sb_read_en),UVM_NONE);
                            end
                        else
                            begin
                             //   `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("Time = %0t ,The Read data is disabled = %0h", $time,sb_read_en),UVM_NONE);
                            end
                    end
            end 



        ///==============================================READ ADDRESS COMPARISON===========================================//

        //Process 3 

         begin
            if(sb_read_en == 1)
                sb_mem_read_addr = sb_base_addr + sb_immediate;
               // $display("The scoreboard address is %0h and immediate = %0h and base address = %0h",sb_mem_read_addr,sb_immediate,sb_base_addr);
                //#10;
                begin            
                    if(sb_mem_read_addr_rtl == sb_mem_read_addr)
                        begin
                         //  `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("Time = %0t,Read addrress is correct and rtl = %0h, sb = %0h",$time,sb_mem_read_addr_rtl,sb_mem_read_addr),UVM_NONE);
                        end
                    else
                        begin
                         //   `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("Time = %0t,Read addrress is wrong and rtl = %0h, sb = %0h",$time,sb_mem_read_addr_rtl,sb_mem_read_addr),UVM_NONE);
                        end
               end           
         end


    ///================================================DATA COMPARSION========================================================//

        begin
           // $display("The destination address is %0h",sb_rd);
                if(sb_mem_read_data == sb_gpr_data)
                    begin
                      //   `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("Time = %0t,Read data is correct and rtl = %0h, sb = %0h",$time,sb_mem_read_data,sb_gpr_data),UVM_NONE);
                    end
                else
                    begin
                      //   `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("Time = %0t,Read data is wrong and rtl = %0h, sb = %0h",$time,sb_mem_read_data,sb_gpr_data),UVM_NONE);
                    end
        end


    //===============================================ADDRESS RANGE=============================================================//
        begin
            if(sb_mem_read_addr_rtl>='h48110 && sb_mem_read_addr_rtl<='h87FF0)
                begin
                //    `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("The address is within the range is %0h",sb_mem_read_addr_rtl),UVM_NONE);
                end
            else
                begin
                 //   `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("The address is not within the range is %0h",sb_mem_read_addr_rtl),UVM_NONE);
                end
        end


    //========================================OPCODE CHECKING FOR STORE==================================================//
          begin
             if(sb_seq_inst.opcode == 'h23)
                 begin 
                    //   `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("Time = %0t ,It is Store Instruction opcode = %0h", $time,sb_seq_inst.opcode),UVM_NONE);
                 end
             else 
                 begin
                   //   `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("Time = %0t ,It is not Store Instruction opcode = %0h", $time,sb_seq_inst.opcode),UVM_NONE);
                 end
          end        
    

  ///==========================================WRITE ENABLE CHECKING===================================================//

           begin
                if(sb_seq_inst.opcode == 'h23 && sb_stall == 0)
                    begin
                         if(sb_write_en == 1)
                            begin
                               // `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("Time = %0t ,The Write data is enabled = %0h", $time,sb_write_en),UVM_NONE);
                            end
                        else
                            begin
                             //   `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("Time = %0t ,The Write data is disabled = %0h", $time,sb_write_en),UVM_NONE);
                            end
                    end
            end 

///==============================================WRITE ADDRESS COMPARISON=============================================//

        //Process 3 

         begin
            if(sb_write_en == 1)
                sb_mem_write_addr = sb_base_addr + sb_immediate;
                sb_mem_write_addr_o = {sb_mem_write_addr[31:2],2'b00};
               // $display("Sariyad address is %0h",sb_mem_write_addr_o);
               // $display("The scoreboard write address is %0h and rtl_addr = %0h and immediate = %0h and base address = %0h",sb_mem_write_addr,sb_mem_write_addr_rtl,sb_immediate,sb_base_addr);
                //#10;
                begin            
                    if(sb_mem_write_addr_rtl == sb_mem_write_addr)
                        begin
                        //   `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("Time = %0t,Write addrress is correct and rtl = %0h, sb = %0h",$time,sb_mem_write_addr_rtl,sb_mem_write_addr),UVM_NONE);
                        end
                    else
                        begin
                         //   `uvm_info("INSIDE LDST SCOREBOARD",$sformatf("Time = %0t,Write addrress is wrong and rtl = %0h, sb = %0h",$time,sb_mem_write_addr_rtl,sb_mem_write_addr),UVM_NONE);
                        end
               end           
         end



 //===========================================================================================================================//

    //wait(ldst_out_queue.size()>0);
        //$display("=================size - queue======%0d",mon_branch_q.size());
        
        /*begin
        sb_seq_inst = ldst_out_queue.pop_front();
        //~~~~~~~~~~~~~~~~data memory signals for read~~~~~~~~~~~~~~~~~~~~~~~~//
        sb_read_en  = sb_seq_inst.data_mem_read_en_o;
        sb_mem_read_addr_rtl = sb_seq_inst.data_mem_read_addr_o;
        sb_mem_read_data = sb_seq_inst.data_mem_read_data_i;
        sb_immediate    = sb_seq_inst.imm;
        //~~~~~~~~~~~~~~~~data memory signals for write~~~~~~~~~~~~~~~~~~~~~~~~//
        sb_write_en = sb_seq_inst.data_mem_write_en_o;
        sb_mem_write_addr_rtl = sb_seq_inst.data_mem_write_addr_o;
        sb_mem_write_data = sb_seq_inst.data_mem_write_data_o;
        //sb_reg_data  = sb_seq_inst.reg_data; */
        
        //*********************************************Logic for load instructions*********************************************/////
                
       //--------------------Read enable checking------------------------------------//
        /*if(sb_seq_inst.opcode == 3)begin
            if(sb_mem_write_addr_rtl == 1)begin
                $display("Read is enabled");
                end
            else
                begin
                $display("Read is disabled");
                end
                end  



                
        //-----------------Read address calcualtion and comparision-----------------//
        begin
         sb_mem_read_addr = sb_immediate + 295200; 
         if(sb_mem_read_addr_rtl == sb_mem_read_addr)
                begin
                $display("Read addrress is correct and rtl = %d, sb = %d",sb_mem_read_addr_rtl,sb_mem_read_addr);
                end
            else
                begin
                $display("Read addrress is wrong and rtl = %d, sb = %d",sb_mem_read_addr_rtl,sb_mem_read_addr);
                end
          end*/
           
      


        ///----------------Read data calcualtion and comparision---------------------// 


        //--------------------Write enable checking------------------------------------//
       /* if(sb_seq_inst.opcode == 35)
            begin
            if(sb_write_en == 1)begin
                $display("Write is enabled");
                end
            else
                begin
                $display("Write is disabled");
                end
            end*/
        //-----------------Write address calcualtion and comparision-----------------//
        /*begin
         sb_mem_write_addr = sb_immediate + 295200; 
         if(sb_mem_write_addr_rtl == sb_mem_write_addr)
                begin
                $display("write addrress is correct and rtl = %d, sb = %d",sb_mem_write_addr_rtl,sb_mem_write_addr);
                end
            else
                begin
                $display("write addrress is wrong and rtl = %d, sb = %d",sb_mem_write_addr_rtl,sb_mem_write_addr);
                end
          end*/

//================================================================================================================================//
          join
       end
    end
    phase.drop_objection(this);
  endtask
endclass

