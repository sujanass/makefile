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
#include "mailbox.h"  /* Linker symbols library */
#include "trapapi.h"  /* Linker symbols library */

extern volatile int irq_asserted  ;



int main()
{

  int r0;
  csr_asm_rs(csrrsi,r0,768,8); // Enable Mstatus mie bit (write to mstatus_csr) : neesd to be enabled to accept interrupt requests

  z_printf("Random One Interrupt Generation \n");
    GEN_INT(IRQ_GEN_RAND1);

  z_printf("Random n Interrupt Generation (n=10 here) \n");
    GEN_INT(IRQ_GEN_RAND2);

  z_printf("Random n Interrupt Generation \n");
    GEN_INT(IRQ_GEN_RAND3);

  z_printf("Random n Interrupt Generation at a particular time \n");
    GEN_INT(IRQ_GEN_RAND5);

  z_printf(" Random n Interrupt Generation with Random Delay  \n");
    GEN_INT(IRQ_GEN_RAND4); 

  mailbox_send_request(MAILBOX1, END_SIM); //End simulation in TB
  mailbox_send_request(MAILBOX2, error_cnt); 
   return 0;
}






