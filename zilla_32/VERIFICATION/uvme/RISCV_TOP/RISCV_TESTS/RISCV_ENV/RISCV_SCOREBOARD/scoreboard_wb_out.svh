class scoreboard_wb_out  extends uvm_scoreboard ;

// Factory Registration
  `uvm_component_utils(scoreboard_wb_out )

// Analysis import to receive data
  // uvm_analysis_imp #(seq_item_wb_out, scoreboard_wb_out) scb_port ;
 uvm_blocking_get_port #(seq_item_wb_out) wb_out_sb; //tlm fifo


// Instance of sequence_item
   seq_item_wb_out sq_i  ;
   seq_item_wb_out sq_i_all[4] ;



  virtual riscv_intf   vif;

// Constructor
    function new(string name = "scoreboard_wb_out", uvm_component parent);
        super.new(name,parent);
    endfunction
                        
                        int count = 0;
                       
                       int m_num_tx ;
                       
                        logic [6:0] opcode  ;
                        logic [4:0] rd      ;
                        logic [2:0] funct3  ;
                        logic [4:0] rs1     ;
                        logic [4:0] rs2     ;
                        logic [6:0] funct7  ;
                        logic [19:0] pc     ;
                        logic [31:0] rd_value;
                        logic [31:0] rd_sb;
                        logic [31:0] ins;
                        logic [31:0] i_out; // for i type sb output
                        logic [31:0] immi;
                        logic [63:0] rs1_gpr;
                        logic [63:0] rs2_gpr;
                        logic [31:0] sb_reg_data [0:31];
                        logic [31:0] immu;  //unsigend imm value for i type 
                        logic [31:0] out;
 
                        logic [1:0] forward_a;
                        logic [1:0] forward_b;
                        logic [31:0]alu_out;


    function void build_phase(uvm_phase phase);
      wb_out_sb = new("wb_out_sb", this);
        if(!uvm_config_db#(virtual riscv_intf)::get(this,"*","riscv_intf", vif))
            `uvm_fatal(get_name(), "Monitor: VIF NOT FOUND")
    endfunction
                                                        


     virtual task run_phase(uvm_phase phase);
        
        forever
          begin
        
            repeat (m_num_tx) 
              begin
              
                if(count < 4)
                 begin
                
                     for(int i=0; i<4; i++)  // Catching initial 4 packets
                        begin
                        wb_out_sb.get(sq_i_all[i]);
                        count ++;
                        end
                end
            else
                begin : Remaining_Packets

           /*         $display("PKT1");
                    sq_i_all[0].print();
                    $display("PKT2");
                    sq_i_all[1].print();
                    $display("PKT3");
                    sq_i_all[2].print();
                    $display("PKT4");
                    sq_i_all[3].print();

*/

                if(sq_i_all[0].instruction == 32'h0000_0013)
                 
                     begin

                        for (int i=0;i<3;i++)       // If instruction is NOP, sq_item is shifted ( 0 <- 1 <- 2 <- 3 )
                        begin
                            sq_i_all[i]=sq_i_all[i+1];
                        end
                         wb_out_sb.get(sq_i_all[3]); // From port to sq_item [3] ( 3 <- port )
                    end


                else
                        begin : Non_NOP_Block

                   //--------------------------------- R - TYPE  -----------------------------------------------------

                             if (sq_i_all[0].opcode == 'h33)
                            begin : R_TYPE


                          
                                   rd      = sq_i_all[0].rd;
                                   funct3  = sq_i_all[0].func3;
                                   rs1     = sq_i_all[0].rs1;
                                   rs2     = sq_i_all[0].rs2;
                                   funct7  = sq_i_all[0].func7;
                                   out     = sq_i_all[3].out;
                                  
                                   forward_a=sq_i_all[1].forward_a; 
                                   forward_b=sq_i_all[1].forward_b; 
                                   alu_out = sq_i_all[1].alu_out;



                                   sb_reg_data[0 ] = sq_i_all[2].rd0 ; 
                                   sb_reg_data[1 ] = sq_i_all[2].rd1 ; 
                                   sb_reg_data[2 ] = sq_i_all[2].rd2 ; 
                                   sb_reg_data[3 ] = sq_i_all[2].rd3 ; 
                                   sb_reg_data[4 ] = sq_i_all[2].rd4 ; 
                                   sb_reg_data[5 ] = sq_i_all[2].rd5 ; 
                                   sb_reg_data[6 ] = sq_i_all[2].rd6 ; 
                                   sb_reg_data[7 ] = sq_i_all[2].rd7 ; 
                                   sb_reg_data[8 ] = sq_i_all[2].rd8 ; 
                                   sb_reg_data[9 ] = sq_i_all[2].rd9 ; 
                                   sb_reg_data[10] = sq_i_all[2].rd10; 
                                   sb_reg_data[11] = sq_i_all[2].rd11; 
                                   sb_reg_data[12] = sq_i_all[2].rd12; 
                                   sb_reg_data[13] = sq_i_all[2].rd13; 
                                   sb_reg_data[14] = sq_i_all[2].rd14; 
                                   sb_reg_data[15] = sq_i_all[2].rd15; 
                                   sb_reg_data[16] = sq_i_all[2].rd16; 
                                   sb_reg_data[17] = sq_i_all[2].rd17; 
                                   sb_reg_data[18] = sq_i_all[2].rd18; 
                                   sb_reg_data[19] = sq_i_all[2].rd19; 
                                   sb_reg_data[20] = sq_i_all[2].rd20; 
                                   sb_reg_data[21] = sq_i_all[2].rd21; 
                                   sb_reg_data[22] = sq_i_all[2].rd22; 
                                   sb_reg_data[23] = sq_i_all[2].rd23; 
                                   sb_reg_data[24] = sq_i_all[2].rd24; 
                                   sb_reg_data[25] = sq_i_all[2].rd25; 
                                   sb_reg_data[26] = sq_i_all[2].rd26; 
                                   sb_reg_data[27] = sq_i_all[2].rd27; 
                                   sb_reg_data[28] = sq_i_all[2].rd28; 
                                   sb_reg_data[29] = sq_i_all[2].rd29; 
                                   sb_reg_data[30] = sq_i_all[2].rd30; 
                                   sb_reg_data[31] = sq_i_all[2].rd31; 
                                   

                                   rs1_gpr = sb_reg_data[rs1];
                                   rs2_gpr = sb_reg_data[rs2];
 
                                 
                                      case (funct3)

                                       3'b000 :   begin
                                                   if (!funct7)     // add R-TYPE
                                                       begin
                                                       if(forward_a==1)
                                                           i_out = alu_out + rs2_gpr;
                                                          
                                                       else if(forward_b==1)
                                                            i_out = rs1_gpr + alu_out;
                                                       else
                                                           i_out = rs1_gpr + rs2_gpr;
                                                            
                                                       if(out == i_out)
                                                       begin
                                                           `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                                               `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                            else
                                                       begin
                                                           `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - ADD SB FAIL "))
                                                         
                                                         
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH-Add SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
                                                         
                                                         end
                                                   
                                                   if (funct7 == 32)        // sub R-TYPE
                                                       begin
                                                       if(forward_a==1)
                                                           i_out = alu_out - rs2_gpr;
                                                          
                                                       else if(forward_b==1)
                                                            i_out = rs1_gpr - alu_out;
                                                       else
                                                           i_out = rs1_gpr - rs2_gpr;                                                         
                                                            
                                                            
                                                         if(out == i_out)
                                                       begin
                                                           `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                                                          
                                               `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                          
                                                          
                                                          else
                                                       begin
                                                           `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - SUB SB FAIL "))

                                                       
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - SUB SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
                                                       
                                                       end
                                                 end
                                                   
                                              
                                       
                                       3'b001 : begin       // sll R-TYPE

                                                       if(forward_a==1)
                                                           i_out = alu_out << rs2_gpr[4:0];
                                                          
                                                       else if(forward_b==1)
                                                            i_out = rs1_gpr << alu_out[4:0];
                                                       else
                                                           i_out = rs1_gpr << rs2_gpr[4:0];  


                                               

                                                 if(out == i_out)
                                                       begin
                                                `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_SHIFT", UVM_MEDIUM) 
                                               
                                               
                                               `uvm_info("[ PASS-R_TYPE_SHIFT_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end

                                               
                                               else
                                                       begin
                                                 `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_SHIFT-sll SB FAIL "))
                                             
                                             
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_SHIFT-sll SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
                                             
                                             end


                                       3'b010 :begin                // slt R-TYPE

                                                       if(forward_a==1)
                                                    begin
                                                        case({alu_out[31],rs2_gpr[31]})
                                                       
                                                       2'b00  : begin
                                                                i_out = (alu_out < rs2_gpr) ? 1 : 0;
                                                               
                                                                 if(out == i_out)
                                                       begin
                                                                  `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                                               `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                                 else
                                                       begin
                                                                 `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH-slt-forward a-00 SB FAIL "))
                             
                             
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH-slt-forward a-00 SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
                                                               end
                                                               
                                                       2'b01  :   begin
                                                                   
                                                                   i_out   = {32'b0};

                                                                 if(out == i_out)
                                                       begin
                                                                  `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                                               `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                                 else
                                                       begin
                                                                 `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH -slt - frwd a - 01 SB FAIL "))
                             
                             
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - frwd a-01 SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end

                                                               end

                                                       2'b10  :   begin
                                                                   
                                                                   i_out   = {31'b0,1'b1};

                                                                   if(out == i_out)
                                                       begin
                                                                  `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                                               `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                                    else
                                                       begin
                                                                 `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH -slt -frwd a -10 SB FAIL "))
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - frwd a 10SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
                                                               end

                                                       2'b11  : begin
                                                                i_out   = (alu_out[30:0] < rs2_gpr[30:0]) ? 1 : 0;

                                                                 if(out == i_out)
                                                       begin
                                                                  `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                                               `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                                 else
                                                       begin
                                                                 `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt -frwd a -11 SB FAIL "))
                             
                             
                              `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - forward a -11 SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
                                                             end
                                                   endcase
                                                    end


                                                       else if(forward_b==1)
                                                          begin
                                                   case({rs1_gpr[31],alu_out[31]})
                                                       
                                                       2'b00  : begin
                                                                i_out = (rs1_gpr[30:0] < alu_out[30:0]) ? 1 : 0;
                                                               
                                                                 if(out == i_out)
                                                       begin
                                                                  `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                                                `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                                 else
                                                       begin
                                                                 `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - forward b -00 SB FAIL "))
                             
                             
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - forward b -00 SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
                                                               end
                                                               
                                                       2'b01  :   begin
                                                                
                                                                   i_out   = {32'b0}; 

                                                                 if(out == i_out)
                                                       begin
                                                                  `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                                               `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                                 else
                                                       begin
                                                                 `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - forward b -01 SB FAIL "))
                             
                             
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - forward b -01 SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end

                                                               end

                                                       2'b10  :   begin
                                                                   i_out   = {31'b0,1'b1};

                                                               if(out == i_out)
                                                       begin
                                                                  `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                                               `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                                    else
                                                       begin
                                                                     `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - forward b -10 SB FAIL "))
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - forward b -10 SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
                                                               end

                                                       2'b11  : begin
                                                                  i_out   = (rs1_gpr[30:0] < alu_out[30:0]) ? 1 : 0;

                                                                 if(out == i_out)
                                                       begin
                                                                  `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                                               `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                                 else
                                                       begin
                                                                 `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - forward b -11 SB FAIL "))
                             
                             
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - forward b -11 SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
                                                             end
                                                   endcase
                                                 end

                                                     else
                                                       begin
                                                        
                                                        case({rs1_gpr[31],rs2_gpr[31]})
                                                       
                                                       2'b00  : begin

                                                                i_out = (rs1_gpr[30:0] < rs2_gpr[30:0]) ? 1 : 0;
                                                               
                                                                 if(out == i_out)
                                                       begin
                                                                  `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                                               `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                               else
                                                       begin
                                                                 `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - without forward  SB FAIL "))
                             
                             
                              `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - without 00 SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
                                                               end
                                                               
                                                       2'b01  :   begin
                                                                    i_out   = {32'b0};
                                                                
                                                                if(out == i_out)
                                                       begin
                                                                  `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                                               `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                                 else
                                                       begin
                                                                 `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - without 01 SB FAIL "))
                             
                             
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - without 01 SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end

                                                               end

                                                       2'b10  :   begin
                                                                   i_out   = {31'b0,1'b1}; 

                                                                 if(out == i_out)
                                                       begin
                                                                  `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                                                `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                               else
                                                       begin
                                                                 `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - without 10 SB FAIL "))
                            `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - without 10 SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
                                                               end

                                                       2'b11  : begin
                                                                 i_out   = (rs1_gpr[30:0] < rs2_gpr[30:0]) ? 1 : 0;

                                                               if(out == i_out)
                                                       begin
                                                                  `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                                               `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                                 else
                                                       begin
                                                                 `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - without 11 SB FAIL "))
                             
                             
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH - slt - without 11 SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
                                                             end
                                                   endcase
end

                                            end


                                       3'b011 :   begin         // sltu R-TYPE

                                                       if(forward_a==1)
                                                           i_out = (alu_out < rs2_gpr)? 1'b1 : 1'b0;
                                                          
                                                       else if(forward_b==1)
                                                            i_out = (rs1_gpr < alu_out)? 1'b1 : 1'b0;
                                                       else
                                                           i_out = (rs1_gpr < rs2_gpr)? 1'b1 : 1'b0;  

                                             

                                                 if(out == i_out)
                                                       begin
                                                   `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                                                
                                                
                                               `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                
                                                else
                                                       begin
                                                 `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH -sltu SB FAIL "))
                                            
                                            
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH -sltu SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
            
                                               end

                                       3'b100 : begin     // xor R-TYPE

                                                       if(forward_a==1)
                                                           i_out = alu_out ^ rs2_gpr;
                                                          
                                                       else if(forward_b==1)
                                                            i_out = rs1_gpr ^ alu_out;
                                                       else
                                                           i_out = rs1_gpr ^ rs2_gpr; 

                                          if(out == i_out)
                                                       begin
                                             `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                              
                              
                                         `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                             else
                                                       begin
                                               `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH xor SB FAIL "))
                             
                             
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH xor SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
                                             end


                                       3'b101 :   begin   // srl and sra R-TYPE

                                                   if (!funct7)
                                                       begin
                                                       if(forward_a==1)
                                                           i_out = alu_out >> rs2_gpr[4:0];
                                                          
                                                       else if(forward_b==1)
                                                            i_out = rs1_gpr >> alu_out[4:0];
                                                       else
                                                           i_out = rs1_gpr >> rs2_gpr[4:0]; 
                                                         
                                                        
                                                           if(out == i_out)
                                                       begin
                                                           `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_SHIFT", UVM_MEDIUM) 
                                               `uvm_info("[ PASS-R_TYPE_SHIFT_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                         else
                                                       begin
                                                           `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_SHIFT srl SB FAIL "))
                             
                             
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_SHIFT srl SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end

                                                       end
                                                   if (funct7 == 'h20)
                                                       begin
                                                       if(forward_a==1)
                                                           i_out = alu_out >>> rs2_gpr[4:0];
                                                          
                                                       else if(forward_b==1)
                                                            i_out = rs1_gpr >>> alu_out[4:0];
                                                       else
                                                           i_out = rs1_gpr >>> rs2_gpr[4:0]; 

                                                           if(out == i_out)
                                                       begin
                                                             `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_SHIFT", UVM_MEDIUM) 
                                               `uvm_info("[ PASS-R_TYPE_SHIFT_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                                         else
                                                       begin
                                                           `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_SHIFT sra SB FAIL "))
                             
                             
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_SHIFT sra SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end

                                                       end
                                               end

                                       3'b110 : begin       // or R-TYPE
                                                       
                                                       if(forward_a==1)
                                                           i_out = alu_out | rs2_gpr;
                                                          
                                                       else if(forward_b==1)
                                                            i_out = rs1_gpr | alu_out;
                                                       else
                                                           i_out = rs1_gpr | rs2_gpr; 
                                           

                                            if(out == i_out)
                                                       begin
                                              `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                              
                              
                                    `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                            else
                                                       begin
                                              `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH or SB FAIL "))
                             
                             
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH or SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
                                   
                                   end



                                       3'b111 : begin       // and R-TYPE
    
                                                       if(forward_a==1)
                                                           i_out = alu_out & rs2_gpr;
                                                          
                                                       else if(forward_b==1)
                                                            i_out = rs1_gpr & alu_out;
                                                       else
                                                           i_out = rs1_gpr & rs2_gpr; 
                                                
                                         if(out == i_out)
                                                       begin
                                           `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS R_TYPE_ARITH", UVM_MEDIUM) 
                              
                              
                                          `uvm_info("[ PASS-R_TYPE_ARITH_WB ]",$sformatf("\n\n[ PASS ]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d,func7=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3,funct7),UVM_MEDIUM)
                              end
                                        
                                        
                                        else
                                                       begin
                                          `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH and SB FAIL "))
                             
                             
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]R_TYPE_ARITH and SB FAIL\n func7=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h\n rs1=%d, rs2=%d, reg_mem_rs1=%h, reg_mem_rs2=%h, func3=%d", funct7,i_out,out,sq_i_all[0].instruction,rs1,rs2,sb_reg_data[rs1],sb_reg_data[rs2], funct3))
                              end
                                             end


                            endcase
                           
                           end : R_TYPE
                            

                 

                 // UJ - TYPE 
               
                    else if (sq_i_all[0].opcode == 'h6F)       // jal instruction (UJ type)
                       begin
                          out     = sq_i_all[3].out;
                          rd =sq_i_all[0].rd;
                          rd_sb =sq_i_all[0].pc-20'd4;
                           
                      
                           if(out == rd_sb)
                              `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS UJ_TYPE", UVM_MEDIUM) 
                            else
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]UJ_TYPE SB FAIL "))
                            
                           end
              
              
              
              // U - TYPE 
              
                    else if(sq_i_all[0].opcode == 'h37)   // U-type Instruction
                         begin
                            out     = sq_i_all[3].out;
                            ins = sq_i_all[0].instruction;
                            rd_value={sq_i_all[0].instruction[31:12],12'b0};
                     
                                if(out == rd_value)
                                    `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS U_TYPE", UVM_MEDIUM) 
                                else
                                    `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]U_TYPE SB FAIL "))
                            
                         end
             
             
             
             
             // I - TYPE 
                             else if(sq_i_all[0].opcode == 'h13)   // I-Type instructions (Arithmetic)
                                 begin
                                 
                                   rd      = sq_i_all[0].rd;
                                   funct3  = sq_i_all[0].func3;
                                   rs1     = sq_i_all[0].rs1;
                                   rs2     = sq_i_all[0].rs2;
                                   funct7  = sq_i_all[0].func7;
                                   out     = sq_i_all[3].out;
                                  
                                   forward_a=sq_i_all[1].forward_a; 
                                   alu_out = sq_i_all[1].alu_out;

                                   sb_reg_data[0 ] = sq_i_all[2].rd0 ; 
                                   sb_reg_data[1 ] = sq_i_all[2].rd1 ; 
                                   sb_reg_data[2 ] = sq_i_all[2].rd2 ; 
                                   sb_reg_data[3 ] = sq_i_all[2].rd3 ; 
                                   sb_reg_data[4 ] = sq_i_all[2].rd4 ; 
                                   sb_reg_data[5 ] = sq_i_all[2].rd5 ; 
                                   sb_reg_data[6 ] = sq_i_all[2].rd6 ; 
                                   sb_reg_data[7 ] = sq_i_all[2].rd7 ; 
                                   sb_reg_data[8 ] = sq_i_all[2].rd8 ; 
                                   sb_reg_data[9 ] = sq_i_all[2].rd9 ; 
                                   sb_reg_data[10] = sq_i_all[2].rd10; 
                                   sb_reg_data[11] = sq_i_all[2].rd11; 
                                   sb_reg_data[12] = sq_i_all[2].rd12; 
                                   sb_reg_data[13] = sq_i_all[2].rd13; 
                                   sb_reg_data[14] = sq_i_all[2].rd14; 
                                   sb_reg_data[15] = sq_i_all[2].rd15; 
                                   sb_reg_data[16] = sq_i_all[2].rd16; 
                                   sb_reg_data[17] = sq_i_all[2].rd17; 
                                   sb_reg_data[18] = sq_i_all[2].rd18; 
                                   sb_reg_data[19] = sq_i_all[2].rd19; 
                                   sb_reg_data[20] = sq_i_all[2].rd20; 
                                   sb_reg_data[21] = sq_i_all[2].rd21; 
                                   sb_reg_data[22] = sq_i_all[2].rd22; 
                                   sb_reg_data[23] = sq_i_all[2].rd23; 
                                   sb_reg_data[24] = sq_i_all[2].rd24; 
                                   sb_reg_data[25] = sq_i_all[2].rd25; 
                                   sb_reg_data[26] = sq_i_all[2].rd26; 
                                   sb_reg_data[27] = sq_i_all[2].rd27; 
                                   sb_reg_data[28] = sq_i_all[2].rd28; 
                                   sb_reg_data[29] = sq_i_all[2].rd29; 
                                   sb_reg_data[30] = sq_i_all[2].rd30; 
                                   sb_reg_data[31] = sq_i_all[2].rd31; 
                                   

                                   rs1_gpr = sb_reg_data[rs1];
                                   rs2_gpr = sb_reg_data[rs2];


                    case(funct3)
                        
                          0 :  begin       //  ori I-TYPE
              
                                // `uvm_info(get_name(),$sformatf("\n\n[addi]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3),UVM_MEDIUM)
                              immi  ={{(32-12){sq_i_all[0].instruction[31]}},sq_i_all[0].instruction[31:20]};
                              
                              if(forward_a==1)
                                    begin
                                     i_out = alu_out + immi;
                                    end

                              else
                                   begin
                              i_out = rs1_gpr + immi;

                                    end

                            if(out == i_out)
                                 begin
                             `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS I_TYPE_ARITH", UVM_MEDIUM) 
                       
                       
                          `uvm_info (get_name(), $sformatf("\n\n[ PASS ]I_TYPE_ARITH SB PASS\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction),UVM_MEDIUM)
                              end
                       
                       
                                else
                                 begin
                                 `uvm_error ("\n\n[ FAIL ] INFO : WB_ScoreBoard", $sformatf("\n\n[ FAIL ]I_TYPE_ARITH ori SB FAIL "))
                             
                               `uvm_error ("\n\n[ FAIL ] INFO : WB_ScoreBoard", $sformatf("\n\n[ FAIL ]I_TYPE_ARITH ori SB FAIL\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction))
                              end
                            
                       


                         end
                            
                          1 : begin         //slli I-TYPE
                                 
                                 
                              //   `uvm_info(get_name(),$sformatf("\n\n[slli]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3),UVM_MEDIUM)
                              immi  ={{(32-12){sq_i_all[0].instruction[31]}},sq_i_all[0].instruction[31:20]};
                              
                               if(forward_a==1)
                                    begin
                                    
                                    if(immi[11:5]==0000000)
                                    i_out = alu_out << immi[4:0];

                                    end

                              else
                                  begin
                                        if(immi[11:5]==0000000)
                                            begin
                                                i_out = rs1_gpr << immi[4:0];
                                            end
                                  end

                            if(out == i_out)
                                 begin
                              `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS I_TYPE_SHIFT", UVM_MEDIUM) 
                           
                           
                              `uvm_info (get_name(), $sformatf("\n\n[ PASS ]I_TYPE_SHIFT SB PASS\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction),UVM_MEDIUM)
                              end
                           
                               else
                                 begin
                                 `uvm_error ("\n\n[ FAIL ] INFO : WB_ScoreBoard", $sformatf("\n\n[ FAIL ]I_TYPE_SHIFT slli SB FAIL "))
                          
                          
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]I_TYPE_SHIFT slli SB FAIL\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction))
                              end
                            
                       
                       

                              end 

                          2:begin        // slti I-TYPE
                                
                                //  `uvm_info(get_name(),$sformatf("\n\n[sltii]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3),UVM_MEDIUM)
                              immi  = {{(32-12){sq_i_all[0].instruction[31]}},sq_i_all[0].instruction[31:20]};

                                    if(forward_a==1)
                                    begin
                                  
                                  if(alu_out[31] && immi[31])
                                   i_out = (alu_out[30:0] < immi[30:0])?1:0;
                             else if (alu_out[31]==1 && immi[31]==0)
                                    i_out = 32'h0000_0001;
                             else if (alu_out[31]==0 && immi[31]==1)
                                    i_out = 32'h0000_0000;
                             else if (alu_out[31]==0 && immi[31]==0)
                                   i_out = (alu_out[30:0] < immi[30:0])?1:0;

                                    
                                    end


                                    else
                                        begin
                            
                            if(rs1_gpr[31] && immi[31])
                                   i_out = (rs1_gpr[30:0] < immi[30:0])?1:0;
                             else if (rs1_gpr[31]==1 && immi[31]==0)
                                    i_out = 32'h0000_0001;
                             else if (rs1_gpr[31]==0 && immi[31]==1)
                                    i_out = 32'h0000_0000;
                             else if (rs1_gpr[31]==0 && immi[31]==0)
                                   i_out = (rs1_gpr[30:0] < immi[30:0])?1:0;
                              
                                  end
                         
                            if(out == i_out)
                                 begin
                              `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS I_TYPE_ARITH", UVM_MEDIUM) 
                         
                         
                           `uvm_info (get_name(), $sformatf("\n\n[ PASS ]I_TYPE_ARITH SB PASS\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction),UVM_MEDIUM)
                              end
                            
                            else
                                 begin
                             `uvm_error ("\n\n[ FAIL ] INFO : WB_ScoreBoard", $sformatf("\n\n[ FAIL ]I_TYPE_ARITH slti SB FAIL "))
                         
                         
                           `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]I_TYPE_ARITH slti SB FAIL\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction))
                              end
                            
                       
                       end

                          
                          3:begin      // sltiu I-TYPE
                           
                           
                           //   `uvm_info(get_name(),$sformatf("\n\n[sltiu]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3),UVM_MEDIUM)
                             immi  ={{20{sq_i_all[0].instruction[31]}},sq_i_all[0].instruction[31:20]};

                              if(forward_a==1)
                                    begin
                                     i_out = (alu_out < immi)?1:0;
                                    end


                              else
                                  begin
                                     i_out = (rs1_gpr < immi)?1:0;
                                  end
                           
                            if(out == i_out)
                                 begin
                              `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS I_TYPE_ARITH", UVM_MEDIUM) 
                
                
                        `uvm_info (get_name(), $sformatf("\n\n[ PASS ]I_TYPE_ARITH SB PASS\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction),UVM_MEDIUM)
                              end
                            
                            else
                                 begin
                             `uvm_error ("\n\n[ FAIL ] INFO : WB_ScoreBoard", $sformatf("\n\n[ FAIL ]I_TYPE_ARITH sltiu SB FAIL "))
                            
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]I_TYPE_ARITH sltiu SB FAIL\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction))
                              end
                       
                       

                            end 

                          4:begin    // xori I-TYPE
                                 
                                 
                                 //  `uvm_info(get_name(),$sformatf("\n\n[xori]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3),UVM_MEDIUM)
                             immi  ={{(32-12){sq_i_all[0].instruction[31]}},sq_i_all[0].instruction[31:20]};
                           
                           if(forward_a==1)
                                    begin
                                         i_out = alu_out ^ immi;
                                    end
                            else
                                begin
                                    i_out = rs1_gpr ^ immi;
                                end
                          
                            if(out == i_out)
                                 begin
                              `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS I_TYPE_ARITH", UVM_MEDIUM) 
                          
                            `uvm_info (get_name(), $sformatf("\n\n[ PASS ]I_TYPE_ARITH SB PASS\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction),UVM_MEDIUM)
                              end
                            
                            else
                                 begin
                             `uvm_error ("\n\n[ FAIL ] INFO : WB_ScoreBoard", $sformatf("\n\n[ FAIL ]I_TYPE_ARITH xori SB FAIL "))
                            
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]I_TYPE_ARITH xori SB FAIL\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction))
                              end
                       
                       

                            end 

                         5: begin   // srai and srli I-TYPE
                                             
                                             
                                             //  `uvm_info(get_name(),$sformatf("\n\n[srli]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3),UVM_MEDIUM)
                             immi  ={{(32-12){sq_i_all[0].instruction[31]}},sq_i_all[0].instruction[31:20]};
                             immu  ={20'b0,sq_i_all[0].instruction[31:20]}; //for unsigned
                          

                           if(forward_a==1)
                                    begin

                            if(immi[11:5]==0100000)
                                 begin
                                    i_out = alu_out >> immi[4:0];

                                   if(out == i_out)
                                 begin
                                    `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS I_TYPE_SHIFT", UVM_MEDIUM) 
                                   
                                  
                            `uvm_info (get_name(), $sformatf("\n\n[ PASS ]I_TYPE_SHIFT SB PASS\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction),UVM_MEDIUM)
                              end
                                   
                                   else
                                 begin
                                    `uvm_error ("\n\n[ FAIL ] INFO : WB_ScoreBoard", $sformatf("\n\n[ FAIL ]I_TYPE_SHIFT srai-frwd a SB FAIL "))
                                
                                
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]I_TYPE_SHIFT srai -frwd a SB FAIL\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction))
                              end
                                
                                end
                           
                             else if (immu[11:5]==0000000)    
                                  begin
                                    i_out = alu_out >> immi[4:0];
                                  

                                    if(out == i_out)
                                 begin
                                     `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS I_TYPE_SHIFT", UVM_MEDIUM) 
                                    
                                    
                            `uvm_info (get_name(), $sformatf("\n\n[ PASS ]I_TYPE_SHIFT SB PASS\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction),UVM_MEDIUM)
                              end
                                    
                                    else
                                 begin
                                     `uvm_error ("\n\n[ FAIL ] INFO : WB_ScoreBoard", $sformatf("\n\n[ FAIL ]I_TYPE_SHIFT srli-frwd a SB FAIL "))
                            
                          
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]I_TYPE_SHIFT srli-frwd a SB FAIL\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction))
                              end
                          
                          end
                         end
                             else
                                 begin

                                  if(immi[11:5]==0100000)
                                        begin
                                            i_out = rs1_gpr >> immi[4:0];

                                     if(out == i_out)
                                 begin
                                    `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS I_TYPE_SHIFT", UVM_MEDIUM) 
                                    
                                    
                            `uvm_info (get_name(), $sformatf("\n\n[ PASS ]I_TYPE_SHIFT SB PASS\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction),UVM_MEDIUM)
                              end
                                    
                                    
                                    
                                    else
                                 begin
                                    `uvm_error ("\n\n[ FAIL ] INFO : WB_ScoreBoard", $sformatf("\n\n[ FAIL ]I_TYPE_SHIFT -srai - without frwd  SB FAIL "))
                                 
                                
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]I_TYPE_SHIFT -srai -without frwd SB FAIL\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction))
                              end
                                 
                                 
                                 end
                           
                                    else if (immu[11:5]==0000000)    
                                        begin
                                            i_out = rs1_gpr >> immi[4:0];
                                  

                                    if(out == i_out)
                                 begin
                                     `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS I_TYPE_SHIFT", UVM_MEDIUM) 

                            `uvm_info (get_name(), $sformatf("\n\n[ PASS ]I_TYPE_SHIFT SB PASS\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction),UVM_MEDIUM)
                              end
                                   
                                   
                                   else
                                 begin
                                     `uvm_error ("\n\n[ FAIL ] INFO : WB_ScoreBoard", $sformatf("\n\n[ FAIL ]I_TYPE_SHIFT - srli - without frwd SB FAIL "))
                           
                           
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]I_TYPE_SHIFT - srli - without frwd SB FAIL\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction))
                              end



                             end

                           end
                          end
                          
                          6:begin            // ori I-TYPE

                              //  `uvm_info(get_name(),$sformatf("\n\n[ori]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3),UVM_MEDIUM)

                                     immi  ={{(32-12){sq_i_all[0].instruction[31]}},sq_i_all[0].instruction[31:20]};
                            
                                        if(forward_a==1)
                                            begin
                                                i_out = alu_out | immi;
                                            end

                                        else
                                            begin
                                                i_out = rs1_gpr  | immi;
                                                rd    = sq_i_all[0].rd;
                                            end
                            
                            if(out == i_out)
                                 begin
                              `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS I_TYPE_ARITH", UVM_MEDIUM) 
                           
                           
                            `uvm_info (get_name(), $sformatf("\n\n[ PASS ]I_TYPE_ARITH SB PASS\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction),UVM_MEDIUM)
                              end
                            
                            else
                                 begin
                             `uvm_error ("\n\n[ FAIL ] INFO : WB_ScoreBoard", $sformatf("\n\n[ FAIL ]I_TYPE_ARITH ori SB FAIL "))
                            
                       
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]I_TYPE_ARITH ori SB FAIL\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction))
                              end
                       


                            end

                          7 : begin     // andi I-Type                                            
                          
                           //   `uvm_info(get_name(),$sformatf("\n\n[andi]rs1=%d, rs2=%d, rs1_gpr=%h, rs2_gpr=%h, reg_mem_rs1=%h, reg_mem_rs2=%h, out=%h, func3=%d",rs1,rs2,rs1_gpr,rs2_gpr,sb_reg_data[rs1],sb_reg_data[rs2],out,funct3),UVM_MEDIUM)
                                      immi  ={{(32-12){sq_i_all[0].instruction[31]}},sq_i_all[0].instruction[31:20]};
                           
                                 if(forward_a==1)
                                    begin
                                     i_out = alu_out & immi;
                                    end

                                 else
                                    begin
                                      i_out = rs1_gpr & immi;
                                      rd      = sq_i_all[0].rd;
                                    end
                        
                            if(out == i_out)
                                 begin
                              `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS I_TYPE_ARITH", UVM_MEDIUM) 
                        
                             `uvm_info (get_name(), $sformatf("\n\n[ PASS ]I_TYPE_ARITH SB PASS\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction),UVM_MEDIUM)
                              end
                            
                            else
                                 begin
                             `uvm_error ("\n\n[ FAIL ] INFO : WB_ScoreBoard", $sformatf("\n\n[ FAIL ]I_TYPE_ARITH andi SB FAIL "))
                            
                       
                             `uvm_error (get_name(), $sformatf("\n\n[ FAIL ]I_TYPE_ARITH andi SB FAIL\n immi=%d,\ni_out=%d,\nout=%d\ninstruction is=%0h ", immi,i_out,out,sq_i_all[0].instruction))
                              end
                       


                            end

                    default : begin
                               i_out = rs1_gpr + rs1_gpr ;

                              end
                     endcase   

              end

              //---------------------------------------------- I- TYPE - JALR-----------------------------------
              
              else if( sq_i_all[0].opcode == 'h67)   

              begin
                // rd      = sq_i_all[0].rd;
                // $display("RD value is : %h",rd);
                
                out = sq_i_all[3].out;
                rd_sb  =sq_i_all[0].pc-20'd4 ;
              
              //  $display(" rd_mon11 value is : %h",rd_sb);
              //  $display("--------value of out is -----------: %h",out);

              if(rd_sb == out)
                 `uvm_info("\n\n[ PASS ] INFO : WB_ScoreBoard", " SB PASS I_TYPE_JALR", UVM_MEDIUM) 
              else
                 `uvm_error("\n\n[ FAIL ] INFO : WB_ScoreBoard", $sformatf("\n\n[ FAIL ]I_TYPE_JALR SB FAIL "))

            end

         //-------------------------------------- Shifting Packages ------------------------------------
              
                    for (int i=0;i<3;i++)
                        begin
                            sq_i_all[i]=sq_i_all[i+1];
                        end
                    wb_out_sb.get(sq_i_all[3]);


                end : Non_NOP_Block

                end : Remaining_Packets

            
            end 
            //`uvm_info(get_type_name(),$sformatf("=====>>>>>step8.0: Inside WB_ScoreBoard Done- drop objection in WB_ScoreBoard"), UVM_MEDIUM)
            //`uvm_info(get_type_name(),$sformatf("=====>>>>>step8: Inside WB_ScoreBoard Done- drop objection in WB_ScoreBoard"), UVM_MEDIUM)

           // phase.drop_objection(this);
      end
          endtask
          
  

  endclass  

