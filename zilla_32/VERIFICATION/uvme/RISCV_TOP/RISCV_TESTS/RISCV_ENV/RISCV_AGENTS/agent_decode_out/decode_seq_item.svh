class decode_seq_item extends uvm_sequence_item;

//Declaring and Randomizing the neccessary parts of Instruction
        rand logic [31:0] instruction;
        rand logic [6:0]  opcode;
        rand logic [2:0]  func3;
        rand logic [6:0]  func7;
        rand logic [31:0] imm;
        rand logic [4:0]  rs1;
        rand logic [4:0]  rs2;
        rand logic [4:0]  rd;
        rand logic        valid;
             logic        reg_wr_en_r;			    
             logic        mem_rd_en_r;			        
             logic        mem_wr_en_r;
             logic   	  reg_wr_en_r1;	
             logic [11:0] alu_ctrl_r;
             logic 	      mem_to_reg_en_r; 
             logic   	  invalid_instruction_valid_o;
        
   //Constructor
  function new(string name = "decode_seq_item");
    super.new(name);
  endfunction

        //Utility and Field macros
  `uvm_object_utils_begin(decode_seq_item)

          `uvm_field_int(instruction                   , UVM_ALL_ON)            
          `uvm_field_int(opcode                        , UVM_ALL_ON)
          `uvm_field_int(func3                         , UVM_ALL_ON)
          `uvm_field_int(func7                         , UVM_ALL_ON)
          `uvm_field_int(rs1                           , UVM_ALL_ON)
          `uvm_field_int(rs2                           , UVM_ALL_ON)
          `uvm_field_int(rd                            , UVM_ALL_ON)
          `uvm_field_int(valid                         , UVM_ALL_ON) 
          `uvm_field_int(reg_wr_en_r                   , UVM_ALL_ON)
          `uvm_field_int(mem_rd_en_r                   , UVM_ALL_ON)
          `uvm_field_int(mem_wr_en_r                   , UVM_ALL_ON)
          `uvm_field_int(reg_wr_en_r1                  , UVM_ALL_ON)
          `uvm_field_int(alu_ctrl_r                    , UVM_ALL_ON)
          `uvm_field_int(mem_to_reg_en_r               , UVM_ALL_ON)
         `uvm_field_int(invalid_instruction_valid_o    , UVM_ALL_ON)

  `uvm_object_utils_end

endclass


