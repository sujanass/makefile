class agent_ldst_out extends uvm_agent;

// factory registration
    `uvm_component_utils(agent_ldst_out)

    // Monitor Instantiation
    ldst_out_monitor monitor_inst;


// Constructor
    function new (string name = "agent_ldst_out", uvm_component parent);
        super.new(name,parent);
    endfunction

    //Build phase
    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        monitor_inst = ldst_out_monitor::type_id::create("ldst_out_monitor",this);
    endfunction
endclass

