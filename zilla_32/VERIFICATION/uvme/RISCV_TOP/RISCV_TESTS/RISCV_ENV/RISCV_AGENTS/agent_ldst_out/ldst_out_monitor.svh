class ldst_out_monitor extends uvm_monitor;
    //Factory registration
    `uvm_component_utils(ldst_out_monitor)

    //Virtual interface
    virtual riscv_intf vif;
    
    virtual ldst_out_intf lvif;
   
    agent_dm dm_agent;
    
    static int m_num_tx_mon = 2;

    
    logic [31:0] reg_data [31:0];

        
     bit [4:0]  sb_rs1;
     bit [4:0]  sb_rs2;
     bit [4:0]  sb_rd;
     bit [31:0] sb_imm;
     bit [31:0] sb_read_addr;
     bit [31:0] sb_write_addr;
     
     
    //Seq_item Instantiation
    seq_item_ldst seq_r;

    //TLM FIFO sender class
    uvm_blocking_put_port #(seq_item_ldst) mon_cont;
        
    //Analysis Port
    uvm_analysis_port #(seq_item_ldst) item_collected_port; 

    //Constructor
    function new(string name ="ls_type_monitor", uvm_component parent);
        super.new(name, parent);
        item_collected_port = new("item_collected_port", this);
    endfunction
   
   //Build phase
    function void build_phase(uvm_phase phase);
        super.build_phase(phase);

        //Analisis port construction
        mon_cont = new("mon_cont", this);

        //uvm_config db 
        if(!uvm_config_db#(virtual riscv_intf)::get(this,"*","riscv_intf", vif))
            `uvm_fatal(get_name(), "Monitor: VIF NOT FOUND")

       //uvm_config db 
        if(!uvm_config_db#(virtual ldst_out_intf)::get(this,"*","ldst_out_intf", lvif))
            `uvm_fatal(get_name(), "Monitor: VIF NOT FOUND")
 
        if(!uvm_config_db#(agent_dm)::get(null,"uvm_test_top.env_i","DM_AGENT",dm_agent))
            `uvm_fatal("NO CONFIGURATION",{"configuration instance must be set for: ",get_full_name(),".dm_agent"});

 
        //sequence_item construction
        seq_r = seq_item_ldst::type_id::create("seq_r");

    endfunction
  
   
    //run phase
    virtual task run_phase(uvm_phase phase);
        super.run_phase(phase);
        phase.raise_objection(this);
        
        repeat(m_num_tx_mon)
        begin
            //exec_done = 0;            
           // mem_stage_done = 0;          
          @(vif.risc_clk)
          begin
           //  fork

        ///Decode Stage packets
               // begin 
                    seq_r.PC                         =     lvif.PC;
                    seq_r.instruction                =     vif.instruction;
                    seq_r.opcode                     =     vif.opcode;
                    seq_r.func3                      =     vif.func3;
                    seq_r.imm                        =     vif.imm;
                    seq_r.rs1                        =     vif.rs1;
                    seq_r.rs2                        =     vif.rs2;
                    seq_r.rd                         =     vif.rd;
                    seq_r.z_instruction_o            =     lvif.z_instruction_o;
                    seq_r.reg_data                   =     vif.reg_data;
                    seq_r.de_ld_sd_addr_o            =     lvif.de_ld_sd_addr_o;
                    seq_r.data_mem_read_en_o         =     vif.data_mem_read_en_o;
                    seq_r.data_mem_read_data_i       =     vif.data_mem_read_data_i;
                    seq_r.data_mem_read_addr_o       =     vif.data_mem_read_addr_o;
                    seq_r.data_mem_write_en_o        =     vif.data_mem_write_en_o;
                    seq_r.data_mem_write_addr_o      =     vif.data_mem_write_addr_o;
                    seq_r.data_mem_write_data_o      =     vif.data_mem_write_data_o;
                    seq_r.data_mem_strobe_o          =     vif.data_mem_strobe_o;
                    seq_r.load_valid_out             =     lvif.load_valid_out;
                    seq_r.store_valid_out            =     lvif.store_valid_out;
                    seq_r.reg_wr_en                  =     lvif.reg_wr_en;
                    seq_r.reg_wr_addr                =     lvif.reg_wr_addr;
                    seq_r.reg_wr_data                =     lvif.reg_wr_data;
                    seq_r.sign_bit                   =     lvif.sign_bit;
                    seq_r.byte_sel_o                 =     lvif.byte_sel_o;
                    seq_r.data_mem_write_en_to_stall =     lvif.data_mem_write_en_to_stall;
                    seq_r.alu_ctrl                   =     lvif.alu_ctrl;
                    seq_r.forward_a                  =     lvif.forward_a;
                    seq_r.byte_en                    =     lvif.byte_en;

                   
                    //$display("The write enable is %0d and Read enable is %0d", seq_r.data_mem_write_en_o,seq_r.data_mem_read_en_o );
              end

             //always @(posedge vif.risc_clk)
               /* begin
                    foreach(lvif.reg_data[i])
                        begin
                           seq_r.reg_data[i] = lvif.reg_data[i];
                           // lvif.reg_data[i] = DUT.reg_file_inst.dp_ram_inst.regfile[i];
                            `uvm_info("INSIDE MONITOR",$sformatf("The value is %0h and PC is %0h", lvif.reg_data[i],lvif.PC),UVM_NONE);
                        end
                end*/
             
               if(seq_r.opcode == 'h03)
                  begin
                    $display("PC = %h",seq_r.PC);
                    sb_rs1 = seq_r.z_instruction_o[19:15];
                    sb_rd  = seq_r.z_instruction_o[11:7];
                    sb_imm = {{(20){seq_r.z_instruction_o[31]}},seq_r.z_instruction_o[31:20]};
                    sb_imm = $signed(sb_imm);
                    $display("RS1=%h RD=%h IMM=%h reg[sb_rs1]=%h",sb_rs1,sb_rd,sb_imm,seq_r.reg_data[sb_rs1]);
                    sb_read_addr = seq_r.reg_data[sb_rs1] + sb_imm;

                    if(seq_r.func3 == 3'b000)  //LB
                        begin
                          seq_r.reg_data[sb_rd] = dm_agent.data_mem[sb_read_addr];
                          $display("LB");
                        end
                     
                    else if(seq_r.func3 == 3'b001) //LHW
                        begin
                           seq_r.reg_data[sb_rd] = {dm_agent.data_mem[sb_read_addr+1],dm_agent.data_mem[sb_read_addr]};
                          $display("LHW");
                        end
                    else if(seq_r.func3 == 3'b010) //LW
                        begin
                            seq_r.reg_data[sb_rd] = {dm_agent.data_mem[sb_read_addr+3],dm_agent.data_mem[sb_read_addr+2],dm_agent.data_mem[sb_read_addr+1],dm_agent.data_mem[sb_read_addr]};
                          $display("LW");
                        end
                   
                    else if(seq_r.func3 == 3'b100) //LBU
                        begin
                           seq_r.reg_data[sb_rd] = $unsigned(dm_agent.data_mem[sb_read_addr]);
                          $display("LBU");
                        end
                   
                   else if(seq_r.func3 == 3'b101)  //LHWU
                        begin
                           seq_r.reg_data[sb_rd] = $unsigned({dm_agent.data_mem[sb_read_addr+1],dm_agent.data_mem[sb_read_addr]});
                          $display("LHWU");
                        end

                    else if(seq_r.func3 == 3'b110) //LWU
                        begin
                            seq_r.reg_data[sb_rd] = $unsigned({dm_agent.data_mem[sb_read_addr+3],dm_agent.data_mem[sb_read_addr+2],dm_agent.data_mem[sb_read_addr+1],dm_agent.data_mem[sb_read_addr]});
                          $display("LWU");
                        end
                    
                   
                   // $display("READ ADDR = %h, READ DATA = %h",sb_read_addr,seq_r.reg_data[sb_rd]);
                    //$display("RD REG = %h",seq_r.reg_data[seq_r.rd]);
                   begin
                     if(seq_r.reg_data[sb_rd] == seq_r.reg_data[seq_r.rd])
                     begin
                     `uvm_info(get_type_name(),$sformatf("\n DATA PASS seq_r.reg_data[sb_rd] = %h seq_r.reg_data[seq_r.rd]=%h tim:e =%dns",seq_r.reg_data[sb_rd],seq_r.reg_data[seq_r.rd],$time),UVM_NONE)
                     end
                     else 
                         begin
                       `uvm_error(get_type_name(),$sformatf("\n DATA FAILseq_r.reg_data[sb_rd] = %h seq_r.reg_data[seq_r.rd]=%h time =%dns",seq_r.reg_data[sb_rd],seq_r.reg_data[seq_r.rd],$time))
                   end
                   end
                     

                   /* if(sb_read_addr == seq_r.de_ld_sd_addr_o)
                       begin
                     `uvm_info(get_type_name(),$sformatf("\n ADDRESS PASS sb_read_addr = %h seq_r.de_ld_sd_addr_o=%h time =%dns",sb_read_addr,seq_r.de_ld_sd_addr_o,$time),UVM_HIGH)
                     end
                     else 
                         begin
                       `uvm_error(get_type_name(),$sformatf("\n ADDRESS FAIL sb_read_addr = %h seq_r.de_ld_sd_addr_o=%h time =%dns",sb_read_addr,seq_r.de_ld_sd_addr_o,$time))
                   end*/
                  
            end

             else if(seq_r.opcode == 'h23)
                   begin
                    seq_r.PC = seq_r.PC + 4;
                    $display("PC = %h",seq_r.PC);
                    sb_rs1 = seq_r.z_instruction_o[19:15];
                    sb_rs2 = seq_r.z_instruction_o[24:20];
                    sb_imm = {{(20){seq_r.z_instruction_o[31]}},seq_r.z_instruction_o[31:25],seq_r.z_instruction_o[11:7]};
                    sb_imm = $signed(sb_imm);
                    $display("RS1=%h IMM=%h REG[rs1]=%h REG[rs2]=%h",sb_rs1,sb_imm,seq_r.reg_data[sb_rs1],seq_r.reg_data[sb_rs2]);
                    sb_write_addr = seq_r.reg_data[sb_rs1] + sb_imm;
                    $display("WRITE ADDR = %h",sb_write_addr);
                    foreach(seq_r.reg_data[i])
                        begin
                            $display("Reg data of %0h = %0h",i, seq_r.reg_data[i]);
                        end
                     if(seq_r.func3 == 3'b000)  //SB
                        begin
                          dm_agent.data_mem[sb_write_addr] = seq_r.reg_data[sb_rs2][7:0];
                           //begin
                           if(dm_agent.data_mem[sb_write_addr] == seq_r.reg_data[seq_r.rs1][7:0])
                     begin
                     `uvm_info(get_type_name(),$sformatf("\n DATA PASS SB dm_agent.data_mem[sb_write_addr] = %h seq_r.reg_data[seq_r.rs1]=%h time =%dns",dm_agent.data_mem[sb_write_addr],seq_r.reg_data[seq_r.rs1][7:0],$time),UVM_NONE)
                     end
                     else 
                         begin
                       `uvm_error(get_type_name(),$sformatf("\n DATA FAIL SB dm_agent.data_mem[sb_write_addr] = %h seq_r.reg_data[seq_r.rs1]=%h time =%dns",dm_agent.data_mem[sb_write_addr],seq_r.reg_data[seq_r.rs1][7:0],$time))
                   end
                   //end

                        end
                    else if(seq_r.func3 == 3'b001) //SHW
                        for(int i=0;i<2;i++)
                        begin
                          dm_agent.data_mem[sb_write_addr+i] = seq_r.reg_data[sb_rs2][(8*i)+:8];
                           //begin
                           if(dm_agent.data_mem[sb_write_addr+i] == seq_r.reg_data[seq_r.rs1+i][(8*i)+:8])
                            begin
                     `uvm_info(get_type_name(),$sformatf("\n DATA PASS SHW dm_agent.data_mem[sb_write_addr+i] = %h seq_r.reg_data[seq_r.rs1+i]=%h time =%dns",dm_agent.data_mem[sb_write_addr+i],seq_r.reg_data[seq_r.rs1][(8*i)+:8],$time),UVM_NONE)
                     end
                     else 
                         begin
                       `uvm_error(get_type_name(),$sformatf("\n DATA FAIL SHW dm_agent.data_mem[sb_write_addr+i] = %h seq_r.reg_data[seq_r.rs1+i]=%h time =%dns",dm_agent.data_mem[sb_write_addr+i],seq_r.reg_data[seq_r.rs1][(8*i)+:8],$time))
                   end
                   //end

                        end
                    else if(seq_r.func3 == 3'b010) //SW
                       for(int i=0;i<4;i++)
                       begin
                         dm_agent.data_mem[sb_write_addr+i] = seq_r.reg_data[sb_rs2][(8*i)+:8];
                          //begin
                           if(dm_agent.data_mem[sb_write_addr+i] == seq_r.reg_data[seq_r.rs1][(8*i)+:8])
                            begin
                     `uvm_info(get_type_name(),$sformatf("\n DATA PASS SW dm_agent.data_mem[sb_write_addr+i] = %h seq_r.reg_data[seq_r.rs1]=%h time =%dns",dm_agent.data_mem[sb_write_addr+i],seq_r.reg_data[seq_r.rs1][(8*i)+:8],$time),UVM_NONE)
                     end
                     else 
                         begin
                       `uvm_error(get_type_name(),$sformatf("\n DATA FAIL SW dm_agent.data_mem[sb_write_addr+i] = %h seq_r.reg_data[seq_r.rs1+i]=%h time =%dns",dm_agent.data_mem[sb_write_addr+i],seq_r.reg_data[seq_r.rs1][(8*i)+:8],$time))
                   end
                   //end

                       end
                       
                                    //end
                  end
            item_collected_port.write(seq_r); 
            mon_cont.put(seq_r); //writing
            end
            phase.drop_objection(this);
    endtask

    
endclass
