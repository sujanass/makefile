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
* File Name : inst_gen_agent.sv

* Purpose : Agent for special counter

* Creation Date : 30-03-2023

* Last Modified : Fri 05 May 2023 12:24:11 PM IST

* Created By :  Sharon

*/
//parameter START_ADDR = 33024;
parameter END_ADDR = 65471;
parameter DATA_WIDTH = 32;


class im_agent extends uvm_agent;


//Factory registration
    `uvm_component_utils(im_agent)

//Instantiations
        //inst_gen_sequencer instantiation
        im_sequencer seqr_im;
    
        //inst_gen_driver instantiation
        im_driver drv_im;
    
        //Virtual interface instantiation
        virtual riscv_intf vif;


//VARIABLES
        //local variables
        int     tb_read_address;
        int     st_addr;

        //32bit variable to keep instruction in que
        static logic [31:0] inst_que;


        //static memory for IM
        static logic [DATA_WIDTH-1:0] inst_mem[0 : END_ADDR];

        //event
        event phase_reset;

//Constructor
    function new(string name ="im_agent" , uvm_component parent);
        super.new(name, parent);
    endfunction

//Build phase
    function void build_phase(uvm_phase phase);
        super.build_phase(phase);

        seqr_im  = im_sequencer::type_id::create("seqr_im" , this);
        drv_im   = im_driver::type_id::create("drv_im", this);
        `uvm_info(get_name(),$sformatf("=====>>>>> inside im agent"),UVM_MEDIUM)

        //If virtual interface not connected via config db, drop the entire process
        if (!uvm_config_db#( virtual riscv_intf)::get(this, "*", "riscv_intf", vif))
            `uvm_fatal(get_full_name(),{"Virtual Interface must be set for:",".riscv_intf"});

    endfunction

//Connect phase
    function void connect_phase( uvm_phase phase);
        super.connect_phase(phase);

        drv_im.seq_item_port.connect(seqr_im.seq_item_export);

    endfunction

task reset_phase (uvm_phase phase);
//loading static memory by using .hex file        
        $readmemh("$tb_dir/uvme/RISCV_TOP/inst.hex", inst_mem);
	inst_mem[65471] = 32'h0010_0173;
        //foreach (inst_mem[i])
            //begin
    decode();
            //end
        
        ->phase_reset;
endtask
        

//buid phase to read IM and DM
    task run_phase (uvm_phase phase);
        super.run_phase(phase);
        
        @(phase_reset)

            forever
            begin

                @ (vif.im_cb iff (vif.z_im_read_en_o))
                    
                    if (vif.z_instruction_addr_o > 33023 && vif.z_instruction_addr_o < 294912 )
                        begin
                            vif.z_im_read_data_i    = inst_que;
                            tb_read_address         = vif.z_instruction_addr_o - 33024;
                            tb_read_address         = tb_read_address >> 2;
                            inst_que                = inst_mem [tb_read_address];
                        end
                    
                    else
                        begin
                            vif.z_im_read_data_i    = inst_que;
                            inst_que                = 32'hFEDC_BA98;
                        end
    
            end // forever
            

    endtask //run phase
 

//endclass


// function to decode instruction and write to decode.x

        function void decode;
            int pc ;
            int fh;
            bit [6:0]   d_func7   ;
            bit [4:0]   d_rs2     ;
            bit [4:0]   d_rs1     ;
            bit [2:0]   d_func3   ;
            bit [4:0]   d_rd      ;
            bit [6:0]   d_opcode  ;
            bit [11:0]  d_imm_12b ;
            bit [4:0]   d_imm_5b  ;
            bit [11:0]  d_imm_s   ;
            bit [12:0]  d_imm_sb  ;
            bit [19:0]  d_imm_u   ;
            bit [20:0]  d_imm_uj  ;
            string oper;
            bit [31:0]  d_inst ;

        fh = $fopen("$tb_dir/uvme/RISCV_TOP/decode.x", "w");

        foreach (inst_mem[i])
        begin

            d_inst      = inst_mem[i];

            //instructions splits
            d_func7     = d_inst[31:25];
            d_rs2       = d_inst[24:20];
            d_rs1       = d_inst[19:15];
            d_func3     = d_inst[14:12];
            d_rd        = d_inst[11:7];
            d_opcode    = d_inst[6:0];
            d_imm_12b   = {d_func7, d_rs2};
            d_imm_5b    = d_rs2;
            d_imm_s     = {d_func7 , d_rd};
            d_imm_sb    = {d_inst[31], d_inst[7], d_inst[30:25], d_inst[11:8]};
            d_imm_sb    = d_imm_sb << 1;
            d_imm_u     = {d_func7, d_rs2, d_rs1, d_func3};
            d_imm_uj    = {d_inst[31], d_inst[19:12], d_inst[20], d_inst[30:21]};
            d_imm_uj    = d_imm_uj << 1;


            pc = 33024  + ( i * 4);
            
            
            $fwrite(fh," %0h    :", pc);

            //for R_type
                if (d_opcode == 'h33)
                    begin
                        case (d_func3)
                            0   :   begin
                                        if (!d_func7)
                                            begin
                                                oper = "ADD ";
                                            end
                                        else 
                                            begin
                                                oper = "SUB ";
                                            end
                                    end
                            1   :   oper = "SLL ";
                            2   :   oper = "SLT ";
                            3   :   oper = "SLTU";
                            4   :   oper = "XOR ";
                            5   :   begin
                                        if (!d_func7)
                                            begin
                                                oper = "SRL ";
                                            end
                                        else
                                            begin
                                                oper = "SRA ";
                                            end
                                    end
                            6   :   oper = "OR  ";
                            7   :   oper = "AND ";
                            default: oper = "INVALID_R";
                        endcase
                        
                        $fwrite(fh, "%s" , oper);
                        $fwrite(fh, "x%d, x%d, x%d R_TYPE \n" , d_rd, d_rs1, d_rs2);

                    end

            //I_TYPE : arithmetic & logic
                else if (d_opcode == 'h13)
                    begin
                        case(d_func3)
                            0   :   oper = "ADDI    ";
                            1   :   begin
                                        oper = "SLLI    ";
                                        d_imm_12b = d_imm_5b;
                                    end
                            2   :   oper = "SLTI    ";
                            3   :   oper = "SLTIU   ";
                            4   :   oper = "XORI    ";
                            5   :   begin
                                        d_imm_12b = d_imm_5b;
                                        if(!d_func7)
                                            begin
                                                oper = "SRLI    ";
                                                d_imm_12b = d_imm_5b;
                                            end
                                        else
                                            begin
                                                oper = "SRAI    ";
                                                d_imm_12b = d_imm_5b;
                                            end
                                    end

                            6   :   oper = "ORI     ";
                            7   :   oper = "ANDI    ";
                            default : oper ="INVALID_I";
                        endcase
                        
                            if(d_imm_12b[11])
                                begin
                                    d_imm_12b = ~d_imm_12b + 1;
                                    $fwrite(fh, "%s x%d, x%d, -%0d I_TYPE \n" , oper, d_rd, d_rs1, d_imm_12b);
                                end
                            else
                                begin
                                    $fwrite(fh, "%s x%d, x%d, %0d I_TYPE \n" ,oper, d_rd, d_rs1, d_imm_12b);
                                end

                    end

            // I_TYPE : load
                else if (d_opcode == 'h3)
                    begin
                        case (d_func3)
                            0   :   oper = "LB  ";
                            1   :   oper = "LH  ";
                            2   :   oper = "LW  ";
                            4   :   oper = "LBU ";
                            5   :   oper = "LHU ";
                            6   :   oper = "LWU ";
                            default : oper = "INVALID_L";
                        endcase

                            if(d_imm_12b[11])
                                begin
                                    d_imm_12b = ~d_imm_12b + 1;
                                    $fwrite(fh, "%s x%d, x%d, -%0d I_TYPE \n" , oper, d_rd, d_rs1, d_imm_12b);
                                end
                            else
                                begin
                                    $fwrite(fh, "%s x%d, x%d, %0d I_TYPE \n" ,oper, d_rd, d_rs1, d_imm_12b);
                                end
                    end


            //I_TYPE : jalr
                else if (d_opcode == 'h67)
                    begin
                            if(d_imm_12b[11])
                                begin
                                    d_imm_12b = ~d_imm_12b + 1;
                                    $fwrite(fh, "%s x%d, x%d, -%0d I_TYPE \n" , oper, d_rd, d_rs1, d_imm_12b);
                                end
                            else
                                begin
                                    $fwrite(fh, "%s x%d, x%d, %0d I_TYPE \n" ,oper, d_rd, d_rs1, d_imm_12b);
                                end
                        

                    end

            //S_TYPE
                else if (d_opcode == 'h23)
                    begin
                        case(d_func3)
                            0   :   oper = "SB  ";
                            1   :   oper = "SH  ";
                            2   :   oper = "SW  ";
                            default : oper = "INVALID_S";
                        endcase

                            if(d_imm_s[11])
                                begin
                                    d_imm_s = ~d_imm_s + 1;
                                    $fwrite(fh, "%s x%d, x%d, -%0d S_TYPE \n" , oper, d_rd, d_rs1, d_imm_s);
                                end
                            else
                                begin
                                    $fwrite(fh, "%s x%d, x%d, %0d S_TYPE \n" ,oper, d_rd, d_rs1, d_imm_s);
                                end

                    end

            //SB_TYPE
                else if (d_opcode == 'h63)
                    begin
                        case(d_func3)
                            0   :   oper = "BEQ ";
                            1   :   oper = "BNE ";
                            4   :   oper = "BLT ";
                            5   :   oper = "BGE ";
                            6   :   oper = "BLTU";
                            7   :   oper = "BGEU";
                            default : oper = "INVALID_SB";
                        endcase
                            
                            if(d_imm_sb[12])
                                begin
                                d_imm_sb = ~d_imm_sb + 1;
                                $fwrite(fh, "%s x%d, x%d, -%0d - offset SB_TYPE \n", oper, d_rs1, d_rs2, d_imm_sb);
                                end
                            else
                                begin
                                $fwrite(fh, "%s x%d, x%d, %0d - offset SB_TYPE \n", oper, d_rs1, d_rs2, d_imm_sb);
                                end

                    end

            //U_TYPE : LUI
                else if (d_opcode == 'h37)
                    begin
                            
                            if(d_imm_u[19])
                                begin
                                d_imm_u = ~d_imm_u + 1;
                                $fwrite(fh, "LUI x%d, -%0d - offset U_TYPE \n", d_rd, d_imm_u);
                                end
                            else
                                begin
                                $fwrite(fh, "LUI x%d, %0d - offset U_TYPE \n", d_rd, d_imm_u);
                                end

                    end
        
            //U_TYPE : AUIPC
                else if (d_opcode == 'h17)
                    begin

                            if(d_imm_u[19])
                                begin
                                d_imm_u = ~d_imm_u + 1;
                                $fwrite(fh, "AUIPC x%d, -%0d - offset U_TYPE \n", d_rd, d_imm_u);
                                end
                            else
                                begin
                                $fwrite(fh, "AUIPC x%d, %0d - offset U_TYPE \n", d_rd, d_imm_u);
                                end
                    end

            //UJ_TYPE
                else if (d_opcode == 'h6f)
                    begin
                            
                            if(d_imm_uj[20])
                                begin
                                d_imm_uj = ~d_imm_uj + 1;
                                $fwrite(fh, "JAL x%d, -%0d - offset UJ_TYPE \n", d_rd, d_imm_uj);
                                end
                            else
                                begin
                                $fwrite(fh, "JAL x%d, %0d - offset UJ_TYPE \n", d_rd, d_imm_uj);
                                end
                    end

            //for ebreak
                else if (d_inst == 'h0010_0173)
                    begin
                        $fwrite(fh, "EBREAK");
                    end

                else
                    begin
                        $fwrite(fh, "improve code");
                    end
                
                        
        end //foreach 
        $fclose (fh);

        endfunction  


endclass

