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
* File Name : Squareroot_new.c

* Purpose :

* Creation Date : 29-12-2022

* Last Modified : Fri 30 Dec 2022 12:00:27 PM IST

* Created By :  

////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


#include<stdio.h>  
#include <limits.h>             /*!< Datatype limit         */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"           /*!< Mailbox access library */
#include "testapi.h"
//#include "squareroot.h"

               /*!< Testbench created data "*/



#ifdef SPIKE_RUN
#include "data.h"               /*!< Testbench created data */
#endif



#define TEST_COUNT     (1)    /*!< Test count             */
#define DATA_SET        (2)   

/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*DATA_SET] __attribute((section(".results"))) = {0,}; 

int main()
{
    	/* test case status */
	//volatile int testnumber   = 1;
	volatile int testtypenum  = 0;
   	int64_t num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*2) ;

    #ifdef SPIKE_RUN
	printf("\nTest/> Square Root:\n");
	printf("\n------------------------------\n");
    #endif

   for(int testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
    {
    #ifdef SPIKE_RUN	

        SQUARE_ROOT_SPIKE(x_tb,rslt_full,rslt_tb,testnumber);
		PRINT_RESULT_SQUARE_ROOT(x_tb,rslt_full,rslt_tb);
    #else
		SQUARE_ROOT_C(MAILBOX1,x,rslt_full,testnumber)
    #endif 
    }
    mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt); 
 
    return 0;

}


