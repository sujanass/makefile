//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Copyright Â© 2022 Vivartan Technologies., All rights reserved/////////////////////////////
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
// Copyright © 2021 Vivartan Technologies., All rights reserved.
// 
// All works published under Zilla_Gen_0 by the Vivartan Technologies. 
// is copyrighted by the Association and ownership of all right, title and interest
// in and to the works remains with Vivartan Technologies.
// 
// No works or documents published under Zilla_Gen_0 by Vivartan Technologies. may be reproduced,
// transmitted or copied without the express written permission of Vivartan Technologies.
// will be considered as a violations of Copyright Act and it may lead to legal action.



/*
**
*******************************************************************************
** Load Store  Program Part 3 (Min offset Cases)for Zilla 
** Immediate Addres is of 12bit ,i.e.(-2048 , 2047 )
** Immediate Address is generated using python script
** Note: Minimum offset = 12'd -2048
*******************************************************************************
*/

#include <stdio.h>              /*!< Standard IO            */
#include <limits.h>             /*!< Datatype limit         */
#include <stdint.h>             /*!< Standarad Integer type */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
#include "testmacro.h"          /*!< Test macros            */

#ifdef SPIKE_RUN
#include "data.h"               /*!< Testbench created data */
#endif

/* Note: TEST_COUNT indicates number of test for each tests. e.g. TEST_COUNT number
   of tests for load byte  signed , TEST_COUNT number of tests for load byte unsigned , etc*/
#define TEST_COUNT     (6)    /*!< Test count             */
#define DATA_SET        (3)     /*!< op1, op2, result       */
#define TEST_TYPES      (7)     /*!< lb , lbu , lh , lhu , lw , lwu , ld  */
#define STORE_TYPES    (4)      /* sb , sh, sw, sd */
#define BANK_COUNT      (62)    /* Total Memory bank count */
#define START_ADDRS     (0x48120) /* Starting Address of Data Memory */

/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};
#include "ui_load_store_3_test.h"       /* Load store header file         */


int main(void){
  volatile int testnumber   = 1;
  volatile int testtypenum  = 0;


int	num_of_elements_memdump = (BANK_COUNT * DATA_SET * TEST_TYPES)   ;
//                          =  

////////////////////////////////////////////////////////////////////////////////////////////////
//
////////////////////////Load Store PART 3: Min offset Test Cases ///////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////////////////////

/******************* Store byte and Load byte signed min test cases  *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store byte and Load byte signed min test cases \n");
	printf("\n------------------------------\n");
#endif

    test_sb_lb_min_type(testnumber) ;
    testnumber += BANK_COUNT ;


/******************* Store byte and Load byte unsigned min test cases  *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store byte and Load byte unsigned min test cases \n");
	printf("\n------------------------------\n");
#endif

    test_sb_lbu_min_type(testnumber) ;
    testnumber += BANK_COUNT ;

/******************* Store half word and Load half word signed min test cases  *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store half word and Load half word signed min test cases \n");
	printf("\n------------------------------\n");
#endif

    test_sh_lh_min_type(testnumber) ;
    testnumber += BANK_COUNT ;


/******************* Store half word and Load half word unsigned min test cases  *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store half word and Load half word unsigned min test cases \n");
	printf("\n------------------------------\n");
#endif

    test_sh_lhu_min_type(testnumber) ;
    testnumber += BANK_COUNT ;

/******************* Store word and Load word signed min test cases  *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store word and Load word signed min test cases \n");
	printf("\n------------------------------\n");
#endif

    test_sw_lw_min_type(testnumber) ;
    testnumber += BANK_COUNT ;

/******************* Store word and Load word unsigned min test cases  *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store word and Load word unsigned min test cases \n");
	printf("\n------------------------------\n");
#endif

    test_sw_lwu_min_type(testnumber) ;
    testnumber += BANK_COUNT ;

/******************* Store double word and Load double word  min test cases  *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store double word and Load doble word min test cases \n");
	printf("\n------------------------------\n");
#endif

    test_sd_ld_min_type(testnumber) ;
    testnumber += BANK_COUNT ;

#ifdef SPIKE_RUN
	printf("__boot_address        = 0x%X\n",(uint32_t)&__boot_address);
	printf("__etext               = 0x%X\n",(uint32_t)&__etext);
	printf("__data_address        = 0x%X\n",(uint32_t)&__data_address);
	printf("__DATA_BEGIN__        = 0x%X\n",(uint32_t)&_start_data);
	printf("__SDATA_BEGIN__       = 0x%X\n",(uint32_t)&__SDATA_BEGIN__);
	printf("__edata               = 0x%X\n",(uint32_t)&_edata);
	printf("__bss_start           = 0x%X\n",(uint32_t)&_start_bss);
	printf("__bss_end             = 0x%X\n",(uint32_t)&_end_bss);
	printf("__heap_start          = 0x%X\n",(uint32_t)&__heap_start);
	printf("__heap_end            = 0x%X\n",(uint32_t)&__heap_end);
	printf("__stack_start         = 0x%X\n",(uint32_t)&__stack_start);
	printf("__stack_end           = 0x%X\n",(uint32_t)&_end_stack);
#endif

    mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
return 0 ;
}

