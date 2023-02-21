//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Copyright © 2022 Vivartan Technologies., All rights reserved/////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                              //
//All works published under Zilla_Gen_0 by Vivartan Technologies is copyrighted by the Association and ownership// 
//of all right, title and interest in and to the works remains with Vivartan Technologies. No works or documents//
//published under Zilla_Gen_0 by Vivartan Technologies may be reproduced,transmitted or copied without the expre//
//-ss written permission of Vivartan Technologies will be considered as a violations of Copyright Act and it may//
//lead to legal action.                                                                                         //
//                                                                                                              //
//**************************************************************************************************************//                                                                                                              //
//                                                                                                              //
//FILE NAME:                                                                                                    //
//DESCRIPTION:                                                                                                  //   
//AUTHOR:                                                                                                       //               
//DATE:                                                                                                         //
//LAST MODIFIED BY:                                                                                             //
//LAST MODIFIED ON:                                                                                             //
//                                                                                                              //      
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
**
*********************************************************************************
** TEST PLAN 
** 
** Part 1 -- ISA TEST USING INLINE ASM 
** 
** In Part 1 -- We are going to check INLINE ASM for R, M, I, S, B and Jump Type
** Instructions
** 
** In Part 2 -- We are going to check IRQ one by one for forcing it via TB,
** Also check for Nesting of Interrupts 
** 
** In Part 3 -- We are going to check Exceptions by Hacking the DUT Signals in
** the instruction Fetch Reg and Create a Sys Reset by Writing to relevant SW 
** reset register (Since SW reset is not implemted for time being POR will be done)
** Part 3 will be TBD 
** 
** Part 4 -- Related to Debug Unit 
** 
** Part 5 -- Related to Trace Unit 
**
*********************************************************************************/



  ////////////    Part 1 -- ISA Test    //////////////////


  ///////////    Part 2 (A) -- IRQ Test Series //////////
  // Enable all IRQ 
  // Enable Global IRQ
  // Update ZIC Memory Map Registers
  // Loop Enable
  // Create MailBox Reqest to Generate IRQ 

  // (MailBox 1 used for Gen IRQ CMD, MailBox 2 to Send ID)
  // After that wait in While Loop when Flow switches to IRQ Handler 
  // Inside IRQ Handler : Send MailBox to deassert IRQ and set a flag to remain in while loop
  // The While loop continues since flag is set , if flag is cleared - exit from while loop
  // Reset flag and Loop Back to Loop Enable (48 Times since 0 to 47 IRQs are there in Gen 0)
 

  //////////    Part 2 (B) -- IRQ Test Nesting ////////////
  // Since IRQs are already enabled no need to enable again 
  // To check how to write remap IRQ handler -- TBD 
  // Send Mail inside exisitng IRQ handler to generate nesting IRQ 
  // Create relevant number of nesting scenaruos 
  // Try nesting more than cap (Max Nesting Possibility)
  // Follow Similar steps as above part for asserting and deasserting IRQs


  /////////    Part 3 -- Check for Exception  //////////////

    
  //// SENDING REQUEST TO TB FROM MB1 ASKING TO GENERATE IRQ CMD  ////////
  //Enable all IRQ : mstatus.mie bits : preset to 1 for all : 0x0000FFFF_FFFFFFFF

  //Update ZIC memory map registers - with respect to IRQ #number 
  //List of ZIC Registers wrt interrupts : 
  // zic_cfg, zic_info ,zic_ack , zic_eoi , zic_nxtp ,
  // zic_int_p , zic_int_en , zic_int_attr & zic_ctl
  //
  // Corresponding : zic_int_p ,zic_int_en, zic_int_attr, zic_int_ctl - offset beginning 0x1000
  

   //rs1 : 64'h8
   //csrrs csr_addr_mstatus,rs1,rd : mie : 1 (pin 3 will be set) -
   //Context saving : interrupt handler  - Need to check

   // ext_int0_i  - assert the pin || Assert - more than one pin - to check level and priority computation
   //if level and priority are same :: ID : 1,7 : ID 1 will have precedence

   // poll - mmr_ack_id :pending IRQ ID
   // EOI_ID - completed interrupt ID
   // CSR : mintstatus :  post entering into active IRQ ID





#include <stdio.h>    /* Standard IO            */
#include "print.h"    /* Mailbox print library  */
#include "linker.h"   /* Linker symbols library */
#include "mailbox.h"  /* Linker symbols library */
#include "trapapi.h"  /* Linker symbols library */

#define csr_asm_rs(inst,rd,imm,imm1)\
        asm volatile (#inst "    %[z], "#imm", "#imm1"\n\t"  : [z] "=r" (rd) ) ;

#define store_asm(inst,rs2,imm,rs1)\
        asm volatile (#inst "    %[z], "#imm"(%[x])\n\t"  :  : [z] "r" (rs2) , [x] "r" (rs1)) ;



extern volatile int irq_asserted  ;

//generate random interrupt number ID
#define GEN_INT(INT_NO)\
             irq_asserted = 0;\
             generate_IRQ(MAILBOX1, INT_NO);\
             while(irq_asserted != 1);

int main()
{
    

 int r0;
  csr_asm_rs(csrrsi,r0,768,8); // Enable Mstatus mie bit (write to mstatus_csr) : need to be enabled to accept interrupt requests
  
  
  
  csr_asm_rs(csrrwi,r0,1984,1); // Enable uart reset signal
  
  
  
  //Interrupt genearation in Ascending order one by one
  GEN_INT(IRQ_GEN_0);
//  GEN_INT(IRQ_GEN_1);
 // GEN_INT(IRQ_GEN_2);
 // GEN_INT(IRQ_GEN_3);
 /* GEN_INT(IRQ_GEN_4);
  GEN_INT(IRQ_GEN_5);
  GEN_INT(IRQ_GEN_6);
  GEN_INT(IRQ_GEN_7);
  GEN_INT(IRQ_GEN_8);
  GEN_INT(IRQ_GEN_9);
  GEN_INT(IRQ_GEN_10);
  GEN_INT(IRQ_GEN_11);
  GEN_INT(IRQ_GEN_12);
  GEN_INT(IRQ_GEN_13);
  GEN_INT(IRQ_GEN_14);
  GEN_INT(IRQ_GEN_15);
  GEN_INT(IRQ_GEN_16);
  GEN_INT(IRQ_GEN_17);
  GEN_INT(IRQ_GEN_18);
  GEN_INT(IRQ_GEN_19);
  GEN_INT(IRQ_GEN_20);
  GEN_INT(IRQ_GEN_22);
  GEN_INT(IRQ_GEN_23);
  GEN_INT(IRQ_GEN_24);
  GEN_INT(IRQ_GEN_25);
  GEN_INT(IRQ_GEN_26);
  GEN_INT(IRQ_GEN_27);
  GEN_INT(IRQ_GEN_28);
  GEN_INT(IRQ_GEN_29);
  GEN_INT(IRQ_GEN_30);
  GEN_INT(IRQ_GEN_31);
  GEN_INT(IRQ_GEN_32);
  GEN_INT(IRQ_GEN_33);
  GEN_INT(IRQ_GEN_34);
  GEN_INT(IRQ_GEN_35);
  GEN_INT(IRQ_GEN_36);
  GEN_INT(IRQ_GEN_37);
  GEN_INT(IRQ_GEN_38);
  GEN_INT(IRQ_GEN_39);
  GEN_INT(IRQ_GEN_40);
  GEN_INT(IRQ_GEN_41);
  GEN_INT(IRQ_GEN_42);
  GEN_INT(IRQ_GEN_43);
  GEN_INT(IRQ_GEN_44);
  GEN_INT(IRQ_GEN_45);
  GEN_INT(IRQ_GEN_46); 
//  GEN_INT(IRQ_GEN_47); 

    GEN_INT(IRQ_GEN_RAND1); //single interrupt generation at a time
    GEN_INT(IRQ_GEN_RAND3); //n random interrupts generation at a time (n=count)
    GEN_INT(IRQ_GEN_RAND5); //n random interrupts generation with m delay (n=count , m=rand_delay )
 
   //Without Nesting of interrupts 
   //get the zic base address from mzicbase-CSR register :: CSRRSI rd,csr,imm : (imm : keep 0's to not change the CSR reg value)
   //Based on the interrupt to be serviced : add the offset addrss for the same to rd : 
   //and update that particular memory location  :: zic_int_en_i , and zic_int_ctl_i
   //  
 
  // Level , Priority : Same , Combination of greater than or equal to 2 interrupts at a time 
  // T1:  1,2
  // T2 : 1,2,3,4
  // T3 : 2,3,6,7 
  // T4 : 5,15,35,45
  // Expectation : if all mentioned interrupts are enabled  at once , the one with lowest ID gets served first.
  

   GEN_INT(IRQ_GEN_P4); 


    // Nesting of interrupts 
    //get the zic base address from mzicbase-CSR register :: CSRRSI rd,csr,imm : (imm : keep 0's to not change the CSR reg value)
    //Based on the interrupt to be serviced : add the offset addrss for the same to rd : 
    //and update that particular memory location  :: zic_int_en_i , and zic_int_ctl_i
    

         
       //int_ctl value : based on Level and priority assigned to an interrupt ID
      // [7:5] : for level , [4:2] : for priority
      // Test scenarios : BASIC
      // Level same , priority varying - eg : L4 , P 1,2,3,4 : 1000ppp0 : 1000_001_0 , 1000_010_0 , 1000_011_0, 1000_100_0
      // Level varying , priority same
      // 
      // T1:  1,2
      // T2 : 1,2,3,4
      // T3 : 2,3,6,7 
      // T4 : 5,15,35, 45 
      //Assigning priorities and levels to a list of interrupts  :
      // IRQ 1 : L4, P1
      // IRQ 2 : L4, P2
      // IRQ 3 : L4, P3
      // IRQ 4 : L4, P4
      // IRQ 6 : L7, P1   : 111_001_00 : 228
      // IRQ 7 : L1, P7   : 001_111_00 : 60
      // IRQ 5 : L1, P6   : 001_110_00 : 56
      // IRQ 15: L5, P3   : 101_011_00 : 172
      // IRQ 35: L5, P5   : 101_101_00 : 180
      // IRQ 45: L7, P7   : 111_111_00 : 252
       
      
    GEN_INT(IRQ_GEN_T1); 
    GEN_INT(IRQ_GEN_T3); 
    GEN_INT(IRQ_GEN_T4);*/
        



    mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
	return 0;
}


