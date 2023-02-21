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
** 
** Load Upper Immediate(U type)) Test Cases 
** Note: Syntax:- lui rd, Immu{[31:12] + 12'b0}
** 
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

/* Note: TEST_COUNT indicates number of test for each tests */
#define TEST_COUNT     (10)      /*!< Test count             */
#define DATA_SET        (3)     /*!< op1, op2, result       */
#define TEST_TYPES      (3)     

/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};
#include "ui_lui_test.h"       /* LUI header       */


int main(void){
  volatile int testnumber   = 1;
  volatile int testtypenum  = 0;
  int	num_of_elements_memdump = (TEST_COUNT * DATA_SET ) + ( 2 * DATA_SET)   ; 
//                                  random immediate       +  Min and Max Cases 

////////////////////////////////////////////////////////////////////////////////////////////////
//
////////////////////////Load Upper Immediate PART 1:Random Immediate test cases ///////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////////////////////


#ifdef SPIKE_RUN
	printf("\nTest/> Load Upper Immediate  test Cases:\n");
	printf("\n------------------------------\n");
#endif


#ifdef SPIKE_RUN
	printf("\n\n-Test/>Load Upper Immediate Random \n");
	printf("\n------------------------------\n");
#endif


    test_lui_type(testnumber) ;
    testnumber += TEST_COUNT ;

/************************************Load Upper Immediate Part 2: Max Case ********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Load Upper Immediate MAX Test Cases \n");
	printf("\n------------------------------\n");
#endif

   
#ifdef SPIKE_RUN
    { TEST_LUI_INSN_I_SPIKE(lui , op1 , 0xFFFFF, result, exp_result, testnumber , uint32_t ,int64_t);
	PRINT_LUI_TEST_RESULT_I(testnumber, op1 , result, exp_result);
	testnumber++;}
#else
    {TEST_LUI_INSN_I( lui , 0xFFFFF, result, testnumber ,uint32_t , int64_t );
	testnumber++;}
#endif

 /************************************Load Upper Immediate Part 2: Max Case ********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Load Upper Immediate Min Test Cases \n");
	printf("\n------------------------------\n");
#endif

   
#ifdef SPIKE_RUN
    {TEST_LUI_INSN_I_SPIKE(lui , op1 , 0x0, result, exp_result, testnumber , uint32_t ,int64_t);
	PRINT_LUI_TEST_RESULT_I(testnumber, op1 , result, exp_result);
	testnumber++;}
#else
    {TEST_LUI_INSN_I( lui , 0x0, result, testnumber ,uint32_t , int64_t );
	testnumber++;}
#endif

    mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
return 0 ;
}
