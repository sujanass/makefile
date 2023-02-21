//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Copyright Â© 2022 Vivartan Technologies., All rights reserved/////////////////////////////
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
Copyright © 2021 Vivartan Technologies., All rights reserved.

All works published under Zilla_Gen_0 by the Vivartan Technologies. 
is copyrighted by the Association and ownership of all right, title and interest
in and to the works remains with Vivartan Technologies.

No works or documents published under Zilla_Gen_0 by Vivartan Technologies. may be reproduced,
transmitted or copied without the express written permission of Vivartan Technologies.
will be considered as a violations of Copyright Act and it may lead to legal action.
*/

#include <stdio.h>    /* Standard IO            */
#include "print.h"    /* Mailbox print library  */
#include "linker.h"   /* Linker symbols library */
#include "mailbox.h"  /* Mailbox library */
#include "trapapi.h"  /* Interrupts and exceptions library */

extern volatile int irq_asserted  ;
extern int exp_intr_flag ;

#define COUNT (3)
int main()
{ 

 int r0;
 csr_asm_rs(csrrsi,r0,768,8); // Enable Mstatus mie bit (write to mstatus_csr) : neesd to be enabled to accept interrupt requests

 // Triggering all exceptions
 MISALIGN_LOAD_HALFWORD;

 MISALIGN_LOAD_WORD;

 MISALIGN_LOAD_DOUBLEWORD;

 MISALIGN_STORE_HALFWORD;

 MISALIGN_STORE_WORD;

 MISALIGN_STORE_DOUBLEWORD;

 ILLEGAL_INSTRUCTION;

 ECALL_EXCEPTION;

// EBREAK_EXCEPTION;

 INST_MISALIGNED_EXCEPTION; 

/* for(int count = 1 ; count <= COUNT ; count++)
 { 
     RAND_EXCEP_GEN ;
 } 

// NESTED_EXCEPTION; 
 //RAND_NESTED_EXCEPTION ; //generates random nested excpetion 

 INT_GENERATION ; //Interrupt comes while executing exception

 for(int count = 1 ; count <=COUNT ; count++){
 GEN_INT_EXP(IRQ_GEN_RAND1); // Exception comes while executing interrupt
 } */

//z_printf("\nMemory Out of Bound Test cases\n");
// Test case Memory out of bound : Missalligned and memory out of bound at the same time , misaligned get the priority 
MEMORY_OUT_MISALIGNED;
// Test case memory out of bound: Changing address range by writing to csr register (0xFC1) 
int64_t rd , rs1 ;
rs1 = 0x50020;  
csr_asm_rs_rd(csrrw ,rd , 4033 , rs1) ;
MEMORY_OUT_OF_BOUND;  // Exception will not trigger becasuse of load addres which is 50018 < 50020*/
 

  mailbox_send_request(MAILBOX1, END_SIM); //End simulation in TB
  mailbox_send_request(MAILBOX2, error_cnt); 
   return 0;
}





