class agent_interrupt extends uvm_agent;

// factory registration
    `uvm_component_utils(agent_interrupt)

    

// Constructor
    function new (string name = "agent_interrupt",uvm_component parent);
        super.new(name,parent);
    endfunction

    //Build phase
    function void build_phase(uvm_phase phase);
        super.build_phase(phase);

    endfunction
endclass

