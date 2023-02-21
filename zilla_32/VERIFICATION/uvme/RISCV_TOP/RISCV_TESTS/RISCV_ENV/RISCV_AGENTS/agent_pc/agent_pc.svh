class agent_pc extends uvm_agent;

// factory registration
    `uvm_component_utils( agent_pc)

//Instantiations
            
        //Virtual interface instantiation
        virtual riscv_intf vif;


       //decode monitor instantiation
       monitor_pc  p_mon;
    

// Constructor
    function new (string name = " agent_pc",uvm_component parent);
        super.new(name,parent);
    endfunction

    //Build phase
    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        p_mon  = monitor_pc::type_id::create("p_mon", this);

    endfunction
endclass

