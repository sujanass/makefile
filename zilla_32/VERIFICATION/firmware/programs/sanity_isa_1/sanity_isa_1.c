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
*********************************************************************************
** TEST PLAN 
** 
** Part 1 -- ISA TEST USING INLINE ASM 
** 
** In Part 1 -- We are going to check INLINE ASM for logical, arithmetic, R, I and 
** load & store Instructions
** 
** Part 2 -- ISA TEST USING INLINE ASM 
** 
** In Part 1 -- We are going to check INLINE ASM for custom, R, multiplication, division,
**  reminde and Jump Type Instruction
** In Part 3 -- We are going to check IRQ one by one for forcing it via TB,
** Also check for Nesting of Interrupts 
** 
** In Part 4 -- We are going to check Exceptions by Hacking the DUT Signals in
** the instruction Fetch Reg and Create a Sys Reset by Writing to relevant SW 
** reset register (Since SW reset is not implemted for time being POR will be done)
** Part 4 will be TBD 
** 
** Part 5 -- Related to Debug Unit 
** 
** Part 6 -- Related to Trace Unit 
**
*********************************************************************************
*/


////////////    Part 1 -- ISA Test -1    //////////////////




#include <stdio.h>
#include <stdlib.h>
#include <limits.h>             /*!< Datatype limit         */
#include <stdint.h>             /*!< Standarad Integer type */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
#include "testmacro.h"          /*!< Test macros            */
#include "custom.h"
#include "type128.h"            /*!< 128 width variable support  */

#ifdef SPIKE_RUN
#include "data.h"               /*!< Testbench created data */
#endif

/* Note: TEST_COUNT indicates number of test for each tests. e.g. TEST_COUNT number
   of tests for uint8_t Addition, TEST_COUNT number of tests for int8_t Addition, etc*/
#define TEST_COUNT     (3)    /*!< Test count             */
#define DATA_SET        (3)     /*!< op1, op2, result       */
#define TEST_TYPES      (4)     /*!< 32u,32s,64u,64s  */
#define TEST_THREE     (150)	//TEST_THREE(is12)x2xTEST_COUNT 
#define STORE_TYPES    (4)      /* sb , sh, sw, sd */
#define BANK_COUNT      (3)    /* Total Memory bank count */
#define START_ADDRS     (0x48120) /* Starting Address of Data Memory */


#define TEST_ONLY    (1)


/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};
#include "ui_sanity_isa_1.h"          /*!< Test macros            */

/* Main function */
int main(int argc, char *argv[])
{
	/* test case status */
	volatile int testnumber   = 1;
	volatile int testtypenum  = 0;
	int num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*3*TEST_TYPES*35) + (TEST_COUNT*3*2*6) +  (BANK_COUNT * DATA_SET * 7) ;
    // number of elements in array = (test 1) + (custom) + (load & store)                       



  /////////////////////////////////////  Addition Test      //////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> C addition tests:\n");
	printf("\n------------------------------\n");
#endif

  
///////////////////////////////////// ADDW_U - Addition Test uint32_t   //////////////////////////////////////////////////////


#ifdef SPIKE_RUN
	printf("\nTest/> ADDW_U - Addition Test uint32_t :\n");
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

/////////////////////////////////////  ADDW_S -  Addition Test int32_t  //////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> ADDW_S -  Addition Test int32_t  :\n");
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
 /////////////////////////////////////Addition Test uint64_t   //////////////////////////////////////////////////////


#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test uint64_t :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_U64_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_ADD_U(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		ADD_TEST_U64_C(MAILBOX1,op1_64u,op2_64u,result_64u_full, testnumber);
#endif
	}


/////////////////////////////////////Addition Test int64_t  //////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Addition Test int64_t  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		ADD_TEST_S64_SPIKE_C(op1_64s,op2_64s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_ADD_S(op1_64s,op2_64s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		ADD_TEST_S64_C(MAILBOX1,op1_64s,op2_64s,result_64s_full,testnumber);
#endif
	}


/////////////////////////////////////  Subtraction Test      //////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/>  C subtraction tests:\n");
	printf("\n------------------------------\n");
#endif


	// SUBW_U -  Subtraction Test uint32_t 


#ifdef SPIKE_RUN
	printf("\nTest/> SUBW_U - Subtraction Test uint32_t :\n");
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



	///SUBW_S -  Subtraction Test int32_t //

#ifdef SPIKE_RUN
	printf("\nTest/> SUBW_S - Subtraction Test int32_t  :\n");
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
///////////////////////////////////////////////////////////
// Subtraction Test uint64_t 


#ifdef SPIKE_RUN
	printf("\nTest/> Subtraction Test uint64_t :\n");
#endif
	testtypenum++;
	

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_U64_SPIKE_C(op1_64u,op2_64u,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_U(op1_64u,op2_64u,result_64s_tb,result_64s_full,testnumber,uint64_t);
#else
		SUB_TEST_U64_C(MAILBOX1,op1_64u,op2_64u,result_64s_full, testnumber);
#endif
	}



	/// Subtraction Test int64_t //

#ifdef SPIKE_RUN
	printf("\nTest/> Subtraction Test int64_t  :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SUB_TEST_S64_SPIKE_C(op1_64s,op2_64s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_SUB_S(op1_64s,op2_64s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SUB_TEST_S64_C(MAILBOX1,op1_64s,op2_64s,result_64s_full,testnumber);
#endif
	}


////////////////////////////////////////// XOR tests ///////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> C XOR tests:\n");
	printf("\n------------------------------\n");
#endif


/*********************************** XOR Test uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> XOR Test uint64_t :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		XOR_TEST_U64_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_XOR64U(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		XOR_TEST_U64_C(MAILBOX1,op1_64u,op2_64u,result_64u_full, testnumber);
#endif
	}


//////////////////////////////////////////  OR tests ///////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> C Or tests:\n");
	printf("\n------------------------------\n");
#endif

  
/*********************************** OR Test uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> OR Test uint64_t :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		OR_TEST_U64_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_OR64U(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		OR_TEST_U64_C(MAILBOX1,op1_64u,op2_64u,result_64u_full, testnumber);
#endif
	}

//////////////////////////////////////////  And tests ///////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> C And tests:\n");
	printf("\n------------------------------\n");
#endif

/*********************************** And Test uint64_t ********************************************/
#ifdef SPIKE_RUN
	printf("\nTest/> And Test uint64_t :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		AND_TEST_U64_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_AND64U(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		AND_TEST_U64_C(MAILBOX1,op1_64u,op2_64u,result_64u_full, testnumber);
#endif
	}
////////////////////////Shift Left Logical ///////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> C Shift Left tests:\n");
	printf("\n------------------------------\n");
#endif

     

////////////////////////////////////////// SLLW_U - Shift left Test uint32_t //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> SLLW_U - Shift left Test uint32_t :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SLL_TEST_U32_SPIKE(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		SLL_PRINT_RESULT_UU(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
#else
		SLL_TEST_U32(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
#endif
	}

////////////////////////////////////////// SLLW_S - Shift left Test int32_t //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> SLLW_S - Shift left Test int32_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SLL_TEST_S32_SPIKE(op1_32s,op2_32s,result_32s_full,result_32s_tb,testnumber);
		SLL_PRINT_RESULT_SS(op1_32s,op2_32s,result_32s_tb,result_32s_full,testnumber,int32_t);
#else
		SLL_TEST_S32(MAILBOX1,op1_32s,op2_32s,result_32s_full,testnumber);
#endif
	}

   

//////////////////////////  Shift left Test uint64_t      /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Shift left Test uint64_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SLL_TEST_U64_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		SLL_PRINT_RESULT_UU(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		SLL_TEST_U64_C(MAILBOX1,op1_64u,op2_64u,result_64u_full, testnumber);
#endif
	} 

//////////////////////////  Shift left Test int64_t   /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Shift left Test int64_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		SLL_TEST_S64_SPIKE_C(op1_64s,op2_64s,result_64s_full,result_64s_tb,testnumber);
		SLL_PRINT_RESULT_SS(op1_64s,op2_64s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		SLL_TEST_S64_C(MAILBOX1,op1_64s,op2_64s,result_64s_full,testnumber);
#endif
	}


////////////////////////Logical Right Shift  ///////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> C Logical Right Shift tests:\n");
	printf("\n------------------------------\n");
#endif


////////////////////////  SRLW_U -Logical Right Shift Test uint32_t ///////////////////////////////////////

	   
#ifdef SPIKE_RUN
     printf("\nTest/> SRLW_U - C Logical Right Shift tests: uint32_t_t\n");
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

//////////////////////// SRLW_S - Logical Right Shift Test int32_t ///////////////////////////////////////

	   
#ifdef SPIKE_RUN
     printf("\nTest/> SRLW_S - C Logical Right Shift tests: int32_t_t\n");
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


//////////////////////// Shift Right Arithmetic ///////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> C Arithmetic Right Shift tests:\n");
	printf("\n------------------------------\n");
#endif


    
	////////////////////////////////////////// SHIFT RIGHT ARITHMETIC tests ///////////////////////////////////////
//////////////////////////  SRA int64_t   /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> C SRA tests:\n");
	printf("\n------------------------------\n");
#endif

//************     SRA Test for uint64_t         *****************
    #ifdef SPIKE_RUN
        printf("\n Test/> SRA Test for uint64_t : \n");
        printf("\n --------------------------------\n");
    #endif

    testtypenum++;

    for (int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
    {
        #ifdef SPIKE_RUN
            SRA_TEST_U64_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
            SRA_PRINT_RESULT_U(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
        #else
            SRA_TEST_U64_C(MAILBOX1,op1_64u,op2_64u,result_64u_full,testnumber);
        #endif
    }

    //*************   SRA Test for int64_t        *******************   
    #ifdef SPIKE_RUN
	    printf("\nTest/> SRA Test for int64_t  : \n");
        printf("\n -------------------------------\n");
    #endif
        
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)   
	{
        #ifdef SPIKE_RUN		
		    SRA_TEST_S64_SPIKE_C(op1_64s,op2_64s,result_64s_full,result_64s_tb,testnumber);    
		    SRA_PRINT_RESULT_S(op1_64s,op2_64s,result_64s_tb,result_64s_full,testnumber,int64_t);  
        #else
		    SRA_TEST_S64_C(MAILBOX1,op1_64s,op2_64s,result_64s_full,testnumber);        
        #endif
     }

//////////////////////////  SRAW int32_t   /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> C SRAW tests:\n");
	printf("\n------------------------------\n");
#endif

//****************   SRAW Test for uint32_t      *********************    
    #ifdef SPIKE_RUN
        printf ("\n Test/ > SRAW Test for uint32_t integer : \n");
        printf ("\n ----------------------------------------\n");
    #endif
        
    testtypenum++;

    for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
        #ifdef SPIKE_RUN	
		    SRAW_TEST_U32_SPIKE_C(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		    SRAW_PRINT_RESULT_U(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);
        #else         
		    SRAW_TEST_U32_C(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);
        #endif
    }
    
    
    //***************   SRAW Test for int32_t          *******************  
    #ifdef SPIKE_RUN
    	printf("\n Test/> SRAW Test for int32_t  : \n");
        printf("\n -------------------------------\n");
    #endif

	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
        #ifdef SPIKE_RUN	
		    SRAW_TEST_S32_SPIKE_C(op1_32s,op2_32s,result_32s_full,result_32s_tb,testnumber);
		    SRAW_PRINT_RESULT_S(op1_32s,op2_32s,result_32s_tb,result_32s_full,testnumber,int32_t);	
        #else         
		    SRAW_TEST_S32_C(MAILBOX1,op1_32s,op2_32s,result_32s_full,testnumber);
        #endif
    }

////////////////////////Set less than ///////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> C Set less than tests:\n");
	printf("\n------------------------------\n");
#endif


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
testtypenum++ ;
testnumber = 1+testtypenum*TEST_COUNT;

testnumber = test_ui_sanity_isa_1_type(testnumber);


//////////////////////// LOAD and STORE Instructions ///////////////////////////////////////
//


#ifdef SPIKE_RUN
	printf("\nTest/> Instruction Load and Store tests:\n");
	printf("\n------------------------------\n");
#endif

    /*******************Store byte and load Byte signed *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store byte and load byte\n");
	printf("\n------------------------------\n");
#endif

test_sb_lb_type(testnumber) ;
testnumber += BANK_COUNT ;

/*******************Store byte and load Byte unsigned *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store byte and Load byte unsigned\n");
	printf("\n------------------------------\n");
#endif

test_sb_lbu_type(testnumber) ;
testnumber += BANK_COUNT ;

/******************* Store half word and Load half word signed test cases *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store half word and Load half word signed\n");
	printf("\n------------------------------\n");
#endif

test_sh_lh_type(testnumber) ;
testnumber += BANK_COUNT ;

/******************* Store half word and Load half word unsigned test cases *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store half word and Load half word unsigned\n");
	printf("\n------------------------------\n");
#endif

test_sh_lhu_type(testnumber) ;
testnumber += BANK_COUNT ;

/******************* Store word and Load  word signed test cases *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store word and Load  word signed\n");
	printf("\n------------------------------\n");
#endif

test_sw_lw_type(testnumber) ;
testnumber += BANK_COUNT ;

/******************* Store word and Load  word unsigned test cases  *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store word and Load word unsigned test cases\n");
	printf("\n------------------------------\n");
#endif

test_sw_lwu_type(testnumber) ;
testnumber += BANK_COUNT ;
/******************* Store double word and Load double word test cases *********************/
#ifdef SPIKE_RUN
	printf("\n\n-Test/>Store double word and Load double word\n");
	printf("\n------------------------------\n");
#endif

test_sd_ld_type(testnumber) ;
testnumber += BANK_COUNT ;





	mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);


	return 0;


}
