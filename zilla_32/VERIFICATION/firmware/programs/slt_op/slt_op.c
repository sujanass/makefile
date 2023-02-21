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
** Set less than Test for ZILLA. 
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
   of tests for uint8_t SHIFT, TEST_COUNT number of tests for int8_t multiplication, etc*/
#define TEST_COUNT     (3)    /*!< Test count             */
#define DATA_SET        (3)     /*!< op1, op2, result       */
#define TEST_TYPES      (8)     /*!< 8u,8s,16u,16s,32u,32s,64u,64s */

// Minimum value of Unsigned numbers 
#define UINT8_MIN 0 
#define UINT16_MIN 0 
#define UINT32_MIN 0  
#define UINT64_MIN 0
    

 

/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};
#include "ui_slt_test.h" 

/* Main function */
int main(void)
{
    /* test case status */
	volatile int testnumber   = 1;
	volatile int testtypenum  = 0;

	int num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*3*12) + (TEST_COUNT*3*15) + (TEST_COUNT*3*15) + (TEST_COUNT*3*10) + (TEST_COUNT*30)  ;
	// num_of_elements_memdump = (test1 and 2)  + 	(test3)	 	+ 	(test4)	    + 	(test5) 	+ (test6)0;
    
    
///////////////////////////////////////////////////////////////////////////////
////////////////////////Set less than PART 1 ///////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> C Set less than tests:\n");
	printf("\n------------------------------\n");
#endif

////////////////////////  Set less than Test uint8_t ///////////////////////////////////////
       
	for(testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
	{
#ifdef SPIKE_RUN	
		SLTU_TEST_U8_SPIKE_C(op1_8u,op2_8u,result_8u_full,result_8u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_8u,op2_8u,result_8u_tb,result_8u_full,testnumber,uint8_t);
#else
		SLTU_TEST_U8_C(MAILBOX1,op1_8u,op2_8u,result_8u_full,testnumber);
               
#endif
	}

    
//////////////////////// Set less than Test int8_t ///////////////////////////////////////
  #ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test int8_t  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
     	SLT_TEST_S8_SPIKE_C(op1_8s,op2_8s,result_8s_full,result_8s_tb,testnumber);
		SLT_PRINT_RESULT_SS(op1_8s,op2_8s,result_8s_tb,result_8s_full,testnumber,int8_t);
		
#else         
		SLT_TEST_S8_C(MAILBOX1,op1_8s,op2_8s,result_8s_full,testnumber);
#endif

    }

    
////////////////////////// Set less than Test uint16_t     /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test uint16_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		SLTU_TEST_U16_SPIKE_C(op1_16u,op2_16u,result_16u_full,result_16u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_16u,op2_16u,result_16u_tb,result_16u_full,testnumber,uint16_t);
#else
		SLTU_TEST_U16_C(MAILBOX1,op1_16u,op2_16u,result_16u_full,testnumber);
#endif
	} 

/////////////////////////////// Set less than Test int16_t  ///////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest Set less than Test int16_t  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		SLT_TEST_S16_SPIKE_C(op1_16s,op2_16s,result_16s_full,result_16s_tb,testnumber)
		SLT_PRINT_RESULT_SS(op1_16s,op2_16s,result_16s_tb,result_16s_full,testnumber,int16_t);
#else
		SLT_TEST_S16_C(MAILBOX1,op1_16s,op2_16s,result_16s_full,testnumber);
#endif
	} 

//////////////////////////  Set less than Test uint32_t      /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test uint32_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SLTU_TEST_U32_SPIKE_C(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		SLTU_TEST_U32_C(MAILBOX1,op1_32u,op2_32u,result_32u_full, testnumber);
#endif
	} 

//////////////////////////  Set less than Test int32_t   /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test int32_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SLT_TEST_S32_SPIKE_C(op1_32s,op2_32s,result_32s_full,result_32s_tb,testnumber);
		SLT_PRINT_RESULT_SS(op1_32s,op2_32s,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		SLT_TEST_S32_C(MAILBOX1,op1_32s,op2_32s,result_32s_full,testnumber);
#endif
	}



//////////////////////////  Set less than Test uint64_t      /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test uint64_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SLTU_TEST_U64_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		SLTU_TEST_U64_C(MAILBOX1,op1_64u,op2_64u,result_64u_full, testnumber);
#endif
	} 

//////////////////////////  Set less than Test int64_t   /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test int64_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SLT_TEST_S64_SPIKE_C(op1_64s,op2_64s,result_64s_full,result_64s_tb,testnumber);
		SLT_PRINT_RESULT_SS(op1_64s,op2_64s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SLT_TEST_S64_C(MAILBOX1,op1_64s,op2_64s,result_64s_full,testnumber);
#endif
	}


////////////////////////////////////////// Assembly Set less than Tests Part 2 //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Set less than tests:\n");
	printf("\n-------------------------------------\n");
#endif

////////////////////////////////////////// Set less than Test uint8_t //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Set less than test uint8_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SLTU_TEST_U8_SPIKE(op1_8u,op2_8u,result_8u_full,result_8u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_8u,op2_8u,result_8u_tb,result_8u_full,testnumber,uint8_t);
#else
		SLTU_TEST_U8(MAILBOX1,op1_8u,op2_8u,result_8u_full,testnumber);
#endif
	} 

////////////////////////////////////////// Set less than Test int8_t  //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Set less than test int8_t  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SLT_TEST_S8_SPIKE(op1_8s,op2_8s,result_8s_full,result_8s_tb,testnumber);
		SLT_PRINT_RESULT_SS(op1_8s,op2_8s,result_8s_tb,result_8s_full,testnumber,int8_t);
#else
		SLT_TEST_S8(MAILBOX1,op1_8s,op2_8s,result_8s_full,testnumber);
#endif
	}

////////////////////////////////////////// Set less than Test uint16_t //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test uint16_t :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		SLTU_TEST_U16_SPIKE(op1_16u,op2_16u,result_16u_full,result_16u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_16u,op2_16u,result_16u_tb,result_16u_full,testnumber,uint16_t);
#else
		SLTU_TEST_U16(MAILBOX1,op1_16u,op2_16u,result_16u_full,testnumber);
#endif
	} 


///////////////////////////////////////// Set less than Test int16_t  //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test int16_t  :\n");
#endif
	testtypenum++;
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		SLT_TEST_S16_SPIKE(op1_16s,op2_16s,result_16s_full,result_16s_tb,testnumber)
		SLT_PRINT_RESULT_SS(op1_16s,op2_16s,result_16s_tb,result_16s_full,testnumber,int16_t);
#else
		SLT_TEST_S16(MAILBOX1,op1_16s,op2_16s,result_16s_full,testnumber);
#endif
	}


////////////////////////////////////////// Set less than Test uint32_t //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test uint32_t :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SLTU_TEST_U32_SPIKE(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		SLTU_TEST_U32(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
#endif
	}

////////////////////////////////////////// Set less than Test int32_t //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test int32_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SLT_TEST_S32_SPIKE(op1_32s,op2_32s,result_32s_full,result_32s_tb,testnumber);
		SLT_PRINT_RESULT_SS(op1_32s,op2_32s,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		SLT_TEST_S32(MAILBOX1,op1_32s,op2_32s,result_32s_full,testnumber);
#endif
	}





////////////////////////////////////////// Set less than Test uint64_t //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test uint64_t :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SLTU_TEST_U64_SPIKE(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		SLTU_TEST_U64(MAILBOX1,op1_64u,op2_64u,result_64u_full,testnumber);
#endif
	}

////////////////////////////////////////// Set less than Test int64_t //////////////////////////////////////
 
#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test int64_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SLT_TEST_S64_SPIKE(op1_64s,op2_64s,result_64s_full,result_64s_tb,testnumber);
		SLT_PRINT_RESULT_SS(op1_64s,op2_64s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SLT_TEST_S64(MAILBOX1,op1_64s,op2_64s,result_64s_full,testnumber);
#endif
	}




///////////////////////////////////////// RISC Compliance Assembly Set less than Tests Part 5 //////////////////////////////////////


#ifdef SPIKE_RUN
   printf("\nTest/> RISC Compliance Assembly Set less than tests:\n");
   printf("\n-------------------------------------\n");
#endif


/*********************************** Set less than Test uint8_t TEST_RR_SRC1_EQ_DEST********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test uint8_t for SRC1_EQ_DEST:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLTU_TEST_U8SRC1_EQ_DEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLTU_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SLTU_TEST_U8SRC1_EQ_DEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   } 
 /*********************************** Set less than Test uint8_t TEST_RR_SRC2_EQ_DEST********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test uint8_t for SRC2_EQ_DEST:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

  for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLTU_TEST_U8SRC2_EQ_DEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLTU_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SLTU_TEST_U8SRC2_EQ_DEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }

/*********************************** Set less than Test uint8_t TEST_RR_SRC12_EQ_DEST****************************************/

#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test uint8_t for SRC12_EQ_DEST:\n");
#endif
   testtypenum++; 
        /*Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */
   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLTU_TEST_U8SRC12_EQ_DEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLTU_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SLTU_TEST_U8SRC12_EQ_DEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   } 
/*********************************** Set less than Test uint8_t TEST_RR_ZEROSRC1********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test uint8_t for ZEROSRC1:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLTU_TEST_U8ZEROSRC1_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLTU_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SLTU_TEST_U8ZEROSRC1(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }

/*********************************** Set less than Test uint8_t TEST_RR_ZEROSRC2********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test uint8_t for ZEROSRC2:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siSLTUation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLTU_TEST_U8ZEROSRC2_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLTU_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SLTU_TEST_U8ZEROSRC2(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }
/*********************************** Set less than Test uint8_t TEST_RR_ZEROSRC12********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test uint8_t for ZEROSRC12:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

  for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLTU_TEST_U8ZEROSRC12_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLTU_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SLTU_TEST_U8ZEROSRC12(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }

/*********************************** Set less than Test uint8_t TEST_RR_ZERODEST********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test uint8_t for ZERODEST:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLTU_TEST_U8ZERODEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLTU_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SLTU_TEST_U8ZERODEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }


/*********************************** Set less than Test uint8_t TEST_RR_DEST_BYPASS********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test uint8_t for DEST_BYPASS:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLTU_TEST_U8DEST_BYPASS_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLTU_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SLTU_TEST_U8DEST_BYPASS(MAILBOX1,op1,op2,result_full,testnumber);
#endif	
   }


/*********************************** Set less than Test uint8_t TEST_RR_SRC12_BYPASS********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test uint8_t for SRC12_BYPASS:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLTU_TEST_U8SRC12_BYPASS_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLTU_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SLTU_TEST_U8SRC12_BYPASS(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }


/*********************************** Set less than Test uint8_t TEST_RR_SRC21_BYPASS********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test uint8_t for SRC21_BYPASS:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

  for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLTU_TEST_U8SRC21_BYPASS_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLTU_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	SLTU_TEST_U8SRC21_BYPASS(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   } 


///////////////////////////////////////////PART 4//////////////////////////////////////////
////////////////COMPLIANCE TEST SLT/////////////////////////////////////////
   

/*********************************** Set less than Test int32_t TEST_RR_SRC1_EQ_DEST********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test int32_t for SRC1_EQ_DEST:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLT_TEST_S32SRC1_EQ_DEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLT_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int32_t);
#else
   	SLT_TEST_S32SRC1_EQ_DEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }



/*********************************** Set less than Test int32_t TEST_RR_SRC2_EQ_DEST********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test int32_t for SRC2_EQ_DEST:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLT_TEST_S32SRC2_EQ_DEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLT_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int32_t);
#else
   	SLT_TEST_S32SRC2_EQ_DEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }


   
/*********************************** Set less than Test int32_t TEST_RR_ZEROSRC1********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test int32_t for ZEROSRC1:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLT_TEST_S32ZEROSRC1_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLT_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int32_t);
#else
   	SLT_TEST_S32ZEROSRC1(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }



/*********************************** Set less than Test int32_t TEST_RR_SRC12_EQ_DEST********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test int32_t for SRC12_EQ_DEST:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLT_TEST_S32SRC12_EQ_DEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLT_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int32_t);
#else
   	SLT_TEST_S32SRC12_EQ_DEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif 
   }

/*********************************** Set less than Test int32_t TEST_RR_ZEROSRC2********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test int32_t for ZEROSRC2:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLT_TEST_S32ZEROSRC2_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLT_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int32_t);
#else
   	SLT_TEST_S32ZEROSRC2(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }

/*********************************** Set less than Test int32_t TEST_RR_ZEROSRC12********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test int32_t for ZEROSRC12:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLT_TEST_S32ZEROSRC12_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLT_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int32_t);
#else
   	SLT_TEST_S32ZEROSRC12(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }

/*********************************** Set less than Test int32_t TEST_RR_ZERODEST********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test int32_t for ZERODEST:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLT_TEST_S32ZERODEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLT_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int32_t);
#else
   	SLT_TEST_S32ZERODEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }


/*********************************** Set less than Test int32_t TEST_RR_DEST_BYPASS********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test int32_t for DEST_BYPASS:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLT_TEST_S32DEST_BYPASS_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLT_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int32_t);
#else
   	SLT_TEST_S32DEST_BYPASS(MAILBOX1,op1,op2,result_full,testnumber);
#endif	
   }


/*********************************** Set less than Test int32_t TEST_RR_SRC12_BYPASS********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test int32_t for SRC12_BYPASS:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLT_TEST_S32SRC12_BYPASS_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLT_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int32_t);
#else
   	SLT_TEST_S32SRC12_BYPASS(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }


/*********************************** Set less than Test int32_t TEST_RR_SRC21_BYPASS********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Set less than Test int32_t for SRC21_BYPASS:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siSLTation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	SLT_TEST_S32SRC21_BYPASS_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	SLT_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int32_t);
#else
   	SLT_TEST_S32SRC21_BYPASS(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }

 /////////////////////////////////////////////////////////////PART 5//////////////////////////////////////////////////////////////
 ///////////////////////////////////////////MIN AND MAX TEST CASES////////////////////////////////////////////////////////////////
             

#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for Max of int8_t :\n");
#endif
	testtypenum++;
    int k = 1+testtypenum*TEST_COUNT;	
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLT_TEST_MAXS88_SPIKE_C(op1_8s,op2_8s,result_8s_full,result_8s_tb,testnumber);
		SLT_PRINT_RESULT_SS(op1_8s,op2_8s,result_8s_tb,result_8s_full,testnumber,int8_t);
#else
		SLT_TEST_MAXS88_C(MAILBOX1,op1_8s,op2_8s,result_8s_full,testnumber);
#endif
	}
	k++;




#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for Max of int16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLT_TEST_MAXS1616_SPIKE_C(op1_16s,op2_16s,result_16s_full,result_16s_tb,testnumber);
		SLT_PRINT_RESULT_SS(op1_16s,op2_16s,result_16s_tb,result_16s_full,testnumber,int16_t);
#else
		SLT_TEST_MAXS1616_C(MAILBOX1,op1_16s,op2_16s,result_16s_full,testnumber);
#endif
	}
	k++;


#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for Max of int32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLT_TEST_MAXS3232_SPIKE_C(op1_32s,op2_32s,result_32s_full,result_32s_tb,testnumber);
		SLT_PRINT_RESULT_SS(op1_32s,op2_32s,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		SLT_TEST_MAXS3232_C(MAILBOX1,op1_32s,op2_32s,result_32s_full,testnumber);
#endif
	}
	k++;



#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for MAX of int64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLT_TEST_MAXS6464_SPIKE_C(op1_64s,op2_64s,result_64s_full,result_64s_tb,testnumber);
		SLT_PRINT_RESULT_SS(op1_64s,op2_64s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SLT_TEST_MAXS6464_C(MAILBOX1,op1_64s,op2_64s,result_64s_full,testnumber);
#endif
	}
	k++;



#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for Max of uint8_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLTU_TEST_MAXU88_SPIKE_C(op1_8u,op2_8u,result_8u_full,result_8u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_8u,op2_8u,result_8u_tb,result_8u_full,testnumber,uint8_t);
#else
		SLTU_TEST_MAXU88_C(MAILBOX1,op1_8u,op2_8u,result_8u_full,testnumber);
#endif
	}
	k++;




#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for Max of uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLTU_TEST_MAXU1616_SPIKE_C(op1_16u,op2_16u,result_16u_full,result_16u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_16u,op2_16u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		SLTU_TEST_MAXU1616_C(MAILBOX1,op1_16u,op2_16u,result_16u_full,testnumber);
#endif
	}
	k++;


#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for Max of uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLTU_TEST_MAXU3232_SPIKE_C(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		SLTU_TEST_MAXU3232_C(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
#endif
	}
	k++;


#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for MAX of uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLTU_TEST_MAXU6464_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		SLTU_TEST_MAXU6464_C(MAILBOX1,op1_64u,op2_64u,result_64u_full,testnumber);
#endif
	}
	k++;


#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for MAX of uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLTU_TEST_MAXU6464_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		SLTU_TEST_MAXU6464_C(MAILBOX1,op1_64u,op2_64u,result_64u_full,testnumber);
#endif
	}
	k++;




#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for MIN of int8_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLT_TEST_MINS88_SPIKE_C(op1_8s,op2_8s,result_8s_full,result_8s_tb,testnumber);
		SLT_PRINT_RESULT_SS(op1_8s,op2_8s,result_8s_tb,result_8s_full,testnumber,int8_t);
#else
		SLT_TEST_MINS88_C(MAILBOX1,op1_8s,op2_8s,result_8s_full,testnumber);
#endif
	}
	k++;




#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for MIN of int16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLT_TEST_MINS1616_SPIKE_C(op1_16s,op2_16s,result_16s_full,result_16s_tb,testnumber);
		SLT_PRINT_RESULT_SS(op1_16s,op2_16s,result_16s_tb,result_16s_full,testnumber,int16_t);
#else
		SLT_TEST_MINS1616_C(MAILBOX1,op1_16s,op2_16s,result_16s_full,testnumber);
#endif
	}
	k++;


#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for MIN of int32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLT_TEST_MINS3232_SPIKE_C(op1_32s,op2_32s,result_32s_full,result_32s_tb,testnumber);
		SLT_PRINT_RESULT_SS(op1_32s,op2_32s,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		SLT_TEST_MINS3232_C(MAILBOX1,op1_32s,op2_32s,result_32s_full,testnumber);
#endif
	}
	k++;

 
#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for MIN of int64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLT_TEST_MINS6464_SPIKE_C(op1_64s,op2_64s,result_64s_full,result_64s_tb,testnumber);
		SLT_PRINT_RESULT_SS(op1_64s,op2_64s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SLT_TEST_MINS6464_C(MAILBOX1,op1_64s,op2_64s,result_64s_full,testnumber);
#endif
	}
	k++;




#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for MIN of uint8_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLTU_TEST_MINU88_SPIKE_C(op1_8u,op2_8u,result_8u_full,result_8u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_8u,op2_8u,result_8u_tb,result_8u_full,testnumber,uint8_t);
#else
		SLTU_TEST_MINU88_C(MAILBOX1,op1_8u,op2_8u,result_8u_full,testnumber);
#endif
	}
	k++;




#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for MIN of uint16_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLTU_TEST_MINU1616_SPIKE_C(op1_16u,op2_16u,result_16u_full,result_16u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_16u,op2_16u,result_16u_tb,result_16u_full,testnumber,uint8_t);
#else
		SLTU_TEST_MINU1616_C(MAILBOX1,op1_16u,op2_16u,result_16u_full,testnumber);
#endif
	}
	k++;


#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for MIN of uint32_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLTU_TEST_MINU3232_SPIKE_C(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		SLTU_TEST_MINU3232_C(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
#endif
	}
	k++;



#ifdef SPIKE_RUN
	printf("\nTest/> Set less than Test for MIN of uint64_t :\n");
#endif
	testtypenum++;
	/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
	{
#ifdef SPIKE_RUN		
		SLTU_TEST_MINU6464_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		SLTU_PRINT_RESULT_UU(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		SLTU_TEST_MINU6464_C(MAILBOX1,op1_64u,op2_64u,result_64u_full,testnumber);
#endif
	}
	k++;

testtypenum++;

////////////////////////////////////////////SET LESS THAN IMMEDIATE TYPE/////////////////////////////////////////


//////////////////////////////////////SLTIU uint8_t///////////////////////////////////////////////
#ifdef SPIKE_RUN
    printf("\n  \n");
	printf("\nTest/> SLTIU uint8_t bit Test   :\n");
#endif

test_sltiu_u8_ui_type(k);
k= k + TEST_COUNT ;


//////////////////////////////////////SLTIU uint16_t///////////////////////////////////////////////
#ifdef SPIKE_RUN
    printf("\n  \n");
	printf("\nTest/> SLTIU uint16_t bit Test   :\n");
#endif

test_sltiu_u16_ui_type(k);
k= k + TEST_COUNT ;



//////////////////////////////////////SLTIU uint32_t///////////////////////////////////////////////
#ifdef SPIKE_RUN
    printf("\n  \n");
	printf("\nTest/> SLTIU uint32_t bit Test   :\n");
#endif

test_sltiu_u32_ui_type(k);
k= k + TEST_COUNT ;



//////////////////////////////////////SLTIU uint64_t///////////////////////////////////////////////
#ifdef SPIKE_RUN
    printf("\n  \n");
	printf("\nTest/> SLTIU uint64_t bit Test   :\n");
#endif

test_sltiu_u64_ui_type(k);
k= k + TEST_COUNT ;




/////////////////////////////////////SLTI int8_t////////////////////////////////////////

#ifdef SPIKE_RUN
    printf("\n \n \n");
	printf("\nTest/> SLTI int8_bit Test   :\n");
#endif

test_slti_s8_ui_type(k);
k= k + TEST_COUNT ;



/////////////////////////////////////SLTI int16_t////////////////////////////////////////

#ifdef SPIKE_RUN
    printf("\n \n \n");
	printf("\nTest/> SLTI int16_bit Test   :\n");
#endif

test_slti_s16_ui_type(k);
k= k + TEST_COUNT ;




/////////////////////////////////////SLTI int32_t////////////////////////////////////////

#ifdef SPIKE_RUN
    printf("\n \n \n");
	printf("\nTest/> SLTI int32_bit Test   :\n");
#endif

test_slti_s32_ui_type(k);
k= k + TEST_COUNT ;




/////////////////////////////////////SLTI int64_t////////////////////////////////////////

#ifdef SPIKE_RUN
    printf("\n \n \n");
	printf("\nTest/> SLTI int64_bit Test   :\n");
#endif

test_slti_s64_ui_type(k);
k= k + TEST_COUNT ;





    mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2, num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
    
    return 0;
}



