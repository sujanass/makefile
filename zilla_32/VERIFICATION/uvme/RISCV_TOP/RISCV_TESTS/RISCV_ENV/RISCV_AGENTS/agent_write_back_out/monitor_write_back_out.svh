
class monitor_write_back_out extends uvm_monitor;


//Factory registration
    `uvm_component_utils( monitor_write_back_out)

    //Virtual interface
    virtual riscv_intf vif;


    virtual write_back_interface wb_vif;


    //Seq_item Instantiation
    seq_item_wb_out seq_inst;


  static  int m_num_tx_mon ;

//TLM FIFO sender class
    uvm_blocking_put_port #(seq_item_wb_out) mon_cont;
    uvm_analysis_port #(seq_item_wb_out) port_cov_wb_sq; // coverage for writeback sequence item
  


    //Constructor
    function new(string name ="monitor_write_back_out", uvm_component parent);
        super.new(name, parent);

    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);


       mon_cont = new("mon_cont", this);
    port_cov_wb_sq     = new("port_cov_wb_sq", this); 


        //uvm_config db 
        if(!uvm_config_db#(virtual riscv_intf)::get(this,"*","riscv_intf", vif))
            `uvm_fatal(get_name(), "Monitor: VIF NOT FOUND")

        
        if(!uvm_config_db#(virtual write_back_interface)::get(this,"*","write_back_interface", wb_vif))
            `uvm_fatal(get_name(), "Monitor: VIF NOT FOUND")
        
        
      endfunction

        virtual task run_phase(uvm_phase phase);
        super.run_phase(phase);
        forever
          begin
              repeat(m_num_tx_mon)
            begin 
         @(posedge vif.risc_clk)
        //  fork
         // begin

      //sequence_item construction
        seq_inst = seq_item_wb_out::type_id::create("seq_inst");

            seq_inst.instruction                =     vif.instruction;       
            seq_inst.opcode                     =     vif.opcode;
            seq_inst.func3                      =     vif.func3;
            seq_inst.func7                      =     vif.func7;
            seq_inst.imm                        =     vif.imm;   
            seq_inst.rs1                        =     vif.rs1;  
            seq_inst.rs2                        =     vif.rs2;  
            seq_inst.rd                         =     vif.rd;  
            seq_inst.pc                         =     vif.pc; 
            seq_inst.forward_a                  =     wb_vif.forward_a;
            seq_inst.forward_b                  =     wb_vif.forward_b;
            seq_inst.alu_out                    =     wb_vif.alu_out;


            seq_inst.rd0                          =     vif.reg_data[0] ;  
            seq_inst.rd1                          =     vif.reg_data[1] ;  
            seq_inst.rd2                          =     vif.reg_data[2] ;  
            seq_inst.rd3                          =     vif.reg_data[3] ;  
            seq_inst.rd4                          =     vif.reg_data[4] ;  
            seq_inst.rd5                          =     vif.reg_data[5] ;  
            seq_inst.rd6                          =     vif.reg_data[6] ;  
            seq_inst.rd7                          =     vif.reg_data[7] ;  
            seq_inst.rd8                          =     vif.reg_data[8] ;  
            seq_inst.rd9                          =     vif.reg_data[9] ;  
            seq_inst.rd10                         =     vif.reg_data[10];  
            seq_inst.rd11                         =     vif.reg_data[11];  
            seq_inst.rd12                         =     vif.reg_data[12];  
            seq_inst.rd13                         =     vif.reg_data[13];  
            seq_inst.rd14                         =     vif.reg_data[14];  
            seq_inst.rd15                         =     vif.reg_data[15];  
            seq_inst.rd16                         =     vif.reg_data[16];  
            seq_inst.rd17                         =     vif.reg_data[17];  
            seq_inst.rd18                         =     vif.reg_data[18];  
            seq_inst.rd19                         =     vif.reg_data[19];  
            seq_inst.rd20                         =     vif.reg_data[20];  
            seq_inst.rd21                         =     vif.reg_data[21];  
            seq_inst.rd22                         =     vif.reg_data[22];  
            seq_inst.rd23                         =     vif.reg_data[23];  
            seq_inst.rd24                         =     vif.reg_data[24];  
            seq_inst.rd25                         =     vif.reg_data[25];  
            seq_inst.rd26                         =     vif.reg_data[26];  
            seq_inst.rd27                         =     vif.reg_data[27];  
            seq_inst.rd28                         =     vif.reg_data[28];  
            seq_inst.rd29                         =     vif.reg_data[29];  
            seq_inst.rd30                         =     vif.reg_data[30];  
            seq_inst.rd31                         =     vif.reg_data[31];
             
        
            seq_inst.data_in_1                      =   wb_vif.data_in_1                              ;
            seq_inst.data_in_2                      =   wb_vif.data_in_2                              ; 
            seq_inst.data_out                       =   wb_vif.data_out                               ;            
            seq_inst.sub_en                         =   wb_vif.sub_en                                 ;
            seq_inst.add_en                         =   wb_vif.add_en                                 ;
            seq_inst.sll_en                         =   wb_vif.sll_en                                 ;
            seq_inst.slt_en                         =   wb_vif.slt_en                                 ;
            seq_inst.xor_en                         =   wb_vif.xor_en                                 ;
            seq_inst.srl_en                         =   wb_vif.srl_en                                 ;
            seq_inst.sra_en                         =   wb_vif.sra_en                                 ;
            seq_inst.or_en                          =   wb_vif.or_en                                  ;
            seq_inst.and_en                         =   wb_vif.and_en                                 ;
            seq_inst.jalr_en                        =   wb_vif.jalr_en                                ;
            seq_inst.jal_en                         =   wb_vif.jal_en                                 ;
            seq_inst.lui_en                         =   wb_vif.lui_en                                 ;
            seq_inst.wr_data_en                     =   wb_vif.wr_data_en                       ;
            seq_inst.in1                            =   wb_vif.in1                                      ;
            seq_inst.in2                            =   wb_vif.in2                                      ;
            seq_inst.sel                            =   wb_vif.sel                                      ;

               seq_inst.out     =     wb_vif.out;


             mon_cont.put(seq_inst); //writing
             port_cov_wb_sq.write(seq_inst); //coverage
             
             end
           //  join
         //  end

end


    endtask

    endclass



