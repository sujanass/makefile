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
#include<stdio.h>  
#include <stdlib.h>
#include <limits.h>             
#include <stdint.h>            
#include "print.h"              
#include "linker.h"            
#include "mailbox.h"  
#include "testapi.h"
//#include "testmacro.h"

//#include "lcm.h"

#ifdef SPIKE_RUN
#include "data.h"               
#endif

#define TEST_COUNT     (5)          
#define DATA_SET        (30)  

uint64_t actual_result[TEST_COUNT*DATA_SET] __attribute((section(".results"))) = {0,};

int main()
{
    //volatile 
    //int testnumber=1;
   	int64_t num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*30) ;

#ifdef SPIKE_RUN
	printf("\nTest/> LCM of two numbers\n");
    printf("----------------------------------- \n");
#endif
 
    for(int testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
  	{
#ifdef SPIKE_RUN
                LCM_SPIKE_C(op1,op2,rslt_full,rslt_tb,testnumber);
       
                PRINT_LCM(op1,op2,rslt_full,rslt_tb);
#else
       
                LCM_C(MAILBOX1,op1,op2,rslt_16u_full,testnumber);
#endif
      
 	}

    mailbox_send_request(MAILBOX1, MEM_DUMP);
    mailbox_send_request(MAILBOX2,num_of_elements_memdump);
    mailbox_send_request(MAILBOX1, END_SIM);
    mailbox_send_request(MAILBOX2, error_cnt); 
  
    return 0;

}  

