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

/***********************************************/
//             armstrong number                 //
/************************************************/
	

#include<stdio.h>  
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



#define TEST_COUNT      (50)     /*!< Test count             */
#define DATA_SET        (2)    /*!< array of 10 elements      */
//#define TEST_TYPES      (6)     /*!< 8u,8s,16u,16s,32u,32s  */
//#define TEST_THREE     (150)	//TEST_THREE(is12)x2xTEST_COUNT 

//TO STORE THE RESULTS//---------------------------------------------
uint64_t actual_result[TEST_COUNT*DATA_SET] __attribute((section(".results"))) = {0,};//memory locations from data.h

/* Main function */
int main(void)
{ 
	/* test case status */
	volatile int testnumber   = 1;
//	volatile int testtypenum  = 0;

//--------------------------------Armstrong no test -------------------------------/
#ifdef SPIKE_RUN
	printf("\nTest/> Armstrong no test\n");
    printf("----------------------------------- \n");
#endif
 


    for(int testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
  	{ 
#ifdef SPIKE_RUN
        ARMSTRONG_TEST_SPIKE(data_input, temp, remainder,rslt_full,rslt_tb,testnumber);
        PRINT_RESULT_ARMSTRONG(testnumber,rslt_full,rslt_tb);

 #else 

        ARMSTRONG_TEST_C(MAILBOX1,data_input,temp,remainder,rslt_full,testnumber);


#endif
       // testnumber++;
   	}
        
//	mailbox_send_request(MAILBOX1, MEM_DUMP);
//	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);    
    
    return 0;

}


/*	int main()    
	{    
		int n,r,sum=0,temp;    
		z_printf("enter the number=");    
	   ///	scanf("%d",&n); 
       n=372;
	   temp=n;    
		while(n>0)    
		{    
			r=n%10;    
			sum=sum+(r*r*r);    
			n=n/10;    
		}    
		if(temp==sum) 
        {   
        z_printf("sum =%d", sum);			
		z_printf("armstrong  number ");
        }
		else    
		z_printf("it is not armstrong number");  


         mailbox_send_request(MAILBOX1, END_SIM);
         mailbox_send_request(MAILBOX2, error_cnt);

		return 0;  
	}   */
