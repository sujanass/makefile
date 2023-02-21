
`define MAILBOX_1  20'h48000    // address of memory  
`define MAILBOX_2  20'h48008    // address of memory  
`define MAILBOX_PRINT  20'h48010   // address of memory write back msg  
`define MAILBOX_1_FLAG   20'h48110 // address for map
`define MAILBOX_2_FLAG   20'h48118 // address for map
`define MEM_DUMP_REQ  32'hA0A0A0A0
`define REQ_RANDS  32'hEEAAEEAA
`define END_SIMS  32'hEEAAAAEE


//`define JTAG_VIP                            //uncomment to run jtag vip , must comment to run debug cases or openocd
//`define OPEN_OCD                            //comment this if you dont want to run openocd or to run debug_test.svh

`define ZILLA_32_BIT
//`define ZILLA_64_BIT
//Use defines here 63 & 31  

`ifdef ZILLA_64_BIT 
  `define DATA_WIDTH 64  
`elsif ZILLA_32_BIT 
  `define DATA_WIDTH 32  
`endif



`define INST_MEM_START_ADDR_D      20'd32768   // Inst memory start address in decimal 
`define INST_MEM_END_ADDR_D        20'd294911  // Inst memory end address in decimal
`define INST_MEM_START_ADDR_H      20'h8000   // Inst memory start address in hex
`define INST_MEM_END_ADDR_H        20'h47fff   // Inst memory end address in hex       


`define DATA_MEM_START_ADDR_D      20'd294912 // Data memory start address in decimal 
`define DATA_MEM_END_ADDR_D        20'd557055 // Data memory end address in decimal
`define DATA_MEM_START_ADDR_H      20'h48000  // Data memory start address in hex
`define DATA_MEM_END_ADDR_H        20'h87fff  // Data memory end address in hex      
