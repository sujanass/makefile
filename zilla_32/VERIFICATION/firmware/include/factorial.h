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
#define FACTORIAL_TEST_U8(mb,n,rslt_full,tn)\
    int64_t i; \
    uint8_t n=((uint8_t)generate_random_num(mb)) % 20 ; \
    uint64_t fact=1; \
    uint64_t rslt_full; \
    z_printf("Integer: %d \n",n);\
    for (i = 1; i <= n; i++) \
    {\
            fact = fact*i;\
    }\
    z_printf("Factorial of %d = %l \n", n, fact);\
    rslt_full=fact;\
    actual_result[(tn-1)*2 + 0] = n; \
    actual_result[(tn-1)*2 + 1] = rslt_full; \



#define FACTORIAL_TEST_U8_SPIKE(n_tb,rslt_tb,rslt_full,tn)\
    int64_t i; \
    uint8_t n_tb=(uint8_t)data[(tn-1)*2 + 0]; \
    uint64_t rslt_tb=(uint64_t)data[(tn-1)*2 + 1]; \
    uint64_t fact=1;\
    uint64_t rslt_full; \
       for (i = 1; i <= n_tb; i++) \
    {\
       fact = fact*i;\
    }\
    rslt_full=fact;\



#define PRINT_RESULT_FACTORIAL(rslt_tb,rslt_full,n_tb)\
if(rslt_tb==rslt_full)\
    printf("Factorial of %d --> E-result = %ld, A-result = %ld : Status = [PASS] \n",n_tb,rslt_full,rslt_tb);\
else\
    printf("Factorial of %d --> E-result = %ld, A-result = %ld : Status = [FAIL] \n",n_tb,rslt_full,rslt_tb);\





