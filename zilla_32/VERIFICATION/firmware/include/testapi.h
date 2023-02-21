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
#ifndef TESTAPI_H
#define TESTAPI_H


////////////////////////////////////////////////////////////////////////
////////////           Prime number or not display          ////////////
///////////////////////////////////////////////////////////////////////

#define PRINT_RESULT_PRIME(rslt_tb,rslt_full,data_input)\
 for(int i=0;i<10;i++)\
   {    if(rslt_tb[i] == rslt_full[i])\
       {\
           if(rslt_tb [i]== 0)\     
       printf("Test/>   Prime : The number = %15d is not a prime number, E-result = %15d, A-result = %15d : Status = [PASS] \n",data_input[i], rslt_full[i], rslt_tb[i]);\
     else\
   	   printf("Test/>   Prime :The number = %15d is a prime number E-result = %15d, A-result = %15d : Status = [PASS] \n", data_input[i],rslt_full[i], rslt_tb[i]);\
   }\
       else\
           printf("Test/>   Prime : E-result = %15d, A-result = %15d : Status = [FAIL] \n",rslt_full[i], rslt_tb[i]);\
   }\
 

////////////////////////////////////////////////////////////////////////
////////////           Fibinocci display                   ////////////
///////////////////////////////////////////////////////////////////////


   
#define PRINT_RESULT_FIBINOCCI(len,rslt_tb,rslt_full,tn) \
                               uint8_t len=rslt_tb[0];\
                               printf("Number of va.ues calculated is %15d\n", len-1);\
                               for(int i=0;i<len+1;i++)\
                               {   \
                                 if(rslt_tb[i] == rslt_full[i])\
                                   printf("Test/>   Fibinocci Series: E-result = %lu, A-result = %lu : Status = [PASS] \n", rslt_full[i], rslt_tb[i]);\
                                 else\
   	                               printf("Test/>   Fibinocci Series: E-result = %lu, A-result = %lu : Status = [FAIL] \n", rslt_full[i], rslt_tb[i]);\
                               }\


////////////////////////////////////////////////////////////////////////
////////////       PALINDROME DISPLAY                      ////////////
///////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////
////////////         CUBEROOT DISPLAY                      ////////////
///////////////////////////////////////////////////////////////////////

#define PRINT_CUBE_SPIKE(number,rslt_tb,rslt_full,tn) \
                          if(rslt_tb == rslt_full) \
                      printf("Test/>   Cuberoot: number = %lu, E-result = %lu, A-result = %lu : Status = [PASS] \n", number,rslt_tb, rslt_full);\
                          else \
                            printf("Test/>   Cuberoot: number = %lu,E-result = %lu, A-result = %lu : Status = [FAIL] \n",number,rslt_tb, rslt_full);\

////////////////////////////////////////////////////////////////////////
////////////       LCM DISPLAY                             ////////////
///////////////////////////////////////////////////////////////////////

#define PRINT_LCM(op1,op2,rslt_tb,rslt_full)\
    if(rslt_tb == rslt_full )\
        printf("TEST/>\n LCM: op1 = %15lu, op2 = %15lu, E_result= %15lu, A_result= %15lu [PASS]\n",op1,op2,rslt_full,rslt_tb);\
    else\
        printf("TEST/>\n LCM: op1 = %15lu op2 = %15lu E_result= %15lu A_result= %15lu [FAIL]\n",op1,op2,rslt_full,rslt_tb);\

////////////////////////////////////////////////////////////////////////
////////////       SQUREROOT DISPLAY                       ////////////
///////////////////////////////////////////////////////////////////////

#define PRINT_RESULT_SQUARE_ROOT(x_tb,rslt_full,rslt_tb)\
   if(rslt_tb == rslt_full) \
        printf("Test/>   Square_root: Number = %lu, E-result = %lu, A-result = %lu : Status = [PASS] \n", x_tb,rslt_tb, rslt_full);\
   else \
        printf("Test/>   Square_root: Number = %lu, E-result = %lu, A-result = %lu : Status = [FAIL] \n", x_tb,rslt_tb, rslt_full);\

////////////////////////////////////////////////////////////////////////
////////////      HCF DISPLAY                              ////////////
///////////////////////////////////////////////////////////////////////

#define PRINT_RESULT_HCF_U(op1,op2,a_result,e_result) \
					 if(a_result == e_result) \
					 	printf("Test/>HCF op1= %0lu op2 = %0lu : E-result = %0lu, A-result = %0lu : Status = [PASS]\n", op1, op2, e_result, a_result); \
					 else \
						printf("Test/>HCF op1= %0lu op2 = %0lu  : E-result = %0lu, A-result = %0lu : Status = [FAIL]\n", op1, op2, e_result, a_result);\

////////////////////////////////////////////////////////////////////////
////////////      CUBE DISPLAY                              ////////////
///////////////////////////////////////////////////////////////////////

#define PRINT_cube(op1,result_full, result_tb) \
					 if (result_full == result_tb) \
					 	printf("op1=%15lu,result-tb = %15lu, result-full = %15lu : Status = [PASS]\n",op1, result_tb, result_full); \
					 else \
					    printf("op1=%15lu,result-tb = %15lu, result-full = %15lu : Status = [FAIL]\n",op1, result_tb, result_full); \

////////////////////////////////////////////////////////////////////////
////////////      GCD DISPLAY                              ////////////
///////////////////////////////////////////////////////////////////////

#define PRINT_GCD(op1,op2,a_result,e_result) \
					 if(a_result == e_result) \
					 	printf("op1=%15lu,  op2=%15lu, E-result = %15lu, A-result = %15lu : Status = [PASS]\n",op1, op2, e_result, a_result); \
					 else \
					printf("op1=%15lu,  op2=%15lu, E-result = %15lu, A-result = %15lu : Status = [FAIL]\n",op1, op2, e_result, a_result); \
				                       
                                         
////////////////////////////////////////////////////////////////////////
////////////      MODULO INVERSE DISPLAY                    ////////////
///////////////////////////////////////////////////////////////////////

#define PRINT_RESULT_MODULO(a,b,a_result,e_result,test_num) \
	if(a_result == e_result) \
	  printf("Test count /> [%3d] inverse_modulus of : %15u&%15u: E-result = %15u, A-result = %15u : Status = [PASS]\n", test_num, a, b, a_result, e_result); \
    else \
	  printf("Tes count t/> [%3d] inverse_modulus of : %15u&%15u: E-result = %15u, A-result = %15u : Status = [FAIL]\n", test_num, a, b, a_result, e_result);

/*------------------------------------------------------------------------------*/

////////////////////////////////////////////////////////////////////////
////////////      MODULO INVERSE DISPLAY                    ////////////
///////////////////////////////////////////////////////////////////////

#define PRINT_RESULT_MODULO(op1,op2,a_result,e_result,test_num) \
	if(a_result == e_result) \
	  printf("Test/> [%2d] MODULUS: %15u | %15u: E-result = %15u, A-result = %15u : Status = [PASS]\n", test_num, op1, op2, a_result, e_result); \
    else \
	  printf("Test/> [%2d] MODULUS: %15u | %15u: E-result = %15u, A-result = %15u : Status = [FAIL]\n", test_num, op1, op2, a_result, e_result);

/*---------------------------------------------------------------------------------*/

////////////////////////////////////////////////////////////////////////
////////////      PRIME DISPLAY                             ////////////
///////////////////////////////////////////////////////////////////////
#define PRINT_RESULT_PRIME(test_num,rand_input,a_result,e_result)\
    if(a_result == e_result)\
       printf("Test/>[%3d]   Prime : The number = %15u , A-result = %15u, E-result = %15u : Status = [PASS] \n",test_num,rand_input,a_result,e_result);\
else\
       printf("Test/>[%3d]   Prime : The number = %15u , A-result = %15u, E-result = %15u : Status = [FAIL] \n",test_num,rand_input,a_result, e_result);\
        
////////////////////////////////////////////////////////////////////////
////////////      ARMSTRONG NUMBER DISPLAY                 ////////////
///////////////////////////////////////////////////////////////////////

#define PRINT_RESULT_ARMSTRONG(testnumber,a_result,e_result)\
    if(a_result == e_result)\
       printf("Test/>[%3d]   Armstrong :  , A-result = %15d, E-result = %15d : Status = [PASS] \n",testnumber, rslt_full, rslt_tb);\
else\
       printf("Test/>[%3d]   Armstrong :  , A-result = %15d, E-result = %15d : Status = [FAIL] \n",testnumber, rslt_full, rslt_tb);
        

////////////////////////////////////////////////////////////////////////
///For displaying results for modular expansion uint8_t, uint16_t, uint32_t tests  /////////////////////////////////////////////////////////////////////////

#define MODEXP1_PRINT_RESULT_UU(x1,y1,p1,a_result,e_result,test_num) \
					 if(a_result == e_result) \
					 	printf("Test/> [%3d] modular exponentiation :%15u^%15umod%15u E-result = %15u, A-result = %15u : Status = [PASS]\n", test_num,x1,y1,p1,e_result, a_result); \
					 else \
						printf("Test/> [%3d] modular exponentiation :%15u^%15umod%15u E-result = %15u, A-result = %15u : Status = [FAIL]\n", test_num,x1,y1,p1,e_result, a_result);

////////////////////////////////////////////////////////////////////////
////////////      CATALAN_NO DISPLAY                       ////////////
///////////////////////////////////////////////////////////////////////

#define PRINT_CATALAN_NO(n,catalan_no,result_tb,test_num)\
    if(catalan_no == result_tb)\
printf("Test count /> [%3d] catalan number of %15u is  :E result = %15lu :A result = %15lu : Status = [PASS]\n", test_num, n, catalan_no, result_tb); \
else\
{\
printf("Test count /> [%3d] catalan number of %15u is  :E result = %15lu :A result = %15lu : Status = [FAIL]\n", test_num, n, catalan_no, result_tb); \
}\

////////////////////////////////////////////////////////////////////////
////////////      FACTORIAL DISPLAY                       ////////////
///////////////////////////////////////////////////////////////////////
#define PRINT_RESULT_FACTORIAL(rslt_tb,rslt_full,n_tb)\
if(rslt_tb==rslt_full)\
    printf("Factorial of %d --> E-result = %ld, A-result = %ld : Status = [PASS] \n",n_tb,rslt_full,rslt_tb);\
else\
    printf("Factorial of %d --> E-result = %ld, A-result = %ld : Status = [FAIL] \n",n_tb,rslt_full,rslt_tb);\



/*********************************Prime test cases***************************/
#define RAND_ARR_PRIME(mb,tn)\
                      uint8_t rand_arr[10];\
					  uint8_t *p=rand_arr;\
					  for ( uint8_t i = 0;i<10;i++)\
					  {    rand_arr[i] = (uint8_t)generate_random_num(mb);\
                           actual_result[(tn-1)*20 + i] = rand_arr[i];}\

   
/***********************RANDOM ARRAY GENERATION FOR PALINDROME*****************************/

#define random_array_palindrome(MAILBOX1, number,tn)\
    uint32_t number[10];\
	for (int i=0; i<10;i++)\
    {\
        number[i]= (uint32_t) generate_random_num(MAILBOX1);\
	 actual_result[(tn-1)*30 + i] = number[i];\
	}




/*************************************Prime no**********************************/


#define PRIME_NO_TEST_C(mb,rand_arr,rslt_full,tn)\
                      uint8_t rslt_full[10];\
                      uint8_t i,j;\
                      rand_arr[i] = (uint8_t)generate_random_num(mb);\
                      uint8_t data_input [10];\
                      for( j = 0; j<10; j++)\
                      { uint8_t test = rand_arr[j];\
                      data_input[i] = rand_arr[i];\
                      for( int k =2;k <= test/2; k++)\
                      { if (test% k == 0)\
                      {\
                      rslt_full[j] = 0;\
                      break;}\
                      else\
                      rslt_full[j] =1;\
                      }\
                      }\
                      for( i=0;i<10;i++)\
                      {actual_result[(tn-1)*20 +(10+i)] = rslt_full[i]; }\

#define PRIME_NO_TEST_SPIKE_C(data_input,rslt_full,rslt_tb,tn)\
                      uint8_t rslt_full[10];\
                      uint8_t rslt_tb[10];\
                      uint8_t data_spike[10];\
                      uint8_t i,j;\
                      uint8_t data_input [10];\
                      for( i=0;i<10;i++)\
                      {  rslt_tb[i] = (uint8_t)data[(tn-1)*20 + (10+i)]; }\
                      for( i=0;i<10;i++)\
                      for( j = 0; j<10; j++)\
                      { uint8_t test = data_input[j];\
                      data_spike[i] = data_input[i];\
                      for( int k =2;k <= test/2; k++)\
                      { if (test% k == 0)\
                      {\
                      rslt_full[j] = 0;\
                      break;}\
                      else\
                      rslt_full[j] =1;\
                      }\
                      }\

#endif



                     
/*************************************FIBONACCI SERIES**********************************/
                 

/***** Header for fibonacci. 64 bit fibonacci series is generate.*****/

#ifndef FIBTST_H
#define FIBTST_H
                

 
/***********************************C test for fibinocci**********************************/
           

#define FIBINOCCI_C(mb,len,rslt_full,tn)\
                    z_printf("CALCULATING FIBINOACCI VALUES IN CORE...");\
                    uint8_t len=94;\
                    actual_result[(tn-1)]=len;\
                    uint64_t n1=0,n2=1,n;\
                    uint8_t index;\
                    if(tn==1)\
                    {\
                      index=0;\
                    }\
                    else \
                    {\
                      uint8_t index =(uint8_t) (index+ actual_result[(tn-2)]);\
                    }\
                    uint64_t rslt_full[len+1];\
                    rslt_full[0]=len;\
                    if(len==1)\
                      rslt_full[1]=n1;\
                    else if(len==2)\
                    {\
                      rslt_full[1]=n1;\
                      rslt_full[2]=n2;\
                    }\
                    else\
                   {\
                     rslt_full[1]=n1;\
                     rslt_full[2]=n2;\
                     for(int i=3;i<len+1;i++)\
                     { n=n1+n2;\
                       rslt_full[i]=n;\
                       n1=n2;\
                       n2=n;}\
                    }\
                    for(int i=1;i<len+1;i++)\
                    {  \
                      actual_result[(index) +i+2]=(uint64_t)rslt_full[i];\
                    }\

 

/*************************************SPIKE TEST FOR FIBINOCCI**********************************/


#define FIBINOCCI_SPIKE_C(len1,rslt_spike,rslt_full,rslt_tb,tn)\
                         uint8_t len1;\
                         len1=data[(tn-1)];\
                         uint8_t index;\
                         if(tn==1)\
                         {\
                           index=0;\
                         }\
                         else\
                         {\
                           index = index+data[(tn-2)]; \
                         }\
                         uint64_t x1=0,x2=1,x;\
                         uint64_t rslt_full[len1+1];\
                         uint64_t rslt_tb[len1+1];\
                         uint64_t rslt_spike[len1+1];\
                         for(int i=0;i<len1+1;i++)\
                         {\
                           if(i==0)\
                           {\
                             rslt_tb[i]=len1;\
                           }\
                           else\
                           rslt_tb[i]=(uint64_t)data[(index)+i+2];      }\
                           rslt_spike[0]=len1;\
                          if(len1==1)\
                            rslt_spike[1]=x1;\
                          else if(len1==2)\
                          {\
                            rslt_spike[1]=x1;\
                            rslt_spike[2]=x2;\
                          }\
                          else\
                          {\
                            rslt_spike[1]=x1;\
                            rslt_spike[2]=x2;\
                            for(int i=3;i<len1+1;i++)\
                            {  x=x1+x2;\
                               rslt_spike[i]=x;\
                               x1=x2;\
                               x2=x;}\
                          }\
                         for(int i=0;i<len1+1;i++)\
                         {  \
                           rslt_full[i]=rslt_spike[i];\
                         }

#endif /* FIBTST_H */

                     
/*************************************PALINDROME SERIES**********************************/
                      
                      
#ifndef PALTST_H
#define PALTST_H



/*************************************C TEST FOR PALINDROME**********************************/
	
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


/*********************************SPIKE TEST FOR PALINDROME******************************/

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
		
          

					

#endif 


/*************************************CUBE ROOT NUMBER**********************************/

                                  

/**********************************C TEST FOR CUBE ROOT NUMBER**********************************/

#define CUBE_C(mb,number,rslt_full, tn);\
                              uint8_t number;\
                              uint8_t rslt_full;\
                              uint8_t i;\
                              number  = (uint8_t)generate_random_num(mb);\
                              actual_result[(tn-1)*2 + 0] = number;\
                              for(int i=0;i<=number;i++)\
                               {if(i*i*i==number)\
                                     rslt_full=i;\
                               }\
                              actual_result[(tn-1)*2 + 1] = rslt_full;\  


/******************************SPIKE TEST FOR CUBE ROOT NUMBER*****************************/

#define CUBE_SPIKE(number,rslt_tb, rslt_full,tn);\
                               uint8_t number;\
                               uint8_t rslt_tb;\
                               uint8_t rslt_full;\
                               number = (uint8_t)data[(tn-1)*2 + 0]; \
                               rslt_tb = (uint8_t)data[(tn-1)*2 + 1]; \
                               for(int i=0;i<=number;i++)\
                               {\
                                if(i*i*i==number){\
                                     rslt_full=i;\
                                                                   }\
                               }\
                               actual_result[(tn-1)*2 + 2] = rslt_full; 


/**********************************C TEST FOR LCM**********************************/

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
 
/*************************************SPIKE TEST FOR LCM**********************************/
  
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
   
        
    



   

/************************************HCF**********************************/
  
                      
/*************************************C TEST FOR HCF**********************************/

// Macro for HCF test without spike (C) 
#define HCF_TEST_U8_C(mb,op1,op2,rslt_full,tn) \
					  uint8_t op1, op2; \
	                                  uint16_t rslt_full; \
                                          op1 = (uint8_t)generate_random_num(mb); \
                                          op2 = (uint8_t)generate_random_num(mb); \
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
actual_result[(tn-1)*3 + 2] = rslt_full;

                      
/*************************************SPIKE TEST FOR HCF**********************************/


#define HCF_TEST_U8_SPIKE_C(op1,op2,rslt_full,rslt_tb,tn)  \
                                          uint8_t op1, op2; \
	                                  uint16_t rslt_full; \
					                  uint16_t rslt_tb; \
                                          op1 = (uint8_t)data[(tn-1)*3 + 0]; \
                                          op2 = (uint8_t)data[(tn-1)*3 + 1]; \
                                          rslt_tb = (uint16_t)data[(tn-1)*3 + 2]; \
                                         while(op1 > op2)\
                                         {\
                                            if(op1 > op2)\
                                                op1 -= op2;\
                                            else\
                                                op2 -= op1;\
                                          }\
                                          rslt_full = (uint16_t)op1;

                     
/*************************************CUBE NUMBER**********************************/

                      
/*************************************C TEST FOR CUBE ROOT**********************************/


// Macro for cube test without spike (C) 
#define cube_C(mb,op1,rslt_full,tn) \
					                      uint8_t op1; \
	                                      uint64_t rslt_full; \
                                          uint8_t i; \
                                          op1 = (uint8_t)generate_random_num(mb); \
                                          rslt_full = op1 *op1 *op1; \
                                          actual_result[(tn-1)*3 + 0] = op1;\
                                          actual_result[(tn-1)*3 + 2] = rslt_full;\

/*************************************SPIKE TEST FOR CUBE ROOT*******************************/

// Macro for cube test with spike (C) 
#define cube_SPIKE(op1,rslt_full,rslt_tb,tn)  \
                                          uint8_t op1; \
	                                      uint64_t rslt_full; \
					                      uint64_t rslt_tb; \
                                          uint8_t i; \
                                          op1 = (uint8_t)data[(tn-1)*3 + 0]; \
                                          rslt_tb = (uint64_t)data[(tn-1)*3 + 2]; \
                                          rslt_full = op1 *op1 *op1; \


// Print
				                       

                      
/*************************************GCD**********************************/


/*************************************C TEST FOR GCD**********************************/

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

                      
/*************************************SPIKE TEST FOR GCD**********************************/

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

 




/*---------------MODULO INVERSE  on core FOR UNSIGNED 16 BIT------------*/
#define MODULO_INVERSE(mb,a,b,result_full,tn)\
    uint8_t  a;\
    uint8_t  b;\
    uint16_t result_full;\
    a=(uint16_t)generate_random_num(mb);\
    b=(uint16_t)generate_random_num(mb);\
     int i,hcf,val;\
    if(a == 1 || b==1)\
   { val=0; } for(i=1;i<=a;i++)\
        {  	  if(a%i==0 && b%i==0)\
          {	    hcf = i;\
	 }	}if (hcf == 1){ int counter,mul;\
          counter = 1;          while (1) { mul = a * counter;\
               if(mul%b == 1){\
               val = counter;\
         break;\
           } counter++;\
        }	}    if (val != 0)\
       {        z_printf("Modular Inverse is : %d\n",val);\
    }    else     {        z_printf("Numbers are invalid");\
    }    result_full=val;\
    actual_result[(tn-1)*3 + 0] = a; \
    actual_result[(tn-1)*3 + 1] = b; \
    actual_result[(tn-1)*3 + 2] = result_full; \

/*---------------------MODULO INVERSE on spike--------------*/
#define  MODULO_INVERSE_SPIKE(a,b,result_full,result_tb,tn)\
    uint8_t  a;\
    uint8_t  b;\
    uint16_t result_full;\
    uint16_t result_tb;    a = (uint8_t)data[(tn-1)*3 + 0]; \
    b = (uint8_t)data[(tn-1)*3 + 1]; \
       result_tb = (uint16_t)data[(tn-1)*3 + 2];      int i,hcf,val;\
    if(a == 1 || b==1)\
   { val=0; } for(i=1;i<=a;i++)\
       {  	  if(a%i==0 && b%i==0)\
        {	    hcf = i;\
	 }	}if (hcf == 1){ int counter,mul;\
        counter = 1;        while (1) { mul = a * counter;\
              if(mul%b == 1){\
               val = counter;\
         break;\
           } counter++;\
        }	}    if (val != 0)\
      {        printf("Modular Inverse is : %d\n",val);\
    }    else     {        printf("Numbers are invalid");\
    }    result_full=val;\





/*---------------modulo arthematic on core FOR UNSIGNED 16 BIT------------*/
#define MODULO_ARTHEMATIC(mb,op1_dt,op1,op2,result_full,tn)\
    op1_dt op1;\
    op1_dt op2;\
    op1_dt result_full;\
    op1=(op1_dt)generate_random_num(mb);\
    op2=(op1_dt)generate_random_num(mb);\
    result_full=op1%op2;\
    actual_result[(tn-1)*3 + 0] = op1; \
    actual_result[(tn-1)*3 + 1] = op2; \
    actual_result[(tn-1)*3 + 2] = result_full; \

/*-------------------modulo arthematic on spike--------------*/
#define MODULO_ARTHEMATIC_SPIKE(op1_dt,op1,op2,result_full,result_tb,tn)\
    op1_dt op1;\
    op1_dt op2;\
    op1_dt result_full,result_tb;\
    op1 = (op1_dt)data[(tn-1)*3 + 0]; \
    op2 = (op1_dt)data[(tn-1)*3 + 1]; \
    result_full=op1%op2;\
    result_tb = (op1_dt)data[(tn-1)*3 + 2];\ 





////////////////////////////////////////////////////////////////////////
 //--------------******PRIME NUMBER OR NOT********------------------// 
////////////////////////////////////////////////////////////////////////

//------------------------PRIME TEST CASES-----------------------------// 

/*------------------------------- Macro for prime test without spike--------------------------------  */
#define PRIME_C(mb,rand_input,rslt_flag,tn)\
                      uint8_t rslt_flag;\
                      uint8_t rand_input;\
                      rand_input = (uint8_t)generate_random_num(mb);\
                    if (rand_input == 0 || rand_input == 1)\
                          rslt_flag = 1;\
                            else\
                          rslt_flag = 0;\
                     for (int i = 2; i <= rand_input / 2; i++) {\
                          if (rand_input % i == 0) {\
                             rslt_flag = 1;\
                                 break;\
                                 }\
                               }\
  if (rslt_flag == 0)\
    z_printf("%d is a prime number.", rand_input);\
  else\
    z_printf("%d is not a prime number.", rand_input);\
  actual_result[(tn-1)*2 + 0] = rand_input;\
  actual_result[(tn-1)*2 + 1] = rslt_flag;\

/*---------------------------------- Macro for prime test with spike-----------------------------------  */


#define PRIME_NO_TEST_SPIKE_C(rand_input,rslt_flag_c,rslt_flag_tb,tn)\
                      uint8_t rand_input;\
                      uint8_t  rslt_flag_tb;\
                      uint8_t  rslt_flag_c;\
                      rand_input=(uint8_t)data[(tn-1)*2 + 0];\
                      rslt_flag_c=(uint8_t)data[(tn-1)*2 + 1];\
                   if (rand_input == 0 || rand_input == 1)\
                          rslt_flag_tb = 1;\
else\
                           rslt_flag_tb = 0;\
                     for (int i = 2; i <= rand_input / 2; i++) {\
                          if (rand_input % i == 0) {\
                             rslt_flag_tb = 1;\
                                 break;\
                                 }\
                               }\
  if (rslt_flag_tb == 0)\
    printf("%d is a prime number.", rand_input);\
  else\
    printf("%d is not a prime number.", rand_input);\
   


 //--------------******ARMSTRONG NUMBER OR NOT********------------------// 
////////////////////////////////////////////////////////////////////////

//------------------------ARMSTRONG NUMBER TEST CASES-----------------------------// 

/*------------------------------- Macro for Armstrong number test without spike--------------------------------  */

#define ARMSTRONG_TEST_C(mb,data_input,temp,remainder,rslt_full,tn)\
                      uint16_t rslt_sum=0;\
                      uint16_t rslt_full;\
                      uint8_t temp;\
                      uint8_t remainder;\
                      uint8_t data_input;\
                      data_input = (uint8_t)generate_random_num(mb);\
                      actual_result[(tn-1)*2 + 0] = data_input;\
                      z_printf("data_input=%d\n",data_input);\
                      temp = data_input;\
                   while(data_input>0) {\
                       remainder = data_input%10;\
                       rslt_sum=rslt_sum+(remainder*remainder*remainder);\
                       data_input=data_input/10; }\
                   if(temp==rslt_sum) {\
                       z_printf("armstrong  number=%d\n",temp); }\
                   else\
	                	z_printf("it is not armstrong number=%d\n",temp);\
                  rslt_full=rslt_sum;\
                  z_printf("rslt_sum=%d\n",rslt_sum);\
                  actual_result[(tn-1)*2 + 1] = rslt_full;

/*---------------------------------- Macro for armstrong test with spike-----------------------------------  */


#define ARMSTRONG_TEST_SPIKE( data_input,temp, remainder,rslt_full,rslt_tb,tn)\
                      uint8_t data_input;\
                      uint16_t rslt_sum = 0;\
                      uint8_t temp;\
                      uint16_t rslt_full;\
                      uint8_t remainder;\
                      uint16_t rslt_tb;\
                      data_input = (uint8_t)data[(tn-1)*2 + 0];\
                     printf("data_input=%d\n",data_input);\
                     rslt_tb   =  (uint16_t)data[(tn-1)*2 + 1];\
                   temp = data_input;\
                   while(data_input>0) {\
                       remainder = data_input%10;\
                       rslt_sum=rslt_sum+(remainder*remainder*remainder);\
                       data_input=data_input/10; }\
                   if(temp==rslt_sum) {\
                       printf("armstrong  number=%d\n",temp); }\
                   else\
                  printf("it is not armstrong number",temp);\
                  rslt_full=rslt_sum;\
                  printf("rslt_sum=%d\n",rslt_sum);
                  

//                                                                                                                                 //
//                                                Modulo exponentiaion Test Cases Macros                                                       //  
//                                                                                                                                 //         
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////// Modulo exponentiation Test uint8_t MACROs ///////////////////////////////////////////


// Macro for MODEXP test with spike (C) 
#define MODEXP1_TEST_U8_SPIKE_C(x,y,p,rslt_full,rslt_tb,tn)  \
                                          uint8_t x,y,p; \
										  uint8_t rslt_full; \
										  uint8_t rslt_tb; \
                                          x = (uint8_t)data[(tn-1)*4 + 0]; \
                                          y = (uint8_t)data[(tn-1)*4 + 1]; \
                                          p = (uint8_t)data[(tn-1)*4 + 2]; \
                                          uint8_t x1=x;\
                                          uint8_t y1=y;\
                                          uint8_t p1=p;\
                                         rslt_tb = (uint8_t)data[(tn-1)*4 + 3]; \
                                         printf("actual_result: %d\n",rslt_tb);\
                                          int res = 1;\
                                          x = x % p;\
                                          while (y > 0)\
                                             {\
                                               if (y & 1)\
                                                    {\
                                                   res = (res*x) % p;\
                                                  }\
                                                    y = y>>1; \
                                                    x = (x*x) % p;\
                                            }\
                                            if(res<0)\
                                                res=p+res;\
                                           rslt_full = res;\
                                          printf("expected_result: %d\n",rslt_full);
//Macro for MODEXP test without spike(c)

#define MODEXP1_TEST_U8_C(mb,x,y,p,rslt_full,tn) \
										  uint8_t x,y,p; \
										  uint8_t rslt_full; \
                                          x = (uint8_t)generate_random_num(mb); \
                                          y = (uint8_t)generate_random_num(mb); \
                                          p = (uint8_t)generate_random_num(mb);\
                                          actual_result[(tn-1)*4 + 0] = x; \
                                          actual_result[(tn-1)*4 + 1] = y; \
                                          actual_result[(tn-1)*4 + 2] = p; \
                                          uint8_t res = 1;\
                                           x = x % p;\
                                            while (y > 0)\
                                            {\
                                               if (y & 1)\
                                                   {\
                                                    res = (res*x) % p;\
                                                  }\
                                                  y = y>>1; \
                                                  x = (x*x) % p;\
                                                  }\
                                            if(res<0)\
                                                res=p+res;\
                                                rslt_full = res;\
                                            z_printf("result_full: %d",rslt_full);\
                                            actual_result[(tn-1)*4 + 3] = rslt_full;



                      
/*...............catalan_no on core for UNSIGNED 8 bit.......................*/

#define CATALAN_NO(mb,n,a,c,catalan_no,tn)\
    uint64_t catalan_no;\
    int n;\
    uint64_t a=1;\
    uint64_t c=1;\
    n=(uint8_t)generate_random_num(mb);\
    int i;\
     for(i=2*n;i>=((2*n)-(n-2));i--)\
   {\
       a =a*i;\
   }\
  for(i=1;i<=n;i++)   {\
       c =c * i;\
   }\
   catalan_no = a/c;\
   z_printf("catalan number of %d = %d", n, catalan_no);\
  actual_result[(tn-1)*4 + 0] = n; \
  actual_result[(tn-1)*4 + 1] = a; \
  actual_result[(tn-1)*4 + 2] = c; \
  actual_result[(tn-1)*4 + 3] = catalan_no; \

/*...............catalan_no on spike........................................*/

#define CATALAN_NO_SPIKE(n,a,c,catalan_no,result_tb,tn)\
    int n;\
    uint64_t a=1;\
    uint64_t c=1;\
    uint64_t catalan_no;\
    uint64_t result_tb;\
     int i;\
   {  n = (uint8_t)data[(tn-1)*4 + 0]; }\
   {  result_tb = (uint64_t)data[(tn-1)*4 + 3]; }\
   for(i=2*n;i>=((2*n)-(n-2));i--)\
   {\
       a =a*i;\
   }\
 for(i=1;i<=n;i++)   {\
       c =c * i;\
   }\
   catalan_no = a/c;
 


 /***************************************************************************************/
//*******************************FACTORIAL**********************************************/
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
//*********************************SQUAREROOT********************************//

#define SQUARE_ROOT_C(mb,x,rslt_full,tn)\
   uint32_t x=(uint32_t)generate_random_num(mb);\
   z_printf("Number : %d\n",x);\
   uint32_t i = 1;\
   uint32_t result = 1;\
   uint32_t rslt_full;\
   if (x == 0 || x == 1)\
        return x;\
   while (result <= x) {\
        i++;\
        result = i * i;\
    }\
    z_printf("Square Root---------------------%d\n",i - 1);\
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

