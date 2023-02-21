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
#include "testmacro.h"          /*!< Test macros            */
#include "math.h"
#include "testapi.h"


#define TEST_COUNT     (20)    
#define DATA_SET        (4)  

#ifdef SPIKE_RUN 
#include "data.h"
#endif

uint64_t actual_result[TEST_COUNT*DATA_SET] __attribute((section(".results"))) = {0,};

     int main(void)    
      {   

   	// test case status 
//	volatile int testnumber   = 1;
//	volatile int testtypenum  = 0;


#ifdef SPIKE_RUN
	printf("\nTest/> catalan number tests:\n");
	printf("\n-------------------------------------\n");
#endif


	////////////////////////////// catalan number test //////////////////////////////

        

	for(int testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
        	{
#ifdef SPIKE_RUN	
        CATALAN_NO_SPIKE(n,a,c,catalan_no,result_tb,testnumber);
        PRINT_CATALAN_NO(n,catalan_no,result_tb,testnumber);
       

#else
	    CATALAN_NO(MAILBOX1,n,a,c,catalan_no,testnumber);
#endif
       
    }



	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
	return 0;

    }
    

