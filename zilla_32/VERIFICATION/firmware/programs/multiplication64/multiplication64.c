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
** Test program for Multiplication of double word operands
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
#include "type128.h"            /*!< 128 width variable support  */

#ifdef SPIKE_RUN
#include "data.h"               /*!< Testbench created data */
/* Note: The testbnch generates the the data array which is of the format,
	 data[] = {op1, op2, result_lo, result_hi, op1, op2, result_lo, result_hi, ......}; */
#endif

/* Note: TEST_COUNT indicates number of test for each tests. e.g. TEST_COUNT number
   of tests for uint64_t multiplication, TEST_COUNT number of tests for int64_t multiplication. */
#define TEST_COUNT     (4)    /*!< Test count             */
#define DATA_SET        (4)     /*!< op1, op2, result_lo, result_hi */
#define TEST_TYPES      (6)     /*!< 64u,64s */


/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};

/* Main function */
int main(void)
{
	/* test case status */
	volatile int testnumber   = 1;
	volatile int testtypenum  = -1;

	int num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*4*3) + (TEST_COUNT*4*3) + (TEST_COUNT*4*12) + (TEST_COUNT*4*12) + (TEST_COUNT*4*10) + (4*30);

	////////////////////////////////////////// C Multiplication tests PART 1 ///////////////////////////////////////


	// Note: In 64bit C multiplication, you can not get the upper HIGH bits of the result since you can't 
	// store the results which is 128-bit width.

#ifdef SPIKE_RUN
	printf("\nTest/> C multiplication tests:\n");
	printf("\n------------------------------\n");
#endif

	/*********************************** Multiplication Test uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64_SPIKE_C(op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_64u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t);
#else
		MUL_TEST_U64_C(MAILBOX1,op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	}


	/*********************************** Multiplication Test int64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S64_SPIKE_C(op1_64s,op2_64s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_64s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t);
#else
		MUL_TEST_S64_C(MAILBOX1,op1_64s,op2_64s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	}


	/*********************************** Multiplication Test int64_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_SU64_SPIKE_C(op1_64s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint64_t);
#else
		MUL_TEST_SU64_C(MAILBOX1,op1_64s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	}


	////////////////////////////////////////// Assembly Multiplication Tests Part 2 //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Assembly multiplication tests:\n");
	printf("\n------------------------------\n");
#endif

	/*********************************** Multiplication Test uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64_SPIKE(op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_64u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t);
#else
		MUL_TEST_U64(MAILBOX1,op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	}
	

	/*********************************** Multiplication Test int64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S64_SPIKE(op1_64s,op2_64s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_64s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t);
#else
		MUL_TEST_S64(MAILBOX1,op1_64s,op2_64s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	}


	/*********************************** Multiplication Test int64_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_SU64_SPIKE(op1_64s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint64_t);
#else
		MUL_TEST_SU64(MAILBOX1,op1_64s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	////////////////////////////////////////// C Multiplication tests PART 3 ///////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> C multiplication tests:\n");
	printf("\n------------------------------\n");
#endif

	/*********************************** Multiplication Test uint64_t and uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t and uint8_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64U8_SPIKE_C(op1_64u,op2_8u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_8u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t&uint8_t);
#else
		MUL_TEST_U64U8_C(MAILBOX1,op1_64u,op2_8u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test uint64_t and uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t and uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64U16_SPIKE_C(op1_64u,op2_16u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_16u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t&uint16_t);
#else
		MUL_TEST_U64U16_C(MAILBOX1,op1_64u,op2_16u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test uint64_t and uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t and uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64U32_SPIKE_C(op1_64u,op2_32u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_32u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t&uint32_t);
#else
		MUL_TEST_U64U32_C(MAILBOX1,op1_64u,op2_32u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int64_t and int8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t and int8_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S64S8_SPIKE_C(op1_64s,op2_8s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_8s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&int8_t);
#else
		MUL_TEST_S64S8_C(MAILBOX1,op1_64s,op2_8s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int64_t and int16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t and int16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S64S16_SPIKE_C(op1_64s,op2_16s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_16s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&int16_t);
#else
		MUL_TEST_S64S16_C(MAILBOX1,op1_64s,op2_16s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int64_t and int32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t and int32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S64S32_SPIKE_C(op1_64s,op2_32s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_32s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&int32_t);
#else
		MUL_TEST_S64S32_C(MAILBOX1,op1_64s,op2_32s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int8_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int8_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S8U64_SPIKE_C(op1_8s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_8s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int8_t&uint64_t);
#else
		MUL_TEST_S8U64_C(MAILBOX1,op1_8s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int16_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int16_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S16U64_SPIKE_C(op1_16s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_16s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int16_t&uint64_t);
#else
		MUL_TEST_S16U64_C(MAILBOX1,op1_16s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int32_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int32_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S32U64_SPIKE_C(op1_32s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_32s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int32_t&uint64_t);
#else
		MUL_TEST_S32U64_C(MAILBOX1,op1_32s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int64_t and uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t and uint8_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S64U8_SPIKE_C(op1_64s,op2_8u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_8u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint8_t);
#else
		MUL_TEST_S64U8_C(MAILBOX1,op1_64s,op2_8u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int64_t and uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t and uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S64U16_SPIKE_C(op1_64s,op2_16u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_16u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint16_t);
#else
		MUL_TEST_S64U16_C(MAILBOX1,op1_64s,op2_16u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int64_t and uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t and uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S64U32_SPIKE_C(op1_64s,op2_32u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_32u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint32_t);
#else
		MUL_TEST_S64U32_C(MAILBOX1,op1_64s,op2_32u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	////////////////////////////////////////// Assembly Multiplication Tests Part 4 //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Assembly multiplication tests:\n");
	printf("\n------------------------------\n");
#endif

	/*********************************** Multiplication Test uint64_t and uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t and uint8_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64U8_SPIKE(op1_64u,op2_8u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_8u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t&uint8_t);
#else
		MUL_TEST_U64U8(MAILBOX1,op1_64u,op2_8u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test uint64_t and uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t and uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64U16_SPIKE(op1_64u,op2_16u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_16u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t&uint16_t);
#else
		MUL_TEST_U64U16(MAILBOX1,op1_64u,op2_16u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test uint64_t and uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t and uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64U32_SPIKE(op1_64u,op2_32u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_32u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t&uint32_t);
#else
		MUL_TEST_U64U32(MAILBOX1,op1_64u,op2_32u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int64_t and int8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t and int8_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S64S8_SPIKE(op1_64s,op2_8s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_8s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&int8_t);
#else
		MUL_TEST_S64S8(MAILBOX1,op1_64s,op2_8s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int64_t and int16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t and int16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S64S16_SPIKE(op1_64s,op2_16s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_16s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&int16_t);
#else
		MUL_TEST_S64S16(MAILBOX1,op1_64s,op2_16s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int64_t and int32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t and int32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S64S32_SPIKE(op1_64s,op2_32s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_32s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&int32_t);
#else
		MUL_TEST_S64S32(MAILBOX1,op1_64s,op2_32s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int8_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int8_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S8U64_SPIKE(op1_8s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_8s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int8_t&uint64_t);
#else
		MUL_TEST_S8U64(MAILBOX1,op1_8s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int16_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int16_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S16U64_SPIKE(op1_16s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_16s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int16_t&uint64_t);
#else
		MUL_TEST_S16U64(MAILBOX1,op1_16s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int32_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int32_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S32U64_SPIKE(op1_32s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_32s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int32_t&uint64_t);
#else
		MUL_TEST_S32U64(MAILBOX1,op1_32s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int64_t and uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t and uint8_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S64U8_SPIKE(op1_64s,op2_8u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_8u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint8_t);
#else
		MUL_TEST_S64U8(MAILBOX1,op1_64s,op2_8u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int64_t and uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t and uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S64U16_SPIKE(op1_64s,op2_16u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_16u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint16_t);
#else
		MUL_TEST_S64U16(MAILBOX1,op1_64s,op2_16u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	/*********************************** Multiplication Test int64_t and uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t and uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S64U32_SPIKE(op1_64s,op2_32u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_32u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint32_t);
#else
		MUL_TEST_S64U32(MAILBOX1,op1_64s,op2_32u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 


	///////////////////////////////////// RISC Compliance Assembly Multiplication Tests Part 5 //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Assembly multiplication tests:\n");
	printf("\n-------------------------------------\n");
#endif

	/*********************************** Multiplication Test uint64_t TEST_RR_SRC1_EQ_DEST********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t for SRC1_EQ_DEST:\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64SRC1_EQ_DEST_SPIKE(op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_64u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t);
#else
		MUL_TEST_U64SRC1_EQ_DEST(MAILBOX1,op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint64_t TEST_RR_SRC2_EQ_DEST********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t for SRC2_EQ_DEST:\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64SRC2_EQ_DEST_SPIKE(op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_64u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t);
#else
		MUL_TEST_U64SRC2_EQ_DEST(MAILBOX1,op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint64_t TEST_RR_SRC12_EQ_DEST********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t for SRC12_EQ_DEST:\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64SRC12_EQ_DEST_SPIKE(op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_64u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t);
#else
		MUL_TEST_U64SRC12_EQ_DEST(MAILBOX1,op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint64_t TEST_RR_ZEROSRC1********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t for ZEROSRC1:\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64ZEROSRC1_SPIKE(op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_64u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t);
#else
		MUL_TEST_U64ZEROSRC1(MAILBOX1,op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint64_t TEST_RR_ZEROSRC2********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t for ZEROSRC2:\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64ZEROSRC2_SPIKE(op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_64u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t);
#else
		MUL_TEST_U64ZEROSRC2(MAILBOX1,op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint64_t TEST_RR_ZEROSRC12********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t for ZEROSRC12:\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64ZEROSRC12_SPIKE(op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_64u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t);
#else
		MUL_TEST_U64ZEROSRC12(MAILBOX1,op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint64_t TEST_RR_ZERODEST********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t for ZERODEST:\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64ZERODEST_SPIKE(op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_64u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t);
#else
		MUL_TEST_U64ZERODEST(MAILBOX1,op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint64_t TEST_RR_DEST_BYPASS********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t for DEST_BYPASS:\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64DEST_BYPASS_SPIKE(op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_64u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t);
#else
		MUL_TEST_U64DEST_BYPASS(MAILBOX1,op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint64_t TEST_RR_SRC12_BYPASS********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t for SRC12_BYPASS:\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64SRC12_BYPASS_SPIKE(op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_64u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t);
#else
		MUL_TEST_U64SRC12_BYPASS(MAILBOX1,op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint64_t TEST_RR_SRC21_BYPASS********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t for SRC21_BYPASS:\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64SRC21_BYPASS_SPIKE(op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_64u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t);
#else
		MUL_TEST_U64SRC21_BYPASS(MAILBOX1,op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	}


	////////////////////////////////// Assembly Multiplication tests PART 6 ///////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Assembly multiplication tests :\n");
	printf("\n------------------------------\n");
#endif

	/*********************************** Multiplication Test Max of uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of uint64_t :\n");
#endif
	testtypenum++;
	int k = 1+testtypenum*TEST_COUNT;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXU64_SPIKE(op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_64u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t);
#else
		MUL_TEST_MAXU64(MAILBOX1,op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	}

	k++;
	

	/*********************************** Multiplication Test Max of int64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS64_SPIKE(op1_64s,op2_64s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_64s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t);
#else
		MUL_TEST_MAXS64(MAILBOX1,op1_64s,op2_64s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	}

	k++;


	/*********************************** Multiplication Test Max of int64_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int64_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXSU64_SPIKE(op1_64s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint64_t);
#else
		MUL_TEST_MAXSU64(MAILBOX1,op1_64s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test Max of uint64_t and uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of uint64_t and uint8_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXU64U8_SPIKE(op1_64u,op2_8u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_8u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t&uint8_t);
#else
		MUL_TEST_MAXU64U8(MAILBOX1,op1_64u,op2_8u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test max of uint64_t and uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of uint64_t and uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXU64U16_SPIKE(op1_64u,op2_16u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_16u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t&uint16_t);
#else
		MUL_TEST_MAXU64U16(MAILBOX1,op1_64u,op2_16u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test max of uint64_t and uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of uint64_t and uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXU64U32_SPIKE(op1_64u,op2_32u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_32u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t&uint32_t);
#else
		MUL_TEST_MAXU64U32(MAILBOX1,op1_64u,op2_32u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test max of int64_t and int8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int64_t and int8_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS64S8_SPIKE(op1_64s,op2_8s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_8s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&int8_t);
#else
		MUL_TEST_MAXS64S8(MAILBOX1,op1_64s,op2_8s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test max of int64_t and int16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int64_t and int16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS64S16_SPIKE(op1_64s,op2_16s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_16s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&int16_t);
#else
		MUL_TEST_MAXS64S16(MAILBOX1,op1_64s,op2_16s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test max of int64_t and int32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int64_t and int32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS64S32_SPIKE(op1_64s,op2_32s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_32s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&int32_t);
#else
		MUL_TEST_MAXS64S32(MAILBOX1,op1_64s,op2_32s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test max of int8_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int8_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS8U64_SPIKE(op1_8s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_8s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int8_t&uint64_t);
#else
		MUL_TEST_MAXS8U64(MAILBOX1,op1_8s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test max of int16_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int16_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS16U64_SPIKE(op1_16s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_16s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int16_t&uint64_t);
#else
		MUL_TEST_MAXS16U64(MAILBOX1,op1_16s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test max of int32_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int32_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS32U64_SPIKE(op1_32s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_32s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int32_t&uint64_t);
#else
		MUL_TEST_MAXS32U64(MAILBOX1,op1_32s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test max of int64_t and uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int64_t and uint8_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS64U8_SPIKE(op1_64s,op2_8u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_8u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint8_t);
#else
		MUL_TEST_MAXS64U8(MAILBOX1,op1_64s,op2_8u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test max of int64_t and uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int64_t and uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS64U16_SPIKE(op1_64s,op2_16u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_16u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint16_t);
#else
		MUL_TEST_MAXS64U16(MAILBOX1,op1_64s,op2_16u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test max of int64_t and uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int64_t and uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS64U32_SPIKE(op1_64s,op2_32u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_32u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint32_t);
#else
		MUL_TEST_MAXS64U32(MAILBOX1,op1_64s,op2_32u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


////////////////////////////////////////////////////////////////////////////////////////////
	/*********************************** Multiplication Test Min of uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINU64_SPIKE(op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_64u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t);
#else
		MUL_TEST_MINU64(MAILBOX1,op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	}

	k++;

	
	/*********************************** Multiplication Test Min of int64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS64_SPIKE(op1_64s,op2_64s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_64s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t);
#else
		MUL_TEST_MINS64(MAILBOX1,op1_64s,op2_64s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	}

	k++;


	/*********************************** Multiplication Test Min of int64_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int64_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINSU64_SPIKE(op1_64s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint64_t);
#else
		MUL_TEST_MINSU64(MAILBOX1,op1_64s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test Min of uint64_t and uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of uint64_t and uint8_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINU64U8_SPIKE(op1_64u,op2_8u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_8u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t&uint8_t);
#else
		MUL_TEST_MINU64U8(MAILBOX1,op1_64u,op2_8u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test min of uint64_t and uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of uint64_t and uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINU64U16_SPIKE(op1_64u,op2_16u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_16u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t&uint16_t);
#else
		MUL_TEST_MINU64U16(MAILBOX1,op1_64u,op2_16u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test min of uint64_t and uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of uint64_t and uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINU64U32_SPIKE(op1_64u,op2_32u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_32u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t&uint32_t);
#else
		MUL_TEST_MINU64U32(MAILBOX1,op1_64u,op2_32u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test min of int64_t and int8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int64_t and int8_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS64S8_SPIKE(op1_64s,op2_8s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_8s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&int8_t);
#else
		MUL_TEST_MINS64S8(MAILBOX1,op1_64s,op2_8s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test min of int64_t and int16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int64_t and int16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS64S16_SPIKE(op1_64s,op2_16s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_16s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&int16_t);
#else
		MUL_TEST_MINS64S16(MAILBOX1,op1_64s,op2_16s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test min of int64_t and int32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int64_t and int32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS64S32_SPIKE(op1_64s,op2_32s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_32s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&int32_t);
#else
		MUL_TEST_MINS64S32(MAILBOX1,op1_64s,op2_32s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test min of int8_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int8_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS8U64_SPIKE(op1_8s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_8s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int8_t&uint64_t);
#else
		MUL_TEST_MINS8U64(MAILBOX1,op1_8s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test min of int16_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int16_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS16U64_SPIKE(op1_16s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_16s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int16_t&uint64_t);
#else
		MUL_TEST_MINS16U64(MAILBOX1,op1_16s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test min of int32_t and uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int32_t and uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS32U64_SPIKE(op1_32s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_32s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int32_t&uint64_t);
#else
		MUL_TEST_MINS32U64(MAILBOX1,op1_32s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test min of int64_t and uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int64_t and uint8_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS64U8_SPIKE(op1_64s,op2_8u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_8u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint8_t);
#else
		MUL_TEST_MINS64U8(MAILBOX1,op1_64s,op2_8u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test min of int64_t and uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int64_t and uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS64U16_SPIKE(op1_64s,op2_16u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_16u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint16_t);
#else
		MUL_TEST_MINS64U16(MAILBOX1,op1_64s,op2_16u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;


	/*********************************** Multiplication Test min of int64_t and uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int64_t and uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2, actual result_lo, actual result_hi (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS64U32_SPIKE(op1_64s,op2_32u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_32u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint32_t);
#else
		MUL_TEST_MINS64U32(MAILBOX1,op1_64s,op2_32u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	} 

	k++;

	mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);

    
	return 0;
}


/* Random number generator for spike simulation */
int random_xor(void)
{
    static unsigned int random_state = 1234;
    unsigned int r = random_state;
    r ^= r << 13;
    r ^= r >> 17;
    r ^= r << 5;
    random_state = r;
    return (int)(r & INT_MAX);
}

