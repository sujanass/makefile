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
** Division program for ZILLA. Devides and prints the result
** Note: For Devide By zero: quotient = all bit set , remainder = dividend
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
#define TEST_COUNT        (3)    /*!< Test count             */
#define DATA_SET          (3)     /*!< op1, op2, result       */
#define TEST_TYPES        (8)     /*!< 8u,8s,16u,16s,32u,32s  */
#define TEST_THREE_COUNT  (90)	//TEST_THREE(is15)x2xTEST_COUNT 
#define TEST_FOUR         (90)	//TEST_FOUR(is15)x2xTEST_COUNT

// Minimum value of Unsigned numbers 
#define UINT8_MIN 0 
#define UINT16_MIN 0 
#define UINT32_MIN 0 
#define UINT64_MIN 0 

/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};

/* Main function */
int main(void)
{
	/* test case status */
	volatile int testnumber   = 1;
	volatile int testtypenum  = 0;

	int num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*3*2*TEST_TYPES) + (TEST_COUNT*3*15) + (TEST_COUNT*3*15) + (TEST_COUNT*3*10) + (TEST_COUNT*30) + 3  ;
	// num_of_elements_memdump = (test1 and 2)  + 	(test3)	 	+ 	(test4)	    + 	(test5) 	+ (test6)             + overlfow ;
    
    
///////////////////////////////////////////////////////////////////////////////
////////////////////////Division PART 1 ///////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> C Division tests:\n");
	printf("\n------------------------------\n");
#endif

////////////////////////  Division Test uint8_t ///////////////////////////////////////
       
	for(testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_U8_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
		DIV_TEST_U8_C(MAILBOX1,op1,op2,result_full,testnumber);
               
#endif
	}

//////////////////////////  Division Test int8_t       /////////////////////////////////////
	
#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int8_t  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S8_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int8_t);
		
#else         
		DIV_TEST_S8_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}

//////////////////////////   Division Test uint16_t     /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test uint16_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		DIV_TEST_U16_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint16_t);
#else
		DIV_TEST_U16_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}


//////////////////////////   Division Test int16_t     /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int16_t  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		DIV_TEST_S16_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int16_t);
#else
		DIV_TEST_S16_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}


//////////////////////////  Division Test uint32_t      /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test uint32_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_U32_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint32_t);
#else
		DIV_TEST_U32_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}

//////////////////////////  Division Test int32_t   /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int32_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S32_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int32_t);
#else
		DIV_TEST_S32_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}

//////////////////////////  Division Test uint64_t      /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test uint64_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_U64_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		DIV_PRINT_RESULT_UU64(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		DIV_TEST_U64_C(MAILBOX1,op1_64u,op2_64u,result_64u_full, testnumber);
#endif
	}

//////////////////////////  Division Test int64_t   /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int64_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S64_SPIKE_C(op1_64s,op2_64s,result_64s_full,result_64s_tb,testnumber);
		DIV_PRINT_RESULT_SS64(op1_64s,op2_64s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		DIV_TEST_S64_C(MAILBOX1,op1_64s,op2_64s,result_64s_full,testnumber);
#endif
	}

////////////////////////////////////////// Assembly Division Tests Part 2 //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Assembly Division tests:\n");
	printf("\n-------------------------------------\n");
#endif

////////////////////////////////////////// Division Test uint8_t //////////////////////////////////////

	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_U8_SPIKE(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
		DIV_TEST_U8(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}

////////////////////////////////////////// Division Test int8_t  //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int8_t  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S8_SPIKE(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int8_t);
#else
		DIV_TEST_S8(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}

////////////////////////////////////////// Division Test uint16_t //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test uint16_t :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		DIV_TEST_U16_SPIKE(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint16_t);
#else
		DIV_TEST_U16(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}


////////////////////////////////////////// Division Test int16_t  //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int16_t  :\n");
#endif
	testtypenum++;
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN		
		DIV_TEST_S16_SPIKE(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int16_t);
#else
		DIV_TEST_S16(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}


////////////////////////////////////////// Division Test uint32_t //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test uint32_t :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_U32_SPIKE(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint32_t);
#else
		DIV_TEST_U32(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}


////////////////////////////////////////// Division Test int32_t //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int32_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S32_SPIKE(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,int32_t);
#else
		DIV_TEST_S32(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}


////////////////////////////////////////// Division Test uint64_t //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test uint64_t :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_U64_SPIKE(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		DIV_PRINT_RESULT_UU64(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		DIV_TEST_U64(MAILBOX1,op1_64u,op2_64u,result_64u_full,testnumber);
#endif
	}

////////////////////////////////////////// Division Test int64_t //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int64_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S64_SPIKE(op1_64s,op2_64s,result_64s_full,result_64s_tb,testnumber);
		DIV_PRINT_RESULT_SS64(op1_64s,op2_64s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		DIV_TEST_S64(MAILBOX1,op1_64s,op2_64s,result_64s_full,testnumber);
#endif
	}



////////////////////////////////////////// C Division tests PART 3 ///////////////////////////////////////
//Get all the random numbers needed as per the test count and store it into a array In LOOP then we will
//Process them into DIV operation with cross data types uint8 * uint16 or similarly for singed and store in the
//necessary data type. 


#ifdef SPIKE_RUN
	printf("\nTest/> C Division tests:\n");
	printf("\n------------------------------\n");
#endif




#ifdef SPIKE_RUN
#else
	RAND_ARR_STORE_C(MAILBOX1);
#endif

/////////////////////////////////// Division Test uint8_t and uint16_t  ///////////////////////////////////////////// 
#ifdef SPIKE_RUN
	printf("\nTest/> Division Test uint8_t and uint16_t:\n");
#endif
	testtypenum++;
	
		for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_U816EC_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,U8xU16);
#else     
		DIV_TEST_U816EC_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}

/////////////////////////////////// Division Test uint8_t and uint32_t  ///////////////////////////////////////////// 

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test uint8_t and uint32_t:\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_U832_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,U8xU32);
#else
		DIV_TEST_U832_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}

/////////////////////////////////// Division Test uint16_t and uint32_t ///////////////////////////////////////////// 

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test uint16_t and uint32_t:\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN			
		DIV_TEST_U1632_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,U16xU32);
#else
		DIV_TEST_U1632_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif

}

/////////////////////////////////// Division Test int8_t and int16_t ///////////////////////////////////////////// 
#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int8_t and int16_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S816_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,S8xS16);
#else
		DIV_TEST_S816_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}

/////////////////////////////////// Division Test int8_t and int32_t ///////////////////////////////////////////// 

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int8_t and int32_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S832_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,S8xS32);
#else
		DIV_TEST_S832_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}

/////////////////////////////////// Division Test int16_t and int32_t ///////////////////////////////////////////// 

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int16_t and int32_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S1632_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_SS(op1,op2,result_tb,result_full,testnumber,S16S32);
#else
		DIV_TEST_S1632_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}
/////////////////////////////////// Division Test int8_t and uint8_t  ///////////////////////////////////////////// 
#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int8_t and uint8_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S8U8_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_US(op1,op2,result_tb,result_full,testnumber,S8xU8);
#else
		DIV_TEST_S8U8_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}
/////////////////////////////////// Division Test int16_t and uint16_t ///////////////////////////////////////////// 
#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int16_t and uint16_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S16U16_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_US(op1,op2,result_tb,result_full,testnumber,S16xU16);
#else
		DIV_TEST_S16U16_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}
/////////////////////////////////// Division Test int32_t and uint32_t ///////////////////////////////////////////// 

#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int32_t and uint32_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S32U32_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_US(op1,op2,result_tb,result_full,testnumber,S32xU32);
#else
		DIV_TEST_S32U32_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}  
/////////////////////////////////// Division Test int8_t and uint16_t  ///////////////////////////////////////////// 
#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int8_t and uint16_t :\n");
#endif
	testtypenum++;
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S8U16_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_US(op1,op2,result_tb,result_full,testnumber,S8xU16);
#else
		DIV_TEST_S8U16_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}


/////////////////////////////////// Division Test int8_t and uint32_t  ///////////////////////////////////////////// 
#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int8_t and uint32_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S8U32_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_US(op1,op2,result_tb,result_full,testnumber,S8xU32);
#else
		DIV_TEST_S8U32_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}
/////////////////////////////////// Division Test int16_t and uint32_t ///////////////////////////////////////////// 
#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int16_t and uint32_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S16U32_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_US(op1,op2,result_tb,result_full,testnumber,S16xU32);
#else
		DIV_TEST_S16U32_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}
/////////////////////////////////// Division Test int16_t and uint8_t  ///////////////////////////////////////////// 
#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int16_t and uint8_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S16U8_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_SU(op1,op2,result_tb,result_full,testnumber,S16xU8);
#else
		DIV_TEST_S16U8_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}

/////////////////////////////////// Division Test int32_t and uint8_t ///////////////////////////////////////////// 
#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int32_t and uint8_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S32U8_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_SU(op1,op2,result_tb,result_full,testnumber,S32xU8);
#else
		DIV_TEST_S32U8_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}


/////////////////////////////////// Division Test int32_t and uint16_t  ///////////////////////////////////////////// 
#ifdef SPIKE_RUN
	printf("\nTest/> Division Test int32_t and uint16_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		DIV_TEST_S32U16_SPIKE_C(op1,op2,result_full,result_tb,testnumber);
		DIV_PRINT_RESULT_SU(op1,op2,result_tb,result_full,testnumber,S32xU16);
#else
		DIV_TEST_S32U16_C(MAILBOX1,op1,op2,result_full,testnumber);
#endif
	}


///////////////////////////////////////// RISC Compliance Assembly Division Tests Part 5 //////////////////////////////////////


#ifdef SPIKE_RUN
   printf("\nTest/> Assembly Division tests:\n");
   printf("\n-------------------------------------\n");
#endif


/*********************************** Division Test uint8_t TEST_RR_SRC1_EQ_DEST********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Division Test uint8_t for SRC1_EQ_DEST:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	DIV_TEST_U8SRC1_EQ_DEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	DIV_TEST_U8SRC1_EQ_DEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }
/*********************************** Division Test uint8_t TEST_RR_SRC2_EQ_DEST********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Division Test uint8_t for SRC2_EQ_DEST:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	DIV_TEST_U8SRC2_EQ_DEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	DIV_TEST_U8SRC2_EQ_DEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }


/*********************************** Division Test uint8_t TEST_RR_SRC12_EQ_DEST********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Division Test uint8_t for SRC12_EQ_DEST:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siDIVation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	DIV_TEST_U8SRC12_EQ_DEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	DIV_TEST_U8SRC12_EQ_DEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }
/*********************************** Division Test uint8_t TEST_RR_ZEROSRC1********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Division Test uint8_t for ZEROSRC1:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siDIVation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	DIV_TEST_U8ZEROSRC1_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	DIV_TEST_U8ZEROSRC1(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }

/*********************************** Division Test uint8_t TEST_RR_ZEROSRC2********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Division Test uint8_t for ZEROSRC2:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siDIVation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	DIV_TEST_U8ZEROSRC2_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	DIV_TEST_U8ZEROSRC2(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }
/*********************************** Division Test uint8_t TEST_RR_ZEROSRC12********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Division Test uint8_t for ZEROSRC12:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siDIVation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	DIV_TEST_U8ZEROSRC12_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	DIV_TEST_U8ZEROSRC12(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }

/*********************************** Division Test uint8_t TEST_RR_ZERODEST********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Division Test uint8_t for ZERODEST:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siDIVation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	DIV_TEST_U8ZERODEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	DIV_TEST_U8ZERODEST(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }


/*********************************** Division Test uint8_t TEST_RR_DEST_BYPASS********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Division Test uint8_t for DEST_BYPASS:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siDIVation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	DIV_TEST_U8DEST_BYPASS_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	DIV_TEST_U8DEST_BYPASS(MAILBOX1,op1,op2,result_full,testnumber);
#endif	
   }


/*********************************** Division Test uint8_t TEST_RR_SRC12_BYPASS********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Division Test uint8_t for SRC12_BYPASS:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siDIVation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	DIV_TEST_U8SRC12_BYPASS_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	DIV_TEST_U8SRC12_BYPASS(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }


/*********************************** Division Test uint8_t TEST_RR_SRC21_BYPASS********************************************/
#ifdef SPIKE_RUN
   printf("\nTest/> Division Test uint8_t for SRC21_BYPASS:\n");
#endif
   testtypenum++;
       /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                Then the result is taken as "Actual" result and the spike siDIVation generates the "Expected" result
                for comparison */

   for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
   {
#ifdef SPIKE_RUN	
   	DIV_TEST_U8SRC21_BYPASS_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,uint8_t);
#else
   	DIV_TEST_U8SRC21_BYPASS(MAILBOX1,op1,op2,result_full,testnumber);
#endif
   }




////////////////////////////////////////// C Division tests PART 6 ///////////////////////////////////////



///////////////////////////////////////////////////////// ///////////////////////////////////
//////////////////////                    MAX cases                  ////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
    #ifdef SPIKE_RUN
   
    printf("\nTest/> Division Test for Max of uint8_t and uint16_t:\n");
#endif
	testtypenum++;
    int k = 1+testtypenum*TEST_COUNT;	
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		DIV_TEST_MAX_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint16_t,uint8_t,uint16_t  );
		DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,U8xU16);
#else
		DIV_TEST_MAX_C(MAILBOX1,op1,op2,result_full,testnumber,uint16_t,uint8_t,uint16_t,UINT16_MAX , UINT8_MAX);
#endif
}

	k++;
    
//////////////// Division MAX test uint32_t / uint8_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for Max of uint32_t and uint8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint32_t, uint8_t, uint32_t);
	DIV_PRINT_RESULT_UU(op1, op2, result_tb, result_full, testnumber, U8xU32);
#else
	DIV_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber, uint32_t, uint8_t, uint32_t, UINT32_MAX, UINT8_MAX);
#endif
}

k++;

//////////////// Division MAX test uint32_t / uint16_t//////////////
#ifdef SPIKE_RUN

	printf("\nTest/> Division Test for Max of uint32_t and uint16_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint32_t, uint16_t, uint32_t);
	DIV_PRINT_RESULT_UU(op1, op2, result_tb, result_full, testnumber, U16xU32);
#else
	DIV_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber, uint32_t, uint16_t, uint32_t, UINT32_MAX, UINT16_MAX);
#endif
}

k++;

//////////////// Division MAX test int16_t / int8_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for Max of int16_t and int8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber, int16_t, int8_t, int16_t);
	DIV_PRINT_RESULT_SS(op1, op2, result_tb, result_full, testnumber, S8xS16);
#else
	DIV_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber, int16_t, int8_t, int16_t, INT16_MAX, INT8_MAX);
#endif
}

k++;


//////////////// Division MAX test int32_t / int16_t//////////////
#ifdef SPIKE_RUN

	printf("\nTest/> Division Test for Max of int32_t and int16_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber, int32_t, int16_t, int32_t);
	DIV_PRINT_RESULT_US(op1, op2, result_tb, result_full, testnumber, S16xU32);
#else
	DIV_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber, int32_t, int16_t, int32_t, INT32_MAX, INT16_MAX);
#endif
}

k++;

//////////////// Division MAX test int32_t / int8_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for Max of int32_t and int8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber, int32_t, int8_t, int32_t);
	DIV_PRINT_RESULT_SS(op1, op2, result_tb, result_full, testnumber, S8xS32);
#else
	DIV_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber, int32_t, int8_t, int32_t, INT32_MAX, INT8_MAX);
#endif
}

k++;

//////////////// Division MAX test int16_t / uint8_t//////////////
#ifdef SPIKE_RUN

	printf("\nTest/> Division Test for Max of int16_t and uint8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber, int16_t, uint8_t, int16_t);
	DIV_PRINT_RESULT_SU(op1, op2, result_tb, result_full, testnumber, U8xS16);
#else
	DIV_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber, int16_t, uint8_t, int16_t, INT16_MAX, UINT8_MAX);
#endif
}

k++;

//////////////// Division MAX test uint8_t / int8_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for Max of uint8_t and int8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint8_t, int8_t, int16_t);
	DIV_PRINT_RESULT_US(op1, op2, result_tb, result_full, testnumber, S8xU8);
#else
	DIV_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber, uint8_t, int8_t, int16_t, UINT8_MAX, INT8_MAX);
#endif
}

k++;

//////////////// Division MAX test uint16_t / int16_t//////////////
#ifdef SPIKE_RUN

	printf("\nTest/> Division Test for Max of uint16_t  and int16_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint16_t, int16_t, int32_t);
	DIV_PRINT_RESULT_US(op1, op2, result_tb, result_full, testnumber, S16xU16);
#else
	DIV_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber, uint16_t, int16_t, int32_t, UINT16_MAX, INT16_MAX);
#endif
}

k++;

////////////////S32U32  Division MAX test uinT32_t / int32_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for Max of uinT32_t and int32_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint32_t, int32_t, int64_t);
	DIV_PRINT_RESULT_US(op1, op2, result_tb, result_full, testnumber, S32xU32);
#else
	DIV_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber, uint32_t, int32_t, int64_t, UINT32_MAX, INT32_MAX);
#endif
}

k++;



//////////////// S8U16 Division MAX test uint16_t / int8_t//////////////
#ifdef SPIKE_RUN

	printf("\nTest/> Division Test for Max of uint16_t and int8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint16_t, int8_t, int32_t);
	DIV_PRINT_RESULT_US(op1, op2, result_tb, result_full, testnumber, S8xU16);
#else
	DIV_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber, uint16_t, int8_t, int32_t, UINT16_MAX, INT8_MAX);
#endif
}

k++;

//////////////// S8U32 Division MAX test uint32_t / int8_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for Max of  uint32_t and int8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint32_t, int8_t, int64_t);
	DIV_PRINT_RESULT_US(op1, op2, result_tb, result_full, testnumber, S8xU32);
#else
	DIV_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber, uint32_t, int8_t, int64_t, UINT32_MAX, INT8_MAX);
#endif
}

k++;


//////////////// S16U32 Division MAX test uint32_t / int16_t//////////////
#ifdef SPIKE_RUN

	printf("\nTest/> Division Test for Max of int16_t and uint8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint32_t, int16_t, int64_t);
	DIV_PRINT_RESULT_US(op1, op2, result_tb, result_full, testnumber, S16xU32);
#else
	DIV_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber, uint32_t, int16_t, int64_t, UINT32_MAX, INT16_MAX);
#endif
}

k++;

//////////////// U8S32 Division MAX test int32_t / int8_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for Max of int32_t and int8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber, int32_t, uint8_t, int32_t);
	DIV_PRINT_RESULT_SU(op1, op2, result_tb, result_full, testnumber, U8xS32);
#else
	DIV_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber, int32_t, uint8_t, int32_t, INT32_MAX, UINT8_MAX);
#endif
}

k++;

////////////////U16S32   Division MAX test int32_t / uint16_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for Max of int32_t and uint16_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MAX_SPIKE_C(op1, op2, result_full, result_tb, testnumber, int32_t, uint16_t, int32_t);
	DIV_PRINT_RESULT_SU(op1, op2, result_tb, result_full, testnumber, U16xS32);
#else
	DIV_TEST_MAX_C(MAILBOX1, op1, op2, result_full, testnumber, int32_t, uint16_t, int32_t, INT32_MAX, UINT16_MAX);
#endif
}

k++;



////////////////////////////////////////////////////////////////////////////////////////////
/////                           Method 2 to Check MIN cases         ////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
    #ifdef SPIKE_RUN
    printf("\n Test/> Min cases");
    printf("\nTest/> Division Test for MIN of uint8_t and uint16_t:\n");
#endif
	testtypenum++;	
        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

	for(int testnumber=k; testnumber < k+1; testnumber++)
{
#ifdef SPIKE_RUN	
		DIV_TEST_MIN_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint16_t,uint8_t,uint16_t  );
		DIV_PRINT_RESULT_UU(op1,op2,result_tb,result_full,testnumber,U8xU16);
#else
		DIV_TEST_MIN_C(MAILBOX1,op1,op2,result_full,testnumber,uint16_t,uint8_t,uint16_t,UINT16_MIN , UINT8_MIN);
#endif
}

	k++;
    
//////////////// Division MIN test uint32_t / uint8_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for MIN of uint32_t and uint8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint32_t, uint8_t, uint32_t);
	DIV_PRINT_RESULT_UU(op1, op2, result_tb, result_full, testnumber, U8xU32);
#else
	DIV_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber, uint32_t, uint8_t, uint32_t, UINT32_MIN, UINT8_MIN);
#endif
}

k++;

//////////////// Division MIN test uint32_t / uint16_t//////////////
#ifdef SPIKE_RUN

	printf("\nTest/> Division Test for MIN of uint32_t and uint16_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint32_t, uint16_t, uint32_t);
	DIV_PRINT_RESULT_UU(op1, op2, result_tb, result_full, testnumber, U16xU32);
#else
	DIV_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber, uint32_t, uint16_t, uint32_t, UINT32_MIN, UINT16_MIN);
#endif
}

k++;

//////////////// Division MIN test int16_t / int8_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for MIN of int16_t and int8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber, int16_t, int8_t, int16_t);
	DIV_PRINT_RESULT_SS(op1, op2, result_tb, result_full, testnumber, S8xS16);
#else
	DIV_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber, int16_t, int8_t, int16_t, INT16_MIN, INT8_MIN);
#endif
}

k++;


//////////////// Division MIN test int32_t / int16_t//////////////
#ifdef SPIKE_RUN

	printf("\nTest/> Division Test for MIN of int32_t and int16_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber, int32_t, int16_t, int32_t);
	DIV_PRINT_RESULT_US(op1, op2, result_tb, result_full, testnumber, S16xU32);
#else
	DIV_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber, int32_t, int16_t, int32_t, INT32_MIN, INT16_MIN);
#endif
}

k++;

//////////////// Division MIN test int32_t / int8_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for MIN of int32_t and int8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber, int32_t, int8_t, int32_t);
	DIV_PRINT_RESULT_SS(op1, op2, result_tb, result_full, testnumber, S8xS32);
#else
	DIV_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber, int32_t, int8_t, int32_t, INT32_MIN, INT8_MIN);
#endif
}

k++;

//////////////// Division MIN test int16_t / uint8_t//////////////
#ifdef SPIKE_RUN

	printf("\nTest/> Division Test for MIN of int16_t and uint8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber, int16_t, uint8_t, int16_t);
	DIV_PRINT_RESULT_SU(op1, op2, result_tb, result_full, testnumber, U8xS16);
#else
	DIV_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber, int16_t, uint8_t, int16_t, INT16_MIN, UINT8_MIN);
#endif
}

k++;

//////////////// Division MIN test uint8_t / int8_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for MIN of uint8_t and int8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint8_t, int8_t, int16_t);
	DIV_PRINT_RESULT_US(op1, op2, result_tb, result_full, testnumber, S8xU8);
#else
	DIV_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber, uint8_t, int8_t, int16_t, UINT8_MIN, INT8_MIN);
#endif
}

k++;

//////////////// Division MIN test uint16_t / int16_t//////////////
#ifdef SPIKE_RUN

	printf("\nTest/> Division Test for MIN of uint16_t  and int16_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint16_t, int16_t, int32_t);
	DIV_PRINT_RESULT_US(op1, op2, result_tb, result_full, testnumber, S16xU16);
#else
	DIV_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber, uint16_t, int16_t, int32_t, UINT16_MIN, INT16_MIN);
#endif
}

k++;

////////////////S32U32  Division MIN test uinT32_t / int32_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for MIN of uint32_t and int32_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint32_t, int32_t, int64_t);
	DIV_PRINT_RESULT_US(op1, op2, result_tb, result_full, testnumber, S32xU32);
#else
	DIV_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber, uint32_t, int32_t, int64_t, UINT32_MIN, INT32_MIN);
#endif
}

k++;



//////////////// S8U16 Division MIN test uint16_t / int8_t//////////////
#ifdef SPIKE_RUN

	printf("\nTest/> Division Test for MIN of uint16_t and int8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint16_t, int8_t, int32_t);
	DIV_PRINT_RESULT_US(op1, op2, result_tb, result_full, testnumber, S8xU16);
#else
	DIV_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber, uint16_t, int8_t, int32_t, UINT16_MIN, INT8_MIN);
#endif
}

k++;

//////////////// S8U32 Division MIN test uint32_t / int8_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for MIN of  uint32_t and int8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint32_t, int8_t, int64_t);
	DIV_PRINT_RESULT_US(op1, op2, result_tb, result_full, testnumber, S8xU32);
#else
	DIV_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber, uint32_t, int8_t, int64_t, UINT32_MIN, INT8_MIN);
#endif
}

k++;


//////////////// S16U32 Division MIN test uint32_t / int16_t//////////////
#ifdef SPIKE_RUN

	printf("\nTest/> Division Test for MIN of int16_t and uint8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber, uint32_t, int16_t, int64_t);
	DIV_PRINT_RESULT_US(op1, op2, result_tb, result_full, testnumber, S16xU32);
#else
	DIV_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber, uint32_t, int16_t, int64_t, UINT32_MIN, INT16_MIN);
#endif
}

k++;

//////////////// U8S32 Division MIN test int32_t / int8_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for MIN of int32_t and int8_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber, int32_t, uint8_t, int32_t);
	DIV_PRINT_RESULT_SU(op1, op2, result_tb, result_full, testnumber, U8xS32);
#else
	DIV_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber, int32_t, uint8_t, int32_t, INT32_MIN, UINT8_MIN);
#endif
}

k++;

////////////////U16S32   Division MIN test int32_t / uint16_t//////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test for MIN of int32_t and uint16_t:\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber, int32_t, uint16_t, int32_t);
	DIV_PRINT_RESULT_SU(op1, op2, result_tb, result_full, testnumber, U16xS32);
#else
	DIV_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber, int32_t, uint16_t, int32_t, INT32_MIN, UINT16_MIN);
#endif
}

k++;

//////////////// Division Overflow //////////////
#ifdef SPIKE_RUN

printf("\nTest/> Division Test:Overflow :\n");
#endif
testtypenum++;
/* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

for (int testnumber = k; testnumber < k + 1; testnumber++)
{
#ifdef SPIKE_RUN
	DIV_TEST_MIN_SPIKE_C(op1, op2, result_full, result_tb, testnumber, int64_t, int64_t, int64_t);
	DIV_PRINT_RESULT_SS64(op1, op2, result_tb, result_full, testnumber, int64_t);
#else
	DIV_TEST_MIN_C(MAILBOX1, op1, op2, result_full, testnumber, int64_t, int64_t, int64_t, INT64_MIN, -1 );
#endif
}

k++;

	mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);

	return 0;
}

