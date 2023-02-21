class pc_seq_item extends uvm_sequence_item;
    
                logic [31:0] instruction;
                logic [6:0]  opcode;
                logic [2:0]  func3;
                logic [6:0]  func7;
                logic [31:0] imm;
                logic [4:0]  rs1;
                logic [4:0]  rs2;
                logic [4:0]  rd;
                logic [19:0] PC;
                logic [19:0] PC_REF;
                logic branch_valid;
                logic z_rst;
                logic z_instruction_read_enable_o;

                logic [19:0] instr_read_addr_o; 
                logic [31:0] z_instruction_o;
                logic 	     exception_valid_o;		    
                logic [7:0]  exception_id_o;			    
                logic	     interrupt_valid_o;		    
                logic	     exception_id_write_valid_o;	
                logic        interrupt_id_write_valid_o;	
                logic 		 ld_sd_misalign_valid_o;  	
                logic [31:0] ld_sd_misalign_addr_o;		
                logic 		 instr_misalign_valid_o;  	
                logic [19:0] instr_misalign_addr_o;		
                logic 	     invalid_instr_valid_o;		
                logic        decode_instruction_valid_o;  
                logic        trap_valid_o; 
                logic 		 z_instruction_valid_i;
                logic 		 stall_valid_i;
                logic 	 	 branch_valid_i;
               // logic [19:0] instr_read_addr_o; 
               // logic 	     z_instruction_read_enable_o;
                logic        read_write_ptr_valid;
                logic [19:0] pc_r ;
                logic [19:0] next_pc_r;
  

                // for reg data  mapping is like reg_data[0] => rd0
                logic [31:0] rd0;
                logic [31:0] rd1;
                logic [31:0] rd2;
                logic [31:0] rd3;
                logic [31:0] rd4;
                logic [31:0] rd5;
                logic [31:0] rd6;
                logic [31:0] rd7;
                logic [31:0] rd8;
                logic [31:0] rd9;
                logic [31:0] rd10;
                logic [31:0] rd11;
                logic [31:0] rd12;
                logic [31:0] rd13;
                logic [31:0] rd14;
                logic [31:0] rd15;
                logic [31:0] rd16;
                logic [31:0] rd17;
                logic [31:0] rd18;
                logic [31:0] rd19;
                logic [31:0] rd20;
                logic [31:0] rd21;
                logic [31:0] rd22;
                logic [31:0] rd23;
                logic [31:0] rd24;
                logic [31:0] rd25;
                logic [31:0] rd26;
                logic [31:0] rd27;
                logic [31:0] rd28;
                logic [31:0] rd29;
                logic [31:0] rd30;
                logic [31:0] rd31;

             
                



    `uvm_object_utils_begin(pc_seq_item)
   
  // `uvm_field_int( instruction,UVM_ALL_ON)
    `uvm_field_int(instruction,UVM_ALL_ON)
    `uvm_field_int( opcode,UVM_ALL_ON)
    `uvm_field_int(func3,UVM_ALL_ON)
    `uvm_field_int(func7,UVM_ALL_ON)
    `uvm_field_int(imm,UVM_ALL_ON)
    `uvm_field_int(rs1,UVM_ALL_ON)
    `uvm_field_int(rs2,UVM_ALL_ON)
    `uvm_field_int(rd,UVM_ALL_ON)
    `uvm_field_int(PC,UVM_ALL_ON)
    `uvm_field_int(PC_REF,UVM_ALL_ON)
    `uvm_field_int(branch_valid,UVM_ALL_ON)
    `uvm_field_int(z_rst,UVM_ALL_ON)
    `uvm_field_int(z_instruction_read_enable_o,UVM_ALL_ON)
    `uvm_field_int(instr_read_addr_o,UVM_ALL_ON)
    `uvm_field_int(z_instruction_o,UVM_ALL_ON)
    `uvm_field_int(exception_valid_o,UVM_ALL_ON)
    `uvm_field_int(exception_id_o,UVM_ALL_ON)
    `uvm_field_int(interrupt_valid_o,UVM_ALL_ON)
    `uvm_field_int(exception_id_write_valid_o,UVM_ALL_ON)
    `uvm_field_int(interrupt_id_write_valid_o,UVM_ALL_ON)
    `uvm_field_int(ld_sd_misalign_valid_o,UVM_ALL_ON)
    `uvm_field_int(ld_sd_misalign_addr_o,UVM_ALL_ON)
    `uvm_field_int(instr_misalign_valid_o,UVM_ALL_ON)
    `uvm_field_int(instr_misalign_addr_o,UVM_ALL_ON)
    `uvm_field_int(invalid_instr_valid_o,UVM_ALL_ON)
    `uvm_field_int(decode_instruction_valid_o,UVM_ALL_ON)
    `uvm_field_int(trap_valid_o,UVM_ALL_ON)
    `uvm_field_int(z_instruction_valid_i,UVM_ALL_ON)
    `uvm_field_int(stall_valid_i,UVM_ALL_ON)
    `uvm_field_int(branch_valid_i,UVM_ALL_ON)
   // `uvm_field_int(instr_read_addr_o,UVM_ALL_ON)
   // `uvm_field_int(z_instruction_read_enable_o,UVM_ALL_ON)
    `uvm_field_int(read_write_ptr_valid,UVM_ALL_ON)
    `uvm_field_int(pc_r,UVM_ALL_ON)
    `uvm_field_int(next_pc_r,UVM_ALL_ON) 
    `uvm_field_int(rd0 ,UVM_ALL_ON)
    `uvm_field_int(rd1 ,UVM_ALL_ON)
    `uvm_field_int(rd2 ,UVM_ALL_ON)
    `uvm_field_int(rd3 ,UVM_ALL_ON)
    `uvm_field_int(rd4 ,UVM_ALL_ON)
    `uvm_field_int(rd5 ,UVM_ALL_ON)
    `uvm_field_int(rd6 ,UVM_ALL_ON)
    `uvm_field_int(rd7 ,UVM_ALL_ON)
    `uvm_field_int(rd8 ,UVM_ALL_ON)
    `uvm_field_int(rd9 ,UVM_ALL_ON)
    `uvm_field_int(rd10,UVM_ALL_ON)
    `uvm_field_int(rd11,UVM_ALL_ON)
    `uvm_field_int(rd12,UVM_ALL_ON)
    `uvm_field_int(rd13,UVM_ALL_ON)
    `uvm_field_int(rd14,UVM_ALL_ON)
    `uvm_field_int(rd15,UVM_ALL_ON)
    `uvm_field_int(rd16,UVM_ALL_ON)
    `uvm_field_int(rd17,UVM_ALL_ON)
    `uvm_field_int(rd18,UVM_ALL_ON)
    `uvm_field_int(rd19,UVM_ALL_ON)
    `uvm_field_int(rd20,UVM_ALL_ON)
    `uvm_field_int(rd21,UVM_ALL_ON)
    `uvm_field_int(rd22,UVM_ALL_ON)
    `uvm_field_int(rd23,UVM_ALL_ON)
    `uvm_field_int(rd24,UVM_ALL_ON)
    `uvm_field_int(rd25,UVM_ALL_ON)
    `uvm_field_int(rd26,UVM_ALL_ON)
    `uvm_field_int(rd27,UVM_ALL_ON)
    `uvm_field_int(rd28,UVM_ALL_ON)
    `uvm_field_int(rd29,UVM_ALL_ON)
    `uvm_field_int(rd30,UVM_ALL_ON)
    `uvm_field_int(rd31,UVM_ALL_ON)

 
 
 `uvm_object_utils_end
 
 
 // Constructor                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
      function new (string name="pc_seq_item");
        super.new(name);
      endfunction

 
endclass




