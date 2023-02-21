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
/***********This program generates fibonacci series of 64 bit values**********/
#include<stdio.h>  
#include <stdlib.h>
#include <limits.h>             /*!< Datatype limit         */
#include <stdint.h>             /*!< Standarad Integer type */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
#include "testmacro.h"          /*!< Test macros            */


#include "fibtst.h"  

#ifdef SPIKE_RUN
#include "data.h"               /*!< Testbench created data */
#endif

#define TEST_COUNT     (1)    /*!< Test count             */
#define DATA_SET        (94)     /*!< array of 10 elements      */

uint64_t actual_result[TEST_COUNT*DATA_SET] __attribute((section(".results"))) = {0,};

int main()
{
   
    volatile int testtypenum  = 0;
   	int64_t num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*94) ;

    #ifdef SPIKE_RUN
	printf("\nTest/> FIBINOCCI SERIES\n");
    printf("----------------------------------- \n");

#endif
 
    for(int testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
  	{
#ifdef SPIKE_RUN
       
		FIBINOCCI_SPIKE_C(len1,rslt_spike,rslt_full,rslt_tb,testnumber); // fibonacci series generats in spike
        printf("Fibinocci series %d \n",testnumber);
    	PRINT_RESULT_FIBINOCCI(len,rslt_tb,rslt_full,testnumber); //compare spike and core result
  
#else   
	   
		FIBINOCCI_C(MAILBOX1,len,rslt_full,testnumber); // fibonacci series generats in core
        	  
#endif
      
   	}


 
    mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt); 
  return 0;

}  
