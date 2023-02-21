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
** Test program for Multiplication
**
*******************************************************************************
*/

#include <stdio.h>              /*!< Standard IO            */
#include <limits.h>             /*!< Datatype limit         */GG
#include <stdint.h>             /*!< Standarad Integer type */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
#include "testmacro.h"          /*!< Test macros            */

#ifdef SPIKE_RUN
#include "data.h"               /*!< Testbench created data */
#endif

/* Note: TEST_COUNT indicates number of test for each tests. e.g. TEST_COUNT number
   of tests for uint8_t multiplication, TEST_COUNT number of tests for int8_t multiplication, etc*/
#define TEST_COUNT     (6)    /*!< Test count             */
#define DATA_SET        (3)     /*!< op1, op2, result       */
#define TEST_TYPES      (8)     /*!< 8u,8s,16u,16s,32u,32s,64u,64s  */
   

/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};

#include "ui_and_test.h"          /*!< Test macros  
                                    
/* Main function */
int main(void)
{
	/* test case status */
	volatile int testnumber   = 1;
	volatile int testtypenum  = 0;

	int num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*3*TEST_TYPES*4) + (TEST_COUNT*3*TEST_TYPES*4) + (TEST_COUNT*3*TEST_TYPES *10) + (TEST_COUNT*3*TEST_TYPES*8) + (TEST_COUNT*3*TEST_TYPES*8);
	// num_of_elements_memdump = (test1)  + 	(test2)	 	+ 	(test3)	  + (test4) + (test5)
	
////////////////////////////////////////// C And tests PART 1 ///////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> C And tests:\n");
	printf("\n------------------------------\n");
#endif


#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint8_t  :\n");
#endif
/*********************************** And Test uint8_t ********************************************/

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
                 

	for(testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U8_SPIKE_C(op1_8u,op2_8u,result_8u_full,result_8u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_8u,op2_8u,result_8u_tb,result_8u_full,testnumber,uint8_t);
#else
		AND_TEST_U8_C(MAILBOX1,op1_8u,op2_8u,result_8u_full,testnumber);
               
#endif
	}


/*********************************** And Test uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		AND_TEST_U16_SPIKE_C(op1_16u,op2_16u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_16u,op2_16u,result_16u_tb,result_16u_full,testnumber,uint16_t);
#else
		AND_TEST_U16_C(MAILBOX1,op1_16u,op2_16u,result_16u_full,testnumber);
#endif
	}


/*********************************** And Test uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U32_SPIKE_C(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		AND_TEST_U32_C(MAILBOX1,op1_32u,op2_32u,result_32u_full, testnumber);
#endif
	}


/*********************************** And Test uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U64_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_AND64U(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		AND_TEST_U64_C(MAILBOX1,op1_64u,op2_64u,result_64u_full, testnumber);
#endif
	}


////////////////////////////////////////// Assembly And tests PART 2 ///////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Assembly and tests:\n");
	printf("\n-------------------------------------\n");
#endif

/*********************************** And Test uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint8_t  :\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U8_SPIKE(op1_8u,op2_8u,result_8u_full,result_8u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_8u,op2_8u,result_8u_tb,result_8u_full,testnumber,uint8_t);
#else
		AND_TEST_U8(MAILBOX1,op1_8u,op2_8u,result_8u_full,testnumber);
#endif
	}


/*********************************** And Test uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		AND_TEST_U16_SPIKE(op1_16u,op2_16u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_16u,op2_16u,result_16u_tb,result_16u_full,testnumber,uint16_t);
#else
		AND_TEST_U16(MAILBOX1,op1_16u,op2_16u,result_16u_full,testnumber);
#endif
	}


/*********************************** And Test uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U32_SPIKE(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		AND_TEST_U32(MAILBOX1,op1_32u,op2_32u,result_32u_full, testnumber);
#endif
	}


/*********************************** And Test uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U64_SPIKE(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_AND64U(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		AND_TEST_U64(MAILBOX1,op1_64u,op2_64u,result_64u_full, testnumber);
#endif
	}


////////////////////////////////////////// RISC Compliance Assembly And Tests Part 3 //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Assembly and tests:\n");
	printf("\n-------------------------------------\n");
#endif


/*********************************** And Test uint32_t TEST_RR_SRC1_EQ_DEST********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint32_t for SRC1_EQ_DEST:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U32SRC1_EQ_DEST_SPIKE(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		AND_TEST_U32SRC1_EQ_DEST(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
#endif
	}


/*********************************** And Test uint32_t TEST_RR_SRC2_EQ_DEST********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint32_t for SRC2_EQ_DEST:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U32SRC2_EQ_DEST_SPIKE(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		AND_TEST_U32SRC2_EQ_DEST(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
#endif
	}


/*********************************** And Test uint32_t TEST_RR_SRC12_EQ_DEST********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint32_t for SRC12_EQ_DEST:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U32SRC12_EQ_DEST_SPIKE(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		AND_TEST_U32SRC12_EQ_DEST(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
#endif
	}


/*********************************** And Test uint32_t TEST_RR_ZEROSRC1********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint32_t for ZEROSRC1:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U32ZEROSRC1_SPIKE(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		AND_TEST_U32ZEROSRC1(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
#endif
	}


/*********************************** And Test uint32_t TEST_RR_ZEROSRC2********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint32_t for ZEROSRC2:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U32ZEROSRC2_SPIKE(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		AND_TEST_U32ZEROSRC2(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
#endif
	}


/*********************************** And Test uint32_t TEST_RR_ZEROSRC12********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint32_t for ZEROSRC12:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U32ZEROSRC12_SPIKE(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		AND_TEST_U32ZEROSRC12(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
#endif
	}


/*********************************** And Test uint32_t TEST_RR_ZERODEST********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> ANd Test uint32_t for ZERODEST:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U32ZERODEST_SPIKE(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		AND_TEST_U32ZERODEST(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
#endif
	}


/*********************************** And Test uint32_t TEST_RR_DEST_BYPASS********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint32_t for DEST_BYPASS:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U32DEST_BYPASS_SPIKE(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		AND_TEST_U32DEST_BYPASS(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
#endif
	}


/*********************************** And Test uint32_t TEST_RR_SRC12_BYPASS********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint32_t for SRC12_BYPASS:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U32SRC12_BYPASS_SPIKE(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		AND_TEST_U32SRC12_BYPASS(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
#endif
	}


/*********************************** And Test uint32_t TEST_RR_SRC21_BYPASS********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint32_t for SRC21_BYPASS:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U32SRC21_BYPASS_SPIKE(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		AND_TEST_U32SRC21_BYPASS(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
#endif
	}


////////////////////////////////////////// C And tests PART 4 ///////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> C And tests:\n");
	printf("\n------------------------------\n");
#endif

/*********************************** And Test Max of uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test for Max of uint8_t  :\n");
#endif
	testtypenum++;
	int k = 1+testtypenum*TEST_COUNT;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_MAXU8_SPIKE_C(op1_8u,op2_8u,result_8u_full,result_8u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_8u,op2_8u,result_8u_tb,result_8u_full,testnumber,uint8_t);
#else
		AND_TEST_MAXU8_C(MAILBOX1,op1_8u,op2_8u,result_8u_full,testnumber);
               
#endif
	}
	k++;


/*********************************** And Test Max of uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test for Max of uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		AND_TEST_MAXU16_SPIKE_C(op1_16u,op2_16u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_16u,op2_16u,result_16u_tb,result_16u_full,testnumber,uint16_t);
#else
		AND_TEST_MAXU16_C(MAILBOX1,op1_16u,op2_16u,result_16u_full,testnumber);
#endif
	}
	k++;


/*********************************** And Test Max of uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test for Max of uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_MAXU32_SPIKE_C(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		AND_TEST_MAXU32_C(MAILBOX1,op1_32u,op2_32u,result_32u_full, testnumber);
#endif
	}
	k++;


/*********************************** And Test Max of uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test for Max of uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_MAXU64_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_AND64U(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		AND_TEST_MAXU64_C(MAILBOX1,op1_64u,op2_64u,result_64u_full, testnumber);
#endif
	}
	k++;


/*********************************** And Test Min of uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test for Min of uint8_t  :\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_MINU8_SPIKE_C(op1_8u,op2_8u,result_8u_full,result_8u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_8u,op2_8u,result_8u_tb,result_8u_full,testnumber,uint8_t);
#else
		AND_TEST_MINU8_C(MAILBOX1,op1_8u,op2_8u,result_8u_full,testnumber);
               
#endif
	}
	k++;


/*********************************** And Test Min of uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test for Min of uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		AND_TEST_MINU16_SPIKE_C(op1_16u,op2_16u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_16u,op2_16u,result_16u_tb,result_16u_full,testnumber,uint16_t);
#else
		AND_TEST_MINU16_C(MAILBOX1,op1_16u,op2_16u,result_16u_full,testnumber);
#endif
	}
	k++;


/*********************************** And Test Min of uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test for Min of uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_MINU32_SPIKE_C(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		AND_TEST_MINU32_C(MAILBOX1,op1_32u,op2_32u,result_32u_full, testnumber);
#endif
	}
	k++;


/*********************************** And Test Min of uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test for Min of uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_MINU64_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_AND64U(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		AND_TEST_MINU64_C(MAILBOX1,op1_64u,op2_64u,result_64u_full, testnumber);
#endif
	}
    k ++ ;
//
//
    
/*////////////////////////////////////////// Part 5- ANDI tests ///////////////////////////////////////*/

#ifdef SPIKE_RUN
	printf("\nTest/> C ANDI tests:\n");
	printf("\n------------------------------\n");
#endif


/*********************************** ANDI Test Max of uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> ANDI Test for Max of uint8_t  :\n");
#endif
	testtypenum++;
       /*  Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		ANDI_TEST_MAXU8_SPIKE_C(op1_8u,op2_12u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_8u,op2_12u,result_16u_tb,result_16u_full,testnumber,uint16i_t);
#else
		ANDI_TEST_MAXU8_C(MAILBOX1,op1_8u,op2_12u,result_16u_full,testnumber);
               
#endif
	}
k++;

 /*********************************** ANDI Test Max of uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> ANDI Test for Max of uint16_t  :\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		ANDI_TEST_MAXU16_SPIKE_C(op1_16u,op2_16u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_16u,op2_16u,result_16u_tb,result_16u_full,testnumber,uint16_t);
#else
		ANDI_TEST_MAXU16_C(MAILBOX1,op1_16u,op2_12u,result_16u_full,testnumber);
               
#endif
	}	
k++;

 /*********************************** ANDI Test Max of uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> ANDI Test for Max of uint32_t  :\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		ANDI_TEST_MAXU32_SPIKE_C(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		ANDI_TEST_MAXU32_C(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
               
#endif
	}	
    k++;

 /*********************************** ANDI Test Max of uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> ANDI Test for Max of uint64_t  :\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		ANDI_TEST_MAXU64_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_AND64U(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		ANDI_TEST_MAXU64_C(MAILBOX1,op1_64u,op2_12u,result_64u_full,testnumber);
               
#endif
	}	
k++;

    
/*********************************** ANDI Test Min of uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> ANDI Test for Min of uint8_t  :\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		ANDI_TEST_MINU8_SPIKE_C(op1_8u,op2_8u,result_8u_full,result_8u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_8u,op2_8u,result_8u_tb,result_8u_full,testnumber,uint8_t);
#else
		ANDI_TEST_MINU8_C(MAILBOX1,op1_8u,op2_8u,result_8u_full,testnumber);
               
#endif
	}
    
k++;

/*********************************** ANDI Test Min of uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> ANDI Test for Min of uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		ANDI_TEST_MINU16_SPIKE_C(op1_16u,op2_16u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_16u,op2_16u,result_16u_tb,result_16u_full,testnumber,uint16_t);
#else
		ANDI_TEST_MINU16_C(MAILBOX1,op1_16u,op2_16u,result_16u_full,testnumber);
#endif
	}

k++;
/***gg******************************* ANDI Test Min of uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> ANDI Test for Min of uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		ANDI_TEST_MINU32_SPIKE_C(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ANDU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		ANDI_TEST_MINU32_C(MAILBOX1,op1_32u,op2_32u,result_32u_full, testnumber);
#endif
	}
k++;

/*********************************** ANDI Test Min of uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> ANDI Test for Min of uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		ANDI_TEST_MINU64_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_AND64U(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		ANDI_TEST_MINU64_C(MAILBOX1,op1_64u,op2_64u,result_64u_full, testnumber);
#endif
	}
k++;


testtypenum++ ;

testnumber = k ;

testnumber = test_ui_and_type(testnumber);
//
//

	mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
	return 0;

}

