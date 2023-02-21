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
#include <stdio.h>              /*!< Standard IO            */
#include <limits.h>             /*!< Datatype limit         */
#include <stdint.h>             /*!< Standarad Integer type */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
#include "testmacro.h"          /*!< Test macros            */


/* Note: TEST_COUNT indicates number of test for each tests */
#define TEST_COUNT     (3)      /*!< Test count             */
#define DATA_SET        (3)  
#define TEST_TYPES      (2)     

int64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};

int main(void){
  volatile int testnumber   = 1;
  volatile int testtypenum  = 0;
  int	num_of_elements_memdump = (TEST_COUNT * DATA_SET ) ;
////////////////////////////////////////////////////////////////////////////////////////////////
//
////////////////////////Jump test cases PART 1:Jump and link  test cases ///////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////////////////////



  	z_printf("\nTest/> Jump instruction test Cases:\n");
	z_printf("\n------------------------------\n");

	z_printf("\n\n-Test/> Jump and link test case \n");
	z_printf("\n------------------------------\n");

  _JAL_();

 testtypenum ++;

 ////////////////////////////////////////////////////////////////////////////////////////////////
//
////////////////////////Jump test cases PART 2:Jump and link register test cases ///////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////////////////////

	z_printf("\n\n-Test/> Jump and link register test case \n");
	z_printf("\n------------------------------\n");

  _JALR_();

 testtypenum ++;



    mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
return 0 ;
}

