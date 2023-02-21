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
* File Name : spc_coverage.sv

* Purpose : Coverage for special counter

* Creation Date : 31-03-2023

* Last Modified : Mon 28 Aug 2023 06:19:59 PM IST

* Created By :  Sharon
*/

class instr_gen_coverage extends uvm_subscriber #(decode_seq_item);

//Factory registration
    `uvm_component_utils(instr_gen_coverage)

//seq_item instantiationv_i.
    decode_seq_item sq_i;


//covergroup
    covergroup riscv_covergroup;

//Coverpoint for opcode
    OPCODE               :   coverpoint sq_i.opcode
                            {
                                bins bin_r_type          = {51};
                                bins bin_i_type_as       = {19};
                                bins bin_i_type_load     = {3};
                                bins bin_i_type_jalr     = {103};
                                bins bin_s_type          = {35};
                                bins bin_sb_type         = {99};
                                bins bin_u_type_auipc    = {23};
                                bins bin_u_type_lui      = {55};
                                bins bin_uj_type         = {111};
                            }
    

//Coverpoint for rs1
    RS1              :   coverpoint sq_i.rs1
                            {
                                option.auto_bin_max     = 32;
                                ignore_bins ignr0_rs1   = {0};
                            }
//Coverpoint for rs2
    RS2              :   coverpoint sq_i.rs2
                            {
                                option.auto_bin_max     = 32;
                                ignore_bins ignr0_rs2   = {0};
                            }
//Coverpoint for rd
    RD              :   coverpoint sq_i.rd
                            {
                                option.auto_bin_max    = 32;
                                ignore_bins ignr0_rd   = {0};
                            }

//Coverpoint for func3
    FUNC3            :   coverpoint sq_i.func3
                            {
                                bins func3_0   = {0};
                                bins func3_1   = {1};
                                bins func3_2   = {2};
                                bins func3_3   = {3};
                                bins func3_4   = {4};
                                bins func3_5   = {5};
                                bins func3_6   = {6};
                                bins func3_7   = {7};
                            }

//Coverpoint for func7
    FUNC7            :   coverpoint sq_i.func7
                            {
                                bins bin_func7_0  = {0};
                                bins bin_func7_20 = {32};
                            }
    
                           
//Corss of Opcode and rs1
    CROSS_OPRS1     :   cross OPCODE, RS1 {
                                              ignore_bins utype_lXrs1      = binsof (OPCODE.bin_u_type_lui);
                                              ignore_bins utype_aXrs1      = binsof (OPCODE.bin_u_type_auipc);
                                              ignore_bins ujypeXrs1        = binsof (OPCODE.bin_uj_type);
                                          }

//Corss of Opcode and rs2
    CROSS_OPRS2     :   cross OPCODE, RS2 {
                                              ignore_bins itypeasXrs2        = binsof (OPCODE.bin_i_type_as);
                                              ignore_bins itypeloadXrs2      = binsof (OPCODE.bin_i_type_load);
                                              ignore_bins itypejalrXrs2      = binsof (OPCODE.bin_i_type_jalr);
                                              ignore_bins utype_lXrs2        = binsof (OPCODE.bin_u_type_lui);
                                              ignore_bins utypeX_ars2        = binsof (OPCODE.bin_u_type_auipc);
                                              ignore_bins ujypeXrs2          = binsof (OPCODE.bin_uj_type);
                                          }

//Corss of Opcode and rd
    CROSS_OPRD      :   cross OPCODE, RD  {
                                             ignore_bins stypeXrd            = binsof (OPCODE.bin_s_type);
                                             ignore_bins sbtypeXrd           = binsof (OPCODE.bin_sb_type);
                                          }

//Corss of Opcode and func3
    CROSS_OPF3      :   cross OPCODE, FUNC3  {
                                                //bins rtypeXfunc3     = binsof (OPCODE.bin_r_type);
                                                ignore_bins itypeloadXfunc3_3     = binsof (OPCODE.bin_i_type_load) && binsof (FUNC3.func3_3);
                                                ignore_bins itypeloadXfunc3_7     = binsof (OPCODE.bin_i_type_load) && binsof (FUNC3.func3_7);
                                                //bins itypeasXfunc3     = binsof (OPCODE.bin_i_type_as);
                                                ignore_bins itypejalrXfunc3_1     = binsof (OPCODE.bin_i_type_jalr) && binsof (FUNC3.func3_1);
                                                ignore_bins itypejalrXfunc3_2     = binsof (OPCODE.bin_i_type_jalr) && binsof (FUNC3.func3_2);
                                                ignore_bins itypejalrXfunc3_3     = binsof (OPCODE.bin_i_type_jalr) && binsof (FUNC3.func3_3);
                                                ignore_bins itypejalrXfunc3_4     = binsof (OPCODE.bin_i_type_jalr) && binsof (FUNC3.func3_4);
                                                ignore_bins itypejalrXfunc3_5     = binsof (OPCODE.bin_i_type_jalr) && binsof (FUNC3.func3_5);
                                                ignore_bins itypejalrXfunc3_6     = binsof (OPCODE.bin_i_type_jalr) && binsof (FUNC3.func3_6);
                                                ignore_bins itypejalrXfunc3_7     = binsof (OPCODE.bin_i_type_jalr) && binsof (FUNC3.func3_7);
                                                ignore_bins stypeXfunc3_3     = binsof (OPCODE.bin_s_type) && binsof (FUNC3.func3_3);
                                                ignore_bins stypeXfunc3_4     = binsof (OPCODE.bin_s_type) && binsof (FUNC3.func3_4);
                                                ignore_bins stypeXfunc3_5     = binsof (OPCODE.bin_s_type) && binsof (FUNC3.func3_5);
                                                ignore_bins stypeXfunc3_6     = binsof (OPCODE.bin_s_type) && binsof (FUNC3.func3_6);
                                                ignore_bins stypeXfunc3_7     = binsof (OPCODE.bin_s_type) && binsof (FUNC3.func3_7);
                                                ignore_bins sbtypeXfunc3_2     = binsof (OPCODE.bin_sb_type) && binsof(FUNC3.func3_2);
                                                ignore_bins sbtypeXfunc3_3     = binsof (OPCODE.bin_sb_type) && binsof(FUNC3.func3_3);
                                                ignore_bins ig_utypeauipcXfunc3 = binsof (OPCODE.bin_u_type_auipc);
                                                ignore_bins ig_utypeluiXfunc3 = binsof (OPCODE.bin_u_type_lui);
                                                ignore_bins ig_ujtypeXfunc3 = binsof (OPCODE.bin_uj_type);
                                             }

//Corss of Opcode and func7
    CROSS_OPF7      :   cross OPCODE, FUNC7 {
                                              ignore_bins itypeloadXfunc7      = binsof (OPCODE.bin_i_type_load);
                                              ignore_bins itypejalrXfunc7      = binsof (OPCODE.bin_i_type_jalr);
                                              ignore_bins utype_lXfunc7        = binsof (OPCODE.bin_u_type_lui);
                                              ignore_bins utype_aXfunc7        = binsof (OPCODE.bin_u_type_auipc);
                                              ignore_bins ujypeXfunc7          = binsof (OPCODE.bin_uj_type);
                                              ignore_bins stypeXfunc7          = binsof (OPCODE.bin_s_type);
                                              ignore_bins sbtypeXfunc7         = binsof (OPCODE.bin_sb_type);
                                            }

//Corss of func3 and func7
    CROSS_F3F7    :   cross FUNC3, FUNC7 {
                                                       ignore_bins f3_1Xf7_20 = binsof (FUNC7.bin_func7_20) && binsof (FUNC3.func3_1);
                                                       ignore_bins f3_2Xf7_20 = binsof (FUNC7.bin_func7_20) && binsof (FUNC3.func3_2);
                                                       ignore_bins f3_3Xf7_20 = binsof (FUNC7.bin_func7_20) && binsof (FUNC3.func3_3);
                                                       ignore_bins f3_4Xf7_20 = binsof (FUNC7.bin_func7_20) && binsof (FUNC3.func3_4);
                                                       ignore_bins f3_6Xf7_20 = binsof (FUNC7.bin_func7_20) && binsof (FUNC3.func3_6);
                                                       ignore_bins f3_7Xf7_20 = binsof (FUNC7.bin_func7_20) && binsof (FUNC3.func3_7);
                                                     }

//Cross of Opcode and Func3 and Func7
    CROSS_OPF3F7    :   cross OPCODE, CROSS_F3F7  {
                                                    
                                                    ignore_bins itypeloadXf7Xf3      = binsof (OPCODE.bin_i_type_load);
                                                    ignore_bins itypejalrXf7Xf3      = binsof (OPCODE.bin_i_type_jalr);
                                                    ignore_bins utype_lXf7Xf3        = binsof (OPCODE.bin_u_type_lui);
                                                    ignore_bins utype_aXf7Xf3        = binsof (OPCODE.bin_u_type_auipc);
                                                    ignore_bins ujypeXf7Xf3          = binsof (OPCODE.bin_uj_type);
                                                    ignore_bins stypeXf7Xf3          = binsof (OPCODE.bin_s_type);
                                                    ignore_bins sbtypeXf7Xf3         = binsof (OPCODE.bin_sb_type);
 
                                                  }

//Cross of func3 and rs1
    CROSS_F3RS1     :   cross FUNC3, RS1;

//Cross of func3 and rs2
    CROSS_F3RS2     :   cross FUNC3, RS2;
    
//Cross of func3 and rd
    CROSS_F3RD      :   cross FUNC3, RD;
    
    endgroup

//constructor new
        function new(string name ="instr_gen_coverage", uvm_component parent);
            super.new(name, parent);
            riscv_covergroup = new();
        endfunction



        function void write(input decode_seq_item t);
            sq_i = new();
            $cast(sq_i, t);

            riscv_covergroup.sample();
        endfunction

endclass
