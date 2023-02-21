class seq_item_ldst extends uvm_sequence_item;
    
    logic [31:0]   z_im_read_data_i;
    logic [19:0] PC;
    logic [31:0] reg_data[0:31];//array to load an gpr 
    logic [31:0]    z_instruction_o;
    logic [31:0] de_ld_sd_addr_o;

    logic load_valid_out;
    logic store_valid_out;
    logic reg_wr_en;
    logic [4:0] reg_wr_addr;
    logic [31:0] reg_wr_data;
    logic sign_bit;
    logic [1:0] byte_sel_o;
    logic data_mem_write_en_to_stall;
    logic [11:0] alu_ctrl;
    logic [1:0] forward_a;
    logic [3:0] byte_en;

     
    //Data memory signals
    logic [31:0]           data_mem_read_data_i  ;
    logic                       data_mem_write_en_o   ;
    logic [31:0]           data_mem_write_data_o ;
    logic [31:0]           data_mem_write_addr_o ;
    logic [(32>>3)-1:0]      data_mem_strobe_o     ;
    logic                       data_mem_read_en_o    ;  
    logic [31:0]           data_mem_read_addr_o  ; 

    //Internal signals

     logic [31:0] instruction;
     logic [6:0]  opcode;
     logic [2:0]  func3;
     logic [31:0] imm;
     logic [4:0]  rs1;
     logic [4:0]  rs2;
     logic [4:0]  rd;

    `uvm_object_utils_begin(seq_item_ldst)
    `uvm_field_int(PC,UVM_ALL_ON)
    
    `uvm_field_int(data_mem_read_data_i,UVM_ALL_ON)
    `uvm_field_int(data_mem_write_en_o,UVM_ALL_ON)
    `uvm_field_int(data_mem_write_data_o,UVM_ALL_ON)
    `uvm_field_int(data_mem_write_addr_o,UVM_ALL_ON)
    `uvm_field_int(data_mem_strobe_o,UVM_ALL_ON)
    `uvm_field_int(data_mem_read_en_o,UVM_ALL_ON)
    `uvm_field_int(data_mem_read_addr_o,UVM_ALL_ON)
    
    `uvm_field_int(instruction,UVM_ALL_ON)
    `uvm_field_int(opcode,UVM_ALL_ON)
    `uvm_field_int(func3,UVM_ALL_ON)
    `uvm_field_int(imm,UVM_ALL_ON)
    `uvm_field_int(rs1,UVM_ALL_ON)
    `uvm_field_int(rs2,UVM_ALL_ON)
    `uvm_field_int(rd,UVM_ALL_ON)
    
    `uvm_field_int(z_instruction_o,UVM_ALL_ON)
    `uvm_field_int(de_ld_sd_addr_o,UVM_ALL_ON)
     `uvm_object_utils_end

 //constructor 
    function new(string name = "seq_item_ldst");
        super.new(name);
    endfunction
    
endclass
