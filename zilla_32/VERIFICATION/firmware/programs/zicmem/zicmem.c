//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////                                                                                                                                          //////
//////                                      ZIC_MEM_MAP                                                                                         //////
//////                                                                                                                                          //////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>          // Standard Input Output Library
#include <stdlib.h>         // Standard Library
#include "print.h"          // Print Function Library
#include "linker.h"         // Linker Symbols Library
#include "mailbox.h"        // Mailbox Function Library




//******************   USER DEFINED STRUCTURE   *******************
// User Defined Structure Defined to store ZIC Memory Registers 
typedef struct zic_mem_sp0{
    volatile uint8_t  zic_cfg;              // Offset : 0x0000
    volatile uint32_t zic_info;             // Offset : 0x0004
} zic_mem_sp0_t;

// Initializing The offset register_offset_address
#define ZIC_MEM_ADDR_SP0 ((zic_mem_sp0_t*) 0x00000)

//******************   USER DEFINED STRUCTURE   *******************
// User Defined Structure Defined to store ZIC Memory Registers 
typedef struct zic_mem_sp1{
    volatile uint8_t  zic_nxtp_int;         // Offset : 0x0800
    volatile uint8_t  zic_ack;              // Offset : 0x0804    
    volatile uint8_t  zic_eoi;              // Offset : 0x0808    
} zic_mem_sp1_t;

// Initializing The offset register_offset_address
#define ZIC_MEM_ADDR_SP1 ((zic_mem_sp1_t*) 0x800)

//******************   USER DEFINED STRUCTURE   *******************
// User Defined Structure Defined to store ZIC Memory Registers
typedef struct zic_mem_reg{   
    volatile uint8_t zic_int_p_0;           // Offset : 0x0000
    volatile uint8_t zic_int_en_0;          // Offset : 0x0001
    volatile uint8_t zic_int_attr_0;        // Offset : 0x0002
    volatile uint8_t zic_int_ctl_0;         // Offset : 0x0003 

    volatile uint8_t zic_int_p_1;           // Offset : 0x0004
    volatile uint8_t zic_int_en_1;          // Offset : 0x0005
    volatile uint8_t zic_int_attr_1;        // Offset : 0x0006
    volatile uint8_t zic_int_ctl_1;         // Offset : 0x0007 

    volatile uint8_t zic_int_p_2;           // Offset : 0x0008
    volatile uint8_t zic_int_en_2;          // Offset : 0x0009
    volatile uint8_t zic_int_attr_2;        // Offset : 0x000A
    volatile uint8_t zic_int_ctl_2;         // Offset : 0x000B

    volatile uint8_t zic_int_p_3;           // Offset : 0x000C
    volatile uint8_t zic_int_en_3;          // Offset : 0x000D
    volatile uint8_t zic_int_attr_3;        // Offset : 0x000E
    volatile uint8_t zic_int_ctl_3;         // Offset : 0x000F

    volatile uint8_t zic_int_p_4;           // Offset : 0x0010
    volatile uint8_t zic_int_en_4;          // Offset : 0x0011
    volatile uint8_t zic_int_attr_4;        // Offset : 0x0012
    volatile uint8_t zic_int_ctl_4;         // Offset : 0x0013

    volatile uint8_t zic_int_p_5;           // Offset : 0x0014
    volatile uint8_t zic_int_en_5;          // Offset : 0x0015
    volatile uint8_t zic_int_attr_5;        // Offset : 0x0016
    volatile uint8_t zic_int_ctl_5;         // Offset : 0x0017

    volatile uint8_t zic_int_p_6;           // Offset : 0x0018
    volatile uint8_t zic_int_en_6;          // Offset : 0x0019
    volatile uint8_t zic_int_attr_6;        // Offset : 0x001A
    volatile uint8_t zic_int_ctl_6;         // Offset : 0x001B

    volatile uint8_t zic_int_p_7;           // Offset : 0x001C
    volatile uint8_t zic_int_en_7;          // Offset : 0x001D
    volatile uint8_t zic_int_attr_7;        // Offset : 0x001E
    volatile uint8_t zic_int_ctl_7;         // Offset : 0x001F

    volatile uint8_t zic_int_p_8;           // Offset : 0x0020
    volatile uint8_t zic_int_en_8;          // Offset : 0x0021
    volatile uint8_t zic_int_attr_8;        // Offset : 0x0022
    volatile uint8_t zic_int_ctl_8;         // Offset : 0x0023

    volatile uint8_t zic_int_p_9;           // Offset : 0x0024
    volatile uint8_t zic_int_en_9;          // Offset : 0x0025
    volatile uint8_t zic_int_attr_9;        // Offset : 0x0026
    volatile uint8_t zic_int_ctl_9;         // Offset : 0x0027

    volatile uint8_t zic_int_p_10;          // Offset : 0x0028
    volatile uint8_t zic_int_en_10;         // Offset : 0x0029
    volatile uint8_t zic_int_attr_10;       // Offset : 0x002A
    volatile uint8_t zic_int_ctl_10;        // Offset : 0x002B

    volatile uint8_t zic_int_p_11;          // Offset : 0x002C
    volatile uint8_t zic_int_en_11;         // Offset : 0x002D
    volatile uint8_t zic_int_attr_11;       // Offset : 0x002E
    volatile uint8_t zic_int_ctl_11;        // Offset : 0x002F

    volatile uint8_t zic_int_p_12;          // Offset : 0x0030
    volatile uint8_t zic_int_en_12;         // Offset : 0x0031
    volatile uint8_t zic_int_attr_12;       // Offset : 0x0032
    volatile uint8_t zic_int_ctl_12;        // Offset : 0x0033

    volatile uint8_t zic_int_p_13;          // Offset : 0x0034
    volatile uint8_t zic_int_en_13;         // Offset : 0x0035
    volatile uint8_t zic_int_attr_13;       // Offset : 0x0036
    volatile uint8_t zic_int_ctl_13;        // Offset : 0x0037

    volatile uint8_t zic_int_p_14;          // Offset : 0x0038
    volatile uint8_t zic_int_en_14;         // Offset : 0x0039
    volatile uint8_t zic_int_attr_14;       // Offset : 0x003A
    volatile uint8_t zic_int_ctl_14;        // Offset : 0x003B

    volatile uint8_t zic_int_p_15;          // Offset : 0x003C
    volatile uint8_t zic_int_en_15;         // Offset : 0x003D
    volatile uint8_t zic_int_attr_15;       // Offset : 0x003E
    volatile uint8_t zic_int_ctl_15;        // Offset : 0x003F

    volatile uint8_t zic_int_p_16;          // Offset : 0x0040
    volatile uint8_t zic_int_en_16;         // Offset : 0x0041
    volatile uint8_t zic_int_attr_16;       // Offset : 0x0042
    volatile uint8_t zic_int_ctl_16;        // Offset : 0x0043

    volatile uint8_t zic_int_p_17;          // Offset : 0x0044
    volatile uint8_t zic_int_en_17;         // Offset : 0x0045
    volatile uint8_t zic_int_attr_17;       // Offset : 0x0046
    volatile uint8_t zic_int_ctl_17;        // Offset : 0x0047

    volatile uint8_t zic_int_p_18;          // Offset : 0x0048
    volatile uint8_t zic_int_en_18;         // Offset : 0x0049
    volatile uint8_t zic_int_attr_18;       // Offset : 0x004A
    volatile uint8_t zic_int_ctl_18;        // Offset : 0x004B

    volatile uint8_t zic_int_p_19;          // Offset : 0x004C
    volatile uint8_t zic_int_en_19;         // Offset : 0x004D
    volatile uint8_t zic_int_attr_19;       // Offset : 0x004E
    volatile uint8_t zic_int_ctl_19;        // Offset : 0x004F

    volatile uint8_t zic_int_p_20;          // Offset : 0x0050
    volatile uint8_t zic_int_en_20;         // Offset : 0x0051
    volatile uint8_t zic_int_attr_20;       // Offset : 0x0052
    volatile uint8_t zic_int_ctl_20;        // Offset : 0x0053

    volatile uint8_t zic_int_p_21;          // Offset : 0x0054
    volatile uint8_t zic_int_en_21;         // Offset : 0x0055
    volatile uint8_t zic_int_attr_21;       // Offset : 0x0056
    volatile uint8_t zic_int_ctl_21;        // Offset : 0x0057

    volatile uint8_t zic_int_p_22;          // Offset : 0x0058
    volatile uint8_t zic_int_en_22;         // Offset : 0x0059
    volatile uint8_t zic_int_attr_22;       // Offset : 0x005A
    volatile uint8_t zic_int_ctl_22;        // Offset : 0x005B

    volatile uint8_t zic_int_p_23;          // Offset : 0x005C
    volatile uint8_t zic_int_en_23;         // Offset : 0x005D
    volatile uint8_t zic_int_attr_23;       // Offset : 0x005E
    volatile uint8_t zic_int_ctl_23;        // Offset : 0x005F

    volatile uint8_t zic_int_p_24;          // Offset : 0x0060
    volatile uint8_t zic_int_en_24;         // Offset : 0x0061
    volatile uint8_t zic_int_attr_24;       // Offset : 0x0062
    volatile uint8_t zic_int_ctl_24;        // Offset : 0x0063

    volatile uint8_t zic_int_p_25;          // Offset : 0x0064
    volatile uint8_t zic_int_en_25;         // Offset : 0x0065
    volatile uint8_t zic_int_attr_25;       // Offset : 0x0066
    volatile uint8_t zic_int_ctl_25;        // Offset : 0x0067

    volatile uint8_t zic_int_p_26;          // Offset : 0x0068
    volatile uint8_t zic_int_en_26;         // Offset : 0x0069
    volatile uint8_t zic_int_attr_26;       // Offset : 0x006A
    volatile uint8_t zic_int_ctl_26;        // Offset : 0x006B

    volatile uint8_t zic_int_p_27;          // Offset : 0x006C
    volatile uint8_t zic_int_en_27;         // Offset : 0x006D
    volatile uint8_t zic_int_attr_27;       // Offset : 0x006E
    volatile uint8_t zic_int_ctl_27;        // Offset : 0x006F

    volatile uint8_t zic_int_p_28;          // Offset : 0x0070
    volatile uint8_t zic_int_en_28;         // Offset : 0x0071
    volatile uint8_t zic_int_attr_28;       // Offset : 0x0072
    volatile uint8_t zic_int_ctl_28;        // Offset : 0x0073

    volatile uint8_t zic_int_p_29;          // Offset : 0x0074
    volatile uint8_t zic_int_en_29;         // Offset : 0x0075
    volatile uint8_t zic_int_attr_29;       // Offset : 0x0076
    volatile uint8_t zic_int_ctl_29;        // Offset : 0x0077

    volatile uint8_t zic_int_p_30;          // Offset : 0x0078
    volatile uint8_t zic_int_en_30;         // Offset : 0x0079
    volatile uint8_t zic_int_attr_30;       // Offset : 0x007A
    volatile uint8_t zic_int_ctl_30;        // Offset : 0x007B

    volatile uint8_t zic_int_p_31;          // Offset : 0x007C
    volatile uint8_t zic_int_en_31;         // Offset : 0x007D
    volatile uint8_t zic_int_attr_31;       // Offset : 0x007E
    volatile uint8_t zic_int_ctl_31;        // Offset : 0x007F

    volatile uint8_t zic_int_p_32;          // Offset : 0x0080
    volatile uint8_t zic_int_en_32;         // Offset : 0x0081
    volatile uint8_t zic_int_attr_32;       // Offset : 0x0082
    volatile uint8_t zic_int_ctl_32;        // Offset : 0x0083

    volatile uint8_t zic_int_p_33;          // Offset : 0x0084
    volatile uint8_t zic_int_en_33;         // Offset : 0x0085
    volatile uint8_t zic_int_attr_33;       // Offset : 0x0086
    volatile uint8_t zic_int_ctl_33;        // Offset : 0x0087

    volatile uint8_t zic_int_p_34;          // Offset : 0x0088
    volatile uint8_t zic_int_en_34;         // Offset : 0x0089
    volatile uint8_t zic_int_attr_34;       // Offset : 0x008A
    volatile uint8_t zic_int_ctl_34;        // Offset : 0x008B

    volatile uint8_t zic_int_p_35;          // Offset : 0x008C
    volatile uint8_t zic_int_en_35;         // Offset : 0x008D
    volatile uint8_t zic_int_attr_35;       // Offset : 0x008E
    volatile uint8_t zic_int_ctl_35;        // Offset : 0x008F

    volatile uint8_t zic_int_p_36;          // Offset : 0x0090
    volatile uint8_t zic_int_en_36;         // Offset : 0x0091
    volatile uint8_t zic_int_attr_36;       // Offset : 0x0092
    volatile uint8_t zic_int_ctl_36;        // Offset : 0x0093

    volatile uint8_t zic_int_p_37;          // Offset : 0x0094
    volatile uint8_t zic_int_en_37;         // Offset : 0x0095
    volatile uint8_t zic_int_attr_37;       // Offset : 0x0096
    volatile uint8_t zic_int_ctl_37;        // Offset : 0x0097

    volatile uint8_t zic_int_p_38;          // Offset : 0x0098
    volatile uint8_t zic_int_en_38;         // Offset : 0x0099
    volatile uint8_t zic_int_attr_38;       // Offset : 0x009A
    volatile uint8_t zic_int_ctl_38;        // Offset : 0x009B

    volatile uint8_t zic_int_p_39;          // Offset : 0x009C
    volatile uint8_t zic_int_en_39;         // Offset : 0x009D
    volatile uint8_t zic_int_attr_39;       // Offset : 0x009E
    volatile uint8_t zic_int_ctl_39;        // Offset : 0x009F

    volatile uint8_t zic_int_p_40;          // Offset : 0x00A0
    volatile uint8_t zic_int_en_40;         // Offset : 0x00A1
    volatile uint8_t zic_int_attr_40;       // Offset : 0x00A2
    volatile uint8_t zic_int_ctl_40;        // Offset : 0x00A3

    volatile uint8_t zic_int_p_41;          // Offset : 0x00A4
    volatile uint8_t zic_int_en_41;         // Offset : 0x00A5
    volatile uint8_t zic_int_attr_41;       // Offset : 0x00A6
    volatile uint8_t zic_int_ctl_41;        // Offset : 0x00A7

    volatile uint8_t zic_int_p_42;          // Offset : 0x00A8
    volatile uint8_t zic_int_en_42;         // Offset : 0x00A9
    volatile uint8_t zic_int_attr_42;       // Offset : 0x00AA
    volatile uint8_t zic_int_ctl_42;        // Offset : 0x00AB

    volatile uint8_t zic_int_p_43;          // Offset : 0x00AC
    volatile uint8_t zic_int_en_43;         // Offset : 0x00AD
    volatile uint8_t zic_int_attr_43;       // Offset : 0x00AE
    volatile uint8_t zic_int_ctl_43;        // Offset : 0x00AF

    volatile uint8_t zic_int_p_44;          // Offset : 0x00B0
    volatile uint8_t zic_int_en_44;         // Offset : 0x00B1
    volatile uint8_t zic_int_attr_44;       // Offset : 0x00B2
    volatile uint8_t zic_int_ctl_44;        // Offset : 0x00B3

    volatile uint8_t zic_int_p_45;          // Offset : 0x00B4
    volatile uint8_t zic_int_en_45;         // Offset : 0x00B5
    volatile uint8_t zic_int_attr_45;       // Offset : 0x00B6
    volatile uint8_t zic_int_ctl_45;        // Offset : 0x00B7

    volatile uint8_t zic_int_p_46;          // Offset : 0x00B8
    volatile uint8_t zic_int_en_46;         // Offset : 0x00B9
    volatile uint8_t zic_int_attr_46;       // Offset : 0x00BA
    volatile uint8_t zic_int_ctl_46;        // Offset : 0x00BB

    volatile uint8_t zic_int_p_47;          // Offset : 0x00BC
    volatile uint8_t zic_int_en_47;         // Offset : 0x00BD
    volatile uint8_t zic_int_attr_47;       // Offset : 0x00BE
    volatile uint8_t zic_int_ctl_47;        // Offset : 0x00BF
}zic_mem_reg_t;

// Initializing The offset register_offset_address
#define ZIC_MEM_ADDR ((zic_mem_reg_t*) 0x1000)


//*************    RANDOMIZE FUNCTION for UINT8_t integer    *****************
//Variable Declaration
uint8_t num8;

//Function declaration to randomize the numbers
uint8_t rand_num8(){  
    
    num8 = (uint8_t)generate_random_num(MAILBOX1); 
    z_printf("Generated Random Number = %u\n",num8);    
}

//Variable Declaration
uint32_t num32;

//Function declaration to randomize the numbers
uint32_t rand_num32(){  
    
    num32 = (uint32_t)generate_random_num(MAILBOX1); 
    z_printf("Generated Random Number = %u\n",num32);    
}


//*************  STATRT OF MAIN() FUNCTION   *************
int main ()
{
    /////////////////  STRUCT1   /////////////////////////////
    // Creating an Object for defined structure
    zic_mem_sp0_t  zm_sp0; 
    uint32_t* ptr_1 = &zm_sp0.zic_cfg;
    while(ptr_1 <= &zm_sp0.zic_info){
        rand_num32();

        *ptr_1 = num32;
        ptr_1++;
    }


    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR_SP0->zic_cfg));
    z_printf("written_data = %u\n",zm_sp0.zic_cfg); 
 
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR_SP0->zic_info));
    z_printf("written_data = %u\n",zm_sp0.zic_info); 
   
    /////////////////  STRUCT2   /////////////////////////////
    // Creating an Object for defined structure
    zic_mem_sp1_t  zm_sp1;
    uint8_t* ptr_2 = &zm_sp1.zic_nxtp_int;
    while(ptr_2 <= &zm_sp1.zic_eoi){
        rand_num8();

        *ptr_2 = num8;
        ptr_2++;
    }
    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR_SP1->zic_nxtp_int));
    z_printf("written_data = %u\n",zm_sp1.zic_nxtp_int); 
 
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR_SP1->zic_ack));
    z_printf("written_data = %u\n",zm_sp1.zic_ack); 

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR_SP1->zic_eoi));
    z_printf("written_data = %u\n",zm_sp1.zic_eoi);       
    
    
    /////////////////  STRUCT3   /////////////////////////////
    // Creating an Object for defined structure
    zic_mem_reg_t  zm_reg; 
    uint8_t* ptr_3 = &zm_reg.zic_int_p_0;

    while(ptr_3 <= &zm_reg.zic_int_ctl_47){
        
        //Calling Randomized Function
        rand_num8();
        *ptr_3 = num8;
        ptr_3++;
    }  
       
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_0));
    z_printf("written_data_zic_int_p_0 = %u\n",zm_reg.zic_int_p_0);   
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_0));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_0);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_0));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_0);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_0));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_0);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_1));
    z_printf("written_data_zic_int_p_1 = %u\n",zm_reg.zic_int_p_1);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_1));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_1);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_1));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_1);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_1));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_1);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_2));
    z_printf("written_data_zic_int_p_2 = %u\n",zm_reg.zic_int_p_2);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_2));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_2);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_2));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_2);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_2));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_2);

    z_printf("register_offset_address =%x\n", &(ZIC_MEM_ADDR->zic_int_p_3));
    z_printf("written_data_zic_int_p_3 = %u\n",zm_reg.zic_int_p_3);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_3));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_3);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_3));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_3);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_3));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_3);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_4));
    z_printf("written_data_zic_int_p_4 = %u\n",zm_reg.zic_int_p_4);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_4));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_4);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_4));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_4);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_4));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_4);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_5));
    z_printf("written_data_zic_int_p_5 = %u\n",zm_reg.zic_int_p_5);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_5));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_5);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_5));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_5);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_5));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_5);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_6));
    z_printf("written_data_zic_int_p_6 = %u\n",zm_reg.zic_int_p_6);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_6));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_6);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_6));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_6);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_6));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_6);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_7));
    z_printf("written_data_zic_int_p_7 = %u\n",zm_reg.zic_int_p_7);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_7));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_7);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_7));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_7);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_7));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_7);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_8));
    z_printf("written_data_zic_int_p_8 = %u\n",zm_reg.zic_int_p_8);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_8));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_8);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_8));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_8);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_8));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_8);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_9));
    z_printf("written_data_zic_int_p_9 = %u\n",zm_reg.zic_int_p_9);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_9));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_9);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_9));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_9);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_9));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_9);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_10));
    z_printf("written_data_zic_int_p_10 = %u\n",zm_reg.zic_int_p_10);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_10));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_10);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_10));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_10);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_10));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_10);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_11));
    z_printf("written_data_zic_int_p_11 = %u\n",zm_reg.zic_int_p_11);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_11));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_11);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_11));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_11);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_11));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_11);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_12));
    z_printf("written_data_zic_int_p_12 = %u\n",zm_reg.zic_int_p_12);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_12));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_12);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_12));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_12);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_12));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_12);

     z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_13));
    z_printf("written_data_zic_int_p_13 = %u\n",zm_reg.zic_int_p_13);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_13));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_13);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_13));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_13);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_13));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_13);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_14));
    z_printf("written_data_zic_int_p_14 = %u\n",zm_reg.zic_int_p_14);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_14));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_14);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_14));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_14);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_14));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_14);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_15));
    z_printf("written_data_zic_int_p_15 = %u\n",zm_reg.zic_int_p_15);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_15));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_15);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_15));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_15);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_15));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_15);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_16));
    z_printf("written_data_zic_int_p_16 = %u\n",zm_reg.zic_int_p_16);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_16));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_16);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_16));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_16);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_16));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_16);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_17));
    z_printf("written_data_zic_int_p_17 = %u\n",zm_reg.zic_int_p_17);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_17));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_17);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_17));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_17);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_17));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_17);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_18));
    z_printf("written_data_zic_int_p_18 = %u\n",zm_reg.zic_int_p_18);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_18));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_18);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_18));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_18);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_18));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_18);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_19));
    z_printf("written_data_zic_int_p_19 = %u\n",zm_reg.zic_int_p_19);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_19));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_19);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_19));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_19);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_19));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_19);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_20));
    z_printf("written_data_zic_int_p_20 = %u\n",zm_reg.zic_int_p_20);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_20));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_20);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_20));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_20);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_20));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_20);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_21));
    z_printf("written_data_zic_int_p_21 = %u\n",zm_reg.zic_int_p_21);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_21));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_21);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_21));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_21);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_21));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_21);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_22));
    z_printf("written_data_zic_int_p_22 = %u\n",zm_reg.zic_int_p_22);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_22));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_22);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_22));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_22);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_22));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_22);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_23));
    z_printf("written_data_zic_int_p_23 = %u\n",zm_reg.zic_int_p_23);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_23));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_23);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_23));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_23);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_23));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_23);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_24));
    z_printf("written_data_zic_int_p_24 = %u\n",zm_reg.zic_int_p_24);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_24));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_24);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_24));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_24);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_24));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_24);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_25));
    z_printf("written_data_zic_int_p_25 = %u\n",zm_reg.zic_int_p_25);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_25));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_25);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_25));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_25);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_25));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_25);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_26));
    z_printf("written_data_zic_int_p_26 = %u\n",zm_reg.zic_int_p_26);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_26));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_26);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_26));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_26);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_26));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_26);
          
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_27));
    z_printf("written_data_zic_int_p_27 = %u\n",zm_reg.zic_int_p_27);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_27));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_27);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_27));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_27);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_27));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_27);
    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_28));
    z_printf("written_data_zic_int_p_28 = %u\n",zm_reg.zic_int_p_28);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_28));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_28);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_28));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_28);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_28));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_28);
    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_29));
    z_printf("written_data_zic_int_p_29 = %u\n",zm_reg.zic_int_p_29);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_29));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_29);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_29));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_29);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_29));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_29);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_30));
    z_printf("written_data_zic_int_p_30 = %u\n",zm_reg.zic_int_p_30);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_30));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_30);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_30));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_30);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_30));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_30);  
    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_31));
    z_printf("written_data_zic_int_p_31 = %u\n",zm_reg.zic_int_p_31);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_31));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_31);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_31));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_31);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_31));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_31);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_32));
    z_printf("written_data_zic_int_p_32 = %u\n",zm_reg.zic_int_p_32);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_32));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_32);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_32));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_32);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_32));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_32);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_33));
    z_printf("written_data_zic_int_p_33 = %u\n",zm_reg.zic_int_p_33);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_33));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_33);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_33));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_33);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_33));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_33);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_34));
    z_printf("written_data_zic_int_p_34 = %u\n",zm_reg.zic_int_p_34);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_34));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_34);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_34));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_34);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_34));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_34);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_35));
    z_printf("written_data_zic_int_p_35 = %u\n",zm_reg.zic_int_p_35);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_35));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_35);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_35));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_35);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_35));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_35);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_36));
    z_printf("written_data_zic_int_p_36 = %u\n",zm_reg.zic_int_p_36);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_36));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_36);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_36));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_36);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_36));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_36);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_37));
    z_printf("written_data_zic_int_p_37 = %u\n",zm_reg.zic_int_p_37);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_37));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_37);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_37));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_37);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_37));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_37);
    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_38));
    z_printf("written_data_zic_int_p_38 = %u\n",zm_reg.zic_int_p_38);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_38));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_38);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_38));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_38);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_38));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_38);
    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_39));
    z_printf("written_data_zic_int_p_39 = %u\n",zm_reg.zic_int_p_39);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_39));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_39);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_39));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_39);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_39));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_39);
    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_40));
    z_printf("written_data_zic_int_p_40 = %u\n",zm_reg.zic_int_p_40);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_40));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_40);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_40));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_40);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_40));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_40);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_41));
    z_printf("written_data_zic_int_p_41 = %u\n",zm_reg.zic_int_p_41);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_41));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_41);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_41));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_41);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_41));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_41);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_42));
    z_printf("written_data_zic_int_p_42 = %u\n",zm_reg.zic_int_p_42);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_42));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_42);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_42));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_42);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_42));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_42);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_43));
    z_printf("written_data_zic_int_p_43 = %u\n",zm_reg.zic_int_p_43);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_43));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_43);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_43));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_43);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_43));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_43);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_44));
    z_printf("written_data_zic_int_p_44 = %u\n",zm_reg.zic_int_p_44);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_44));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_44);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_44));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_44);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_44));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_44);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_45));
    z_printf("written_data_zic_int_p_45 = %u\n",zm_reg.zic_int_p_45);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_45));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_45);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_45));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_45);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_45));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_45);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_46));
    z_printf("written_data_zic_int_p_46 = %u\n",zm_reg.zic_int_p_46);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_46));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_46);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_46));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_46);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_46));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_46);

    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_p_47));
    z_printf("number_zic_int_p_47 = %u\n",zm_reg.zic_int_p_47);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_en_47));
    z_printf("written_data = %u\n",zm_reg.zic_int_en_47);
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_attr_47));
    z_printf("written_data = %u\n",zm_reg.zic_int_attr_47);    
    z_printf("register_offset_address = %x\n", &(ZIC_MEM_ADDR->zic_int_ctl_47));
    z_printf("written_data = %u\n",zm_reg.zic_int_ctl_47);

    
    mailbox_send_request(MAILBOX1, END_SIM); //End simulation in TB
    mailbox_send_request(MAILBOX2, error_cnt); 
    return 0;
}

