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


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>             /*!< Datatype limit         */
#include <stdint.h>             /*!< Standarad Integer type */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
//#include "testmacro.h"          /*!< Test macros            */

#include "testapi.h" 
#ifdef SPIKE_RUN
#include "data.h"               /*!< Testbench created data */
#endif

/* Note: TEST_COUNT indicates number of test for each tests. e.g. TEST_COUNT number
   of tests for uint8_t Addition, TEST_COUNT number of tests for int8_t Addition, etc*/
#define TEST_COUNT     (5)    /*!< Test count             */
#define DATA_SET        (3)     /*!< op1, op2, result       */
#define TEST_TYPES (2)
/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*DATA_SET] __attribute((section(".results"))) = {0,};

//uint64_t *p ;

int main()
{
   //volatile int testnumber=1;
    volatile int testtypenum  = 0;
   	uint64_t num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*30) ;

#ifdef SPIKE_RUN
	printf("\nTest/> HCF\n");
    printf("----------------------------------- \n");

#endif
for(int testnumber = 1; testnumber <= TEST_COUNT; testnumber++)	
{
#ifdef SPIKE_RUN	
		HCF_TEST_U8_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		PRINT_RESULT_HCF_U(op1,op2,result_tb,result_full);
#else
		HCF_TEST_U8_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}
       // p=p+len;

   	

    mailbox_send_request(MAILBOX1, MEM_DUMP);
    mailbox_send_request(MAILBOX2,num_of_elements_memdump);
    mailbox_send_request(MAILBOX1, END_SIM);
    mailbox_send_request(MAILBOX2, error_cnt); 
  return 0;


}
