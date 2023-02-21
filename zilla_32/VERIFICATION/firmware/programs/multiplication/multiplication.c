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
#define TEST_COUNT     (3)    /*!< Test count             */
#define DATA_SET        (3)     /*!< op1, op2, result       */
#define TEST_TYPES      (6)     /*!< 8u,8s,16u,16s,32u,32s  */
#define TEST_THREE     (90)	//TEST_THREE(is15)x2xTEST_COUNT 
#define TEST_FOUR     (90)	//TEST_FOUR(is15)x2xTEST_COUNT

/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};

/* Main function */
int main(void)
{
	/* test case status */
	volatile int testnumber   = 1;
	volatile int testtypenum  = 0;

	int num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*3*12) + (TEST_COUNT*3*15) + (TEST_COUNT*3*15) + (TEST_COUNT*3*10) + (3*28);
	// num_of_elements_memdump = (test1 and 2)  + 	(test3)	 	+ 	(test4)	    + 	(test5) 	+ (test6);

////////////////////////////////////////// C Multiplication tests PART 1 ///////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> C multiplication tests:\n");
	printf("\n------------------------------\n");
#endif


	/*********************************** Multiplication Test uint8_t ********************************************/

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U8_SPIKE_C(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		MUL_TEST_U8_C(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
               
#endif
	}


	/*********************************** Multiplication Test int8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int8_t  :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S8_SPIKE_C(op1_8s,op2_8s,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_S(op1_8s,op2_8s,result_16s_tb,result_16s_full,testnumber,int8_t);
#else
                //z_printf("MULTI int8_t\n");
		MUL_TEST_S8_C(MAILBOX1,op1_8s,op2_8s,result_16s_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		MUL_TEST_U16_SPIKE_C(op1_16u,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_U(op1_16u,op2_16u,result_32u_tb,result_32u_full,testnumber,uint16_t);
#else
		MUL_TEST_U16_C(MAILBOX1,op1_16u,op2_16u,result_32u_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test int16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int16_t  :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		MUL_TEST_S16_SPIKE_C(op1_16s,op2_16s,result_32s_full,result_32s_tb,testnumber)
		PRINT_RESULT_S(op1_16s,op2_16s,result_32s_tb,result_32s_full,testnumber,int16_t);
#else
		MUL_TEST_S16_C(MAILBOX1,op1_16s,op2_16s,result_32s_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U32_SPIKE_C(op1_32u,op2_32u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_U(op1_32u,op2_32u,result_64u_tb,result_64u_full,testnumber,uint32_t);
#else
		MUL_TEST_U32_C(MAILBOX1,op1_32u,op2_32u,result_32u_full, testnumber);
#endif
	}


	/*********************************** Multiplication Test int32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int32_t  :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S32_SPIKE_C(op1_32s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_S(op1_32s,op2_32s,result_64s_tb,result_64s_full,testnumber,int32_t);
#else
		MUL_TEST_S32_C(MAILBOX1,op1_32s,op2_32s,result_64s_full,testnumber);
#endif
	}



////////////////////////////////////////// Assembly Multiplication Tests Part 2 //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Assembly multiplication tests:\n");
	printf("\n-------------------------------------\n");
#endif

	/*********************************** Multiplication Test uint8_t ********************************************/
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U8_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		MUL_TEST_U8(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test int8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int8_t  :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S8_SPIKE(op1_8s,op2_8s,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_S(op1_8s,op2_8s,result_16s_tb,result_16s_full,testnumber,int8_t);
#else
		MUL_TEST_S8(MAILBOX1,op1_8s,op2_8s,result_16s_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		MUL_TEST_U16_SPIKE(op1_16u,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_U(op1_16u,op2_16u,result_32u_tb,result_32u_full,testnumber,uint16_t);
#else
		MUL_TEST_U16(MAILBOX1,op1_16u,op2_16u,result_32u_full,testnumber);
#endif
	}



	/*********************************** Multiplication Test int16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int16_t  :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		MUL_TEST_S16_SPIKE(op1_16s,op2_16s,result_32s_full,result_32s_tb,testnumber)
		PRINT_RESULT_S(op1_16s,op2_16s,result_32s_tb,result_32s_full,testnumber,int16_t);
#else
		MUL_TEST_S16(MAILBOX1,op1_16s,op2_16s,result_32s_full,testnumber);
#endif
	}



	/*********************************** Multiplication Test uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U32_SPIKE(op1_32u,op2_32u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_U(op1_32u,op2_32u,result_64u_tb,result_64u_full,testnumber,uint32_t);
#else
		MUL_TEST_U32(MAILBOX1,op1_32u,op2_32u,result_64u_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test int32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int32_t  :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S32_SPIKE(op1_32s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_S(op1_32s,op2_32s,result_64s_tb,result_64s_full,testnumber,int32_t);
#else
		MUL_TEST_S32(MAILBOX1,op1_32s,op2_32s,result_64s_full,testnumber);
#endif
	}




////////////////////////////////////////// C Multiplication tests PART 3 ///////////////////////////////////////
//Get all the random numbers needed as per the test count and store it into a array In LOOP then we will
//Process them into Mul operation with cross data types uint8 * uint16 or similarly for singed and store in the
//necessary data type. 


#ifdef SPIKE_RUN
	printf("\nTest/> C multiplication tests:\n");
	printf("\n------------------------------\n");
#endif


#ifdef SPIKE_RUN
#else
	RAND_ARR_STORE_C(MAILBOX1);
#endif


	/*********************************** Multiplication Test uint8_t and uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint8_t and uint16_t:\n");
#endif
	testtypenum++;
	
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U816EC_SPIKE_C(op1_8u,op2_16u,result_32u_full,result_32u_tb,testnumber);	
		PRINT_RESULT_U(op1_8u,op2_16u,result_32u_tb,result_32u_full,testnumber,U8xU16);
#else     
		//print_str("hello _world");
		MUL_TEST_U816EC_C(MAILBOX1,op1_8u,op2_16u,result_32u_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint8_t and uint32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint8_t and uint32_t:\n");
#endif
	testtypenum++;
	
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U832_SPIKE_C(op1_8u,op2_32u,result_64u_full,result_64u_tb,testnumber);	
		PRINT_RESULT_U(op1_8u,op2_32u,result_64u_tb,result_64u_full,testnumber,U8xU32);
#else
		MUL_TEST_U832_C(MAILBOX1,op1_8u,op2_32u,result_64u_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint16_t and uint32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint16_t and uint32_t:\n");
#endif
	testtypenum++;
	
	 /*Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN			
		MUL_TEST_U1632_SPIKE_C(op1_16u,op2_32u,result_64u_full,result_64u_tb,testnumber);	
		PRINT_RESULT_U(op1_16u,op2_32u,result_64u_tb,result_64u_full,testnumber,U16xU32);
#else
		MUL_TEST_U1632_C(MAILBOX1,op1_16u,op2_32u,result_64u_full,testnumber);
#endif

}



	/*********************************** Multiplication Test int8_t and int16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int8_t and int16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison  */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S816_SPIKE_C(op1_8s,op2_16s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_S(op1_8s,op2_16s,result_32s_tb,result_32s_full,testnumber,S8xS16);
#else
		MUL_TEST_S816_C(MAILBOX1,op1_8s,op2_16s,result_32s_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test int8_t and int32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int8_t and int32_t :\n");
#endif
	testtypenum++;
	/*Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S832_SPIKE_C(op1_8s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_S(op1_8s,op2_32s,result_64s_tb,result_64s_full,testnumber,S8xS32);
#else
		MUL_TEST_S832_C(MAILBOX1,op1_8s,op2_32s,result_64s_full,testnumber);
#endif
	}



	/*********************************** Multiplication Test int16_t and int32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int16_t and int32_t :\n");
#endif
	testtypenum++;
	/*Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S1632_SPIKE_C(op1_16s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_S(op1_16s,op2_32s,result_64s_tb,result_64s_full,testnumber,S16S32);
#else
		MUL_TEST_S1632_C(MAILBOX1,op1_16s,op2_32s,result_64s_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test int8_t and uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int8_t and uint8_t :\n");
#endif
	testtypenum++;
	/*Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S8U8_SPIKE_C(op1_8s,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_SU(op1_8s,op2_8u,result_16u_tb,result_16u_full,testnumber,S8xU8);
#else
		MUL_TEST_S8U8_C(MAILBOX1,op1_8s,op2_8u,result_16u_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test int16_t and uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int16_t and uint16_t :\n");
#endif
	testtypenum++;
	/*Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S16U16_SPIKE_C(op1_16s,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_SU(op1_16s,op2_16u,result_32u_tb,result_32u_full,testnumber,S16xU16);
#else
		MUL_TEST_S16U16_C(MAILBOX1,op1_16s,op2_16u,result_32u_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test int32_t and uint32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int32_t and uint32_t :\n");
#endif
	testtypenum++;
	/*Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S32U32_SPIKE_C(op1_32s,op2_32u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_SU(op1_32s,op2_32u,result_64u_tb,result_64u_full,testnumber,S32xU32);
#else
		MUL_TEST_S32U32_C(MAILBOX1,op1_32s,op2_32u,result_64u_full,testnumber);
#endif
	}



	/*********************************** Multiplication Test int8_t and uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int8_t and uint16_t :\n");
#endif
	testtypenum++;
	/*Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S8U16_SPIKE_C(op1_8s,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_SU(op1_8s,op2_16u,result_32u_tb,result_32u_full,testnumber,S8xU16);
#else
		MUL_TEST_S8U16_C(MAILBOX1,op1_8s,op2_16u,result_32u_full,testnumber);
#endif
	}



	/*********************************** Multiplication Test int8_t and uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int8_t and uint32_t :\n");
#endif
	testtypenum++;
	/*Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S8U32_SPIKE_C(op1_8s,op2_32u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_SU(op1_8s,op2_32u,result_64u_tb,result_64u_full,testnumber,S8xU32);
#else
		MUL_TEST_S8U32_C(MAILBOX1,op1_8s,op2_32u,result_64u_full,testnumber);
#endif
	}



	/*********************************** Multiplication Test int16_t and uint32_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int16_t and uint32_t :\n");
#endif
	testtypenum++;
	/*Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S16U32_SPIKE_C(op1_16s,op2_32u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_SU(op1_16s,op2_32u,result_64u_tb,result_64u_full,testnumber,S16xU32);
#else
		MUL_TEST_S16U32_C(MAILBOX1,op1_16s,op2_32u,result_64u_full,testnumber);
#endif
	}




	/*********************************** Multiplication Test int16_t and uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int16_t and uint8_t :\n");
#endif
	testtypenum++;
	/*Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S16U8_SPIKE_C(op1_16s,op2_8u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_SU(op1_16s,op2_8u,result_32u_tb,result_32u_full,testnumber,S16xU8);
#else
		MUL_TEST_S16U8_C(MAILBOX1,op1_16s,op2_8u,result_32u_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test int32_t and uint8_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int32_t and uint8_t :\n");
#endif
	testtypenum++;
	/*Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S32U8_SPIKE_C(op1_32s,op2_8u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_SU(op1_32s,op2_8u,result_64u_tb,result_64u_full,testnumber,S32xU8);
#else
		MUL_TEST_S32U8_C(MAILBOX1,op1_32s,op2_8u,result_64u_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test int32_t and uint16_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int32_t and uint16_t :\n");
#endif
	testtypenum++;
	/*Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S32U16_SPIKE_C(op1_32s,op2_16u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_SU(op1_32s,op2_16u,result_64u_tb,result_64u_full,testnumber,S32xU16);
#else
		MUL_TEST_S32U16_C(MAILBOX1,op1_32s,op2_16u,result_64u_full,testnumber);
#endif
	}




////////////////////////////////////////// Assembly Multiplication Tests Part 4 //////////////////////////////////////
//Repeat the above with a new Assembly Macro called Custom Mul Assembly. 


#ifdef SPIKE_RUN
	printf("\nTest/> Assembly multiplication tests:\n");
	printf("\n------------------------------\n");
#endif


#ifdef SPIKE_RUN
#else
	RAND_ARR_STORE(MAILBOX1,testnumber,za,na);
#endif


	/*********************************** Multiplication Test uint8_t and uint16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint8_t and uint16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U816_SPIKE(op1_8u,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_16u,result_32u_tb,result_32u_full,testnumber,U8xU16);
#else
		MUL_TEST_U816(MAILBOX1,op1_8u,op2_16u,result_32u_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint8_t and uint32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint8_t and uint32_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U832_SPIKE(op1_8u,op2_32u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_32u,result_64u_tb,result_64u_full,testnumber,U8xU32);
#else
		MUL_TEST_U832(MAILBOX1,op1_8u,op2_32u,result_64u_full,testnumber);
#endif
	}


	/*********************************** Multiplication Test uint16_t and uint32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint16_t and uint32_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U1632_SPIKE(op1_16u,op2_32u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_U(op1_16u,op2_32u,result_64u_tb,result_64u_full,testnumber,U16xU32);
#else
		MUL_TEST_U1632(MAILBOX1,op1_16u,op2_32u,result_64u_full,testnumber);
#endif
	}


/*********************************** Multiplication Test int8_t and int16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int8_t and int16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S816_SPIKE(op1_8s,op2_16s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_S(op1_8s,op2_16s,result_32s_tb,result_32s_full,testnumber,S8xS16);
#else
		MUL_TEST_S816(MAILBOX1,op1_8s,op2_16s,result_32s_full,testnumber);
#endif
	}



/*********************************** Multiplication Test int8_t and int32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int8_t and int32_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S832_SPIKE(op1_8s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_S(op1_8s,op2_32s,result_64s_tb,result_64s_full,testnumber,U8xU32);
#else
		MUL_TEST_S832(MAILBOX1,op1_8s,op2_32s,result_64s_full,testnumber);
#endif
	}


/*********************************** Multiplication Test int16_t and int32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int16_t and int32_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S1632_SPIKE(op1_16s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_S(op1_16s,op2_32s,result_64s_tb,result_64s_full,testnumber,U16xU32);
#else
		MUL_TEST_S1632(MAILBOX1,op1_16s,op2_32s,result_64s_full,testnumber);
#endif
	}


/*********************************** Multiplication Test int8_t and uint8_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int8_t and uint8_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S8U8_SPIKE(op1_8s,op2_8u,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_SU(op1_8s,op2_8u,result_16s_tb,result_16s_full,testnumber,S8xU8);
#else
		MUL_TEST_S8U8(MAILBOX1,op1_8s,op2_8u,result_16s_full,testnumber);
#endif
	}


/*********************************** Multiplication Test int16_t and uint16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int16_t and uint16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S16U16_SPIKE(op1_16s,op2_16u,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_SU(op1_16s,op2_16u,result_32s_tb,result_32s_full,testnumber,S16xU16);
#else
		MUL_TEST_S16U16(MAILBOX1,op1_16s,op2_16u,result_32s_full,testnumber);
#endif
	}


/*********************************** Multiplication Test int32_t and uint32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int32_t and uint32_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S32U32_SPIKE(op1_32s,op2_32u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SU(op1_32s,op2_32u,result_64s_tb,result_64s_full,testnumber,S32xU32);
#else
		MUL_TEST_S32U32(MAILBOX1,op1_32s,op2_32u,result_64s_full,testnumber);
#endif
	}


/*********************************** Multiplication Test int8_t and uint16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int8_t and uint16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S8U16_SPIKE(op1_8s,op2_16u,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_SU(op1_8s,op2_16u,result_32s_tb,result_32s_full,testnumber,S8xU16);
#else
		MUL_TEST_S8U16(MAILBOX1,op1_8s,op2_16u,result_32s_full,testnumber);
#endif
	}


/*********************************** Multiplication Test int8_t and uint32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int8_t and uint32_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S8U32_SPIKE(op1_8s,op2_32u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SU(op1_8s,op2_32u,result_64s_tb,result_64s_full,testnumber,S8xU32);
#else
		MUL_TEST_S8U32(MAILBOX1,op1_8s,op2_32u,result_64s_full,testnumber);
#endif
	}


/*********************************** Multiplication Test int16_t and uint32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int16_t and uint32_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S16U32_SPIKE(op1_16s,op2_32u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SU(op1_16s,op2_32u,result_64s_tb,result_64s_full,testnumber,S16xU32);
#else
		MUL_TEST_S16U32(MAILBOX1,op1_16s,op2_32u,result_64s_full,testnumber);
#endif
	}


/*********************************** Multiplication Test int16_t and uint8_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int16_t and uint8_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S16U8_SPIKE(op1_16s,op2_8u,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_SU(op1_16s,op2_8u,result_32s_tb,result_32s_full,testnumber,S16xU8);
#else
		MUL_TEST_S16U8(MAILBOX1,op1_16s,op2_8u,result_32s_full,testnumber);
#endif
	}


/*********************************** Multiplication Test int32_t and uint8_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int32_t and uint8_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S32U8_SPIKE(op1_32s,op2_8u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SU(op1_32s,op2_8u,result_64s_tb,result_64s_full,testnumber,S32xU8);
#else
		MUL_TEST_S32U8(MAILBOX1,op1_32s,op2_8u,result_64s_full,testnumber);
#endif
	}


/*********************************** Multiplication Test int32_t and uint16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int32_t and uint16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S32U16_SPIKE(op1_32s,op2_16u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SU(op1_32s,op2_16u,result_64s_tb,result_64s_full,testnumber,S32xU16);
#else
		MUL_TEST_S32U16(MAILBOX1,op1_32s,op2_16u,result_64s_full,testnumber);
#endif
	}



////////////////////////////////////////// RISC Compliance Assembly Multiplication Tests Part 5 //////////////////////////////////////


#ifdef SPIKE_RUN
	printf("\nTest/> Assembly multiplication tests:\n");
	printf("\n-------------------------------------\n");
#endif


/*********************************** Multiplication Test uint8_t TEST_RR_SRC1_EQ_DEST********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint8_t for SRC1_EQ_DEST:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U8SRC1_EQ_DEST_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		MUL_TEST_U8SRC1_EQ_DEST(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


/*********************************** Multiplication Test uint8_t TEST_RR_SRC2_EQ_DEST********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint8_t for SRC2_EQ_DEST:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U8SRC2_EQ_DEST_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		MUL_TEST_U8SRC2_EQ_DEST(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


/*********************************** Multiplication Test uint8_t TEST_RR_SRC12_EQ_DEST********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint8_t for SRC12_EQ_DEST:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U8SRC12_EQ_DEST_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		MUL_TEST_U8SRC12_EQ_DEST(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


/*********************************** Multiplication Test uint8_t TEST_RR_ZEROSRC1********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint8_t for ZEROSRC1:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U8ZEROSRC1_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		MUL_TEST_U8ZEROSRC1(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


/*********************************** Multiplication Test uint8_t TEST_RR_ZEROSRC2********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint8_t for ZEROSRC2:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U8ZEROSRC2_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		MUL_TEST_U8ZEROSRC2(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


/*********************************** Multiplication Test uint8_t TEST_RR_ZEROSRC12********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint8_t for ZEROSRC12:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U8ZEROSRC12_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		MUL_TEST_U8ZEROSRC12(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


/*********************************** Multiplication Test uint8_t TEST_RR_ZERODEST********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint8_t for ZERODEST:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U8ZERODEST_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		MUL_TEST_U8ZERODEST(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


/*********************************** Multiplication Test uint8_t TEST_RR_DEST_BYPASS********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint8_t for DEST_BYPASS:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U8DEST_BYPASS_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		MUL_TEST_U8DEST_BYPASS(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


/*********************************** Multiplication Test uint8_t TEST_RR_SRC12_BYPASS********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint8_t for SRC12_BYPASS:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U8SRC12_BYPASS_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		MUL_TEST_U8SRC12_BYPASS(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


/*********************************** Multiplication Test uint8_t TEST_RR_SRC21_BYPASS********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint8_t for SRC21_BYPASS:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U8SRC21_BYPASS_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		MUL_TEST_U8SRC21_BYPASS(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}



////////////////////////////////////////// C Multiplication tests PART 6 ///////////////////////////////////////


	/*********************************** Multiplication Test Max of uint8_t and uint16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of uint8_t and uint16_t:\n");
#endif
	testtypenum++;
	int k = 1+testtypenum*TEST_COUNT;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXU816_SPIKE_C(op1_8u,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_16u,result_32u_tb,result_32u_full,testnumber,U8xU16);
#else
		MUL_TEST_MAXU816_C(MAILBOX1,op1_8u,op2_16u,result_32u_full,testnumber);
#endif
	}

	k++;


	/*********************************** Multiplication Test Max of int8_t and uint8_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int8_t and uint8_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS8U8_SPIKE_C(op1_8s,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_SU(op1_8s,op2_8u,result_16u_tb,result_16u_full,testnumber,S8xU8);
#else
		MUL_TEST_MAXS8U8_C(MAILBOX1,op1_8s,op2_8u,result_16u_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Max of int16_t and uint8_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int16_t and uint8_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS16U8_SPIKE_C(op1_16s,op2_8u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_SU(op1_16s,op2_8u,result_32u_tb,result_32u_full,testnumber,S16xU8);
#else
		MUL_TEST_MAXS16U8_C(MAILBOX1,op1_16s,op2_8u,result_32u_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Max of int8_t and uint16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int8_t and uint16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS8U16_SPIKE_C(op1_8s,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_SU(op1_8s,op2_16u,result_32u_tb,result_32u_full,testnumber,S8xU16);
#else
		MUL_TEST_MAXS8U16_C(MAILBOX1,op1_8s,op2_16u,result_32u_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Max of int16_t and uint16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int16_t and uint16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
		{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS16U16_SPIKE_C(op1_16s,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_SU(op1_16s,op2_16u,result_32u_tb,result_32u_full,testnumber,S16xU16);
#else
		MUL_TEST_MAXS16U16_C(MAILBOX1,op1_16s,op2_16u,result_32u_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Max of int8_t and int16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int8_t and int16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS816_SPIKE_C(op1_8s,op2_16s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_S(op1_8s,op2_16s,result_32s_tb,result_32s_full,testnumber,S8xS16);
#else
		MUL_TEST_MAXS816_C(MAILBOX1,op1_8s,op2_16s,result_32s_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Max of int8_t and int8_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int8_t and int8_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS88_SPIKE_C(op1_8s,op2_8s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_S(op1_8s,op2_8s,result_32s_tb,result_32s_full,testnumber,S8xS8);
#else
		MUL_TEST_MAXS88_C(MAILBOX1,op1_8s,op2_8s,result_32s_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Max of int16_t and int16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int16_t and int16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS1616_SPIKE_C(op1_16s,op2_16s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_S(op1_16s,op2_16s,result_32s_tb,result_32s_full,testnumber,S16xS16);
#else
		MUL_TEST_MAXS1616_C(MAILBOX1,op1_16s,op2_16s,result_32s_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Max of int32_t and int32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int32_t and int32_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS3232_SPIKE_C(op1_32s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_S(op1_32s,op2_32s,result_64s_tb,result_64s_full,testnumber,S32xS32);
#else
		MUL_TEST_MAXS3232_C(MAILBOX1,op1_32s,op2_32s,result_64s_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Max of uint8_t and uint8_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of uint8_t and uint8_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXU88_SPIKE_C(op1_8u,op2_8u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_8u,result_32u_tb,result_32u_full,testnumber,U8xU8);
#else
		MUL_TEST_MAXU88_C(MAILBOX1,op1_8u,op2_8u,result_32u_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Max of uint16_t and uint16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of uint16_t and uint16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXU1616_SPIKE_C(op1_16u,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_U(op1_16u,op2_16u,result_32u_tb,result_32u_full,testnumber,U16xU16);
#else
		MUL_TEST_MAXU1616_C(MAILBOX1,op1_16u,op2_16u,result_32u_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Max of uint32_t and uint32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of uint32_t and uint32_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXU3232_SPIKE_C(op1_32u,op2_32u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_U(op1_32u,op2_32u,result_64u_tb,result_64u_full,testnumber,U32xU32);
#else
		MUL_TEST_MAXU3232_C(MAILBOX1,op1_32u,op2_32u,result_64u_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Max of int8_t and int32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int8_t and int32_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS832_SPIKE_C(op1_8s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_S(op1_8s,op2_32s,result_64s_tb,result_64s_full,testnumber,S8xS32);
#else
		MUL_TEST_MAXS832_C(MAILBOX1,op1_8s,op2_32s,result_64s_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Max of int16_t and int32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int16_t and int32_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS1632_SPIKE_C(op1_16s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_S(op1_16s,op2_32s,result_64s_tb,result_64s_full,testnumber,S8xS32);
#else
		MUL_TEST_MAXS1632_C(MAILBOX1,op1_16s,op2_32s,result_64s_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Max of int8_t and int16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Max of int8_t and int16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MAXS816_SPIKE_C(op1_8s,op2_16s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_S(op1_8s,op2_16s,result_32s_tb,result_32s_full,testnumber,S8xS16);
#else
		MUL_TEST_MAXS816_C(MAILBOX1,op1_8s,op2_16s,result_32s_full,testnumber);
#endif
	}

	k++;


///////////////////////////////////////////////////////////////////////////////////////////
/*********************************** Multiplication Test Min of uint8_t and uint16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of uint8_t and uint16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MINU816_SPIKE_C(op1_8u,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_16u,result_32u_tb,result_32u_full,testnumber,U8xU16);
#else
		MUL_TEST_MINU816_C(MAILBOX1,op1_8u,op2_16u,result_32u_full,testnumber);
#endif
	}

	k++;


	/*********************************** Multiplication Test Min of int8_t and uint8_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int8_t and uint8_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS8U8_SPIKE_C(op1_8s,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_SU(op1_8s,op2_8u,result_16u_tb,result_16u_full,testnumber,S8xU8);
#else
		MUL_TEST_MINS8U8_C(MAILBOX1,op1_8s,op2_8u,result_16u_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Min of int16_t and uint8_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int16_t and uint8_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS16U8_SPIKE_C(op1_16s,op2_8u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_SU(op1_16s,op2_8u,result_32u_tb,result_32u_full,testnumber,S16xU8);
#else
		MUL_TEST_MINS16U8_C(MAILBOX1,op1_16s,op2_8u,result_32u_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Min of int8_t and uint16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int8_t and uint16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS8U16_SPIKE_C(op1_8s,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_SU(op1_8s,op2_16u,result_32u_tb,result_32u_full,testnumber,S8xU16);
#else
		MUL_TEST_MINS8U16_C(MAILBOX1,op1_8s,op2_16u,result_32u_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Min of int16_t and uint16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int16_t and uint16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
		{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS16U16_SPIKE_C(op1_16s,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_SU(op1_16s,op2_16u,result_32u_tb,result_32u_full,testnumber,S16xU16);
#else
		MUL_TEST_MINS16U16_C(MAILBOX1,op1_16s,op2_16u,result_32u_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Min of int8_t and int16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int8_t and int16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS816_SPIKE_C(op1_8s,op2_16s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_S(op1_8s,op2_16s,result_32s_tb,result_32s_full,testnumber,S8xS16);
#else
		MUL_TEST_MINS816_C(MAILBOX1,op1_8s,op2_16s,result_32s_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Min of uint8_t and uint8_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of uint8_t and uint8_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MINU88_SPIKE_C(op1_8u,op2_8u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_U(op1_8u,op2_8u,result_32u_tb,result_32u_full,testnumber,U8xU8);
#else
		MUL_TEST_MINU88_C(MAILBOX1,op1_8u,op2_8u,result_32u_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Min of uint16_t and uint16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of uint16_t and uint16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MINU1616_SPIKE_C(op1_16u,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_U(op1_16u,op2_16u,result_32u_tb,result_32u_full,testnumber,U16xU16);
#else
		MUL_TEST_MINU1616_C(MAILBOX1,op1_16u,op2_16u,result_32u_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Min of uint32_t and uint32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of uint32_t and uint32_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MINU3232_SPIKE_C(op1_32u,op2_32u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_U(op1_32u,op2_32u,result_64u_tb,result_64u_full,testnumber,U32xU32);
#else
		MUL_TEST_MINU3232_C(MAILBOX1,op1_32u,op2_32u,result_64u_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Min of int8_t and int8_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int8_t and int8_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS88_SPIKE_C(op1_8s,op2_8s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_S(op1_8s,op2_8s,result_32s_tb,result_32s_full,testnumber,S8xS8);
#else
		MUL_TEST_MINS88_C(MAILBOX1,op1_8s,op2_8s,result_32s_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Min of int16_t and int16_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int16_t and int16_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS1616_SPIKE_C(op1_16s,op2_16s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_S(op1_16s,op2_16s,result_32s_tb,result_32s_full,testnumber,S16xS16);
#else
		MUL_TEST_MINS1616_C(MAILBOX1,op1_16s,op2_16s,result_32s_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Min of int32_t and int32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int32_t and int32_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS3232_SPIKE_C(op1_32s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_S(op1_32s,op2_32s,result_64s_tb,result_64s_full,testnumber,S32xS32);
#else
		MUL_TEST_MINS3232_C(MAILBOX1,op1_32s,op2_32s,result_64s_full,testnumber);
#endif
	}


/*********************************** Multiplication Test Min of int8_t and int32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int8_t and int32_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS832_SPIKE_C(op1_8s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_S(op1_8s,op2_32s,result_64s_tb,result_64s_full,testnumber,S8xS32);
#else
		MUL_TEST_MINS832_C(MAILBOX1,op1_8s,op2_32s,result_64s_full,testnumber);
#endif
	}

	k++;


/*********************************** Multiplication Test Min of int16_t and int32_t ********************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test for Min of int16_t and int32_t:\n");
#endif
	testtypenum++;
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		MUL_TEST_MINS1632_SPIKE_C(op1_16s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_S(op1_16s,op2_32s,result_64s_tb,result_64s_full,testnumber,S16xS32);
#else
		MUL_TEST_MINS1632_C(MAILBOX1,op1_16s,op2_32s,result_64s_full,testnumber);
#endif
	}



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

