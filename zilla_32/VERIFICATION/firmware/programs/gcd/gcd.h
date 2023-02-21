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



          // Macro for GCD test without spike (C) 
#define GCD_C(mb,op1,op2,rslt_full,tn) \
					                      uint8_t op1, op2; \
	                                      uint16_t rslt_full; \
                                          uint8_t i; \
                                          op1 = (uint8_t)generate_random_num(mb); \
                                          op2 = (uint8_t)generate_random_num(mb); \
                                          for(i=1; i <= op1 && i <= op2; ++i) \
                                          { if(op1%i==0 && op2%i==0) \
                                          rslt_full= i;\
                                          }\
                                          actual_result[(tn-1)*3 + 0] = op1;\
                                          actual_result[(tn-1)*3 + 1] = op2;\
                                          actual_result[(tn-1)*3 + 2] = rslt_full;\

// Macro for GCD test with spike (C) 
#define GCD_SPIKE(op1,op2,rslt_full,rslt_tb,tn)  \
                                          uint8_t op1, op2; \
	                                      uint16_t rslt_full; \
					                      uint16_t rslt_tb; \
                                          uint8_t i; \
                                          op1 = (uint8_t)data[(tn-1)*3 + 0]; \
                                          op2 = (uint8_t)data[(tn-1)*3 + 1]; \
                                          rslt_tb = (uint16_t)data[(tn-1)*3 + 2]; \
                                          for(i=1; i <= op1 && i <= op2; ++i) \
                                          { \
                                          if(op1%i==0 && op2%i==0)\
                                          rslt_full= i;\
                                          }\


// Print

#define PRINT_GCD(op1,op2,a_result,e_result) \
					 if(a_result == e_result) \
					 	printf("op1=%15lu,  op2=%15lu, E-result = %15lu, A-result = %15lu : Status = [PASS]\n",op1, op2, e_result, a_result); \
					 else \
					printf("op1=%15lu,  op2=%15lu, E-result = %15lu, A-result = %15lu : Status = [FAIL]\n",op1, op2, e_result, a_result); \
				                       
                                          

