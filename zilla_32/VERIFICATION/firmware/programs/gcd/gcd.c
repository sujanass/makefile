////////////////////


#include<stdio.h>  
#include <stdlib.h>
#include <limits.h>             /*!< Datatype limit         */
#include <stdint.h>             /*!< Standarad Integer type */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
#include "testmacro.h"          /*!< Test macros            */


#include "testapi.h"  

#ifdef SPIKE_RUN
#include "data.h"               /*!< Testbench created data */
#endif

/* Note: TEST_COUNT indicates number of test for each tests. e.g. TEST_COUNT number
   of tests for uint8_t multiplication, TEST_COUNT number of tests for int8_t multiplication, etc*/
#define TEST_COUNT     (5)    /*!< Test count             */
#define DATA_SET        (30)   /*!< array of 10 elements      */
//#define TEST_TYPES      (12)     /*!< Buuble sort,Insertion sort,Selection sort,Quick sort,Count sort,Bucket sort,Radix sort,Shell sort*/
   
/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*DATA_SET] __attribute((section(".results"))) = {0,};
uint64_t *p ;

int main()
{
   //volatile int testnumber=1;
    volatile int testtypenum  = 0;
   	int64_t num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*30) ;

    #ifdef SPIKE_RUN
	printf("\nTest/> GCD\n");
    printf("----------------------------------- \n");

#endif
 
    for(int testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
  	{
#ifdef SPIKE_RUN
                GCD_SPIKE(op1_u,op2_u,result_full,result_tb,testnumber);
       
                PRINT_GCD(op1_u,op2_u,result_tb,result_full);
  
#else
         //random_array_palindrome(MAILBOX1, number,testnumber);

            GCD_C(MAILBOX1,op1_u,op2_u,result_16u_full,testnumber);
             //random_array_palindrome(MAILBOX1, number,testnumber);
        	  
#endif
       // p=p+len;

   	}

    mailbox_send_request(MAILBOX1, MEM_DUMP);
    mailbox_send_request(MAILBOX2,num_of_elements_memdump);
    mailbox_send_request(MAILBOX1, END_SIM);
    mailbox_send_request(MAILBOX2, error_cnt); 
  return 0;

}  
