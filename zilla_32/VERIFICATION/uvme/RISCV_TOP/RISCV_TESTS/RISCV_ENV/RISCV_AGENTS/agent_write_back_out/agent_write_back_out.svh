class agent_write_back_out extends uvm_agent;

// factory registration
    `uvm_component_utils(agent_write_back_out)

   // Instances
         monitor_write_back_out   wb_monitor_inst   ;
 

// Constructor
    function new (string name = "agent_write_back_out",uvm_component parent);
        super.new(name,parent);
    endfunction

    //Build phase
    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
       wb_monitor_inst = monitor_write_back_out::type_id::create("wb_monitor_inst",this) ;

    endfunction









    endclass








