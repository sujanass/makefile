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
#ifndef PALTST_H
#define PALTST_H

#define random_array_palindrome(MAILBOX1, number,tn)\
    uint32_t number[10];\
	for (int i=0; i<10;i++)\
    {\
        number[i]= (uint32_t) generate_random_num(MAILBOX1);\
	 actual_result[(tn-1)*30 + i] = number[i];\
	}
	
#define PALINDROME_C(MAILBOX1,number,tn,rev,prime_result)\
	 uint64_t rev[10];\
    uint32_t arr[10];\
      uint64_t reverse;\
    uint32_t temp;\
    uint8_t i; \
    uint8_t prime_result[10];\
	for ( i=0; i<10;i++)\
    {\
    	arr[i]= (uint32_t)number[i];\
        reverse=0;\
        while(number[i]!=0)\
        {\
            temp= number[i]%10;\
            reverse = reverse*10 + temp;\
            number[i]=number[i]/10;\
        }\
        rev[i]=(uint64_t) reverse;\
	}\
	for ( i=0; i<10;i++)\
		{\
		actual_result[(tn-1)*30 + (i+10)] = rev[i];	\
		if(arr[i]==rev[i])\
            {\
                prime_result[i]=1;\
            }\
        else\
            {\
                prime_result[i]=0;\
            }\
            actual_result[(tn-1)*30 + (i+20)] = prime_result[i];\
        }
		
		
#define PALINDROME_SPIKE(number,arr, tn,rslt_tb,rslt_rev)\
		uint32_t number[10];\
		uint64_t rev[10];\
    uint32_t arr[10];\
    uint64_t reverse;\
    uint32_t temp;\
    uint8_t i;\
	uint64_t rslt_rev[10];\
    uint8_t spike_result[10];\
		uint8_t rslt_tb[10];\
		for( i=0;i<10;i++)\
            {  rslt_tb[i] = (uint8_t)data[(tn-1)*30 + (20+i)]; \
			number[i] = (uint32_t)data[(tn-1)*30 + i]; \
			rslt_rev[i] = (uint64_t)data[(tn-1)*30 + (10+i)]; }\
			for ( i=0; i<10;i++)\
			{\
			arr[i]= number[i];\
        reverse=0;\
        while(number[i]!=0)\
        {\
            temp= number[i]%10;\
            reverse = reverse*10 + temp;\
			number[i]=number[i]/10;\
        }\
        rev[i]= reverse;\
	}	\
		for ( i=0; i<10;i++)\
		{\
		if(arr[i]==rev[i])\
            {\
                spike_result[i]=1;\
            }\
        else\
            {\
                spike_result[i]=0;\
            }\
        }
		
		
#define PRINT_PALINDROME(spike_result,rslt_tb,rslt_rev,arr)	\
	for( i=0;i<10; i++)\
	{\
		if((spike_result[i] ==1)  && (rslt_tb[i]==1))\
			printf("input number=%15lu, reverse number =%15lu, it is a palindrome number [PASS]\n", arr[i], rslt_rev[i]);\
		else if((spike_result[i] ==0)  && (rslt_tb[i]==0))\
			printf("input number=%15lu, reverse number =%15lu, it is  not a palindrome number [PASS]\n", arr[i], rslt_rev[i]);\
		else\
			printf("input number=%15lu, reverse number =%15lu,[FAIL]\n", arr[i], rslt_rev[i]);\
	}            

					

#endif 
