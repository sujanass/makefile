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
/*
Copyright © 2021 Vivartan Technologies., All rights reserved.

All works published under Zilla_Gen_0 by the Vivartan Technologies. 
is copyrighted by the Association and ownership of all right, title and interest
in and to the works remains with Vivartan Technologies.

No works or documents published under Zilla_Gen_0 by Vivartan Technologies. may be reproduced,
transmitted or copied without the express written permission of Vivartan Technologies.
will be considered as a violations of Copyright Act and it may lead to legal action.
*/ 

/*
*******************************************************************************
**
** Shift Right Logical program for ZILLA. Shifts and prints the result
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

/* Note: TEST_COUNT indicates number of test for each tests. e.g. TEST_COUNT number
   of tests for uint8_t multiplication, TEST_COUNT number of tests for int8_t multiplication, etc*/
#define TEST_COUNT     (3)    /*!< Test count             */
#define DATA_SET        (3)     /*!< op1, op2, result       */
#define TEST_TYPES      (8)     /*!< 8u,8s,16u,16s,32u,32s,64u,64s */
#define TEST_THREE     (96)	//TEST_THREE(is16)x2xTEST_COUNT 

// Minimum and Maximum  value of Unsigned And Signed numbers 
#define UINT8_MIN 0 
#define UINT16_MIN 0 
#define UINT32_MIN 0 
#define UINT64_MIN 0 
#define UINT8_MAX 0xFF
#define UINT16_MAX 0xFFFF
#define UINT32_MAX 0xFFFFFFFF
#define UINT64_MAX 0xFFFFFFFFFFFFFFFF
#define INT8_MAX 0x7F
#define INT16_MAX 0x7FFF
#define INT32_MAX 0x7FFFFFFF
#define INT64_MAX 0x7FFFFFFFFFFFFFFF
#define INT32_MIN 0x80000000

/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};
#include "ui_srl_test.h" 
/* Main function */
int main(void)
{
    /* test case status */
	volatile int testnumber   = 1;
	volatile int testtypenum  = 0;

	int num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*3*16) + (TEST_COUNT*3*16)   + (3*10) + (TEST_COUNT*TEST_TYPES*3 )  + ( 3 * 16 ) ;
	// num_of_elements_memdump = (test1 and 2)  + 	(test3)	 	+ 	(test4)	   + (immediate) + ( immediate 32)+ (Immediate Min and Max cases ) 
    
//////////////////////////////////////////////////////////////////////////////////////////
//
////////////////////////Logical Right Shift PART 1 ///////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> C Logical Right Shift tests:\n");
	printf("\n------------------------------\n");
#endif

////////////////////////  Logical Right Shift Test uint8_t ///////////////////////////////////////
  
#ifdef SPIKE_RUN
     printf("\nTest/> C Logical Right Shift tests:uint8\n");
    printf("\n-----------------------------------\n");
#endif
	for(testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint8_t,uint8_t);
		SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
		SRL_TEST_C(MAILBOX1,op1,op2,result_full,testnumber,uint8_t,uint8_t);
               
#endif
	}


 ////////////////////////  Logical Right Shift Test int8_t ///////////////////////////////////////

	   
#ifdef SPIKE_RUN
     printf("\nTest/> C Logical Right Shift tests: int8\n");
#endif
	testtypenum++;
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_SPIKE_C(op1,op2,result_full,result_tb,testnumber,int8_t,uint8_t);
		SRL_PRINT_RESULT_S(op1,op2,result_tb,result_full,testnumber,int8_t);
#else
		SRL_TEST_C(MAILBOX1,op1,op2,result_full,testnumber,int8_t,uint8_t);
               
#endif
	}

////////////////////////  Logical Right Shift Test uint16_t ///////////////////////////////////////

	   
#ifdef SPIKE_RUN
     printf("\nTest/> C Logical Right Shift tests: uint16_t_t\n");
#endif
	testtypenum++;
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint16_t,uint16_t);
		SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint16_t);
#else
		SRL_TEST_C(MAILBOX1,op1,op2,result_full,testnumber,uint16_t,uint16_t);
               
#endif
	}

////////////////////////  Logical Right Shift Test int16_t ///////////////////////////////////////

	   
#ifdef SPIKE_RUN
     printf("\nTest/> C Logical Right Shift tests: int16_t_t\n");
#endif
	testtypenum++;
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_SPIKE_C(op1,op2,result_full,result_tb,testnumber,int16_t,uint16_t);
		SRL_PRINT_RESULT_S(op1,op2,result_tb,result_full,testnumber,int16_t);
#else
		SRL_TEST_C(MAILBOX1,op1,op2,result_full,testnumber,int16_t,uint16_t);
               
#endif
	}

////////////////////////  Logical Right Shift Test uint32_t ///////////////////////////////////////

	   
#ifdef SPIKE_RUN
     printf("\nTest/> C Logical Right Shift tests: uint32_t_t\n");
#endif
	testtypenum++;
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint32_t,uint32_t);
		SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint32_t);
#else
		SRL_TEST_C(MAILBOX1,op1,op2,result_full,testnumber,uint32_t,uint32_t);
               
#endif
	}

////////////////////////  Logical Right Shift Test int32_t ///////////////////////////////////////

	   
#ifdef SPIKE_RUN
     printf("\nTest/> C Logical Right Shift tests: int32_t_t\n");
#endif
	testtypenum++;
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_SPIKE_C(op1,op2,result_full,result_tb,testnumber,int32_t,uint32_t);
		SRL_PRINT_RESULT_S(op1,op2,result_tb,result_full,testnumber,int32_t);
#else
		SRL_TEST_C(MAILBOX1,op1,op2,result_full,testnumber,int32_t,uint32_t);
               
#endif
	}

////////////////////////  Logical Right Shift Test uint64_t ///////////////////////////////////////

	   
#ifdef SPIKE_RUN
     printf("\nTest/> C Logical Right Shift tests: uint64_t_t\n");
#endif
	testtypenum++;
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint64_t,uint64_t);
		SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint64_t);
#else
		SRL_TEST_C(MAILBOX1,op1,op2,result_full,testnumber,uint64_t,uint64_t);
               
#endif
	}

////////////////////////  Logical Right Shift Test int64_t ///////////////////////////////////////

	   
#ifdef SPIKE_RUN
     printf("\nTest/> C Logical Right Shift tests: int64_t_t\n");
#endif
	testtypenum++;
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_SPIKE_C(op1,op2,result_full,result_tb,testnumber,int64_t,uint64_t);
		SRL_PRINT_RESULT_S(op1,op2,result_tb,result_full,testnumber,int64_t);
#else
		SRL_TEST_C(MAILBOX1,op1,op2,result_full,testnumber,int64_t,uint64_t);
               
#endif
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                       //                                                   
////////////////////////////////////////// Assembly Logical Right Shift Tests Part 2 //////////////////////////////////////
//                                                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Logical Right Shift tests:\n");
	printf("\n-------------------------------------\n");
#endif

////////////////////////////////////////// Logical Right Shift Test uint8_t assembly //////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Logical Right Shift Test uint8_t:\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_U8_SPIKE(op1,op2,result_full,result_tb,testnumber);
		SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
		SRL_TEST_U8(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}


////////////////////////////////////////// Logical Right Shift Test int8_t assembly //////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Logical Right Shift Test uint8_t and int8_t :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_S8_SPIKE(op1,op2,result_full,result_tb,testnumber);
		SRL_PRINT_RESULT_S(op1,op2,result_tb,result_full,testnumber,int8_t);
#else
		SRL_TEST_S8(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}

//////////////////////////uint16_t assembly ////////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Logical Right Shift Testuint16_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_U16_SPIKE(op1,op2,result_full,result_tb,testnumber);
		SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint16_t);
#else
		SRL_TEST_U16(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}


////////////////////////// int16_t assembly ////////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Logical Right Shift Test int16_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_S16_SPIKE(op1,op2,result_full,result_tb,testnumber);
		SRL_PRINT_RESULT_S(op1,op2,result_tb,result_full,testnumber,int16_t);
#else
		SRL_TEST_S16(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}

	
////////////////////////// uint32_t assembly ////////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Logical Right Shift Test uint32_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_U32_SPIKE(op1,op2,result_full,result_tb,testnumber);
		SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint32_t);
#else
		SRL_TEST_U32(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}

	
////////////////////////// int32_t assembly ////////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Logical Right Shift Test int32_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_S32_SPIKE(op1,op2,result_full,result_tb,testnumber);
		SRL_PRINT_RESULT_S(op1,op2,result_tb,result_full,testnumber,int32_t);
#else
		SRL_TEST_S32(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}

	
////////////////////////// uint64_t assembly ////////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Logical Right Shift Test uint64_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_U64_SPIKE(op1,op2,result_full,result_tb,testnumber);
		SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint64_t);
#else
		SRL_TEST_U64(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}

	
////////////////////////// int64_t assembly ////////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Logical Right Shift Test int64_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SRL_TEST_S64_SPIKE(op1,op2,result_full,result_tb,testnumber);
		SRL_PRINT_RESULT_S(op1,op2,result_tb,result_full,testnumber,int64_t);
#else
		SRL_TEST_S64(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}
///////////////////////////////////////// RISC Compliance Assembly Logical Shift Right Tests Part 3 //////////////////////////////////////


#ifdef SPIKE_RUN
   printf("\nTest/> Assembly Logical Shift Right tests:\n");
   printf("\n-------------------------------------\n");
#endif


/*********************************** Logical Shift Right Test uint8_t TEST_RR_SRC1_EQ_DEST********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Logical Shift Right Test uint8_t for SRC1_EQ_DEST:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SRL_TEST_U8SRC1_EQ_DEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SRL_TEST_U8SRC1_EQ_DEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }


/*********************************** Logical Shift Right Test uint8_t TEST_RR_SRC2_EQ_DEST********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Logical Shift Right Test uint8_t for SRC2_EQ_DEST:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SRL_TEST_U8SRC2_EQ_DEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SRL_TEST_U8SRC2_EQ_DEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }


/*********************************** Logical Shift Right Test uint8_t TEST_RR_SRC12_EQ_DEST********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Logical Shift Right Test uint8_t for SRC12_EQ_DEST:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siSRLation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SRL_TEST_U8SRC12_EQ_DEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SRL_TEST_U8SRC12_EQ_DEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }
/*********************************** Logical Shift Right Test uint8_t TEST_RR_ZEROSRC1********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Logical Shift Right Test uint8_t for ZEROSRC1:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siSRLation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SRL_TEST_U8ZEROSRC1_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SRL_TEST_U8ZEROSRC1(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }

/*********************************** Logical Shift Right Test uint8_t TEST_RR_ZEROSRC2********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Logical Shift Right Test uint8_t for ZEROSRC2:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siSRLation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SRL_TEST_U8ZEROSRC2_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SRL_TEST_U8ZEROSRC2(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }
/*********************************** Logical Shift Right Test uint8_t TEST_RR_ZEROSRC12********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Logical Shift Right Test uint8_t for ZEROSRC12:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siSRLation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SRL_TEST_U8ZEROSRC12_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SRL_TEST_U8ZEROSRC12(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }

/*********************************** Logical Shift Right Test uint8_t TEST_RR_ZERODEST********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Logical Shift Right Test uint8_t for ZERODEST:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siSRLation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SRL_TEST_U8ZERODEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SRL_TEST_U8ZERODEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }

/*********************************** Logical Shift Right Test uint8_t TEST_RR_DEST_BYPASS********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Logical Shift Right Test uint8_t for DEST_BYPASS:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siSRLation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SRL_TEST_U8DEST_BYPASS_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SRL_TEST_U8DEST_BYPASS(MAILBOX1,op1,op2,result_full,testnumber);
#endif	
   }


/*********************************** Logical Shift Right Test uint8_t TEST_RR_SRC12_BYPASS********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Logical Shift Right Test uint8_t for SRC12_BYPASS:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siSRLation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SRL_TEST_U8SRC12_BYPASS_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SRL_TEST_U8SRC12_BYPASS(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }
/*********************************** Logical Shift Right Test uint8_t TEST_RR_SRC21_BYPASS********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Logical Shift Right Test uint8_t for SRC21_BYPASS:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siSRLation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SRL_TEST_U8SRC21_BYPASS_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SRL_TEST_U8SRC21_BYPASS(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }

////////////////////////////////////////////////////////////////////////////////////////////
/////                          Part 4 Min and Max Cases	         ///////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////// logical shift right uint8_t min /////////////////////////////
    #ifdef SPIKE_RUN
   printf("\nTest/> Logical Shift Right Test for Max and Min cases:\n");
    printf("\nTest/> Logical Shift Right Test for Max of uint8_t:\n");
#endif
	testtypenum++;
    int k = 1+testtypenum*TEST_COUNT;	
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		SRL_TEST_MAX_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint8_t,uint8_t  );
		SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
		SRL_TEST_MAX_C(MAILBOX1,op1,op2,result_full,testnumber,uint8_t,uint8_t,UINT8_MAX,8);
#endif
}

	k++;



/////////////////////////////////////////////// Logical Shift Right MAX test int8_t ////////////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> Logical Shift Right Test for Max of int8_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	SRL_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber,  int8_t, uint8_t);
	SRL_PRINT_RESULT_S(op1, op2, result_tb, result_full, testnumber, int8_t);
#else
	SRL_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber,  int8_t, uint8_t, INT8_MAX,8);
#endif
}

k++;


/////////////////////////////////////////////////// Logical Shift Right MAX test uint16_t /////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> Logical Shift Right Test for Max of uint16_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	SRL_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber,  uint16_t, uint16_t);
	SRL_PRINT_RESULT_U(op1, op2, result_tb, result_full, testnumber, uint16_t);
#else
	SRL_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber,  uint16_t, uint16_t, UINT16_MAX,16);
#endif
}

k++;



///////////////////////////////////////// Logical Shift Right MAX test int16_t //////////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> Logical Shift Right Test for Max of int16_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	SRL_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber,  int16_t, uint16_t);
	SRL_PRINT_RESULT_S(op1, op2, result_tb, result_full, testnumber, int16_t);
#else
	SRL_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber,  int16_t, uint16_t, INT16_MAX,16);
#endif
}

k++;


/////////////////////////////////////////// Logical Shift Right MAX test uint32_t //////////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> Logical Shift Right Test for Max of uint32_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	SRL_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber,  uint32_t, uint32_t);
	SRL_PRINT_RESULT_U(op1, op2, result_tb, result_full, testnumber, uint32_t);
#else
	SRL_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber,  uint32_t, uint32_t, UINT32_MAX,31);
#endif
}

k++;


//////////////////////////////////////////////// Logical Shift Right MAX test int32_t ///////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> Logical Shift Right Test for Max of int32_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	SRL_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber,  int32_t, uint32_t);
	SRL_PRINT_RESULT_S(op1, op2, result_tb, result_full, testnumber, int32_t);
#else
	SRL_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber,  int32_t, uint32_t, INT32_MAX,31);
#endif
}

k++;



/////////////////////////////////////////////// Logical Shift Right MAX test uint64_t ///////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> Logical Shift Right Test for Max of uint64_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	SRL_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber,  uint64_t, uint64_t);
	SRL_PRINT_RESULT_U(op1, op2, result_tb, result_full, testnumber, uint64_t);
#else
	SRL_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber,  uint64_t, uint64_t, UINT64_MAX,63);
#endif
}

k++;


//////////////////////////////////// Logical Shift Right MAX test int64_t /////////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> Logical Shift Right Test for Max of int64_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	SRL_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber,  int64_t, uint64_t);
	SRL_PRINT_RESULT_S(op1, op2, result_tb, result_full, testnumber, int64_t);
#else
	SRL_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber,  int64_t, uint64_t, INT64_MAX,63);
#endif
}

k++;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////          Min cases      ///////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////// logical shift right min uint8_t ////////////////////////////////////////////////////
    #ifdef SPIKE_RUN
   printf("\nTest/> Logical Shift Right Test for MIN  cases:\n");
    printf("\nTest/> Logical Shift Right Test for MIN of uint8_t:\n");
#endif
	testtypenum++;

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		SRL_TEST_MIN_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint8_t,uint8_t  );
		SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
		SRL_TEST_MIN_C(MAILBOX1,op1,op2,result_full,testnumber,uint8_t,uint8_t,UINT8_MIN,0);
#endif
}

	k++;



//////////////////////////////////////////// Logical Shift Right MIN test int8_t //////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> Logical Shift Right Test for MIN of int8_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	SRL_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber,  int8_t, uint8_t);
	SRL_PRINT_RESULT_S8(op1, op2, result_tb, result_full, testnumber, int8_t);
#else
	SRL_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber,  int8_t, uint8_t, INT8_MIN,0);
#endif
}

k++;


/////////////////////////////// Logical Shift Right MIN test uint16_t ////////////////////////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> Logical Shift Right Test for MIN of uint16_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	SRL_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber,  uint16_t, uint16_t);
	SRL_PRINT_RESULT_U(op1, op2, result_tb, result_full, testnumber, uint16_t);
#else
	SRL_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber,  uint16_t, uint16_t, UINT16_MIN,0);
#endif
}

k++;



///////////////////////////////////////// Logical Shift Right MIN test int16_t /////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> Logical Shift Right Test for MIN of int16_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	SRL_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber,  int16_t, uint16_t);
	SRL_PRINT_RESULT_S16(op1, op2, result_tb, result_full, testnumber, int16_t);
#else
	SRL_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber,  int16_t, uint16_t, INT16_MIN,0);
#endif
}

k++;


//////////////////////////////////////Logical Shift Right MIN test uint32_t //////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> Logical Shift Right Test for MIN of uint32_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	SRL_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber,  uint32_t, uint32_t);
	SRL_PRINT_RESULT_U(op1, op2, result_tb, result_full, testnumber, uint32_t);
#else
	SRL_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber,  uint32_t, uint32_t, UINT32_MIN,0);
#endif
}

k++;



///////////////////////////////////////// Logical Shift Right MIN test int32_t ///////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> Logical Shift Right Test for MIN of int32_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	SRL_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber,  int32_t, uint32_t);
	SRL_PRINT_RESULT_S(op1, op2, result_tb, result_full, testnumber, int32_t);
#else
	SRL_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber,  int32_t, uint32_t, INT32_MIN,0);
#endif
}

k++;


//////////////////////////////////////////// Logical Shift Right MIN test uint64_t //////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> Logical Shift Right Test for MIN of uint64_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	SRL_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber,  uint64_t, uint64_t);
	SRL_PRINT_RESULT_U(op1, op2, result_tb, result_full, testnumber, uint64_t);
#else
	SRL_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber,  uint64_t, uint64_t, UINT64_MIN,0);
#endif
}

k++;


///////////////////////////////////// Logical Shift Right MIN test int64_t //////////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> Logical Shift Right Test for MIN of int64_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	SRL_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber,  int64_t, uint64_t);
	SRL_PRINT_RESULT_S(op1, op2, result_tb, result_full, testnumber, int64_t);
#else
	SRL_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber,  int64_t, uint64_t, INT64_MIN,0);
#endif
}

k++;


///////////////////////////////////////////////////////////////////////////////////////////////////////
//

/******************************************Immediate Logical Shift Right ****************************/
//
////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////SRLI uint64_t bit ////////////////////////////////////////////////////
#ifdef SPIKE_RUN
    printf("\n \n \n");
	printf("\nTest/> SRLI uint64_t Test   :\n");
#endif
 test_srli_ui_type(k);
 k=k+ TEST_COUNT ;
//////////////////////////////////// SRLIW uint32_t bit ///////////////////////////////////////////////////
#ifdef SPIKE_RUN
    printf("\n  \n");
	printf("\nTest/> SRLIW uint32_t Test   :\n");
#endif

test_srliw_ui_type(k);
k= k + TEST_COUNT ;

////////////////////////////////////// SRLIW uint16_t bit ///////////////////////////////////////////////////
#ifdef SPIKE_RUN
    printf("\n  \n");
	printf("\nTest/> SRLIW uint16_t bit Test   :\n");
#endif

test_srliw_u16_ui_type(k);
k= k + TEST_COUNT ;

//////////////////////////////////////SRLIW uint8_t  ///////////////////////////////////////////////////////
#ifdef SPIKE_RUN
    printf("\n  \n");
	printf("\nTest/> SRLIW uint8_bit Test   :\n");
#endif

test_srliw_u8_ui_type(k);
k= k + TEST_COUNT ;


//////////////////////////////////////SRLI  int64_t bit ///////////////////////////////////////////////////////
#ifdef SPIKE_RUN
    printf("\n \n \n");
	printf("\nTest/> SRLIW int64_bit Test   :\n");
#endif

test_srli_s64_ui_type(k);
k= k + TEST_COUNT ;


//////////////////////////////////////SRLIW int32_t bit ///////////////////////////////////////////////////////
#ifdef SPIKE_RUN
    printf("\n \n \n");
	printf("\nTest/> SRLIW int32_bit Test   :\n");
#endif

test_srliw_s32_ui_type(k);
k= k + TEST_COUNT ;


//////////////////////////////////////SRLIW int16_t   ///////////////////////////////////////////////////////
#ifdef SPIKE_RUN
    printf("\n \n \n");
	printf("\nTest/> SRLIW int16_bit Test   :\n");
#endif

test_srliw_s16_ui_type(k);
k= k + TEST_COUNT ;


//////////////////////////////////////SRLIW int8_t  ///////////////////////////////////////////////////////
#ifdef SPIKE_RUN
    printf("\n \n \n");
	printf("\nTest/> SRLIW int8_bit Test   :\n");
#endif

test_srliw_s8_ui_type(k);
k= k + TEST_COUNT ;


////////////////////////////////////////////////////////////////////////////////////////////
/////                SRL-immediatee         Part 2 Min and Max Cases	         ///////////
////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////// immediate logical shift right uint8_t min /////////////////////////////
    #ifdef SPIKE_RUN
   printf("\nTest/> immediate logical shift right Test for Max and Min cases:\n");
    printf("\nTest/> immediate logical shift right Test for Max of uint8_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		TEST_MAX_MIN_SRLIW_INSN_I_SPIKE(srliw , op1, op2 , result_full, result_tb, testnumber,uint8_t,uint8_t  );
		SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
		TEST_MAX_MIN_SRLIW_INSN_I(srliw, op1, op2, result_full, testnumber,uint8_t,uint8_t,UINT8_MAX,8);
#endif
}

	k++;



/////////////////////////////////////////////// immediate logical shift right MAX test int8_t ////////////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> Immediate logical shift right Test for Max of int8_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
  
#ifdef SPIKE_RUN
	TEST_MAX_MIN_SRLIW_INSN_I_SPIKE(srliw , op1, op2 , result_full, result_tb, testnumber,  int8_t, int8_t);
	SRL_PRINT_RESULT_S(op1, op2, result_tb, result_full, testnumber, int8_t);
#else
	TEST_MAX_MIN_SRLIW_INSN_I(srliw, op1, op2, result_full, testnumber,  int8_t, uint8_t, INT8_MAX,8);
#endif
}


k++;


/////////////////////////////////////////////////// immediate logical shift right MAX test uint16_t /////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> immediate logical shift right Test for Max of uint16_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	TEST_MAX_MIN_SRLIW_INSN_I_SPIKE(srliw , op1, op2 , result_full, result_tb, testnumber,  uint16_t, uint16_t);
	SRL_PRINT_RESULT_U(op1, op2, result_tb, result_full, testnumber, uint16_t);
#else
	TEST_MAX_MIN_SRLIW_INSN_I(srliw, op1, op2, result_full, testnumber,  uint16_t, uint16_t, UINT16_MAX,16);
#endif
}

k++;



///////////////////////////////////////// immediate logical shift right MAX test int16_t //////////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> immediate logical shift right Test for Max of int16_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	TEST_MAX_MIN_SRLIW_INSN_I_SPIKE(srliw , op1, op2 , result_full, result_tb, testnumber,  int16_t, int16_t);
	SRL_PRINT_RESULT_S(op1, op2, result_tb, result_full, testnumber, int16_t);
#else
	TEST_MAX_MIN_SRLIW_INSN_I(srliw, op1, op2, result_full, testnumber,  int16_t, int16_t, INT16_MAX,16);
#endif
}

k++;


/////////////////////////////////////////// immediate logical shift right MAX test uint32_t //////////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> immediate logical shift right Test for Max of uint32_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	TEST_MAX_MIN_SRLIW_INSN_I_SPIKE(srliw , op1, op2 , result_full, result_tb, testnumber,  uint32_t, uint32_t);
	SRL_PRINT_RESULT_U(op1, op2, result_tb, result_full, testnumber, uint32_t);
#else
	TEST_MAX_MIN_SRLIW_INSN_I(srliw, op1, op2, result_full, testnumber,  uint32_t, uint32_t, UINT32_MAX,31);
#endif
}

k++;


//////////////////////////////////////////////// immediate logical shift right MAX test int32_t ///////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> immediate logical shift right Test for Max of int32_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	TEST_MAX_MIN_SRLIW_INSN_I_SPIKE(srliw , op1, op2 , result_full, result_tb, testnumber,  int32_t, int32_t);
	SRL_PRINT_RESULT_S(op1, op2, result_tb, result_full, testnumber, int32_t);
#else
	TEST_MAX_MIN_SRLIW_INSN_I(srliw, op1, op2, result_full, testnumber,  int32_t, int32_t, INT32_MAX,31);
#endif
}

k++;



/////////////////////////////////////////////// immediate logical shift right MAX test uint64_t ///////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> immediate logical shift right Test for Max of uint64_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	TEST_MAX_MIN_SRLI_INSN_I_SPIKE(srli, op1, op2 , result_full, result_tb, testnumber,  uint64_t, uint64_t);
	SRL_PRINT_RESULT_U(op1, op2, result_tb, result_full, testnumber, uint64_t);
#else
	TEST_MAX_MIN_SRLI_INSN_I(srli, op1, op2, result_full, testnumber,  uint64_t, uint64_t, UINT64_MAX,63);
#endif
}

k++;


//////////////////////////////////// immediate logical shift right MAX test int64_t /////////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> immediate logical shift right Test for Max of int64_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	TEST_MAX_MIN_SRLI_INSN_I_SPIKE(srli , op1, op2 , result_full, result_tb, testnumber,  int64_t, int64_t);
	SRL_PRINT_RESULT_S(op1, op2, result_tb, result_full, testnumber, int64_t);
#else
	TEST_MAX_MIN_SRLI_INSN_I(srli, op1, op2, result_full, testnumber,  int64_t, int64_t, INT64_MAX,63);
#endif
}

k++;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////          Min cases      ///////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////// immediate logical shift right min uint8_t ////////////////////////////////////////////////////
    #ifdef SPIKE_RUN
   printf("\nTest/> immediate logical shift right Test for MIN  cases:\n");
    printf("\nTest/> immediate logical shift right Test for MIN of uint8_t:\n");
#endif
	testtypenum++;

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		TEST_MAX_MIN_SRLIW_INSN_I_SPIKE(srliw , op1, op2 , result_full, result_tb, testnumber,uint8_t,uint8_t  );
		SRL_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
		TEST_MAX_MIN_SRLIW_INSN_I(srliw, op1, op2, result_full, testnumber,uint8_t,uint8_t,UINT8_MIN,0);
#endif
}

	k++;



//////////////////////////////////////////// immediate logical shift right MIN test int8_t //////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> immediate logical shift right Test for MIN of int8_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	TEST_MAX_MIN_SRLIW_INSN_I_SPIKE(srliw , op1, op2 , result_full, result_tb, testnumber,  int8_t, int8_t);
	SRL_PRINT_RESULT_S8(op1, op2, result_tb, result_full, testnumber, int8_t);
#else
	TEST_MAX_MIN_SRLIW_INSN_I(srliw, op1, op2, result_full, testnumber,  int8_t, int8_t, INT8_MIN,0);
#endif
}

k++;


/////////////////////////////// immediate logical shift right MIN test uint16_t ////////////////////////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> immediate logical shift right Test for MIN of uint16_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	TEST_MAX_MIN_SRLIW_INSN_I_SPIKE(srliw , op1, op2 , result_full, result_tb, testnumber,  uint16_t, uint16_t);
	SRL_PRINT_RESULT_U(op1, op2, result_tb, result_full, testnumber, uint16_t);
#else
	TEST_MAX_MIN_SRLIW_INSN_I(srliw, op1, op2, result_full, testnumber,  uint16_t, uint16_t, UINT16_MIN,0);
#endif
}

k++;



///////////////////////////////////////// immediate logical shift right MIN test int16_t /////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> immediate logical shift right Test for MIN of int16_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	TEST_MAX_MIN_SRLIW_INSN_I_SPIKE(srliw , op1, op2 , result_full, result_tb, testnumber,  int16_t, int16_t);
	SRL_PRINT_RESULT_S16(op1, op2, result_tb, result_full, testnumber, int16_t);
#else
	TEST_MAX_MIN_SRLIW_INSN_I(srliw, op1, op2, result_full, testnumber,  int16_t, int16_t, INT16_MIN,0);
#endif
}

k++;


//////////////////////////////////////immediate logical shift right MIN test uint32_t //////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> immediate logical shift right Test for MIN of uint32_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	TEST_MAX_MIN_SRLIW_INSN_I_SPIKE(srliw , op1, op2 , result_full, result_tb, testnumber,  uint32_t, uint32_t);
	SRL_PRINT_RESULT_U(op1, op2, result_tb, result_full, testnumber, uint32_t);
#else
	TEST_MAX_MIN_SRLIW_INSN_I(srliw, op1, op2, result_full, testnumber,  uint32_t, uint32_t, UINT32_MIN,0);
#endif
}

k++;



///////////////////////////////////////// immediate logical shift right MIN test int32_t ///////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> immediate logical shift right Test for MIN of int32_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	TEST_MAX_MIN_SRLIW_INSN_I_SPIKE(srliw , op1, op2 , result_full, result_tb, testnumber,  int32_t, int32_t);
	SRL_PRINT_RESULT_S(op1, op2, result_tb, result_full, testnumber, int32_t);
#else
	TEST_MAX_MIN_SRLIW_INSN_I(srliw, op1, op2, result_full, testnumber,  int32_t, int32_t, INT32_MIN,0);
#endif
}

k++;




//////////////////////////////////////////// immediate logical shift right MIN test uint64_t //////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> immediate logical shift right Test for MIN of uint64_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	TEST_MAX_MIN_SRLI_INSN_I_SPIKE(srli , op1, op2 , result_full, result_tb, testnumber,  uint64_t, uint64_t);
	SRL_PRINT_RESULT_U(op1, op2, result_tb, result_full, testnumber, uint64_t);
#else
	TEST_MAX_MIN_SRLI_INSN_I(srli, op1, op2, result_full, testnumber,  uint64_t, uint64_t, UINT64_MIN,0);
#endif
}

k++;


///////////////////////////////////// immediate logical shift right MIN test int64_t //////////////////////////////////////////
#ifdef SPIKE_RUN

printf("\nTest/> immediate logical shift right Test for MIN of int64_t :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	TEST_MAX_MIN_SRLI_INSN_I_SPIKE(srli , op1, op2 , result_full, result_tb, testnumber,  int64_t, int64_t);
	SRL_PRINT_RESULT_S(op1, op2, result_tb, result_full, testnumber, int64_t);
#else
	TEST_MAX_MIN_SRLI_INSN_I(srli, op1, op2, result_full, testnumber,  int64_t, int64_t, INT64_MIN,0);
#endif
}

k++;


	mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
    
    return 0;
}

