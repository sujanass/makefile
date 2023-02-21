parameter DM_WIDTH = 32;
parameter DM_END_ADDR = 65535;



`ifdef FIRMWARE
    `define FIRMWARE_DUMP_EN 1
`else
    `define FIRMWARE_DUMP_EN 0
`endif




class agent_dm extends uvm_agent;

//Factory registration
    `uvm_component_utils(agent_dm)

//Instantiations
            
        //Virtual interface instantiation
        virtual riscv_intf vif;

        //local variables 
        logic [DM_WIDTH-1:0] wr_addr_in;
        logic [DM_WIDTH-1:0] rd_addr_in;

        event phase_reset;

        // data .hex file handling
        integer count=0;
        int file_handle;
        string line;
        int rand_number;



        //array of 256KB of 1 word
        static logic [7:0] data_mem [294912:557055];
        static logic [DM_WIDTH-1:0] data_mem_arr [int];

        //Constructor
        function new(string name ="agent_dm" , uvm_component parent);
            super.new(name, parent);
        endfunction

               
        //Build phase
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
           // `uvm_info(get_name(),$sformatf("=====>>>>> inside dm agent"),UVM_MEDIUM)
            //If virtual interface not connected via config db, drop the entire process
            if (!uvm_config_db#( virtual riscv_intf)::get(this, "*", "riscv_intf", vif))
                `uvm_fatal(get_full_name(),{"Virtual Interface must be set for:",".riscv_intf"});

        endfunction
        
        task reset_phase (uvm_phase phase);
        //loading static memory by using .hex file
	    if(`FIRMWARE_DUMP_EN)
        begin
            //`uvm_info(get_name(),$sformatf("C dump into the array happened in Im_agent"),UVM_MEDIUM)
            
            file_handle = $fopen("$tb_dir/uvme/RISCV_TOP/data.hex","r");
            
            if(file_handle)
                begin
            
                    $display("file opened in read mode");
                    while(!$feof(file_handle))
                        begin
                        $fgets(line,file_handle);
                        $display(line,count);
                        count++;
                        end
                    $fclose(file_handle);
                    count =count-1;
                    $display("count:",(count));
                $display("remaining lines :",(65536-count));
                file_handle= $fopen("$tb_dir/uvme/RISCV_TOP/data.hex", "a");
            
                for (int i = 0; i < (65536-count); i++) 
                    begin
                        rand_number = $random();
                        $fwrite(file_handle,$sformatf("%8h\n",rand_number) );
                    end
                $fclose(file_handle); 
            
            
            
                end
            
            
            else
                begin
                    $display("data.hex file not opned in read mode");
                end
            
            


            $readmemh("$tb_dir/uvme/RISCV_TOP/data.hex", data_mem_arr);
           /* foreach (data_mem[i])
                 begin
                  $display("DATA_MEM[%d] = %h", i, data_mem[i]);
                 end*/
/*
                for(int i =0;i<65536;i++)
                begin
                    

                    $display("4123 DATA_MEM[%h]=%h",(294912+(i*4)),data_mem[i]);

                end
*/

/*
              foreach(data_mem[i])
                begin
                    $display(" 4123 DATA_MEM[%h]=%h",i,data_mem[i]);
                end
*/

              foreach(data_mem_arr[i])
                begin
                    $display("here: 1432 data_mem_arr[%h]=%h",i,data_mem_arr[i]);
                end

             foreach(data_mem_arr[i])
              begin
                {
                 data_mem[((i*4)+294912+3)],
                 data_mem[((i*4)+294912+2)],
                 data_mem[((i*4)+294912+1)],
                 data_mem[(i*4)+294912]} = data_mem_arr[i];

                    $display("here: i :%d",i);
                    $display("here: data_mem_arr[%d] :%h",i,data_mem_arr[i]);

              end



              foreach(data_mem[i])
                begin
                    $display("C DATA_MEM[%h]=%h",i,data_mem[i]);
                end

        end
        else
        begin
            $readmemh("$tb_dir/uvme/RISCV_TOP/data.hex", data_mem_arr);
             foreach(data_mem_arr[i])
              begin
                {
                 data_mem[((i*4)+294912+3)],
                 data_mem[((i*4)+294912+2)],
                 data_mem[((i*4)+294912+1)],
                 data_mem[(i*4)+294912]} = data_mem_arr[i];

                    $display("here: i :%d",i);
                    $display("here: data_mem_arr[%d] :%h",i,data_mem_arr[i]);

              end



              foreach(data_mem[i])
                begin
                    $display("UVM DATA_MEM[%h]=%h",i,data_mem[i]);
                end
        end
             
            ->phase_reset;
        endtask 

        task run_phase(uvm_phase phase);
/*    

         `uvm_info(get_name(),$sformatf("=====>>>>> inside dm agent RUN PHASE - START"),UVM_MEDIUM)
         //To store data into desired memory location

           @(phase_reset)
           fork 
                forever
                begin

                    //To read data from memory
                    @ (vif.dm_cb iff (vif.data_mem_read_en_o && vif.data_mem_read_addr_o > 294911))
                          `uvm_info(get_name(),$sformatf("====>>>>Inside read operation<<<<===="),UVM_MEDIUM)
                        begin
                        //logic to convert address from ZCore to word readable
                           $display("DATA READ ADDR = %h",vif.data_mem_read_addr_o);
                            rd_addr_in = vif.data_mem_read_addr_o - 294912;
                            rd_addr_in = rd_addr_in >> 2;
                            @(vif.dm_cb) begin
                                vif.data_mem_read_data_i = data_mem [rd_addr_in];
                               $display("8. data_mem[%d]=%d",rd_addr_in,data_mem [rd_addr_in]);
                            end
                             `uvm_info(get_name(),$sformatf("=====>>>>Read operation is completed<<<<===="),UVM_MEDIUM)

                        end
 
                 end
                          forever
                begin
                    $display("time = %dns data_mem_write= %d WRITE ADDR=%h",$stime,vif.data_mem_write_en_o,vif.data_mem_write_addr_o);
                    @ (vif.dm_cb iff (vif.data_mem_write_en_o && vif.data_mem_read_addr_o > 294911))
         
                        begin
                          // $display("DATA MEM WRITE ADDR = %d",vif.data_mem_write_addr_o);   
                          `uvm_info(get_name(),$sformatf("====>>>>Inside Write operation<<<<==== "),UVM_MEDIUM)
                        //logic to convert address from ZCore to word writable
                            wr_addr_in = vif.data_mem_write_addr_o - 294912;
                            wr_addr_in = wr_addr_in>>2;

                        //assigning value to array
                            data_mem [wr_addr_in] = vif.data_mem_write_data_o;
                          //  $display("4. data_write_mem[%d]=%h",wr_addr_in,data_mem [wr_addr_in]);
                            $display("DATA MEM WRITE DATA = %h",vif.data_mem_write_data_o);
                            
                        end
                         `uvm_info(get_name(),$sformatf("====>>>>Write operation is completed<<<<===="),UVM_MEDIUM)

                end
          join
         `uvm_info(get_name(),$sformatf("=====>>>>> inside dm agent RUN PHASE - DONE"),UVM_MEDIUM) 
*/

         `uvm_info(get_name(),$sformatf("=====>>>>> inside dm agent RUN PHASE - START"),UVM_MEDIUM)
         //To store data into desired memory location

           @(phase_reset)
           fork 

                forever
                begin
                    $display("[Data_Mem_Write]time = %dns data_mem_write= %d\n WRITE ADDR=%h",$stime,vif.data_mem_write_en_o,vif.data_mem_write_addr_o);
                    @ (vif.dm_cb iff (vif.data_mem_write_en_o && vif.data_mem_write_addr_o > 294911))
         
                        begin
                          // $display("DATA MEM WRITE ADDR = %d",vif.data_mem_write_addr_o);   
                          `uvm_info(get_name(),$sformatf("====>>>>Inside Write operation<<<<==== "),UVM_MEDIUM)
                        //logic to convert address from ZCore to word writable
                            wr_addr_in = vif.data_mem_write_addr_o;
                            
                        //assigning value to array
                            data_mem [wr_addr_in] = vif.data_mem_write_data_o[7:0];
                            data_mem [wr_addr_in+1] = vif.data_mem_write_data_o[15:8];
                            data_mem [wr_addr_in+2] = vif.data_mem_write_data_o[23:16];
                            data_mem [wr_addr_in+3] = vif.data_mem_write_data_o[31:24];
                          //  $display("4. data_write_mem[%d]=%h",wr_addr_in,data_mem [wr_addr_in]);
                            $display("[Data_Mem_Write]CPU DATA MEM WRITE DATA = %h",vif.data_mem_write_data_o);
                            $display("[Data_Mem_Write]DATA MEM WRITTEN DATA = %h",{data_mem [wr_addr_in+3],data_mem [wr_addr_in+2],data_mem [wr_addr_in+1],data_mem [wr_addr_in]});
                            
                        end
                         `uvm_info(get_name(),$sformatf("====>>>>Write operation is completed<<<<===="),UVM_MEDIUM)

                end






                forever
                begin

                    //To read data from memory
                    @ (vif.dm_cb iff (vif.data_mem_read_en_o && vif.data_mem_read_addr_o > 294911))
                          `uvm_info(get_name(),$sformatf("[Data_Mem_Read] ====>>>>Inside read operation<<<<===="),UVM_MEDIUM)
                        begin
                        //logic to convert address from ZCore to word readable
                           $display("[Data_Mem_Read] DATA READ ADDR = %h",vif.data_mem_read_addr_o);
                            rd_addr_in = vif.data_mem_read_addr_o ;
                           
                            @(vif.dm_cb) begin
                                vif.data_mem_read_data_i[7:0]   = data_mem [rd_addr_in];
                                vif.data_mem_read_data_i[15:8]  = data_mem [rd_addr_in+1];
                                vif.data_mem_read_data_i[23:16] = data_mem [rd_addr_in+2];
                                vif.data_mem_read_data_i[31:24] = data_mem [rd_addr_in+3];
                               $display("[Data_Mem_Read] 8. data_mem[%h,%h,%h,%h]=%h\n",rd_addr_in+3,rd_addr_in+2,rd_addr_in+1,rd_addr_in,vif.data_mem_read_data_i);
                            end
                             `uvm_info(get_name(),$sformatf("=====>>>>Read operation is completed<<<<===="),UVM_MEDIUM)

                        end
 
                 end
          join
         `uvm_info(get_name(),$sformatf("=====>>>>> inside dm agent RUN PHASE - DONE"),UVM_MEDIUM)




         endtask

endclass
        



