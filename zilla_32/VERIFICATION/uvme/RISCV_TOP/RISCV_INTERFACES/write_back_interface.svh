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
* File Name : write_back_interface.sv

* Purpose :

* Creation Date : 04-07-2023

* Last Modified : Tue 04 Jul 2023 04:07:19 PM IST

* Created By :  

////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


interface write_back_interface(input logic  risc_clk);

     logic[31:0] out;

    logic [1:0]  forward_a ;
    logic [1:0]  forward_b ;

    logic [31:0] alu_out;
    
 

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


endinterface




