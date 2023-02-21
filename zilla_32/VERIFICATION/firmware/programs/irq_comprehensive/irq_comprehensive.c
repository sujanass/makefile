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
  
  INT_DESCENDING; //Descending order IRQ generation(47-0)

  INT_ASCENDING;  //Ascending order IRQ generation(0-47) 

  //With delay cases

  GEN_INT(IRQ_GEN_L1); // Level 7 IRQ generation

  GEN_INT(IRQ_GEN_L2); // Level 6 IRQ generation

  GEN_INT(IRQ_GEN_L3); // Level 5 IRQ generation
 
  GEN_INT(IRQ_GEN_L4); // Level 4 IRQ generation

  GEN_INT(IRQ_GEN_L5); // Level 3 IRQ generation

  GEN_INT(IRQ_GEN_L6); // Level 2 IRQ generation 

  GEN_INT(IRQ_GEN_L7); // Level 1 IRQ generation

  GEN_INT(IRQ_GEN_P1); //Priority 7 IRQ Generation

  GEN_INT(IRQ_GEN_P2); //Priority 6 IRQ Generation

  GEN_INT(IRQ_GEN_P3); //Priority 5 IRQ Generation

  GEN_INT(IRQ_GEN_P4); //Priority 4 IRQ Generation

  GEN_INT(IRQ_GEN_P5); //Priority 3 IRQ Generation

  GEN_INT(IRQ_GEN_P6); //Priority 2 IRQ Generation

  GEN_INT(IRQ_GEN_P7); //Priority 1 IRQ Generation 
 
  //without delay cases
  
  GEN_INT(IRQ_GEN_T1); // Level 7 IRQ generation

  GEN_INT(IRQ_GEN_T2); // Level 6 IRQ generation

  GEN_INT(IRQ_GEN_T3); // Level 5 IRQ generation
 
  GEN_INT(IRQ_GEN_T4); // Level 4 IRQ generation

  GEN_INT(IRQ_GEN_T5); // Level 3 IRQ generation

  GEN_INT(IRQ_GEN_T6); // Level 2 IRQ generation 

  GEN_INT(IRQ_GEN_T7); // Level 1 IRQ generation

  GEN_INT(IRQ_GEN_T8); //Priority 7 IRQ Generation

  GEN_INT(IRQ_GEN_T9); //Priority 6 IRQ Generation

  GEN_INT(IRQ_GEN_T10); //Priority 5 IRQ Generation

  GEN_INT(IRQ_GEN_T11); //Priority 4 IRQ Generation

  GEN_INT(IRQ_GEN_T12); //Priority 3 IRQ Generation

  GEN_INT(IRQ_GEN_T13); //Priority 2 IRQ Generation

  GEN_INT(IRQ_GEN_T14); //Priority 1 IRQ Generation 
  

  mailbox_send_request(MAILBOX1, END_SIM); //End simulation in TB
  mailbox_send_request(MAILBOX2, error_cnt); 
   return 0;
}





