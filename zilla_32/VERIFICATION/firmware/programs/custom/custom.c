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
** Tests custom instruction added to zilla and toolchain
**
*******************************************************************************
*/

#include <stdio.h>
#include "custom.h"
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
#include "data.h"

#define TEST_ONLY    (1)
#define TEST_COUNT    (2)


volatile int status =  0;    /* test case status */
volatile int testnumber    =  1;
volatile int testtypenum   = -1;

#define DATA_SET         (3)    /*!< op1, op2, result       */
#define TEST_TYPES      (16)    /*!< 16 instructions        */

/* Array to store the operand1, operand2 and actual result */
int64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};
	
/* Function prototypes */
//int print_test_results_R(uint64_t tn, uint64_t o1, uint64_t o2, uint64_t r, uint64_t e_r);
//int print_test_results_I(uint64_t tn, uint64_t o1, uint64_t o2, uint64_t r, uint64_t e_r);
//int print_test_results_U(uint64_t tn, uint64_t o1, uint64_t r, uint64_t e_r);

#include "ui_cust_test.h"
/* Main function */
int main(int argc, char *argv[])
{
    	/* Note: The I-Type and U-Type instruction test cases have op2ediate values which makes the 
		 test cases sem-automatic. The immediate values have to be passed as argument to macro
		 and write test cases with 2 parameters for the immediate value as shown in the test
		 cases. As of now, this is the solution since the macros do not permit to pass values
		 with double quaotes when we need the rvalue for immediate operand fields */


#ifdef SPIKE_RUN
	printf("\nTest/> Custom instruction test:\n");
#endif

	/*********************************** IN-LINE ASSEMBLY INSTRUCTIONS ********************************************/

	/*********************************** Custom zilla instruction : z.cgt ********************************************/

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

 //8 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 8bit : z.cgt");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R8_SPIKE(z.cgt, op1, op2, result, exp_result, testnumber);
		print_test_results_cgt(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R8(MAILBOX1, z.cgt, op1, op2, result, testnumber);
#endif
	}
  
   //16 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 16bit : z.cgt");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R16_SPIKE(z.cgt, op1, op2, result, exp_result, testnumber);
		print_test_results_cgt(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R16(MAILBOX1, z.cgt, op1, op2, result, testnumber);
#endif
	}
 //32 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 32bit : z.cgt");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R32_SPIKE(z.cgt, op1, op2, result, exp_result, testnumber);
		print_test_results_cgt(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R32(MAILBOX1, z.cgt, op1, op2, result, testnumber);
#endif
	}    
    
    //64 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit : z.cgt");
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


	/*********************************** Custom zilla instruction : z.cgte ********************************************/

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

 //8 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 8bit : z.cgte");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R8_SPIKE(z.cgte, op1, op2, result, exp_result, testnumber);
		print_test_results_cgte(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R8(MAILBOX1, z.cgte, op1, op2, result, testnumber);
#endif
	}
  
   //16 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 16bit : z.cgte");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R16_SPIKE(z.cgte, op1, op2, result, exp_result, testnumber);
		print_test_results_cgte(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R16(MAILBOX1, z.cgte, op1, op2, result, testnumber);
#endif
	}
 //32 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 32bit : z.cgte");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R32_SPIKE(z.cgte, op1, op2, result, exp_result, testnumber);
		print_test_results_cgte(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R32(MAILBOX1, z.cgte, op1, op2, result, testnumber);
#endif
	}    
    
    //64 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit : z.cgte");
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



	/*********************************** Custom zilla instruction : z.cgtu ********************************************/

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

 //8 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 8bit : z.cgtu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R8_SPIKE_U(z.cgtu, op1, op2, result, exp_result, testnumber);
		print_test_results_cgtu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R8_U(MAILBOX1, z.cgtu, op1, op2, result, testnumber);
#endif
	}
  
   //16 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 16bit : z.cgtu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R16_SPIKE_U(z.cgtu, op1, op2, result, exp_result, testnumber);
		print_test_results_cgtu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R16_U(MAILBOX1, z.cgtu, op1, op2, result, testnumber);
#endif
	}
 //32 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 32bit : z.cgtu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R32_SPIKE_U(z.cgtu, op1, op2, result, exp_result, testnumber);
		print_test_results_cgtu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R32_U(MAILBOX1, z.cgtu, op1, op2, result, testnumber);
#endif
	}    
    
    //64 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit : z.cgtu");
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

	/*********************************** Custom zilla instruction : z.cgteu ********************************************/

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

 //8 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 8bit : z.cgteu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R8_SPIKE_U(z.cgteu, op1, op2, result, exp_result, testnumber);
		print_test_results_cgteu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R8_U(MAILBOX1, z.cgteu, op1, op2, result, testnumber);
#endif
	}
  
   //16 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 16bit : z.cgteu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R16_SPIKE_U(z.cgteu, op1, op2, result, exp_result, testnumber);
		print_test_results_cgteu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R16_U(MAILBOX1,z.cgteu, op1, op2, result, testnumber);
#endif
	}
 //32 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 32bit : z.cgteu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R32_SPIKE_U(z.cgteu, op1, op2, result, exp_result, testnumber);
		print_test_results_cgteu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R32_U(MAILBOX1, z.cgteu, op1, op2, result, testnumber);
#endif
	}    
    
    //64 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit : z.cgteu");
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


	/*********************************** Custom zilla instruction : z.clt ********************************************/

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

 //8 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 8bit : z.clt");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R8_SPIKE( z.clt, op1, op2, result, exp_result, testnumber);
		print_test_results_clt(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R8(MAILBOX1, z.clt, op1, op2, result, testnumber);
#endif
	}
  
   //16 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 16bit : z.clt");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R16_SPIKE( z.clt, op1, op2, result, exp_result, testnumber);
		print_test_results_clt(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R16(MAILBOX1, z.clt, op1, op2, result, testnumber);
#endif
	}
 //32 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 32bit :  z.clt");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R32_SPIKE( z.clt, op1, op2, result, exp_result, testnumber);
		print_test_results_clt(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R32(MAILBOX1, z.clt, op1, op2, result, testnumber);
#endif
	}    
    
    //64 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit :  z.clt");
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

	/*********************************** Custom zilla instruction : z.clte ********************************************/

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
 //8 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 8bit :z.clte");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R8_SPIKE(z.clte, op1, op2, result, exp_result, testnumber);
		print_test_results_clte(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R8(MAILBOX1,z.clte, op1, op2, result, testnumber);
#endif
	}
  
   //16 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 16bit : z.clte");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R16_SPIKE(z.clte, op1, op2, result, exp_result, testnumber);
		print_test_results_clte(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R16(MAILBOX1, z.clte, op1, op2, result, testnumber);
#endif
	}
 //32 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 32bit :z.clte");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R32_SPIKE(z.clte, op1, op2, result, exp_result, testnumber);
		print_test_results_clte(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R32(MAILBOX1, z.clte, op1, op2, result, testnumber);
#endif
	}    
    
    //64 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit :z.clte");
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
	/*********************************** Custom zilla instruction : z.cltu ********************************************/

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
 //8 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 8bit :z.cltu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R8_SPIKE_U(z.cltu, op1, op2, result, exp_result, testnumber);
		print_test_results_cltu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R8_U(MAILBOX1,z.cltu, op1, op2, result, testnumber);
#endif
	}
  
   //16 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 16bit : z.cltu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R16_SPIKE_U(z.cltu, op1, op2, result, exp_result, testnumber);
		print_test_results_cltu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R16_U(MAILBOX1, z.cltu, op1, op2, result, testnumber);
#endif
	}
 //32 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 32bit :z.cltu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R32_SPIKE_U(z.cltu, op1, op2, result, exp_result, testnumber);
		print_test_results_cltu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R32_U(MAILBOX1, z.cltu, op1, op2, result, testnumber);
#endif
	}    
    
    //64 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit :z.cltu");
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
	/*********************************** Custom zilla instruction : z.clteu ********************************************/

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

 //8 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 8bit : z.clteu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R8_SPIKE_U(z.clteu, op1, op2, result, exp_result, testnumber);
		print_test_results_clteu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R8_U(MAILBOX1, z.clteu, op1, op2, result, testnumber);
#endif
	}
  
   //16 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 16bit : z.clteu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R16_SPIKE_U(z.clteu, op1, op2, result, exp_result, testnumber);
		print_test_results_clteu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R16_U(MAILBOX1,z.clteu, op1, op2, result, testnumber);
#endif
	}
 //32 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 32bit :z.clteu");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R32_SPIKE_U(z.clteu, op1, op2, result, exp_result, testnumber);
		print_test_results_clteu(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R32_U(MAILBOX1, z.clteu, op1, op2, result, testnumber);
#endif
	}    
    
    //64 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit :z.clteu");
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

	/*********************************** Custom zilla instruction : z.ceq ********************************************/

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

 //8 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 8bit :  z.ceq ");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R8_SPIKE( z.ceq , op1, op2, result, exp_result, testnumber);
		print_test_results_ceq(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R8(MAILBOX1,  z.ceq , op1, op2, result, testnumber);
#endif
	}
  
   //16 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 16bit :  z.ceq ");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R16_SPIKE( z.ceq , op1, op2, result, exp_result, testnumber);
		print_test_results_ceq(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R16(MAILBOX1,  z.ceq , op1, op2, result, testnumber);
#endif
	}
 //32 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 32bit :  z.ceq ");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R32_SPIKE( z.ceq , op1, op2, result, exp_result, testnumber);
		print_test_results_ceq(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R32(MAILBOX1,  z.ceq , op1, op2, result, testnumber);
#endif
	}    
    
    //64 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit : z.ceq ");
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

	/*********************************** Custom zilla instruction : z.cne ********************************************/

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */
 //8 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 8bit : z.cne");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R8_SPIKE(z.cne, op1, op2, result, exp_result, testnumber);
		print_test_results_cne(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R8(MAILBOX1, z.cne, op1, op2, result, testnumber);
#endif
	}
  
   //16 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 16bit : z.cne");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R16_SPIKE(z.cne, op1, op2, result, exp_result, testnumber);
		print_test_results_cne(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R16(MAILBOX1,z.cne, op1, op2, result, testnumber);
#endif
	}
 //32 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 32bit : z.cne");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R32_SPIKE(z.cne, op1, op2, result, exp_result, testnumber);
		print_test_results_cne(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R32(MAILBOX1,z.cne, op1, op2, result, testnumber);
#endif
	}    
    
    //64 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit :z.cne");
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
  

	/*********************************** Custom zilla instruction : z.rol ********************************************/

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
             for comparison */

 // 8 bit//
    #ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 8bit : z.rol");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R8_SPIKE(z.rol, op1, op2, result, exp_result, testnumber);
	    print_test_results_rol(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R8(MAILBOX1, z.rol, op1, op2, result, testnumber);
#endif
	}

  // 8 bit unsigned//
    #ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 8bit unsigned : z.rol");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R8_SPIKE_U(z.rol, op1, op2, result, exp_result, testnumber);
	    print_test_results_rol_u(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R8_U(MAILBOX1, z.rol, op1, op2, result, testnumber);
#endif
	}


// 16 bit//
    #ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 16bit : z.rol");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R16_SPIKE(z.rol, op1, op2, result, exp_result, testnumber);
	    print_test_results_rol(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R16(MAILBOX1, z.rol, op1, op2, result, testnumber);
#endif
	}

    
// 16 bit unsigned//
    #ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 16bit unsigned : z.rol");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R16_SPIKE_U(z.rol, op1, op2, result, exp_result, testnumber);
	    print_test_results_rol_u(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R16_U(MAILBOX1, z.rol, op1, op2, result, testnumber);
#endif
	}

     // 32 bit//
    #ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 32bit : z.rol");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R32_SPIKE(z.rol, op1, op2, result, exp_result, testnumber);
	    print_test_results_rol(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R32(MAILBOX1, z.rol, op1, op2, result, testnumber);
#endif
	}

     // 32 bit unsigned//
    #ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 32bit unsigned : z.rol");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R32_SPIKE_U(z.rol, op1, op2, result, exp_result, testnumber);
	    print_test_results_rol_u(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R32_U(MAILBOX1, z.rol, op1, op2, result, testnumber);
#endif
	}

//64 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit: z.rol");
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
	printf("\nTest/> Instruction 64bit unsigned: z.rol");
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






	/*********************************** Custom zilla instruction : z.ror ********************************************/

        /* Note: UVM TestBench generates data.h file with operand1, operand2 and actual result (when run without SPIKE).
                 Then the result is taken as "Actual" result and the spike simulation generates the "Expected" result
                 for comparison */

  //8 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 8bit : z.ror");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R8_SPIKE(z.ror, op1, op2, result, exp_result, testnumber);
		print_test_results_ror(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R8(MAILBOX1, z.ror, op1, op2, result, testnumber);
#endif
	}

    
  //8 bit unsigned//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 8bit unsigned : z.ror");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R8_SPIKE_U(z.ror, op1, op2, result, exp_result, testnumber);
		print_test_results_ror_u(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R8_U(MAILBOX1, z.ror, op1, op2, result, testnumber);
#endif
	}
  

  
   //16 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 16bit : z.ror");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R16_SPIKE(z.ror, op1, op2, result, exp_result, testnumber);
		print_test_results_ror(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R16(MAILBOX1, z.ror, op1, op2, result, testnumber);
#endif
	}
  
   //16 bit unsigned//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 16bit unsigned : z.ror");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R16_SPIKE_U(z.ror, op1, op2, result, exp_result, testnumber);
		print_test_results_ror_u(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R16_U(MAILBOX1, z.ror, op1, op2, result, testnumber);
#endif
	}

 //32 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 32bit : z.ror");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R32_SPIKE(z.ror, op1, op2, result, exp_result, testnumber);
		print_test_results_ror(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R32(MAILBOX1, z.ror, op1, op2, result, testnumber);
#endif
	}  

 //32 bit unsigned//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 32bit unsigned : z.ror");
	printf("\n------------------------------\n");
#endif
	testtypenum++;
	for(testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
#ifdef SPIKE_RUN	
		TEST_CUSTOM_INSN_R32_SPIKE_U(z.ror, op1, op2, result, exp_result, testnumber);
		print_test_results_ror_u(testnumber, op1, op2, result, exp_result);
#else
		TEST_CUSTOM_INSN_R32_U(MAILBOX1, z.ror, op1, op2, result, testnumber);
#endif
	}    

    //64 bit//
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64bit : z.ror");
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
	printf("\nTest/> Instruction 64bit unsigned : z.ror");
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



  //test_ui_type(void)  
  test_ui_custom_type();


    	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);

return 0;
}	

