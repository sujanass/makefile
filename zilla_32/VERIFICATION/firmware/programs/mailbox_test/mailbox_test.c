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
* File Name : mailbox_test.c

* Purpose :

* Creation Date : 18-05-2023

* Last Modified : Tue 06 Jun 2023 04:45:28 PM IST

* Created By :  

////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <stdio.h>

#include "print.h"
#include "linker.h"
#include "mailbox.h"
//#define TRAP_ENTRY asm volatile("addi sp, sp, -72"); \
// asm volatile("sw x1, 0(sp) "); \
// asm volatile("sw x5, 4(sp) "); \
// asm volatile("sw x6, 8(sp) ");\
// asm volatile("sw x7, 12(sp)"); \
// asm volatile("sw x10, 16(sp)"); \
// asm volatile("sw x11, 20(sp)"); \
// asm volatile("sw x12, 24(sp)"); \
// asm volatile("sw x13, 28(sp)"); \
// asm volatile("sw x14, 32(sp)"); \
// asm volatile("sw x15, 36(sp)"); \
// asm volatile("sw x16, 40(sp)"); \
// asm volatile("sw x17, 44(sp)"); \
// asm volatile("sw x28, 48(sp)"); \
// asm volatile("sw x29, 52(sp)"); \
// asm volatile("sw x30, 56(sp)"); \
// asm volatile("sw x31, 60(sp)"); \
// asm volatile("csrrsi a6,834,0"); \
// asm volatile("sw a6,64(sp) "); \
// asm volatile("csrrsi a5,833,0"); \
// asm volatile("sw a5,68(sp) "); \
// asm volatile("csrrsi x0,768,8"); //Global Interrupt Enable -- MSTATUS REGISTER : 0x300
//
//// Macro for TRAP EXIT
//#define TRAP_EXIT asm volatile("csrrci x0,768,8"); \
// asm volatile("lw a6, 64(sp)"); \
// asm volatile("csrrw a0, mcause, a6"); \
// asm volatile("lw a5, 68(sp)"); \
// asm volatile("csrrw a0, mepc, a5"); \
// asm volatile("lw x1, 0(sp) "); \
// asm volatile("lw x5, 4(sp) "); \
// asm volatile("lw x6, 8(sp) "); \
// asm volatile("lw x7, 12(sp)"); \
// asm volatile("lw x10, 16(sp)"); \
// asm volatile("lw x11, 20(sp)"); \
// asm volatile("lw x12, 24(sp)"); \
// asm volatile("lw x13, 28(sp)"); \
// asm volatile("lw x14, 32(sp)"); \
// asm volatile("lw x15, 36(sp)"); \
// asm volatile("lw x16, 40(sp)"); \
// asm volatile("lw x17, 44(sp)"); \
// asm volatile("lw x28, 48(sp)"); \
// asm volatile("lw x29, 52(sp)"); \
// asm volatile("lw x30, 56(sp)"); \
// asm volatile("lw x31, 60(sp)"); \
// asm volatile("addi sp, sp, 72"); \
// asm volatile("mret");

//#define ENABLE_GLOBAL_INT_FLAG asm volatile("csrrwi x1,mstatus, 0x00000008");
void main()
{
    z_printf("Hello from Zilla\n");
   // uint32_t x;
  //  uint32_t y;
    
//  generate_random_num(MAILBOX1);
//    //z_printf("Result=%lu\n",x);
//
//    generate_random_num(MAILBOX2);
//    //z_printf("Result=%lu\n",y);
//
//    
//    ENABLE_GLOBAL_INT_FLAG
//    generate_IRQ(MAILBOX1,IRQ_GEN_10);
//    
//    mailbox_send_request(MAILBOX1, END_SIM);
//	mailbox_send_request(MAILBOX2, error_cnt);
//
//     //ENABLE_GLOBAL_INT_FLAG
//    deassert_IRQ(MAILBOX1,DE_IRQ_10);

    mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);


    return 0;
}
   
//   __attribute__((naked)) void irq_10_handler()
//{
//    TRAP_ENTRY
//    //z_printf("Interrupt_10 generated");
//    TRAP_EXIT
//}

/*  __attribute__((naked)) void irq_10_handler()
{
    TRAP_ENTRY
    //z_printf("Interrupt_10 Deasserted");
    TRAP_EXIT
}
*/

