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
* File Name : dm_intf.sv

* Purpose :

* Creation Date : 22-05-2023

* Last Modified : Mon 22 May 2023 06:25:35 PM IST

* Created By :  
*/
parameter D_WIDTH = 32;
`timescale 1ns/1ps


interface dm_intf (
                    input logic mem_clk);

        logic [D_WIDTH-1:0]         data_mem_read_data_i;
        logic                       data_mem_write_en_o;
        logic [D_WIDTH-1:0]         data_mem_write_data_o;
        logic [D_WIDTH-1:0]         data_mem_write_addr_o;
        logic [(D_WIDTH>>3)-1:0]    data_mem_strobe_o;
        logic                       data_mem_read_en_o;  
        logic [D_WIDTH-1:0]         data_mem_read_addr_o;

//clocking block for data memory

    clocking dm_cb @ (posedge mem_clk);
    default input #0 output #0;

    output      data_mem_read_data_i;

    input       data_mem_write_en_o;
    input       data_mem_write_data_o;
    input       data_mem_write_addr_o;
    input       data_mem_strobe_o;
    input       data_mem_read_en_o;  
    input       data_mem_read_addr_o;

    endclocking

endinterface
