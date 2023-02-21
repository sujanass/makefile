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
        #include <stdio.h>
        #include <string.h>
        #include <limits.h>
        #include <stdint.h>
        #include <stdio.h>
        #include "print.h"
        #include "linker.h"
        #include "mailbox.h"
        #include "testapi.h"
       #include "stdlib.h"
       

#define TEST_COUNT     (10)    /*!< Test count             */
#define DATA_SET        (3)     /*!< op1, op2, result       */
//#define TEST_TYPES      (6)     /*!< 8u,8s,16u,16s,32u,32s  */
//#define TEST_THREE     (150)	//TEST_THREE(is12)x2xTEST_COUNT 

//#include "crc.h"

#ifdef SPIKE_RUN 
#include "data.h"
#endif


/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*DATA_SET] __attribute((section(".results"))) = {0,};
//#include "ui_test.h"          /*!< Test macros            */




     int main(void)    
      {   

   	// test case status 
	volatile int testnumber   = 1;
	volatile int testtypenum  = 0;


#ifdef SPIKE_RUN
	printf("\nTest/> modulo_inverse tests:\n");
	printf("\n-------------------------------------\n");
#endif

	////////////////////////////// inverse_modulo Test //////////////////////////////
	//testtypenum++;
        

	for(int testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
  	{
#ifdef SPIKE_RUN	
	MODULO_INVERSE_SPIKE(op1_16u,op2_16u,result_full_16u,result_tb_16u,testnumber);
        PRINT_RESULT_MODULO(op1_16u,op2_16u,result_tb_16u,result_full_16u,testnumber);
       //printf(" is %d \n received data is %s",final_data1,received_data);

#else
	    MODULO_INVERSE(MAILBOX1,op1_16u,op2_16u,result_full_16u,testnumber);
#endif
       // testnumber++;
    }
	
    mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
	return 0;
}  
