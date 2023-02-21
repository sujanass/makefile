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
#include <math.h>
#include <stdlib.h>
#include <limits.h>             /*!< Datatype limit         */
#include <stdint.h>             /*!< Standarad Integer type */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
//#include "fibsearch1.h"           /*!< Test macros            */

//#ifdef SPIKE_RUN
//#include "data.h"               /*!< Testbench created data */
//#endif


/* Note: TEST_COUNT indicates number of test for each tests. e.g. TEST_COUNT number
   of tests for uint8_t multiplication, TEST_COUNT number of tests for int8_t multiplication, etc*/
//#define TEST_COUNT     (3)    /*!< Test count             */
//#define DATA_SET        (11)     /*!< array of 10 elements      */
//#define TEST_TYPES      (1)     /*!< Exponential Search*/
   
int main(void)
{
        /*volatile int testnumber   = 1;
	    volatile int testtypenum  = 0;
    	int32_t num_of_elements_memdump;
	    num_of_elements_memdump = (TEST_COUNT*11*1);*/
        int32_t i;
        int32_t arr[] = {65536,131072,196608,262144,327680,393216}; 
        int32_t n = sizeof(arr)/sizeof(arr[0]); 
        int32_t total=0;
        for(i=0;i<n;i++)
       {
        total=total+arr[i];
       }
        int32_t average=total/n;
        int32_t a=average/65536;
        int32_t b=average%65536;

        z_printf("average is %d\n", average);
        z_printf("average is %d\n", a);
        z_printf("average is %d\n", b);

    mailbox_send_request(MAILBOX1, MEM_DUMP);
	//mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);    
  
    return 0;
}
