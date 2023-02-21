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
/**
*******************************************************************************
**
** To search and element of the sorted given array and return index
**
*********************************************************************************
*/


#include <stdio.h>  
#include "print.h"              /*!< Mailbox print library  */
#include "mailbox.h"            /*!< Mailbox access library */
#include "search.h"

#ifdef SPIKE_RUN
#include "data.h"               /*!< Testbench created data */
#endif


/* Note: TEST_COUNT indicates number of test for each tests. e.g. TEST_COUNT number
   of tests for uint8_t multiplication, TEST_COUNT number of tests for int8_t multiplication, etc*/
#define TEST_COUNT     (1)    /*!< Test count             */
#define DATA_SET        (11)     /*!< array of 10 elements      */
#define TEST_TYPES      (6)     /*!< */ 


/* Array to store the operand1, operand2 and actual result */
int64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};
int64_t *p ;
                                    
/* Main function */
int main(void)
{
	/* test case status */
	volatile int testtypenum  = 0;
   	int64_t num_of_elements_memdump;
	num_of_elements_memdump = (TEST_COUNT*11*1) ;

/**********************************Linear Search*****************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Linear search test\n");
    printf("----------------------------------- \n");

#endif

 for(int testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
  	{

#ifdef SPIKE_RUN	
	    LINEAR_SEARCH_TEST_SPIKE_C(e_rand_arr,rslt_full,rslt_tb,testnumber);
        PRINT_RESULT_SEARCH(rslt_tb,rslt_full);
#else  
        RAND_ARR_SEARCH(MAILBOX1,testnumber);
        LINEAR_SEARCH_TEST_C(MAILBOX1,rand_arr,rslt_full,testnumber);
        z_printf("Element is present at index %d\n",rslt_full);
  	  
#endif

     p=p+1;
        
   	}

/*************************************************Binary Search*******************************************/

#ifdef SPIKE_RUN
	printf("\nTest/> Binary search test\n");
    printf("----------------------------------- \n");

#endif
     	
testtypenum++;
         	
for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{

#ifdef SPIKE_RUN	
		BINARY_SEARCH_TEST_SPIKE_C(e_rand_arr,rslt_full,rslt_tb,testnumber);
        PRINT_RESULT_SEARCH(rslt_tb,rslt_full);
#else  
        RAND_ARR_SEARCH(MAILBOX1,testnumber);
        BINARY_SEARCH_TEST_C(MAILBOX1,rand_arr,rslt_full,testnumber);
        z_printf("Element is present at index %d\n",rslt_full);
#endif
 
        p=p+1;  
        
   	}

///////////////////////////////////////////////////EXPONENTIAL SEARCH//////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Exponential search test\n");
    printf("----------------------------------- \n");

#endif

testtypenum++;
  

for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
 
        
#ifdef SPIKE_RUN	
		        
        int32_t j, i, gap,key;
        int32_t result[10];
        int32_t rslt_full;
        int32_t e_rand_arr[10]; 
        int32_t rslt_tb;
        int32_t size_1 = sizeof(e_rand_arr)/ sizeof(e_rand_arr[0]);
       
        rslt_tb = (int32_t)data[(testnumber-1)*11 + 10]; 
        for(i=0;i<size_1;i++)
        { 
            e_rand_arr[i] = (int32_t)data[(testnumber-1)*11 + i];                 
        }
    
        for(gap =size_1/2;gap>0;gap/=2)
        { 
            for(i=0;i<size_1;i++)
             {  
                 j=i-gap;
                 key= e_rand_arr[i];
                 while(j>=0 && e_rand_arr[j]>key)
                 { 
                     e_rand_arr[j+gap] = e_rand_arr[j];
                      j=j-gap; 
                 }
                 e_rand_arr[j+gap] = key; 
             } 
        }
        for( i=0;i<size_1;i++)
        { 
           result[i] = e_rand_arr[i];
        }              
                    
        int32_t x = e_rand_arr[rslt_tb];
        rslt_full = exponentialSearch_spike_test(&result[0], size_1, x);
        PRINT_RESULT_SEARCH(rslt_tb,rslt_full);
#else  
        RAND_ARR_SEARCH(MAILBOX1,testnumber);
        int32_t j, i, gap,key;
        int32_t result[10];
        int32_t rslt_full;
        int32_t size_1 = sizeof(rand_arr)/ sizeof(rand_arr[0]);
        
        for(i=0;i<size_1;i++)
        {  
            rand_arr[i] = (int32_t)(*p);
            p++; 
        }
        z_printf("unsorted random array \n");
        for(i=0; i<size_1;i++)
        {
            z_printf("%d\n", rand_arr[i]);
        }
        for(gap =size_1/2;gap>0;gap/=2)
        { 
           for(i=0;i<size_1;i++)
           {  
              j=i-gap;
              key= rand_arr[i];
              while(j>=0 && rand_arr[j]>key)
              { 
                  rand_arr[j+gap] = rand_arr[j];
                  j=j-gap; 
              }
              rand_arr[j+gap] = key; 
           } 
        }
        for( i=0;i<size_1;i++)
        { 
            result[i] = rand_arr[i];
        }              
        z_printf("The Sorted array is : \n");
        for(i=0; i<size_1;i++)
        {
            z_printf("%d\n", result[i]);
        }
        int32_t a = rand() % 10;     
        int32_t x = result[a];
        z_printf("The Element to be searched : %d\n", result[a]); 
        rslt_full = exponentialSearch(&result[0], size_1, x);
        (rslt_full == -1)? z_printf("Element is not present in array\n") : z_printf("Element is present at index %d\n",rslt_full);
        actual_result[(testnumber-1)*11 + 10] = rslt_full;
    	  
#endif

      p=p+1;
    
    }     
    
///////////////////////////////////////////////////INTERPOLATION  SEARCH////////////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Interpolation search test\n");
    printf("----------------------------------- \n");
#endif

testtypenum++;

for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	
{
       
#ifdef SPIKE_RUN	
		 
        int32_t i;
        int32_t rslt_full,interval;
        int32_t e_random[10];
        int32_t size_1 = sizeof(e_random)/ sizeof(e_random[0]);
        int32_t rslt_tb;

        rslt_tb = (int32_t)data[(testnumber-1)*11 + 10]; 
        for(i=0;i<size_1;i++)
        { 
            e_random[i] = (int32_t)data[(testnumber-1)*11 + i];                 
        }
      
        int32_t x =e_random[rslt_tb];
        rslt_full = interpolationSearch_spike_test(&e_random[0], 0, size_1 - 1, x);
        PRINT_RESULT_SEARCH(rslt_tb,rslt_full);

#else  

        int32_t i;
        int32_t rslt_full,interval;
        int32_t random[10];
        int32_t size_1 = sizeof(random)/ sizeof(random[0]);

        random[0] = (int32_t)generate_random_num(MAILBOX1);
        actual_result[(testnumber-1)*11 + 0] = random[0];
        interval = (uint8_t)generate_random_num(MAILBOX2);
        z_printf("Interval is : %d\n",interval);
        z_printf("1st element is : %d\n", random[0]);
    
        for(i=0;i<size_1;i++)
        {
            random[i+1]=random[i]+interval;
            z_printf("Distributed Array: %d\n", random[i+1]);
            actual_result[(testnumber-1)*11 + (i+1)] = random[i+1];
        }
        
        int32_t a = rand() % 10;     
        int32_t x = random[a];
        z_printf("The element to be searched : %d\n", random[a]);
   	    rslt_full = interpolationSearch(&random[0], 0, size_1 - 1, x);
        (rslt_full == -1)? z_printf("Element is not present in array\n") : z_printf("Element is present at index %d\n",rslt_full);
        actual_result[(testnumber-1)*11 + 10] = rslt_full;
    	  
#endif
      
        p=p+1;
    
}     

////////////////////////////////////////////////////////////JUMP SEARCH////////////////////////////////////////////////////////////

#ifdef SPIKE_RUN
	printf("\nTest/> Jump search test\n");
    printf("----------------------------------- \n");

#endif

testtypenum++;
 
for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
       
#ifdef SPIKE_RUN	
		        
        int32_t j, i, gap,key;
        int32_t result[10];
        int32_t rslt_full;
        int32_t e_rand_arr[10]; 
        int32_t rslt_tb;
        int32_t size_1 = sizeof(e_rand_arr)/ sizeof(e_rand_arr[0]);
       
        rslt_tb = (int32_t)data[(testnumber-1)*11 + 10]; 
        for(i=0;i<size_1;i++)
        { 
            e_rand_arr[i] = (int32_t)data[(testnumber-1)*11 + i];                 
        }

            
        for(gap =size_1/2;gap>0;gap/=2)
        { 
            for(i=0;i<size_1;i++)
             {  
                 j=i-gap;
                 key= e_rand_arr[i];
                 while(j>=0 && e_rand_arr[j]>key)
                 { 
                     e_rand_arr[j+gap] = e_rand_arr[j];
                      j=j-gap; 
                 }
                 e_rand_arr[j+gap] = key; 
             } 
        }
          
        for( i=0;i<size_1;i++)
        { 
            result[i] = e_rand_arr[i];
        }              
                
        int32_t x =e_rand_arr[rslt_tb];
        rslt_full = jumpsearch_spike_test(&result[0], x, size_1);
        PRINT_RESULT_SEARCH(rslt_tb,rslt_full);

#else
    
        RAND_ARR_SEARCH(MAILBOX1,testnumber);
        int32_t j, i, gap,key;
        int32_t result[10];
        int32_t rslt_full;
        int32_t size_1 = sizeof(rand_arr)/ sizeof(rand_arr[0]);
        
        for(i=0;i<size_1;i++)
        {  
            rand_arr[i] = (int32_t)(*p);
            p++; 
        }
        z_printf("unsorted random array \n");
        for(i=0; i<size_1;i++)
        {
            z_printf("%d\n", rand_arr[i]);
        }
           
        for(gap =size_1/2;gap>0;gap/=2)
        { 
           for(i=0;i<size_1;i++)
           {  
               j=i-gap;
               key= rand_arr[i];
               while(j>=0 && rand_arr[j]>key)
               { 
                    rand_arr[j+gap] = rand_arr[j];
                    j=j-gap; 
               }
               rand_arr[j+gap] = key; 
           } 
        }
               
        for( i=0;i<size_1;i++)
        { 
            result[i] = rand_arr[i];
        }              
        z_printf("The Sorted array is : \n");

        for(i=0; i<size_1;i++)
        {
            z_printf("%d\n", result[i]);
        }

        int32_t a = rand() % 10;     
        int32_t x = result[a];
        z_printf("The Element to be searched : %d\n", result[a]); 
	    rslt_full = jumpsearch(&result[0], x, size_1);
        (rslt_full == -1)? z_printf("Element is not present in array\n") : z_printf("Element is present at index %d\n",rslt_full);
        actual_result[(testnumber-1)*11 + 10] = rslt_full;

#endif

        p=p+1;
    
    }
	
///////////////////////////////////////////////////////////FIBONACCI SEARCH////////////////////////////////////////////////////////////////


#ifdef SPIKE_RUN
	printf("\nTest/> Fibonacci search test\n");
    printf("----------------------------------- \n");

#endif

testtypenum++;
       	
for(int testnumber = 1+testtypenum*TEST_COUNT; testnumber <= TEST_COUNT*(1+testtypenum); testnumber++)
	{
           
#ifdef SPIKE_RUN
        
        int32_t j, i, gap,key;
        int32_t result[10];
        int32_t rslt_full;
        int32_t e_rand_arr[10]; 
        int32_t rslt_tb;
        int32_t size_1 = sizeof(e_rand_arr)/ sizeof(e_rand_arr[0]);
       
        rslt_tb = (int32_t)data[(testnumber-1)*11 + 10]; 
        for(i=0;i<size_1;i++)
        { 
            e_rand_arr[i] = (int32_t)data[(testnumber-1)*11 + i];                 
        }

            
        for(gap =size_1/2;gap>0;gap/=2)
        { 
            for(i=0;i<size_1;i++)
            {  
                 j=i-gap;
                 key= e_rand_arr[i];
                 while(j>=0 && e_rand_arr[j]>key)
                 { 
                     e_rand_arr[j+gap] = e_rand_arr[j];
                      j=j-gap; 
                 }
                 e_rand_arr[j+gap] = key; 
            } 
        }
          
        for( i=0;i<size_1;i++)
        { 
            result[i] = e_rand_arr[i];
        }              
      
        int32_t x =e_rand_arr[rslt_tb];
        rslt_full = fibMonaccianSearch_spike(&result[0],x, size_1);
        PRINT_RESULT_SEARCH(rslt_tb,rslt_full);

#else		        
        
        RAND_ARR_SEARCH(MAILBOX1,testnumber);
        int32_t j, i, gap,key;
        int32_t result[10];
        int32_t rslt_full;
        int32_t size_1 = sizeof(rand_arr)/ sizeof(rand_arr[0]);
        
        for(i=0;i<size_1;i++)
        {  
            rand_arr[i] = (int32_t)(*p);
            p++; 
        }
        z_printf("unsorted random array \n");
        for(i=0; i<size_1;i++)
        {
            z_printf("%d\n", rand_arr[i]);
        }
            
        for(gap =size_1/2;gap>0;gap/=2)
        { 
           for(i=0;i<size_1;i++)
           {  
               j=i-gap;
               key= rand_arr[i];
               while(j>=0 && rand_arr[j]>key)
               { 
                   rand_arr[j+gap] = rand_arr[j];
                   j=j-gap; 
               }
               rand_arr[j+gap] = key; 
            } 
        }
     
        for( i=0;i<size_1;i++)
        { 
            result[i] = rand_arr[i];
        }              

        z_printf("The Sorted array is : \n");

        for(i=0; i<size_1;i++)
        {
            z_printf("%d\n", result[i]);
        }

        int32_t a = rand() % 10;          
        int32_t x = result[a];
        z_printf("The Element to be searched : %d\n", result[a]); 
        rslt_full = fibMonaccianSearch(&result[0], x, size_1);
        (rslt_full == -1)? z_printf("Element is not present in array\n") : z_printf("Element is present at index %d\n",rslt_full);
        actual_result[(testnumber-1)*11 + 10] = rslt_full;

#endif

        p=p+1;
    
    }
    
    mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt);    
    
    return 0;
}

//////////////////////////////////////////////////////THE END __/\__////////////////////////////////////////////////////////////////	
