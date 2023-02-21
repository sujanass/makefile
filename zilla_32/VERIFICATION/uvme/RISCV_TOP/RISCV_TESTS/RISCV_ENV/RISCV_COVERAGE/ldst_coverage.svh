class ldst_coverage extends uvm_subscriber #(seq_item_ldst);

//factory registration
    `uvm_component_utils(ldst_coverage)

//sequence item instantiation
    seq_item_ldst seq_item_inst;

//covergroup - set of coverage points
    covergroup ldst_cov;
    option.name = "ldst_coverage";

//Coverpoint
    
    READ_EN   :  coverpoint seq_item_inst.data_mem_read_en_o
                                 {   
                                     ignore_bins low = {0};
                                     bins high= {1};
                                 }

    WRITE_EN  :  coverpoint seq_item_inst.data_mem_write_en_o
                                 {   
                                     ignore_bins low = {0};
                                     bins high = {1};
                                 }

   LOAD_VALID_OUT : coverpoint seq_item_inst.load_valid_out

                                {
                                     ignore_bins low = {0};
                                     bins high = {1};
                                }
   STORE_VALID_OUT : coverpoint seq_item_inst.store_valid_out

                                {
                                     ignore_bins low = {0};
                                     bins high = {1};
                                }


    READ_ADDRESS : coverpoint seq_item_inst.data_mem_read_addr_o
                                {
                                     bins mailbox_addr[] = {294912, 294916, 294920, 295176,295180};
                                     bins start_addr = {[294928:295680]};
                                     bins end_addr = {[556755:557055]};
                                     bins addr_0[4]  = {[295680:395680],[320681:345681],[345681:370682],[370683:395682]};
                                     bins addr_1[4] = {[395683:420683],[420684:445684],[445685:470685],[470685:495681]};
                                     bins addr_2[3]  = {[495682:520682],[520683:545683],[545683:556755]};
                                    // ignore_bins addr_all[] = {[294912:557055]} with (item % 4 == 0);                                                                             
                                     //illegal_bins addr_illegal_1[] = {[0:294912]}; 
                                     //illegal_bins addr_illegal_2[] = {[557055:$]};

                                 } 

    READ_DATA :  coverpoint seq_item_inst.data_mem_read_data_i
                                 {           
                                     option.auto_bin_max = 32; 
                                 }

                                 

    WRITE_ADDRESS : coverpoint seq_item_inst.data_mem_write_addr_o
                                {
                                     bins mailbox_addr_w[] = {294912, 294916, 294920, 295176,295180};
                                     bins start_addr_w = {[294928:295680]};
                                     bins end_addr_w = {[556755:557055]};
                                     bins addr_0_w[4]  = {[295680:395680],[320681:345681],[345681:370682],[370683:395682]};
                                     bins addr_1_w[4] = {[395683:420683],[420684:445684],[445685:470685],[470685:495681]};
                                     bins addr_2_w[3]  = {[495682:520682],[520683:545683],[545683:556755]};
                                     //all address location
                                    // bins addr_all_w[100] = {[295680:556755]} with (item % 4 == 0);
                                    // illegal_bins addr_illegal_1_w[] = {[0:294912]}; 
                                     //illegal_bins addr_illegal_2_w[] = {[557055:$]};
                                     }

     WRITE_DATA : coverpoint seq_item_inst.data_mem_write_data_o
                               
                                    { 
                                       option.auto_bin_max = 32;  
                                     }

   DATA_STROBE : coverpoint seq_item_inst.data_mem_strobe_o
                                    {
                                        bins strobe[] = {0,15};
                                    }
   
    REG_WRITE_EN  :  coverpoint seq_item_inst.reg_wr_en
                                 {   
                                     ignore_bins low = {0};
                                     bins high = {1};
                                 }
     
   
    REG_WRITE_ADDR : coverpoint seq_item_inst.reg_wr_addr
                                 {   
                                     bins reg_addr[32] = {[0:31]};
                                 }


    REG_WRITE_DATA  : coverpoint seq_item_inst.reg_wr_data
                                {
                                    option.auto_bin_max = 32;
                                }

    SIGN_BIT       :  coverpoint seq_item_inst.sign_bit

                                {
                                     bins low = {0};
                                     bins high  = {1};
                                }

    BYTE_SEL  : coverpoint seq_item_inst.byte_sel_o
                                {
                                   bins sel[3] = {0,1,2};

                                }

    MEM_WRITE_STALL :  coverpoint seq_item_inst.data_mem_write_en_to_stall

                                {
                                     bins low = {0};
                                     bins high  = {1};
                                }

   ALU_CTRL        :  coverpoint seq_item_inst.alu_ctrl
                                    
                                {
                                     bins lb = {3};
                                     bins lh = {131};
                                     bins lw = {259};
                                     bins lbu = {515};
                                     bins lhu = {643};
                                     bins lwu = {771};
                                     bins sh = {163};
                                     bins sw = {291};
                                }
    FORWARD_A      : coverpoint seq_item_inst.forward_a
                                {
                                    bins forward_a[4] = {[0:4]};
                                }


   BYTE_ENABLE     : coverpoint seq_item_inst.byte_en
                               {
                                   bins byte_en[] = {0,1,3,15};
                               } 


    CROSS_COVERAGE_READ_A : cross READ_EN,READ_ADDRESS;
    CROSS_COVERAGE_READ_D : cross READ_EN,READ_DATA;

    CROSS_COVERAGE_WRITE_A : cross WRITE_EN,WRITE_ADDRESS;
    CROSS_COVERAGE_WRITE_D : cross WRITE_EN,WRITE_DATA;

    CROSS_COVERAGE_STROBE_WRITE  : cross WRITE_DATA,DATA_STROBE;
    CROSS_COVERAGE_STROBE_READ   : cross READ_DATA,DATA_STROBE;

    CROSS_COVERAGE_REG : cross REG_WRITE_EN,REG_WRITE_ADDR;

   endgroup
    
//constructor new
        function new(string name ="ldst_coverage", uvm_component parent);
            super.new(name, parent);
            ldst_cov  = new();
        endfunction


        function void write(seq_item_ldst t);
            seq_item_inst = new();        
            $cast(seq_item_inst,t);
             `uvm_info(get_type_name(),$sformatf("The coverage write data is %0d",seq_item_inst.data_mem_write_addr_o
),UVM_NONE)

            ldst_cov.sample();  //samples each time
        endfunction

endclass                                


   


