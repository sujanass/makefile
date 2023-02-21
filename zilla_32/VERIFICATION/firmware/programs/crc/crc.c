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
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
#include "crc.h"

#ifdef SPIKE_RUN
#include "data.h"               /*!< Testbench created data */
#endif


#define TEST_COUNT     (2)    /*!< Test count             */
#define DATA_SET        (30)    
#define TEST_TYPES      (2)     

int64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};
int64_t *p ;
              

int main(void)
{
	/* test case status */
	//volatile int testnumber   = 1;
	volatile int testtypenum  = 0;
   	int64_t num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*30*2) ;
    
#ifdef SPIKE_RUN
    printf("-------------------------------------------------------------------------------------------------------\n");
	printf("\nTest/> crc tests:\n");
    printf("-------------------------------------------------------------------------------------------------------\n");
#endif
////////////////////////////// crc Test //////////////////////////////
	for(int testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
	{
     
#ifdef SPIKE_RUN	
    uint8_t data_dec_tb,gen_dec_tb,flag_tb,flag;
	CRC_TEST_SPIKE(data_dec_tb,gen_dec_tb,flag,flag_tb,len,rslt_tb,rslt_full,testnumber);
    PRINT_RESULT_CRC(flag,flag_tb,len,rslt_tb,rslt_full,testnumber);
#else
    uint8_t data_dec,gen_dec,flag;
	CRC_TEST_C(MAILBOX1,data_dec,gen_dec,flag,rslt_full,testnumber);
#endif
  p=p+1;
        
   	}
/////////////////////////////////////////////////////////////////////////////////////////
#ifdef SPIKE_RUN
    printf("---------------------------------------------------------------------------------------------------------\n");
	printf("\nTest/> With error test\n");
    printf("---------------------------------------------------------------------------------------------------------\n");

#endif

testtypenum++;
 
        	
for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
 
        
#ifdef SPIKE_RUN	
    uint8_t data_dec_tb,gen_dec_tb,flag,flag_tb;
	CRC_TEST_ERROR_SPIKE(data_dec_tb,gen_dec_tb,flag,flag_tb,len,rslt_tb,rslt_full,testnumber);
    PRINT_RESULT_CRC(flag,flag_tb,len,rslt_tb,rslt_full,testnumber);
#else
    uint8_t data_dec,gen_dec,flag;
	CRC_TEST_ERROR_C(MAILBOX1,data_dec,gen_dec,flag,rslt_full,testnumber);
#endif
  p=p+1;
        
   	}
    
	mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);    
    
    return 0;

}

