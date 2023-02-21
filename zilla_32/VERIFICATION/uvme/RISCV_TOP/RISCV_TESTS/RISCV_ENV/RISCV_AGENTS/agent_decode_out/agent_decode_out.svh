class agent_decode_out extends uvm_agent;

// factory registration
    `uvm_component_utils( agent_decode_out)

//Instantiations
            
        //Virtual interface instantiation
        virtual riscv_intf vif;


       //decode monitor instantiation
       decode_mon  dcd_mon;
    

// Constructor
    function new (string name = " agent_decode_out",uvm_component parent);
        super.new(name,parent);
    endfunction

    //Build phase
    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
       // dcd_seqr = decode_sequencer::type_id::create("dcd_seqr" , this);
        dcd_mon  = decode_mon::type_id::create("dcd_mon", this);

    endfunction
endclass

