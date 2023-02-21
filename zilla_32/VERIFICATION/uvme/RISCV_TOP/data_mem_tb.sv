//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Copyright © 2022 Vivartan Technologies., All rights reserved////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//All works published under Zilla_Gen_0 by Vivartan Technologies is copyrighted by the Association and ownership// 
//of all right, title and interest in and to the works remains with Vivartan Technologies. No works or documents//
//published under Zilla_Gen_0 by Vivartan Technologies may be reproduced,transmitted or copied without the expre//
//-ss written permission of Vivartan Technologies will be considered as a violations of Copyright Act and it may//
//lead to legal action.                                                                                         //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
* File Name : data_mem.sv

* Purpose : data memory for ZCore

* Creation Date : 03-05-2023

* Last Modified : Mon 22 May 2023 06:26:50 PM IST

* Created By :  Sharon
*/
`timescale 1ns/1ps


module data_mem_tb #(parameter DM_WIDTH = 32)
                    (dm_intf intf_dm);

logic [DM_WIDTH-1:0]  wr_addr_in;
logic [DM_WIDTH-1:0]  rd_addr_in;

//array of 256KB of 1 word
    //logic [DM_WIDTH-1:0] data_mem [360735:295200];
    logic [DM_WIDTH-1:0] data_mem [295300:295200];

// loading instructions into array
   initial $readmemh("../top/data.hex", data_mem);

//To store data into desired memory location
    always @ (intf_dm.dm_cb)
        begin
            
            if (intf_dm.data_mem_write_en_o)
                begin

                 //logic to convert address from ZCore to word writable
                        wr_addr_in = intf_dm.data_mem_write_addr_o - 295200;
                        wr_addr_in = wr_addr_in/4;
                        wr_addr_in = wr_addr_in + 295200;

//assigning value to array
                        data_mem [wr_addr_in] = intf_dm.data_mem_write_data_o;
                end
        end

//To read data from memory
    always @ (intf_dm.dm_cb)
        begin
        
            if(intf_dm.data_mem_read_en_o)
                begin

                //logic to convert address from ZCore to word readable
                        rd_addr_in = intf_dm.data_mem_read_addr_o - 295200;
                        rd_addr_in = rd_addr_in/4;
                        rd_addr_in = rd_addr_in + 295200;

//assigning value from array
                        intf_dm.data_mem_read_data_i = data_mem [rd_addr_in];
                end
        end

    
endmodule

