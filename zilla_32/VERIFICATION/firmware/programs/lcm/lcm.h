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

#define LCM_C(mb,op1,op2,rslt_full,tn) \
                                 uint8_t op1, op2; \
                                 uint16_t rslt_full; \
                                 uint8_t i; \
                                 op1 = (uint8_t)generate_random_num(mb);  \
                                 op2 = (uint8_t)generate_random_num(mb);  \
                                 for(i = 1;i < op1 && i < op2 ;++i) \
                                 { if(op1%i==0 && op2%i==0) \
                                 rslt_full = i;\
                                 }\
                                 rslt_full = (op1 * op2)/rslt_full;\
                                 z_printf(" Actual %d\n",rslt_full);\
                                 actual_result[(tn-1)*3 + 0] = op1;\
                                 actual_result[(tn-1)*3 + 1] = op2;\
                                 actual_result[(tn-1)*3 + 2] = rslt_full;\
   
#define LCM_SPIKE_C(op1,op2,rslt_full,rslt_tb,tn) \
                                        uint8_t op1, op2; \
                                        uint16_t grt,rslt_full; \
                                        uint16_t rslt_tb; \
                                        uint8_t i; \
                                        op1 = (uint8_t)data[(tn-1)*3 + 0]; \
                                        op2 = (uint8_t)data[(tn-1)*3 + 1]; \
                                        rslt_tb = (uint16_t)data[(tn-1)*3 + 2]; \
                                        for(i = 1;i < op1 && i < op2 ;++i) \
                                        { \
                                        if(op1%i==0 && op2%i==0)\
                                        rslt_full = i;\
                                        }\
                                        rslt_full = (op1 * op2)/rslt_full;\
   
        
    



#define PRINT_LCM(op1,op2,rslt_tb,rslt_full)\
    if(rslt_tb == rslt_full )\
        printf("TEST/>\n LCM: op1 = %15lu, op2 = %15lu, E_result= %15lu, A_result= %15lu [PASS]\n",op1,op2,rslt_full,rslt_tb);\
    else\
        printf("TEST/>\n LCM: op1 = %15lu op2 = %15lu E_result= %15lu A_result= %15lu [FAIL]\n",op1,op2,rslt_full,rslt_tb);\
   

