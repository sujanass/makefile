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
/************************************************************************************************************
 ***                                                               
 ***                                          CSR TEST PLAN  
 ***
 ************************************************************************************************************/

#include <stdio.h>       // Standard Input_Output Library
#include "print.h"       // Print Mailbox function Library
#include "linker.h"      // Linker Symbol Library
#include "mailbox.h"     // Mailbox Function Library
#include "trapapi.h"     // trapapi includes info related to inteerupts and exceptions
#include "csr.h"         // Includes Info related to mask_id's for CSR Registers



// Register-Register Type Instruction Macro Declaration
#define csr_asm_rw(insn,rd,csr_add,rs1)\
    asm volatile (#insn " %[z], "#csr_add",%[y]\n\t" : [z] "=r" (rd) : [y] "r" (rs1));

// Immediate Type Instruction Macro Declaration
#define csr_asm_rw_i(insn,rd,csr_add,imm)\
    asm volatile (#insn " %[z], "#csr_add", "#imm"\n\t" : [z] "=r" (rd));

extern volatile int irq_asserted  ;

int main()
{
    uint64_t rs1;
    uint64_t r1,r2,r3,r4,r5,r6;
    int      EXP_CSR_READ;
 //   int r0;  

//Function declaration to randomize rs1
int r0;
  csr_asm_rs(csrrsi,r0,768,8); // Enable Mstatus mie bit (write to mstatus_csr) : neesd to be enabled to accept interrupt requests
     //GEN_INT(IRQ_GEN_5);

z_printf("zzzzzzzzzzzzzzzzzzzzzzzzzzz");
 INST_MISALIGNED_EXCEPTION;
 ILLEGAL_INSTRUCTION;
   uint64_t rand_num()
    {
               
        rs1 = (uint64_t)generate_random_num(MAILBOX1); 
        z_printf("Generated Random Number_rs1 = %u\n",rs1);
    
    }

   ///////////////////////////  MVENDORID_READ_ONLY REGISTER   //////////////////////////////////

    
    z_printf("///////////////////////    MVENDORID_READ_ONLY    ////////////////////\n");
    

    csr_asm_rw(csrrw,r0,3857,UINT64_MIN);
    //z_printf("Actual_mvendorid = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN & MASK_MVENDORID);
    z_printf("Expected_mvendorid = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrw,r0,3857,UINT64_MAX);
    z_printf("Actual_mvendorid = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MAX & MASK_MVENDORID);
    z_printf("Expected_mvendorid = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,3857,UINT64_MIN);
    z_printf("Actual_mvendorid = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN & MASK_MVENDORID);
    z_printf("Expected_mvendorid = %u\n",EXP_CSR_READ);
 

    for(int i = 0; i < 5; i++)
    {
        rand_num();
      
        csr_asm_rw(csrrw,r0,3857,rs1);
        z_printf("Actual_mvendorid = %u\n",r0);  
        
        EXP_CSR_READ = (rs1 & MASK_MVENDORID);
        z_printf("Expected_mvendorid = %u\n",EXP_CSR_READ);

    }
    csr_asm_rw(csrrw,r0,3857,UINT64_MIN);
    z_printf("Actual_mvendorid = %u\n",r0);

    ////////////////////////////////////////
   csr_asm_rw(csrrw,r0,1968,0xFFFFFFFFFFFFFFFF);  
  csr_asm_rw(csrrw,r0,1968,0x0000000000000000);  
  csr_asm_rw(csrrc,r0,1968,0);
  csr_asm_rw(csrrs,r0,1968,0xFFFFFFFFFFFFFFFF);
  csr_asm_rw(csrrc,r0,1968,0);
  csr_asm_rw(csrrc,r0,1968,1);

  csr_asm_rw(csrrs,r0,1968,0x8000000000000000);

csr_asm_rw(csrrw,r0,1969,0xFFFFFFFFFFFFFFFF);  
  csr_asm_rw(csrrw,r0,1969,0x0000000000000000);  
  csr_asm_rw(csrrc,r0,1969,0);
  csr_asm_rw(csrrs,r0,1969,0xFFFFFFFFFFFFFFFF);
  csr_asm_rw(csrrc,r0,1969,0);
  csr_asm_rw(csrrc,r0,1969,1);

  csr_asm_rw(csrrs,r0,1969,0x8000000000000000);

    ///////////////////////////  MARCHID_READ_ONLY REGISTER   //////////////////////////////////

    z_printf("///////////////////////   MARCHID_READ_ONLY   /////////////////////\n");

    
    csr_asm_rw(csrrw,r0,3858,UINT64_MIN);
    //z_printf("Actual_marchid = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN & MASK_MARCHID);
    z_printf("Expected_marchid = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,3858,UINT64_MAX);
    z_printf("Actual_marchid = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MAX & MASK_MARCHID);
    z_printf("Expected_marchid = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,3858,UINT64_MIN);
    z_printf("Actual_marchid = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN & MASK_MARCHID);
    z_printf("Expected_marchid = %u\n",EXP_CSR_READ);
    
    for(int i = 0; i < 5; i++)
    {
        rand_num();

        csr_asm_rw(csrrw,r0,3858,rs1);
        z_printf("Actual_marchid = %u\n",r0);

        EXP_CSR_READ = (rs1 & MASK_MARCHID);
        z_printf("Expected_marchid = %u\n",EXP_CSR_READ);

    }
    csr_asm_rw(csrrw,r0,3858,UINT64_MIN);
    z_printf("Actual_marchid = %u\n",r0);


    ///////////////////////////  MIMPID_READ_ONLY REGISTER   //////////////////////////////////

    z_printf("///////////////////////   MIMPID_READ_ONLY   /////////////////////\n");   
    
    
    csr_asm_rw(csrrw,r0,3859,UINT64_MIN);
    //z_printf("Actual_mimpid = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN & MASK_MIMPID);
    z_printf("Expected_mimpid = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrw,r0,3859,UINT64_MAX);
    z_printf("Actual_mimpid = %u\n",r0);

    EXP_CSR_READ = (UINT64_MAX & MASK_MIMPID);
    z_printf("Expected_mimpid = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,3859,UINT64_MIN);
    z_printf("Actual_mimpid = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN & MASK_MIMPID);
    z_printf("Expected_mimpid = %u\n",EXP_CSR_READ);

    for(int i = 0; i < 5; i++)
    {
        rand_num();

        csr_asm_rw(csrrw,r0,3859,rs1);
        z_printf("Actual_mimpid = %u\n",r0);

        EXP_CSR_READ = (rs1 & MASK_MIMPID);
        z_printf("Expected_mimpid = %u\n",EXP_CSR_READ);
    } 
    csr_asm_rw(csrrw,r0,3859,UINT64_MIN);
    z_printf("Actual_mimpid = %u\n",r0);


    ///////////////////////////  MHARTID_READ_ONLY REGISTER   //////////////////////////////////

    z_printf("///////////////////////   MHARTID_READ_ONLY   /////////////////////\n");


    csr_asm_rw(csrrs,r0,3860,UINT64_MIN);
    //z_printf("Actual_mhartid = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN & MASK_MHARTID);
    z_printf("Expected_mhartid = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,3860,UINT64_MAX);
    z_printf("Actual_mhartid = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MAX & MASK_MHARTID);
    z_printf("Expected_mhartid = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,3860,UINT64_MIN);
    z_printf("Actual_mhartid = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN & MASK_MHARTID);
    z_printf("Expected_mhartid = %u\n",EXP_CSR_READ);

    for(int i = 0; i < 5; i++)
    {
        rand_num();

        csr_asm_rw(csrrw,r0,3860,rs1);
        z_printf("Actual_mhartid = %u\n",r0);

        EXP_CSR_READ = (rs1 & MASK_MHARTID);
        z_printf("Expected_mhartid = %u\n",EXP_CSR_READ);
    }
    csr_asm_rw(csrrs,r0,3860,UINT64_MIN);
    z_printf("Actual_mhartid = %u\n",r0);

   
    ///////////////////////////   MSTATUS READ_WRITE REGISTER     /////////////////////////////////////////

    z_printf("///////////////////////   MSTATUS_READ_WRITE   /////////////////////\n"); 

    ///////////   CSRRW/I Instruction ///////////////////

    z_printf("////////////////    CSRRW    /////////////////\n");
   
    // 12th & 11th bit = fixed to 1 , 7th & 3rd = writable

    csr_asm_rw(csrrw,r0,768,UINT64_MIN);                                          
    //z_printf("Actual_mstatus_csrrw_min = %u\n",r0);
    
    EXP_CSR_READ = ((UINT64_MIN | MASK_MSTATUS_1) & MASK_MSTATUS_2);
    z_printf("Expected_mstatus_csrrw = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrw,r0,768,UINT64_MAX);                                          
    z_printf("Actual_mstatus_csrrw_max = %u\n",r0);
    
    EXP_CSR_READ = ((UINT64_MAX | MASK_MSTATUS_1) & MASK_MSTATUS_2);
    z_printf("Expected_mstatus_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,768,UINT64_MIN);                                          
    z_printf("Actual_mstatus_csrrw_min = %u\n",r0);

    EXP_CSR_READ = ((UINT64_MIN | MASK_MSTATUS_1) & MASK_MSTATUS_2);
    z_printf("Expected_mstatus_csrrw = %u\n",EXP_CSR_READ);
  
    for(int i = 0; i < 5; i++)
    {
        rand_num();

        csr_asm_rw(csrrw,r0,768,rs1);
        z_printf("Actual_mstatus_csrrw = %u\n",r0);

        EXP_CSR_READ = ((rs1 | MASK_MSTATUS_1) & MASK_MSTATUS_2);
        z_printf("Expected_mstatus_csrrw = %u\n",EXP_CSR_READ);

    } 

    csr_asm_rw(csrrw,r0,768,UINT64_MIN);
    z_printf("Actual_mstatus_csrrw = %u\n",r0);

    EXP_CSR_READ = ((UINT64_MIN | MASK_MSTATUS_1) & MASK_MSTATUS_2);
    z_printf("Expected_mstatus_csrrw = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,768,31);
    z_printf("Actual_mstatus_csrrwi = %u\n",r0);
    
    //////////////////////      IMMEDIATE INSTRUCTION    /////////////////////////////

    z_printf("////////////////   CSRRWI   /////////////////\n");
           
    EXP_CSR_READ = ((31 | MASK_MSTATUS_1) & MASK_MSTATUS_2);
    z_printf("Expected_mstatus_csrrw = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,768,25);
    z_printf("Actual_mstatus_csrrwi = %u\n",r0);

    EXP_CSR_READ = ((25 | MASK_MSTATUS_1) & MASK_MSTATUS_2);
    z_printf("Expected_mstatus_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,768,13);
    z_printf("Actual_mstatus_csrrwi = %u\n",r0);

    EXP_CSR_READ = ((13 | MASK_MSTATUS_1) & MASK_MSTATUS_2);
    z_printf("Expected_mstatus_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,768,19);
    z_printf("Actual_mstatus_csrrwi = %u\n",r0);

    EXP_CSR_READ = ((19 | MASK_MSTATUS_1) & MASK_MSTATUS_2);
    z_printf("Expected_mstatus_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,768,0);
    z_printf("Actual_mstatus_csrrwi = %u\n",r0);


    /////////////////////////  CSRRS/I Instruction  ///////////////////////////// 
   
    z_printf("////////////////   CSRRS   /////////////////\n");

    csr_asm_rw (csrrs,r0,768,UINT64_MIN);
    //z_printf("Actual_mstatus_csrrs = %u\n",r0);
       
    EXP_CSR_READ = ((r0 | UINT64_MIN ) & MASK_MSTATUS_2) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw (csrrs,r0,768,UINT64_MAX);
    z_printf("Actual_mstatus_csrrs = %u\n",r0);
  
    EXP_CSR_READ = ((r0 | UINT64_MAX) & MASK_MSTATUS_2) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw (csrrs,r0,768,3539086163);
    z_printf("Actual_mstatus_csrrs = %u\n",r0);

    EXP_CSR_READ = ((r0 | 3539086163) & MASK_MSTATUS_2) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw (csrrs,r0,768,2901383633);
    z_printf("Actual_mstatus_csrrs = %u\n",r0);

    EXP_CSR_READ = ((r0 | 2901383633 ) & MASK_MSTATUS_2) | (MASK_MSTATUS_1);    
    z_printf("Expected_mstatus_csrrs = %u\n",EXP_CSR_READ);
        
    csr_asm_rw (csrrs,r0,768,UINT64_MIN);
    z_printf("Actual_mstatus_csrrs = %u\n",r0);    
     
    EXP_CSR_READ = ((r0 | UINT64_MIN) & MASK_MSTATUS_2) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrs = %u\n",EXP_CSR_READ);

    for(int i = 0; i < 5; i++)
    {
        
        rand_num();  
        
        csr_asm_rw(csrrs,r0,768,rs1);  
        z_printf("Actual_mstatus_csrrs = %u\n",r0);

        EXP_CSR_READ = ((r0 | rs1 ) & MASK_MSTATUS_2) | (MASK_MSTATUS_1);
        z_printf("Expected_mstatus_csrrs = %u\n",EXP_CSR_READ);
        
    }

    csr_asm_rw(csrrs,r0,768,UINT64_MIN);
    z_printf("Actual_mstatus_csrrs = %u\n",r0);
    
    EXP_CSR_READ = ((r0 | UINT64_MIN) & MASK_MSTATUS_2) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,768,31);
    z_printf("Actual_mstatus_csrrsi = %u\n",r0);

    ///////////////////  IMMEDIATE INSTRUCTION    /////////////////////////
    
    z_printf("////////////////   CSRRSI   /////////////////\n");

    EXP_CSR_READ = ((r0 | 31 ) & MASK_MSTATUS_2) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrsi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,768,5);
    z_printf("Actual_mstatus_csrrsi = %u\n",r0);

    EXP_CSR_READ = ((r0 | 5 ) & MASK_MSTATUS_2) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrsi = %u\n",EXP_CSR_READ);
  
    csr_asm_rw_i(csrrsi,r0,768,13);
    z_printf("Actual_mstatus_csrrsi = %u\n",r0);

    EXP_CSR_READ = ((r0 | 13 ) & MASK_MSTATUS_2) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrsi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,768,17);
    z_printf("Actual_mstatus_csrrsi = %u\n",r0);

    EXP_CSR_READ = ((r0 | 17 ) & MASK_MSTATUS_2) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrsi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,768,0);
    z_printf("Actual_mstatus_csrrsi = %u\n",r0);
     
 
    ////////////////////////////   CSRRC/I Instruction  /////////////////////////

    z_printf("////////////////   CSRRC   /////////////////\n");
    
    csr_asm_rw(csrrc,r0,768,UINT64_MIN);
    z_printf("Actual_mstatus_csrrc = %u\n",r0);
    
    EXP_CSR_READ = ((r0 | UINT64_MIN ) & MASK_MSTATUS_1) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrc = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,768,9865432);
    z_printf("Actual_mstatus_csrrc = %u\n",r0);

    EXP_CSR_READ = ((r0 | 9865432 ) & MASK_MSTATUS_1) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrc = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrc,r0,768,543673);
    z_printf("Actual_mstatus_csrrc = %u\n",r0);

    EXP_CSR_READ = ((r0 | 543673 ) & MASK_MSTATUS_1) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrc = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,768,UINT64_MAX);
    z_printf("Actual_mstatus_csrrc = %u\n",r0);

    EXP_CSR_READ = ((r0 | UINT64_MAX ) & MASK_MSTATUS_1) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrc = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrc,r0,768,UINT64_MIN);
    z_printf("Actual_mstatus_csrrc = %u\n",r0);
    
    EXP_CSR_READ = ((r0 | UINT64_MIN ) & MASK_MSTATUS_1) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrc = %u\n",EXP_CSR_READ);
    
    for(int i = 0; i < 5; i++)

    {

        rand_num();

        csr_asm_rw(csrrc,r0,768,rs1);
        z_printf("Actual_mstatus_csrrc = %u\n",r0);
    
        EXP_CSR_READ = ((r0 | rs1 ) & MASK_MSTATUS_1) | (MASK_MSTATUS_1);
        z_printf("Expected_mstatus_csrrc = %u\n",EXP_CSR_READ);

      
    }
    csr_asm_rw(csrrc,r0,768,UINT64_MIN);
    z_printf("Actual_mstatus_csrrc = %u\n",r0);

    EXP_CSR_READ = ((r0 | UINT64_MIN ) & MASK_MSTATUS_1) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrc = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,768,31);
    z_printf("Actual_mstatus_csrrci = %u\n",r0);
 

    ////////////////////////   IMMEDIATE INSTRUCTION    ///////////////////////////////

    z_printf("////////////////   CSRRCI   /////////////////\n");
   
    EXP_CSR_READ = ((r0 | 31 ) & MASK_MSTATUS_1) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrci = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,768,9);
    z_printf("Actual_mstatus_csrrci = %u\n",r0);
   
    EXP_CSR_READ = ((r0 | 9 ) & MASK_MSTATUS_1) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrci = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,768,16);
    z_printf("Actual_mstatus_csrrci = %u\n",r0);

    EXP_CSR_READ = ((r0 | 16 ) & MASK_MSTATUS_1) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrci = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,768,28);
    z_printf("Actual_mstatus_csrrci = %u\n",r0);
   
    EXP_CSR_READ = ((r0 | 28 ) & MASK_MSTATUS_1) | (MASK_MSTATUS_1);
    z_printf("Expected_mstatus_csrrci = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,768,0);
    z_printf("Actual_mstatus_csrrci = %u\n",r0);


    ///////////////////////////  MISA_READ ONLY REGISTER   //////////////////////////////////

    z_printf("///////////////////////   MISA_READ_ONLY   /////////////////////\n");
    
    // out of [25:0] extension fields, 8th,12th and 23rd bit fields should read 1 while remaining bit fields should read 0

    csr_asm_rw(csrrw,r0,769,UINT64_MIN);
    z_printf("Actual_misa_min = %u\n",r0);

    csr_asm_rw(csrrw,r0,769,UINT64_MAX);
    z_printf("Actual_misa_max = %u\n",r0);

    csr_asm_rw(csrrw,r0,769,UINT64_MIN);
    z_printf("Actual_misa_min = %u\n",r0);
    
    EXP_CSR_READ = ((UINT64_MAX & MASK_MISA) | (MASK_MISA));
    z_printf("Expected_misa = %u\n",EXP_CSR_READ);
    
    for(int i = 0; i < 5; i++)
    {
        rand_num();

        csr_asm_rw(csrrw,r0,769,rs1);       
        z_printf("Actual_misa = %u\n",r0);
                
        EXP_CSR_READ = ((rs1 & MASK_MISA) | (MASK_MISA));
        z_printf("Expected_misa = %u\n",EXP_CSR_READ);
    }
    csr_asm_rw(csrrw,r0,769,UINT64_MIN);
    z_printf("Actual_misa = %u\n",r0);
    

    /////////////////////////    MIE READ_WRITE REGISTER    ///////////////////////////////////////////
    
    z_printf("////////////////////    MIE_READ_WRITE   /////////////////////////\n"); 

    ///////////////////////   CSRRW INSTRUCTION    ///////////////////
    
    //3rd,7th and 11th bits are writable         
    
    z_printf("///////////    CSRRW  INSTRUCTION  /////////////////\n");

    csr_asm_rw(csrrw,r0,772,UINT64_MIN);                                
    //z_printf("Actual_mie_csrrw = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN & MASK_MIE);
    z_printf("Expected_mie = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,772,UINT64_MAX);                                
    z_printf("Actual_mie_csrrw = %u\n",r0);

    EXP_CSR_READ = (UINT64_MAX & MASK_MIE);
    z_printf("Expected_mie = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,772,UINT64_MIN);                                
    z_printf("Actual_mie_csrrw = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN & MASK_MIE);
    z_printf("Expected_mie = %u\n",EXP_CSR_READ);

    
    for(int i = 0; i < 5; i++)
    {
        rand_num();

        csr_asm_rw(csrrw,r0,772,rs1);
        z_printf("Actual_mie_csrrw = %u\n",r0);
       
        EXP_CSR_READ = (rs1 & MASK_MIE);
        z_printf("Expected_mie = %u\n",EXP_CSR_READ);
      
    } 
    csr_asm_rw(csrrw,r0,772,UINT64_MIN);
    z_printf("Actual_mie_csrrw = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN & MASK_MIE);
    z_printf("Expected_mie = %u\n",EXP_CSR_READ);    
     
    csr_asm_rw_i(csrrwi,r0,772,31);
    z_printf("Actual_mie_csrrwi = %u\n",r0);
   
    ///////////////////////////     IMMEDIATE INSTRUCTION       //////////////////////////    
    
    z_printf("////////////////   IMMEDIATE INSTRUCTION   /////////////////\n");
    
    EXP_CSR_READ = (31 & MASK_MIE);
    z_printf("Expected_mie = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,772,26);
    z_printf("Actual_mie_csrrwi = %u\n",r0);

    EXP_CSR_READ = (26 & MASK_MIE);
    z_printf("Expected_mie = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,772,7);
    z_printf("Actual_mie_csrrwi = %u\n",r0);
    
    EXP_CSR_READ = (7 & MASK_MIE);
    z_printf("Expected_mie = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,772,11);
    z_printf("Actual_mie_csrrwi = %u\n",r0);

    EXP_CSR_READ = (11 & MASK_MIE);
    z_printf("Expected_mie = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,772,0);
    z_printf("Actual_mie_csrrwi = %u\n",r0);
      

    /////////////////////////     CSRRS INSTRUCTION      ////////////////////////
   
    z_printf("/////////////////    CSRRS INSTRUCTION    /////////////////////\n");

    csr_asm_rw(csrrs,r0,772,UINT64_MIN);
    //z_printf("Actual_mie_csrrs = %u\n",r0);
    
    EXP_CSR_READ = ((UINT64_MIN | r0) & MASK_MIE );
    z_printf("Expected_mie_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrs,r0,772,2901383633);
    z_printf("Actual_mie_csrrs = %u\n",r0);

    EXP_CSR_READ = ((2901383633 | r0 ) & MASK_MIE );
    z_printf("Expected_mie_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,772,1648);
    z_printf("Actual_mie_csrrs = %u\n",r0);

    EXP_CSR_READ = ((1684 | r0) & MASK_MIE );
    z_printf("Expected_mie_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,772,3824302800);
    z_printf("Actual_mie_csrrs = %u\n",r0);

    EXP_CSR_READ = ((3824302800 | r0 ) & MASK_MIE );
    z_printf("Expected_mie_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,772,UINT64_MAX);
    z_printf("Actual_mie_csrrs = %u\n",r0);
    
    EXP_CSR_READ = ((UINT64_MAX |r0) & MASK_MIE);
    z_printf("Expected_mie_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,772,UINT64_MIN);
    z_printf("Actual_mie_csrrs= %u\n",r0);

    
    EXP_CSR_READ = ((r0 | UINT64_MIN) & MASK_MIE);
    z_printf("Expected_mie_csrrs = %u\n",EXP_CSR_READ);

    for(int i = 0; i < 5; i++)
    {

        rand_num();
   
        csr_asm_rw(csrrs,r0,772,rs1);
        z_printf("Actual_mie_csrrs = %u\n",r0);
  
        EXP_CSR_READ = ((rs1 | r0) & MASK_MIE);
        z_printf("Expected_mie_csrrs = %u\n",EXP_CSR_READ);
    
    }
    csr_asm_rw(csrrs,r0,772,UINT64_MIN);
    z_printf("Actual_mie_csrrs = %u\n",r0);

    EXP_CSR_READ = (( UINT64_MIN  | r0) & MASK_MIE);
    z_printf("Expected_mie_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrsi,r0,772,31);
    z_printf("Actual_mie_csrrsi = %u\n",r0);
    
    //////////////////   IMMEDIATE INSTRUCTION      /////////////////////////

    z_printf("////////////////   IMMEDIATE INSTRUCTION   /////////////////\n");


    EXP_CSR_READ = ((r0 | 31 ) & MASK_MIE);
    z_printf("Expected_mie_csrrsi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,772,18);
    z_printf("Actual_mie_csrrsi = %u\n",r0);

    EXP_CSR_READ = ((r0 | 18 ) & MASK_MIE);
    z_printf("Expected_mie_csrrsi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,772,26);
    z_printf("Actual_mie_csrrsi = %u\n",r0);

    EXP_CSR_READ = ((r0 | 26 ) & MASK_MIE);
    z_printf("Expected_mie_csrrsi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,772,7);
    z_printf("Actual_mie_csrrsi = %u\n",r0);

    EXP_CSR_READ = ((r0 | 7 ) & MASK_MIE);
    z_printf("Expected_mie_csrrsi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,772,11);
    z_printf("Actual_mie_csrrsi = %u\n",r0);
    
    EXP_CSR_READ = ((r0 | 11 ) & MASK_MIE);
    z_printf("Expected_mie_csrrsi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,772,0);
    z_printf("Actual_mie_csrrsi = %u\n",r0);
     
  
    /////////////////////////    CSRRC INSTRUCTION     ///////////////////////

    z_printf("////////////////   CSRRC INSTRUCTION  /////////////////\n");
   
    csr_asm_rw(csrrc,r0,772,UINT64_MIN);
    //z_printf("Actual_mie_csrrc = %u\n",r0);
        
    EXP_CSR_READ = (~(MASK_MIE & UINT64_MIN) & r0) ;
    z_printf("Expected_mie_csrrc = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrc,r0,772,87567767);
    z_printf("Actual_mie_csrrc = %u\n",r0);

    EXP_CSR_READ = (~(MASK_MIE & 87567767 ) & r0) ;
    z_printf("Expected_mie_csrrc = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrc,r0,772,2385);
    z_printf("Actual_mie_csrrc = %u\n",r0);

    EXP_CSR_READ = (~(MASK_MIE & 2385) & r0) ;
    z_printf("Expected_mie_csrrc = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrc,r0,772,UINT64_MAX);
    z_printf("Actual_mie_csrrc = %u\n",r0);    
      
    EXP_CSR_READ = (~(MASK_MIE & UINT64_MAX) & r0) ;
    z_printf("Expected_mie_csrrc = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrc,r0,772,UINT64_MIN);
    z_printf("Actual_mie_csrrc = %u\n",r0);

    EXP_CSR_READ = (~(MASK_MIE & UINT64_MIN) & r0) ;
    z_printf("Expected_mie_csrrc = %u\n",EXP_CSR_READ);    

     
    for(int i = 0; i < 5; i++)
    {
        rand_num();

        csr_asm_rw(csrrc,r0,772,rs1);
        z_printf("Actual_mie_csrrc = %u\n",r0);
        
        EXP_CSR_READ = (~(MASK_MIE & rs1) & r0) ;
        z_printf("Expected_mie_csrrc = %u\n",EXP_CSR_READ);

    }
    
    csr_asm_rw(csrrc,r0,772,UINT64_MIN);
    z_printf("Actual_mie_csrrc = %u\n",r0);

    EXP_CSR_READ = (~(MASK_MIE & UINT64_MIN) & r0) ;
    z_printf("Expected_mie_csrrc = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrci,r0,772,31);
    z_printf("Actual_mie_csrrci = %u\n",r0);
   
    ///////////////////////    IMMEDIATE INSTRUCTION      ///////////////////////////

    z_printf("////////////////   IMMEDIATE INSTRUCTION   /////////////////\n");

    EXP_CSR_READ = (~(MASK_MIE & 31) & r0) ;
    z_printf("Expected_mie_csrrci = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,772,18);
    z_printf("Actual_mie_csrrci = %u\n",r0);

    EXP_CSR_READ = (~(MASK_MIE & 18) & r0) ;
    z_printf("Expected_mie_csrrci = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,772,26);
    z_printf("Actual_mie_csrrci = %u\n",r0);

    EXP_CSR_READ = (~(MASK_MIE & 26) & r0) ;
    z_printf("Expected_mie_csrrci = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,772,7);
    z_printf("Actual_mie_csrrci = %u\n",r0);
 
    EXP_CSR_READ = (~(MASK_MIE & 7) & r0) ;
    z_printf("Expected_mie_csrrci = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrc,r0,772,0);
    z_printf("Actual_mie_csrrci = %u\n",r0);

    
    ///////////////////////    MTVEC READ_WRITE REGISTER     /////////////////////////////////////////
    
    z_printf("///////////////////////   MTVEC_READ_WRITE   /////////////////////\n");

    ///////////////////   CSRRW/I INSTRUCTION   ///////////////////////

    z_printf("////////////////   CSRRW   /////////////////\n");

  
    //out of [63:0],[1:0] will always set to 2'b01

    csr_asm_rw(csrrw,r0,773,UINT64_MIN);                           
    //z_printf("Actual_mtvec = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN & MASK_MTVEC_2) | MASK_MTVEC_1;
    z_printf("Expected_mtvec_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,773,UINT64_MAX);                           
    z_printf("Actual_mtvec_csrrw = %u\n",r0);

    EXP_CSR_READ = ( UINT64_MAX  & MASK_MTVEC_2) | MASK_MTVEC_1;
    z_printf("Expected_mtvec_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,773,897654);                           
    z_printf("Actual_mtvec_csrrw = %u\n",r0);

    EXP_CSR_READ = (897654 & MASK_MTVEC_2) | MASK_MTVEC_1;
    z_printf("Expected_mtvec_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,773,UINT64_MIN);                           
    z_printf("Actual_mtvec_csrrw = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN  & MASK_MTVEC_2) | MASK_MTVEC_1;
    z_printf("Expected_mtvec_csrrw = %u\n",EXP_CSR_READ);

    
    for(int i = 0; i < 3; i++)
    {

        rand_num();

        csr_asm_rw(csrrw,r0,773,rs1);
        z_printf("Actual_mtvec = %u\n",r0); 

        EXP_CSR_READ = ( rs1 & MASK_MTVEC_2) | MASK_MTVEC_1 ;
        z_printf("Expected_mtvec_csrrw = %u\n",EXP_CSR_READ);      
    }
    csr_asm_rw(csrrw,r0,773,UINT64_MIN);
    z_printf("Actual_mtvec_csrrw = %u\n",r0);

    EXP_CSR_READ = ( UINT64_MIN & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrw = %u\n",EXP_CSR_READ); 
    
    csr_asm_rw_i(csrrwi,r0,773,31);
    z_printf("Actual_mtvec_csrrwi = %u\n",r0);

    ///////////////////////      IMMEDIATE INSTRUCTION      /////////////////////////

    z_printf("////////////////   IMMEDIATE INSTRUCTION   /////////////////\n");

    EXP_CSR_READ = ((31 & MASK_MTVEC_2) | MASK_MTVEC_1) ;
    z_printf("Expected_mtvec_csrrwi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,773,18);
    z_printf("Actual_mtvec_csrrwi = %u\n",r0);

    EXP_CSR_READ = ((18 & MASK_MTVEC_2) | MASK_MTVEC_1) ;
    z_printf("Expected_mtvec_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,773,26);
    z_printf("Actual_mtvec_csrrwi = %u\n",r0);

    EXP_CSR_READ = ((26 & MASK_MTVEC_2) | MASK_MTVEC_1) ;
    z_printf("Expected_mtvec_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,773,7);
    z_printf("Actual_mtvec_csrrwi = %u\n",r0);

    EXP_CSR_READ = ((7 & MASK_MTVEC_2) | MASK_MTVEC_1) ;
    z_printf("Expected_mtvec_csrrwi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,773,11);
    z_printf("Actual_mtvec_csrrwi = %u\n",r0);
    
    EXP_CSR_READ = ((11 & MASK_MTVEC_2) | MASK_MTVEC_1) ;
    z_printf("Expected_mtvec_csrrwi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,773,0);
    z_printf("Actual_mtvec_csrrwi = %u\n",r0);
    

    /////////////////////    CSRRS/I INSTRUCTION      ///////////////////////

    z_printf("////////////////   CSRRS INSTRUCTION  /////////////////\n");

    csr_asm_rw(csrrs,r0,773,UINT64_MIN);
    //z_printf("Actual_mtvec = %u\n",r0);
    
    EXP_CSR_READ = ((r0 | UINT64_MIN) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,773,76854);
    z_printf("Actual_mtvec_csrrs = %u\n",r0); 
    
    EXP_CSR_READ = ((r0 | 76854) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,773,786543452);
    z_printf("Actual_mtvec_csrrs = %u\n",r0);

    EXP_CSR_READ = ((r0 | 786543452) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,773,UINT64_MAX);
    z_printf("Actual_mtvec_csrrs = %u\n",r0);
    
    EXP_CSR_READ = ((r0 | UINT64_MAX) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,773,UINT64_MIN);
    z_printf("Actual_mtvec_csrrs = %u\n",r0);

    EXP_CSR_READ = ((r0 | UINT64_MIN) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);


    for(int i = 0; i < 5; i++)
    {

        rand_num();

        csr_asm_rw(csrrs,r0,773,rs1);
        z_printf("Actual_mtvec_csrrs = %u\n",r0);
        
        EXP_CSR_READ = ((r0 | rs1) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
        z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);

    }
    csr_asm_rw(csrrs,r0,773,UINT64_MIN);
    z_printf("Actual_mtvec_csrrs = %u\n",r0);

    EXP_CSR_READ = ((r0 | UINT64_MIN) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrsi,r0,773,31);
    z_printf("Actual_mtvec = %u\n",r0);
    
    
    /////////////////   IMMEDIATE INSTRUCTION  /////////////////////////
    
    z_printf("////////////////  IMMEDIATE INSTRUCTION   /////////////////\n");

    EXP_CSR_READ = ((r0 | 31) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,773,18);
    z_printf("Actual_mtvec = %u\n",r0);

    EXP_CSR_READ = ((r0 | 18) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,773,26);
    z_printf("Actual_mtvec = %u\n",r0);

    EXP_CSR_READ = ((r0 | 26) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,773,7);
    z_printf("Actual_mtvec = %u\n",r0);

    EXP_CSR_READ = ((r0 | 7) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,773,11);
    z_printf("Actual_mtvec = %u\n",r0);

    EXP_CSR_READ = ((r0 | 11) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrsi,r0,773,0);
    z_printf("Actual_mtvec = %u\n",r0);

    
    //////////////////////////      CSRRC INSTRUCTION         ////////////////////////////

    z_printf("////////////////   CSRRC INSTRUCTION  ///////////////////\n");
    
    csr_asm_rw(csrrc,r0,773,UINT64_MIN);
    //z_printf("Actual_mtvec = %u\n",r0);
    
    EXP_CSR_READ = ((r0 & UINT64_MIN) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrc,r0,773,764435);
    z_printf("Actual_mtvec = %u\n",r0);
    
    EXP_CSR_READ = ((r0 & 764435) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,773,UINT64_MAX);
    z_printf("Actual_mtvec = %u\n",r0);
    
    EXP_CSR_READ = ((r0 & UINT64_MAX) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrc,r0,773,UINT64_MIN);
    z_printf("Actual_mtvec = %u\n",r0);

    EXP_CSR_READ = ((r0 & UINT64_MIN) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);

    for(int i = 0; i < 5; i++)
    {

        rand_num();

        csr_asm_rw(csrrc,r0,773,rs1);
        z_printf("Actual_mtvec = %u\n",r0);
            
        EXP_CSR_READ = ((r0 & rs1) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
        z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);

    }

    csr_asm_rw(csrrc,r0,773,UINT64_MIN);
    z_printf("Actual_mtvec = %u\n",r0);
            
    EXP_CSR_READ = ((r0 & UINT64_MIN) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrci,r0,773,31);
    z_printf("Actual_mtvec_csrrsi = %u\n",r0);

    ////////////////////////    IMMEDIATE INSTRUCTION  ///////////////////////////////

    z_printf("/////////////////   IMMEDIATE INSTRUCTION   ///////////////////\n");
    
    EXP_CSR_READ = ((r0 & 31) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrsi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrci,r0,773,18);
    z_printf("Actual_mtvec_csrrsi = %u\n",r0);
    
    EXP_CSR_READ = ((r0 & 18) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrsi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrci,r0,773,26);
    z_printf("Actual_mtvec_csrrsi = %u\n",r0);
    
    EXP_CSR_READ = ((r0 & 26) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrsi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrci,r0,773,7);
    z_printf("Actual_mtvec_csrrsi = %u\n",r0);
    
    EXP_CSR_READ = ((r0 & 7) & MASK_MTVEC_2) | MASK_MTVEC_1 ;
    z_printf("Expected_mtvec_csrrsi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrci,r0,773,0);
    z_printf("Actual_mtvec_csrrsi = %u\n",r0);

    ///////////////////////    MSCRATCH READ_WRITE REGISTER     /////////////////////////////////////////

    z_printf("///////////////////////   MSCRATCH_READ_WRITE   /////////////////////\n");

    ///////////////////   CSRRW/I INSTRUCTION   ///////////////////

    z_printf("////////////////   CSRRW INSTRUCTION   /////////////////\n");

    csr_asm_rw(csrrw,r0,832,UINT64_MIN);
    //z_printf("Actual_mscratch_csrrw = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN | MASK_MSCRATCH);
    z_printf("Expected_mscratch_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,832,65433452);
    z_printf("Actual_mscratch_csrrw = %u\n",r0);
    
    EXP_CSR_READ = (65433452 | MASK_MSCRATCH);
    z_printf("Expected_mscratch_csrrw = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrw,r0,832,8765);
    z_printf("Actual_mscratch_csrrw = %u\n",r0);
    
    EXP_CSR_READ = (8765 | MASK_MSCRATCH);
    z_printf("Expected_mscratch_csrrw = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrw,r0,832,UINT64_MAX);
    z_printf("Actual_mscratch_csrrw = %u\n",r0);

    EXP_CSR_READ = (UINT64_MAX | MASK_MSCRATCH);
    z_printf("Expected_mscratch_csrrw = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrw,r0,832,UINT64_MIN);
    z_printf("Actual_mscratch_csrrw = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN | MASK_MSCRATCH);
    z_printf("Expected_mscratch_csrrw = %u\n",EXP_CSR_READ);
    
    for(int i = 0; i < 5; i++)
    {

        rand_num();

        csr_asm_rw(csrrw,r0,832,rs1);
        z_printf("Actual_mscratch = %u\n",r0);
        
        EXP_CSR_READ = (rs1 | MASK_MSCRATCH);
        z_printf("Expected_mscratch_csrrw = %u\n",EXP_CSR_READ);

    }
    csr_asm_rw(csrrw,r0,832,UINT64_MIN);
    z_printf("Actual_mscratch = %u\n",r0);
        
    EXP_CSR_READ = (UINT64_MIN | MASK_MSCRATCH);
    z_printf("Expected_mscratch_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,832,31);
    z_printf("Actual_mscratch_csrrwi = %u\n",r0);

    ///////////////////////   IMMEDIATE INSTRUCTION    /////////////////////

    z_printf("////////////////   IMMEDIATE INSTRUCTION   /////////////////\n");

    EXP_CSR_READ = (31 | MASK_MSCRATCH);
    z_printf("Expected_mscratch_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,832,18);
    z_printf("Actual_mscratch_csrrwi = %u\n",r0);

    EXP_CSR_READ = (18 | MASK_MSCRATCH);
    z_printf("Expected_mscratch_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,832,26);
    z_printf("Actual_mscratch_csrrwi = %u\n",r0);

    EXP_CSR_READ = (26 | MASK_MSCRATCH);
    z_printf("Expected_mscratch_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,832,7);
    z_printf("Actual_mscratch_csrrwi = %u\n",r0);

    EXP_CSR_READ = (7 | MASK_MSCRATCH);
    z_printf("Expected_mscratch_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,832,11);
    z_printf("Actual_mscratch_csrrwi = %u\n",r0);

    EXP_CSR_READ = (11 | MASK_MSCRATCH);
    z_printf("Expected_mscratch_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,832,0);     
    z_printf("Actual_mscratch_csrrwi = %u\n",r0);

    /////////////////////////////      CSRRS/I INSTRUCTION     ///////////////////

    z_printf("////////////////   CSRRS INSTRUCTION   /////////////////\n");

    csr_asm_rw(csrrs,r0,832,UINT64_MIN);
    //z_printf("Actual_mscratch_csrrs = %u\n",r0);
    
    EXP_CSR_READ = (r0 | UINT64_MIN );
    z_printf("Expected_mscratch_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,832,765748);
    z_printf("Actual_mscratch_csrrs = %u\n",r0);
    
    EXP_CSR_READ = (r0 | 765748  );
    z_printf("Expected_mscratch_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrs,r0,832,UINT64_MAX);
    z_printf("Actual_mscratch_csrrs = %u\n",r0);
    
    EXP_CSR_READ = (r0 | UINT64_MAX);
    z_printf("Expected_mscratch_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrs,r0,832,UINT64_MIN);
    z_printf("Actual_mscratch_csrrs = %u\n",r0);

    EXP_CSR_READ = (r0 | UINT64_MIN);
    z_printf("Expected_mscratch_csrrs = %u\n",EXP_CSR_READ);

    
    for(int i = 0; i < 5; i++)
    {

        rand_num();

        csr_asm_rw(csrrs,r0,832,rs1);
        z_printf("Actual_mscratch_csrrs = %u\n",r0);

        EXP_CSR_READ = (r0 | rs1) ;
        z_printf("Expected_mscratch_csrrs = %u\n",EXP_CSR_READ);        
    }
    csr_asm_rw(csrrs,r0,832,UINT64_MIN);
    z_printf("Actual_mscratch_csrrs = %u\n",r0);

    EXP_CSR_READ = (r0 | UINT64_MIN);
    z_printf("Expected_mscratch_csrrs = %u\n",EXP_CSR_READ); 
    
    csr_asm_rw_i(csrrsi,r0,832,31);
    z_printf("Actual_mscratch_csrrs = %u\n",r0);
    
    //////////////////   IMMEDIATE INSTRUCTION   ///////////////////
    
    z_printf("////////////////  IMMEDIATE INSTRUCTION   /////////////////\n");

    EXP_CSR_READ = (r0 | 31);
    z_printf("Expected_mscratch_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrsi,r0,832,18);
    z_printf("Actual_mscratch = %u\n",r0);
    
    EXP_CSR_READ = (r0 | 18);
    z_printf("Expected_mscratch_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrsi,r0,832,26);
    z_printf("Actual_mscratch = %u\n",r0);
    
    EXP_CSR_READ = (r0 | 26);
    z_printf("Expected_mscratch_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrsi,r0,832,7);
    z_printf("Actual_mscratch = %u\n",r0);
    
    EXP_CSR_READ = (r0 | 7) ;
    z_printf("Expected_mscratch_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrsi,r0,832,11);
    z_printf("Actual_mscratch = %u\n",r0);

    EXP_CSR_READ = (r0 | 11);
    z_printf("Expected_mscratch_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrsi,r0,832,0);
    z_printf("Actual_mscratch = %u\n",r0);
       
    //////////////////////      CSRRC INSTRUCTION    ////////////////////////

    z_printf("////////////////   CSRRC INSTRUCTION  /////////////////\n");
  
    csr_asm_rw(csrrc,r0,832,UINT64_MIN);
    //z_printf("Actual_mscratch_csrrc = %u\n",r0);
    
    EXP_CSR_READ = (r0 | UINT64_MIN) & MASK_MSCRATCH;
    z_printf("Expected_mscratch_csrrc = %u\n",EXP_CSR_READ);
   
    csr_asm_rw(csrrc,r0,832,536638);
    z_printf("Actual_mscratch_csrrc = %u\n",r0);    
    
    EXP_CSR_READ = (r0 | 536638) & MASK_MSCRATCH;
    z_printf("Expected_mscratch_csrrc = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,832,5524249);
    z_printf("Actual_mscratch_csrrc = %u\n",r0);    
    
    EXP_CSR_READ = (r0 | 5524249) & MASK_MSCRATCH;
    z_printf("Expected_mscratch_csrrc = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,832,UINT64_MAX);
    z_printf("Actual_mscratch_csrrc = %u\n",r0);
    
    EXP_CSR_READ = (r0 | UINT64_MAX) & MASK_MSCRATCH;
    z_printf("Expected_mscratch_csrrc = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,832,UINT64_MIN);
    z_printf("Actual_mscratch_csrrc = %u\n",r0);

    EXP_CSR_READ = (r0 | UINT64_MIN) & MASK_MSCRATCH;
    z_printf("Expected_mscratch_csrrc = %u\n",EXP_CSR_READ);
   
    for(int i = 0; i < 5; i++)
    {

        rand_num();

        csr_asm_rw(csrrc,r0,832,rs1);
        z_printf("Actual_mscratch_csrrc = %u\n",r0);
            
        EXP_CSR_READ = (r0 | rs1) & MASK_MSCRATCH;
        z_printf("Expected_mscratch_csrrc = %u\n",EXP_CSR_READ);

    } 
    csr_asm_rw(csrrc,r0,832,UINT64_MIN);
    z_printf("Actual_mscratch_csrrc = %u\n",r0);
            
    EXP_CSR_READ = (r0 | UINT64_MIN) & MASK_MSCRATCH;
    z_printf("Expected_mscratch_csrrc = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,832,31);
    z_printf("Actual_mscratch_csrrci = %u\n",r0);

    ////////////////////   IMMEDIATE INSTRUCTION   ////////////////////////////

    z_printf("////////////////   IMMEDIATE INSTRUCTION   /////////////////\n");
    
    EXP_CSR_READ = (r0 | 31) & MASK_MSCRATCH;
    z_printf("Expected_mscratch_csrrc = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,832,18);
    z_printf("Actual_mscratch_csrrci = %u\n",r0);
    
    EXP_CSR_READ = (r0 | 18) & MASK_MSCRATCH;
    z_printf("Expected_mscratch_csrrc = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,832,26);
    z_printf("Actual_mscratch_csrrci = %u\n",r0);
    
    EXP_CSR_READ = (r0 | 26) & MASK_MSCRATCH;
    z_printf("Expected_mscratch_csrrc = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,832,7);
    z_printf("Actual_mscratch_csrrci = %u\n",r0);
    
    EXP_CSR_READ = (r0 | 7) & MASK_MSCRATCH;
    z_printf("Expected_mscratch_csrrc = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,832,11);
    z_printf("Actual_mscratch_csrrci = %u\n",r0);
    
    EXP_CSR_READ = (r0 | 11) & MASK_MSCRATCH;
    z_printf("Expected_mscratch_csrrc = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrci,r0,832,0);
    z_printf("Actual_mscratch_csrrci = %u\n",r0);

    ///////////////////////    MEPC READ_WRITE REGISTER     /////////////////////////////////////////
    
    z_printf("///////////////////////   MEPC_READ_WRITE   /////////////////////\n");

    ////////////////////////     CSRRW/I INSTRUCTION     ///////////////////

    // Only CSRRW/I instruction is applicable and it performs normal read write operation

    z_printf("////////////////   CSRRW INSTRUCTION   /////////////////\n");

    csr_asm_rw(csrrw,r0,833,UINT64_MIN);
    //z_printf("Actual_mepc = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN | MASK_MEPC);
    z_printf("Expected_mepc_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,833,14578);
    z_printf("Actual_mepc_csrrw = %u\n",r0);

    EXP_CSR_READ = (14578 | MASK_MEPC);
    z_printf("Expected_mepc_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,833,89674);
    z_printf("Actual_mepc_csrrw = %u\n",r0);

    EXP_CSR_READ = (89674 | MASK_MEPC);
    z_printf("Expected_mepc_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,833,113452367);
    z_printf("Actual_mepc_csrrw = %u\n",r0);

    EXP_CSR_READ = (113452367 | MASK_MEPC);
    z_printf("Expected_mepc_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,833,9807654);
    z_printf("Actual_mepc_csrrw = %u\n",r0);

    EXP_CSR_READ = (9807654 | MASK_MEPC);
    z_printf("Expected_mepc_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,833,UINT64_MAX);
    z_printf("Actual_mepc_csrrw = %u\n",r0);    

    EXP_CSR_READ = (UINT64_MAX | MASK_MEPC);
    z_printf("Expected_mepc_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,833,UINT64_MIN);
    z_printf("Actual_mepc_csrrw = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN | MASK_MEPC);
    z_printf("Expected_mepc_csrrw = %u\n",EXP_CSR_READ);
    
    for(int i = 0; i < 5; i++)
    {
        rand_num();
        
        csr_asm_rw(csrrw,r0,833,rs1);
        z_printf("Actual_mepc_csrrw = %u\n",r0);

        EXP_CSR_READ = (rs1 | MASK_MEPC);
        z_printf("Expected_mepc_csrrw = %u\n",EXP_CSR_READ);
        
    }

    csr_asm_rw(csrrw,r0,833,UINT64_MIN);
    z_printf("Actual_mepc_csrrw = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN | MASK_MEPC);
    z_printf("Expected_mepc_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,833,31);
    z_printf("Actual_mepc_csrrwi = %u\n",r0);

    /////////////////////    IMMEDIATE INSTRUCTION      //////////////////////////////

    z_printf("/////////////////   IMMEDIATE INSTRUCTION  /////////////////////////");

    EXP_CSR_READ = (31 | MASK_MEPC);
    z_printf("Expected_mepc_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,833,16);
    z_printf("Actual_mepc_csrrwi = %u\n",r0);

    EXP_CSR_READ = (16 | MASK_MEPC);
    z_printf("Expected_mepc_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,833,27);
    z_printf("Actual_mepc_csrrwi = %u\n",r0);

    EXP_CSR_READ = (27 | MASK_MEPC);
    z_printf("Expected_mepc_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,833,0);
    z_printf("Actual_mepc_csrrwi = %u\n",r0);



   ///////////////////////    MTVAL READ_WRITE REGISTER     /////////////////////////////////////////

    // It performs normal read_write operation
    // Only CSRRW/I is applicable, if performs CSRRS/I and CSRRC/I; it will perform CSRRW/I only

    z_printf("///////////////////////    MTVAL_READ_WRITE   /////////////////////\n");

    ///////////////////////   CSRRW/I INSTRUCTION    ///////////////////

    z_printf("////////////////   CSRRW INSTRUCTION   /////////////////\n");

    csr_asm_rw(csrrw,r0,835,UINT64_MIN);
    //z_printf("Actual_mtval = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN | MASK_MTVAL);
    z_printf("Expected_mtval_csrrw = %u\n", EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,835,UINT64_MAX);
    z_printf("Actual_mtval_csrrw = %u\n",r0);

    EXP_CSR_READ = (UINT64_MAX | MASK_MTVAL);
    z_printf("Expected_mtval_csrrw = %u\n", EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,835,UINT64_MIN);
    z_printf("Actual_mtval_csrrw = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN | MASK_MTVAL);
    z_printf("Expected_mtval_csrrw = %u\n", EXP_CSR_READ);

 
    for (int i = 0; i < 5 ; i++)
    {

        rand_num();

        csr_asm_rw(csrrw,r0,835,rs1);
        z_printf("Actual_mtval_csrrw = %u\n",r0);

        EXP_CSR_READ = (rs1 | MASK_MTVAL);
        z_printf("Expected_mtval_csrrw = %u\n", EXP_CSR_READ);
        
    }

    csr_asm_rw(csrrw,r0,835,UINT64_MIN);
    z_printf("Actual_mtval_csrrw = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN | MASK_MTVAL);
    z_printf("Expected_mtval_csrrw = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,835,31);
    z_printf("Actual_mtval_csrrwi = %u\n",r0);

    //////////////////////////    IMMEDIATE INSTRUCTION      ///////////////////////

    z_printf("/////////////////    IMMEDIATE INSTRUCTION   //////////////////////\n");
    
    EXP_CSR_READ = (31 | MASK_MTVAL);
    z_printf("Expected_mtval_csrrwi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,835,18);
    z_printf("Actual_mtval_csrrwi = %u\n",r0);

    EXP_CSR_READ = (18 | MASK_MTVAL);
    z_printf("Expected_mtval_csrrwi = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,835,26);
    z_printf("Actual_mtval_csrrwi = %u\n",r0);

    EXP_CSR_READ = (26 | MASK_MTVAL);
    z_printf("Expected_mtval_csrrwi = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,835,7);
    z_printf("Actual_mtval_csrrwi = %u\n",r0);

    EXP_CSR_READ = (7 | MASK_MTVAL);
    z_printf("Expected_mtval_csrrwi = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,835,11);
    z_printf("Actual_mtval_csrrwi = %u\n",r0);

    EXP_CSR_READ = (11 | MASK_MTVAL);
    z_printf("Expected_mtval_csrrwi = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,835,0);
    z_printf("Actual_mtval_csrrwi = %u\n",r0);

    ////////////////////      CSRRS/I INSTRUCTION    //////////////////////////

    //Test case for set - the bits are not set instead it's performing CSRRW/I"
    
    z_printf("//////////////////////    CSRRS INSTRUCTION   /////////////////////////\n");

    csr_asm_rw(csrrs,r0,835,UINT64_MIN);
    //z_printf("Actual_mtval_csrrs = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN | MASK_MTVAL);
    z_printf("Expected_mtval_csrrs = %u\n", EXP_CSR_READ);
    
    csr_asm_rw(csrrs,r0,835,8678397);
    z_printf("Actual_mtval_csrrs = %u\n",r0);
    
    EXP_CSR_READ = (8678397 | MASK_MTVAL);
    z_printf("Expected_mtval_csrrs = %u\n", EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,835,UINT64_MAX);
    z_printf("Actual_mtval_csrrs = %u\n",r0);
    
    EXP_CSR_READ =  (UINT64_MAX | MASK_MTVAL);
    z_printf("Expected_mtval_csrrs = %u\n", EXP_CSR_READ);
    
    csr_asm_rw(csrrs,r0,835,UINT64_MIN);
    z_printf("Actual_mtval_csrrs = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN | MASK_MTVAL);
    z_printf("Expected_mtval_csrrs = %u\n", EXP_CSR_READ);

    for(int i = 0; i < 5; i++)
    {

        rand_num();

        csr_asm_rw(csrrs,r0,835,rs1);
        z_printf("Actual_mtval_csrrs = %u\n",r0);

        EXP_CSR_READ = (rs1 | MASK_MTVAL) ;
        z_printf("Expected_mtval_csrrs = %u\n", EXP_CSR_READ);

        
    }

    csr_asm_rw(csrrs,r0,835,UINT64_MIN);
    z_printf("Actual_mtval_csrrs = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN | MASK_MTVAL) ;
    z_printf("Expected_mtval_csrrs = %u\n", EXP_CSR_READ);
 
    csr_asm_rw_i(csrrsi,r0,835,31);
    z_printf("Actual_mtval_csrrsi = %u\n",r0);
    
    ///////////////////////  IMMEDIATE INSTRUCTION   ///////////////////////////////

    z_printf("////////////////////////   IMMEDIATE INSTRUCTION   //////////////////////\n");

    EXP_CSR_READ = (31  | MASK_MTVAL) ;
    z_printf("Expected_mtval_csrrsi = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,835,18);
    z_printf("Actual_mtval_csrrsi = %u\n",r0);

    EXP_CSR_READ = (18 | MASK_MTVAL) ;
    z_printf("Expected_mtval_csrrsi = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,835,26);
    z_printf("Actual_mtval_csrrsi = %u\n",r0);

    EXP_CSR_READ =  (26 | MASK_MTVAL) ;
    z_printf("Expected_mtval_csrrsi = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,835,7);
    z_printf("Actual_mtval_csrrsi = %u\n",r0);

    EXP_CSR_READ =  (7 | MASK_MTVAL) ;
    z_printf("Expected_mtval_csrrsi = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,835,0);
    z_printf("Actual_mtval_csrrsi = %u\n",r0);

    ///////////////////////////////     CSRRC/I INSTRUCTION        /////////////////////////////
    
    //Test case for clear - the bits are not cleared instead it's performing CSRRW/I");

    z_printf("/////////////////////////   CSRRC INSTRUCTION    /////////////////////////\n");

    
    csr_asm_rw(csrrc,r0,835,UINT64_MIN);
    //z_printf("Actual_mtval_csrrc = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN | MASK_MTVAL) ;
    z_printf("Expected_mtval_csrrc = %u\n", EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,835,254647);
    z_printf("Actual_mtval_csrrc = %u\n",r0);

    EXP_CSR_READ = (254647 | MASK_MTVAL) ;
    z_printf("Expected_mtval_csrrc = %u\n", EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,835,8789786);
    z_printf("Actual_mtval_csrrc = %u\n",r0);

    EXP_CSR_READ = (8789786 | MASK_MTVAL) ;
    z_printf("Expected_mtval_csrrc = %u\n", EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,835,UINT64_MAX);
    z_printf("Actual_mtval_csrrc = %u\n",r0);

    EXP_CSR_READ = (UINT64_MAX | MASK_MTVAL) ;
    z_printf("Expected_mtval_csrrc = %u\n", EXP_CSR_READ);

    csr_asm_rw(csrrc,r0,835,UINT64_MIN);
    z_printf("Actual_mtval_csrrc = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN | MASK_MTVAL) ;
    z_printf("Expected_mtval_csrrc = %u\n", EXP_CSR_READ);


    for(int i = 0; i < 5; i++)
    {

        rand_num();

        csr_asm_rw(csrrc,r0,835,rs1);
        z_printf("Actual_mtval_csrrc = %u\n",r0);

        EXP_CSR_READ = (rs1 | MASK_MTVAL) ;
        z_printf("Expected_mtval_csrrc = %u\n", EXP_CSR_READ);
        
    }

    csr_asm_rw(csrrc,r0,835,UINT64_MIN);
    z_printf("Actual_mtval_csrrc = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN | MASK_MTVAL) ;
    z_printf("Expected_mtval_csrrc = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,835,31);
    z_printf("Actual_mtval_csrrci = %u\n",r0);
  
    ////////////////////////    IMMEDIATE INSTRUCTION    ///////////////////////////////
    
    z_printf("////////////////////    IMMEDIATE INSTRUCTION    /////////////////////////\n");

    EXP_CSR_READ = (31 | MASK_MTVAL) ;
    z_printf("Expected_mtval_csrrci = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,835,18);
    z_printf("Actual_mtval_csrrci = %u\n",r0);

    EXP_CSR_READ = (18 | MASK_MTVAL) ;
    z_printf("Expected_mtval_csrrci = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,835,26);
    z_printf("Actual_mtval_csrrci = %u\n",r0);

    EXP_CSR_READ = (26 | MASK_MTVAL) ;
    z_printf("Expected_mtval_csrrci = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,835,7);
    z_printf("Actual_mtval_csrrci = %u\n",r0);

    EXP_CSR_READ = (7 | MASK_MTVAL) ;
    z_printf("Expected_mtval_csrrci = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,835,0);
    z_printf("Actual_mtval_csrrci = %u\n",r0);

    
    ///////////////////////    MIP READ_WRITE REGISTER     /////////////////////////////////////////
    
    z_printf("//////////////////////    MIP_READ_WRITE   ///////////////////////\n");

    ///////////////////////   CSRRW/I INSTRUCTION    ///////////////////

    //Here 3rd , 7th, 11 th bits are writable only 

    z_printf("//////////////////   CSRRW INSTRUCTION  ///////////////////////\n");

    csr_asm_rw(csrrw,r0,836,UINT64_MIN);
    //z_printf("Actual_mip_csrrw = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN  & MASK_MIP);
    z_printf("Expected_mip_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,836,16789654);
    z_printf("Actual_mip_csrrw = %u\n",r0);

    EXP_CSR_READ = (16789654 & MASK_MIP);
    z_printf("Expected_mip_csrrw = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrw,r0,836,98766);
    z_printf("Actual_mip_csrrw = %u\n",r0);

    EXP_CSR_READ = (98766 & MASK_MIP) ;
    z_printf("Expected_mip_csrrw = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrw,r0,836,UINT64_MAX);
    z_printf("Actual_mip_csrrw = %u\n",r0);

    EXP_CSR_READ = (UINT64_MAX & MASK_MIP) ;
    z_printf("Expected_mip_csrrw = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrw,r0,836,UINT64_MIN);
    z_printf("Actual_mip_csrrw = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN & MASK_MIP) ;
    z_printf("Expected_mip_csrrw = %u\n",EXP_CSR_READ);

    
    for(int i = 0; i < 5; i++)
    {

        rand_num();

        csr_asm_rw(csrrw,r0,836,rs1);
        z_printf("Actual_mip_csrrw = %u\n",r0);

        EXP_CSR_READ = (rs1 & MASK_MIP) ;
        z_printf("Expected_mip_csrrw = %u\n",EXP_CSR_READ);
       
    } 
    csr_asm_rw(csrrw,r0,836,UINT64_MIN);
    z_printf("Actual_mip_csrrw = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN & MASK_MIP) ;
    z_printf("Expected_mip_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,836,31);
    z_printf("Actual_mip_csrrwi = %u\n",r0);

    ///////////////////////////   IMMEDIATE INSTRUCTION   ////////////////////////////

    z_printf("///////////////////   IMMEDIATE INSTRUCTION   ////////////////////////\n");

    EXP_CSR_READ = (31 & MASK_MIP);
    z_printf("Expected_mip_csrrwi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,836,18);
    z_printf("Actual_mip_csrrwi = %u\n",r0);

    EXP_CSR_READ = (18 & MASK_MIP);
    z_printf("Expected_mip_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,836,26);
    z_printf("Actual_mip_csrrwi = %u\n",r0);

    EXP_CSR_READ = (26 & MASK_MIP);
    z_printf("Expected_mip_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,836,7);
    z_printf("Actual_mip_csrrwi = %u\n",r0);

    EXP_CSR_READ = (7 & MASK_MIP);
    z_printf("Expected_mip_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,836,11);
    z_printf("Actual_mip_csrrwi = %u\n",r0);

    EXP_CSR_READ = (11 & MASK_MIP);
    z_printf("Expected_mip_csrrwi = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,836,0);
    z_printf("Actual_mip_csrrwi = %u\n",r0);
   
    EXP_CSR_READ = (0 & MASK_MIP);
    z_printf("Expected_mip_csrrwi = %u\n", EXP_CSR_READ);
 
    ////////////////////////////    CSRRS INSTRUCTION    ////////////////////////////////
    
    z_printf("///////////////////////   CSRRS INSTRUCTION  ///////////////////\n");
    
    csr_asm_rw(csrrs,r0,836,UINT64_MIN);
    //z_printf("Actual_mip_csrrs = %u\n",r0);

    EXP_CSR_READ = (r0 | UINT64_MIN ) & MASK_MIP;
    z_printf("Expected_mip_csrrs = %u\n", EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,836,7869);
    z_printf("Actual_mip_csrrs = %u\n",r0);

    EXP_CSR_READ = (r0 | 7869) & MASK_MIP;
    z_printf("Expected_mip_csrrs = %u\n", EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,836,UINT64_MIN);
    z_printf("Actual_mip_csrrs = %u\n",r0);

    EXP_CSR_READ = (r0 | UINT64_MIN) & MASK_MIP;
    z_printf("Expected_mip_csrrs = %u\n", EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,836,67548);
    z_printf("Actual_mip_csrrs = %u\n",r0);

    EXP_CSR_READ = (r0 |67548 ) & MASK_MIP;
    z_printf("Expected_mip_csrrs = %u\n", EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,836,UINT64_MAX);
    z_printf("Actual_mip_csrrs = %u\n",r0);

    EXP_CSR_READ = (r0 | UINT64_MAX) & MASK_MIP;
    z_printf("Expected_mip_csrrs = %u\n", EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,836,UINT64_MIN);
    z_printf("Actual_mip_csrrs = %u\n",r0);
    
    EXP_CSR_READ = (r0 | UINT64_MIN) & MASK_MIP;
    z_printf("Expected_mip_csrrs = %u\n", EXP_CSR_READ);

    for (int i = 0; i < 5; i++)
    {

        rand_num();

        csr_asm_rw(csrrs,r0,836,rs1);
        z_printf("Actual_mip_csrrs = %u\n",r0);

        EXP_CSR_READ = (r0 | rs1) & MASK_MIP;
        z_printf("Expected_mip_csrrs = %u\n", EXP_CSR_READ);

    }

    csr_asm_rw(csrrs,r0,836,UINT64_MIN);
    z_printf("Actual_mip_csrrs = %u\n",r0);
    
    EXP_CSR_READ = (r0 | UINT64_MIN) & MASK_MIP;
    z_printf("Expected_mip_csrrs = %u\n", EXP_CSR_READ);
    
    csr_asm_rw_i(csrrsi,r0,836,31);
    z_printf("Actual_mip_csrrsi = %u\n",r0);
    
    ////////////////////////////    IMMEDIATE INSTRUCTION   /////////////////////////////

    z_printf("///////////////////   IMMEDIATE INSTRUCTION  /////////////////////\n");
    
    EXP_CSR_READ = (r0 | 31) & MASK_MIP;
    z_printf("Expected_mip_csrrsi = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,836,18);
    z_printf("Actual_mip_csrrsi = %u\n",r0);

    EXP_CSR_READ = (r0 | 18) & MASK_MIP;
    z_printf("Expected_mip_csrrsi = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,836,26);
    z_printf("Actual_mip_csrrsi = %u\n",r0);

    EXP_CSR_READ = (r0 | 26) & MASK_MIP;
    z_printf("Expected_mip_csrrsi = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,836,7);
    z_printf("Actual_mip_csrrsi = %u\n",r0);

    EXP_CSR_READ = (r0 | 7) & MASK_MIP;
    z_printf("Expected_mip_csrrsi = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrsi,r0,836,0);
    z_printf("Actual_mip_csrrsi = %u\n",r0);

    ////////////////////////         CSRRC/I INSTRUCTION      //////////////////////
 
    z_printf("/////////////////////  CSRRC INSTRUCTION   //////////////////////\n");
    
    csr_asm_rw(csrrc,r0,836,UINT64_MIN);
    //z_printf("Actual_mip_csrrc = %u\n",r0);

    EXP_CSR_READ = (~(MASK_MIP & UINT64_MIN) & r0);
    z_printf("Expected_mip_csrrc = %u\n", EXP_CSR_READ);

    csr_asm_rw(csrrc,r0,836,753757);
    z_printf("Actual_mip_csrrc = %u\n",r0);
    
    EXP_CSR_READ = (~(MASK_MIP & 753757) & r0);
    z_printf("Expected_mip_csrrc = %u\n", EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,836,24343546);
    z_printf("Actual_mip_csrrc = %u\n",r0);
    
    EXP_CSR_READ = (~(MASK_MIP & 24343546) & r0);
    z_printf("Expected_mip_csrrc = %u\n", EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,836,UINT64_MAX);
    z_printf("Actual_mip_csrrc = %u\n",r0);
    
    EXP_CSR_READ = (~(MASK_MIP & UINT64_MAX) & r0);
    z_printf("Expected_mip_csrrc = %u\n", EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,836,UINT64_MIN);
    z_printf("Actual_mip_csrrc = %u\n",r0);

    EXP_CSR_READ = (~(MASK_MIP & UINT64_MIN) & r0);
    z_printf("Expected_mip_csrrc = %u\n", EXP_CSR_READ);

    for (int i = 0; i < 5 ; i++)
    {

        rand_num();

        csr_asm_rw(csrrc,r0,836,rs1);
        z_printf("Actual_mip_csrrc = %u\n",r0);
    
        EXP_CSR_READ = (~(MASK_MIP & rs1) & r0);
        z_printf("Expected_mip_csrrc = %u\n", EXP_CSR_READ);
        
    }
 
    csr_asm_rw(csrrc,r0,836,UINT64_MIN);
    z_printf("Actual_mip_csrrc = %u\n",r0);

    EXP_CSR_READ = (~(MASK_MIP & UINT64_MIN) & r0);
    z_printf("Expected_mip_csrrc = %u\n", EXP_CSR_READ);
    
    csr_asm_rw_i(csrrci,r0,836,31);
    z_printf("Actual_mip_csrrci = %u\n",r0);

    //////////////////////////   IMMEDIATE  INSTRUCTION    /////////////////////////////

    z_printf("/////////////////////   IMMEDIATE INSTRUCTION   /////////////////\n");
    

    EXP_CSR_READ = (~(MASK_MIP & 31) & r0);
    z_printf("Expected_mip_csrrci = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,836,18);
    z_printf("Actual_mip_csrrci = %u\n",r0);

    EXP_CSR_READ = (~(MASK_MIP & 18) & r0);
    z_printf("Expected_mip_csrrci = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,836,26);
    z_printf("Actual_mip_csrrci = %u\n",r0);

    EXP_CSR_READ = (~(MASK_MIP & 26) & r0);
    z_printf("Expected_mip_csrrci = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,836,7);
    z_printf("Actual_mip_csrrci = %u\n",r0);

    EXP_CSR_READ = (~(MASK_MIP & 7) & r0);
    z_printf("Expected_mip_csrrci = %u\n", EXP_CSR_READ);

    csr_asm_rw_i(csrrci,r0,836,0);
    z_printf("Actual_mip_csrrci = %u\n",r0);

  

    ///////////////////////    MZICBASE READ_WRITE REGISTER     /////////////////////////////////////////


    z_printf("/////////////////////////    MZICBASE_READ_WRITE   /////////////////////\n");
    
    // Only CSRRW/I Instruction is available for MZICBASE and It will perform normal read_write Operation

    ////////////////////   CSRRW/I INSTRUCTION    ///////////////////

    z_printf("//////////////////    CSRRW INSTRUCTION  ////////////////////\n");

    csr_asm_rw(csrrw,r0,3008,UINT64_MIN);
    //z_printf("Actual_mzicbase = %u\n",r0);
    
    csr_asm_rw(csrrw,r0,3008,908987);
    z_printf("Actual_mzicbase = %u\n",r0);
    
    EXP_CSR_READ = (r0 | MASK_MZICBASE);
    z_printf("Expected_mzicbase = %u\n", EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,3008,UINT64_MAX);
    z_printf("Actual_mzicbase = %u\n",r0);
    
    EXP_CSR_READ = (r0 | MASK_MZICBASE);
    z_printf("Expected_mzicbase = %u\n", EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,3008,6753324);
    z_printf("Actual_mzicbase = %u\n",r0);

    EXP_CSR_READ = (r0 | MASK_MZICBASE);
    z_printf("Expected_mzicbase = %u\n", EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,3008,0);
    z_printf("Actual_mzicbase = %u\n",r0);

    EXP_CSR_READ = (r0 | MASK_MZICBASE);
    z_printf("Expected_mzicbase = %u\n", EXP_CSR_READ);

    
    for(int i = 0; i < 3; i++)
    {

        rand_num();

        csr_asm_rw(csrrw,r0,3008,rs1);
        z_printf("Actual_mzicbase = %u\n",r0);

        EXP_CSR_READ = (r0 | MASK_MZICBASE);
        z_printf("Expected_mzicbase = %u\n", EXP_CSR_READ);
     
    }

    csr_asm_rw(csrrw,r0,3008,UINT64_MIN);
    z_printf("Actual_mzicbase = %u\n",r0);

    EXP_CSR_READ = (r0 | MASK_MZICBASE);
    z_printf("Expected_mzicbase = %u\n", EXP_CSR_READ);

    /////////////////////  IMMEDIATE INSTRUCTION   ///////////////////

    z_printf("////////////////   IMMEDIATE INSTRUCTION     /////////////////\n");

    csr_asm_rw_i(csrrwi,r0,3008,31);
    z_printf("Actual_mzicbase = %u\n",r0);
    
    EXP_CSR_READ = (r0 | MASK_MZICBASE);
    z_printf("Expected_mzicbase = %u\n", EXP_CSR_READ);
       
    csr_asm_rw_i(csrrwi,r0,3008,18);
    z_printf("Actual_mzicbase = %u\n",r0);

    EXP_CSR_READ = (r0 | MASK_MZICBASE);
    z_printf("Expected_mzicbase = %u\n", EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,3008,26);
    z_printf("Actual_mzicbase = %u\n",r0);

    EXP_CSR_READ = (r0 | MASK_MZICBASE);
    z_printf("Expected_mzicbase = %u\n", EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,3008,7);
    z_printf("Actual_mzicbase = %u\n",r0);

    EXP_CSR_READ = (r0 | MASK_MZICBASE);
    z_printf("Expected_mzicbase = %u\n", EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,3008,0);
    z_printf("Actual_mzicbase = %u\n",r0);
    
    EXP_CSR_READ = (r0 | MASK_MZICBASE);
    z_printf("Expected_mzicbase = %u\n", EXP_CSR_READ);


    ///////////////////////    MINSTATUS READ_WRITE REGISTER     /////////////////////////////////////////

    //Only CSRRW/I Instruction is available for MINSTATUS and it always reads 0 only

    z_printf("/////////////////////     MINSTATUS_READ_WRITE    //////////////////////\n");

    ///////////   CSRRW/I Instruction ///////////////////

    z_printf("////////////////////////    CSRRW  INSTRUCTION   /////////////////////////\n");

    csr_asm_rw(csrrw,r0,4032,UINT64_MIN);
    //z_printf("Actual_minstatus = %u\n",r0);

    csr_asm_rw(csrrw,r0,4032,67855);
    z_printf("Actual_minstatus = %u\n",r0);

    EXP_CSR_READ = (r0 & MASK_MINSTATUS);
    z_printf("Expected_minstatus = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,4032,UINT64_MAX);
    z_printf("Actual_minstatus = %u\n",r0);
    
    EXP_CSR_READ = (r0 & MASK_MINSTATUS);
    z_printf("Expected_minstatus = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,4032,UINT64_MIN);
    z_printf("Actual_minstatus = %u\n",r0);

    EXP_CSR_READ = (r0 & MASK_MINSTATUS);
    z_printf("Expected_minstatus = %u\n",EXP_CSR_READ);

    for(int i = 0; i < 5; i++)
    {

        rand_num();

        csr_asm_rw(csrrw,r0,4032,rs1);                
        z_printf("Actual_minstatus = %u\n",r0);

        EXP_CSR_READ =(r0 & MASK_MINSTATUS);
        z_printf("Expected_minstatus = %u\n",EXP_CSR_READ);
       
    }

    csr_asm_rw(csrrw,r0,4032,UINT64_MIN);
    z_printf("Actual_minstatus = %u\n",r0);

    EXP_CSR_READ = (r0 & MASK_MINSTATUS);
    z_printf("Expected_minstatus = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,4032,31);
    z_printf("Actual_minstatus = %u\n",r0);

    /////////////////////   IMMEDIATE INSTRUCTION     ///////////////////////////

    z_printf("/////////////////////   IMMEDIATE INSTRUCTION   /////////////////////\n");

    EXP_CSR_READ = (r0 & MASK_MINSTATUS);
    z_printf("Expected_minstatus = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,4032,17);
    z_printf("Actual_minstatus = %u\n",r0);
    
    EXP_CSR_READ = (r0 & MASK_MINSTATUS);
    z_printf("Expected_minstatus = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,4032,29);
    z_printf("Actual_minstatus = %u\n",r0);
    
    EXP_CSR_READ = (r0 & MASK_MINSTATUS);
    z_printf("Expected_minstatus = %u\n",EXP_CSR_READ);
   
    csr_asm_rw_i(csrrwi,r0,4032,7);
    z_printf("Actual_minstatus = %u\n",r0);
    
    EXP_CSR_READ = (r0 & MASK_MINSTATUS);
    z_printf("Expected_minstatus = %u\n",EXP_CSR_READ);

    csr_asm_rw_i(csrrwi,r0,4032,0);
    z_printf("Actual_minstatus = %u\n",r0);
 
    //////////////////////   MCOUNTINHIBIT READ_WRITE REGISTER    ////////////////////////////////////
    
    z_printf("/////////////////   MCOUNTINHIBIT READ_WRITE REGISTER    //////////////////////\n");

    //////////////////////      CSRRW INSTRUCTION       //////////////////////////
    
    z_printf("//////////////   CSRRW INSTRUCTION    /////////////////////\n");
    
    csr_asm_rw(csrrw,r0,800,UINT64_MIN);
    //z_printf("Actual_mcountinhibit_csrrw = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN | MASK_MCOUNTINHIBIT);
    z_printf("Expected_mcountinhibit_csrrw = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrw,r0,800,5787887);
    z_printf("Actual_mcountinhibit_csrrw = %u\n",r0);
    
    EXP_CSR_READ = (5787887 | MASK_MCOUNTINHIBIT);
    z_printf("Expected_mcountinhibit_csrrw = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrw,r0,800,43564758);
    z_printf("Actual_mcountinhibit_csrrw = %u\n",r0);
    
    EXP_CSR_READ = (43564758 | MASK_MCOUNTINHIBIT);
    z_printf("Expected_mcountinhibit_csrrw = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrw,r0,800,UINT64_MAX);
    z_printf("Actual_mcountinhibit_csrrw = %u\n",r0); 
    
    EXP_CSR_READ = (UINT64_MAX | MASK_MCOUNTINHIBIT);
    z_printf("Expected_mcountinhibit_csrrw = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrw,r0,800,678388);
    z_printf("Actual_mcountinhibit_csrrw = %u\n",r0);
    
    EXP_CSR_READ = (678388 | MASK_MCOUNTINHIBIT);
    z_printf("Expected_mcountinhibit_csrrw = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrw,r0,800,UINT64_MIN);
    z_printf("Actual_mcountinhibit_csrrw = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN | MASK_MCOUNTINHIBIT);
    z_printf("Expected_mcountinhibit_csrrw = %u\n",EXP_CSR_READ);
    
    for(int i = 0; i < 5; i++)
    {
        rand_num();
        
        csr_asm_rw(csrrw,r0,800,rs1);
        z_printf("Actual_mcountinhibit_csrrw = %u\n",r0);
        
        EXP_CSR_READ = (rs1 | MASK_MCOUNTINHIBIT);
        z_printf("Expected_mcountinhibit_csrrw = %u\n",EXP_CSR_READ);
    }
    
    csr_asm_rw(csrrw,r0,800,UINT64_MIN);
    z_printf("Actual_mcountinhibit_csrrw = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN | MASK_MCOUNTINHIBIT);
    z_printf("Expected_mcountinhibit_csrrw = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,800,31);
    z_printf("Actual_mcountinhibit_csrrw = %u\n",r0);


    //////////////////////  IMMEDIATE INSTRUCTION   ///////////////////////////
    
    z_printf("////////////////  IMMEDIATE INSTRUCTION   ////////////////////\n");
    
    EXP_CSR_READ = (31 | MASK_MCOUNTINHIBIT);
    z_printf("Expected_mcountinhibit_csrrwi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,800,17);
    z_printf("Actual_mcountinhibit_csrrwi = %u\n",r0);
   
    EXP_CSR_READ = (17 | MASK_MCOUNTINHIBIT);
    z_printf("Expected_mcountinhibit_csrrwi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,800,23);
    z_printf("Actual_mcountinhibit_csrrwi = %u\n",r0);
   
    EXP_CSR_READ = (23 | MASK_MCOUNTINHIBIT);
    z_printf("Expected_mcountinhibit_csrrwi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,800,9);
    z_printf("Actual_mcountinhibit_csrrwi = %u\n",r0);
    
    EXP_CSR_READ = (9 | MASK_MCOUNTINHIBIT);
    z_printf("Expected_mcountinhibit_csrrwi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrwi,r0,800,0);
    z_printf("Actual_mcountinhibit_csrrwi = %u\n",r0);

    /////////////////////////////   CSRRS INSTRUCTION    ////////////////////////////
    
    z_printf("//////////////   CSRRS INSTRUCTION    /////////////////////\n");
    
    csr_asm_rw(csrrs,r0,800,UINT64_MIN);
    //z_printf("Actual_mcountinhibit_csrrs = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN | r0);
    z_printf("Expected_mcountinhibit_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrs,r0,800,5787887);
    z_printf("Actual_mcountinhibit_csrrs = %u\n",r0);
    
    EXP_CSR_READ = (5787887 | r0);
    z_printf("Expected_mcountinhibit_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrs,r0,800,43564758);
    z_printf("Actual_mcountinhibit_csrrs = %u\n",r0);
    
    EXP_CSR_READ = (43564758 | r0);
    z_printf("Expected_mcountinhibit_csrrs = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrs,r0,800,UINT64_MAX);
    z_printf("Actual_mcountinhibit_csrrs = %u\n",r0); 
    
    EXP_CSR_READ = (UINT64_MAX | r0);
    z_printf("Expected_mcountinhibit_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrs,r0,800,678388);
    z_printf("Actual_mcountinhibit_csrrs = %u\n",r0);
    
    EXP_CSR_READ = (678388 | r0);
    z_printf("Expected_mcountinhibit_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrs,r0,800,UINT64_MIN);
    z_printf("Actual_mcountinhibit_csrrs = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN | r0);
    z_printf("Expected_mcountinhibit_csrrs = %u\n",EXP_CSR_READ);
    
    for(int i = 0; i < 5; i++)
    {
        rand_num();
        
        csr_asm_rw(csrrs,r0,800,rs1);
        z_printf("Actual_mcountinhibit_csrrs = %u\n",r0);
        
        EXP_CSR_READ = (rs1 | r0);
        z_printf("Expected_mcountinhibit_csrrs = %u\n",EXP_CSR_READ);
    }
    
    csr_asm_rw(csrrs,r0,800,UINT64_MIN);
    z_printf("Actual_mcountinhibit_csrrs = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN | r0);
    z_printf("Expected_mcountinhibit_csrrs = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrsi,r0,800,31);
    z_printf("Actual_mcountinhibit_csrrsi = %u\n",r0);


    //////////////////////  IMMEDIATE INSTRUCTION   ///////////////////////////
    
    z_printf("////////////////  IMMEDIATE INSTRUCTION   ////////////////////\n");
    
    EXP_CSR_READ = (31 | r0);
    z_printf("Expected_mcountinhibit_csrrsi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrsi,r0,800,17);
    z_printf("Actual_mcountinhibit_csrrsi = %u\n",r0);
   
    EXP_CSR_READ = (17 | r0);
    z_printf("Expected_mcountinhibit_csrrsi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrsi,r0,800,23);
    z_printf("Actual_mcountinhibit_csrrsi = %u\n",r0);
   
    EXP_CSR_READ = (23 | r0);
    z_printf("Expected_mcountinhibit_csrrsi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrsi,r0,800,9);
    z_printf("Actual_mcountinhibit_csrrsi = %u\n",r0);
    
    EXP_CSR_READ = (9 | r0);
    z_printf("Expected_mcountinhibit_csrrsi = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrsi,r0,800,0);
    z_printf("Actual_mcountinhibit_csrrsi = %u\n",r0);

    /////////////////////////////   CSRRC INSTRUCTION    ////////////////////////////
    
    z_printf("//////////////   CSRRC INSTRUCTION    /////////////////////\n");
    
    csr_asm_rw(csrrc,r0,800,UINT64_MIN);
    //z_printf("Actual_mcountinhibit_csrrc = %u\n",r0);

    EXP_CSR_READ = (UINT64_MIN & r0);
    z_printf("Expected_mcountinhibit_csrrc = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,800,5787887);
    z_printf("Actual_mcountinhibit_csrrc = %u\n",r0);
    
    EXP_CSR_READ = (5787887 & r0);
    z_printf("Expected_mcountinhibit_csrrc = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,800,43564758);
    z_printf("Actual_mcountinhibit_csrrc = %u\n",r0);
    
    EXP_CSR_READ = (43564758 & r0);
    z_printf("Expected_mcountinhibit_csrrc = %u\n",EXP_CSR_READ);

    csr_asm_rw(csrrc,r0,800,UINT64_MAX);
    z_printf("Actual_mcountinhibit_csrrc = %u\n",r0); 
    
    EXP_CSR_READ = (UINT64_MAX & r0);
    z_printf("Expected_mcountinhibit_csrrc = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,800,678388);
    z_printf("Actual_mcountinhibit_csrrc = %u\n",r0);
    
    EXP_CSR_READ = (678388 & r0);
    z_printf("Expected_mcountinhibit_csrrc = %u\n",EXP_CSR_READ);
    
    csr_asm_rw(csrrc,r0,800,UINT64_MIN);
    z_printf("Actual_mcountinhibit_csrrc = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN & r0);
    z_printf("Expected_mcountinhibit_csrrc = %u\n",EXP_CSR_READ);
    
    for(int i = 0; i < 5; i++)
    {
        rand_num();
        
        csr_asm_rw(csrrc,r0,800,rs1);
        z_printf("Actual_mcountinhibit_csrrc = %u\n",r0);
        
        EXP_CSR_READ = (rs1 & r0);
        z_printf("Expected_mcountinhibit_csrrc = %u\n",EXP_CSR_READ);
    }
    
    csr_asm_rw(csrrc,r0,800,UINT64_MIN);
    z_printf("Actual_mcountinhibit_csrrc = %u\n",r0);
    
    EXP_CSR_READ = (UINT64_MIN & r0);
    z_printf("Expected_mcountinhibit_csrrc = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrci,r0,800,31);
    z_printf("Actual_mcountinhibit_csrrci = %u\n",r0);


    //////////////////////  IMMEDIATE INSTRUCTION   ///////////////////////////
    
    z_printf("////////////////  IMMEDIATE INSTRUCTION   ////////////////////\n");
    
    EXP_CSR_READ = (31 & r0);
    z_printf("Expected_mcountinhibit_csrrci = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrci,r0,800,17);
    z_printf("Actual_mcountinhibit_csrrci = %u\n",r0);
   
    EXP_CSR_READ = (17 & r0);
    z_printf("Expected_mcountinhibit_csrrci = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrci,r0,800,23);
    z_printf("Actual_mcountinhibit_csrrci = %u\n",r0);
   
    EXP_CSR_READ = (23 & r0);
    z_printf("Expected_mcountinhibit_csrrci = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrci,r0,800,9);
    z_printf("Actual_mcountinhibit_csrrci = %u\n",r0);
    
    EXP_CSR_READ = (9 & r0);
    z_printf("Expected_mcountinhibit_csrrci = %u\n",EXP_CSR_READ);
    
    csr_asm_rw_i(csrrci,r0,800,0);
    z_printf("Actual_mcountinhibit_csrrci = %u\n",r0);


//int r0;
/*  csr_asm_rs(csrrsi,r0,768,8); // Enable Mstatus mie bit (write to mstatus_csr) : neesd to be enabled to accept interrupt requests
     //GEN_INT(IRQ_GEN_5);

z_printf("zzzzzzzzzzzzzzzzzzzzzzzzzzz");
 INST_MISALIGNED_EXCEPTION;
 ILLEGAL_INSTRUCTION;*/
  

               // mcause reg whose [11:0] represents interrupt/exception_id,63rd bit field represents interrupt/exception while [23:16] represent previous interrupt level
    z_printf("mcause = %d\n",r0);
        
                  // mcause reg whose [11:0] represents interrupt/exception_id,63rd bit field represents interrupt/exception while [23:16] represent previous interrupt level
   // z_printf("mcause = %d\n",r0);
  csr_asm_rw(csrrw,r0,834,0xFFFFFFFFFFFFFFFF);  
  csr_asm_rw(csrrw,r0,834,0x0000000000000000);  
  csr_asm_rw(csrrc,r0,834,0);
  csr_asm_rw(csrrs,r0,834,0xFFFFFFFFFFFFFFFF);
  csr_asm_rw(csrrc,r0,834,0);
  csr_asm_rw(csrrc,r0,834,1);

  csr_asm_rw(csrrs,r0,834,0x8000000000000000);


  // mcause reg whose [11:0] represents interrupt/exception_id,63rd bit field represents interrupt/exception while [23:16] represent previous interrupt level
    //z_printf("mcause = %d\n",r0);


   //csr_asm_rs(csrrsi,r0,768,8); // Enable Mstatus mie bit (write to mstatus_csr) : neesd to be enabled to accept interrupt requests

    //GEN_INT(IRQ_GEN_5);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////  With Interrupt  ////////////////////////////
/*
    csr_asm_rw(csrrw,r0,768,8);                   // 3rd bit o mstatus should be hign for enabling an Interrupt
    z_printf("mstatus_after Interrupt = %d\n",r0);

   
    csr_asm_rw(csrrw,r0,833,7685);                // mepc to store address/pc value of an instruction that executed trap
    z_printf("mepc = %d\n",r0);

       csr_asm_rw(csrrw,r0,834,0);                 // mcause reg whose [11:0] represents interrupt/exception_id,63rd bit field represents interrupt/exception while [23:16] represent previous interrupt level
    z_printf("mcause = %d\n",r0);
    csr_asm_rw(csrrw,r0,834,764);                 // mcause reg whose [11:0] represents interrupt/exception_id,63rd bit field represents interrupt/exception while [23:16] represent previous interrupt level
    z_printf("mcause = %d\n",r0);

    csr_asm_rw(csrrw,r0,835,876);                 // mtval is written with exception specific Info
    z_printf("mtval = %d\n",r0);
    
    csr_asm_rw(csrrw,r0,773,1);                   // mtvec should hold the base address for interrupt handler
    z_printf("mtvec_1 = %u\n",r0);

//  csr_asm_rs(csrrsi,r0,768,8); // Enable Mstatus mie bit (write to mstatus_csr) : neesd to be enabled to accept interrupt requests

  //  GEN_INT(IRQ_GEN_5);                           // interrupt ID = 21

    //GEN_INT(IRQ_GEN_7);                           // interrupt ID = 23



    csr_asm_rw(csrrw,r0,833,0);
    z_printf("mepc3 = %d\n",r0);                  // mepc will store the pc addr where it enters the trap

    csr_asm_rw(csrrw,r0,834,0); 
    z_printf("mcause after intr/excpt = %d\n",r0);

    csr_asm_rw(csrrw,r0,835,0);                   // mtval will read 876 if there is no exception
    z_printf("mtval = %d\n",r0);

    csr_asm_rw(csrrw,r0,773,0);
    z_printf("mtvec_2 = %u\n",r0);


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    ////////////////////////////////  With Exception  ////////////////////////////////
    
    csr_asm_rw(csrrw,r0,768,8);                   // 3rd bit o mstatus should be hign for enabling an Interrupt
    z_printf("mstatus_after Interrupt = %d\n",r0);

   
    csr_asm_rw(csrrw,r0,833,7685);                // mepc to store address/pc value of an instruction that executed trap
    z_printf("mepc = %d\n",r0);

       
    csr_asm_rw(csrrw,r0,834,764);                 // mcause reg whose [11:0] represents interrupt/exception_id,63rd bit field represents interrupt/exception while [23:16] represent previous interrupt level
    z_printf("mcause = %d\n",r0);

    csr_asm_rw(csrrw,r0,835,876);                 // mtval is written with exception specific Info
    z_printf("mtval = %d\n",r0);
    
    csr_asm_rw(csrrw,r0,773,1);                   // mtvec should hold the base address for interrupt handler
    z_printf("mtvec_1 = %u\n",r0);


   // ILLEGAL_INSTRUCTION ;                         // exception ID = 2

    //ECALL_EXCEPTION;                              // exception ID = 11 

             
           
    csr_asm_rw(csrrw,r0,833,0);
    z_printf("mepc3 = %d\n",r0);                  // mepc will store the pc addr where it enters the trap

    csr_asm_rw(csrrw,r0,834,0); 
    z_printf("mcause after intr/excpt = %d\n",r0);

    csr_asm_rw(csrrw,r0,835,0);                   // mtval will read 876 if there is no exception
    z_printf("mtval = %d\n",r0);

    csr_asm_rw(csrrw,r0,773,0);
    z_printf("mtvec_2 = %u\n",r0);
*/
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////    TO COUNT NO. OF CLOCK CYCLES & INSTRUCTIONS     /////////////////////////////////////////

    /////////////////////// MHPCOUNT, MHPEVENT, MCYCLE, MINSTRET ////////////////////

   z_printf("////////////////   NO. OF CLOCK CYCLES AND NO. OF INSTRUCTIONS   /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    //z_printf("mcountinhibit = %u\n",r0);

    csr_asm_rw(csrrw,r1,2819,0);                  // mhpcounter[3] clear  (0xB03)
    //z_printf("mhpcount_3 = %u\n",r1);

    csr_asm_rw(csrrw,r2,803,0);                   // mhpevent[3] clear    (0x323)
    //z_printf("mhpevent_3 = %u\n",r2);
    
    csr_asm_rw(csrrw,r6,2820,0);                  // mhpcounter[4] clear  (0xB03)
    //z_printf("mhpcount_4 = %u\n",r1);

    csr_asm_rw(csrrw,r5,804,1);                   // mhpevent[4] set    (0x324)
    //z_printf("mhpevent_4 = %u\n",r2);

    csr_asm_rw(csrrw,r3,2816,0);                  // mcycle reg to count number of cycles  (0xB00)
    //z_printf("mcycle = %u\n",r3);

    csr_asm_rw(csrrw,r4,2818,0);                  // minstret reg to count number of instructions   (0xB02)
    //z_printf("minstert = %u\n",r4);

   

         __asm__  ("add a5,a5,a4;"
                   "bne a5,a4,branch1;"
                   "branch1: beq a5,a4,branch2;"
                   "branch2: beq a5,a4,branch3;"
                   "branch3: nop;"
                   "sub a5,a5,a4;"
                   "mul a5,a5,a4;"
                   );
    

    csr_asm_rw(csrrw,r2,803,0);                   // mhpevent[3] clear    (0x323)
    //z_printf("Actual_mhpevent_3 = %u\n",r2);

    csr_asm_rw(csrrw,r5,804,0);                   // mhpevent[4] clear    (0x323)
    //z_printf("mhpevent_4 = %u\n",r2);

    csr_asm_rw(csrrw,r0,800,5);                   // setting CY,IR & HPMn bit fields in mcountinhibit (0x320)
    //z_printf("mcountinhibit = %u\n",r0);

    csr_asm_rw(csrrw,r4,2818,0);                  // minstret reg to count number of instructions   (0xB02)
    z_printf("number of instructions = %u\n",r4);

    csr_asm_rw(csrrw,r1,2819,0);                  // mhpcount[3] clear  (0xB03)
    z_printf("mhpcounter_3 = %u\n",r1);

    csr_asm_rw(csrrw,r6,2820,0);                  // mhpcount[4] clear  (0xB04)
    z_printf("mhpcounter_4 = %u\n",r6);

    csr_asm_rw(csrrw,r3,2816,0);                  // mcycle reg to count number of cycles  (0xB00)
    z_printf("number of clock cycle = %u\n",r3);

   z_printf("////////////////   MHPM COUNTER_3  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2819,0);                  // mhpcounter[3] clear  (0xB03)
    csr_asm_rw(csrrw,r2,803,0);                   // mhpevent[3] clear    (0x323)
    
    csr_asm_rw(csrrw,r2,803,18446744073709551615);                    //mhpevent[3] set
    //csr_asm_rw(cssrw,r0,800,1); //mcounterinhibit[3]= 0
    csr_asm_rw(csrrw,r1,2819,18446744073709551615);//mhp counter[3] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_3 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2819,0);                  // mhpcounter[3] clear  (0xB03)
    csr_asm_rw(csrrw,r2,803,0);                   // mhpevent[3] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);
    
    z_printf("////////////////   MHPM COUNTER_4  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2820,0);                  // mhpcounter[4] clear  (0xB04)
    csr_asm_rw(csrrw,r2,804,0);                   // mhpevent[4] clear    (0x324)
    
    csr_asm_rw(csrrw,r2,804,18446744073709551615);                    //mhpevent[4] set
    //csr_asm_rw(cssrw,r0,800,18446744073709551599); //mcounterinhibit[4]= 0
    csr_asm_rw(csrrw,r1,2820,18446744073709551615);//mhp counter[4] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_4 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2820,0);                  // mhpcounter[4] clear  (0xB04)
    csr_asm_rw(csrrw,r2,804,0);                   // mhpevent[4] clear    (0x324)
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    
    z_printf("////////////////   MHPM COUNTER_5  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2821,0);                  // mhpcounter[5] clear  (0xB05)
    csr_asm_rw(csrrw,r2,805,0);                   // mhpevent[5] clear    (0x325)
    
    csr_asm_rw(csrrw,r2,805,18446744073709551615);                    //mhpevent[5] set
    //csr_asm_rw(cssrw,r0,800,18446744073709551583); //mcounterinhibit[5]= 0
    csr_asm_rw(csrrw,r1,2821,18446744073709551615);//mhp counter[5] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_5 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2821,0);                  // mhpcounter[5] clear  (0xB05)
    csr_asm_rw(csrrw,r2,805,0);                   // mhpevent[5] clear    (0x325)
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)

    z_printf("////////////////   MHPM COUNTER_6  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2822,0);                  // mhpcounter[6] clear  (0xB06)
    csr_asm_rw(csrrw,r2,806,0);                   // mhpevent[6] clear    (0x326)
    
    csr_asm_rw(csrrw,r2,806,18446744073709551615);                    //mhpevent[6] set
    //csr_asm_rw(cssrw,r0,800,18446744073709551551); //mcounterinhibit[6]= 0
    csr_asm_rw(csrrw,r1,2822,18446744073709551615);//mhp counter[6] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_6 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2822,0);                  // mhpcounter[6] clear  (0xB06)
    csr_asm_rw(csrrw,r2,806,0);                   // mhpevent[6] clear    (0x326)
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)

    z_printf("////////////////   MHPM COUNTER_7  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2823,0);                  // mhpcounter[7] clear  (0xB07)
    csr_asm_rw(csrrw,r2,807,0);                   // mhpevent[7] clear    (0x327)
    
    csr_asm_rw(csrrw,r2,807,18446744073709551615);                    //mhpevent[7] set
    //csr_asm_rw(cssrw,r0,800,18446744073709551487); //mcounterinhibit[7]= 0
    csr_asm_rw(csrrw,r1,2823,18446744073709551615);//mhp counter[7] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_7 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2823,0);                  // mhpcounter[7] clear  (0xB07)
    csr_asm_rw(csrrw,r2,807,0);                   // mhpevent[7] clear    (0x327)
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)

    z_printf("////////////////   MHPM COUNTER_8  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2824,0);                  // mhpcounter[8] clear  (0xB08)
    csr_asm_rw(csrrw,r2,808,0);                   // mhpevent[8] clear    (0x328)
    
    csr_asm_rw(csrrw,r2,808,18446744073709551615);                    //mhpevent[8] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[8]= 0
    csr_asm_rw(csrrw,r1,2824,18446744073709551615);//mhp counter[8] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_8 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2824,0);                  // mhpcounter[8] clear  (0xB08)
    csr_asm_rw(csrrw,r2,808,0);                   // mhpevent[8] clear    (0x328)
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)


    z_printf("////////////////   MHPM COUNTER_9  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2825,0);                  // mhpcounter[9] clear  (0xB09)
    csr_asm_rw(csrrw,r2,809,0);                   // mhpevent[9] clear    (0x329)
    
    csr_asm_rw(csrrw,r2,809,18446744073709551615);                    //mhpevent[9] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[9]= 0
    csr_asm_rw(csrrw,r1,2825,18446744073709551615);//mhp counter[9] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_9 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2825,0);                  // mhpcounter[9] clear  (0xB09)
    csr_asm_rw(csrrw,r2,809,0);                   // mhpevent[9] clear    (0x329)
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)

    z_printf("////////////////   MHPM COUNTER_10  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2826,0);                  // mhpcounter[10] clear  (0xB0A)
    csr_asm_rw(csrrw,r2,810,0);                   // mhpevent[10] clear    (0x32A)
    
    csr_asm_rw(csrrw,r2,810,18446744073709551615);                    //mhpevent[10] set
    //csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[10]= 0
    csr_asm_rw(csrrw,r1,2826,18446744073709551615);//mhp counter[10] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_10 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2826,0);                  // mhpcounter[10] clear  (0xB0A)
    csr_asm_rw(csrrw,r2,810,0);                   // mhpevent[10] clear    (0x32A)
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)


    z_printf("////////////////   MHPM COUNTER_11  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2827,0);                  // mhpcounter[11] clear  (0xB0B)
    csr_asm_rw(csrrw,r2,811,0);                   // mhpevent[11] clear    (0x32B)
    
    csr_asm_rw(csrrw,r2,811,18446744073709551615);                    //mhpevent[11] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[11]= 0
    csr_asm_rw(csrrw,r1,2827,18446744073709551615);//mhp counter[11] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_11 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2827,0);                  // mhpcounter[11] clear  (0xB0B)
    csr_asm_rw(csrrw,r2,811,0);                   // mhpevent[11] clear    (0x32B)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_12  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2828,0);                  // mhpcounter[12] clear  (0xB0C)
    csr_asm_rw(csrrw,r2,812,0);                   // mhpevent[12] clear    (0x32C)
    
    csr_asm_rw(csrrw,r2,812,18446744073709551615);                    //mhpevent[12] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[12]= 0
    csr_asm_rw(csrrw,r1,2828,18446744073709551615);//mhp counter[12] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_12 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2828,0);                  // mhpcounter[12] clear  (0xB0C)
    csr_asm_rw(csrrw,r2,812,0);                   // mhpevent[12] clear    (0x32C)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_13  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2829,0);                  // mhpcounter[13] clear  (0xB0D)
    csr_asm_rw(csrrw,r2,813,0);                   // mhpevent[13] clear    (0x32D)
    
    csr_asm_rw(csrrw,r2,813,18446744073709551615);                    //mhpevent[13] set
    //csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[13]= 0
    csr_asm_rw(csrrw,r1,2829,18446744073709551615);//mhp counter[13] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_13 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2829,0);                  // mhpcounter[13] clear  (0xB0D)
    csr_asm_rw(csrrw,r2,813,0);                   // mhpevent[13] clear    (0x32D)
    csr_asm_rw(csrrw,r0,800,0);


    z_printf("////////////////   MHPM COUNTER_14  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2830,0);                  // mhpcounter[14] clear  (0xB0E)
    csr_asm_rw(csrrw,r2,814,0);                   // mhpevent[14] clear    (0x32E)
    
    csr_asm_rw(csrrw,r2,814,18446744073709551615);                    //mhpevent[14] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[14]= 0
    csr_asm_rw(csrrw,r1,2830,18446744073709551615);//mhp counter[14] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_14 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2830,0);                  // mhpcounter[14] clear  (0xB0E)
    csr_asm_rw(csrrw,r2,814,0);                   // mhpevent[14] clear    (0x32E)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_15  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2831,0);                  // mhpcounter[15] clear  (0xB0F)
    csr_asm_rw(csrrw,r2,815,0);                   // mhpevent[15] clear    (0x32F)
    
    csr_asm_rw(csrrw,r2,815,18446744073709551615);                    //mhpevent[15] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[15]= 0
    csr_asm_rw(csrrw,r1,2831,18446744073709551615);//mhp counter[15] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_15 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2831,0);                  // mhpcounter[15] clear  (0xB0F)
    csr_asm_rw(csrrw,r2,815,0);                   // mhpevent[15] clear    (0x32F)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_16  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2832,0);                  // mhpcounter[16] clear  (0xB10)
    csr_asm_rw(csrrw,r2,816,0);                   // mhpevent[16] clear    (0x330)
    
    csr_asm_rw(csrrw,r2,816,18446744073709551615);                    //mhpevent[16] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[16]= 0
    csr_asm_rw(csrrw,r1,2832,18446744073709551615);//mhp counter[16] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_16 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2832,0);                  // mhpcounter[16] clear  (0xB10)
    csr_asm_rw(csrrw,r2,816,0);                   // mhpevent[16] clear    (0x330)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_17  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2833,0);                  // mhpcounter[17] clear  (0xB11)
    csr_asm_rw(csrrw,r2,817,0);                   // mhpevent[17] clear    (0x331)
    
    csr_asm_rw(csrrw,r2,817,18446744073709551615);                    //mhpevent[17] set
    //csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[17]= 0
    csr_asm_rw(csrrw,r1,2833,18446744073709551615);//mhp counter[17] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_17 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2833,0);                  // mhpcounter[17] clear  (0xB11)
    csr_asm_rw(csrrw,r2,817,0);                   // mhpevent[17] clear    (0x331)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_18  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2834,0);                  // mhpcounter[18] clear  (0xB03)
    csr_asm_rw(csrrw,r2,818,0);                   // mhpevent[18] clear    (0x323)
    
    csr_asm_rw(csrrw,r2,818,18446744073709551615);                    //mhpevent[18] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[18]= 0
    csr_asm_rw(csrrw,r1,2834,18446744073709551615);//mhp counter[18] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_18 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2834,0);                  // mhpcounter[18] clear  (0xB03)
    csr_asm_rw(csrrw,r2,818,0);                   // mhpevent[18] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);


    z_printf("////////////////   MHPM COUNTER_19  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2835,0);                  // mhpcounter[19] clear  (0xB03)
    csr_asm_rw(csrrw,r2,819,0);                   // mhpevent[19] clear    (0x323)
    
    csr_asm_rw(csrrw,r2,819,18446744073709551615);                    //mhpevent[19] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[19]= 0
    csr_asm_rw(csrrw,r1,2835,18446744073709551615);//mhp counter[19] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_19 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2835,0);                  // mhpcounter[19] clear  (0xB03)
    csr_asm_rw(csrrw,r2,819,0);                   // mhpevent[19] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_20  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2836,0);                  // mhpcounter[20] clear  (0xB03)
    csr_asm_rw(csrrw,r2,820,0);                   // mhpevent[20] clear    (0x323)
    
    csr_asm_rw(csrrw,r2,820,18446744073709551615);                    //mhpevent[20] set
    //csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[20]= 0
    csr_asm_rw(csrrw,r1,2836,18446744073709551615);//mhp counter[20] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_20 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2836,0);                  // mhpcounter[20] clear  (0xB03)
    csr_asm_rw(csrrw,r2,820,0);                   // mhpevent[20] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_21  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2837,0);                  // mhpcounter[21] clear  (0xB03)
    csr_asm_rw(csrrw,r2,821,0);                   // mhpevent[21] clear    (0x323)
    
    csr_asm_rw(csrrw,r2,821,18446744073709551615);                    //mhpevent[21] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[21]= 0
    csr_asm_rw(csrrw,r1,2837,18446744073709551615);//mhp counter[21] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_21 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2837,0);                  // mhpcounter[21] clear  (0xB03)
    csr_asm_rw(csrrw,r2,821,0);                   // mhpevent[21] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_22  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2838,0);                  // mhpcounter[22] clear  (0xB03)
    csr_asm_rw(csrrw,r2,822,0);                   // mhpevent[22] clear    (0x323)
    
    csr_asm_rw(csrrw,r2,822,18446744073709551615);                    //mhpevent[22] set
    //csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[22]= 0
    csr_asm_rw(csrrw,r1,2838,18446744073709551615);//mhp counter[22] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_22 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2838,0);                  // mhpcounter[22] clear  (0xB03)
    csr_asm_rw(csrrw,r2,822,0);                   // mhpevent[22] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_23  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2839,0);                  // mhpcounter[22] clear  (0xB03)
    csr_asm_rw(csrrw,r2,823,0);                   // mhpevent[22] clear    (0x323)
    
    csr_asm_rw(csrrw,r2,823,18446744073709551615);                    //mhpevent[22] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[22]= 0
    csr_asm_rw(csrrw,r1,2839,18446744073709551615);//mhp counter[22] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_22 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2839,0);                  // mhpcounter[22] clear  (0xB03)
    csr_asm_rw(csrrw,r2,823,0);                   // mhpevent[22] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_24  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2840,0);                  // mhpcounter[24] clear  (0xB03)
    csr_asm_rw(csrrw,r2,824,0);                   // mhpevent[24] clear    (0x323)
    
    csr_asm_rw(csrrw,r2,824,18446744073709551615);                    //mhpevent[24] set
    //csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[24]= 0
    csr_asm_rw(csrrw,r1,2840,18446744073709551615);//mhp counter[24] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_24 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2840,0);                  // mhpcounter[24] clear  (0xB03)
    csr_asm_rw(csrrw,r2,824,0);                   // mhpevent[24] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_25  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2841,0);                  // mhpcounter[25] clear  (0xB03)
    csr_asm_rw(csrrw,r2,825,0);                   // mhpevent[25] clear    (0x323)
    
    csr_asm_rw(csrrw,r2,825,18446744073709551615);                    //mhpevent[25] set
    //csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[25]= 0
    csr_asm_rw(csrrw,r1,2841,18446744073709551615);//mhp counter[25] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_25 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2841,0);                  // mhpcounter[25] clear  (0xB03)
    csr_asm_rw(csrrw,r2,825,0);                   // mhpevent[25] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_26  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2842,0);                  // mhpcounter[26] clear  (0xB03)
    csr_asm_rw(csrrw,r2,826,0);                   // mhpevent[26] clear    (0x323)
    
    csr_asm_rw(csrrw,r2,826,18446744073709551615);                    //mhpevent[26] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[26]= 0
    csr_asm_rw(csrrw,r1,2842,18446744073709551615);//mhp counter[26] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_26 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2842,0);                  // mhpcounter[26] clear  (0xB03)
    csr_asm_rw(csrrw,r2,826,0);                   // mhpevent[26] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);


    z_printf("////////////////   MHPM COUNTER_27  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2843,0);                  // mhpcounter[27] clear  (0xB03)
    csr_asm_rw(csrrw,r2,827,0);                   // mhpevent[27] clear    (0x323)
    
    csr_asm_rw(csrrw,r2,827,18446744073709551615);                    //mhpevent[27] set
    //csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[27]= 0
    csr_asm_rw(csrrw,r1,2843,18446744073709551615);//mhp counter[27] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_27 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2843,0);                  // mhpcounter[27] clear  (0xB03)
    csr_asm_rw(csrrw,r2,827,0);                   // mhpevent[27] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);


    z_printf("////////////////   MHPM COUNTER_28  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2844,0);                  // mhpcounter[28] clear  (0xB03)
    csr_asm_rw(csrrw,r2,828,0);                   // mhpevent[28] clear    (0x323)
    
    csr_asm_rw(csrrw,r2,828,18446744073709551615);                    //mhpevent[28] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[28]= 0
    csr_asm_rw(csrrw,r1,2844,18446744073709551615);//mhp counter[28] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_28 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2844,0);                  // mhpcounter[28] clear  (0xB03)
    csr_asm_rw(csrrw,r2,828,0);                   // mhpevent[28] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_29  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2845,0);                  // mhpcounter[29] clear  (0xB03)
    csr_asm_rw(csrrw,r2,829,0);                   // mhpevent[29] clear    (0x323)
    
    csr_asm_rw(csrrw,r2,829,18446744073709551615);                    //mhpevent[29] set
    //csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[29]= 0
    csr_asm_rw(csrrw,r1,2845,18446744073709551615);//mhp counter[29] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_29 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2845,0);                  // mhpcounter[29] clear  (0xB03)
    csr_asm_rw(csrrw,r2,829,0);                   // mhpevent[29] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_30  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2846,0);                  // mhpcounter[30] clear  (0xB03)
    csr_asm_rw(csrrw,r2,830,0);                   // mhpevent[30] clear    (0x323)
    
    csr_asm_rw(csrrw,r2,830,18446744073709551615);                    //mhpevent[30] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[30]= 0
    csr_asm_rw(csrrw,r1,2846,18446744073709551615);//mhp counter[30] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_30 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2846,0);                  // mhpcounter[30] clear  (0xB03)
    csr_asm_rw(csrrw,r2,830,0);                   // mhpevent[30] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);

    z_printf("////////////////   MHPM COUNTER_31  /////////////////\n");
       
    csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,2847,0);                  // mhpcounter[31] clear  (0xB03)
    csr_asm_rw(csrrw,r2,831,0);                   // mhpevent[31] clear    (0x323)
    
    csr_asm_rw(csrrw,r2,831,18446744073709551615);                    //mhpevent[31] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[31]= 0
    csr_asm_rw(csrrw,r1,2847,18446744073709551615);//mhp counter[31] set   

    for(int i=0;i<=64;i++)
    {
        z_printf("mhpcounter_31 = %u\n",r1);            
    }

    csr_asm_rw(csrrw,r1,2847,0);                  // mhpcounter[31] clear  (0xB03)
    csr_asm_rw(csrrw,r2,831,0);                   // mhpevent[31] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);

//////////////////////////////////////////////////////////////////////////////////////
//WORKING FINE(DCSR)
/*csr_asm_rw(csrrw,r0,800,0);    // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)

        csr_asm_rw(csrrs,r1,2847,0);
csr_asm_rw(csrrs,r1,831,0);//
 csr_asm_rw(csrrc,r1,2847,0);//
csr_asm_rw(csrrc,r1,831,0);//
    csr_asm_rw(csrrs,r1,1968,0);  // mhpcounter[28] clear  (0xB03)
    csr_asm_rw(csrrc,r1,1968,0);
   // csr_asm_rw(csrrw,r2,828,0);                   // mhpevent[28] clear    (0x323)
    csr_asm_rw(csrrw,r1,1968,0);
    //csr_asm_rw(csrrw,r2,828,18446744073709551615);                    //mhpevent[28] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[28]= 0
    csr_asm_rw(csrrw,r1,1968,18446744073709551615);//mhp counter[28] set   

 
    csr_asm_rw(csrrw,r1,1968,0);                  // mhpcounter[28] clear  (0xB03)
 //   csr_asm_rw(csrrw,r2,828,0);                   // mhpevent[28] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);*/
//////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////// 
//////////////////////////dcsr/////////////////////////////////////////////////////////
//NEW DCSR//
z_printf("entering");
     csr_asm_rw(csrrw,r0,800,0); 
     csr_asm_rw(csrrs,r1,2847,0);
    csr_asm_rw(csrrc,r1,2847,0);
    csr_asm_rw(csrrs,r1,831,0);
    csr_asm_rw(csrrc,r1,831,0);
        csr_asm_rw(csrrs,r1,1968,0);
    csr_asm_rw(csrrc,r1,1968,0);
                      // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,1968,0);                  // mhpcounter[31] clear  (0xB03)
    //csr_asm_rw(csrrw,r2,831,0);                   // mhpevent[31] clear    (0x323)
  z_printf("entering_1");  
  //  csr_asm_rw(csrrw,r2,831,2);                    //mhpevent[31] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[31]= 0
    csr_asm_rw(csrrw,r1,1968,18446744073709551615);//mhp counter[31] set   

   z_printf("value of dscr = %u\n",r1); 
    csr_asm_rw(csrrs,r1,1968,1);
     csr_asm_rw(csrrc,r1,1968,1);  // mhpcounter[31] clear  (0xB03)
    //csr_asm_rw(csrrw,r2,831,0);                   // mhpevent[31] clear    (0x323)
     csr_asm_rw(csrrw,r0,800,0);
z_printf("exit");

////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////dcsr/////////////////////////////////////////////////////////
z_printf("entering");
csr_asm_rw(csrrw,r0,800,0); 
 csr_asm_rw(csrrs,r1,1968,0);
    csr_asm_rw(csrrc,r1,1968,0);
csr_asm_rw(csrrs,r1,1969,0);
    csr_asm_rw(csrrc,r1,1969,0);
                      // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
   // csr_asm_rw(csrrw,r1,4016,0);                  // mhpcounter[31] clear  (0xB03)
    //csr_asm_rw(csrrw,r2,831,0);                   // mhpevent[31] clear    (0x323)
  z_printf("entering_1");  
  //  csr_asm_rw(csrrw,r2,831,2);                    //mhpevent[31] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[31]= 0
    csr_asm_rw(csrrw,r1,1969,18446744073709551615);//mhp counter[31] set   

   z_printf("value of dscr = %u\n",r1); 
    csr_asm_rw(csrrw,r1,1969,0);                  // mhpcounter[31] clear  (0xB03)
    //csr_asm_rw(csrrw,r2,831,0);                   // mhpevent[31] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);
z_printf("exit");
///////////////mcause ka method////////////////////////////////////////////////////////
/*  csr_asm_rw(csrrw,r0,1968,18446744073709551615);  
  csr_asm_rw(csrrw,r0,1968,0x0000000000000000);  
  csr_asm_rw(csrrc,r0,1968,0);
  csr_asm_rw(csrrs,r0,1968,18446744073709551615);
  csr_asm_rw(csrrc,r0,1968,0);
  csr_asm_rw(csrrc,r0,1968,1);

  csr_asm_rw(csrrs,r0,1968,0x8000000000000000);

csr_asm_rw(csrrw,r0,1969,18446744073709551615);  
  csr_asm_rw(csrrw,r0,1969,0x0000000000000000);  
  csr_asm_rw(csrrc,r0,1969,0);
  csr_asm_rw(csrrs,r0,1969,18446744073709551615);
  csr_asm_rw(csrrc,r0,1969,0);
  csr_asm_rw(csrrc,r0,1969,1);

  csr_asm_rw(csrrs,r0,1969,0x8000000000000000);

*/

//////////////////////////dcsr/////////////////////////////////////////////////////////

z_printf("entering");
//csr_asm_rw(csrrs,r1,4016,0);
  //  csr_asm_rw(csrrc,r1,4016,0);
    csr_asm_rw(csrrs,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrc,r1,1969,0);                  // mhpcounter[31] clear  (0xB03)
    csr_asm_rw(csrrw,r1,1969,18446744073709551615);
    //csr_asm_rw(csrrc,r1,1969,18446744073709551615);

    //csr_asm_rw(csrrw,r2,831,0);                   // mhpevent[31] clear    (0x323)
  z_printf("entering_1");  
  //  csr_asm_rw(csrrw,r2,831,2);                    //mhpevent[31] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[31]= 0
    csr_asm_rw(csrrw,r1,1969,18446744073709551615);//mhp counter[31] set   

   z_printf("value of dscr = %u\n",r1); 
    csr_asm_rw(csrrs,r1,1969,1);                  // mhpcounter[31] clear  (0xB03)
    //csr_asm_rw(csrrw,r2,831,0);                   // mhpevent[31] clear    (0x323)
    csr_asm_rw(csrrc,r0,800,1);
z_printf("exit");
//////////////////////////////////////////fc1///////////////////////////////


/*csr_asm_rw(csrrw,r0,800,0);                   // clearing CY,IR & HPMn bit fields in mcountinhibit (0x320)
    csr_asm_rw(csrrw,r1,4033,0);                  // mhpcounter[28] clear  (0xB03)
   // csr_asm_rw(csrrw,r2,4033,0);                   // mhpevent[28] clear    (0x323)
    
    //csr_asm_rw(csrrw,r2,828,18446744073709551615);                    //mhpevent[28] set
   // csr_asm_rw(cssrw,r0,800,18446744073709551359); //mcounterinhibit[28]= 0
    csr_asm_rw(csrrw,r1,4033,18446744073709551615);//mhp counter[28] set   

 
    csr_asm_rw(csrrw,r1,4033,0);                  // mhpcounter[28] clear  (0xB03)
 //   csr_asm_rw(csrrw,r2,828,0);                   // mhpevent[28] clear    (0x323)
    csr_asm_rw(csrrw,r0,800,0);*/
   
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

    mailbox_send_request(MAILBOX1, END_SIM);
    mailbox_send_request(MAILBOX2, error_cnt); 
    return 0;
   
}

