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
 ****************************************************************************
 *
 *                   "DHRYSTONE" Benchmark Program
 *                   -----------------------------
 *
 *  Version:    C, Version 2.1
 *
 *  File:       dhry_1.c (part 2 of 3)
 *
 *  Date:       May 25, 1988
 *
 *  Author:     Reinhold P. Weicker
 *
 ****************************************************************************
 */
#define USE_MYSTDLIB

#include<stdio.h>  
#include <stdlib.h>
//#include <time.h>>
#include <limits.h>             /*!< Datatype limit         */
#include <stdint.h>             /*!< Standarad Integer type */
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
#include "testmacro.h"          /*!< Test macros    */

#include "dhry.h"
#include "dhry_2.h"

#ifdef USE_MYSTDLIB
extern char     *malloc ();
#else
#  include <stdlib.h>
#  include <string.h>
#endif
/* Global Variables: */

Rec_Pointer     Ptr_Glob,
               Next_Ptr_Glob;
int             Int_Glob;
Boolean         Bool_Glob;
char            Ch_1_Glob,
                Ch_2_Glob;
int             Arr_1_Glob [50];
int             Arr_2_Glob [50] [50];

//extern char     *malloc ();
Enumeration     Func_1 ();
  /* forward declaration necessary since Enumeration may not simply be int */

#ifndef REG
        Boolean Reg = false;
#define REG
        /* REG becomes defined as empty */
        /* i.e. no register variables   */
#else
        Boolean Reg = true;
#endif

/* variables for time measurement: */
#define IGN_TIMES
//#define TIME

#define RISCV



#ifdef IGN_TIMES
//struct tms      time_info; //edited reshma-commanded
extern  int     times ();
                /* see library function "times" */
#define Too_Small_Time 120
                /* Measurements should last at least about 2 seconds */
#endif
#ifdef TIME
extern long     time();
#ifdef RISCV
extern long     insn();
#endif
                /* see library function "time"  */
#define Too_Small_Time 2
                /* Measurements should last at least 2 seconds */
#endif

long            Begin_Time,
                End_Time,
                User_Time;
#ifdef RISCV
long            Begin_Insn,
                End_Insn,
                User_Insn;
#endif
float           Microseconds,
                Dhrystones_Per_Second;

/* end of variables for time measurement */


main ()
/*****/

  /* main program, corresponds to procedures        */
  /* Main and Proc_0 in the Ada version             */
{
        One_Fifty       Int_1_Loc;
  REG   One_Fifty       Int_2_Loc;
        One_Fifty       Int_3_Loc;
  REG   char            Ch_Index;
        Enumeration     Enum_Loc;
        Str_30          Str_1_Loc;
        Str_30          Str_2_Loc;
  REG   int             Run_Index;
  REG   int             Number_Of_Runs;

  /* Initializations */

  Next_Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));
  Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));

  Ptr_Glob->Ptr_Comp                    = Next_Ptr_Glob;
  Ptr_Glob->Discr                       = Ident_1;
  Ptr_Glob->variant.var_1.Enum_Comp     = Ident_3;
  Ptr_Glob->variant.var_1.Int_Comp      = 40;
  strcpy (Ptr_Glob->variant.var_1.Str_Comp,
          "DHRYSTONE PROGRAM, SOME STRING");
  strcpy (Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING");

  Arr_2_Glob [8][7] = 10;
        /* Was missing in published program. Without this statement,    */
        /* Arr_2_Glob [8][7] would have an undefined value.             */
        /* Warning: With 16-Bit processors and Number_Of_Runs > 32000,  */
        /* overflow may occur for this array element.                   */
  z_printf ("\n");
  z_printf ("Dhrystone Benchmark, Version 2.1 (Language: C)\n");
  z_printf ("\n");
  if (Reg)
  {
    z_printf ("Program compiled with 'register' attribute\n");
    z_printf ("\n");
  }
  else
  {
    z_printf ("Program compiled without 'register' attribute\n");
    z_printf ("\n");
  }
  z_printf ("Please give the number of runs through the benchmark: ");
  {
    // int n;
    // scanf ("%d", &n);
    Number_Of_Runs = 2; //100
  }
  z_printf ("\n");

  z_printf ("Execution starts, %d runs through Dhrystone\n", Number_Of_Runs);

  /***************/
  /* Start timer */
  /***************/

/*#ifdef IGN_TIMES
  times (&time_info);
  Begin_Time = (long) time_info.tms_utime;
#endif
#ifdef TIME
  Begin_Time = time ( (long *) 0);*/
//#ifdef RISCV
//  Begin_Insn = insn ( (long *) 0);
//#endif
//#endif

  
#define csr_asm_rwi(inst,rd,imm,imm1)\
        asm volatile (#inst "    %[z], "#imm", "#imm1"\n\t"  : [z] "=r" (rd)  )
        static uint64_t start,stop,r0,r1,r2,r3,r4,r5,start_instn,stop_instn,start_cycle,stop_cycle;
        //static unsigned long start,stop,r0,r1,r2,r3,r4,r5,start_instn,stop_instn,start_cycle,stop_cycle;
     z_printf("start timer"); 
     csr_asm_rwi( csrrwi,r0,0x320,0); //inhibit -clear
      csr_asm_rwi(csrrwi,r1,0xB03,0);  //  counter3
           start=r1;
     csr_asm_rwi( csrrwi,r2,0x323,1); // Event  reg -set
                 //  csr_asm_rwi(csrrwi,start_cycle,0xB00,0);   //mcycle  
        
                   csr_asm_rwi(csrrwi,start_cycle,0xB00,0);   //mcycle  
                  // csr_asm_rwi(csrrwi,start_instn,0xB02,0);
        csr_asm_rwi(csrrwi,start_instn,0xB02,0);  // instruction count -minstret

       for (Run_Index = 1; Run_Index <= Number_Of_Runs; ++Run_Index)
  {

    Proc_5();
    Proc_4();
      /* Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == true */
    Int_1_Loc = 2;
    Int_2_Loc = 3;
    strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
    Enum_Loc = Ident_2;
    Bool_Glob = ! Func_2 (Str_1_Loc, Str_2_Loc);
      /* Bool_Glob == 1 */
    while (Int_1_Loc < Int_2_Loc)  /* loop body executed once */
    {
      Int_3_Loc = 5 * Int_1_Loc - Int_2_Loc;
             /* Int_3_Loc == 7 */
      Proc_7 (Int_1_Loc, Int_2_Loc, &Int_3_Loc); 
        /* Int_3_Loc == 7 */
      Int_1_Loc += 1;
    } /* while */
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Proc_8 (Arr_1_Glob, Arr_2_Glob, Int_1_Loc, Int_3_Loc);
        /* Int_Glob == 5 */
    Proc_1 (Ptr_Glob);
    for (Ch_Index = 'A'; Ch_Index <= Ch_2_Glob; ++Ch_Index)
                             /* loop body executed twice */
    {
      if (Enum_Loc == Func_1 (Ch_Index, 'C'))
          /* then, not executed */
        {
        Proc_6 (Ident_1, &Enum_Loc);
        strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 3'RD STRING");
        Int_2_Loc = Run_Index;
        Int_Glob = Run_Index;
        }
    }
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Int_2_Loc = Int_2_Loc * Int_1_Loc;
    Int_1_Loc = Int_2_Loc / Int_3_Loc;
    Int_2_Loc = 7 * (Int_2_Loc - Int_3_Loc) - Int_1_Loc;
      /* Int_1_Loc == 1, Int_2_Loc == 13, Int_3_Loc == 7 */
    Proc_2 (&Int_1_Loc);
      /* Int_1_Loc == 5 */

  } /* loop "for Run_Index" */

  /**************/
  /* Stop timer */
  /**************/
  //z_printf("stop timer");
   csr_asm_rwi(csrrwi,r4,0x323,0);
  csr_asm_rwi(csrrwi,r3,0x320,5);
  csr_asm_rwi(csrrwi,stop_instn,0xB02,0);  // instruction count
  csr_asm_rwi(csrrwi,r5,0xB03,0); //performance counter
     csr_asm_rwi(csrrwi,stop_cycle,0xB00,0);   //mcycle  
      stop=r5;
    z_printf ("begin time is  %l\n",start);
     z_printf ("begin instn is  %l\n",start_instn);

     z_printf ("begin cycle is  %l\n",start_cycle);

   z_printf ("stop time is  %l\n",stop);
  z_printf ("stop instn is  %l\n",stop_instn);
     z_printf ("stop cycle is  %l\n",stop_cycle);

 z_printf ("total time (from performance counter)is  %l\n",(stop - start));
  z_printf ("total instn (from minstret) is  %l\n",(stop_instn));
     z_printf ("total  cycle (from mcycle)is  %l\n",(stop_cycle));

     //z_printf ("total  cycle (from mcycle)is  %l\n",(stop_cycle - start_cycle));
  //z_printf ("total instn (from minstret) is  %l\n",(stop_instn-start_instn));
/*
#ifdef IGN_TIMES
  times (&time_info);
  End_Time = (long) time_info.tms_utime;
#endif
#ifdef TIME
  End_Time = time ( (long *) 0);*/
//#ifdef RISCV
 // End_Insn = insn ( (long *) 0);
//#endif
//#endif

  z_printf ("Execution ends\n");
  z_printf ("\n");
  z_printf ("Final values of the variables used in the benchmark:\n");
  z_printf ("\n");
  z_printf ("Int_Glob:            %d\n", Int_Glob);
  z_printf ("        should be:   %d\n", 5);
  z_printf ("Bool_Glob:           %d\n", Bool_Glob);
  z_printf ("        should be:   %d\n", 1);
  z_printf ("Ch_1_Glob:           %c\n", Ch_1_Glob);
  z_printf ("        should be:   %c\n", 'A');
  z_printf ("Ch_2_Glob:           %c\n", Ch_2_Glob);
  z_printf ("        should be:   %c\n", 'B');
  z_printf ("Arr_1_Glob[8]:       %d\n", Arr_1_Glob[8]);
  z_printf ("        should be:   %d\n", 7);
  z_printf ("Arr_2_Glob[8][7]:    %d\n", Arr_2_Glob[8][7]);
  z_printf ("        should be:   Number_Of_Runs + 10\n");
  z_printf ("Ptr_Glob->\n");
  z_printf ("  Ptr_Comp:          %d\n", (int) Ptr_Glob->Ptr_Comp);
  z_printf ("        should be:   (implementation-dependent)\n");
  z_printf ("  Discr:             %d\n", Ptr_Glob->Discr);
  z_printf ("        should be:   %d\n", 0);
  z_printf ("  Enum_Comp:         %d\n", Ptr_Glob->variant.var_1.Enum_Comp);
  z_printf ("        should be:   %d\n", 2);
  z_printf ("  Int_Comp:          %d\n", Ptr_Glob->variant.var_1.Int_Comp);
  z_printf ("        should be:   %d\n", 17);
  z_printf ("  Str_Comp:          %s\n", Ptr_Glob->variant.var_1.Str_Comp);
  z_printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  z_printf ("Next_Ptr_Glob->\n");
  z_printf ("  Ptr_Comp:          %d\n", (int) Next_Ptr_Glob->Ptr_Comp);
  z_printf ("        should be:   (implementation-dependent), same as above\n");
  z_printf ("  Discr:             %d\n", Next_Ptr_Glob->Discr);
  z_printf ("        should be:   %d\n", 0);
  z_printf ("  Enum_Comp:         %d\n", Next_Ptr_Glob->variant.var_1.Enum_Comp);
  z_printf ("        should be:   %d\n", 1);
  z_printf ("  Int_Comp:          %d\n", Next_Ptr_Glob->variant.var_1.Int_Comp);
  z_printf ("        should be:   %d\n", 18);
  z_printf ("  Str_Comp:          %s\n",
                                Next_Ptr_Glob->variant.var_1.Str_Comp);
  z_printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  z_printf ("Int_1_Loc:           %d\n", Int_1_Loc);
  z_printf ("        should be:   %d\n", 5);
  z_printf ("Int_2_Loc:           %d\n", Int_2_Loc);
  z_printf ("        should be:   %d\n", 13);
  z_printf ("Int_3_Loc:           %d\n", Int_3_Loc);
  z_printf ("        should be:   %d\n", 7);
  z_printf ("Enum_Loc:            %d\n", Enum_Loc);
  z_printf ("        should be:   %d\n", 1);
  z_printf ("Str_1_Loc:           %s\n", Str_1_Loc);
  z_printf ("        should be:   DHRYSTONE PROGRAM, 1'ST STRING\n");
  z_printf ("Str_2_Loc:           %s\n", Str_2_Loc);
  z_printf ("        should be:   DHRYSTONE PROGRAM, 2'ND STRING\n");
  z_printf ("\n");

  User_Time = stop - start;

  //User_Time = End_Time - Begin_Time;
#ifdef RISCV
//  User_Insn = End_Insn - Begin_Insn;

  //User_Insn = stop_instn - start_instn;
  User_Insn = stop_instn ;
  z_printf("Number_Of_Runs: %d\n", Number_Of_Runs);
  z_printf("User_Time: %d cycles, %d insn\n", User_Time, User_Insn);

  int Cycles_Per_Instruction_x1000 = (1000 * User_Time) / User_Insn;
  z_printf("Cycles_Per_Instruction: %d.%d%d%d\n", Cycles_Per_Instruction_x1000 / 1000,
		(Cycles_Per_Instruction_x1000 / 100) % 10,
		(Cycles_Per_Instruction_x1000 / 10) % 10,
		(Cycles_Per_Instruction_x1000 / 1) % 10);

  int Dhrystones_Per_Second_Per_MHz = (Number_Of_Runs * 1000000) / User_Time;
  z_printf("Dhrystones_Per_Second_Per_MHz: %d\n", Dhrystones_Per_Second_Per_MHz);

  int DMIPS_Per_MHz_x1000 = (1000 * Dhrystones_Per_Second_Per_MHz) / 1757;
  z_printf("DMIPS_Per_MHz: %d.%d%d%d\n", DMIPS_Per_MHz_x1000 / 1000,
		(DMIPS_Per_MHz_x1000 / 100) % 10,
		(DMIPS_Per_MHz_x1000 / 10) % 10,
		(DMIPS_Per_MHz_x1000 / 1) % 10);

#else
  if (User_Time < Too_Small_Time)
  {
    z_printf ("Measured time too small to obtain meaningful results\n");
    z_printf ("Please increase number of runs\n");
    z_printf ("\n");
  }
  else
  {
#ifdef TIME
    Microseconds = (float) User_Time * Mic_secs_Per_Second
                        / (float) Number_Of_Runs;
    Dhrystones_Per_Second = (float) Number_Of_Runs / (float) User_Time;
#else
     Microseconds = (float) User_Time * Mic_secs_Per_Second
                        / (float) Number_Of_Runs;
    Dhrystones_Per_Second = (float) Number_Of_Runs / (float) User_Time;

   /* Microseconds = (float) User_Time * Mic_secs_Per_Second
                        / ((float) HZ * ((float) Number_Of_Runs));
    Dhrystones_Per_Second = ((float) HZ * (float) Number_Of_Runs)
                        / (float) User_Time;*/
#endif
    z_printf ("Microseconds for one run through Dhrystone: ");
    z_printf ("%6.1f \n", Microseconds);
    z_printf ("Dhrystones per Second:                      ");
    z_printf ("%6.1f \n", Dhrystones_Per_Second);
    z_printf ("\n");
  }
#endif
mailbox_send_request(MAILBOX1, END_SIM);
 mailbox_send_request(MAILBOX2, error_cnt);
}


Proc_1 (Ptr_Val_Par)
/******************/

REG Rec_Pointer Ptr_Val_Par;
    /* executed once */
{

  //z_printf ("inside proc1\n");
  REG Rec_Pointer Next_Record = Ptr_Val_Par->Ptr_Comp;
                                        /* == Ptr_Glob_Next */
  /* Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    */
  /* corresponds to "rename" in Ada, "with" in Pascal           */

 // z_printf ("inside proc1\n");
  structassign (*Ptr_Val_Par->Ptr_Comp, *Ptr_Glob);
//Ptr_Val_Par->Ptr_Comp= Ptr_Glob;
  //z_printf ("inside proc1\n");
  Ptr_Val_Par->variant.var_1.Int_Comp = 5;
  Next_Record->variant.var_1.Int_Comp
        = Ptr_Val_Par->variant.var_1.Int_Comp;
  Next_Record->Ptr_Comp = Ptr_Val_Par->Ptr_Comp;
 // z_printf ("inside proc1\n");
  Proc_3 (&Next_Record->Ptr_Comp);
    /* Ptr_Val_Par->Ptr_Comp->Ptr_Comp
                        == Ptr_Glob->Ptr_Comp */
  if (Next_Record->Discr == Ident_1)
    /* then, executed */
  {
    Next_Record->variant.var_1.Int_Comp = 6;
    Proc_6 (Ptr_Val_Par->variant.var_1.Enum_Comp,
           &Next_Record->variant.var_1.Enum_Comp);
    Next_Record->Ptr_Comp = Ptr_Glob->Ptr_Comp;
    Next_Record->variant.var_1.Int_Comp = 6;  //added for tsting
    Proc_7 (Next_Record->variant.var_1.Int_Comp, 10,
           &Next_Record->variant.var_1.Int_Comp);
  }
  else /* not executed */
    structassign (*Ptr_Val_Par, *Ptr_Val_Par->Ptr_Comp);
 // Ptr_Val_Par= Ptr_Val_Par->Ptr_Comp;
} /* Proc_1 */


Proc_2 (Int_Par_Ref)
/******************/
    /* executed once */
    /* *Int_Par_Ref == 1, becomes 4 */

One_Fifty   *Int_Par_Ref;
{
 // z_printf ("inside proc2\n");
  One_Fifty  Int_Loc;
  Enumeration   Enum_Loc;

  Int_Loc = *Int_Par_Ref + 10;
  do /* executed once */
    if (Ch_1_Glob == 'A')
      /* then, executed */
    {
      Int_Loc -= 1;
      *Int_Par_Ref = Int_Loc - Int_Glob;
      Enum_Loc = Ident_1;
    } /* if */
  while (Enum_Loc != Ident_1); /* true */
} /* Proc_2 */


Proc_3 (Ptr_Ref_Par)
/******************/
    /* executed once */
    /* Ptr_Ref_Par becomes Ptr_Glob */

Rec_Pointer *Ptr_Ref_Par;

{
 // z_printf ("inside proc3\n");
  if (Ptr_Glob != Null)
    /* then, executed */
    *Ptr_Ref_Par = Ptr_Glob->Ptr_Comp;
  Proc_7 (10, Int_Glob, &Ptr_Glob->variant.var_1.Int_Comp);
} /* Proc_3 */


Proc_4 () /* without parameters */
/*******/
    /* executed once */
{
 // z_printf ("inside proc4\n");
  Boolean Bool_Loc;

  Bool_Loc = Ch_1_Glob == 'A';
  Bool_Glob = Bool_Loc | Bool_Glob;
  Ch_2_Glob = 'B';
} /* Proc_4 */


Proc_5 () /* without parameters */
/*******/
    /* executed once */
{
 // z_printf ("inside proc5\n");
  Ch_1_Glob = 'A';
  Bool_Glob = false;
} /* Proc_5 */

        /* Procedure for the assignment of structures,          */
        /* if the C compiler doesn't support this feature       */
#ifdef  NOSTRUCTASSIGN
memcopy (d, s, l)
register char   *d;
register char   *s;
register int    l;
{
        while (l--) *d++ = *s++;
}
#endif
