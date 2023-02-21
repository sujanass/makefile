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
                      int32_t rand_arr[10];\
					  int32_t *p=rand_arr;\
					  for ( int32_t i = 0;i<10;i++)\
					  {    rand_arr[i] = (int32_t)generate_random_num(mb);\
                           actual_result[(tn-1)*11 + i] = rand_arr[i];}\

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define PRINT_RESULT_SEARCH(rslt_tb,rslt_full)\
if(rslt_tb==rslt_full)\
    printf("Test/>   Search : E-result = %15d, A-result = %15d : Status = [PASS] \n", rslt_full, rslt_tb);\
 else\
    printf("Test/>   Search : E-result = %15d, A-result = %15d : Status = [FAIL] \n", rslt_full, rslt_tb);\

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int MIN(int32_t a, int32_t b)
{
    return (a < b ? a : b);
}

//////////////////////////////////////////////////////////////////// LINEAR SEARCH //////////////////////////////////////////////////////////////////////////////
/*********************************************************************C TEST********************************************************************************/

#define LINEAR_SEARCH_TEST_C(mb,rand_arr,rslt_full ,tn)\
                      int64_t rslt_full;\
                      int64_t i,j,temp;\
                      int64_t size_1,x;\
                      size_1 = sizeof(rand_arr)/sizeof(rand_arr[0]);\
                      for(i=0;i<size_1;i++)\
                      {  rand_arr[i] = (int64_t)(*p);\
                         p++; }\
                      for(i=0;i<size_1-1;i++)\
                      { for(j=i+1;j<size_1;j++)\
                      { if(rand_arr[i]>rand_arr[j])\
                          { temp = rand_arr[i];\
                            rand_arr[i] = rand_arr[j];\
                          rand_arr[j] = temp; } } }\
                      int32_t a = rand() % 10;\
                      x = rand_arr[a];\
                      for(i=0;i<size_1;i++)\
                      { if(rand_arr[i]==x)\
                          rslt_full = i;}\
                      actual_result[(tn-1)*11 + 10] = rslt_full;
               
/***********************************************************************SPIKE TEST**************************************************************************/
      
#define LINEAR_SEARCH_TEST_SPIKE_C(e_rand_arr,rslt_full,rslt_tb,tn)\
                      int64_t e_rand_arr[10]; \
                      int64_t rslt_full; \
                      int64_t rslt_tb;\
                      int64_t i,j,x;\
                      int64_t size_1,temp;\
                      size_1 = sizeof(e_rand_arr)/sizeof(e_rand_arr[0]);\
                      rslt_tb = (int64_t)data[(tn-1)*11 + 10];\
                       for(i=0;i<size_1;i++)\
                      { e_rand_arr[i] = (int64_t)data[(tn-1)*11 + i]; \
                      }\
                      for(i=0;i<size_1-1;i++)\
                      { for(j=i+1;j<size_1;j++)\
                      { if(e_rand_arr[i]>e_rand_arr[j])\
                          { temp = e_rand_arr[i];\
                            e_rand_arr[i] = e_rand_arr[j];\
                          e_rand_arr[j] = temp; } } }\
                     x = e_rand_arr[rslt_tb];\
                     for(i=0;i<size_1;i++)\
                     { if(e_rand_arr[i]==x)\
                       rslt_full = i; }\

/////////////////////////////////////////////////////////////////BINARY SEARCH//////////////////////////////////////////////////////////////////////////
/*****************************************************************C TEST****************************************************************************/

#define BINARY_SEARCH_TEST_C(mb,rand_arr,rslt_full ,tn)\
                      int64_t rslt_full;\
                      int64_t i,j,temp;\
                      int64_t size_1,x;\
                      int64_t low,high,mid;\
                      size_1 = sizeof(rand_arr)/sizeof(rand_arr[0]);\
                      for(i=0;i<size_1;i++)\
                      {  rand_arr[i] = (int64_t)(*p);\
                         p++; }\
                     for(i=0;i<size_1-1;i++)\
                      { for(j=i+1;j<size_1;j++)\
                      { if(rand_arr[i]>rand_arr[j])\
                          { temp = rand_arr[i];\
                            rand_arr[i] = rand_arr[j];\
                          rand_arr[j] = temp; } } }\
                        int32_t a = rand() % 10;\
                        x = rand_arr[a];\
                      low= 0;\
                      high= size_1-1;\
                      while(low<high) {\
                     mid= low +((high-low)/2);\
                      if(rand_arr[mid]==x)\
                          { rslt_full = mid ;\
                              break; }\
                    if(rand_arr[mid]>x)\
                     high = mid-1;\
                     else \
                     low = mid+1; }\
                     actual_result[(tn-1)*11 + 10] = rslt_full;


/*********************************************************************SPIKE TEST*********************************************************************/

#define BINARY_SEARCH_TEST_SPIKE_C(e_rand_arr,rslt_full,rslt_tb,tn)\
                      int64_t e_rand_arr[10]; \
                      int64_t rslt_full; \
                      int64_t rslt_tb;\
                      int64_t i,j,x;\
                      int64_t size_1,temp;\
                      int64_t low,mid,high;\
                      size_1 = sizeof(e_rand_arr)/sizeof(e_rand_arr[0]);\
                      rslt_tb = (int64_t)data[(tn-1)*11 + 10]; \
                      for(i=0;i<size_1;i++)\
                      { e_rand_arr[i] = (int64_t)data[(tn-1)*11 + i]; \
                      }\
                      for(i=0;i<size_1-1;i++)\
                      { for(j=i+1;j<size_1;j++)\
                      { if(e_rand_arr[i]>e_rand_arr[j])\
                          { temp = e_rand_arr[i];\
                            e_rand_arr[i] = e_rand_arr[j];\
                          e_rand_arr[j] = temp; } } }\
                      x = e_rand_arr[rslt_tb];\
                      low = 0;\
                      high = size_1-1;\
                      while(low<=high) {\
                     mid= low +((high-low)/2);\
                      if(e_rand_arr[mid]==x)\
                          {  rslt_full = mid ;\
                              break ; }\
                      if(e_rand_arr[mid]>x)\
                     high = mid-1;\
                     else \
                     low = mid+1; }\
  
////////////////////////////////////////////////////////////EXPONENTIAL SEARCH///////////////////////////////////////////////////////////
/****************************************************************C TEST*****************************************************************/

int exponentialSearch(int32_t rand_arr[], int32_t n, int32_t x)
{
	if (rand_arr[0] == x)
    
	    return 0;
	    int32_t i = 1;
    
	while (i < n && rand_arr[i] <= x)
    
        i = i*2;
	    return binarySearch(rand_arr, i/2, MIN(i, n-1), x);
    
}

int binarySearch(int32_t rand_arr[], int32_t low, int32_t high, int32_t x)
{
	if (high >= low)
	{
		int32_t mid = low + (high - low)/2;

			if (rand_arr[mid] == x)
			return mid;

			if (rand_arr[mid] > x)
			return binarySearch(rand_arr, low, mid-1, x);



		return binarySearch(rand_arr, mid+1, high, x);
	}

	return -1;
}

/*****************************************************************SPIKE TEST***************************************************************/

int exponentialSearch_spike_test(int32_t e_rand_arr[], int32_t n, int32_t x)
{
	if (e_rand_arr[0] == x)
    
        return 0;
	    int32_t i = 1;
	while (i < n && e_rand_arr[i] <= x)
         i = i*2;
	     return binarySearch_spike_test(e_rand_arr, i/2, MIN(i, n-1), x);
    
    
}

int binarySearch_spike_test(int32_t e_rand_arr[], int32_t low, int32_t high, int32_t x)
{
	if (high >= low)
	{
		int32_t mid = low + (high - low)/2;

			if (e_rand_arr[mid] == x)
			return mid;

			if (e_rand_arr[mid] > x)
			return binarySearch_spike_test(e_rand_arr, low, mid-1, x);

		return binarySearch_spike_test(e_rand_arr, mid+1, high, x);
	}

	return -1;
}

////////////////////////////////////////////////////////////INTERPOLATION SEARCH///////////////////////////////////////////////////////////
/**************************************************************C TEST*********************************************************************/

int32_t interpolationSearch(int32_t rand_arr[], int32_t low, int32_t high, int32_t x)
{
	int32_t interpol;
	if (low <= high && x >= rand_arr[low] && x <= rand_arr[high]) 
    {
		interpol = low + (((double)(high - low) / (rand_arr[high] - rand_arr[low]))* (x - rand_arr[low]));
		if (rand_arr[interpol] == x)
			return interpol;
		if (rand_arr[interpol] < x)
			return interpolationSearch(rand_arr, interpol + 1, high, x);
		if (rand_arr[interpol] > x)
			return interpolationSearch(rand_arr, low, interpol - 1, x);
	}
	return -1;
}

/*******************************************************************SPIKE TEST**********************************************************/

int32_t interpolationSearch_spike_test(int32_t e_rand_arr[], int32_t low, int32_t high, int32_t x)
{
	int32_t interpol;
	if (low <= high && x >= e_rand_arr[low] && x <= e_rand_arr[high]) 
    {
		interpol = low + (((double)(high - low) / (e_rand_arr[high] - e_rand_arr[low]))* (x - e_rand_arr[low]));
		if (e_rand_arr[interpol] == x)
			return interpol;
		if (e_rand_arr[interpol] < x)
			return interpolationSearch_spike_test(e_rand_arr, interpol + 1, high, x);
		if (e_rand_arr[interpol] > x)
			return interpolationSearch_spike_test(e_rand_arr, low, interpol - 1, x);
	}
	return -1;
}

////////////////////////////////////////////////////////////JUMP SEARCH///////////////////////////////////////////////////////////
/*************************************************************C TEST*************************************************************/

int jumpsearch(int rand_arr[], int x, int n)
{
	int step = n/2;
	int prev = 0;
	while (rand_arr[MIN(step, n)-1] < x)
	{
		prev = step;
		step += n/2;
		if (prev >= n)
			return -1;
	}

	while (rand_arr[prev] < x)
	{
		prev++;
		if (prev == MIN(step, n))
			return -1;
	}
	// If element is found
	if (rand_arr[prev] == x)
    {
		return prev;
    }
    return -1;
}

/***************************************************************SPIKE TEST**********************************************************************/

int jumpsearch_spike_test(int e_rand_arr[], int x, int n)
{
	int step = n/2;
	int prev = 0;
	while (e_rand_arr[MIN(step, n)-1] < x)
	{
		prev = step;
		step += n/2;
		if (prev >= n)
			return -1;
	}

	while (e_rand_arr[prev] < x)
	{
		prev++;
		if (prev == MIN(step, n))
			return -1;
	}
	// If element is found
	if (e_rand_arr[prev] == x)
    {
		return prev;
    }

    return -1;
    
}

////////////////////////////////////////////////////////////FIBONACCI SEARCH///////////////////////////////////////////////////////////
/***************************************************************C TEST********************************************************************/

int fibMonaccianSearch(int32_t rand_arr[], int32_t x, int32_t size_1) 
{ 
    int32_t fibMMm2 = 0;  
    int32_t fibMMm1 = 1;  
    int32_t fibM = fibMMm2 + fibMMm1;  
        while (fibM < size_1) 
    { 
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM  = fibMMm2 + fibMMm1; 
    } 
  
       int32_t offset = -1; 
  
        while (fibM > 1) 
    { 
               int32_t i = MIN(offset+fibMMm2, size_1-1); 
  
                if (rand_arr[i] < x) 
        { 
            fibM  = fibMMm1; 
            fibMMm1 = fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
            offset = i; 
        } 
  
                else if (rand_arr[i] > x) 
        { 
            fibM  = fibMMm2; 
            fibMMm1 = fibMMm1 - fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
        } 
  
                else return i; 
    } 
  
        if(fibMMm1 && rand_arr[offset+1]==x)return offset+1; 
  
        return -1; 
} 

/************************************************************SPIKE TEST***************************************************************/

int fibMonaccianSearch_spike(int32_t rand_arr[], int32_t x, int32_t size_1) 
{ 
    int32_t fibMMm2 = 0;  
    int32_t fibMMm1 = 1;       
    int32_t fibM = fibMMm2 + fibMMm1;    

      while (fibM < size_1) 
    { 
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM  = fibMMm2 + fibMMm1; 
    } 
  
   
    int32_t offset = -1; 
  
        while (fibM > 1) 
    { 
        
        int32_t i = MIN(offset+fibMMm2, size_1-1); 
  
                if (rand_arr[i] < x) 
        { 
            fibM  = fibMMm1; 
            fibMMm1 = fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
            offset = i; 
        } 
  
                else if (rand_arr[i] > x) 
        { 
            fibM  = fibMMm2; 
            fibMMm1 = fibMMm1 - fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
        } 
  
               else return i; 
    } 
  
        if(fibMMm1 && rand_arr[offset+1]==x)return offset+1; 
  
        return -1; 
}

//////////////////////////////////////////////////////////////////THE END///////////////////////////////////////////////////////////////////

