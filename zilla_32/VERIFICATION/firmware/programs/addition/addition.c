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
** Addition program for ZILLA. Adds 2 variables and prints the result
**
*******************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
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
   of tests for uint8_t Addition, TEST_COUNT number of tests for int8_t Addition, etc*/
#define TEST_COUNT     (5)    /*!< Test count             */
#define DATA_SET        (3)     /*!< op1, op2, result       */
#define TEST_TYPES      (6)     /*!< 8u,8s,16u,16s,32u,32s  */
#define TEST_THREE     (150)	//TEST_THREE(is12)x2xTEST_COUNT 


/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};
#include "ui_test.h"          /*!< Test macros            */

/* Main function */
int main(void)
{
	/* test case status */
	volatile int testnumber   = 14;
	volatile int testtypenum  = 0;

/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike siADDation generates the "Expected" result
                 for comparison */
	
////////////////////////////////////////// C Addition tests PART 1 ///////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> C addition Immediate tests:\n");
	printf("\n------------------------------\n");
#endif
test_ui_type();                 // Immediate test cases function call 15 tests hardcoded

	testtypenum++;
	testtypenum++;
	testtypenum++;

/////////////////////////////////////  Addition Test uint8_t      //////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> C addition tests:\n");
	printf("\n------------------------------\n");
#endif

//	for(testnumber = 1; testnumber <= TEST_COUNT; testnumber++)

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8_SPIKE_C(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		ADD_TEST_U8_C(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}

///////////////////////////////////// Addition Test int8_t//////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test int8_t  :\n");
#endif
	testtypenum++;
	
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S8_SPIKE_C(op1_8s,op2_8s,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_ADD_S(op1_8s,op2_8s,result_16s_tb,result_16s_full,testnumber,int8_t);
#else
		ADD_TEST_S8_C(MAILBOX1,op1_8s,op2_8s,result_16s_full,testnumber);
#endif
	}

///////////////////////////////////// Addition Test uint16_t //////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint16_t :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		ADD_TEST_U16_SPIKE_C(op1_16u,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_16u,op2_16u,result_32u_tb,result_32u_full,testnumber,uint16_t);
#else
		ADD_TEST_U16_C(MAILBOX1,op1_16u,op2_16u,result_32u_full,testnumber);
#endif
	}


/////////////////////////////////////Addition Test int16_t//////////////////////////////////////////////////////


#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test int16_t  :\n");
#endif
	testtypenum++;
	
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		ADD_TEST_S16_SPIKE_C(op1_16s,op2_16s,result_32s_full,result_32s_tb,testnumber)
		PRINT_RESULT_ADD_S(op1_16s,op2_16s,result_32s_tb,result_32s_full,testnumber,int16_t);
#else
		ADD_TEST_S16_C(MAILBOX1,op1_16s,op2_16s,result_32s_full,testnumber);
#endif
	}


/////////////////////////////////////Addition Test uint32_t   //////////////////////////////////////////////////////


#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint32_t :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U32_SPIKE_C(op1_32u,op2_32u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_32u,op2_32u,result_64u_tb,result_64u_full,testnumber,uint32_t);
#else
		ADD_TEST_U32_C(MAILBOX1,op1_32u,op2_32u,result_32u_full, testnumber);
#endif
	}


/////////////////////////////////////Addition Test int32_t  //////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test int32_t  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S32_SPIKE_C(op1_32s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_ADD_S(op1_32s,op2_32s,result_64s_tb,result_64s_full,testnumber,int32_t);
#else
		ADD_TEST_S32_C(MAILBOX1,op1_32s,op2_32s,result_64s_full,testnumber);
#endif
	}


////////////////////////////////////////// Assembly addition Tests Part 2 //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Assembly addition tests uint8t:\n");
	printf("\n-------------------------------------\n");
#endif

	////////////////////////////// addition Test uint8_t //////////////////////////////
	testtypenum++;
        

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		ADD_TEST_U8(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}



	////////////////////////////// addition Test int8_t //////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Assembly addition Test int8_t  :\n");
#endif
	testtypenum++;
	
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S8_SPIKE(op1_8s,op2_8s,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_ADD_S(op1_8s,op2_8s,result_16s_tb,result_16s_full,testnumber,int8_t);
#else
		ADD_TEST_S8(MAILBOX1,op1_8s,op2_8s,result_16s_full,testnumber);
#endif
	}


	////////////////////////////// addition Test uint16_t //////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test uint16_t :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		ADD_TEST_U16_SPIKE(op1_16u,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_16u,op2_16u,result_32u_tb,result_32u_full,testnumber,uint16_t);
#else
		ADD_TEST_U16(MAILBOX1,op1_16u,op2_16u,result_32u_full,testnumber);
#endif
	}



	////////////////////////////// addition Test int16_t ///////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test int16_t  :\n");
#endif
	testtypenum++;
	
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		ADD_TEST_S16_SPIKE(op1_16s,op2_16s,result_32s_full,result_32s_tb,testnumber)
		PRINT_RESULT_ADD_S(op1_16s,op2_16s,result_32s_tb,result_32s_full,testnumber,int16_t);
#else
		ADD_TEST_S16(MAILBOX1,op1_16s,op2_16s,result_32s_full,testnumber);
#endif
	}



	/////////////////////////////// addition Test uint32_t ///////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test uint32_t :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U32_SPIKE(op1_32u,op2_32u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_32u,op2_32u,result_64u_tb,result_64u_full,testnumber,uint32_t);
#else
		ADD_TEST_U32(MAILBOX1,op1_32u,op2_32u,result_64u_full,testnumber);
#endif
	}


	/////////////////////////////// addition Test int32_t ///////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test int32_t  :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S32_SPIKE(op1_32s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_ADD_S(op1_32s,op2_32s,result_64s_tb,result_64s_full,testnumber,int32_t);
#else
		ADD_TEST_S32(MAILBOX1,op1_32s,op2_32s,result_64s_full,testnumber);
#endif
	}



            ////////////////////////////// part 4////////////////////////////////////////////
/////////////////////////////////////addition Test U8U16  //////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test U8U16  :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8U16_SPIKE(op1_8u,op2_16u,result_32u_full,result_32u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_8u,op2_16u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		ADD_TEST_U8U16(MAILBOX1,op1_8u,op2_16u,result_32u_full,testnumber);
#endif
	}

///////////////////////////////// addition Test U8U32  /////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test U8U32  :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8U32_SPIKE(op1_8u,op2_32u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_8u,op2_32u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		ADD_TEST_U8U32(MAILBOX1,op1_8u,op2_16u,result_32u_full,testnumber);
#endif
	}


///////////////////////////////// addition Test U8S8  /////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test U8S8  :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8S8_SPIKE(op1_8u,op2_8s,result_16s_full,result_16s_tb,testnumber);
		PRINT_RESULT_ADD_S(op1_8u,op2_8s,result_16s_tb,result_16s_full,testnumber,int16_t);
#else
		ADD_TEST_U8S8(MAILBOX1,op1_8u,op2_8s,result_16s_full,testnumber);
#endif
	}

///////////////////////////////// addition Test U8S16  ////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test U8S16  :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8S16_SPIKE(op1_8u,op2_16s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_ADD_S(op1_8u,op2_16s,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		ADD_TEST_U8S16(MAILBOX1,op1_8u,op2_16s,result_32s_full,testnumber);
#endif
	}

///////////////////////////////// addition Test U8S32  //////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test U8S32  :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8S32_SPIKE(op1_8u,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_ADD_S(op1_8u,op2_32s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		ADD_TEST_U8S16(MAILBOX1,op1_8u,op2_32s,result_64s_full,testnumber);
#endif
	}

/////////////////////////////////////addition Test U16U32  //////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test U16U32  :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U16U32_SPIKE(op1_16u,op2_32u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_16u,op2_32u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		ADD_TEST_U16U32(MAILBOX1,op1_16u,op2_32u,result_64u_full,testnumber);
#endif
	}



///////////////////////////////// addition Test U16S8  ////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test U16S8  :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U16S8_SPIKE(op1_16u,op2_8s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_ADD_S(op1_16u,op2_8s,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		ADD_TEST_U16S8(MAILBOX1,op1_16u,op2_8s,result_32s_full,testnumber);
#endif
	}


///////////////////////////////// addition Test U16S16  /////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test U16S16  :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U16S16_SPIKE(op1_16u,op2_16s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_ADD_S(op1_16u,op2_16s,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		ADD_TEST_U16S16(MAILBOX1,op1_16u,op2_16s,result_32s_full,testnumber);
#endif
	}

///////////////////////////////// addition Test U16S32  ///////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test U16S32  :\n");
#endif
	testtypenum++;


	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U16S32_SPIKE(op1_16u,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_ADD_S(op1_16u,op2_32s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		ADD_TEST_U16S32(MAILBOX1,op1_16u,op2_32s,result_64s_full,testnumber);
#endif
	}

///////////////////////////////// addition Test U32S8  /////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test U32S8  :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U32S8_SPIKE(op1_32u,op2_8s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_ADD_SU(op1_32u,op2_8s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		ADD_TEST_U32S8(MAILBOX1,op1_32u,op2_8s,result_64s_full,testnumber);
#endif
	}

///////////////////////////////// addition Test U32S16  /////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test U32S16  :\n");
#endif
	testtypenum++;


	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U32S16_SPIKE(op1_32u,op2_16s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_ADD_SU(op1_32u,op2_16s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		ADD_TEST_U32S16(MAILBOX1,op1_32u,op2_16s,result_64s_full,testnumber);
#endif
	}

///////////////////////////////// addition Test U32S32  ////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test U32S32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U32S32_SPIKE(op1_32u,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_ADD_SU(op1_32u,op2_32s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		ADD_TEST_U32S32(MAILBOX1,op1_32u,op2_32s,result_64s_full,testnumber);
#endif
	}


///////////////////////////////// addition Test S8S16  ////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test S8S16  :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S8S16_SPIKE(op1_8s,op2_16s,result_32s_full,result_32s_tb,testnumber);
		PRINT_RESULT_ADD_S(op1_8s,op2_16s,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		ADD_TEST_S8S16(MAILBOX1,op1_8s,op2_16s,result_32s_full,testnumber);
#endif
	}


///////////////////////////////// addition Test S8S32  //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test S8S32  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S8S32_SPIKE(op1_8s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_ADD_S(op1_8s,op2_32s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		ADD_TEST_S8S32(MAILBOX1,op1_8s,op2_32s,result_64s_full,testnumber);
#endif
	}

///////////////////////////////// addition Test S16S32  ///////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>Assembly addition Test S16S32  :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S16S32_SPIKE(op1_16s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_ADD_S(op1_16s,op2_32s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		ADD_TEST_S16S32(MAILBOX1,op1_16s,op2_32s,result_64s_full,testnumber);
#endif
	}




                            ///////////// Part 3 ////////////////////


////////////////////////////////////////// C Addition tests PART 3 ////////////////////////////////////////////////
//We will get all the random numbers needed as per the test count and store it into a array In LOOP then we will
//Process them into Add operation with cross data types uint8 * uint16 or similarly for singed and store in the
//necessary data type. 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifdef SPIKE_RUN
#else
        //z_printf("RANDOM  vsdvvv ARRAY\n");
	RAND_ARR_STORE_C(MAILBOX1);
#endif

//////////////////////////// Addition Test uint8_t and uint16_t (u8u16 C )///////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint8_t and uint16_t:\n");
#endif

	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U816EC_SPIKE_C(op1_8u,op2_16u,result_32u_full,result_32u_tb,testnumber,z);	
		PRINT_RESULT_ADD_U(op1_8u,op2_16u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
               
		ADD_TEST_U816EC_C(MAILBOX1,op1_8u,op2_16u,result_32u_full,testnumber,z);


#endif
	}

//////////////////  Addition Test C code  uint8_t and int16_t: u8s16 c program ///////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test C code  uint8_t and int16_t:\n");
#endif

	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8S16EC_SPIKE_C(op1_8u,op2_16s,result_32s_full,result_32s_tb,testnumber,z);	
		PRINT_RESULT_ADD_S(op1_8u,op2_16s,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
               
		ADD_TEST_U8S16EC_C(MAILBOX1,op1_8u,op2_16s,result_32s_full,testnumber,z);


#endif
	}


////////////////////Addition Test C code  uint8_t and int32_t:u8s32 c program //////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test C code  uint8_t and int32_t:\n");
#endif

    testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8S32EC_SPIKE_C(op1_8u,op2_32s,result_64s_full,result_64s_tb,testnumber,z);	
		PRINT_RESULT_ADD_S(op1_8u,op2_32s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
               
		ADD_TEST_U8S32EC_C(MAILBOX1,op1_8u,op2_32s,result_64s_full,testnumber,z);

#endif
	}


/////////////////  Addition Test C code  uint16_t and int32_t: u16s32 c program //////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test C code  uint16_t and int32_t:\n");
#endif

	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U16S32EC_SPIKE_C(op1_16u,op2_32s,result_64s_full,result_64s_tb,testnumber,z);	
		PRINT_RESULT_ADD_S(op1_16u,op2_32s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
               
		ADD_TEST_U16S32EC_C(MAILBOX1,op1_16u,op2_32s,result_64s_full,testnumber,z);

#endif
	}


/////////////////  Addition Test uint8_t and uint32_t: u8u32 c program //////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint8_t and uint32_t:\n");
#endif

	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U832_SPIKE_C(op1_8u,op2_32u,result_64u_full,result_64u_tb,testnumber,z);	
		PRINT_RESULT_ADD_U(op1_8u,op2_32u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		ADD_TEST_U832_C(MAILBOX1,op1_8u,op2_32u,result_64u_full,testnumber,z);
#endif
	}


/////////////////   Addition Test uint16_t and uint32_t: u16u32 c program //////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint16_t and uint32_t:\n");
#endif

	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN			
		ADD_TEST_U1632_SPIKE_C(op1_16u,op2_32u,result_64u_full,result_64u_tb,testnumber,z);	
		PRINT_RESULT_ADD_U(op1_16u,op2_32u,result_64u_tb,result_64u_full,testnumber,uint16_32_t);
#else
		ADD_TEST_U1632_C(MAILBOX1,op1_16u,op2_32u,result_64u_full,testnumber,z);
#endif

}


/////////////////  Addition Test int8_t and int16_t s8s16 c program //////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test int8_t and int16_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S816_SPIKE_C(op1_8s,op2_16s,result_32s_full,result_32s_tb,testnumber,z);
		PRINT_RESULT_ADD_S(op1_8s,op2_16s,result_32s_tb,result_32s_full,testnumber,int8_t);
#else
		ADD_TEST_S816_C(MAILBOX1,op1_8s,op2_16s,result_32s_full,testnumber,z);
#endif
	}

///////////////////////////////////////Addition Test int832_t/////////////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test int8_t and int32_t :\n");
#endif
	testtypenum++;
	
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S832_SPIKE_C(op1_8s,op2_32s,result_64s_full,result_64s_tb,testnumber,z);
		PRINT_RESULT_ADD_S(op1_8s,op2_32s,result_64s_tb,result_64s_full,testnumber,int8_t);
#else
		ADD_TEST_S832_C(MAILBOX1,op1_8s,op2_32s,result_64s_full,testnumber,z);
#endif
	}



/////////////////////////////////////////Addition Test int1632_t ///////////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test int16_t and int32_t :\n");
#endif
	testtypenum++;
	
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S1632_SPIKE_C(op1_16s,op2_32s,result_64s_full,result_64s_tb,testnumber,t);
		PRINT_RESULT_ADD_S(op1_16s,op2_32s,result_64s_tb,result_64s_full,testnumber,int8_t);
#else
		ADD_TEST_S1632_C(MAILBOX1,op1_16s,op2_32s,result_64s_full,testnumber,t);
#endif
	}

///////////////////////////////////////// ADD Test s8u8_t  ///////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> ADD Test int8_t and uint8_t :\n");
#endif
	testtypenum++;
	
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S8U8_SPIKE_C(op1_8s,op2_8u,result_16u_full,result_16u_tb,testnumber,t);
		PRINT_RESULT_ADD_S(op1_8s,op2_8u,result_16u_tb,result_16u_full,testnumber,int8_t);
#else
		ADD_TEST_S8U8_C(MAILBOX1,op1_8s,op2_8u,result_16u_full,testnumber,t);
#endif
	}



/////////////////////////////////////////ADD Test s16u16_t///////////////////////////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> ADD Test int16_t and uint16_t :\n");
#endif
	testtypenum++;
	
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S16U16_SPIKE_C(op1_16s,op2_16u,result_32u_full,result_32u_tb,testnumber,t);
		PRINT_RESULT_ADD_S(op1_16s,op2_16u,result_32u_tb,result_32u_full,testnumber,int8_t);
#else
		ADD_TEST_S16U16_C(MAILBOX1,op1_16s,op2_16u,result_32u_full,testnumber,t);
#endif
	}



/////////////////////////////////////////ADD Test s32u32_t ///////////////////////////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> ADD Test int32_t and uint32_t :\n");
#endif
	testtypenum++;
	
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S32U32_SPIKE_C(op1_32s,op2_32u,result_64u_full,result_64u_tb,testnumber,t);
		PRINT_RESULT_ADD_S(op1_32s,op2_32u,result_64u_tb,result_64u_full,testnumber,int8_t);
#else
		ADD_TEST_S32U32_C(MAILBOX1,op1_32s,op2_32u,result_64u_full,testnumber,t);
#endif
	}




///////////////////////////////////////addition Test s8u16_t/////////////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> addition Test int8_t and uint16_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S8U16_SPIKE_C(op1_8s,op2_16u,result_32u_full,result_32u_tb,testnumber,t);
		PRINT_RESULT_ADD_S(op1_8s,op2_16u,result_32u_tb,result_32u_full,testnumber,int32_t);
#else
		ADD_TEST_S8U16_C(MAILBOX1,op1_8s,op2_16u,result_32u_full,testnumber,t);
#endif
	}


////////////////////////////////////////addition Test s8u32_t////////////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> addition Test int8_t and uint32_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S8U32_SPIKE_C(op1_8s,op2_32u,result_64u_full,result_64u_tb,testnumber,t);
		PRINT_RESULT_ADD_S(op1_8s,op2_32u,result_64u_tb,result_64u_full,testnumber,int64_t);
#else
		ADD_TEST_S8U32_C(MAILBOX1,op1_8s,op2_32u,result_64u_full,testnumber,t);
#endif
	}


/////////////////////////////////////addition Test s16u32_t///////////////////////////////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> addition Test int16_t and uint32_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S16U32_SPIKE_C(op1_16s,op2_32u,result_64u_full,result_64u_tb,testnumber,t);
		PRINT_RESULT_ADD_S(op1_16s,op2_32u,result_64u_tb,result_64u_full,testnumber,int64_t);
#else
		ADD_TEST_S16U32_C(MAILBOX1,op1_16s,op2_32u,result_64u_full,testnumber,t);
#endif
	}

/////////////////////////////////////////////////////////////////////////////////////////////////
////////////////              Compliance Test                                           /////////
/////////////////////////////////////////////////////////////////////////////////////////////////                          
///////////// RISC Compliance Assembly Addition Tests Part 5 ////////////////////////////////////


#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Addition tests:\n");
	printf("\n-------------------------------------\n");
#endif

#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint8_t for SRC1_EQ_DEST:\n");
#endif

/////////////////////////////////////////Addition Test uint8_t TEST_RR_SRC1_EQ_DEST ///////////////////////////////////////////////////

	testtypenum++;
      
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8SRC1_EQ_DEST_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		ADD_TEST_U8SRC1_EQ_DEST(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint8_t for SRC2_EQ_DEST:\n");
#endif


/////////////////////////////////////////Addition Test uint8_t TEST_RR_SRC2_EQ_DEST ///////////////////////////////////////////////////

	testtypenum++;
       

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8SRC2_EQ_DEST_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		ADD_TEST_U8SRC2_EQ_DEST(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint8_t for SRC12_EQ_DEST:\n");
#endif


///////////////////////////////////////// Addition Test uint8_t TEST_RR_SRC12_EQ_DEST ///////////////////////////////////////////////////

	testtypenum++;
    

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8SRC12_EQ_DEST_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		ADD_TEST_U8SRC12_EQ_DEST(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint8_t for ZEROSRC1:\n");
#endif


/////////////////////////////////////////Addition Test uint8_t TEST_RR_ZEROSRC1 ///////////////////////////////////////////////////

	testtypenum++;
      

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8ZEROSRC1_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		ADD_TEST_U8ZEROSRC1(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint8_t for ZEROSRC2:\n");
#endif

///////////////////////////////////////// Addition Test uint8_t TEST_RR_ZEROSRC2 ///////////////////////////////////////////////////

	testtypenum++;
       
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8ZEROSRC2_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		ADD_TEST_U8ZEROSRC2(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}



#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint8_t for ZEROSRC12:\n");
#endif


///////////////////////////////////////// Addition Test uint8_t TEST_RR_ZEROSRC12 ///////////////////////////////////////////////////

	testtypenum++;
       

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8ZEROSRC12_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		ADD_TEST_U8ZEROSRC12(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint8_t for ZERODEST:\n");
#endif


/////////////////////////////////////////Addition Test uint8_t TEST_RR_ZERODEST ///////////////////////////////////////////////////

	testtypenum++;
      

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8ZERODEST_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		ADD_TEST_U8ZERODEST(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint8_t for DEST_BYPASS:\n");
#endif


/////////////////////////////////////////Addition Test uint8_t TEST_RR_DEST_BYPASS ///////////////////////////////////////////////////

	testtypenum++;
      

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8DEST_BYPASS_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		ADD_TEST_U8DEST_BYPASS(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint8_t for SRC12_BYPASS:\n");
#endif



////////////////////////////////////////////// Addition Test uint8_t TEST_RR_SRC12_BYPAS //////////////////////////////////////////////

	testtypenum++;
        

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8SRC12_BYPASS_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		ADD_TEST_U8SRC12_BYPASS(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint8_t for SRC21_BYPASS:\n");
#endif



////////////////////////////// Addition Test uint8_t TEST_RR_SRC21_BYPASS //////////////////////////////////////////////
	testtypenum++;
        

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U8SRC21_BYPASS_SPIKE(op1_8u,op2_8u,result_16u_full,result_16u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_8u,op2_8u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		ADD_TEST_U8SRC21_BYPASS(MAILBOX1,op1_8u,op2_8u,result_16u_full,testnumber);
#endif
	}


	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
	return 0;


}
