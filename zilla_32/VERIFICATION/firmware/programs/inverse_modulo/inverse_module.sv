     #include<stdio.h>
        #include <stdio.h>
        #include <string.h>
        #include <limits.h>
        #include <stdint.h>
        #include <stdio.h>
        #include "print.h"
        #include "linker.h"
        #include "mailbox.h"
        #include "modulo_inverse.h"
       #include "stdlib.h"
       

#define TEST_COUNT     (3)    /*!< Test count             */
#define DATA_SET        (3)     /*!< op1, op2, result       */
//#define TEST_TYPES      (6)     /*!< 8u,8s,16u,16s,32u,32s  */
//#define TEST_THREE     (150)	//TEST_THREE(is12)x2xTEST_COUNT 

//#include "crc.h"

#ifdef SPIKE_RUN 
#include "data.h"
#endif


/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};
//#include "ui_test.h"          /*!< Test macros            */




     int main(void)    
     {   

   	// test case status 
	volatile int testnumber   = 1;
//	volatile int testtypenum  = 0;


#ifdef SPIKE_RUN
	printf("\nTest/> modulo_inverse tests:\n");
	printf("\n-------------------------------------\n");
#endif

	////////////////////////////// crc Test //////////////////////////////
	//testtypenum++;
        

	for(int testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
 	{
#ifdef SPIKE_RUN	
		MODULO_ARTHEMATIC_SPIKE(uint16_t,uint16_t,op1_16u,op2_16u,result_16u_full,result_16u_tb,testnumber);
        PRINT_RESULT_MODULO(op1_16u,op2_16u,result_16u_tb,result_16u_full,testnumber);
       //printf(" is %d \n received data is %s",final_data1,received_data);

#else
	    MODULO_ARTHEMATIC(MAILBOX1,uint16_t,uint16_t,op1_16u,op2_16u,result_16u_full,testnumber);
#endif
        testnumber++;
    }
	
    mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
	return 0;
}  
