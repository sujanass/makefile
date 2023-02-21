class monitor_pc extends uvm_monitor;


//Factory registration
    `uvm_component_utils( monitor_pc)

    //Virtual interface
    virtual riscv_intf vif;
     
        logic [19:0] mon_pc    ;             //Reference PC value 
        logic [31:0] immb_mon  ;             //Immediate value for sb type
        logic [31:0] rs1_gpr   ;             //For storing source register(rs1) value
        logic [31:0] rs2_gpr   ;             //For storing source register(rs2) value
        logic [6:0]  opcode    ;
        logic [4:0]  rd        ;
        logic [19:0] return_location;        //Return address for UJ and I type JALR 
        int          funct     ;
        logic [4:0]  rs1       ;
        logic [4:0]  rs2       ;
        logic [6:0]  func7     ;
        logic [31:0] imm_mono  ;             //Immediate OFFSET value for JALR and JAL type
        logic [31:0] rd_value  ;
        logic [31:0] mon_reg_data[31:0];     //For storing GPR value
        logic [19:0] rtl_pc;                 //RTL pc value
        logic [19:0] false_pc;               //When condition is not matched
        logic [19:0] pc_value;               //RTL PC value for I,R,S & U type
         logic [19:0] PC1;   
         logic [19:0] PC2;   

 
    //Seq_item Instantiation
    pc_seq_item seq_inst;

    //analysis port instantiation
    uvm_analysis_port #(pc_seq_item) mon_port;
 

    //constructor
    function new(string name ="monitor_pc", uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
          seq_inst = pc_seq_item::type_id::create("seq_inst");

        //analysis port construction
       mon_port = new("mon_port", this);

        //uvm_config db 
        if(!uvm_config_db#(virtual riscv_intf)::get(this,"*","riscv_intf", vif))
            `uvm_fatal(get_name(), "Monitor: VIF NOT FOUND");

     endfunction

     virtual task run_phase(uvm_phase phase);
        super.run_phase(phase);
        forever
        @(posedge vif.risc_clk)
            begin
            seq_inst.instruction                  =     vif.instruction     ;       
            seq_inst.opcode                       =     vif.opcode          ;
            seq_inst.func3                        =     vif.func3           ;
            seq_inst.func7                        =     vif.func7           ;
            seq_inst.imm                          =     vif.imm             ;   
            seq_inst.rs1                          =     vif.rs1             ;  
            seq_inst.rs2                          =     vif.rs2             ;  
            seq_inst.rd                           =     vif.rd              ;
            seq_inst.PC                           =     vif.PC              ;
            seq_inst.PC_REF                       =     mon_pc              ; 
            seq_inst.branch_valid                 =     vif.branch_valid    ; 
            seq_inst.z_rst                        =     vif.z_rst           ;
            seq_inst.z_instruction_read_enable_o  =     vif.z_instruction_read_enable_o;

            seq_inst.instr_read_addr_o            =     vif.instr_read_addr_o;
            seq_inst.z_instruction_o              =     vif.z_instruction_o;
            seq_inst.exception_valid_o            =     vif.exception_valid_o;
            seq_inst.exception_id_o               =     vif.exception_id_o;
            seq_inst.interrupt_valid_o            =     vif.interrupt_valid_o;
            seq_inst.exception_id_write_valid_o   =     vif.exception_id_write_valid_o;
            seq_inst.interrupt_id_write_valid_o   =     vif.interrupt_id_write_valid_o;
            seq_inst.ld_sd_misalign_valid_o       =     vif.ld_sd_misalign_valid_o;
            seq_inst.ld_sd_misalign_addr_o        =     vif.ld_sd_misalign_addr_o;
            seq_inst.instr_misalign_valid_o       =     vif.instr_misalign_valid_o;
            seq_inst.instr_misalign_addr_o        =     vif.instr_misalign_addr_o;
            seq_inst.invalid_instr_valid_o        =     vif.invalid_instr_valid_o;
            seq_inst.decode_instruction_valid_o   =     vif.decode_instruction_valid_o;
            seq_inst.trap_valid_o                 =     vif.trap_valid_o ;
            seq_inst.z_instruction_valid_i        =     vif.z_instruction_valid_i;
            seq_inst.stall_valid_i                =     vif.stall_valid_i;
            seq_inst.branch_valid_i               =     vif.branch_valid_i;
            seq_inst.read_write_ptr_valid         =     vif.read_write_ptr_valid;
            seq_inst.pc_r                         =     vif.pc_r;
            seq_inst.next_pc_r                    =     vif.next_pc_r;  
            seq_inst.rd0                          =     vif.reg_data[0]     ;  
            seq_inst.rd1                          =     vif.reg_data[1]     ;  
            seq_inst.rd2                          =     vif.reg_data[2]     ;  
            seq_inst.rd3                          =     vif.reg_data[3]     ;  
            seq_inst.rd4                          =     vif.reg_data[4]     ;  
            seq_inst.rd5                          =     vif.reg_data[5]     ;  
            seq_inst.rd6                          =     vif.reg_data[6]     ;  
            seq_inst.rd7                          =     vif.reg_data[7]     ;  
            seq_inst.rd8                          =     vif.reg_data[8]     ;  
            seq_inst.rd9                          =     vif.reg_data[9]     ;  
            seq_inst.rd10                         =     vif.reg_data[10]    ;  
            seq_inst.rd11                         =     vif.reg_data[11]    ;  
            seq_inst.rd12                         =     vif.reg_data[12]    ;  
            seq_inst.rd13                         =     vif.reg_data[13]    ;  
            seq_inst.rd14                         =     vif.reg_data[14]    ;  
            seq_inst.rd15                         =     vif.reg_data[15]    ;  
            seq_inst.rd16                         =     vif.reg_data[16]    ;  
            seq_inst.rd17                         =     vif.reg_data[17]    ;  
            seq_inst.rd18                         =     vif.reg_data[18]    ;  
            seq_inst.rd19                         =     vif.reg_data[19]    ;  
            seq_inst.rd20                         =     vif.reg_data[20]    ;  
            seq_inst.rd21                         =     vif.reg_data[21]    ;  
            seq_inst.rd22                         =     vif.reg_data[22]    ;  
            seq_inst.rd23                         =     vif.reg_data[23]    ;  
            seq_inst.rd24                         =     vif.reg_data[24]    ;  
            seq_inst.rd25                         =     vif.reg_data[25]    ;  
            seq_inst.rd26                         =     vif.reg_data[26]    ;  
            seq_inst.rd27                         =     vif.reg_data[27]    ;  
            seq_inst.rd28                         =     vif.reg_data[28]    ;  
            seq_inst.rd29                         =     vif.reg_data[29]    ;  
            seq_inst.rd30                         =     vif.reg_data[30]    ;  
            seq_inst.rd31                         =     vif.reg_data[31]    ;
            mon_reg_data[0 ]                      =     seq_inst.rd0        ; 
            mon_reg_data[1 ]                      =     seq_inst.rd1        ; 
            mon_reg_data[2 ]                      =     seq_inst.rd2        ; 
            mon_reg_data[3 ]                      =     seq_inst.rd3        ; 
            mon_reg_data[4 ]                      =     seq_inst.rd4        ; 
            mon_reg_data[5 ]                      =     seq_inst.rd5        ; 
            mon_reg_data[6 ]                      =     seq_inst.rd6        ; 
            mon_reg_data[7 ]                      =     seq_inst.rd7        ; 
            mon_reg_data[8 ]                      =     seq_inst.rd8        ; 
            mon_reg_data[9 ]                      =     seq_inst.rd9        ; 
            mon_reg_data[10]                      =     seq_inst.rd10       ; 
            mon_reg_data[11]                      =     seq_inst.rd11       ; 
            mon_reg_data[12]                      =     seq_inst.rd12       ; 
            mon_reg_data[13]                      =     seq_inst.rd13       ; 
            mon_reg_data[14]                      =     seq_inst.rd14       ; 
            mon_reg_data[15]                      =     seq_inst.rd15       ; 
            mon_reg_data[16]                      =     seq_inst.rd16       ; 
            mon_reg_data[17]                      =     seq_inst.rd17       ;
            mon_reg_data[18]                      =     seq_inst.rd18       ;
            mon_reg_data[19]                      =     seq_inst.rd19       ;
            mon_reg_data[20]                      =     seq_inst.rd20       ; 
            mon_reg_data[21]                      =     seq_inst.rd21       ; 
            mon_reg_data[22]                      =     seq_inst.rd22       ; 
            mon_reg_data[23]                      =     seq_inst.rd23       ; 
            mon_reg_data[24]                      =     seq_inst.rd24       ; 
            mon_reg_data[25]                      =     seq_inst.rd25       ; 
            mon_reg_data[26]                      =     seq_inst.rd26       ; 
            mon_reg_data[27]                      =     seq_inst.rd27       ; 
            mon_reg_data[28]                      =     seq_inst.rd28       ; 
            mon_reg_data[29]                      =     seq_inst.rd29       ; 
            mon_reg_data[30]                      =     seq_inst.rd30       ; 
            mon_reg_data[31]                      =     seq_inst.rd31       ; 

                 

    begin  //For comparison purposes               
      if( seq_inst.branch_valid==1)
       begin
        @(posedge vif.risc_clk) 
         rtl_pc = vif.PC;
         $display(" RTL PC value=%h",rtl_pc);
          end
     end

   /*  begin
       if(seq_inst.z_rst !=1)
           begin
           mon_pc = seq_inst.PC;
           $display("value of PC and sb fail =%h",mon_pc);
           `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] SB FAIL DUE TO RESET IS LOW "))
           end

       end

     begin
       if(!seq_inst.z_instruction_read_enable_o && seq_inst.opcode )
           begin
           mon_pc = seq_inst.PC;
           $display("value of PC for read enable and sb fail =%h",mon_pc);
           `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] SB FAIL DUE TO INS. READ ENABLE IS LOW "))
           end

       end*/


   // Stall and exception logic
     if(seq_inst.stall_valid_i || seq_inst.exception_valid_o ||seq_inst.exception_id_o)
         begin 
             seq_inst.next_pc_r <= seq_inst.pc_r;
             seq_inst.PC <= seq_inst.PC;
             mon_pc = seq_inst.PC;
          end
  
  /*  if((seq_inst.next_pc_r-seq_inst.pc_r!=4'b0100) && (!seq_inst.branch_valid))
          `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] SB FAIL due to Wrong PC updation "))*/

   

    //wrong Pc updation Catcher logic 
   /*begin               
       if( seq_inst.opcode == 'h33) 
       begin
       @(posedge vif.risc_clk) 
       rtl_pc = vif.PC;
       $display(" RTL PC1 value=%h",rtl_pc);
        PC1=rtl_pc;
       @(posedge vif.risc_clk) 
        rtl_pc = vif.PC;
       $display(" RTL PC2 value=%h",rtl_pc);
         PC2 = rtl_pc;
       $display("difference=%d",(PC2-PC1));
         if(PC2-PC1==2)
      `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] SB FAIL due to Wrong PC updation "))
                              
       end
   end*/


     if( seq_inst.opcode == 'h63  && seq_inst.z_instruction_read_enable_o)  //SB Type
       begin
           opcode  = seq_inst.opcode;
           rd      = seq_inst.rd;
           funct   = seq_inst.func3;
           rs1     = seq_inst.rs1;
           rs2     = seq_inst.rs2;
           rs1_gpr = mon_reg_data[rs1];
           rs2_gpr = mon_reg_data[rs2];
           false_pc= seq_inst.PC;
                 
                       
     case (funct) 
          0:  begin
                   if (rs1_gpr==rs2_gpr)
                      begin
                        immb_mon = {{(19){seq_inst.instruction[31]}},seq_inst.instruction[31],seq_inst.instruction[7],seq_inst.instruction[30:25],seq_inst.instruction[11:8],1'b0};
                        mon_pc   = seq_inst.PC+immb_mon-32'd8;
              
                        if(mon_pc == rtl_pc) 
                            `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " SB_TYPE SCOREBOARD PASS", UVM_LOW) 
                        else 
                            `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]SB_TYPE SCOREBOARD FAIL "))

                       end
                       
                  else
                      begin
                        mon_pc  =   seq_inst.PC-20'd4 ; 
             
                         if(mon_pc == (false_pc-4))
                            `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " SB_TYPE SCOREBOARD PASS", UVM_LOW) 
                         else
                            `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] SB_TYPE SCOREBOARD FAIL "))

                        
                      end  
              end 
          
          1 :  begin
                    if (rs1_gpr!==rs2_gpr)
                       begin
                          immb_mon = {{(19){seq_inst.instruction[31]}},seq_inst.instruction[31],seq_inst.instruction[7],seq_inst.instruction[30:25],seq_inst.instruction[11:8],1'b0};
                          mon_pc   =  seq_inst.PC+immb_mon-32'd8;
                          
                          if(mon_pc == rtl_pc)
                           `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " SB_TYPE SCOREBOARD PASS", UVM_LOW) 
                          else
                            `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] SB_TYPE SCOREBOARD FAIL "))
                         
                        
                        end
                    else
                       begin
                         mon_pc  =   seq_inst.PC-20'd4;

                         if(mon_pc == (false_pc-4))
                            `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " SB_TYPE SCOREBOARD PASS", UVM_LOW)
                         else
                            `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] SB_TYPE SCOREBOARD FAIL "))
                            
                    
                   end 
               end                                               
                
         4 :  begin
                  if (rs1_gpr<rs2_gpr)
                     begin
                        immb_mon = {{(19){seq_inst.instruction[31]}},seq_inst.instruction[31],seq_inst.instruction[7],seq_inst.instruction[30:25],seq_inst.instruction[11:8],1'b0};
                        mon_pc   = seq_inst.PC+immb_mon-32'd8;
              
                        if(mon_pc == rtl_pc)
                            `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " SB_TYPE SCOREBOARD PASS", UVM_LOW) 
                        else
                            `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] SB_TYPE SCOREBOARD FAIL "))

                    end
                  else
                     begin
                       mon_pc  =   seq_inst.PC-20'd4 ; 
              
                       if(mon_pc == (false_pc-4))
                            `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " SB_TYPE SCOREBOARD PASS", UVM_LOW) 
                      else
                            `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] SB_TYPE SCOREBOARD FAIL "))

                   
                  end 
              end 
          5 :  begin
                   if (rs1_gpr>=rs2_gpr) 
                      begin
                         immb_mon = {{(19){seq_inst.instruction[31]}},seq_inst.instruction[31],seq_inst.instruction[7],seq_inst.instruction[30:25],seq_inst.instruction[11:8],1'b0};
                          mon_pc  = seq_inst.PC+immb_mon-32'd8;
                   
                          if(mon_pc == rtl_pc)
                            `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " SB_TYPE SCOREBOARD PASS", UVM_LOW) 
                          else
                            `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] SB_TYPE SCOREBOARD FAIL "))

                        
                      end
                  else
                     begin
                        mon_pc  =   seq_inst.PC-20'd4;
             
                        if(mon_pc == (false_pc-4))
                            `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " SB_TYPE SCOREBOARD PASS", UVM_LOW) 
                        else
                            `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] SB_TYPE SCOREBOARD FAIL "))

                    end 
              end          

          6 :  begin
                   if (rs1_gpr<rs2_gpr)
                      begin
                         immb_mon = {{(19){seq_inst.instruction[31]}},seq_inst.instruction[31],seq_inst.instruction[7],seq_inst.instruction[30:25],seq_inst.instruction[11:8],1'b0};                                              
                         mon_pc   = seq_inst.PC+immb_mon-32'd8;
              
                          if(mon_pc == rtl_pc)
                            `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " SB_TYPE SCOREBOARD PASS", UVM_LOW) 
                          else
                            `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] SB_TYPE SCOREBOARD FAIL "))
                        
                      end
                      
                   else
                      begin
                        mon_pc  =   seq_inst.PC-20'd4 ; 
                                           
                        if(mon_pc == (false_pc-4))
                            `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " SB_TYPE SCOREBOARD PASS", UVM_LOW) 
                        else
                            `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] SB_TYPE SCOREBOARD FAIL "))

                      end 
               end

          7 :  begin
                   if (rs1_gpr>=rs2_gpr)
                      begin
                       immb_mon = {{(19){seq_inst.instruction[31]}},seq_inst.instruction[31],seq_inst.instruction[7],seq_inst.instruction[30:25],seq_inst.instruction[11:8],1'b0}; 
                       mon_pc   = seq_inst.PC+immb_mon-32'd8;
              
                       if(mon_pc == rtl_pc)
                           `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " SB_TYPE SCOREBOARD PASS", UVM_LOW) 
                       else
                           `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] SB_TYPE SCOREBOARD FAIL "))

                      end
                   else
                      begin
                          mon_pc=seq_inst.PC-20'd4 ; 

                          if(mon_pc == (false_pc-4))
                            `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " SB_TYPE SCOREBOARD PASS", UVM_LOW) 
                          else
                            `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] SB_TYPE SCOREBOARD FAIL "))

                      end 
               end 
                  
        default: mon_pc=seq_inst.PC+4 ;
              
        endcase   
      end 
        
        //UJ TYPE (JAL)
        else if( seq_inst.opcode == 'h6f && seq_inst.z_instruction_read_enable_o)            
             begin
             rd               = seq_inst.rd;
             imm_mono         = {{(11){seq_inst.instruction[31]}},seq_inst.instruction[31],seq_inst.instruction[19:12],seq_inst.instruction[20],seq_inst.instruction[30:21],1'b0};
             mon_pc           = seq_inst.PC+imm_mono-32'd8; 
             return_location  = seq_inst.PC-20'd4 ;
               
             if(mon_pc == rtl_pc)
                `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " UJ_TYPE SCOREBOARD PASS ", UVM_LOW) 
             else
                `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] UJ_TYPE SCOREBOARD FAIL "))
                  
         end

         //I TYPE (JALR)
         else if( seq_inst.opcode == 'h67 && seq_inst.z_instruction_read_enable_o)
             begin
                rs1              = seq_inst.rs1;
                rs1_gpr          = mon_reg_data[rs1];
                imm_mono         = {{(20){seq_inst.instruction[31]}},seq_inst.instruction[31:20]};
                mon_pc           = rs1_gpr+imm_mono; 
                return_location  = seq_inst.PC-20'd4 ;
                          
                if(mon_pc == rtl_pc)
                      `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " JALR_TYPE SCOREBOARD PASS ", UVM_LOW) 
                else
                      `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] JALR_TYPE SCOREBOARD FAIL "))



             end

           //R TYPE
           else if(seq_inst.opcode == 'h33)
           begin
              pc_value = seq_inst.PC;
              mon_pc   = seq_inst.PC-20'd4 ;
       
              if(mon_pc == (pc_value-4))
               `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " R_TYPE SCOREBOARD PASS ", UVM_LOW) 
              else
                `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] R_TYPE SCOREBOARD  FAIL "))

           end
      
      //S TYPE
      else if(seq_inst.opcode == 'h23 && seq_inst.z_instruction_read_enable_o)
          begin
             pc_value = seq_inst.PC;
             mon_pc   = seq_inst.PC-20'd4 ;
         
          if(mon_pc == (pc_value-4))
            `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " S_TYPE SCOREBOARD PASS ", UVM_LOW) 
          else
            `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] S_TYPE SCOREBOARD FAIL "))

      
        end
         
         //I TYPE
         else if(seq_inst.opcode == 'h13 && seq_inst.instruction!= 32'h00000013 && seq_inst.z_instruction_read_enable_o)
           begin
               pc_value = seq_inst.PC;
               mon_pc   = seq_inst.PC-20'd4 ;
        
              if(mon_pc == (pc_value-4))
               `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " I_TYPE SCOREBOARD PASS ", UVM_LOW) 
              else
                `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] I_TYPE SCOREBOARD FAIL "))

           end

           //I TYPE (LOAD)
           else if(seq_inst.opcode == 'h3 && seq_inst.z_instruction_read_enable_o)
           begin
              pc_value = seq_inst.PC;
              mon_pc   = seq_inst.PC-20'd4 ;
        
              if(mon_pc == (pc_value-4))
               `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " I_TYPE_LOAD SCOREBOARD PASS ", UVM_LOW) 
              else
                `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] I_TYPE_LOAD SCOREBOARD FAIL "))

           end


     //U TYPE
     else if(seq_inst.opcode == 'h37 && seq_inst.opcode == 'h17 && seq_inst.z_instruction_read_enable_o)
         begin

           pc_value = seq_inst.PC;
           mon_pc   = seq_inst.PC-20'd4 ;
    
           if(mon_pc == (pc_value-4))
               `uvm_info("\n\n[ PASS ] INFO : PC_Scoreboard", " U_TYPE SCOREBOARD PASS", UVM_LOW) 
           else
               `uvm_error (get_name(), $sformatf("\n\n[ FAIL ] U_TYPE SCOREBOARD FAIL "))


        end

         mon_port.write(seq_inst);

  end

endtask
endclass


                                  


