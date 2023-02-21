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


////////////    Part 1 -- ISA Test -2   //////////////////




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

#define TEST_ONLY    (1)


/* Array to store the operand1, operand2 and actual result */
uint64_t actual_result[TEST_COUNT*TEST_TYPES*93] __attribute((section(".results"))) = {0,};
int64_t *p ;

/* Main function */
int main(int argc, char *argv[])
{
	/* test case status */
	volatile int testnumber   = 1;
	volatile int testtypenum  = 0;
	int num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*3*TEST_TYPES*9) + (TEST_COUNT*3*2*14) + (TEST_COUNT*20) + (TEST_COUNT*11) ;
    // number of elements in array = (test 1) + (custom) + (sort) + (search)                     



////////////////////////////////////////// Division tests ///////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> C Division tests:\n");
	printf("\n------------------------------\n");
#endif


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


////////////////////////////////////////// Remainder tests ///////////////////////////////////////


#ifdef SPIKE_RUN
	printf("\nTest/> C Reminder tests:\n");
	printf("\n------------------------------\n");
#endif
    
//////////////////////////  Reminder Test uint64_t      /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Reminder Test uint64_t :\n");
#endif
	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		REM_TEST_U64_SPIKE_C(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		REM_PRINT_RESULT_UU(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
#else
		REM_TEST_U64_C(MAILBOX1,op1_64u,op2_64u,result_64u_full, testnumber);
#endif
	}

//////////////////////////  Reminder Test int64_t   /////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Reminder Test int64_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		REM_TEST_S64_SPIKE_C(op1_64s,op2_64s,result_64s_full,result_64s_tb,testnumber);
		REM_PRINT_RESULT_SS(op1_64s,op2_64s,result_64s_tb,result_64s_full,testnumber,int64_t);
#else
		REM_TEST_S64_C(MAILBOX1,op1_64s,op2_64s,result_64s_full,testnumber);
#endif
	}

	///////////////////////////////////// IN-LINE ASSEMBLY INSTRUCTIONS /////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Custom instruction test:\n");
#endif

 
	////////////////////////////////////// Custom zilla instruction : z.cgt //////////////////////////////////////


   
    //64 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit compare greater than - signed : z.cgt");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R_SPIKE(z.cgt, op1, op2, result, exp_result, testnumber);
		print_test_results_cgt(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R(MAILBOX1, z.cgt, op1, op2, result, testnumber);
#endif
	}


	////////////////////////////////////// Custom zilla instruction : z.cgte //////////////////////////////////////



#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit compare greater than or equal to - signed : z.cgte");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R_SPIKE(z.cgte, op1, op2, result, exp_result, testnumber);
		print_test_results_cgte(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R(MAILBOX1, z.cgte, op1, op2, result, testnumber);
#endif
	}



	////////////////////////////////////// Custom zilla instruction : z.cgtu //////////////////////////////////////


#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit  compare greater than - unsigned: z.cgtu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R_SPIKE_U(z.cgtu, op1, op2, result, exp_result, testnumber);
		print_test_results_cgtu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R_U(MAILBOX1, z.cgtu, op1, op2, result, testnumber);
#endif
	}

	////////////////////////////////////// Custom zilla instruction : z.cgteu //////////////////////////////////////



#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit compare greater than or equal to - unsigned: z.cgteu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R_SPIKE_U(z.cgteu, op1, op2, result, exp_result, testnumber);
		print_test_results_cgteu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R_U(MAILBOX1, z.cgteu, op1, op2, result, testnumber);
#endif
	}


	////////////////////////////////////// Custom zilla instruction : z.clt //////////////////////////////////////



#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit compare lesser than - signed:  z.clt");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R_SPIKE( z.clt, op1, op2, result, exp_result, testnumber);
		print_test_results_clt(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R(MAILBOX1, z.clt, op1, op2, result, testnumber);
#endif
	}

	////////////////////////////////////// Custom zilla instruction : z.clte //////////////////////////////////////


 #ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit compare lesser than or equal to - signed  :z.clte");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R_SPIKE(z.clte, op1, op2, result, exp_result, testnumber);
		print_test_results_clte(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R(MAILBOX1, z.clte, op1, op2, result, testnumber);
#endif
	}

	////////////////////////////////////// Custom zilla instruction : z.cltu //////////////////////////////////////


 #ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit compare lesser than - unsigned:z.cltu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R_SPIKE_U(z.cltu, op1, op2, result, exp_result, testnumber);
		print_test_results_cltu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R_U(MAILBOX1, z.cltu, op1, op2, result, testnumber);
#endif
	}

	////////////////////////////////////// Custom zilla instruction : z.clteu //////////////////////////////////////


#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit compare lesser than or equal to - unsigned :z.clteu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R_SPIKE_U(z.clteu, op1, op2, result, exp_result, testnumber);
		print_test_results_clteu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R_U(MAILBOX1, z.clteu, op1, op2, result, testnumber);
#endif
	}

	////////////////////////////////////// Custom zilla instruction : z.ceq //////////////////////////////////////

  
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit compare equal : z.ceq ");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R_SPIKE( z.ceq , op1, op2, result, exp_result, testnumber);
		print_test_results_ceq(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R(MAILBOX1,  z.ceq , op1, op2, result, testnumber);
#endif
	}

	////////////////////////////////////// Custom zilla instruction : z.cne //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit compare not equal :z.cne");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R_SPIKE(z.cne, op1, op2, result, exp_result, testnumber);
		print_test_results_cne(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R(MAILBOX1, z.cne, op1, op2, result, testnumber);
#endif
	}
  

	////////////////////////////////////// Custom zilla instruction : z.rol //////////////////////////////////////


#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit rotate left - signed: z.rol");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R_SPIKE(z.rol, op1, op2, result, exp_result, testnumber);
	    print_test_results_rol(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R(MAILBOX1, z.rol, op1, op2, result, testnumber);
#endif
	}

      
//64 bit unsigned//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit rotate left -  unsigned: z.rol");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R_SPIKE_U(z.rol, op1, op2, result, exp_result, testnumber);
	    print_test_results_rol_u(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R_U(MAILBOX1, z.rol, op1, op2, result, testnumber);
#endif
	}


	////////////////////////////////////// Custom zilla instruction : z.ror //////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit rotate right - signed  : z.ror");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R_SPIKE(z.ror, op1, op2, result, exp_result, testnumber);
		print_test_results_ror(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R(MAILBOX1, z.ror, op1, op2, result, testnumber);
#endif
	}

        //64 bit unsigned//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit rotate right - unsigned : z.ror");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R_SPIKE_U(z.ror, op1, op2, result, exp_result, testnumber);
		print_test_results_ror_u(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R_U(MAILBOX1, z.ror, op1, op2, result, testnumber);
#endif
	}


/////////////////////////////////////////////////////////Insertion Sort //////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Insertion Sort test\n");
    printf("----------------------------------- \n");

#endif
	
testtypenum++;
 
for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{

#ifdef SPIKE_RUN	
		INSERTION_SORT_TEST_SPIKE_C(e_rand_arr,rslt_full,rslt_tb,testnumber);
        printf("Insertion sort %d \n",testnumber);
    	PRINT_RESULT_SORT(rslt_tb,rslt_full);
#else   
        RAND_ARR_SORT(MAILBOX1,testnumber);
		INSERTION_SORT_TEST_C(MAILBOX1,rand_arr,rslt_full ,testnumber);
  	  
#endif
        p=p+10;
        
   	}

//////////////////////////////////////////////// Binary Search //////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Binary search test\n");
    printf("----------------------------------- \n");

#endif

testtypenum++;
 
        	
for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
 
        
#ifdef SPIKE_RUN	
		BINARY_SEARCH_TEST_SPIKE_C(e_rand_arr,rslt_full,rslt_tb,testnumber);
        printf("Binary Search %d \n",testnumber);
        PRINT_RESULT_SEARCH(rslt_tb,rslt_full);
#else  
        
        RAND_ARR_SEARCH(MAILBOX1,testnumber);
        BINARY_SEARCH_TEST_C(MAILBOX1,rand_arr,rslt_full,testnumber);
  	  
#endif
      p=p+1;  
        
   	}




	////////////////////////////////////////// Multiplication tests ///////////////////////////////////////


#ifdef SPIKE_RUN
	printf("\nTest/> C multiplication tests:\n");
	printf("\n------------------------------\n");
#endif

    ////////////////////////////////  MULW_U - Multiplication Test uint32_t ////////////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> MULW_U - Multiplication Test uint32_t :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U32_SPIKE_C(op1_32u,op2_32u,result_64u_full,result_64u_tb,testnumber);
		PRINT_RESULT_U(op1_32u,op2_32u,result_64u_tb,result_64u_full,testnumber,uint32_t);
#else
		MUL_TEST_U32_C(MAILBOX1,op1_32u,op2_32u,result_32u_full, testnumber);
#endif
	}


	/////////////////////////////////// MULW_S Multiplication Test int32_t /////////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> MULW_S Multiplication Test int32_t  :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S32_SPIKE_C(op1_32s,op2_32s,result_64s_full,result_64s_tb,testnumber);
		PRINT_RESULT_S(op1_32s,op2_32s,result_64s_tb,result_64s_full,testnumber,int32_t);
#else
		MUL_TEST_S32_C(MAILBOX1,op1_32s,op2_32s,result_64s_full,testnumber);
#endif
	}

	//////////////////////////////////// Multiplication Test uint64_t /////////////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test uint64_t :\n");
#endif

	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_U64_SPIKE_C(op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,result_64u_tb_lo,result_64u_tb_hi,testnumber);
		PRINT_RESULT_U64(op1_64u,op2_64u,result_64u_tb_lo,rslt_64u_lo,result_64u_tb_hi,rslt_64u_hi,testnumber,uint64_t);
#else
		MUL_TEST_U64_C(MAILBOX1,op1_64u,op2_64u,rslt_64u_lo,rslt_64u_hi,testnumber);
#endif
	}


	///////////////////////////////////// Multiplication Test int64_t /////////////////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t :\n");
#endif
	testtypenum++;

    for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_S64_SPIKE_C(op1_64s,op2_64s,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_S64(op1_64s,op2_64s,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t);
#else
		MUL_TEST_S64_C(MAILBOX1,op1_64s,op2_64s,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	}


	////////////////////////////////////// Multiplication Test int64_t and uint64_t ////////////////////////////////
#ifdef SPIKE_RUN
	printf("\nTest/> Multiplication Test int64_t and uint64_t :\n");
#endif
	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		MUL_TEST_SU64_SPIKE_C(op1_64s,op2_64u,rslt_64s_lo,rslt_64s_hi,result_64s_tb_lo,result_64s_tb_hi,testnumber);
		PRINT_RESULT_SU64(op1_64s,op2_64u,result_64s_tb_lo,rslt_64s_lo,result_64s_tb_hi,rslt_64s_hi,testnumber,int64_t&uint64_t);
#else
		MUL_TEST_SU64_C(MAILBOX1,op1_64s,op2_64u,rslt_64s_lo,rslt_64s_hi,testnumber);
#endif
	}


testtypenum++ ;


	mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);
    
    return 0;


}
