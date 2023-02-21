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
* File Name : riscv_interface.sv

* Purpose :

* Creation Date : 29-04-2023

* Last Modified : Fri 05 May 2023 02:23:48 PM IST

* Created By :  sharon
*/

//Defining the Instruction formats   
   typedef enum {
        R_TYPE_A,
        R_TYPE_S,
        I_TYPE_A,
        I_TYPE_S,
        I_TYPE_L,
        I_TYPE_J,
        S_TYPE,
        SB_TYPE,
        U_TYPE,
        UJ_TYPE,
        I_TYPE_L_E } INSTRUCTION_TYPE;


class im_seq_item extends uvm_sequence_item;

 //Inputs

      
   //Declaring and Randomizing the neccessary parts of Instruction
        rand INSTRUCTION_TYPE instruction;
        rand logic [6:0]    opcode;
        rand logic [2:0]    func3;
        rand logic [6:0]    func7;
        rand logic [31:0]   imm;
        rand logic [4:0]    rs1;
        rand logic [4:0]    rs2;
        rand logic [4:0]    rd;
             logic [31:0]   sample;
     
        logic [3:0] modes;
        
        //for UJ , U type 20b imm
        rand logic [19:0] imm_20b;

        //12bit immediate for I type 
        rand logic [11:0] imm_12b;

        //5bit immediate for shift operations
        rand logic [4:0] imm_5b;


        //variables to set lower and upper limit of brach
        rand int lower_limit;
        rand int upper_limit;

        //static variable to check no of instructions generated
        static int count;


   //Constructor
  function new(string name = "im_seq_item");
    super.new(name);
  endfunction

//CONSTRAINTS____________________________________________________________________________________________________________________

            // R_TYPE   : arithmetic oprations
            constraint r_type_a     {
                                        opcode  == 'h33;
                                        func3   inside {0, 2, 3, 4, 6, 7};
                                        func7   inside {'h0, 'h20};
                                        rs1     != 0;
                                        rs2     != 0;
                                        rd      != 0;
                                        rs2     != rs1;
                                        rd      != rs1;
                                        rd      != rs2;

                                        func3 != 0 -> func7 == 'h0;               //add
                                    }
                                               
            //R_TYPE    : shift operations
            constraint r_type_s     {
                                        opcode  == 'h33;
                                        func3   inside { 1, 5};
                                        func7   inside {'h0, 'h20};
                                        rs1     != 0;
                                        rs2     != 0;
                                        rd      != 0;
                                        rs2     != rs1;
                                        rd      != rs1;
                                        rd      != rs2;

                                        func3 == 1 -> func7 == 'h0;                //sll
                                    }
           
            //I_TYPE    : arithematic operations
            constraint i_type_a     {   opcode  == 'h13;
                                        func3   inside {0, 2, 3, 4, 6, 7};
                                        rs1     != 0;
                                        rs2     != 0;
                                        rd      != 0;
                                        rd      != rs1;
                                    }
            
            //I_TYPE    :shift operations
            constraint i_type_s     {   opcode  == 'h13;
                                        func3   inside  {1,5};
                                        func7   inside {'h0, 'h20};
                                        rs1     != 0;
                                        rs2     != 0;
                                        rd      != 0;
                                        rd      != rs1;
                                        func3 == 1 -> func7 == 'h0;             //slli
                                    }
                                               
            //I_TYPE    : load instructions
            constraint i_type_l     {   opcode      == 'h3;
                                        func3       inside {0, 1, 2, 4, 5, 6};
                                        rs1     != 0;
                                        rs2     != 0;
                                        rd      != 0;
                                        imm_12b     inside {[lower_limit : upper_limit]};     
                                        (func3 == 2 || func3 == 6) -> imm_12b % 4 == 0;
                                        (func3 == 1 || func3 == 5) -> imm_12b % 2 == 0;
                                        rd          != rs1;
                                    
                                    }

            //I_TYPE    : load instructions_to gen exp
            constraint i_type_l_e     {   opcode      == 'h3;
                                        func3       inside {0, 1, 2, 4, 5, 6};
                                        rs1     != 0;
                                        rs2     != 0;
                                        rd      != 0;
                                        imm_12b     inside {[lower_limit : upper_limit]};     
                                        (func3 == 2 || func3 == 6) -> imm_12b % 4 != 0;
                                        (func3 == 1 || func3 == 5) -> imm_12b % 2 != 0;
                                        rd          != rs1;
                                    
                                    }

            //I_TYPE    :jalr
            constraint i_type_j     {   opcode      == 'h67;
                                        func3       == 0;
                                        rs1     != 0;
                                        rs2     != 0;
                                        rd      != 0;
                                        imm_12b     inside {[lower_limit : upper_limit]};    
                                        imm_12b %4  == 0;
                                        rd          != rs1;
                                    }
            
            
            //S_TYPE    :
            constraint s_type       {   opcode      == 'h23;
                                        func3       inside {[0:2]};
                                        rs1     != 0;
                                        rs2     != 0;
                                        rd      != 0;
                                        imm_12b     inside {[lower_limit : upper_limit]};   
                                        imm_12b % 4 == 0;
                                        rs1         != rs2;
                                    }
            
            //SB_TYPE   :
            constraint sb_type      {   opcode      == 'h63;
                                        func3       inside {0,1,4,5,6,7};
                                        rs1     != 0;
                                        rs2     != 0;
                                        rd      != 0;
                                        imm_12b     inside {[lower_limit : upper_limit]};   
                                        imm_12b % 2 == 0;
                                        rs2         != rs1;
                                    }
            
            //U_TYPE    :
            constraint u_type       {   opcode      inside {'h37 , 'h17};
                                        rs1     != 0;
                                        rs2     != 0;
                                        rd      != 0;
                                        if (opcode == 'h17)
                                            {   imm_20b     inside {[lower_limit : upper_limit]};
                                                imm_20b % 4 ==0;
                                            }
                                    }
            
            //UJ_TYPE   :
            constraint uj_type      {   opcode      == 'h6F;
                                        rs1     != 0;
                                        rs2     != 0;
                                        rd      != 0;
                                        imm_20b     inside {[lower_limit : upper_limit]};
                                        imm_20b % 2 == 0;
                                    }
                                                        
//constraint ends______________________________________________________________________________________________________________
            


//pre-randomoze function
                    function void pre_randomize();

                        case(modes)
                            0        :  begin
                                            $display( "R_TYPE_A");
                                            r_type_a.constraint_mode(1);
                                            r_type_s.constraint_mode(0);
                                            i_type_a.constraint_mode(0);      
                                            i_type_s.constraint_mode(0);      
                                            i_type_l.constraint_mode(0);      
                                            i_type_l_e.constraint_mode(0);      
                                            i_type_j.constraint_mode(0);      
                                            s_type  .constraint_mode(0);      
                                            sb_type .constraint_mode(0);      
                                            u_type  .constraint_mode(0);      
                                            uj_type .constraint_mode(0);      
                                        end
                            1        :  begin
                                            $display( "R_TYPE_S");
                                            r_type_a.constraint_mode(0);
                                            r_type_s.constraint_mode(1);
                                            i_type_a.constraint_mode(0);      
                                            i_type_s.constraint_mode(0);      
                                            i_type_l.constraint_mode(0);      
                                            i_type_j.constraint_mode(0);      
                                            s_type  .constraint_mode(0);      
                                            sb_type .constraint_mode(0);      
                                            u_type  .constraint_mode(0);      
                                            uj_type .constraint_mode(0);      
                                            i_type_l_e.constraint_mode(0);      
                                        end
                            2        :  begin
                                            $display( "I_TYPE_A");
                                            r_type_a.constraint_mode(0);
                                            r_type_s.constraint_mode(0);
                                            i_type_a.constraint_mode(1);      
                                            i_type_s.constraint_mode(0);      
                                            i_type_l.constraint_mode(0);      
                                            i_type_j.constraint_mode(0);      
                                            s_type  .constraint_mode(0);      
                                            sb_type .constraint_mode(0);      
                                            u_type  .constraint_mode(0);      
                                            uj_type .constraint_mode(0);      
                                            i_type_l_e.constraint_mode(0);      
                                        end
                            3        :  begin
                                            $display( "I_TYPE_S");
                                            r_type_a.constraint_mode(0);
                                            r_type_s.constraint_mode(0);
                                            i_type_a.constraint_mode(0);      
                                            i_type_s.constraint_mode(1);      
                                            i_type_l.constraint_mode(0);      
                                            i_type_j.constraint_mode(0);      
                                            s_type  .constraint_mode(0);      
                                            sb_type .constraint_mode(0);      
                                            u_type  .constraint_mode(0);      
                                            uj_type .constraint_mode(0);      
                                            i_type_l_e.constraint_mode(0);      
                                        end
                            4        :  begin
                                            $display( "I_TYPE_L");
                                            r_type_a.constraint_mode(0);
                                            r_type_s.constraint_mode(0);
                                            i_type_a.constraint_mode(0);      
                                            i_type_s.constraint_mode(0);      
                                            i_type_l.constraint_mode(1);      
                                            i_type_j.constraint_mode(0);      
                                            s_type  .constraint_mode(0);      
                                            sb_type .constraint_mode(0);      
                                            u_type  .constraint_mode(0);      
                                            uj_type .constraint_mode(0);      
                                            i_type_l_e.constraint_mode(0);      
                                        end
                            5        :  begin
                                            $display( "I_TYPE_J");
                                            r_type_a.constraint_mode(0);
                                            r_type_s.constraint_mode(0);
                                            i_type_a.constraint_mode(0);      
                                            i_type_s.constraint_mode(0);      
                                            i_type_l.constraint_mode(0);      
                                            i_type_j.constraint_mode(1);      
                                            s_type  .constraint_mode(0);      
                                            sb_type .constraint_mode(0);      
                                            u_type  .constraint_mode(0);      
                                            uj_type .constraint_mode(0);      
                                            i_type_l_e.constraint_mode(0);      
                                        end
                            6        :  begin
                                            $display( "S_TYPE");
                                            r_type_a.constraint_mode(0);
                                            r_type_s.constraint_mode(0);
                                            i_type_a.constraint_mode(0);      
                                            i_type_s.constraint_mode(0);      
                                            i_type_l.constraint_mode(0);      
                                            i_type_j.constraint_mode(0);      
                                            s_type  .constraint_mode(1);      
                                            sb_type .constraint_mode(0);      
                                            u_type  .constraint_mode(0);      
                                            uj_type .constraint_mode(0);      
                                            i_type_l_e.constraint_mode(0);      
                                        end
                            7        :  begin
                                            $display( "SB_TYPE");
                                            r_type_a.constraint_mode(0);
                                            r_type_s.constraint_mode(0);
                                            i_type_a.constraint_mode(0);      
                                            i_type_s.constraint_mode(0);      
                                            i_type_l.constraint_mode(0);      
                                            i_type_j.constraint_mode(0);      
                                            s_type  .constraint_mode(0);      
                                            sb_type .constraint_mode(1);      
                                            u_type  .constraint_mode(0);      
                                            uj_type .constraint_mode(0);      
                                            i_type_l_e.constraint_mode(0);      
                                        end
                            8        :  begin
                                            $display( "U_TYPE");
                                            r_type_a.constraint_mode(0);
                                            r_type_s.constraint_mode(0);
                                            i_type_a.constraint_mode(0);      
                                            i_type_s.constraint_mode(0);      
                                            i_type_l.constraint_mode(0);      
                                            i_type_j.constraint_mode(0);      
                                            s_type  .constraint_mode(0);      
                                            sb_type .constraint_mode(0);      
                                            u_type  .constraint_mode(1);      
                                            uj_type .constraint_mode(0);      
                                            i_type_l_e.constraint_mode(0);      
                                        end
                            9        :  begin
                                            $display( "UJ_TYPE");
                                            r_type_a.constraint_mode(0);
                                            r_type_s.constraint_mode(0);
                                            i_type_a.constraint_mode(0);      
                                            i_type_s.constraint_mode(0);      
                                            i_type_l.constraint_mode(0);      
                                            i_type_j.constraint_mode(0);      
                                            s_type  .constraint_mode(0);      
                                            sb_type .constraint_mode(0);      
                                            u_type  .constraint_mode(0);      
                                            uj_type .constraint_mode(1);      
                                            i_type_l_e.constraint_mode(0);      
                                        end
                            10      :   begin
                                            $display("LOAD_EXP");
                                            r_type_a.constraint_mode(0);
                                            r_type_s.constraint_mode(0);
                                            i_type_a.constraint_mode(0);      
                                            i_type_s.constraint_mode(0);      
                                            i_type_l.constraint_mode(0);      
                                            i_type_j.constraint_mode(0);      
                                            s_type  .constraint_mode(0);      
                                            sb_type .constraint_mode(0);      
                                            u_type  .constraint_mode(0);      
                                            uj_type .constraint_mode(0);      
                                            i_type_l_e.constraint_mode(1);      
                                        end

                           default :   begin
                                            $display( "INVALID");
                                       end
                        endcase
                                        
                    endfunction //pre_randomize
                    

//post_randomization
                    function void post_randomize();

                    //in case of shift operation in I_TYPE
                    if ( opcode == 'h13 && (func3 == 5 || func3 == 1))
                        begin
                            imm_12b = {func7, imm_5b};
                        end
                    
                    //imm_12b = imm_12b << 2;
                            case(instruction)
                                
                                   R_TYPE_A :  this.sample = {func7,rs2,rs1,func3,rd,opcode};
                                   R_TYPE_S :  this.sample = {func7,rs2,rs1,func3,rd,opcode};
                                   I_TYPE_A :  this.sample = {imm_12b, rs1, func3, rd, opcode};
                                   I_TYPE_S :  this.sample = {imm_12b, rs1, func3, rd, opcode};
                                   I_TYPE_L :  this.sample = {imm_12b, rs1, func3, rd, opcode};
                                   I_TYPE_L_E :  this.sample = {imm_12b, rs1, func3, rd, opcode};
                                   I_TYPE_J :  this.sample = {imm_12b, rs1, func3, rd, opcode};
                                   S_TYPE   :  this.sample = {imm_12b[11:5], rs2, rs1, func3, imm_12b[4:0], opcode};
                                   SB_TYPE  :  this.sample = {imm_12b[11], imm_12b[9:4], rs2, rs1, func3, imm_12b[3:0], imm_12b[10], opcode};
                                   U_TYPE   :  this.sample = {imm_20b, rd, opcode};
                                   UJ_TYPE  :  this.sample = {imm_20b[19], imm_20b[9:0], imm_20b[10], imm_20b[18:11], rd, opcode};
                    
                                   default  :  this.sample = 32'h00000013;
                            
                            endcase
                            
                            //count = count + 1;
                            //$display("Instructions : %0d", count);
                    endfunction
                    
                    
//Utility and Field macros
  `uvm_object_utils_begin(im_seq_item)
          `uvm_field_int(sample             , UVM_ALL_ON)
          `uvm_field_int(instruction        , UVM_ALL_ON)            
          `uvm_field_int(opcode             , UVM_ALL_ON)
          `uvm_field_int(func3              , UVM_ALL_ON)
          `uvm_field_int(func7              , UVM_ALL_ON)
          `uvm_field_int(rs1                , UVM_ALL_ON)
          `uvm_field_int(rs2                , UVM_ALL_ON)
          `uvm_field_int(rd                 , UVM_ALL_ON)                     
          
  `uvm_object_utils_end

endclass















