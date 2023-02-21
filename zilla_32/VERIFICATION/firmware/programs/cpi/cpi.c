//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Copyright Â© 2022 Vivartan Technologies., All rights reserved/////////////////////////////
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
/*Copyright © 2021 Frenustech Private Ltd., All rights reserved.

All works published under Zilla_Gen_0 by the Frenustech Private Ltd. 
is copyrighted by the Association and ownership of all right, title and interest
in and to the works remains with Frenustech Private Ltd..

No works or documents published under Zilla_Gen_0 by Frenustech Private Ltd. may be reproduced,
transmitted or copied without the express written permission of Frenustech Private Ltd.
will be considered as a violations of Copyright Act and it may lead to legal action.
*/

/***** CPI analysis for various types of instructions are done in this. I-Type, R-Type, MUL & DIV, S & SB- Type, U & UJ-Type 
 * custom instrucions, rotate instrutions are considered separately. Number of instructions and cycles are calculated using CSR register.
 * Then cycles per instructions is calculated and analysis is done. Inline assembly coding is done for inlcuding the instructions.**/

#include<stdio.h>  
#include <stdlib.h>
#include <limits.h>             /*!< Datatype limit         */
#include <stdint.h>             /*!< Standarad Integer type */
#include "custom.h"
#include "print.h"              /*!< Mailbox print library  */
#include "linker.h"             /*!< Linker symbols library */
#include "mailbox.h"            /*!< Mailbox access library */
#include "testmacro.h"          /*!< Test macros            */

 #define csr_asm_rwi(inst,rd,imm,imm1)\
         asm volatile (#inst "    %[z], "#imm", "#imm1"\n\t"  : [z] "=r" (rd)  )

uint64_t r0,r1,r2,r3,r4,r5;

static  unsigned long start,stop,start_cycle,start_instn,stop_cycle,stop_instn;

int main()
{ 
  
  /******************** I-TYPE************************/
  csr_asm_rwi( csrrwi,r0,0x320,0); //inhibit -clear needed for counter, instruction,cycle registers to start        
  csr_asm_rwi(csrrwi,start_cycle,0xB00,0);   //mcycle  
  csr_asm_rwi(csrrwi,start_instn,0xB02,0);  // instruction count -minstret
   
   __asm__ (
            "lui a0,0x5;"
             "lui a1,0x4;"
             "lui a2,0x4;"
             "lui a3,0x3;"
             "lui a4,0x2;"
             "lui a5,0x1;"
             "lui a6,0x0;"       
             "mv a1,a4;"
             "mv a1,a5;" 
            
             //addition
             "addi a5,a5,0x14;"
             "addiw a2,a5,0x16;"

             //logical and
             "andi a1,a4,0x4;"

             //logical or
             "ori a5,a5,0x45;"

             //logial xor
             "xori a5,a5,0x45;"

             //shift lft logical
             "slli a0,a1,0x3;"
             "slliw a2,a3,0x5;"

             //shift right logical
             "srli a0,a1,0x3;"
             "srliw a2,a3,0x5;"
             "srai a0,a1,0x3;"
             "sraiw a2,a3,0x5;"

             "slti a4,a5,0x6;"
             "sltiu a6,a4,0x5;"

             //LOAD 
             "lb	    a5,0(a1);"
             "lbu	    a4,0(a1);"
             "lh	    a3,0(a1);"
             "lhu	    a4,0(a1);"
             "ld	    a2,0(a1);"
             "lw	    a1,0(a0);"
             "lwu	    a6,0(a0);"                 
           );

   csr_asm_rwi(csrrwi,r3,0x320,5);
   csr_asm_rwi(csrrwi,stop_instn,0xB02,0);  // instruction count
   csr_asm_rwi(csrrwi,stop_cycle,0xB00,0);   //mcycle 
   z_printf(" Total I-type instructions executed are  : %d \n",stop_instn-3); 
   z_printf(" Total Cycles for I-Type Instructions are: %d \n",(stop_cycle-6)); 
   z_printf(" Average CPI for I-Type Instructions : %d.%d \n\n",((stop_cycle-6)/(stop_instn-3)),(((stop_cycle-6)%(stop_instn-3))*10)/(stop_instn-3)); 




    /******************** R-TYPE************************/

  csr_asm_rwi( csrrwi,r0,0x320,0); //inhibit -clear needed for counter, instruction,cycle registers to start        
  csr_asm_rwi(csrrwi,start_cycle,0xB00,0);   //mcycle  
  csr_asm_rwi(csrrwi,start_instn,0xB02,0);  // instruction count -minstret

  __asm__ (
           
           //addition

           "add a5,a5,a4;"
           "addw a5,a5,a4;"


           //substraction
           "sub a4,a4,a1;"
           "subw a4,a4,a1;"
         
           
           //logical and
           "and a3,a4,a5;"
  
           //logical or
           "or a5,a5,a4;"

           //logical xor
            "xor a5,a5,a4;"

           //shift left logical
           "sll a0,a1,a3;"
           "sllw a2,a3,a5;"

           //shift right logical
           "srl a0,a1,a3;"
           "srlw a2,a3,a5;"

           //shift right arithmetic
           "sra a0,a1,a3;"
           "sraw a2,a3,a5;"   

           "slt a6,a4,a5;"
           "sltu a5,a6,a0;"
         );
   csr_asm_rwi(csrrwi,r3,0x320,5);
   csr_asm_rwi(csrrwi,stop_instn,0xB02,0);  // instruction count
   csr_asm_rwi(csrrwi,stop_cycle,0xB00,0);   //mcycle  
   z_printf(" Total R-type instructions executed are  : %d \n",stop_instn-3); 
   z_printf(" Total Cycles for R-Type Instructions are: %d \n",(stop_cycle-6)); 
   z_printf(" Average CPI for R-Type Instructions : %d.%d \n\n",((stop_cycle-6)/(stop_instn-3)),(((stop_cycle-6)%(stop_instn-3))*10)/(stop_instn-3)); 

 /******************** Mul , Div & rem -TYPE************************/

  csr_asm_rwi( csrrwi,r0,0x320,0); //inhibit -clear needed for counter, instruction,cycle registers to start        
  csr_asm_rwi(csrrwi,start_cycle,0xB00,0);   //mcycle  
  csr_asm_rwi(csrrwi,start_instn,0xB02,0);  // instruction count -minstret

  __asm__ (    
           //division
           "div a5,a5,a4;"
           "divu a5,a5,a4;"
           "divw a5,a4,a5;"
           "divuw a4,a5,a4;"


           //multiplication
          "mul a4,a4,a5;"
          "mulh a4,a4,a5;"
          "mulhu a4,a4,a5;"
          "mulhsu a4,a4,a5;"
          "mulw a4,a6,a0;" 
          
  
           //reminder
           "rem a0,a4,a6;"
           "remu a1,a4,a2;"
           "remw a2,a5,a6;"
           "remuw a5,a1,a2;"
   
           );
   csr_asm_rwi(csrrwi,r3,0x320,5);
   csr_asm_rwi(csrrwi,stop_instn,0xB02,0);  // instruction count
   csr_asm_rwi(csrrwi,stop_cycle,0xB00,0);   //mcycle  
   z_printf(" Total  Mul, Div & Rem-type instructions executed are  : %d \n",stop_instn-3); 
   z_printf(" Total Cycles for Mul, Div & Rem-Type Instructions are: %d \n",(stop_cycle-6)); 
   z_printf(" Average CPI for Mul,Div & Rem-Type Instructions : %d.%d \n\n",((stop_cycle-6)/(stop_instn-3)),(((stop_cycle-6)%(stop_instn-3))*10)/(stop_instn-3)); 
 /******************** S-TYPE************************/

  csr_asm_rwi( csrrwi,r0,0x320,0); //inhibit -clear needed for counter, instruction,cycle registers to start        
  csr_asm_rwi(csrrwi,start_cycle,0xB00,0);   //mcycle  
  csr_asm_rwi(csrrwi,start_instn,0xB02,0);  // instruction count -minstret

  __asm__ (            
           "sb  	a5,0(a1) ;"  
           "sh  	a4,0(a1) ;"             
           "sw  	a3,0(a1) ;"            
           "sd  	a2,0(a1) ;"  
            
          );
  csr_asm_rwi(csrrwi,r3,0x320,5);
  csr_asm_rwi(csrrwi,stop_instn,0xB02,0);  // instruction count
  csr_asm_rwi(csrrwi,stop_cycle,0xB00,0);   //mcycle  
  z_printf(" Total S-type instructions executed are  : %d \n",stop_instn-3); 
  z_printf(" Total Cycles for S-Type Instructions are: %d \n",(stop_cycle-6)); 
  z_printf(" Average CPI for S-Type Instructions : %d.%d \n\n",((stop_cycle-6)/(stop_instn-3)),(((stop_cycle-6)%(stop_instn-3))*10)/(stop_instn-3)); 


/******************** B-TYPE************************/

  csr_asm_rwi( csrrwi,r0,0x320,0); //inhibit -clear needed for counter, instruction,cycle registers to start        
  csr_asm_rwi(csrrwi,start_cycle,0xB00,0);   //mcycle  
  csr_asm_rwi(csrrwi,start_instn,0xB02,0);  // instruction count -minstret

 __asm__ (        
            
             "lui a5,0x5;"
             "lui a6,0x0;" 
             " beq  	a5,a6,b00;"   
             " b00: beq  	a5,a6,b01  ;"  
             " b01: beq  	a5,a6,b02  ;"  
             " b02: beq  	a5,a6,b03  ;"  
             " b03: beq  	a5,a6,b10  ;"  
             " b10: bne  	a5,a6,b11  ;"  
             " b11: bne  	a5,a6,b12  ;"  
             " b12: bne  	a5,a6,b13  ;"  
             " b13: bne  	a5,a6,b14  ;" 
             " b14: bne  	a5,a6,b20  ;"  
             " b20: bge  	a5,a6,b21 ;"    
             " b21: bge  	a5,a6,b22 ;"  
             " b22: bge  	a5,a6,b23 ;"  
             " b23: bge  	a5,a6,b24 ;"  
             " b24: bge  	a5,a6,b30 ;"  
             " b30: bgeu  	a5,a6,b31 ;"  
             " b31:bgeu  	a5,a6,b32 ;"  
             " b32:bgeu  	a5,a6,b33 ;"   
             " b33:bgeu  	a5,a6,b34 ;"  
             " b34:bgeu  	a5,a6,b40 ;"   
             " b40:blt  	a5,a6,b41;" 
             " b41:blt  	a5,a6,b42;"  
             " b42:blt  	a5,a6,b43;"  
             " b43:blt  	a5,a6,b44;"  
             " b44:blt  	a5,a6,b50;"  
             " b50:bltu  	a5,a6,b51;" 
             " b51:bltu  	a5,a6,b52;"  
             " b52:bltu  	a5,a6,b53;"  
             " b53:bltu  	a5,a6,b54;"  
             " b54:bltu  	a5,a6,b6;"  
             " b6 :nop;"
         );

  csr_asm_rwi(csrrwi,r3,0x320,5);
  csr_asm_rwi(csrrwi,stop_instn,0xB02,0);  // instruction count
  csr_asm_rwi(csrrwi,stop_cycle,0xB00,0);   //mcycle  
  z_printf(" Total B-type instructions executed are  : %d \n",stop_instn-3); 
  z_printf(" Total Cycles for B-Type Instructions are: %d \n",(stop_cycle-6)); 
  z_printf(" Average CPI for B-Type Instructions : %d.%d \n\n",((stop_cycle-6)/(stop_instn-3)),(((stop_cycle-6)%(stop_instn-3))*10)/(stop_instn-3)); 

 /******************** U & J-TYPE************************/

  csr_asm_rwi( csrrwi,r0,0x320,0); //inhibit -clear needed for counter, instruction,cycle registers to start        
  csr_asm_rwi(csrrwi,start_cycle,0xB00,0);   //mcycle  
  csr_asm_rwi(csrrwi,start_instn,0xB02,0);  // instruction count -minstret

  __asm__ (
            
            "jump0:jal a6,jump1;"
            "jump1: nop;"
            "auipc a4,0x0;"
            "jalr a6,a4,0x8;"
            "lui a0,0x5;"
            "z.mvir a1,0x3;"
            "z.mviru a2,0x5;"          
          );

  csr_asm_rwi(csrrwi,r3,0x320,5);
  csr_asm_rwi(csrrwi,stop_instn,0xB02,0);  // instruction count
  csr_asm_rwi(csrrwi,stop_cycle,0xB00,0);   //mcycle 
  z_printf(" Total U & J-type instructions executed are  : %d \n",stop_instn-3); 
  z_printf(" Total Cycles for U & J-Type Instructions are: %d  \n",(stop_cycle-6)); 
  z_printf(" Average CPI for U & J-Type Instructions : %d.%d \n\n",((stop_cycle-6)/(stop_instn-3)),(((stop_cycle-6)%(stop_instn-3))*10)/(stop_instn-3)); 

  /*******************CUSTOM INSTRUCTIONS***************************/
  csr_asm_rwi( csrrwi,r0,0x320,0); //inhibit -clear needed for counter, instruction,cycle registers to start        
  csr_asm_rwi(csrrwi,start_cycle,0xB00,0);   //mcycle  
  csr_asm_rwi(csrrwi,start_instn,0xB02,0);  // instruction count -minstret

  __asm__ (
            
            "z.cgt a1,a2,a4;"
            "z.cgte a1,a2,a3;"
            "z.cgtu a1,a2,a5;"
            "z.cgteu a1,a2,a5;"
            "z.clt a1,a2,a4;"
            "z.clte a1,a2,a6;"
            "z.cltu a1,a2,a4;"
            "z.clteu a1,a2,a6;"
            "z.ceq a1,a2,a4;"
            "z.cne a1,a2,a5;"
            
          );

  csr_asm_rwi(csrrwi,r3,0x320,5);
  csr_asm_rwi(csrrwi,stop_instn,0xB02,0);  // instruction count
  csr_asm_rwi(csrrwi,stop_cycle,0xB00,0);   //mcycle 
  z_printf(" Total Custom instruction executed are  : %d \n",stop_instn-3); 
  z_printf(" Total Cycles for Custom Instructions are: %d  \n",(stop_cycle-6)); 
  z_printf(" Average CPI for Custom Instructions : %d.%d \n\n",((stop_cycle-6)/(stop_instn-3)),(((stop_cycle-6)%(stop_instn-3))*10)/(stop_instn-3)); 

/******************** ROTATE INSTRUCTIONS ************************/

  csr_asm_rwi( csrrwi,r0,0x320,0); //inhibit -clear needed for counter, instruction,cycle registers to start        
  csr_asm_rwi(csrrwi,start_cycle,0xB00,0);   //mcycle  
  csr_asm_rwi(csrrwi,start_instn,0xB02,0);  // instruction count -minstret

  __asm__ (
            
            "z.rol a1,a2,a4;"                
            "z.ror a1,a2,a5;"
            "z.roli a1,a2,0x4;"                
            "z.rori a1,a2,0x5;"

            
          
          );

  csr_asm_rwi(csrrwi,r3,0x320,5);
  csr_asm_rwi(csrrwi,stop_instn,0xB02,0);  // instruction count
  csr_asm_rwi(csrrwi,stop_cycle,0xB00,0);   //mcycle 
  z_printf(" Total rotate-type instructions executed are  : %d \n",stop_instn-3); 
  z_printf(" Total Cycles for rotate-Type Instructions are: %d  \n",(stop_cycle-6)); 
  z_printf(" Average CPI for rotate-Type Instructions : %d.%d \n\n",((stop_cycle-6)/(stop_instn-3)),(((stop_cycle-6)%(stop_instn-3))*10)/(stop_instn-3)); 



	mailbox_send_request(MAILBOX1, END_SIM);
	mailbox_send_request(MAILBOX2, error_cnt); 
  return 0;

}  
