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
#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>            
//#include <stdint.h>
#include "print.h"
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
#include "average.h"
#ifdef SPIKE_RUN
#include "data.h"               /*!< Testbench created data */
#endif

#define TEST_COUNT     (3)    /*!< Test count             */
#define DATA_SET        (12)  /*!< array of 10 elements+2(for int part and fractional part)>*/
#define TEST_TYPES      (1)   /*!< Exponential Search*/
   

int64_t actual_result[TEST_COUNT*DATA_SET*TEST_TYPES] __attribute((section(".results"))) = {0,};
int32_t *p ;

#define ABS(x) ((x) >= 0 ? (x) : -(x))
#define DECIMAL_FACTOR 1000
#define LIT(x) ((uint64_t)((x) * DECIMAL_FACTOR))
#define INT_PART(x) ((x) / DECIMAL_FACTOR)
#define DEC_PART(x) (ABS((x) % DECIMAL_FACTOR))
//#define csr_asm_rw(insn,rd,csr_add,rs1)(asm volatile (#insn " %[z], "#csr_add",%[y]\n\t" : [z] "=r" (rd) : [y] "r" (rs1)))


/*typedef struct {
       uint8_t   mhpmevent3;
   }EVENT_t;

#define EVENT ((volatile EVENT_t*) 0x0323)

 typedef struct {
     uint8_t   mcounterinhibit;
 }INHIBIT_t;

#define INHIBIT ((volatile INHIBIT_t*) 0x0320)
 typedef struct {  
     uint8_t   mhpmcounter3;  
   }COUNTER_t;

#define COUNTER ((volatile COUNTER_t*) 0x0B03)*/
int main(void) 
{
        volatile int testnumber   = 1;
	    volatile int testtypenum  = 0;
   	    int32_t num_of_elements_memdump;
	    num_of_elements_memdump = (TEST_COUNT*12*1);
        int r0;
    //csr_asm_rw(csrrc,r0,803,0); /// 803 is in decimal, which is equal to 323 in hexa
    //csr_asm_rw(csrrs,r0,803,18446744073709551615);
for(int testnumber = 1; testnumber <= TEST_COUNT; testnumber++)
	{

#ifdef SPIKE_RUN
        uint16_t e_rand_arr[10]; 
        uint32_t n=sizeof(e_rand_arr)/ sizeof(e_rand_arr[0]);
        for(int8_t i=0;i<n;i++)
        { 
            e_rand_arr[i] = (int16_t)data[(testnumber-1)*12 + i];                 
        }
           
        uint64_t rslt_tb_int = (int32_t)data[(testnumber-1)*12 + 10];
        uint64_t rslt_tb_fract = (int32_t)data[(testnumber-1)*12 + 11];
        
        uint64_t total=0;
        for(uint32_t i=0;i<n;i++)
        {  
            printf("Random array %u\n",e_rand_arr[i]);
            total=total+e_rand_arr[i];
        }
    
        printf("total %u\n", total);
        total=LIT(total);
        uint64_t avg_spike=(total/n);
        uint64_t rslt_full_int=INT_PART(avg_spike);
        uint64_t rslt_full_fract=DEC_PART(avg_spike);

        printf("Average is %u.%u",rslt_full_int,rslt_full_fract);
        PRINT_RESULT_AVERAGE(rslt_tb_int,rslt_tb_fract,rslt_full_int,rslt_full_fract);
    
#else	
       // csr_asm_rw(csrrc,r0,803,0); 
       // csr_asm_rw(csrrs,r0,803,18446744073709551615);
        RAND_ARR_SEARCH(MAILBOX1,testnumber);
        uint32_t n=sizeof(rand_arr)/ sizeof(rand_arr[0]);
        uint64_t total=0;
        for(uint32_t i=0;i<n;i++)
        {  
            rand_arr[i] = (uint16_t)(*p);
            p++;
            z_printf("Random array %u\n",rand_arr[i]);
            total=total+rand_arr[i];
        }
    
        z_printf("total %u\n", total);
        total=LIT(total);
        uint64_t avg=(total/n);
        uint64_t rslt_full_int=INT_PART(avg);
        uint64_t rslt_full_fract=DEC_PART(avg);
        z_printf("Average is %u.%u",rslt_full_int,rslt_full_fract);
        actual_result[(testnumber-1)*12 + 10] = rslt_full_int;
        actual_result[(testnumber-1)*12 + 11] = rslt_full_fract;
        //csr_asm_rw(csrrc,r0,803,0); 
        //z_printf("%d\n",COUNTER -> mhpmcounter3);

#endif
    p=p+1;
    }
    mailbox_send_request(MAILBOX1, MEM_DUMP);
	mailbox_send_request(MAILBOX2,num_of_elements_memdump);
	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt); 
    return 0;
    //csr_asm_rw(csrrc,r0,803,0); 
//    z_printf("%d\n",COUNTER -> mhpmcounter3);
}
