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
// Macro for HCF test without spike (C) 
#define HCF_TEST_U8_C(mb,op1,op2,rslt_full,tn) \
					  uint64_t op1, op2; \
	                  uint64_t rslt_full; \
                      op1 = (uint64_t)generate_random_num(mb); \
                      op2 = (uint64_t)generate_random_num(mb); \
 while(op1 > op2)\
    {\
        if(op1 > op2)\
            op1 -= op2;\
        else\
            op2 -= op1;\
    }\
rslt_full = op1; \
actual_result[(tn-1)*3 + 0] = op1; \
actual_result[(tn-1)*3 + 1] = op2; \
actual_result[(tn-1)*3 + 2] = rslt_full;\
					  

// Macro for HCF test with spike (C) 
#define HCF_TEST_U8_SPIKE_C(op1,op2,rslt_full,rslt_tb,tn)  \
                                          uint64_t op1, op2; \
	                                  uint64_t rslt_full; \
					                  uint64_t rslt_tb; \
                                          op1 = (uint64_t)data[(tn-1)*3 + 0]; \
                                          op2 = (uint64_t)data[(tn-1)*3 + 1]; \
                                          rslt_tb = (uint64_t)data[(tn-1)*3 + 2]; \
                                         while(op1 > op2)\
                                         {\
                                            if(op1 > op2)\
                                                op1 -= op2;\
                                            else\
                                                op2 -= op1;\
                                          }\
                                          rslt_full = (uint64_t)op1;\

#define PRINT_RESULT_HCF_U(op1,op2,a_result,e_result,test_num) \
					 if(a_result == e_result) \
					 	printf("Test/> [%3d] HCF of %s : %0lu and %0lu  : E-result = %0lu, A-result = %0lu : Status = [PASS]\n", test_num, MKSTR(test_type), op1, op2, e_result, a_result); \
					 else \
						printf("Test/> [%3d] HCF of %s : %0lu and %0lu  : E-result = %0lu, A-result = %0lu : Status = [FAIL]\n", test_num, MKSTR(test_type), op1, op2, e_result, a_result);\



