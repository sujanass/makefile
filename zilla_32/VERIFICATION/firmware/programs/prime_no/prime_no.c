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
** Number is prime or not
**
*********************************************************************************
*/


#include <stdio.h>  
#include <stdlib.h>
#include <limits.h>             /*!< Datatype limit         */
#include <stdint.h>             /*!< Standarad Integer type */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
#include "testapi.h"           /*!< Test macros            */



#ifdef SPIKE_RUN
#include "data.h"               /*!< Testbench created data */
#endif


/* Note: TEST_COUNT indicates number of test for each tests. e.g. TEST_COUNT number
   of tests for uint8_t multiplication, TEST_COUNT number of tests for int8_t multiplication, etc*/
#define TEST_COUNT     (3)    /*!< Test count             */
#define DATA_SET        (20)     /*!< array of 10 elements      */
//#define TEST_TYPES      (8)     /*!< 8u,8s,16u,16s,32u,32s,64u,64s */
   

/* Array to store the operand1, operand2 and actual result */
int64_t actual_result[TEST_COUNT*DATA_SET] __attribute((section(".results"))) = {0,};
int64_t *p ;
                                    
/* Main function */
int main(void)
{
	/* test case status */
	//volatile int testnumber   = 1;
	volatile int testtypenum  = 0;
   	int64_t num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*20) ;


	/***********************************Prime no test ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Prime no test\n");
    printf("----------------------------------- \n");

#endif
 
    for(int testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
  	{
#ifdef SPIKE_RUN
       
		PRIME_NO_TEST_SPIKE_C(data_input,rslt_full,rslt_tb,testnumber);
        printf("Prime no %d \n",testnumber);
    	PRINT_RESULT_PRIME(rslt_tb,rslt_full,data_input);
  
#else   
	    RAND_ARR_PRIME(MAILBOX1,testnumber);
		PRIME_NO_TEST_C(MAILBOX1,rand_arr,rslt_full ,testnumber);
        	  
#endif
       // p=p+10;

   	}
        
	mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);    
    
    return 0;

}

