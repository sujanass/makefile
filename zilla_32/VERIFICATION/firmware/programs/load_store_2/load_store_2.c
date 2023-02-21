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
** Load Store  Program Part 2 (MAX offset Cases)for Zilla 
** Immediate Addres is of 12bit ,i.e.(-2048 , 2047 )
** Immediate Address is generated using python script
** Note Max offset for:
        byte = 12'd2047 
        half word = 12'd 2046
        word = 12'd 2044
        double word = 12'd 2040
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
#include "ui_load_store_2_test.h"       /* Load header file         */


int main(void){
    volatile int testnumber   = 1;
	volatile int testtypenum  = 0;
    int	num_of_elements_memdump = (BANK_COUNT * DATA_SET * TEST_TYPES)   ; 
/////////////////////////////////////////////////////////////////////////////////////////////////
//
////////////////////////Load Store  PART 2: Max offset test cases ///////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////////////////////

/******************* Store byte and Load byte signed max test cases  *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store byte and Load byte signed MAX test cases \n");
	printf("\n------------------------------\n");
#endif

    test_sb_lb_max_type(testnumber) ;
    testnumber += BANK_COUNT ;


/******************* Store byte and Load byte unsigned max test cases  *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store byte and Load byte unsigned MAX test cases \n");
	printf("\n------------------------------\n");
#endif

    test_sb_lbu_max_type(testnumber) ;
    testnumber += BANK_COUNT ;

/******************* Store half word and Load half word signed max test cases  *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store half word and Load half word signed MAX test cases \n");
	printf("\n------------------------------\n");
#endif

    test_sh_lh_max_type(testnumber) ;
    testnumber += BANK_COUNT ;


/******************* Store half word and Load half word unsigned max test cases  *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store half word and Load half word unsigned MAX test cases \n");
	printf("\n------------------------------\n");
#endif

    test_sh_lhu_max_type(testnumber) ;
    testnumber += BANK_COUNT ;

/******************* Store word and Load word signed max test cases  *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store word and Load word signed MAX test cases \n");
	printf("\n------------------------------\n");
#endif

    test_sw_lw_max_type(testnumber) ;
    testnumber += BANK_COUNT ;

/******************* Store word and Load word unsigned max test cases  *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store word and Load word unsigned MAX test cases \n");
	printf("\n------------------------------\n");
#endif

test_sw_lwu_max_type(testnumber) ;
testnumber += BANK_COUNT ;

/******************* Store double word and Load double word  max test cases  *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store double word and Load doble word MAX test cases \n");
	printf("\n------------------------------\n");
#endif

    test_sd_ld_max_type(testnumber) ;
    testnumber += BANK_COUNT ;



    mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
return 0 ;
}

