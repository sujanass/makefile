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
/***********************************************************************************
 **************                                                       **************
 **************     Shift Right Arithmetic Operation for Zilla_Core   **************
 **************                                                       **************
 ***********************************************************************************/

#include <stdio.h>      //  Standard Input Output
#include <stdlib.h>     //  Standard Library
#include <limits.h>     //  Datatype Limit
#include <stdint.h>     //  Standard Integer Type
#include "print.h"      //  Mailbox Print Library
#include "linker.h"     //  Linker Symbols Library
#include "mailbox.h"    //  Mailbox Access Library
#include "testmacro.h"  //  Test Macros


#ifdef SPIKE_RUN
#include "data.h"       //  stores entries of DATA created by Testbench
#endif

/*Note : TEST_COUNT indicates no.of times the testcase is performed
         e.g. The number of times uint8_t,int8_t...etc are performed.
*/

#define TEST_COUNT (5)  //  no.of times tests to be performed
#define DATA_SET   (3)  //  no.of operands needed to perform the operation (op1,op2,rslt)
#define TEST_TYPES (8)  //  types of testcases applied e.g.uint8_t,int8_t,.....int64_t etc.




//Minimum and Maximum Values defined for Signed and Unsigned Integer
    #define UINT8_MIN  0 
    #define UINT16_MIN 0 
    #define UINT32_MIN 0 
    #define UINT64_MIN 0 

    #define UINT8_MAX 0xFF
    #define UINT16_MAX 0xFFFF
    #define UINT32_MAX 0xFFFFFFFF
    #define UINT64_MAX 0xFFFFFFFFFFFFFFFF

    #define INT8_MAX 0x7F
    #define INT16_MAX 0x7FFF
    #define INT32_MAX 0x7FFFFFFF
    #define INT64_MAX 0x7FFFFFFFFFFFFFFF
    #define INT32_MIN 0x80000000
    
   /* #define UINT8_MIN 0
    #define UINT8_MAX 0xFF                 //(Max = 255 in Decimal)
    #define UINT16_MIN 0
    #define UINT16_MAX 0xFFFF              //(Max = 65535 in Decimal)
    #define UINT32_MIN 0
    #define UINT32_MAX 0xFFFFFFFF           //(Max = 4294967295 in Decimal)
    #define UINT64_MIN 0
    #define UINT64_MAX 0xFFFFFFFFFFFFFFFF   //(Max = 18446744073709551615 in Decimal)

    #define INT8_MAX  0x7F
    #define INT16_MAX 0x7FFF
    #define INT32_MAX 0x7FFFFFFF
    #define INT64_MAX 0x7FFFFFFFFFFFFFFF
    #define INT32_MIN 0x80000000
*/

//Array to store the op1,op2 and actual_result
uint64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,}; 

//Include ui_sra_test.h header file here for I-type n U-type Instruction (Should be declared only after actual_result)
#include "ui_sra_test.h"


//Main Function starts from here
int main(void)
{
    //Test Case Status
    volatile int testnumber  = 1;
    volatile int testtypenum = 0;
    
    int num_of_elements_memdump;

    //num_of_elements_memdump =    (Test 1)         +     ( Test 2)      +      (Test 3)      +    (Test 4)
    //                             (C Test)         +   Assembly Test)   + (Min and Max Test) + (Assembly Compliance Test)  + (SRA/SRAW Imm Test)  + (SRA/SRAW Imm Min & Max)
    num_of_elements_memdump   =   (TEST_COUNT*3*8)  +  (TEST_COUNT*3*8)  + (TEST_COUNT*3*16)  +      (3*10) +                  (TEST_COUNT*3*8)    +        (3*16);



    /*************************************************************************************************************************
    ////////                          PART 1 : C-Code for Shift Right Arithmetic Operation                           ////////
    *************************************************************************************************************************/
   
    #ifdef SPIKE_RUN
	    printf ("\n-------------------------------------------------------\n");
        printf ("\n Test/ > C-Code for Shift Right Arithmetic Operation : \n");
        printf ("\n------------------------------------------------------ \n");
    #endif

    //*************     SRAW Test for uint8_t integer    ******************
    #ifdef SPIKE_RUN
        printf ("\n Test/ > SRAW Test for uint8_t integer : \n");
        printf ("\n ---------------------------------------\n");
    #endif

    for(testnumber=1; testnumber <= TEST_COUNT; testnumber++)
    {
        #ifdef SPIKE_RUN
            SRAW_TEST_U8_SPIKE_C(op1_8u,op2_8u,result_8u_full,result_8u_tb,testnumber);
            SRAW_PRINT_RESULT_U(op1_8u,op2_8u,result_8u_tb,result_8u_full,testnumber,uint8_t);
        #else
            SRAW_TEST_U8_C(MAILBOX1,op1_8u,op2_8u,result_8u_full,testnumber);
        #endif
    }

    //*************     SRAW Test for int8_t integer     ********************
    #ifdef SPIKE_RUN
        printf ("\n Test/ > SRAW Test for int8_t integer : \n");
        printf ("\n --------------------------------------\n");
    #endif 

    testtypenum++;

    for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
        #ifdef SPIKE_RUN	
		    SRAW_TEST_S8_SPIKE_C(op1_8s,op2_8s,result_8s_full,result_8s_tb,testnumber);
		    SRAW_PRINT_RESULT_S(op1_8s,op2_8s,result_8s_tb,result_8s_full,testnumber,int8_t);
		#else         
		    SRAW_TEST_S8_C(MAILBOX1,op1_8s,op2_8s,result_8s_full,testnumber);
        #endif
    }

    //*************     SRAW Test for uint16_t integer     ********************    
    #ifdef SPIKE_RUN
        printf ("\n Test/ > SRAW Test for uint16_t integer : \n");
        printf ("\n ----------------------------------------\n");
    #endif
        
    testtypenum++;

    for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
        #ifdef SPIKE_RUN	
		    SRAW_TEST_U16_SPIKE_C(op1_16u,op2_16u,result_16u_full,result_16u_tb,testnumber);
		    SRAW_PRINT_RESULT_U(op1_16u,op2_16u,result_16u_tb,result_16u_full,testnumber,uint16_t);
        #else         
		    SRAW_TEST_U16_C(MAILBOX1,op1_16u,op2_16u,result_16u_full,testnumber);
        #endif
    }
    
    //**************   SRAW Test for int16_t    *************************    
    #ifdef SPIKE_RUN
	    printf ("\n Test/ > SRAW Test for int16_t  : \n");
        printf ("\n --------------------------------\n");
    #endif

	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
        #ifdef SPIKE_RUN		
		    SRAW_TEST_S16_SPIKE_C(op1_16s,op2_16s,result_16s_full,result_16s_tb,testnumber);
		    SRAW_PRINT_RESULT_S(op1_16s,op2_16s,result_16s_tb,result_16s_full,testnumber,int16_t);
        #else
		    SRAW_TEST_S16_C(MAILBOX1,op1_16s,op2_16s,result_16s_full,testnumber);
        #endif
	}

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

    /**********************************************************************************************************************                                                              
    /////                             PART 2 : Assembly Code for Shift Right Arithmetic Operation                    //////
    **********************************************************************************************************************/

    #ifdef SPIKE_RUN
	    printf("\n-------------------------------------------------------------\n");
	    printf("\n Test/ > Assembly Code for Shift Right Arithmetic Operation :\n");
	    printf("\n-------------------------------------------------------------\n");
    #endif

    //*************     SRAW Test for uint8_t integer    ****************
    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRAW Test for uint8_t integer : \n");
        printf("\n ---------------------------------------\n");
    #endif
        
    testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)   
	{
        #ifdef SPIKE_RUN		
		    SRAW_TEST_U8_SPIKE(op1_8u,op2_8u,result_8u_full,result_8u_tb,testnumber);    
		    SRAW_PRINT_RESULT_U(op1_8u,op2_8u,result_8u_tb,result_8u_full,testnumber,uint8_t);  
        #else
		    SRAW_TEST_U8(MAILBOX1,op1_8u,op2_8u,result_8u_full,testnumber);        
        #endif
     }

    //**************       SRAW Test for int8_t          ******************
    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRAW Test for int8_t  : \n");
        printf("\n -------------------------------\n");
    #endif

	testtypenum++;
	
	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
        #ifdef SPIKE_RUN	
		    SRAW_TEST_S8_SPIKE(op1_8s,op2_8s,result_8s_full,result_8s_tb,testnumber);
		    SRAW_PRINT_RESULT_S(op1_8s,op2_8s,result_8s_tb,result_8s_full,testnumber,int8_t);
        #else
		    SRAW_TEST_S8(MAILBOX1,op1_8s,op2_8s,result_8s_full,testnumber);
        #endif
	}

    //**************         SRAW Test for uint16_t        ************************
    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRAW Test for uint16_t : \n");
        printf("\n --------------------------------\n");
    #endif
	
    testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
        #ifdef SPIKE_RUN		
		    SRAW_TEST_U16_SPIKE(op1_16u,op2_16u,result_16u_full,result_16u_tb,testnumber);
		    SRAW_PRINT_RESULT_U(op1_16u,op2_16u,result_16u_tb,result_16u_full,testnumber,uint16_t);       
        #else
		    SRAW_TEST_U16(MAILBOX1,op1_16u,op2_16u,result_16u_full,testnumber);
        #endif
	}

    //**************         SRAW Test for int16_t    *********************
    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRAW Test for int16_t  : \n");
        printf("\n --------------------------------\n");
    #endif

	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
        #ifdef SPIKE_RUN		
		    SRAW_TEST_S16_SPIKE(op1_16s,op2_16s,result_16s_full,result_16s_tb,testnumber);
		    SRAW_PRINT_RESULT_S(op1_16s,op2_16s,result_16s_tb,result_16s_full,testnumber,int16_t);        
        #else
		    SRAW_TEST_S16(MAILBOX1,op1_16s,op2_16s,result_16s_full,testnumber);
        #endif
	}

    //*****************    SRAW Test for uint32_t        *********************
    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRAW Test for uint32_t : \n");
        printf("\n --------------------------------\n");
    #endif

	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
        #ifdef SPIKE_RUN	
		    SRAW_TEST_U32_SPIKE(op1_32u,op2_32u,result_32u_full,result_32u_tb,testnumber);
		    SRAW_PRINT_RESULT_U(op1_32u,op2_32u,result_32u_tb,result_32u_full,testnumber,uint32_t);       
        #else
		    SRAW_TEST_U32(MAILBOX1,op1_32u,op2_32u,result_32u_full,testnumber);            
        #endif
	}

    //***************           SRAW Test for int32_t         ****************
    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRAW Test for int32_t  : \n");
        printf("\n --------------------------------\n");
    #endif

	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
        #ifdef SPIKE_RUN	
		    SRAW_TEST_S32_SPIKE(op1_32s,op2_32s,result_32s_full,result_32s_tb,testnumber);
		    SRAW_PRINT_RESULT_S(op1_32s,op2_32s,result_32s_tb,result_32s_full,testnumber,int32_t);
        #else
		    SRAW_TEST_S32(MAILBOX1,op1_32s,op2_32s,result_32s_full,testnumber);
        #endif
	}

    //**************       SRA Test for uint64_t             *****************
    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRA Test for uint64_t : \n");
        printf("\n ---------------------------------\n");
    #endif

	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
        #ifdef SPIKE_RUN	
		    SRA_TEST_U64_SPIKE(op1_64u,op2_64u,result_64u_full,result_64u_tb,testnumber);
		    SRA_PRINT_RESULT_U(op1_64u,op2_64u,result_64u_tb,result_64u_full,testnumber,uint64_t);
        #else
		    SRA_TEST_U64(MAILBOX1,op1_64u,op2_64u,result_64u_full,testnumber);
        #endif
	}

    //***************      SRA Test for int64_t     ****************
    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRA Test for int64_t  : \n");        
        printf("\n ---------------------------------\n");
    #endif

	testtypenum++;

	for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
        #ifdef SPIKE_RUN	
		    SRA_TEST_S64_SPIKE(op1_64s,op2_64s,result_64s_full,result_64s_tb,testnumber);
		    SRA_PRINT_RESULT_S(op1_64s,op2_64s,result_64s_tb,result_64s_full,testnumber,int64_t);
        #else
		    SRA_TEST_S64(MAILBOX1,op1_64s,op2_64s,result_64s_full,testnumber);
        #endif
	}


    /********************************************************************************************************************
    //////              PART 3 : RISC Compliance Assembly Test for Shift Right Arithmetic Operation               ///////
    ********************************************************************************************************************/                                                                                

    #ifdef SPIKE_RUN
        printf("\n-------------------------------------------------------------------------------------\n");
        printf("\n Test/ > RISC Compliance Test Assembly Code for Arithmetic Shift Right operation :   \n");
        printf("\n-------------------------------------------------------------------------------------\n");
    #endif

    //************     TEST_RR_SRC1_EQ_DEST Shift Right Arithmetic operation for uint8_t     **********

    #ifdef SPIKE_RUN
        printf("\n Test/ >  SRC1_EQ_DEST Shift Right Arithmetic Test for uint8_t : \n");
        printf("\n---------------------------------------------------------------------\n");
    #endif

    testtypenum++;

    for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
    {
        #ifdef SPIKE_RUN	
            SRAW_TEST_U8SRC1_EQ_DEST_SPIKE(op1_8u,op2_8u,result_full,result_tb,testnumber);
            SRAW_PRINT_RESULT_U(op1_8u,op2_8u,result_tb,result_full,testnumber,uint8_t);
        #else
   	        SRAW_TEST_U8SRC1_EQ_DEST(MAILBOX1,op1_8u,op2_8u,result_full,testnumber);
        #endif
    }

    //***********    TEST_RR_SRC2_EQ_DEST Shift Right Arithmetic Test for uint8_t    ***********
    
    #ifdef SPIKE_RUN
        printf("\n Test/ > SRC2_EQ_DEST Shift Right Arithmetic Test for uint8_t : \n");
        printf("\n---------------------------------------------------------------------\n");
    #endif

    testtypenum++;

    for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
    {
        #ifdef SPIKE_RUN	
   	        SRAW_TEST_U8SRC2_EQ_DEST_SPIKE(op1_8u,op2_8u,result_full,result_tb,testnumber);
   	        SRAW_PRINT_RESULT_U(op1_8u,op2_8u,result_tb,result_full,testnumber,uint8_t);
        #else
   	        SRAW_TEST_U8SRC2_EQ_DEST(MAILBOX1,op1_8u,op2_8u,result_full,testnumber);
        #endif
    }

    //***********  TEST_RR_SRC12_EQ_DEST Shift Right Arithmetic Test for uint8_t *******************************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > SRC12_EQ_DEST Shift Right Arithmetic Test for uint8_t : \n");
        printf("\n---------------------------------------------------------------------\n");
    #endif

    testtypenum++;

    for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
    {
        #ifdef SPIKE_RUN	
   	        SRAW_TEST_U8SRC12_EQ_DEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	        SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);       
        #else
   	        SRAW_TEST_U8SRC12_EQ_DEST(MAILBOX1,op1,op2,result_full,testnumber);
        #endif
    }

    //***********    TEST_RR_ZEROSRC1 Shift Right Arithmetic Test for uint8_t      ***************

    #ifdef SPIKE_RUN
        printf("\n Test/> ZEROSRC1 Shift Right Arithmetic Test for uint8_t : \n");
        printf("\n---------------------------------------------------------------------\n");
    #endif

    testtypenum++;
       
    for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
    {
        #ifdef SPIKE_RUN	
   	        SRAW_TEST_U8ZEROSRC1_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	        SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);      
        #else
   	        SRAW_TEST_U8ZEROSRC1(MAILBOX1,op1,op2,result_full,testnumber);  
        #endif
    }

    //**********      TEST_RR_ZEROSRC2 Shift Right Arithmetic Test for uint8_t    **************

    #ifdef SPIKE_RUN
        printf("\n Test/> ZEROSRC2 Shift Right Arithmetic Test for uint8_t : \n");
        printf("\n---------------------------------------------------------------------\n");

    #endif

    testtypenum++;
       
    for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
    {
        #ifdef SPIKE_RUN	
   	        SRAW_TEST_U8ZEROSRC2_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	        SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
        #else
   	        SRAW_TEST_U8ZEROSRC2(MAILBOX1,op1,op2,result_full,testnumber);
        #endif
    }

    //**********     TEST_RR_ZEROSRC12 Shift Right Arithmetic Test for uint8_t      ***********

    #ifdef SPIKE_RUN
        printf("\n Test/> ZEROSRC12 Shift Right Arithmetic Test for uint8_t : \n");
        printf("\n---------------------------------------------------------------------\n");
    #endif

    testtypenum++;
   
    for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
    {
        #ifdef SPIKE_RUN	
   	        SRAW_TEST_U8ZEROSRC12_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	        SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
        #else
   	        SRAW_TEST_U8ZEROSRC12(MAILBOX1,op1,op2,result_full,testnumber);
        #endif
    }
    
    //**************      TEST_RR_ZERODEST Shift Right Arithmetic Test for uint8_t     ***********

    #ifdef SPIKE_RUN
        printf("\n Test/> ZERODEST Shift Right Arithmetic Test for uint8_t : \n");
        printf("\n---------------------------------------------------------------------\n");
    #endif

    testtypenum++;
   
    for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
    {
        #ifdef SPIKE_RUN	
   	        SRAW_TEST_U8ZERODEST_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	        SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
        #else
   	        SRAW_TEST_U8ZERODEST(MAILBOX1,op1,op2,result_full,testnumber);
        #endif
    }

    //***************     TEST_RR_DEST_BYPASS Shift Right Arithmetic Test for uint8_t       **********
   
    #ifdef SPIKE_RUN
        printf("\nTest/> DEST_BYPASS Shift Right Arithmetic Test for uint8_t : \n");
        printf("\n---------------------------------------------------------------------\n");
    #endif

    testtypenum++;
      
    for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
    {
        #ifdef SPIKE_RUN	
   	        SRAW_TEST_U8DEST_BYPASS_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	        SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
        #else
   	        SRAW_TEST_U8DEST_BYPASS(MAILBOX1,op1,op2,result_full,testnumber);
        #endif	
    }
    
    //************     TEST_RR_SRC12_BYPASS Shift Right Arithmetic Test for uint8_t     *********
    
    #ifdef SPIKE_RUN
        printf("\nTest/> SRC12_BYPASS Shift Right Arithmetic Test for uint8_t : \n");
        printf("\n---------------------------------------------------------------------\n");
    #endif

    testtypenum++;

    for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
    {
        #ifdef SPIKE_RUN	
   	        SRAW_TEST_U8SRC12_BYPASS_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	        SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
        #else
   	        SRAW_TEST_U8SRC12_BYPASS(MAILBOX1,op1,op2,result_full,testnumber);
        #endif
    }
    
    //********     TEST_RR_SRC21_BYPASS Shift Right Arithmetic Test for uint8_t     **********
    
    #ifdef SPIKE_RUN
        printf("\n Test/ > SRC21_BYPASS Shift Right Arithmetic Test for uint8_t : \n");
        printf("\n---------------------------------------------------------------------\n");
    #endif

    testtypenum++;
       
    for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
    {
        #ifdef SPIKE_RUN	
   	        SRAW_TEST_U8SRC21_BYPASS_SPIKE(op1,op2,result_full,result_tb,testnumber);
   	        SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
        #else
   	        SRAW_TEST_U8SRC21_BYPASS(MAILBOX1,op1,op2,result_full,testnumber);
        #endif
    }

    /********************************************************************************************************************
    //////////                                       Min and Max Test Cases                                //////////////
    ********************************************************************************************************************/
    #ifdef SPIKE_RUN
        printf("\n -----------------------------------------------------------------------\n");
        printf("\n Test/ > Shift Right Arithmetic Operation Min Test and Max Test cases : \n");
        printf("\n -----------------------------------------------------------------------\n");
    #endif

    
    ///////////////////////////////        Max Test   //////////////////////////////////////////
    
    //******************         SRAW Max Test for uint8_t integer     **************************
    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Max Test for uint8_t integer :\n");
        printf("\n -------------------------------------------------------------\n");
    #endif
	
    testtypenum++;

    int k = 1+testtypenum*TEST_COUNT;	
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRAW_TEST_MAX_U8_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint8_t,uint8_t);
		    SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
        #else
		    SRAW_TEST_MAX_U8_C(MAILBOX1,op1,op2,result_full,testnumber,uint8_t,uint8_t,UINT8_MAX,8);
        #endif
    }
	k++;

    //******************         SRAW Max Test for int8_t integer     **************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Max Test for int8_t integer :\n");
        printf("\n ------------------------------------------------------------\n");
    #endif
	
    testtypenum++;
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRAW_TEST_MAX_S8_SPIKE_C(op1,op2,result_full,result_tb,testnumber,int8_t,uint8_t);
		    SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,int8_t);
        #else
		    SRAW_TEST_MAX_S8_C(MAILBOX1,op1,op2,result_full,testnumber,int8_t,uint8_t,INT8_MAX,8);
        #endif
    }
	k++;
    
    //******************         SRAW Max Test for uint16_t integer     **************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Max Test for uint16_t integer :\n");
        printf("\n --------------------------------------------------------------\n");
    #endif
	
    testtypenum++;
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRAW_TEST_MAX_U16_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint16_t,uint16_t);
		    SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint16_t);
        #else
		    SRAW_TEST_MAX_U16_C(MAILBOX1,op1,op2,result_full,testnumber,uint16_t,uint16_t,UINT16_MAX,16);
        #endif
    }
	k++;

    //******************         SRAW Max Test for int16_t integer     **************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Max Test for int16_t integer :\n");
        printf("\n -------------------------------------------------------------\n");
    #endif
	
    testtypenum++;
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRAW_TEST_MAX_S16_SPIKE_C(op1,op2,result_full,result_tb,testnumber,int16_t,uint16_t);
		    SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,int16_t);
        #else
		    SRAW_TEST_MAX_S16_C(MAILBOX1,op1,op2,result_full,testnumber,int16_t,uint16_t,INT16_MAX,16);
        #endif
    }
	k++;

    //******************         SRAW Max Test for uint32_t integer     **************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Max Test for uint32_t integer :\n");
        printf("\n --------------------------------------------------------------\n");
    #endif
	
    testtypenum++;
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRAW_TEST_MAX_U32_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint32_t,uint32_t);
		    SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint32_t);
        #else
		    SRAW_TEST_MAX_U32_C(MAILBOX1,op1,op2,result_full,testnumber,uint32_t,uint32_t,UINT32_MAX,31);
        #endif
    }
	k++;

    //******************         SRAW Max Test for int32_t integer     **************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Max Test for int32_t integer :\n");
        printf("\n -------------------------------------------------------------\n");
    #endif
	
    testtypenum++;
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRAW_TEST_MAX_S32_SPIKE_C(op1,op2,result_full,result_tb,testnumber,int32_t,uint32_t);
		    SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,int32_t);
        #else
		    SRAW_TEST_MAX_S32_C(MAILBOX1,op1,op2,result_full,testnumber,int32_t,uint32_t,INT32_MAX,31);
        #endif
    }
	k++;

    //******************         SRA Max Test for uint64_t integer     **************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Max Test for uint64_t integer :\n");
        printf("\n --------------------------------------------------------------\n");
    #endif
	
    testtypenum++;
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRA_TEST_MAX_U64_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint64_t,uint64_t);
		    SRA_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint64_t);
        #else
		    SRA_TEST_MAX_U64_C(MAILBOX1,op1,op2,result_full,testnumber,uint64_t,uint64_t,UINT64_MAX,63);
        #endif
    }
	k++;

    //******************         SRA Max Test for int64_t integer     **************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Max Test for int64_t integer :\n");
        printf("\n -------------------------------------------------------------\n");
    #endif
	
    testtypenum++;
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRA_TEST_MAX_S64_SPIKE_C(op1,op2,result_full,result_tb,testnumber,int64_t,uint64_t);
		    SRA_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,int64_t);
        #else
		    SRA_TEST_MAX_S64_C(MAILBOX1,op1,op2,result_full,testnumber,int64_t,uint64_t,INT64_MAX,63);
        #endif
    }
	k++;

    ////////////////////////////////////   Min Test   //////////////////////////////////////////
    
    //******************         SRAW Min Test for uint8_t integer     **************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Min Test for uint8_t integer :\n");
        printf("\n -------------------------------------------------------------\n");
    #endif
	
    testtypenum++;
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRAW_TEST_MIN_U8_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint8_t,uint8_t);
		    SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint8_t);
        #else
		    SRAW_TEST_MIN_U8_C(MAILBOX1,op1,op2,result_full,testnumber,uint8_t,uint8_t,UINT8_MIN,0);
        #endif
    }
	k++;

    //******************         SRAW Min Test for int8_t integer     **************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Min Test for int8_t integer :\n");
        printf("\n -------------------------------------------------------------\n");
    #endif
	
    testtypenum++;
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRAW_TEST_MIN_S8_SPIKE_C(op1,op2,result_full,result_tb,testnumber,int8_t,uint8_t);
		    SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,int8_t);
        #else
		    SRAW_TEST_MIN_S8_C(MAILBOX1,op1,op2,result_full,testnumber,int8_t,uint8_t,INT8_MIN,0);
        #endif
    }
	k++;
    
    //******************         SRAW Min Test for uint16_t integer     **************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Min Test for uint16_t integer :\n");
        printf("\n --------------------------------------------------------------\n");
    #endif
	
    testtypenum++;
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRAW_TEST_MIN_U16_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint16_t,uint16_t);
		    SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint16_t);
        #else
		    SRAW_TEST_MIN_U16_C(MAILBOX1,op1,op2,result_full,testnumber,uint16_t,uint16_t,UINT16_MIN,0);
        #endif
    }
	k++;

    //******************         SRAW Min Test for int16_t integer     **************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Min Test for int16_t integer :\n");
        printf("\n -------------------------------------------------------------\n");
    #endif
	
    testtypenum++;
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRAW_TEST_MIN_S16_SPIKE_C(op1,op2,result_full,result_tb,testnumber,int16_t,uint16_t);
		    SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,int16_t);
        #else
		    SRAW_TEST_MIN_S16_C(MAILBOX1,op1,op2,result_full,testnumber,int16_t,uint16_t,INT16_MIN,0);
        #endif
    }
	k++;

    //******************         SRAW Min Test for uint32_t integer     **************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Min Test for uint32_t integer :\n");
        printf("\n --------------------------------------------------------------\n");
    #endif
	
    testtypenum++;
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRAW_TEST_MIN_U32_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint32_t,uint32_t);
		    SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint32_t);
        #else
		    SRAW_TEST_MIN_U32_C(MAILBOX1,op1,op2,result_full,testnumber,uint32_t,uint32_t,UINT32_MIN,0);
        #endif
    }
	k++;

    //******************         SRAW Min Test for int32_t integer     **************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Min Test for int32_t integer :\n");
        printf("\n -------------------------------------------------------------\n");
    #endif
	
    testtypenum++;
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRAW_TEST_MIN_S32_SPIKE_C(op1,op2,result_full,result_tb,testnumber,int32_t,uint32_t);
		    SRAW_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,int32_t);
        #else
		    SRAW_TEST_MIN_S32_C(MAILBOX1,op1,op2,result_full,testnumber,int32_t,uint32_t,INT32_MIN,0);
        #endif
    }
	k++;

    //******************         SRAW Min Test for uint64_t integer     **************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Min Test for uint64_t integer :\n");
        printf("\n --------------------------------------------------------------\n");
    #endif
	
    testtypenum++;
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRA_TEST_MIN_U64_SPIKE_C(op1,op2,result_full,result_tb,testnumber,uint64_t,uint64_t);
		    SRA_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,uint64_t);
        #else
		    SRA_TEST_MIN_U64_C(MAILBOX1,op1,op2,result_full,testnumber,uint64_t,uint64_t,UINT64_MIN,0);
        #endif
    }
	k++;

    //******************         SRAW Min Test for int64_t integer     **************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Shift Right Arithmetic Min Test for int64_t integer :\n");
        printf("\n -------------------------------------------------------------\n");
    #endif
	
    testtypenum++;
        
	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    SRA_TEST_MIN_S64_SPIKE_C(op1,op2,result_full,result_tb,testnumber,int64_t,uint64_t);
		    SRA_PRINT_RESULT_U(op1,op2,result_tb,result_full,testnumber,int64_t);
        #else
		    SRA_TEST_MIN_S64_C(MAILBOX1,op1,op2,result_full,testnumber,int64_t,uint64_t,INT64_MIN,0);
        #endif
    }
	k++;

    /*******************************************************************************************************************
    //////////                            Immediate Shift Right Arithmetic Test Cases                     //////////////
    *******************************************************************************************************************/

    #ifdef SPIKE_RUN
        printf("\n ------------------------------------------------------\n");
        printf("\n Test/ > Shift Right Arithmetic Immediate Test cases : \n");
        printf("\n ------------------------------------------------------\n");
    #endif
    
    //**************  SRAI Test for uint64_t integers   ***************************************

    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRAI uint64_t Test   :\n");
        printf("\n-------------------------------\n");
    #endif
 
    test_srai_u64_ui_type(k);
    
    k=k+ TEST_COUNT ;
    
    //**************  SRAI Test for int64_t integers   ***************************************

    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRAI int64_t Test   :\n");
        printf("\n-------------------------------\n");
    #endif
 
    test_srai_s64_ui_type(k);
    
    k=k+ TEST_COUNT ;


    //**************  SRAIW Test for uint32_t integers   ***************************************

    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRAIW uint32_t Test   :\n");
        printf("\n-------------------------------\n");
    #endif
 
    test_sraiw_u32_ui_type(k);
    
    k=k+ TEST_COUNT ;

    //**************  SRAIW Test for int32_t integers   ***************************************

    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRAIW int32_t Test   :\n");
        printf("\n-------------------------------\n");
    #endif
 
    test_sraiw_s32_ui_type(k);
    
    k=k+ TEST_COUNT ;

    //**************  SRAIW Test for uint16_t integers   ***************************************

    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRAIW uint16_t Test   :\n");
        printf("\n-------------------------------\n");
    #endif
 
    test_sraiw_u16_ui_type(k);
    
    k=k+ TEST_COUNT ;

    //**************  SRAIW Test for int16_t integers   ***************************************

    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRAI int16_t Test   :\n");
        printf("\n-------------------------------\n");
    #endif
 
    test_sraiw_s16_ui_type(k);
    
    k=k+ TEST_COUNT ;


    //**************  SRAIW Test for uint8_t integers   ***************************************

    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRAI uint8_t Test   : \n");
        printf("\n-------------------------------\n");
    #endif
 
    test_sraiw_u8_ui_type(k);
    
    k=k+ TEST_COUNT ;

    //**************  SRAIW Test for int8_t integers   ***************************************

    #ifdef SPIKE_RUN
	    printf("\n Test/ > SRAI int8_t Test   :\n");
        printf("\n-------------------------------\n");
    #endif
 
    test_sraiw_s8_ui_type(k);
    
    k=k+ TEST_COUNT ;

    /*******************************************************************************************************************
     ***********                        Min and Max Testcase for  SRAI/SRAIW Instructions         **********************
     *******************************************************************************************************************/
    #ifdef SPIKE_RUN
        printf("\n Test/ > ------------------------------------------------------------- \n");
        printf("\n Test/ > Immediate Shift Right Arithmetic Test for Max and Min cases:  \n");
        printf("\n Test/ > ------------------------------------------------------------- \n");
    #endif

    //**********************    Max Test for SRAIW uint8_t integer      **************************************************
   
    #ifdef SPIKE_RUN
        printf("\n Test/ > Immediate Shift Right Arithmetic(Word) Test for Max of uint8_t : \n");
        printf("\n Test/ > ---------------------------------------------------------------- \n");
    #endif

	testtypenum++;
        

	for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    TEST_MAX_MIN_SRAIW_INSN_I_SPIKE(sraiw,op1,op2,result_full,result_tb,testnumber,uint8_t,uint8_t);
		    SRAIW_PRINT_RESULT_U(testnumber,op1,op2,result_tb,result_full,uint8_t);
        #else
		    TEST_MAX_MIN_SRAIW_INSN_I(sraiw,op1,op2,result_full,testnumber,uint8_t,uint8_t,UINT8_MAX,8);
        #endif
    }
	k++;
   

    //**********************    Max Test for SRAIW int8_t integer      **************************************************
    #ifdef SPIKE_RUN
        printf("\n Test/ > Immediate Shift Right Arithmetic(Word) Test for Max of int8_t :\n");
        printf("\n Test/ > -------------------------------------------------------------- \n");
    #endif
            
    testtypenum++;


    for (int testnumber = k; testnumber < k + 1; testnumber++)
    {
  
        #ifdef SPIKE_RUN
	        TEST_MAX_MIN_SRAIW_INSN_I_SPIKE(sraiw,op1,op2,result_full,result_tb,testnumber,int8_t,int8_t);
	        SRAIW_PRINT_RESULT_S(testnumber,op1,op2,result_tb,result_full,int8_t);
        #else
	        TEST_MAX_MIN_SRAIW_INSN_I(sraiw,op1,op2,result_full,testnumber,int8_t,uint8_t,INT8_MAX,8);
        #endif
    }
    k++;

    //**********************    Max Test for SRAIW uint16_t integer      **************************************************
    
    #ifdef SPIKE_RUN
        printf("\n Test/ > Immediate Shift Right Arithmetic(Word) Max Test uint16_t : \n");
        printf("\n Test/ > ---------------------------------------------------------- \n");
    #endif

    testtypenum++;


    for (int testnumber = k; testnumber < k + 1; testnumber++)
    {
        #ifdef SPIKE_RUN
	        TEST_MAX_MIN_SRAIW_INSN_I_SPIKE(sraiw,op1,op2,result_full,result_tb,testnumber,uint16_t,uint16_t);
	        SRAIW_PRINT_RESULT_U(testnumber,op1,op2,result_tb,result_full,uint16_t);
        #else
	        TEST_MAX_MIN_SRAIW_INSN_I(sraiw,op1,op2,result_full,testnumber,uint16_t,uint16_t,UINT16_MAX,16);
        #endif
    }
    k++;

    //**********************    Max Test for SRAIW int16_t integer      **************************************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Immediate Shift Right Arithmetic(Word) Max Test for int16_t :\n");
        printf("\n Test/ > ------------------------------------------------------------ \n");
    #endif

    testtypenum++;
    

    for (int testnumber = k; testnumber < k + 1; testnumber++)
    {
        #ifdef SPIKE_RUN
	        TEST_MAX_MIN_SRAIW_INSN_I_SPIKE(sraiw,op1,op2,result_full,result_tb,testnumber,int16_t,int16_t);
	        SRAIW_PRINT_RESULT_S(testnumber,op1,op2,result_tb,result_full,int16_t);
        #else
	        TEST_MAX_MIN_SRAIW_INSN_I(sraiw,op1,op2,result_full,testnumber,int16_t,int16_t,INT16_MAX,16);
        #endif
    }
    k++;
    
    //**********************    Max Test for SRAIW uint32_t integer      **************************************************
    
    #ifdef SPIKE_RUN
        printf("\n Test/ > Immediate Shift Right  Arithmetic (Word )Test for Max of uint32_t :\n");
        printf("\n Test/ > ------------------------------------------------------------------ \n");
    #endif
        
    testtypenum++;


    for (int testnumber = k; testnumber < k + 1; testnumber++)
    {
        #ifdef SPIKE_RUN
	        TEST_MAX_MIN_SRAIW_INSN_I_SPIKE(sraiw,op1,op2,result_full,result_tb,testnumber,uint32_t,uint32_t);
        	SRAIW_PRINT_RESULT_U(testnumber,op1,op2,result_tb,result_full,uint32_t);
        #else
	        TEST_MAX_MIN_SRAIW_INSN_I(sraiw,op1,op2,result_full,testnumber,uint32_t,uint32_t,UINT32_MAX,31);
        #endif
    }
    k++;
    
    //**********************    Max Test for SRAIW int32_t integer      **************************************************

    #ifdef SPIKE_RUN
        printf("\n Test/> Immediate Shift Right Arithmetic (Word) Test for Max of int32_t :\n");
        printf("\n Test/ > --------------------------------------------------------------- \n");
    #endif

    testtypenum++;


    for (int testnumber = k; testnumber < k + 1; testnumber++)
    {
        #ifdef SPIKE_RUN
        	TEST_MAX_MIN_SRAIW_INSN_I_SPIKE(sraiw,op1,op2,result_full,result_tb,testnumber,int32_t,int32_t);
	        SRAIW_PRINT_RESULT_S(testnumber,op1,op2,result_tb,result_full,int32_t);
        #else
	        TEST_MAX_MIN_SRAIW_INSN_I(sraiw,op1,op2,result_full,testnumber,int32_t,int32_t,INT32_MAX,31);
        #endif
    }
    k++;

    //**********************    Max Test for SRAI uint64_t integer      **************************************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Immediate Shift Right Arithmetic Test for Max of uint64_t :\n");
        printf("\n Test/ > ---------------------------------------------------------- \n");
    #endif

    testtypenum++;


    for (int testnumber = k; testnumber < k + 1; testnumber++)
    {
        #ifdef SPIKE_RUN
	        TEST_MAX_MIN_SRAI_INSN_I_SPIKE(srai,op1,op2,result_full,result_tb,testnumber,uint64_t,uint64_t);
        	SRAI_PRINT_RESULT_U(testnumber,op1,op2,result_tb,result_full,uint64_t);
        #else
	        TEST_MAX_MIN_SRAI_INSN_I(srai,op1,op2,result_full,testnumber,uint64_t,uint64_t,UINT64_MAX,63);
        #endif
    }
    k++;

    //**********************    Max Test for SRAI int64_t integer      **************************************************
    #ifdef SPIKE_RUN
        printf("\n Test/ > Immediate Shift Right Arithmetic Test for Max int64_t :\n");
        printf("\n Test/ > ------------------------------------------------------ \n");
    #endif

    testtypenum++;


    for (int testnumber = k; testnumber < k + 1; testnumber++)
    {
        #ifdef SPIKE_RUN
	        TEST_MAX_MIN_SRAI_INSN_I_SPIKE(srai,op1,op2,result_full,result_tb,testnumber,int64_t,int64_t);
	        SRAI_PRINT_RESULT_S(testnumber,op1,op2,result_tb,result_full,int64_t);
        #else
        	TEST_MAX_MIN_SRAI_INSN_I(srai,op1,op2,result_full,testnumber,int64_t,int64_t,INT64_MAX,63);
        #endif
    }
    k++;

    //***********************************  Min test Case for SRAI/SRAIW Instructions    ********************************
    #ifdef SPIKE_RUN
        printf("\n Test/ > ---------------------------------------------------------------- \n");
        printf("\n Test/ > Immediate Shift Right Arithmetic Test for MIN  cases:\n");
        printf("\n Test/ > ---------------------------------------------------------------- \n");
    #endif

    //**********************    Min Test for SRAIW int8_t integer      **************************************************
    
    #ifdef SPIKE_RUN
        printf("\n Test/ > Immediate Shift Right Arithmetic (Word) Test for MIN uint8_t:\n");
        printf("\n Test/ > ------------------------------------------------------------ \n");
    #endif

	testtypenum++;


    for(int testnumber=k; testnumber < k+1; testnumber++)
    {
        #ifdef SPIKE_RUN	
		    TEST_MAX_MIN_SRAIW_INSN_I_SPIKE(sraiw,op1,op2,result_full,result_tb,testnumber,uint8_t,uint8_t);
		    SRAIW_PRINT_RESULT_U(testnumber,op1,op2,result_tb,result_full,uint8_t);
        #else
		    TEST_MAX_MIN_SRAIW_INSN_I(sraiw,op1,op2,result_full,testnumber,uint8_t,uint8_t,UINT8_MIN,0);
        #endif
    }
	k++;

    //**********************    Min Test for SRAIW int8_t integer      **************************************************
    #ifdef SPIKE_RUN
        printf("\n Test/ > Immediate Shift Right Arithmetic (Word) Test for MIN int8_t :\n");
        printf("\n Test/ > ------------------------------------------------------------ \n");
    #endif

    testtypenum++;


    for (int testnumber = k; testnumber < k + 1; testnumber++)
    {
        #ifdef SPIKE_RUN
	        TEST_MAX_MIN_SRAIW_INSN_I_SPIKE(sraiw,op1,op2,result_full,result_tb,testnumber,int8_t,int8_t);
	        SRAIW_PRINT_RESULT_S(testnumber,op1,op2,result_tb,result_full,int8_t);
        #else
	        TEST_MAX_MIN_SRAIW_INSN_I(sraiw,op1,op2,result_full,testnumber,int8_t,int8_t,INT8_MIN,0);
        #endif
    }
    k++;

    //**********************    Min Test for SRAIW uint16_t integer      **************************************************
    #ifdef SPIKE_RUN
        printf("\n Test/ > Immediate Shift Right Arithmetic(Word) Test for MIN uint16_t :\n");
        printf("\n Test/ > ------------------------------------------------------------- \n");
    #endif

    testtypenum++;


    for (int testnumber = k; testnumber < k + 1; testnumber++)
    {
        #ifdef SPIKE_RUN
	        TEST_MAX_MIN_SRAIW_INSN_I_SPIKE(sraiw,op1,op2,result_full,result_tb,testnumber,uint16_t,uint16_t);
	        SRAIW_PRINT_RESULT_U(testnumber,op1,op2,result_tb,result_full,uint16_t);
        #else
	        TEST_MAX_MIN_SRAIW_INSN_I(sraiw,op1,op2,result_full,testnumber,uint16_t,uint16_t,UINT16_MIN,0);
        #endif
    }
    k++;

    //**********************    Min Test for SRAIW int16_t integer      **************************************************
    #ifdef SPIKE_RUN
        printf("\n Test/ > Immediate Shift Right Arithmetic (Word)Test for MIN int16_t :\n");
        printf("\n Test/ > ------------------------------------------------------------ \n");
    #endif

    testtypenum++;


    for (int testnumber = k; testnumber < k + 1; testnumber++)
    {
        #ifdef SPIKE_RUN
	        TEST_MAX_MIN_SRAIW_INSN_I_SPIKE(sraiw,op1,op2,result_full,result_tb,testnumber,int16_t,int16_t);
	        SRAIW_PRINT_RESULT_S(testnumber,op1,op2,result_tb,result_full,int16_t);
        #else
	        TEST_MAX_MIN_SRAIW_INSN_I(sraiw,op1,op2,result_full,testnumber,int16_t,int16_t,INT16_MIN,0);
        #endif
    }
    k++;

    //**********************    Min Test for SRAIW uint32_t integer      **************************************************
    #ifdef SPIKE_RUN
        printf("\n Test/ > Immediate Shift Right Arithmetic(Word) Test for MIN uint32_t :\n");
        printf("\n Test/ > ------------------------------------------------------------- \n");
    #endif

    testtypenum++;


    for (int testnumber = k; testnumber < k + 1; testnumber++)
    {
        #ifdef SPIKE_RUN
	        TEST_MAX_MIN_SRAIW_INSN_I_SPIKE(sraiw,op1,op2,result_full,result_tb,testnumber,uint32_t,uint32_t);
	        SRAIW_PRINT_RESULT_U(testnumber,op1,op2,result_tb,result_full,uint32_t);
        #else
	        TEST_MAX_MIN_SRAIW_INSN_I(sraiw,op1,op2,result_full,testnumber,uint32_t,uint32_t,UINT32_MIN,0);
        #endif
    }
    k++;

    //**********************    Min Test for SRAIW int32_t integer      **************************************************
    #ifdef SPIKE_RUN
        printf("\n Test/ > Immediate Shift Right Arithmetic(Word) Test for MIN int32_t :\n");
        printf("\n Test/ > ------------------------------------------------------------ \n");
    #endif

    testtypenum++;


    for (int testnumber = k; testnumber < k + 1; testnumber++)
    {
        #ifdef SPIKE_RUN
	        TEST_MAX_MIN_SRAIW_INSN_I_SPIKE(sraiw,op1,op2,result_full,result_tb,testnumber,int32_t,int32_t);
	        SRAIW_PRINT_RESULT_S(testnumber,op1,op2,result_tb,result_full,int32_t);
        #else
	        TEST_MAX_MIN_SRAIW_INSN_I(sraiw,op1,op2,result_full,testnumber,int32_t,int32_t,INT32_MIN,0);
        #endif
    }
    k++;

    //**********************    Min Test for SRAI uint64_t integer      **************************************************

    #ifdef SPIKE_RUN
        printf("\n Test/ > Immediate Shift Right Arithmetic Test for MIN uint64_t :\n");
        printf("\n Test/ > ------------------------------------------------------- \n");
    #endif

    testtypenum++;


    for (int testnumber = k; testnumber < k + 1; testnumber++)
    {
        #ifdef SPIKE_RUN
	        TEST_MAX_MIN_SRAI_INSN_I_SPIKE(srai,op1,op2,result_full,result_tb,testnumber,uint64_t,uint64_t);
	        SRAI_PRINT_RESULT_U(testnumber,op1,op2,result_tb,result_full,uint64_t);
        #else
	        TEST_MAX_MIN_SRAI_INSN_I(srai,op1,op2,result_full,testnumber,uint64_t,uint64_t,UINT64_MIN,0);
        #endif
    }
    k++;

    //**********************    Min Test for SRAI int64_t integer      **************************************************
    #ifdef SPIKE_RUN
        printf("\n Test/ > Immediate Shift Right Arithmetic Test for MIN int64_t :\n");
        printf("\n Test/ > ------------------------------------------------------ \n");
    #endif

    testtypenum++;


    for (int testnumber = k; testnumber < k + 1; testnumber++)
    {
        #ifdef SPIKE_RUN
	        TEST_MAX_MIN_SRAI_INSN_I_SPIKE(srai,op1,op2,result_full,result_tb,testnumber,int64_t,int64_t);
	        SRAI_PRINT_RESULT_S(testnumber,op1,op2,result_tb,result_full,int64_t);
        #else
	        TEST_MAX_MIN_SRAI_INSN_I(srai,op1,op2,result_full,testnumber,int64_t,int64_t,INT64_MIN,0);
        #endif
    }
    k++;

    //************   MAILBOX  REQUEST    ***************
    mailbox_send_request (MAILBOX1, MEM_DUMP);
    mailbox_send_request (MAILBOX2, num_of_elements_memdump);
    mailbox_send_request (MAILBOX1, END_SIM);
    mailbox_send_request (MAILBOX2, error_cnt);

    return 0;
}

