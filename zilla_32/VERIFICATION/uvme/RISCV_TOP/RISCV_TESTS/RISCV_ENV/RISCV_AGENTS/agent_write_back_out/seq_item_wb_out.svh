
 
class seq_item_wb_out extends uvm_sequence_item;
    
                logic [31:0] instruction;
                logic [6:0]  opcode;
                logic [2:0]  func3;
                logic [6:0]  func7;
                logic [31:0] imm;
                logic [4:0]  rs1;
                logic [4:0]  rs2;
                logic [4:0]  rd;
                logic [19:0] pc;
                //logic [31:0] instruction;


                logic [1:0] forward_a;
                logic [1:0] forward_b;
                logic [31:0]alu_out;





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

                

     // alu inst - write back stage
    logic [31:0] data_in_1   ;
    logic [31:0] data_in_2   ;                    
    logic [31:0] data_out    ;                               
    //R and I type enable signals for writeback stage
    logic sub_en            ;
    logic add_en            ;
    logic sll_en            ;
    logic slt_en            ;
    logic xor_en            ;
    logic srl_en            ;
    logic sra_en            ;
    logic or_en             ;
    logic and_en            ;
    //I type - writeback stage
    logic jalr_en           ;
    // uj type enable signal for writeback
    logic jal_en            ;   
    // u type enable signal for writeback
    logic lui_en             ;     
    //gpr - regfileinst - write_en for writeback stage
    logic wr_data_en        ;
    
    logic [31:0] in1        ;
    logic [31:0] in2        ;
    logic        sel        ;
                logic [31:0] out;



    `uvm_object_utils_begin(seq_item_wb_out)
   
    `uvm_field_int( instruction,UVM_ALL_ON)
    `uvm_field_int( opcode,UVM_ALL_ON)
    `uvm_field_int(func3,UVM_ALL_ON)
    `uvm_field_int(func7,UVM_ALL_ON)
    `uvm_field_int(imm,UVM_ALL_ON)
    `uvm_field_int(rs1,UVM_ALL_ON)
    `uvm_field_int(rs2,UVM_ALL_ON)
    `uvm_field_int(rd,UVM_ALL_ON)
    //`uvm_field_int_array(reg_data,UVM_ALL_ON)
    `uvm_field_int(out,UVM_ALL_ON)
    `uvm_field_int(pc,UVM_ALL_ON)
    `uvm_field_int(forward_a,UVM_ALL_ON)
    `uvm_field_int(forward_b,UVM_ALL_ON)
    `uvm_field_int(alu_out,UVM_ALL_ON)
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


    `uvm_field_int(data_in_1,UVM_ALL_ON)
    `uvm_field_int(data_in_2,UVM_ALL_ON)
    `uvm_field_int(data_out ,UVM_ALL_ON)
    `uvm_field_int(sub_en,UVM_ALL_ON)
    `uvm_field_int(add_en,UVM_ALL_ON)
    `uvm_field_int(sll_en,UVM_ALL_ON)
    `uvm_field_int(slt_en,UVM_ALL_ON)
    `uvm_field_int(xor_en,UVM_ALL_ON)
    `uvm_field_int(srl_en,UVM_ALL_ON)
    `uvm_field_int(sra_en,UVM_ALL_ON)
    `uvm_field_int(or_en ,UVM_ALL_ON)
    `uvm_field_int(and_en,UVM_ALL_ON)
    `uvm_field_int(jalr_en ,UVM_ALL_ON)
    `uvm_field_int(jal_en ,UVM_ALL_ON)
    `uvm_field_int(lui_en ,UVM_ALL_ON)
    `uvm_field_int(wr_data_en ,UVM_ALL_ON)
    `uvm_field_int(in1,UVM_ALL_ON)
    `uvm_field_int(in2,UVM_ALL_ON)
    `uvm_field_int(sel,UVM_ALL_ON)





 
 `uvm_object_utils_end
 
 
 // Constructor                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
      function new (string name="seq_item_wb_out");
        super.new(name);
      endfunction

 
endclass




