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



#include <stdio.h>    /* Standard IO            */
#include "print.h"    /* Mailbox print library  */
#include "linker.h"   /* Linker symbols library */
#include "mailbox.h"  /* Linker symbols library */
#include "trapapi.h"  /* Linker symbols library */

#define csr_asm_rs(inst,rd,imm,imm1)\
        asm volatile (#inst "    %[z], "#imm", "#imm1"\n\t"  : [z] "=r" (rd) ) ;

#define store_asm(inst,rs2,imm,rs1)\
        asm volatile (#inst "    %[z], "#imm"(%[x])\n\t"  :  : [z] "r" (rs2) , [x] "r" (rs1)) ;



int main()
{
    

 int r0;
  csr_asm_rs(csrrsi,r0,768,8); // Enable Mstatus mie bit (write to mstatus_csr) : need to be enabled to accept interrupt requests

uint8_t op1=111;
uint8_t op2=222;
uint8_t op3 = (uint8_t)generate_random_num(MAILBOX1);
uint8_t op4 = (uint8_t)generate_random_num(MAILBOX1);

uint8_t a1 = (uint8_t)generate_random_num(MAILBOX1);
uint8_t a2=111;

uint8_t b1=111;
uint8_t b2=111;
uint8_t b3=222;
uint8_t b4=222;
uint8_t b5=123;

uint8_t result; 


///////////////////////// R - TYPE INSTRUCTIONS ///////////////////////////

_ASM_IRQ_MUL_(&op1, &op2, &op3, &op4, &result);
_ASM_IRQ_ADD_(&op1, &op2, &op3, &op4, &result); 
_ASM_IRQ_SUB_(&op1, &op2, &op3, &op4, &result); 
_ASM_IRQ_SLL_(&op1, &op2, &op3, &op4, &result); 


///////////////////////// I - TYPE INSTRUCTIONS ///////////////////////////

_ASM_IRQ_ADDI_ (&a1, &a2, &result);
_ASM_IRQ_XORI_ (&a1, &a2, &result);

///////////////////////// LOAD & STORE INSTRUCTIONS ///////////////////////////



///////////////////////// BRANCH INSTRUCTIONS ///////////////////////////

_ASM_IRQ_BEQ_ (&b1, &b2, &b3, &b4);
_ASM_IRQ_BNE_ (&b1, &b5, &b2, &b4);

///////////////////////// JUMP INSTRUCTIONS ///////////////////////////

_ASM_IRQ_JAL_ (); 
_ASM_IRQ_JALR_();   

        


    mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
	return 0;
}


