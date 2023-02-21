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
#include <stdlib.h>
#include <limits.h>             /*!< Datatype limit         */
#include <stdint.h>             /*!< Standarad Integer type */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
#include "data.h"               /*!< Testbench created data */




/* Note: TEST_COUNT indicates number of test for each tests. e.g. TEST_COUNT number
   of tests for uint8_t multiplication, TEST_COUNT number of tests for int8_t multiplication, etc*/
#define TEST_COUNT     (1)    /*!< Test count             */
#define DATA_SET        (1083)     /*!< array of 10 elements      */
//#define TEST_TYPES      (12)     /*!< Buuble sort,Insertion sort,Selection sort,Quick sort,Count sort,Bucket sort,Radix sort,Shell sort*/

/* Array to store the operand1, operand2 and actual result */
int64_t actual_result[1083] __attribute((section(".results"))) = {0,};

/* Main function */

#include "testcordic.h"           /*!< Test macros            */

int main(void)
    {
    int input_angle[361];
    int rslt_tb_cos_arr[361];
    int rslt_tb_sin_arr[361];
    int rslt_full_cos_arr[361];
    int rslt_full_sin_arr[361];

   /* test case status */
	volatile int testtypenum  = 0;
   	int64_t num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*1083);

   	/***********************************Cordic algorithm ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Cordic algorithm for sin and cos values\n");
    printf("----------------------------------- \n");
    printf("ENTERING INTO THE SPIKE LOOP");	
#endif
 
    for(int testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
  	{
#ifdef SPIKE_RUN
    int iterations = 16;
    int theta_inp;
    int sins,coss;
      for(int k=0;k<361;k++)
        {
          theta_inp=k;
          CORDIC_SIN_COS_TEST_SPIKE_C(theta_inp,iterations,testnumber,&sins,&coss,input_angle,k,rslt_full_cos_arr,rslt_full_sin_arr,rslt_tb_cos_arr,rslt_tb_sin_arr);
          printf("Sin and cos values from cordic algorithm %d \n",testnumber);
    	}

          PRINT_RESULT_CORDIC(iterations,rslt_tb_cos_arr,rslt_tb_sin_arr,rslt_full_cos_arr,rslt_full_sin_arr,testnumber);
#else  
        z_printf("wwwwwwwww");
        int iterations = 16;
        int inp_angle;
        int sins,coss;
        for(int k=0;k<361;k++)
         {
           inp_angle=k;
           input_angle[k]=k;
           CORDIC_SIN_COS_TEST_C(MAILBOX1,inp_angle,iterations,testnumber,&sins,&coss,k); 
         }
         z_printf("wwwwwwwww");
#endif
      

   	}
        
	mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);    
    
    return 0;

}

