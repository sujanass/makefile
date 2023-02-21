/*
**
*******************************************************************************
**
** Header file for creating I-Type and U-Type tests
**
** Usage : #include "ui_test.h"
*******************************************************************************
*/

#ifndef UI_TEST_H
#define UI_TEST_H

#ifdef SPIKE_RUN
#include "data.h"               /*!< Testbench created data */
#endif


void test_ui_type(void)
{
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 64 bit: addi");
	printf("\n------------------------------\n");
#endif
volatile int testnumber=1; 
#ifdef SPIKE_RUN
{	TEST_ADDI_INSN_I_SPIKE(addi, op1, 1, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDI_INSN_I_SPIKE(addi, op1, 25, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDI_INSN_I_SPIKE(addi, op1, 49, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDI_INSN_I_SPIKE(addi, op1, 42, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDI_INSN_I_SPIKE(addi, op1, 14, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDI_INSN_I_SPIKE(addi, op1, 48, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDI_INSN_I_SPIKE(addi, op1, 4, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDI_INSN_I_SPIKE(addi, op1, 7, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDI_INSN_I_SPIKE(addi, op1, 11, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDI_INSN_I_SPIKE(addi, op1, 48, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDI_INSN_I_SPIKE(addi, op1, 61, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDI_INSN_I_SPIKE(addi, op1, 46, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDI_INSN_I_SPIKE(addi, op1, 52, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDI_INSN_I_SPIKE(addi, op1, 53, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDI_INSN_I_SPIKE(addi, op1, 26, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
#else
{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, 1, result, testnumber);}
	testnumber++;
{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, 25, result, testnumber);}
	testnumber++;
{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, 49, result, testnumber);}
	testnumber++;
{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, 42, result, testnumber);}
	testnumber++;
{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, 14, result, testnumber);}
	testnumber++;
{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, 48, result, testnumber);}
	testnumber++;
{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, 4, result, testnumber);}
	testnumber++;
{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, 7, result, testnumber);}
	testnumber++;
{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, 11, result, testnumber);}
	testnumber++;
{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, 48, result, testnumber);}
	testnumber++;
{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, 61, result, testnumber);}
	testnumber++;
{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, 46, result, testnumber);}
	testnumber++;
{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, 52, result, testnumber);}
	testnumber++;
{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, 53, result, testnumber);}
	testnumber++;
{	TEST_ADDI_INSN_I(MAILBOX1, addi, op1, 26, result, testnumber);}
	testnumber++;
#endif
#ifdef SPIKE_RUN
	printf("\n------------------------------");
	printf("\nTest/> Instruction 32 bit: addiw");
	printf("\n------------------------------\n");
#endif
#ifdef SPIKE_RUN
{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, 18, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, 20, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, 5, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, 10, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, 5, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, 15, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, 9, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, 26, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, 15, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, 17, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, 26, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, 27, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, 30, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, 24, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
{	TEST_ADDIW_INSN_I_SPIKE(addi, op1, 15, result, exp_result, testnumber);
	print_test_results_I(testnumber, op1, op2, result, exp_result);} 
	testnumber++;
#else
{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, 18, result, testnumber);}
	testnumber++;
{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, 20, result, testnumber);}
	testnumber++;
{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, 5, result, testnumber);}
	testnumber++;
{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, 10, result, testnumber);}
	testnumber++;
{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, 5, result, testnumber);}
	testnumber++;
{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, 15, result, testnumber);}
	testnumber++;
{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, 9, result, testnumber);}
	testnumber++;
{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, 26, result, testnumber);}
	testnumber++;
{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, 15, result, testnumber);}
	testnumber++;
{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, 17, result, testnumber);}
	testnumber++;
{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, 26, result, testnumber);}
	testnumber++;
{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, 27, result, testnumber);}
	testnumber++;
{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, 30, result, testnumber);}
	testnumber++;
{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, 24, result, testnumber);}
	testnumber++;
{	TEST_ADDIW_INSN_I(MAILBOX1, addi, op1, 15, result, testnumber);}
	testnumber++;
#endif
}

#endif /* UI_TEST_H */
