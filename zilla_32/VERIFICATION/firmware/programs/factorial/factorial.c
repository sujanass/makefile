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
*******************************************************************************
**
** To find factorial of a number
**
** The factorial of a positive number n is given by:
** factorial of n (n!) = 1 * 2 * 3 * 4....n
** The factorial of a negative number doesn't exist. And, the factorial of 0 is 1.
**
*******************************************************************************
*/



#include <stdio.h>  
#include "print.h"              
#include "linker.h"            
#include "mailbox.h"           
#include "testapi.h"

#ifdef SPIKE_RUN
#include "data.h"               
#endif

#define TEST_COUNT     (6)          
#define DATA_SET        (2)        
#define TEST_TYPES      (1)         

uint64_t actual_result[TEST_COUNT*DATA_SET] __attribute((section(".results"))) = {0,};

int main()
{
    volatile int testnumber   = 1;
	volatile int testtypenum  = 0;
   	int64_t num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*2*6) ;


    #ifdef SPIKE_RUN
	printf("\nTest/> Factorial :\n");
    #endif

 z_printf("YASHQANT");	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
    #ifdef SPIKE_RUN	
		FACTORIAL_TEST_U8_SPIKE(n_tb,rslt_tb,rslt_full,testnumber);
		PRINT_RESULT_FACTORIAL(rslt_tb,rslt_full,n_tb);
    #else
		FACTORIAL_TEST_U8(MAILBOX1,n,rslt_full,testnumber);
    #endif
	}
 
    mailbox_send_request(MAILBOX1, MEM_DUMP);
    mailbox_send_request(MAILBOX2,num_of_elements_memdump);
    mailbox_send_request(MAILBOX1, END_SIM);
    mailbox_send_request(MAILBOX2, error_cnt); 
    return 0;   
}
