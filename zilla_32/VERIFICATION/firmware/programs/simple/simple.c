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
* File Name : simple.c

* Purpose :

* Creation Date : 29-12-2022

* Last Modified : Thu 29 Dec 2022 07:28:05 PM IST

* Created By :  

////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
//
//
//
//
//
#include <stdio.h>  
#include "print.h"              
#include "linker.h"            
#include "mailbox.h"           
#include "factorial.h"

#ifdef SPIKE_RUN
#include "data.h"               
#endif

#define TEST_COUNT     (6)          
#define DATA_SET        (2)        
#define TEST_TYPES      (1)         

uint64_t actual_result[TEST_COUNT*DATA_SET] __attribute((section(".results"))) = {0,};

int main()
{
    
    int a;
    int b;


    int c;


    c = a+b;
    c = a*b;
    c = a/b;

    mailbox_send_request(MAILBOX1, END_SIM);
    mailbox_send_request(MAILBOX2, error_cnt); 
    return 0;   
}
