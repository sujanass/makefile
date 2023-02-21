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
//  Copyright © 2021 Vivartan Technologies., All rights reserved.
//  
//  All works published under Zilla_Gen_0 by the Vivartan Technologies. 
//  is copyrighted by the Association and ownership of all right, title and interest
//  in and to the works remains with Vivartan Technologies.
//  
//  No works or documents published under Zilla_Gen_0 by Vivartan Technologies. may be reproduced,
//  transmitted or copied without the express written permission of Vivartan Technologies.
//  will be considered as a violations of Copyright Act and it may lead to legal action.


#include <stdio.h>    /* Standard IO            */
#include "print.h"    /* Mailbox print library  */
#include "linker.h"   /* Linker symbols library */
#include "mailbox.h"  /* Linker symbols library */
#include "trapapi.h"  /* Linker symbols library */

extern volatile int irq_asserted  ;
int main(){
    asm ("nop") ;      //additional nop is introduced to ease the instruction memory overwrite of ebreak instruction 
    //asm ("EBREAK") ;   //Comment this while running openocd 
    asm ("nop") ;

    int r0;
    csr_asm_rs(csrrsi,r0,768,8); // Enable Mstatus mie bit (write to mstatus_csr) : neesd to be enabled to accept interrupt requests
 
    uint64_t sample = 10 ;
    uint64_t *addrs = &sample ; 
    asm volatile ("mv  a5  , %[x]  \n\t" :  : [x] "r" (addrs)  ) ; //addres to register a5 
 while(1) {     //multicycle load and store instruction 
    asm ("lb a4 , 0(a5)") ;
    asm ("sb a4 , 1(a5)") ;
    asm ("lb a4 , 1(a5)") ;
    asm ("sb a4 , 2(a5)") ;
    asm ("lb a4 , 2(a5)") ;
    asm ("sb a4 , 3(a5)") ;
    asm ("sb a4 , 4(a5)") ;
    asm ("lb a4 , 4(a5)") ;
    asm ("sb a4 , 5(a5)") ;  
    asm ("lb a4 , 5(a5)") ;
 } 
    return 0;
}
