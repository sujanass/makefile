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
/*
**
*******************************************************************************
** 
** Add upper immediate to pc(U type)) Test Cases 
** Note: Syntax:- auipc rd, Immu{[31:12] + 12'b0}
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


/* Note: TEST_COUNT indicates number of test for each tests */
#define TEST_COUNT     (3)      /*!< Test count             */
#define DATA_SET        (3)     /*!< op1, op2, result       */
#define TEST_TYPES      (4)     

/* Array to store the operand1, operand2 and actual result */
int64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};
#include "ui_auipc_test.h"       /* AUIPC header  */

int main(void){
  volatile int testnumber   = 1;
  volatile int testtypenum  = 0;
  int	num_of_elements_memdump = (TEST_COUNT * DATA_SET ) + ( 2 * DATA_SET)   ; 
//                                  random immediate       +  Min and Max Cases 

////////////////////////////////////////////////////////////////////////////////////////////////
//
////////////////////////Add upper immediate to pc PART 1:Random Immediate test cases ///////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////////////////////


	z_printf("\nTest/> Add upper immediate to pc  test Cases:\n");
	z_printf("\n------------------------------\n");

	z_printf("\n\n-Test/>Add upper immediate to pc Random \n");
	z_printf("\n------------------------------\n");


test_auipc_type(testnumber) ;
testnumber += TEST_COUNT ;


/************************************Add upper immediate to pc Part 2: Max Case ********************/

	z_printf("\n\n-Test/>Add upper immediate to pc MAX Test Cases \n");
	z_printf("\n------------------------------\n");

   
    { TEST_AUIPC_INSN_I( auipc , 0xFFFFF, result, testnumber ,uint32_t , int64_t );}
	testnumber++;


/************************************Add upper immediate to pc Part 2: Max Case ********************/

    z_printf("\n\n-Test/>Add upper immediate to pc Min Test Cases \n");
	z_printf("\n------------------------------\n");

    { TEST_AUIPC_INSN_I( auipc , 0x0, result, testnumber, uint32_t , int64_t);}
	testnumber++;

/************************************Add upper immediate to pc Part 3: Call offset (JALR case) ********************/

    z_printf("\n\n-Test/>Add upper immediate to pc and jump Test Case \n");
	z_printf("\n------------------------------\n");
 
     test_auipc_jalr_type(testnumber) ;
    testnumber += TEST_COUNT ;

/************************************ Add upper immediate to pc Part 4: Tail offset (JALR case) ********************/

    z_printf("\n\n-Test/>Add upper immediate to pc and jump Test Case \n");
	z_printf("\n------------------------------\n");
 
     test_jalr_auipc_type(testnumber) ;
    testnumber += TEST_COUNT ;






    mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
return 0 ;
}

