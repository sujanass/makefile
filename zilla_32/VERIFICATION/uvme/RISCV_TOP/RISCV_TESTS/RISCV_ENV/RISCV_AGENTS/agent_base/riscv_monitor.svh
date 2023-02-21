class riscv_monitor extends uvm_monitor;


//Factory registration
    `uvm_component_utils(riscv_monitor)

//Virtual interface
    virtual riscv_intf vif;

//seq_item instantiation
    riscv_seq_item sq_i;
    im_seq_item sq_im;

//Analysis port instantiation
    uvm_analysis_port #(riscv_seq_item) mon_rv;

//Constructor
    function new(string name ="riscv_monitor", uvm_component parent);
        super.new(name, parent);
    endfunction

//Build phase
    function void build_phase(uvm_phase phase);
        super.build_phase(phase);

//Analisis port construction
        mon_rv = new("mon_rv", this);

//uvm_config db 
        if(!uvm_config_db#(virtual jtag_intf)::get(this,"*","riscv_intf", vif))
            `uvm_fatal(get_name(), "Monitor: VIF NOT FOUND")

//sequence_item construction
        sq_i = riscv_seq_item::type_id::create("sq_i");

    endfunction

//Run phase
    virtual task run_phase(uvm_phase phase);
        super.run_phase(phase);
        
        forever begin
//Sampling at posedge of clock
                    @(vif.im_clk);

//Assigning data from interface to sequence item - sw clock
//inputs
                    sq_i.trst                       <= vif.trst;           
                    sq_i.tms                        <= vif.tms;                                
                    sq_i.tdi                        <= vif.tdi;            
                    sq_i.dmi_data_in                <= vif.dmi_data_in;                  
                    sq_i.tdo                        <= vif.tdo;            
                    sq_i.tdo_en                     <= vif.tdo_en;             
                    sq_i.dr_scan                    <= vif.dr_scan;        
                    sq_i.dmi_data_out               <= vif.dmi_data_out;   
                    sq_i.dmi_address_out            <= vif.dmi_address_out;
                    sq_i.dmi_op_out                 <= vif.dmi_op_out;     
                    sq_i.dmi_transfer               <= vif.dmi_transfer;
                    

//Writing to analysis port from sequence_item
                    mon_ap.write(sq_i);


            end

    endtask

endclass

