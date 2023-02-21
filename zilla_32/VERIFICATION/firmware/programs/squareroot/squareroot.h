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
#define SQUARE_ROOT_C(mb,x,rslt_full,tn)\
   uint32_t x=(uint32_t)generate_random_num(mb);\
   uint32_t i = 1;\
   uint32_t result = 1;\
   uint32_t rslt_full;\
   if (x == 0 || x == 1)\
        return x;\
   while (result <= x) {\
        i++;\
        result = i * i;\
    }\
    z_printf("---------------------%d\n",i - 1);\
    rslt_full=i-1;\
    actual_result[(tn-1)*2 + 0] = x;\
    actual_result[(tn-1)*2 + 1] = rslt_full;\
    
#define SQUARE_ROOT_SPIKE(x_tb,rslt_full,rslt_tb,tn)\
   uint32_t x_tb=(uint32_t)data[(tn-1)*2 + 0];\
   uint32_t rslt_tb = (uint32_t)data[(tn-1)*2 + 1];\
   uint32_t i = 1;\
   uint32_t result = 1;\
   uint32_t rslt_full;\
   if (x_tb == 0 || x_tb == 1)\
        return x_tb;\
   while (result <= x_tb) {\
        i++;\
        result = i * i;\
    }\
   rslt_full=i-1;\

#define PRINT_RESULT_SQUARE_ROOT(x_tb,rslt_full,rslt_tb)\
   if(rslt_tb == rslt_full) \
        printf("Test/>   Square_root: Number = %lu, E-result = %lu, A-result = %lu : Status = [PASS] \n", x_tb,rslt_tb, rslt_full);\
   else \
        printf("Test/>   Square_root: Number = %lu, E-result = %lu, A-result = %lu : Status = [FAIL] \n", x_tb,rslt_tb, rslt_full);\


