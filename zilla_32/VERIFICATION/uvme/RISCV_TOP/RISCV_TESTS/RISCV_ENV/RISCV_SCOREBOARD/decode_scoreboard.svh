//User-defined class
class decode_scoreboard extends uvm_scoreboard;

//Factory registration
     `uvm_component_utils(decode_scoreboard)

       
  
//Analysis port to receive sequence item from monitor
    // uvm_analysis_imp #(decode_seq_item,decode_scoreboard) sb_port;   
     
  uvm_blocking_get_port #(decode_seq_item) dcd_out_sb; //tlm fifo

//Queue for storing sequence item from monitor 
    // decode_seq_item queue[$];          
     //decode_seq_item seq_d;

     /*decode_seq_item sb_decode[$];
     
      decode_seq_item sb_seq;
   decode_seq_item sb_seq_q;*/ 
     //Local variables
         int m_num_tx = 2;
         logic [31:0] sb_instruction;
         logic [6:0]  sb_opcode;
         logic [2:0]  sb_func3;
         logic [2:0]  func3;
         logic [6:0]  sb_func7;
         logic [31:0] sb_imm;
         logic [31:0] sb_immu;
         logic [11:0] sb_IMM;
         logic [4:0]  sb_rs1;
         logic [4:0]  sb_rs2;
         logic [4:0]  sb_rd;
         logic        sb_valid;
         logic        sb_type;
         logic        sb_SB_imm11;
         logic [3:0]  sb_SB_imm41;
         logic [5:0]  sb_SB_imm510;
         logic        sb_SB_imm12;
         logic        sb_uj_imm20;
         logic [9:0]  sb_uj_imm101;
         logic        sb_uj_imm11;
         logic [8:0]  sb_uj_imm1912;
         logic [19:0] sb_uj_imm;
         logic [19:0] sb_u_imm;
         logic        sb_waste = 0;
         logic        sb_wait = 0;
        
        //Enable signal
         logic       reg_wr_en_r;			    
         logic       mem_rd_en_r;			        
         logic       mem_wr_en_r;	

 /* $readmemh("sb_instruction.hex", inst_mem);//need to change
     foreach(inst_mem[i])
       begin
           inst_mem[i]= 
       end*/

// Constructor
  function new (string name = "scoreboard", uvm_component parent = null);
    super.new (name, parent);
  endfunction

//Build phase
  function void build_phase (uvm_phase phase);
    super.build_phase(phase);
      `uvm_info(get_type_name(),$sformatf("Build_phase in sb"),UVM_LOW) 
      // sb_port	 = new("sb_port", this);
        dcd_out_sb	 = new("dcd_out_sb", this);

  endfunction

//Write function - To receive seq_item from monitor
  //virtual function void write (input decode_seq_item pkt);
  // queue.push_back(pkt);             //stores the received sequence item
 // endfunction

//Run phase - To check functionality of DUT
  task run_phase(uvm_phase phase);
 
   decode_seq_item seq_d;

    phase.raise_objection(this);
   // decode_seq_item seq_d*/
   repeat (m_num_tx) 
   // forever
        begin  //start
         //TLM 
                dcd_out_sb.get(seq_d);

         // wait(queue.size() > 0);   // Will wait till queue gets data from monitor
            begin //start

             //seq_d = queue.pop_front();

             sb_instruction = seq_d.instruction;
             sb_opcode      = sb_instruction[6:0];
             sb_valid       = seq_d.valid;
             func3          = sb_instruction[14:12];

    /*if(sb_instruction == 'hX)begin //start
        $display("Escape");
        end //end

    else begin   //start 
         $display("Into the SB CHECK");

         if(sb_waste == 0)begin //start
             seq_d = queue.pop_front();
             sb_waste = 1;
         end //end
       
         else begin //start
            $display("Intoseq_d.imm the SB LOGIC");*/


            if(sb_valid == 1)begin //start

            if(sb_opcode == 'h33)
             begin //start
    
             sb_rd     = sb_instruction[11:7];
             sb_func3 = sb_instruction[14:12];
             sb_rs1    = sb_instruction[19:15];
             sb_rs2    = sb_instruction[24:20];
             sb_func7 = sb_instruction[31:25];
             sb_type   = 1;
            
       if(seq_d.rd == sb_rd && seq_d.func3 == sb_func3 && seq_d.rs1 == sb_rs1 && seq_d.rs2 == sb_rs2 && seq_d.func7 == sb_func7 )begin
    `uvm_info ("DECODER SCOREBOARD ", $sformatf (" R TYPE DECODE SUCCESSFUL"),UVM_LOW);
    end
    else begin 
        `uvm_error ("DECODER SCOREBOARD " , $sformatf ("R TYPE DECODE UNSUCCESSFUL"));


     end
     
             end //end
              
             
             
             
             begin
              sb_rd     = sb_instruction[11:7];
              sb_func3 = sb_instruction[14:12];
              sb_rs1 = sb_instruction[19:15];
              sb_imm  ={{(32-12){sb_instruction[31]}},sb_instruction[31:20]};
              sb_immu  ={20'b0,sb_instruction[31:20]}; //For Unsigned
             if(sb_opcode == 'h13 && func3==5)
               begin
                  if(sb_imm[11:5]==0100000)
                    begin
                     if(seq_d.rd == sb_rd && seq_d.func3 == sb_func3 && seq_d.rs1 == sb_rs1  && seq_d.imm == sb_imm  )
                        begin
                        `uvm_info ("DECODER SCOREBOARD ", $sformatf ("I TYPE DECODE SUCCESSFUL"),UVM_LOW);
                        end
                     else
                         begin 
                          `uvm_error ("DECODER SCOREBOARD " , $sformatf ("I TYPE DECODE UNSUCCESSFUL"));
                         end
                    end     
                   else if (sb_immu[11:5]==0000000)
                       begin
                       if(seq_d.rd == sb_rd && seq_d.func3 == sb_func3 && seq_d.rs1 == sb_rs1  && seq_d.imm == sb_immu  )
                        begin
                        `uvm_info ("DECODER SCOREBOARD ", $sformatf ("I TYPE DECODE SUCCESSFUL"),UVM_LOW);
                        end
                     else
                         begin 
                          `uvm_error ("DECODER SCOREBOARD " , $sformatf ("I TYPE DECODE UNSUCCESSFUL"));
                         end
                       end
              end
           end 



             if((sb_opcode == 'h13 && func3 inside{0,1,2,3,4,6,7})|| sb_opcode == 'h3 || sb_opcode == 'h67)
              begin //start
              sb_rd     = sb_instruction[11:7];
              sb_func3 = sb_instruction[14:12];
              sb_rs1    = sb_instruction[19:15];
              sb_imm    = {{(32-12){sb_instruction[31]}},sb_instruction[31:20]};             
              sb_type   = 2;
        
        $display ("decode");
        $display ("rd %h",sb_rd);
        $display ("func3 %h ",sb_func3);
        $display ("rs1 %h",sb_rs1);
        $display ("rs2 %h",sb_rs2);
        $display ("func7 %h",sb_func7);
        $display ("IMM %h",sb_imm);

        if(seq_d.rd == sb_rd && seq_d.func3 == sb_func3 && seq_d.rs1 == sb_rs1  && seq_d.imm == sb_imm  )
          begin
           `uvm_info ("DECODER SCOREBOARD ", $sformatf ("I TYPE DECODE SUCCESSFUL"),UVM_LOW);
          end

    else begin 
        `uvm_error ("DECODER SCOREBOARD " , $sformatf ("I TYPE DECODE UNSUCCESSFUL"));
end

              end //end

              if(sb_opcode == 'h23)
              begin //start};
              

              sb_func7    = sb_instruction[31:25];
              sb_rd     = sb_instruction[11:7];
              sb_func3  = sb_instruction[14:12];
              sb_rs1    = sb_instruction[19:15];
              sb_rs2    = sb_instruction[24:20];
        
           //   sb_imm    = {$signed(sb_func7[31]),sb_func7[30:25],sb_rd};
              sb_imm    = {{(32-12){sb_instruction[31]}},sb_instruction[31:25],sb_instruction[11:7]};    
                /*if(sb_func7[31] == 1)begin
                    sb_imm = {20'b1,sb_func7,sb_rd};
                end
                else begin
                    sb_imm = {20'b0,sb_func7,sb_rd};
                end  */  
              sb_type   = 3;
         
        $display ("decode");
        $display ("rd %h",sb_rd);
        $display ("func3 %h ",sb_func3);
        $display ("rs1 %h",sb_rs1);
        $display ("rs2 %h",sb_rs2);
        $display ("func7 %h",sb_func7);
        $display ("IMM %h",sb_imm);


         if(seq_d.rs2 == sb_rs2 && seq_d.func3 == sb_func3 && seq_d.rs1 == sb_rs1 && seq_d.imm == sb_imm  )begin
    `uvm_info ("DECODER SCOREBOARD ", $sformatf ("S TYPE DECODE SUCCESSFUL"),UVM_LOW);
    
end

    else begin 
        `uvm_error ("DECODER SCOREBOARD " , $sformatf ("S TYPE DECODE UNSUCCESSFUL"));


    end


              end //end
            
            begin
              if(sb_opcode == 'h63)
               begin //start
                sb_func3  = sb_instruction[14:12];
                sb_rs1    = sb_instruction[19:15];
               // sb_func7  = sb_instruction[31:25];
                sb_rs2    = sb_instruction[24:20];
                //sb_rd     = sb_instruction[11:7];
                sb_type   = 4;
                sb_imm ={{(32-13){sb_instruction[31]}},sb_instruction[31],sb_instruction[7],sb_instruction[30:25],sb_instruction[11:8],1'b0};                
               
        $display ("rd %h",sb_rd);
        $display ("func3 %h ",sb_func3);
        $display ("rs1 %h",sb_rs1);
        $display ("rs2 %h",sb_rs2);
        //$display ("func7 %h",sb_func7);
        $display ("IMM %h",sb_imm);
 
     if(seq_d.rs2 == sb_rs2 && seq_d.func3 == sb_func3 && seq_d.rs1 == sb_rs1 && seq_d.imm == sb_imm )begin
    `uvm_info ("DECODER SCOREBOARD ", $sformatf ("SB TYPE DECODE SUCCESSFUL"),UVM_LOW);
    end

    else begin 
        `uvm_error ("DECODER SCOREBOARD " , $sformatf ("SB TYPE DECODE UNSUCCESSFUL"));


    end

        
               end //end

              if(sb_opcode == 'h37)
               begin //start
                sb_u_imm    = sb_instruction[31:12];
                sb_rd       = sb_instruction[11:7];
                sb_type     = 5;

                sb_imm = {sb_u_imm,12'b0};
                
        $display ("decode");
        $display ("rd %h",sb_rd);
        $display ("func3 %h ",sb_func3);
        $display ("rs1 %h",sb_rs1);
        $display ("rs2 %h",sb_rs2);
        $display ("func7 %h",sb_func7);
        $display ("IMM %h",sb_imm);



         if(seq_d.rd == sb_rd && seq_d.imm == sb_imm )begin
    `uvm_info ("DECODER SCOREBOARD ", $sformatf ("U TYPE DECODE SUCCESSFUL"),UVM_LOW);
    end

    else begin 
        `uvm_error ("DECODER SCOREBOARD " , $sformatf ("U TYPE DECODE UNSUCCESSFUL"));


    end


               end  //end
    end           

               if(sb_opcode == 'h6F)
               begin  //start
                 
                sb_opcode     = sb_instruction[6:0];
               

                sb_uj_imm = {sb_uj_imm20,sb_uj_imm1912,sb_uj_imm11,sb_uj_imm101};
                                
                                
                sb_rd    = sb_instruction[11:7];
                sb_type  = 6;
                sb_imm   ={{(32-21){sb_instruction[31]}},sb_instruction[31],sb_instruction[19:12],sb_instruction[20],sb_instruction[30:21],1'b0};
 

        $display ("decode");
        $display ("rd value %h",sb_rd);
        $display ("code %h ",sb_opcode);
        $display ("IMM %h",sb_imm);




        if(seq_d.rd == sb_rd && seq_d.imm == sb_imm )begin
             
    `uvm_info ("DECODER SCOREBOARD ",$sformatf("UJ TYPE DECODE SUCCESSFUL"),UVM_LOW);
    end

    else begin 
        `uvm_error ("DECODER SCOREBOARD " , $sformatf ("UJ TYPE DECODE UNSUCCESSFUL"));


    end

               end //end

                if(sb_opcode == 'hD)
                begin // start
                 sb_rd     = 0;
                 sb_func3  = 0;
                 sb_rs1    = 0;
                 sb_rs2    = 0;
                 sb_func7  = 0;
                 sb_type   = 7;

                 if(seq_d.rd == sb_rd && seq_d.func3 == sb_func3 && seq_d.rs1 == sb_rs1 && seq_d.rs2 == sb_rs2 && seq_d.func7 == sb_func7 )begin
    `uvm_info ("DECODER SCOREBOARD ", $sformatf (" NO OPERATION DECODE SUCCESSFUL"),UVM_LOW);
    end

                end //end

               else 
                begin //start
             $display ("INVALID INSTRUCTION");
                end // end


    end //97end
 end 

                /* sb_seq.rd     = sb_rd;
                 sb_seq.func3 = sb_func3; 
                 sb_seq.rs1    = sb_rs1;        
                 sb_seq.rs2    = sb_rs2;           
                 sb_seq.func7 = sb_func7;
                 sb_seq.imm    = sb_imm;

                sb_decode.push_back(sb_seq);

    if(sb_wait == 0)begin
        $display("aaguthunna");
        sb_wait = 1;
    end
                  
    else begin                      
                                
      sb_seq_q = sb_decode.pop_front;

      if(
          (sb_seq_q.rd    == sb_seq.rd) &&
          (sb_seq_q.rs1   == sb_seq.rs1) &&
          (sb_seq_q.rs2   == sb_seq.rs2) &&
          (sb_seq_q.imm   == sb_seq.imm) &&
          (sb_seq_q.func3 == sb_seq.func3) &&
          (sb_seq_q.func7 == sb_seq.func7) 

          )begin
        $display ("Fetch");
        $display ("rd %h",sb_seq_q.sb_rd);
        $display ("func3 %h ",sb_seq_q.sb_func3);
        $display ("rs1 %h",sb_seq_q.sb_rs1);
        $display ("rs2 %h",sb_seq_q.sb_rs2);
        $display ("func7 %h",sb_seq_q.sb_func7);





        $display ("decode");
        $display ("rd %h",sb_rd);
        $display ("func3 %h ",sb_func3);
        $display ("rs1 %h",sb_rs1);
        $display ("rs2 %h",sb_rs2);
        $display ("func7 %h",sb_func7);

         `uvm_info ("DECODER SCOREBOARD ", $sformatf (" DECODE SUCCESSFUL"),UVM_LOW);
                                            

        end
        else begin

        `uvm_error ("DECODER SCOREBOARD " , $sformatf (" DECODE UNSUCCESSFUL"));
            end
        end*/

        //-------------------------comparision--------------------------
    

end
   phase.drop_objection(this);

        endtask
    endclass







