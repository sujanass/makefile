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
**
** Subtraction program for ZILLA. Subtracts var2 from var1 and prints the result
**
**
*/

#include <stdio.h>   		//!< Standard IO            //
#include <stdlib.h>
#include <stdint.h>             //!< Standarad Integer type //
#include "print.h"              //!< Mailbox print library  //
#include "linker.h"             //!< Linker symbols library //
#include "mailbox.h"            //!< Mailbox access library //
#include "testmacro.h"          //!< Test macros            //


#ifdef SPIKE_RUN
#include "data.h"               //!< Testbench created data //
#endif

// Note: TEST_COUNT indicates number of test for each tests. e.g. TEST_COUNT number of tests for uint8_t Subtraction, TEST_COUNT number of tests for int8_t Subtraction, etc

#define TEST_COUNT     (5)    //!< Test count             
#define DATA_SET        (3)     //!< op1, op2, result     
#define TEST_TYPES      (6)     //!< 8u,8s,16u,16s,32u,32s  
#define TEST_THREE     (150)	//TEST_THREE(is15)x2xTEST_COUNT 

// Array to store the operand1, operand2 and actual result 
uint64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};

// Main function //
int main(void)
{
	// test case status //
	volatile int testnumber   = 1;
	volatile int testtypenum  = 0;



   ////////////////////////////////////////// C Subtraction tests PART 1 ///////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> C Subtraction tests:\n");
	printf("\n------------------------------\n");
#endif

// Subtraction Test uint8_t /

// Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result for comparison //

	for(testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8_SPIKE_C(op1_8u,op2_8u,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_SUB_U(op1_8u,op2_8u,result_16s_tb,result_16s_full,testnumber,uint8_t);
#else
		SUB_TEST_U8_C(MAILBOX1,op1_8u,op2_8u,result_16s_full,testnumber);
#endif
	}



	// Subtraction Test int8_t 
#ifdef SPIKE_RUN
	printf("\nTest/> Subtraction Test int8_t  :\n");
#endif
	testtypenum++;
	
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S8_SPIKE_C(op1_8s,op2_8s,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8s,op2_8s,result_16s_tb,result_16s_full,testnumber,int8_t);
#else
		SUB_TEST_S8_C(MAILBOX1,op1_8s,op2_8s,result_16s_full,testnumber);
#endif
	}


	// Subtraction Test uint16_t 
#ifdef SPIKE_RUN
	printf("\nTest/> Subtraction Test uint16_t :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		SUB_TEST_U16_SPIKE_C(op1_16u,op2_16u,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_SUB_U(op1_16u,op2_16u,result_32s_tb,result_32s_full,testnumber,uint16_t);
#else
		SUB_TEST_U16_C(MAILBOX1,op1_16u,op2_16u,result_32s_full,testnumber);
#endif
	}


	// Subtraction Test int16_t 
	

#ifdef SPIKE_RUN
	printf("\nTest/> Subtraction Test int16_t  :\n");
#endif
	testtypenum++;
	
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		SUB_TEST_S16_SPIKE_C(op1_16s,op2_16s,result_32s_full,result_32s_tb,testnumber)
		PRINT_RESULT_SUB_S(op1_16s,op2_16s,result_32s_tb,result_32s_full,testnumber,int16_t);
#else
		SUB_TEST_S16_C(MAILBOX1,op1_16s,op2_16s,result_32s_full,testnumber);
#endif
	}



	// Subtraction Test uint32_t 


#ifdef SPIKE_RUN
	printf("\nTest/> Subtraction Test uint32_t :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U32_SPIKE_C(op1_32u,op2_32u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_U(op1_32u,op2_32u,result_64s_tb,result_64s_full,testnumber,uint32_t);
#else
		SUB_TEST_U32_C(MAILBOX1,op1_32u,op2_32u,result_64s_full, testnumber);
#endif
	}



	/// Subtraction Test int32_t //

#ifdef SPIKE_RUN
	printf("\nTest/> Subtraction Test int32_t  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S32_SPIKE_C(op1_32s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_32s,op2_32s,result_64s_tb,result_64s_full,testnumber,int32_t);
#else
		SUB_TEST_S32_C(MAILBOX1,op1_32s,op2_32s,result_64s_full,testnumber);
#endif
	}




     //Assembly Subtraction Test uint8_t PART2 //


#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test uint8_t  :\n");
#endif
	testtypenum++;
	
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S8_SPIKE(op1_8u,op2_8u,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_SUB_U(op1_8u,op2_8u,result_16s_tb,result_16s_full,testnumber,uint8_t);
#else
		SUB_TEST_S8(MAILBOX1,op1_8u,op2_8u,result_16s_full,testnumber);
#endif
	}

	// Subtraction Test int8_t //
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test int8_t  :\n");
#endif
	testtypenum++;
	
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S8_SPIKE(op1_8s,op2_8s,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8s,op2_8s,result_16s_tb,result_16s_full,testnumber,int8_t);
#else
		SUB_TEST_S8(MAILBOX1,op1_8s,op2_8s,result_16s_full,testnumber);
#endif
	}


     // Subtraction Test uint16_t 
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test uint16_t :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		SUB_TEST_U16_SPIKE(op1_16u,op2_16u,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_SUB_U(op1_16u,op2_16u,result_32s_tb,result_32s_full,testnumber,uint16_t);
#else
		SUB_TEST_U16(MAILBOX1,op1_16u,op2_16u,result_32s_full,testnumber);
#endif
	}


	// Subtraction Test int16_t 
	

#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test int16_t  :\n");
#endif
	testtypenum++;
	
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		SUB_TEST_S16_SPIKE(op1_16s,op2_16s,result_32s_full,result_32s_tb,testnumber)
		PRINT_RESULT_SUB_S(op1_16s,op2_16s,result_32s_tb,result_32s_full,testnumber,int16_t);
#else
		SUB_TEST_S16(MAILBOX1,op1_16s,op2_16s,result_32s_full,testnumber);
#endif
	}


	// Subtraction Test uint32_t 


#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test uint32_t :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U32_SPIKE(op1_32u,op2_32u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_U(op1_32u,op2_32u,result_64s_tb,result_64s_full,testnumber,uint32_t);
#else
		SUB_TEST_U32(MAILBOX1,op1_32u,op2_32u,result_64s_full, testnumber);
#endif
	}



	// Subtraction Test int32_t //

#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test int32_t  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S32_SPIKE(op1_32s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_32s,op2_32s,result_64s_tb,result_64s_full,testnumber,int32_t);
#else
		SUB_TEST_S32(MAILBOX1,op1_32s,op2_32s,result_64s_full,testnumber);
#endif
	}




 ////////////////////////////////////////// C Subtraction tests PART 3 ///////////////////////////////////////
//We will get all the random numbers needed as per the test count and store it into a array In LOOP then we will
//Process them into Add operation with cross data types uint8 * uint16 or similarly for singed and store in the
//necessary data type. 


#ifdef SPIKE_RUN
#else
	RAND_ARR_STORE_C(MAILBOX1);
#endif

    // Subtraction Test U8U16 //
#ifdef SPIKE_RUN
	printf("\nTest/> Subtraction Test U8U16  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8U16EC_SPIKE_C(op1_8u,op2_16u,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_SUB_U(op1_8u,op2_16u,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		SUB_TEST_U8U16EC_C(MAILBOX1,op1_8u,op2_16u,result_32s_full,testnumber);
#endif
	}

    // Subtraction Test U8U32 //
#ifdef SPIKE_RUN
	printf("\nTest/>  Subtraction Test U8U32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8U32EC_SPIKE_C(op1_8u,op2_32u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_U(op1_8u,op2_32u,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_U8U32EC_C(MAILBOX1,op1_8u,op2_32u,result_64s_full,testnumber);
#endif
	}


    // Subtraction Test U16U32 //
#ifdef SPIKE_RUN
	printf("\nTest/>  Subtraction Test U16U32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U16U32EC_SPIKE_C(op1_16u,op2_32u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_U(op1_16u,op2_32u,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_U16U32EC_C(MAILBOX1,op1_16u,op2_32u,result_64s_full,testnumber);
#endif
	}


    /// Subtraction Test S8S16 //
#ifdef SPIKE_RUN
	printf("\nTest/> Subtraction Test S8S16  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S8S16EC_SPIKE_C(op1_8s,op2_16s,result_32s_full,result_32s_tb,testnumber );
		PRINT_RESULT_SUB_S(op1_8s,op2_16s,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		SUB_TEST_S8S16EC_C(MAILBOX1,op1_8s,op2_16s,result_32s_full,testnumber);
#endif
	}

    /// Subtraction Test S8S32 //
#ifdef SPIKE_RUN
	printf("\nTest/>  Subtraction Test S8S32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S8S32EC_SPIKE_C(op1_8s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8s,op2_32s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S8S32EC_C(MAILBOX1,op1_8s,op2_32s,result_64s_full,testnumber);
#endif
	}


    /// Subtraction Test S16S32 //
#ifdef SPIKE_RUN
	printf("\nTest/>  Subtraction Test S16S32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S16S32EC_SPIKE_C(op1_16s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_16s,op2_32s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S16S32EC_C(MAILBOX1,op1_16s,op2_32s,result_64s_full,testnumber);
#endif
	}



 /// Subtraction Test U8S16 //
#ifdef SPIKE_RUN
	printf("\nTest/> Subtraction Test U8S16  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8S16EC_SPIKE_C(op1_8u,op2_16s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_SUB_SU(op1_8u,op2_16s,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		SUB_TEST_U8S16EC_C(MAILBOX1,op1_8u,op2_16s,result_32s_full,testnumber);
#endif
	}


    /// Subtraction Test S8U8 //
#ifdef SPIKE_RUN
	printf("\nTest/>  Subtraction Test S8U8  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S8U8EC_SPIKE_C(op1_8s,op2_8u,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_SUB_SU(op1_8s,op2_8u,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		SUB_TEST_S8U8EC_C(MAILBOX1,op1_8s,op2_8u,result_32s_full,testnumber);
#endif
	}


    /// Subtraction Test S16U16 //
#ifdef SPIKE_RUN
	printf("\nTest/>  Subtraction Test S16U16  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S16U16EC_SPIKE_C(op1_16s,op2_16u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_SU(op1_16s,op2_16u,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S16U16EC_C(MAILBOX1,op1_16s,op2_16u,result_64s_full,testnumber);
#endif
	}


 /// Subtraction Test S32U32 //
#ifdef SPIKE_RUN
	printf("\nTest/> Subtraction Test S32U32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S32U32EC_SPIKE_C(op1_32s,op2_32u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_SU(op1_32s,op2_32u,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S32U32EC_C(MAILBOX1,op1_32s,op2_32u,result_64s_full,testnumber);
#endif
	}


    /// Subtraction Test S8U16 //
#ifdef SPIKE_RUN
	printf("\nTest/>  Subtraction Test S8U16  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S8U16EC_SPIKE_C(op1_8s,op2_16u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_SU(op1_8s,op2_16u,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S8U16EC_C(MAILBOX1,op1_8s,op2_16u,result_64s_full,testnumber);
#endif
	}



    /// Subtraction Test S8U32 //
#ifdef SPIKE_RUN
	printf("\nTest/>  Subtraction Test S8U32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S8U32EC_SPIKE_C(op1_8s,op2_32u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_SU(op1_8s,op2_32u,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S8U32EC_C(MAILBOX1,op1_8s,op2_32u,result_64s_full,testnumber);
#endif
	}



 /// Subtraction Test S16U32 //
#ifdef SPIKE_RUN
	printf("\nTest/> Subtraction Test S16U32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S16U32EC_SPIKE_C(op1_16s,op2_32u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_SU(op1_16s,op2_32u,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S16U32EC_C(MAILBOX1,op1_16s,op2_32u,result_64s_full,testnumber);
#endif
	}



    /// Subtraction Test S8S32 //
#ifdef SPIKE_RUN
	printf("\nTest/>  Subtraction Test S8S32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S8S32EC_SPIKE_C(op1_8s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8s,op2_32s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S8S32EC_C(MAILBOX1,op1_8s,op2_32s,result_64s_full,testnumber);
#endif
	}


    /// Subtraction Test S16S32 //
#ifdef SPIKE_RUN
	printf("\nTest/>  Subtraction Test S16S32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U16S32EC_SPIKE_C(op1_16u,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_16u,op2_32s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_U16S32EC_C(MAILBOX1,op1_16u,op2_32s,result_64s_full,testnumber);
#endif
	}


 ////////////////////////////////////////// C Subtraction tests PART 4 ///////////////////////////////////////

    /// Assembly Subtraction Test U8U16 //
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test U8U16  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8U16_SPIKE(op1_8u,op2_16u,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_SUB_U(op1_8u,op2_16u,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		SUB_TEST_U8U16(MAILBOX1,op1_8u,op2_16u,result_32s_full,testnumber);
#endif
	}

    /// Assembly Subtraction Test U8U32 //
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test U8U32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8U32_SPIKE(op1_8u,op2_32u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_U(op1_8u,op2_32u,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_U8U32(MAILBOX1,op1_8u,op2_32u,result_64s_full,testnumber);
#endif
	}


    /// Assembly Subtraction Test U16U32 //
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test U16U32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U16U32_SPIKE(op1_16u,op2_32u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_U(op1_16u,op2_32u,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_U16U32(MAILBOX1,op1_16u,op2_32u,result_64s_full,testnumber);
#endif
	}

    /// Assembly Subtraction Test S8S16 //
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test S8S16  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S8S16_SPIKE(op1_8s,op2_16s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8s,op2_16s,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		SUB_TEST_S8S16(MAILBOX1,op1_8s,op2_16s,result_32s_full,testnumber);
#endif
	}

    /// Assembly Subtraction Test S8S32 //
#ifdef SPIKE_RUN

	printf("\nTest/> Assembly Subtraction Test S8S32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S8S32_SPIKE(op1_8s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8s,op2_32s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S8S32(MAILBOX1,op1_8s,op2_32s,result_64s_full,testnumber);
#endif
	}


    ///Assembly Subtraction Test S16S32 //
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test S16S32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S16S32_SPIKE(op1_16s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_16s,op2_32s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S16S32(MAILBOX1,op1_16s,op2_32s,result_64s_full,testnumber);
#endif
	}



 /// Assembly Subtraction Test U8S16 //
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test U8S16  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8S16_SPIKE(op1_8u,op2_16s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_SUB_SU(op1_8u,op2_16s,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		SUB_TEST_U8S16(MAILBOX1,op1_8u,op2_16s,result_32s_full,testnumber);
#endif
	}


    /// Assembly Subtraction Test S8U8 //
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test S8U8  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S8U8_SPIKE(op1_8s,op2_8u,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_SUB_SU(op1_8s,op2_8u,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		SUB_TEST_S8U8(MAILBOX1,op1_8s,op2_8u,result_32s_full,testnumber);
#endif
	}


    /// Assembly Subtraction Test S16U16 //
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test S16U16  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S16U16_SPIKE(op1_16s,op2_16u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_SU(op1_16s,op2_16u,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S16U16(MAILBOX1,op1_16s,op2_16u,result_64s_full,testnumber);
#endif
	}


 ///Assembly Subtraction Test S32U32 //
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test S32U32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S32U32_SPIKE(op1_32s,op2_32u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_SU(op1_32s,op2_32u,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S32U32(MAILBOX1,op1_32s,op2_32u,result_64s_full,testnumber);
#endif
	}


    /// Assembly Subtraction Test S8U16 //
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test S8U16  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S8U16_SPIKE(op1_8s,op2_16u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_SU(op1_8s,op2_16u,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S8U16(MAILBOX1,op1_8s,op2_16u,result_64s_full,testnumber);
#endif
	}



    /// Assembly Subtraction Test S8U32 //
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test S8U32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S8U32_SPIKE(op1_8s,op2_32u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_SU(op1_8s,op2_32u,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S8U32(MAILBOX1,op1_8s,op2_32u,result_64s_full,testnumber);
#endif
	}



 /// Assembly Subtraction Test S16U32 //
#ifdef SPIKE_RUN
	printf("\nTest/>Assembly Subtraction Test S16U32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S16U32_SPIKE(op1_16s,op2_32u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_SU(op1_16s,op2_32u,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S16U32(MAILBOX1,op1_16s,op2_64u,result_64s_full,testnumber);
#endif
	}

    /// Assembly Subtraction Test S8S32 //
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test S8S32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S8S32_SPIKE(op1_8s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8s,op2_32s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S8S32(MAILBOX1,op1_8s,op2_32s,result_64s_full,testnumber);
#endif
	}


    /// Assembly Subtraction Test U16S32 //
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Subtraction Test U16S32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U16S32_SPIKE(op1_16u,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_SU(op1_16u,op2_32s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_U16S32(MAILBOX1,op1_16u,op2_32s,result_64s_full,testnumber);
#endif
	}


////////////////////////////////////////// RISC Compliance Assembly subtraction Tests Part 5 //////////////////////////////////////


#ifdef SPIKE_RUN
	printf("\nTest/> Assembly subtraction tests:\n");
	printf("\n-------------------------------------\n");
#endif

#ifdef SPIKE_RUN
	printf("\nTest/> subtraction Test uint8_t for SRC1_EQ_DEST:\n");
#endif
// subtraction Test uint8_t TEST_RR_SRC1_EQ_DEST
	testtypenum++;
      
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8SRC1_EQ_DEST_SPIKE(op1_8u,op2_8u,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8u,op2_8u,result_16s_tb,result_16s_full,testnumber,uint8_t);
#else
		SUB_TEST_U8SRC1_EQ_DEST(MAILBOX1,op1_8u,op2_8u,result_16s_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> subtraction Test uint8_t for SRC2_EQ_DEST:\n");
#endif
// subtraction Test uint8_t TEST_RR_SRC2_EQ_DEST
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8SRC2_EQ_DEST_SPIKE(op1_8u,op2_8u,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8u,op2_8u,result_16s_tb,result_16s_full,testnumber,uint8_t);
#else
		SUB_TEST_U8SRC2_EQ_DEST(MAILBOX1,op1_8u,op2_8u,result_16s_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> subtraction Test uint8_t for SRC12_EQ_DEST:\n");
#endif



//subtraction Test uint8_t TEST_RR_SRC12_EQ_DEST
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8SRC12_EQ_DEST_SPIKE(op1_8u,op2_8u,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8u,op2_8u,result_16s_tb,result_16s_full,testnumber,uint8_t);
#else
		SUB_TEST_U8SRC12_EQ_DEST(MAILBOX1,op1_8u,op2_8u,result_16s_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> subtraction Test uint8_t for ZEROSRC1:\n");
#endif



// subtraction Test uint8_t TEST_RR_ZEROSRC1
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8ZEROSRC1_SPIKE(op1_8u,op2_8u,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8u,op2_8u,result_16s_tb,result_16s_full,testnumber,uint8_t);
#else
		SUB_TEST_U8ZEROSRC1(MAILBOX1,op1_8u,op2_8u,result_16s_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> subtraction Test uint8_t for ZEROSRC2:\n");
#endif



// subtraction Test uint8_t TEST_RR_ZEROSRC2
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8ZEROSRC2_SPIKE(op1_8u,op2_8u,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8u,op2_8u,result_16s_tb,result_16s_full,testnumber,uint8_t);
#else
		SUB_TEST_U8ZEROSRC2(MAILBOX1,op1_8u,op2_8u,result_16s_full,testnumber);
#endif
	}



#ifdef SPIKE_RUN
	printf("\nTest/> subtraction Test uint8_t for ZEROSRC12:\n");
#endif



// subtraction Test uint8_t TEST_RR_ZEROSRC12
	testtypenum++;


	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8ZEROSRC12_SPIKE(op1_8u,op2_8u,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8u,op2_8u,result_16s_tb,result_16s_full,testnumber,uint8_t);
#else
		SUB_TEST_U8ZEROSRC12(MAILBOX1,op1_8u,op2_8u,result_16s_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> subtraction Test uint8_t for ZERODEST:\n");
#endif



// subtraction Test uint8_t TEST_RR_ZERODEST**/
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8ZERODEST_SPIKE(op1_8u,op2_8u,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8u,op2_8u,result_16s_tb,result_16s_full,testnumber,uint8_t);
#else
		SUB_TEST_U8ZERODEST(MAILBOX1,op1_8u,op2_8u,result_16s_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> subtraction Test uint8_t for DEST_BYPASS:\n");
#endif



// subtraction Test uint8_t TEST_RR_DEST_BYPASS
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8DEST_BYPASS_SPIKE(op1_8u,op2_8u,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8u,op2_8u,result_16s_tb,result_16s_full,testnumber,uint8_t);
#else
		SUB_TEST_U8DEST_BYPASS(MAILBOX1,op1_8u,op2_8u,result_16s_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> subtraction Test uint8_t for SRC12_BYPASS:\n");
#endif



// subtraction Test uint8_t TEST_RR_SRC12_BYPASS**/
	testtypenum++;
  
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8SRC12_BYPASS_SPIKE(op1_8u,op2_8u,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8u,op2_8u,result_16s_tb,result_16s_full,testnumber,uint8_t);
#else
		SUB_TEST_U8SRC12_BYPASS(MAILBOX1,op1_8u,op2_8u,result_16s_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> subtraction Test uint8_t for SRC21_BYPASS:\n");
#endif



// subtraction Test uint8_t TEST_RR_SRC21_BYPASS**/
	testtypenum++;
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U8SRC21_BYPASS_SPIKE(op1_8u,op2_8u,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_8u,op2_8u,result_16s_tb,result_16s_full,testnumber,uint8_t);
#else
		SUB_TEST_U8SRC21_BYPASS(MAILBOX1,op1_8u,op2_8u,result_16s_full,testnumber);
#endif
	}


	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
	return 0;


}
