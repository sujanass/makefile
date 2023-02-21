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
/*
Copyright 2018 Embedded Microprocessor Benchmark Consortium (EEMBC)
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
Original Author: Shay Gal-on
*/

#include <stdio.h>
#include <stdlib.h>


#if VALIDATION_RUN
volatile ee_s32 seed1_volatile = 0x3415;
volatile ee_s32 seed2_volatile = 0x3415;
volatile ee_s32 seed3_volatile = 0x66;
#endif
#if PERFORMANCE_RUN
volatile ee_s32 seed1_volatile = 0x0;
volatile ee_s32 seed2_volatile = 0x0;
volatile ee_s32 seed3_volatile = 0x66;
#endif
#if PROFILE_RUN
volatile ee_s32 seed1_volatile = 0x8;
volatile ee_s32 seed2_volatile = 0x8;
volatile ee_s32 seed3_volatile = 0x8;
#endif
volatile ee_s32 seed4_volatile = 0x1; //ITERATIONS;
volatile ee_s32 seed5_volatile = 0;
/* Porting : Timing functions
        How to capture time and convert to seconds must be ported to whatever is
   supported by the platform. e.g. Read value from on board RTC, read value from
   cpu clock cycles performance counter etc. Sample implementation for standard
   time.h and windows.h definitions included.
*/
/* Define : TIMER_RES_DIVIDER
        Divider to trade off timer resolution and total time that can be
   measured.
        Use lower values to increase resolution, but make sure that overflow
   does not occur. If there are issues with the return value overflowing,
   increase this value.
        */
#define CLOCKS_PER_SEC  100000000
#define NSECS_PER_SEC              CLOCKS_PER_SEC
#define CORETIMETYPE              unsigned long // clock_t
//#define GETMYTIME(_t)              (*_t = clock())
#define MYTIMEDIFF(fin, ini)       ((fin) - (ini))
#define TIMER_RES_DIVIDER          1
#define SAMPLE_TIME_IMPLEMENTATION 1
#define EE_TICKS_PER_SEC           (NSECS_PER_SEC / TIMER_RES_DIVIDER)

/** Define Host specific (POSIX), or target specific global time variables. */
static CORETIMETYPE start_time_val, stop_time_val;

/* Function : start_time
        This function will be called right before starting the timed portion of
   the benchmark.
        Implementation may be capturing a system timer (as implemented in the
   example code) or zeroing some system parameters - e.g. setting the cpu clocks
   cycles to 0.
*/
#define csr_asm_rwi(inst,rd,imm,imm1)\
        asm volatile (#inst "    %[z], "#imm", "#imm1"\n\t"  : [z] "=r" (rd)  )
static CORETIMETYPE  start,stop,start_cycle,start_instn,stop_cycle,stop_instn;
CORETIMETYPE r0,r1,r2,r3,r4,r5;
    
    void
start_time(void)
{
  csr_asm_rwi( csrrwi,r0,0x320,0); //inhibit -clear
      csr_asm_rwi(csrrwi,r1,0xB03,0);  //  counter3
           start=r1;
     csr_asm_rwi( csrrwi,r2,0x323,1); // Event  reg -set
                 //  csr_asm_rwi(csrrwi,start_cycle,0xB00,0);   //mcycle  
        
                   csr_asm_rwi(csrrwi,start_cycle,0xB00,0);   //mcycle  
                  // csr_asm_rwi(csrrwi,start_instn,0xB02,0);
        csr_asm_rwi(csrrwi,start_instn,0xB02,0);  // instruction count -minstret


}
/* Function : stop_time
        This function will be called right after ending the timed portion of the
   benchmark.
        Implementation may be capturing a system timer (as implemented in the
   example code) or other system parameters - e.g. reading the current value of
   cpu cycles counter.
*/
void
stop_time(void)
{
        csr_asm_rwi(csrrwi,r4,0x323,0);
  csr_asm_rwi(csrrwi,r3,0x320,1);
  csr_asm_rwi(csrrwi,stop_instn,0xB02,0);  // instruction count
  csr_asm_rwi(csrrwi,r5,0xB03,0); //performance counter
     csr_asm_rwi(csrrwi,stop_cycle,0xB00,0);   //mcycle  
      stop=r5;

   
}
/* Function : get_time
        Return an abstract "ticks" number that signifies time on the system.
        Actual value returned may be cpu cycles, milliseconds or any other
   value, as long as it can be converted to seconds by <time_in_secs>. This
   methodology is taken to accomodate any hardware or simulated platform. The
   sample implementation returns millisecs by default, and the resolution is
   controlled by <TIMER_RES_DIVIDER>
*/
CORE_TICKS
get_time(void)
{
    CORE_TICKS elapsed
        = (CORE_TICKS)(MYTIMEDIFF(stop, start));
    return elapsed;
}

CORE_TICKS
get_cycle(void)
{
    CORE_TICKS elapsed
        = (CORE_TICKS)(MYTIMEDIFF(stop_cycle, start_cycle));
    return elapsed;
}

CORE_TICKS
get_instn(void)
{
    CORE_TICKS elapsed
        = (CORE_TICKS)(MYTIMEDIFF(stop_instn, start_instn));
    return elapsed;
}

/* Function : time_in_secs
        Convert the value returned by get_time to seconds.
        The <secs_ret> type is used to accomodate systems with no support for
   floating point. Default implementation implemented by the EE_TICKS_PER_SEC
   macro above.
*/
secs_ret
time_in_secs(CORE_TICKS ticks)
{
    return ticks;
   // secs_ret retval = ((secs_ret)ticks) / (secs_ret)EE_TICKS_PER_SEC;
   // return retval;
    //return ticks;
}

ee_u32 default_num_contexts = 1;

/* Function : portable_init
        Target specific initialization code
        Test for some common mistakes.
*/
void
portable_init(core_portable *p, int *argc, char *argv[])
{
    if (sizeof(ee_ptr_int) != sizeof(ee_u8 *))
    {
        z_printf(
            "ERROR! Please define ee_ptr_int to a type that holds a "
            "pointer!ee_u8 %d  ee_ptr_int %d \n",sizeof(ee_u8 *),sizeof(ee_ptr_int) );
    }
    if (sizeof(ee_u32) != 4)
    {
        z_printf("ERROR! Please define ee_u32 to a 32b unsigned type!\n");
    }
    p->portable_id = 1;
}
/* Function : portable_fini
        Target specific final code
*/
void
portable_fini(core_portable *p)
{
    p->portable_id = 0;
}
