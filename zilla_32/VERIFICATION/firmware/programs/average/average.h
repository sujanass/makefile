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
#define RAND_ARR_SEARCH(mb,tn)\
                      uint16_t rand_arr[10];\
					  uint16_t *p=rand_arr;\
					  for( uint8_t i = 0;i<10;i++)\
					  {  \
                          rand_arr[i] = (uint16_t)generate_random_num(mb);\
                           actual_result[(tn-1)*12 + i] = rand_arr[i];\
                      }\

#define PRINT_RESULT_AVERAGE(rslt_tb_int,rslt_tb_fract,rslt_full_int,rslt_full_fract)\
if((rslt_tb_int==rslt_full_int)&&(rslt_tb_fract==rslt_full_fract))\
    printf("Average: E-result = %u.%u, A-result = %u.%u : Status = [PASS] \n",rslt_full_int,rslt_full_fract,rslt_tb_int,rslt_tb_fract);\
else\
    printf("Average: E-result = %u.%u, A-result = %u.%u : Status = [FAIL] \n",rslt_full_int,rslt_full_fract,rslt_tb_int,rslt_tb_fract);\


